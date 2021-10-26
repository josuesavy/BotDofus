#include "ScriptManager.h"

ScriptManager::ScriptManager(QMap<SocketIO *, BotData> *connectionsData,
                           MapManager *mapManager, FightManager *fightManager,
                           FarmManager *farmManager,
                           CraftManager *craftManager,
                           InteractionManager *interactionManager,
                           GroupManager *groupManager,
                           StatsManager *statsManager,
                           ConnectionManager *connectionManager):
    AbstractManager(ManagerType::SCRIPT, connectionsData),
    m_mapManager(mapManager),
    m_farmManager(farmManager),
    m_craftManager(craftManager),
    m_fightManager(fightManager),
    m_interactionManager(interactionManager),
    m_groupManager(groupManager),
    m_statsManager(statsManager),
    m_connectionManager(connectionManager)
{
    connect(m_mapManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_farmManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_craftManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_interactionManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightManager, SIGNAL(scriptActionCancel(SocketIO*)), this, SLOT(cancelProcessingAction(SocketIO*)));
    connect(m_fightManager, SIGNAL(scriptActionRepeat(SocketIO*)), this, SLOT(processRepeatAction(SocketIO*)));
    connect(m_statsManager, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
}

void ScriptManager::reset(SocketIO *sender)
{
    m_botData[sender].scriptData.lastActionMapId = INVALID;
    m_botData[sender].scriptData.isIndependent = false;
    m_botData[sender].scriptData.toExecute.clear();
    m_botData[sender].scriptData.activeManager = ManagerType::UNKNOWN;
    m_botData[sender].scriptData.sequence = -10;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
}

bool ScriptManager::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::BASICACKMESSAGE:
    {
        if(m_botData[sender].scriptData.scriptMaxTime != INVALID &&
                m_botData[sender].scriptData.scriptMaxTime < m_botData[sender].scriptData.scriptTimer.elapsed() &&
                sender->getLatencyList().last() <= m_botData[sender].scriptData.scriptMaxTime)
        {
            m_botData[sender].scriptData.scriptMaxTime = INVALID;
            warn(sender)<<"Il semblerait que le bot soit bloqué, tentative de relance du script...";
            m_connectionManager->reconnect(sender);
        }
    }
        break;
    }

    return messageFound;
}

void ScriptManager::cancelProcessingAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.lastInstruction.type != ScriptFunctionEnum::UNDEFINED)
    {
        m_botData[sender].scriptData.toExecute<<m_botData[sender].scriptData.lastInstruction;
        m_botData[sender].scriptData.lastInstruction.type = ScriptFunctionEnum::UNDEFINED;
    }
}

void ScriptManager::processRepeatAction(SocketIO *sender)
{
    SocketIO *master = m_groupManager->getMaster(sender);
    QList<SocketIO*> slaves = m_groupManager->getSlaves(sender);

    // Si c'est le master / independent
    if(master == NULL)
    {
        slaves<<sender;

        foreach(SocketIO *slave, slaves)
            m_botData[slave].scriptData.toExecute.insert(0, m_botData[slave].scriptData.lastInstruction);

        processNextAction(sender);
    }
}

void ScriptManager::processNextAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.isActive)
    {
        qDebug() << "P. NEXT ACTION"<<m_botData[sender].mapData.map.getPosition().getX()<<m_botData[sender].mapData.map.getPosition().getY();

        SocketIO *master = m_groupManager->getMaster(sender);

        if((master == nullptr && !m_groupManager->getSlaves(sender).isEmpty()) || (master == nullptr))
            master = sender;

        if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
        {
            m_statsManager->freeSoul(sender);
            m_botData[sender].scriptData.activeManager = ManagerType::STATS;
        }

        if(groupNeedsHeal(sender))
        {
            action(sender)<<"Regeneration de groupe en cours";

            m_botData[sender].scriptData.activeManager = ManagerType::STATS;

            if(!m_statsManager->healEat(sender))
            {
                m_statsManager->healSit(sender);
            }

            return;
        }
        else if(m_statsManager->needsToGoToPhoenix(sender))
        {
            action(sender)<<"Etat fantome, passage au phoenix nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            getGlobalFunction(sender, lua, ScriptTag::GHOST);
        }
        else if(groupNeedsToGoToBank(sender))
        {
            action(sender)<<"Limite de pods dépassée, retour à la banque nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            getGlobalFunction(sender, lua, ScriptTag::BANK);
        }
        else
        {
            getGlobalFunction(sender, lua, ScriptTag::MOVE);
        }

        if(m_botData[sender].scriptData.scriptMaxTime != INVALID)
            m_botData[sender].scriptData.scriptTimer.restart();
    }
}

void ScriptManager::processControl(SocketIO *sender)
{
    qDebug() << "START PROCESS CONTROL";

    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    m_botData[sender].scriptData.activeManager = ManagerType::UNKNOWN;

    SocketIO *master = m_groupManager->getMaster(sender);
    if(master == nullptr && !m_groupManager->getSlaves(sender).isEmpty())
        master = sender;

    if(master != nullptr)
    {
        if(m_groupManager->isGroupOnMapAndInactive(master))
        {
            QList<SocketIO*> slaves = m_groupManager->getSlaves(master);

            foreach(SocketIO *slave, slaves)
            {
                if(m_botData[slave].scriptData.activeManager == ManagerType::UNKNOWN)
                {
                    processNextAction(slave);
                    m_botData[slave].scriptData.isActive = true;
                }
            }
        }
        else
        {
            QList<SocketIO*> members = m_groupManager->getSlaves(master);
            members << master;

            foreach(SocketIO *member, members)
            {
                if(m_botData[master].mapData.map.getMapId() != m_botData[member].mapData.map.getMapId() && m_botData[member].scriptData.activeManager == ManagerType::UNKNOWN)
                {
                    error(master) << "Impossible de démarrer le script : Tous les membres du groupe ne sont pas sur la même carte.";
                    unloadFile(master);
                    break;
                }
            }
        }
    }

    else
    {
        qDebug() << "INDEPENDENT";
        processNextAction(sender);
    }

    qDebug() << "END PROCESS CONTROL";
}

void ScriptManager::waitForInactivity()
{
    SocketIO *sender = m_waitingList.first();
    m_waitingList.removeFirst();
    processNextAction(sender);
}

void ScriptManager::getSettings(SocketIO *sender, lua_State *lua)
{
    lua_getglobal(lua, "MAX_PODS");
    if(lua_isnumber(lua, -1))
        setPodsLimit(sender, (ushort)lua_tonumber(lua,-1));

    lua_getglobal(lua, "AUTO_DELETE");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                m_botData[sender].farmData.resourcesToDelete << (int)lua_tonumber(lua,-1);

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "GATHER");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                m_botData[sender].farmData.elementsId << (int)lua_tonumber(lua,-1);

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "MIN_MONSTERS");
    if(lua_isnumber(lua, -1))
        m_botData[sender].fightData.requestedMonsters.mnNbMonsters = (int)lua_tonumber(lua,-1);

    lua_getglobal(lua, "MAX_MONSTERS");
    if(lua_isnumber(lua, -1))
        m_botData[sender].fightData.requestedMonsters.mxNbMonsters = (int)lua_tonumber(lua,-1);

    // TODO : add properties open bag in datahandlers
    lua_getglobal(lua, "OPEN_BAGS");
    if(lua_isboolean(lua, -1))
        lua_toboolean(lua,-1); // value

    lua_getglobal(lua, "FORBIDDEN_MONSTERS");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
            {
                MonsterCondition cond;
                cond.id = (int)lua_tonumber(lua,-1);
                cond.monsterInclusion = MonsterInclusion::ALL_EXCEPT;
                m_botData[sender].fightData.requestedMonsters.monsterConditions << cond;
            }

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "MANDATORY_MONSTERS");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
            {
                MonsterCondition cond;
                cond.id = (int)lua_tonumber(lua,-1);
                cond.monsterInclusion = MonsterInclusion::NONE_EXCEPT;
                m_botData[sender].fightData.requestedMonsters.monsterConditions << cond;
            }

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }
}

void ScriptManager::getGlobalFunction(SocketIO *sender, lua_State *lua, ScriptTag function)
{
    m_botData[sender].scriptData.tag = function;

    switch (function)
    {
    case ScriptTag::MOVE:
        lua_getglobal(lua, "move");
        break;

    case ScriptTag::BANK:
        lua_getglobal(lua, "bank");
        break;

    case ScriptTag::GHOST:
        lua_getglobal(lua, "phoenix");
        break;

    case ScriptTag::UNDEFINED:
        break;
    }

    if(lua_isfunction(lua, -1))
    {
        if(!lua_pcall(lua, 0, LUA_MULTRET, 0))
        {
            if(lua_istable(lua, -1))
            {
                lua_pushnil(lua);
                while(lua_next(lua,-2) != 0)
                {
                    if(lua_istable(lua, -3))
                        getActions(sender, lua);

                    lua_pop(lua,1);
                }
            }
        }
    }

    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
}

void ScriptManager::getActions(SocketIO *sender, lua_State *lua)
{
    // action's priority: Gather<Fight<Door<Custom<ChangeMap

    int mapid = INVALID;

    lua_pushstring(lua, "map");
    lua_gettable(lua, -2);
    mapid = getMap(sender, lua_tostring(lua, -1));
    lua_pop(lua,1);


    lua_pushstring(lua, "gather");
    lua_gettable(lua, -2);
    if ((bool)lua_toboolean(lua, -1) && mapid != INVALID)
    {
        if(m_farmManager->processFarm(sender))
        {
            m_botData[sender].scriptData.scriptMaxTime = FARM_MAXTIME;
        }
    }
    lua_pop(lua,1);


    lua_pushstring(lua, "fight");
    lua_gettable(lua, -2);
    if ((bool)lua_toboolean(lua, -1) && mapid != INVALID)
    {
        if(m_fightManager->processMonsters(sender))
            qDebug()<<"IS GOING TO FIGHT";

        else
            qDebug()<<"NO MONSTERS";
    }
    lua_pop(lua,1);


    lua_pushstring(lua, "door");
    lua_gettable(lua, -2);
    QString door = lua_tostring(lua, -1);
    if (!door.isEmpty() && mapid != INVALID)
    {
        if (m_interactionManager->processUse(sender, door.toInt()))
        {
            m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
            m_botData[sender].scriptData.activeManager = ManagerType::INTERACTION;
        }
    }
    lua_pop(lua,1);


    lua_pushstring(lua, "custom");
    lua_gettable(lua, -2);
    if(lua_topointer(lua, -1) != nullptr && mapid != INVALID)
    {
        if(lua_isfunction(lua, -1))
        {
            if(lua_pcall(lua, 0,1,0))
            {
                qDebug() << lua_tostring(lua, -1); // value
            }
        }
    }
    lua_pop(lua,1);


    lua_pushstring(lua, "npcBank");
    lua_gettable(lua, -2);
    if ((bool)lua_toboolean(lua, -1))
    {
        if (m_interactionManager->processNpcInteraction(sender, -1))
        {
            if (m_interactionManager->processNpcDialog(sender, ""))
            {
                m_botData[sender].scriptData.scriptMaxTime = INTERACTION_MAXTIME;
                m_botData[sender].scriptData.activeManager = ManagerType::INTERACTION;
            }
        }
    }
    lua_pop(lua,1);


    lua_pushstring(lua, "lockedHouse");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);


    lua_pushstring(lua, "lockedStorage");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);


    lua_pushstring(lua, "path");
    lua_gettable(lua, -2);
    if (mapid != INVALID)
    {
        QList<MapSide> sides = getSides(lua_tostring(lua, -1));
        MapSide side = sides[QRandomGenerator::global()->generate() % sides.size()];
        m_botData[sender].scriptData.activeManager = ManagerType::MAP;

        if (m_mapManager->changeMap(sender, side))
            m_botData[sender].scriptData.scriptMaxTime = MOVE_MAXTIME;
        else
            action(sender) << "Une erreur est survenue, impossible de passer d'une carte à une autre";
    }
    lua_pop(lua,1);
}

bool ScriptManager::groupNeedsHeal(SocketIO *sender)
{
    SocketIO *master = m_groupManager->getMaster(sender);

    QList<SocketIO*> slaves = m_groupManager->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {
        if(m_statsManager->needsHeal(player))
            return true;
    }

    return false;
}

bool ScriptManager::groupNeedsToGoToBank(SocketIO *sender)
{
    SocketIO *master = m_groupManager->getMaster(sender);

    QList<SocketIO*> slaves = m_groupManager->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {
        if(m_statsManager->needsToGoToBank(player))
            return true;
    }

    return false;
}

void ScriptManager::unloadFile(SocketIO *sender)
{
    // clear global
    m_botData[sender].scriptData.fileContent.clear();
    m_botData[sender].scriptData.isActive = false;
    foreach(SocketIO *salve, m_groupManager->getSlaves(sender)) m_botData[salve].scriptData.isActive = false;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    // TODO : empty openbags

    // clear farm
    setPodsLimit(sender, 90);
    m_botData[sender].farmData.resourcesToDelete.clear();
    m_botData[sender].farmData.elementsId.clear();

    // clear fight
    m_botData[sender].fightData.requestedMonsters.mnNbMonsters = INVALID;
    m_botData[sender].fightData.requestedMonsters.mxNbMonsters = INVALID;
    m_botData[sender].fightData.requestedMonsters.groupLevelMin = INVALID;
    m_botData[sender].fightData.requestedMonsters.groupLevelMin = INVALID;
    m_botData[sender].fightData.requestedMonsters.monsterConditions.clear();

    if(m_botData[sender].scriptData.activeManager == ManagerType::MAP)
        m_mapManager->stopMoving(sender);

    else if(m_botData[sender].scriptData.activeManager == ManagerType::INTERACTION)
        m_interactionManager->leaveNpcDialog(sender);

    // TODO: emit signal gui

    info(sender) << "Script arrêté.";
}

bool ScriptManager::loadFile(SocketIO *sender, QString p)
{
    QFile file(p);
    if (file.open(QIODevice::ReadOnly) && file.size())
    {
        m_botData[sender].scriptData.fileContent = file.readAll();
        return true;
    }

    return false;
}

int ScriptManager::parse(SocketIO *sender)
{
    // clear global
    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    m_botData[sender].scriptData.isActive = false;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    // TODO : empty openbags

    // clear farm
    setPodsLimit(sender, 90);
    m_botData[sender].farmData.resourcesToDelete.clear();
    m_botData[sender].farmData.elementsId.clear();

    // clear fight
    m_botData[sender].fightData.requestedMonsters.mnNbMonsters = INVALID;
    m_botData[sender].fightData.requestedMonsters.mxNbMonsters = INVALID;
    m_botData[sender].fightData.requestedMonsters.groupLevelMin = INVALID;
    m_botData[sender].fightData.requestedMonsters.groupLevelMin = INVALID;
    m_botData[sender].fightData.requestedMonsters.monsterConditions.clear();


    // begin read and parse lua file
    lua = luaL_newstate();
    luaopen_table(lua);
    luaL_openlibs(lua);

    LuaFunctions luaFunctions;
    luaFunctions.setLuaState(lua);
    luaFunctions.init();

    if(luaL_dostring(lua, m_botData[sender].scriptData.fileContent.toStdString().c_str()) != 0)
    {
        error(sender) << lua_tostring(lua, -1);
        unloadFile(sender);
        return 1;
    }

    else
    {
        info(sender) << "Script démarré.";

        // Get vars
        getSettings(sender, lua);

        // Get functions
        getGlobalFunction(sender, lua, ScriptTag::MOVE);
        getGlobalFunction(sender, lua, ScriptTag::BANK);
        getGlobalFunction(sender, lua, ScriptTag::GHOST);
    }

    lua_close(lua);
    // end read and parse lua file


    if (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED)
    {
        //unloadFile(sender);
        return 1;
    }

    else
    {
        info(sender) << "Script démarré.";
        m_botData[sender].scriptData.isActive = true;
        processControl(sender);
        return 0;
    }
}

QList<MapSide> ScriptManager::getSides(QString side)
{
    QList<MapSide> q;
    QStringList sides = side.split("|");
    foreach (QString s, sides)
    {
        s.replace(" ", "");

        QRegularExpression t("[tT][oO][pP]");
        QRegularExpression l("[lL][eE][fF][tT]");
        QRegularExpression r("[rR][iI][gG][hH][tT]");
        QRegularExpression b("[bB][oO][tT][tT][oO][mM]");

        QRegularExpressionMatch mt = t.match(s);
        QRegularExpressionMatch ml = l.match(s);
        QRegularExpressionMatch mr = r.match(s);
        QRegularExpressionMatch mb = b.match(s);

        if (mt.hasMatch())
            q.append(MapSide::TOP);
        else if (ml.hasMatch())
            q.append(MapSide::LEFT);
        else if (mr.hasMatch())
            q.append(MapSide::RIGHT);
        else if (mb.hasMatch())
            q.append(MapSide::BOTTOM);
        else
            return QList<MapSide>();
    }

    return q;
}

int ScriptManager::getMap(SocketIO *sender, QString map)
{
    int mapid = INVALID;
    QRegularExpression r("(?<x>[-]*[0-9][0-9]*),[ ]*(?<y>[-]*[0-9][0-9]*)");
    QRegularExpression re("^(?<id>[0-9]+)");
    QRegularExpressionMatch me = re.match(map);
    QRegularExpressionMatch m = r.match(map);
    if ((m.hasMatch() || me.hasMatch()) && (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED))
    {
        if (m.hasMatch())
        {
            QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
            QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

            mapid = PathfindingMap::coordsToMapId(m.captured("x").toInt(), m.captured("y").toInt(), area->getSuperAreaId());
        }
        else if (me.hasMatch())
        {
            mapid = me.captured("id").toInt();
        }
    }

    if (m_botData[sender].mapData.map.getMapId() != mapid)
        mapid = INVALID;

    return mapid;
}

void ScriptManager::setActivePath(SocketIO *sender, bool active)
{
    m_botData[sender].scriptData.isActive = active;
}

void ScriptManager::setPodsLimit(SocketIO *sender, ushort ratio)
{
    if(ratio >= 0 && ratio <= 100)
        m_botData[sender].scriptData.podsLimitRatio = ratio;
}
