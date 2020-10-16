#include "ScriptModule.h"

ScriptModule::ScriptModule(QMap<SocketIO *, BotData> *connectionsData,
                           MapModule *mapModule, FightModule *fightModule,
                           FarmModule *farmModule,
                           CraftModule *craftModule,
                           InteractionModule *interactionModule,
                           GroupModule *groupModule,
                           StatsModule *statsModule,
                           ConnectionModule *connectionModule):
    AbstractModule(ModuleType::SCRIPT, connectionsData),
    m_mapModule(mapModule),
    m_farmModule(farmModule),
    m_craftModule(craftModule),
    m_fightModule(fightModule),
    m_interactionModule(interactionModule),
    m_groupModule(groupModule),
    m_statsModule(statsModule),
    m_connectionModule(connectionModule)
{
    connect(m_mapModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_farmModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_craftModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_interactionModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionCancel(SocketIO*)), this, SLOT(cancelProcessingAction(SocketIO*)));
    connect(m_fightModule, SIGNAL(scriptActionRepeat(SocketIO*)), this, SLOT(processRepeatAction(SocketIO*)));
    connect(m_statsModule, SIGNAL(scriptActionDone(SocketIO*)), this, SLOT(processControl(SocketIO*)));
}

void ScriptModule::reset(SocketIO *sender)
{
    m_botData[sender].scriptData.lastActionMapId = INVALID;
    m_botData[sender].scriptData.isIndependent = false;
    m_botData[sender].scriptData.toExecute.clear();
    m_botData[sender].scriptData.activeModule = ModuleType::UNKNOWN;
    m_botData[sender].scriptData.sequence = -10;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
}

bool ScriptModule::processMessage(const MessageInfos &data, SocketIO *sender)
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
            m_connectionModule->reconnect(sender);
        }
    }
        break;
    }

    return messageFound;
}

ScriptPathMapData ScriptModule::getGhost(SocketIO *sender, uint id)
{
    ScriptPathMapData d;
    if (m_botData[sender].scriptData.ghost.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;

    foreach (ScriptPathMapData m, m_botData[sender].scriptData.ghost)
        if (m.id == id)
            return d;

    return d;
}

ScriptPathMapData ScriptModule::getBank(SocketIO *sender, uint id)
{
    ScriptPathMapData d;
    if (m_botData[sender].scriptData.bank.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId;

    foreach (ScriptPathMapData m, m_botData[sender].scriptData.bank)
        if (m.id == id)
            return d;

    return d;
}

ScriptPathMapData ScriptModule::getMap(SocketIO *sender, uint id)
{
    ScriptPathMapData d = {};
    ScriptPathMapData s = {};

    if (m_botData[sender].scriptData.data.isEmpty())
        return d;

    if (!id)
        id = m_botData[sender].mapData.map.getMapId();

    QList<ScriptPathMapData> l;
    foreach (ScriptPathMapData m, m_botData[sender].scriptData.data)
    {
        if (m.id == id)
            l << m;
    }


    int i = 0;
    foreach (ScriptPathMapData m, l)
    {
        if (m.tag == ScriptTag::BANK)
            return m;
        else
            d = m;

        i++;
    }

    convertToFunction(d);
    convertToFunction(s);

    if (!m_botData[sender].scriptData.isActive)
        return d;
    else if (i >= 1 || d.id == INVALID)
        return d;
    else
        return s;
}

void ScriptModule::cancelProcessingAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.lastInstruction.type != ScriptFunctionEnum::UNDEFINED)
    {
        m_botData[sender].scriptData.toExecute<<m_botData[sender].scriptData.lastInstruction;
        m_botData[sender].scriptData.lastInstruction.type = ScriptFunctionEnum::UNDEFINED;
    }
}

void ScriptModule::processRepeatAction(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);
    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    // Si c'est le master / independent
    if(master == NULL)
    {
        slaves<<sender;

        foreach(SocketIO *slave, slaves)
            m_botData[slave].scriptData.toExecute.insert(0, m_botData[slave].scriptData.lastInstruction);

        processNextAction(sender);
    }
}

void ScriptModule::processNextAction(SocketIO *sender)
{
    if(m_botData[sender].scriptData.isActive)
    {
        qDebug() << "P. NEXT ACTION"<<m_botData[sender].mapData.map.getPosition().getX()<<m_botData[sender].mapData.map.getPosition().getY();

        SocketIO *master = m_groupModule->getMaster(sender);

        if((master == NULL && !m_groupModule->getSlaves(sender).isEmpty()) || (master == NULL))
            master = sender;

        if(m_botData[sender].scriptData.toExecute.isEmpty() && groupNeedsHeal(sender))
        {
            action(sender)<<"Regeneration de groupe en cours";

            m_botData[sender].scriptData.activeModule = ModuleType::STATS;

            if(!m_statsModule->healEat(sender))
                m_statsModule->healSit(sender);

            return;
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty() && m_statsModule->needsToGoToPhoenix(sender))
        {
            m_botData[sender].scriptData.isIndependent = true;

            if(m_botData[sender].scriptData.lastActionMapId == m_botData[sender].mapData.map.getMapId())
                action(sender)<<"Etat fantome, passage au phoenix nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            m_botData[sender].scriptData.toExecute = getGhost(sender).functions;

            if(m_botData[sender].scriptData.toExecute.isEmpty())
            {
                action(sender)<<"Erreur, la balise GHOST n'est pas configurée";
                return;
            }
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty() && groupNeedsToGoToBank(sender))
        {
            if(m_botData[sender].scriptData.lastActionMapId == m_botData[sender].mapData.map.getMapId())
                action(sender)<<"Limite de pods dépassée, retour à la banque nécessaire";

            m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
            m_botData[sender].scriptData.toExecute = getBank(sender).functions;

            if(m_botData[sender].scriptData.toExecute.isEmpty())
                action(sender)<<"Erreur, la balise BANK n'est pas configurée";
        }

        else if(m_botData[sender].scriptData.toExecute.isEmpty())
        {
            ScriptPathMapData d = getMap(master, m_botData[sender].mapData.map.getMapId());

            if(master != sender)
                d = arrangeScriptForSlave(d);

            if (d.id != INVALID)
            {
                m_botData[sender].scriptData.lastActionMapId = m_botData[sender].mapData.map.getMapId();
                m_botData[sender].scriptData.toExecute = d.functions;
            }
        }

        if (!m_botData[sender].scriptData.toExecute.isEmpty())
        {
            debug(sender) << "size to execute:" << m_botData[sender].scriptData.toExecute.size();
            foreach(ScriptFunction func, m_botData[sender].scriptData.toExecute)
            {
                if(func.type == ScriptFunctionEnum::FIGHT)
                    debug(sender) << "to execute is fight";
                else if(func.type == ScriptFunctionEnum::CHANGEMAP)
                    debug(sender) << "to execute is changeMap";
            }

            ScriptFunction f = m_botData[sender].scriptData.toExecute.takeFirst();
            m_botData[sender].scriptData.lastInstruction = f;

            if(m_botData[sender].scriptData.lastInstruction.type == ScriptFunctionEnum::FIGHT)
                debug(sender) << "next instruction is fight";
            else if(m_botData[sender].scriptData.lastInstruction.type == ScriptFunctionEnum::CHANGEMAP)
                debug(sender) << "next instruction is changeMap";

            if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
            {
                m_botData[sender].scriptData.toExecute<<m_botData[sender].scriptData.lastInstruction;
                m_statsModule->freeSoul(sender);
                m_botData[sender].scriptData.activeModule = ModuleType::STATS;
            }

            else if (f.type == ScriptFunctionEnum::GATHER)
            {
                qDebug()<<"FARM";
                m_botData[sender].scriptData.activeModule = ModuleType::FARM;

                if (m_farmModule->processFarm(sender))
                    m_botData[sender].scriptData.scriptMaxTime = FARM_MAXTIME;

                else
                    processNextAction(sender);
            }

            else if (f.type == ScriptFunctionEnum::FIGHT)
            {
                qDebug()<<"FIGHT";
                m_botData[sender].scriptData.activeModule = ModuleType::FIGHT;

                if (!m_fightModule->processMonsters(sender))
                    processNextAction(sender);
            }

            else if(f.type == ScriptFunctionEnum::DOOR)
            {

            }

            else if(f.type == ScriptFunctionEnum::CUSTOM)
            {
                qDebug()<<"CUSTOM";
                m_botData[sender].scriptData.activeModule = ModuleType::UNKNOWN;

//                lua_State *lua;

//                lua = luaL_newstate();
//                luaL_openlibs(lua);

//                if(luaL_dostring(lua, m_botData[sender].scriptData.fileContent.toStdString().c_str()))
//                {
//                    lua_getglobal(lua, f.params.first());
//                }

//                lua_close(lua);
            }

            else if (f.type == ScriptFunctionEnum::CHANGEMAP)
            {
                qDebug()<<"MOVE";
                QList<QVariant> sides = f.params.first().toList();
                MapSide m = (MapSide)sides[qrand() % sides.size()].toInt();
                m_botData[sender].scriptData.activeModule = ModuleType::MAP;

                if (m_mapModule->changeMap(sender, m))
                    m_botData[sender].scriptData.scriptMaxTime = MOVE_MAXTIME;

                else
                    action(sender) << "Une erreur est survenue, impossible de passer d'une carte à une autre";
            }

            else if(f.type == ScriptFunctionEnum::UNDEFINED)
            {

            }

            else
            {
                error(sender) << "Fonction de trajet inconnue";
                processNextAction(sender);
            }

            if(m_botData[sender].scriptData.toExecute.isEmpty() && m_botData[sender].scriptData.isIndependent)
                m_botData[sender].scriptData.isIndependent = false;
        }

        else
        {
            action(sender) << "Carte non repertoriée dans le script, impossible de récuperer";
            unloadFile(sender);
        }

        if(m_botData[sender].scriptData.scriptMaxTime != INVALID)
            m_botData[sender].scriptData.scriptTimer.restart();
    }
}

void ScriptModule::processControl(SocketIO *sender)
{
    qDebug() << "START PROCESS CONTROL";

    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    m_botData[sender].scriptData.activeModule = ModuleType::UNKNOWN;

    SocketIO *master = m_groupModule->getMaster(sender);
    if(master == NULL && !m_groupModule->getSlaves(sender).isEmpty())
        master = sender;

    // MODE MULTI-COMPTES
    if(master != NULL)
    {
        // LE GROUPE EST REUNI
        if(m_groupModule->isGroupOnMapAndInactive(master))
        {
            QList<SocketIO*> slaves = m_groupModule->getSlaves(master);

            foreach(SocketIO *slave, slaves)
            {
                if(m_botData[slave].scriptData.activeModule == ModuleType::UNKNOWN)
                {
                    // ON FOURNI LES INSTRUCTIONS AUX ESCLAVES N'AYANT PAS CHARGE DE SCRIPTS
                    if(m_botData[slave].scriptData.toExecute.isEmpty())
                    {
                        m_botData[slave].scriptData.isIndependent = false;
                        m_botData[slave].scriptData.toExecute = arrangeScriptForSlave(getMap(master, m_botData[slave].mapData.map.getMapId())).functions;
                    }

                    m_botData[slave].scriptData.isActive = true;

                    // SYNCHRONISATION A LA MEME SEQUENCE SI NECESSAIRE (DEMARRAGE & BUGS)
                    if ((m_botData[slave].scriptData.sequence > m_botData[master].scriptData.sequence || m_botData[slave].scriptData.sequence < 0) && !m_botData[slave].scriptData.isIndependent)
                    {
                        int s = m_botData[master].scriptData.toExecute.size();

                        if(m_botData[master].scriptData.activeModule != ModuleType::UNKNOWN)
                            s++;

                        debug(slave)<<"ASYNCHRONE - RECALIBRAGE - Sequence:"<<m_botData[slave].scriptData.sequence<<"- MASTER's Sequence:"<<m_botData[master].scriptData.sequence;

                        // action(slave)<<"CALCUL"<< m_botData[m].scriptData.sequence <<f.functions.size()<<s;
                        m_botData[slave].scriptData.sequence = m_botData[master].scriptData.sequence;
                    }

                    // LES MEMBRES EN PHASE CONTINUENT LEURS ACTIONS
                    if(m_botData[slave].scriptData.sequence < m_botData[master].scriptData.sequence && !m_botData[slave].scriptData.isIndependent)
                    {
                        debug(slave)<<"SYNCHRONE - Sequence :"<<m_botData[slave].scriptData.sequence;
                        processNextAction(slave);

                        if(m_botData[slave].scriptData.sequence >= 0)
                            m_botData[slave].scriptData.sequence = m_botData[slave].scriptData.sequence + 1;
                    }

                    else if(m_botData[slave].scriptData.isIndependent)
                    {
                        debug(slave)<<"ISOLEMENT";
                        m_botData[slave].scriptData.sequence = INVALID;
                        processNextAction(slave);
                    }

                    // LES AUTRES AYANT DEJA EXECUTE LEUR ACTION ATTENDENT LES AUTRES
                    else
                        debug(slave)<<"EN ATTENTE1 - MAP X:"<<m_botData[slave].mapData.map.getPosition().getX()<<"Y:"<<m_botData[slave].mapData.map.getPosition().getY()<<" - Sequence:"<<m_botData[slave].scriptData.sequence;
                }
            }

            if(isGroupReadyForNextSequence(master))
            {
                if(m_botData[master].scriptData.sequence >= 0)
                    m_botData[master].scriptData.sequence = m_botData[master].scriptData.sequence + 1;

                debug(master)<<"NEW ACTION - Sequence:"<<m_botData[master].scriptData.sequence;
                processNextAction(master);
            }

            else
                debug(master)<<"EN ATTENTE2 - MAP X:"<<m_botData[master].mapData.map.getPosition().getX()<<"Y:"<<m_botData[master].mapData.map.getPosition().getY()<<" - Sequence:"<<m_botData[master].scriptData.sequence;
        }


        // LE GROUPE EST DISPERE SUR DIFFERENTES CARTES
        else
        {
            QList<SocketIO*> members = m_groupModule->getSlaves(master);
            members << master;

            bool lost = false;

            // ON CHERCHE UN MEMBRE DU GROUPE QUI EST PERDU (DEMARRAGE & BUGS)
            foreach(SocketIO *member, members)
            {
                if(m_botData[master].mapData.map.getMapId() != m_botData[member].mapData.map.getMapId() &&
                        m_botData[member].scriptData.activeModule == ModuleType::UNKNOWN &&
                        m_botData[member].scriptData.toExecute.isEmpty() &&
                        m_botData[member].scriptData.sequence != m_botData[master].scriptData.sequence &&
                        m_botData[member].scriptData.sequence+1 != m_botData[master].scriptData.sequence &&
                        !m_botData[member].scriptData.isIndependent)
                {
                    lost = true;
                    break;
                }
            }

            // SI UN MEMBRE DU GROUPE EST PERDU, RETOUR A LA POSITION LOST (DEMARRAGE & BUGS)
            if(lost)
            {
                error(master) << "Impossible de démarrer le script : Tous les membres du groupe ne sont pas sur la même carte.";
                unloadFile(master);
            }

            // LES MEMBRES EN PHASE CONTINUENT LEURS ACTIONS
            else
            {
                foreach(SocketIO *member, members)
                {
                    if(m_botData[master].mapData.map.getMapId() != m_botData[member].mapData.map.getMapId() &&
                            m_botData[member].scriptData.activeModule == ModuleType::UNKNOWN &&
                            m_botData[member].scriptData.sequence+1 == m_botData[master].scriptData.sequence)
                    {
                        debug(member)<<"SYNCHRONE2 - Sequence:"<<m_botData[member].scriptData.sequence;

                        m_botData[member].scriptData.isActive = true;

                        //if(m_botData[member].scriptData.toExecute.isEmpty())
                        //   m_botData[member].scriptData.toExecute = arrangeScriptForSlave(getMap(master, m_botData[member].mapData.map.getMapId())).functions;

                        processNextAction(member);

                        if(m_botData[member].scriptData.sequence >= 0)
                            m_botData[member].scriptData.sequence = m_botData[member].scriptData.sequence + 1;
                    }

                    else
                        debug(member)<<"EN ATTENTE3 - MAP X:"<<m_botData[member].mapData.map.getPosition().getX()<<"Y:"<<m_botData[member].mapData.map.getPosition().getY()<<" - Sequence :"<<m_botData[member].scriptData.sequence<<" - MASTER's Sequence:"<<m_botData[master].scriptData.sequence ;
                }
            }
        }
    }

    // MODE SOLO
    else
    {
        qDebug() << "INDEPENDENT";
        processNextAction(sender);
    }

    qDebug() << "END PROCESS CONTROL";
}

void ScriptModule::waitForInactivity()
{
    SocketIO *sender = m_waitingList.first();
    m_waitingList.removeFirst();
    processNextAction(sender);
}

void ScriptModule::getSettings(SocketIO *sender, lua_State *lua)
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
        (bool)lua_toboolean(lua,-1); // value

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

void ScriptModule::getGlobalFunction(SocketIO *sender, lua_State *lua, ScriptTag function)
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

void ScriptModule::getActions(SocketIO *sender, lua_State *lua)
{
    ScriptPathMapData a;
    a.tag = m_botData[sender].scriptData.tag;

    lua_pushstring(lua, "map");
    lua_gettable(lua, -2);

    QString d = lua_tostring(lua, -1);
    QRegularExpression r("(?<x>[-]*[0-9][0-9]*),[ ]*(?<y>[-]*[0-9][0-9]*)");
    QRegularExpression re("^(?<id>[0-9]+)");
    QRegularExpressionMatch me = re.match(d);
    QRegularExpressionMatch m = r.match(d);
    if (((m.hasMatch() || me.hasMatch()) && (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED)))
    {
        int id = INVALID;
        if (m.hasMatch())
        {
            QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
            QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

            id = PathfindingMap::coordsToMapId(m.captured("x").toInt(), m.captured("y").toInt(), area->getSuperAreaId());
        }
        else if (me.hasMatch())
            id = me.captured("id").toInt();

        a.id = id;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "custom");
    lua_gettable(lua, -2);
    if(lua_topointer(lua, -1) != NULL)
    {
        if(lua_isfunction(lua, -1))
        {
            ScriptFunction func;
            func.type = ScriptFunctionEnum::CUSTOM;
            func.params << qVariantFromValue((void*)lua_topointer(lua, -1));

            a.functions << func;
        }
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "npcBank");
    lua_gettable(lua, -2);
    if(a.id != INVALID && (bool)lua_toboolean(lua, -1))
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::NPC_BANK;

        a.functions << func;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "changeMap");
    lua_gettable(lua, -2);
    if(a.id != INVALID)
    {
        QList<MapSide> side = getSides(lua_tostring(lua, -1));
        a.sides = side;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "door");
    lua_gettable(lua, -2);
    if(a.id != INVALID && !QString::fromUtf8(lua_tostring(lua, -1)).isEmpty())
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::DOOR;
        func.params << lua_tostring(lua, -1);

        a.functions << func;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "gather");
    lua_gettable(lua, -2);
    if(a.id != INVALID && (bool)lua_toboolean(lua, -1))
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::GATHER;

        a.functions << func;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "fight");
    lua_gettable(lua, -2);
    if(a.id != INVALID && (bool)lua_toboolean(lua, -1))
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::FIGHT;

        a.functions << func;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "lockedHouse");
    lua_gettable(lua, -2);
    if(a.id != INVALID && !QString::fromUtf8(lua_tostring(lua, -1)).isEmpty())
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::HOUSE;
        func.params << lua_tostring(lua, -1); // value

        a.functions << func;
    }
    lua_pop(lua,1);



    lua_pushstring(lua, "lockedStorage");
    lua_gettable(lua, -2);
    if(a.id != INVALID && !QString::fromUtf8(lua_tostring(lua, -1)).isEmpty())
    {
        ScriptFunction func;
        func.type = ScriptFunctionEnum::SAFE;
        func.params << lua_tostring(lua, -1); // value

        a.functions << func;
    }
    lua_pop(lua,1);



    if (m_botData[sender].scriptData.tag == ScriptTag::BANK)
        m_botData[sender].scriptData.bank << a;
    else if (m_botData[sender].scriptData.tag == ScriptTag::GHOST)
        m_botData[sender].scriptData.ghost << a;
    else if (m_botData[sender].scriptData.tag != ScriptTag::UNDEFINED)
        m_botData[sender].scriptData.data << a;
}

bool ScriptModule::groupNeedsHeal(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);

    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {
        if(m_statsModule->needsHeal(player))
            return true;
    }

    return false;
}

bool ScriptModule::groupNeedsToGoToBank(SocketIO *sender)
{
    SocketIO *master = m_groupModule->getMaster(sender);

    QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);

    slaves<<master;

    foreach(SocketIO* player, slaves)
    {
        if(m_statsModule->needsToGoToBank(player))
            return true;
    }

    return false;
}

bool ScriptModule::isGroupReadyForNextSequence(SocketIO *master)
{
    QList<SocketIO*> slaves = m_groupModule->getSlaves(master);
    int sequence = m_botData[master].scriptData.sequence;
    int mapId = m_botData[master].mapData.map.getMapId();


    if(sequence < 0 || m_botData[master].scriptData.isIndependent || m_botData[master].scriptData.activeModule != ModuleType::UNKNOWN)
        return false;

    for(int i = 0; i < slaves.size(); i++)
    {
        if(sequence != m_botData[slaves[i]].scriptData.sequence ||
                mapId != m_botData[slaves[i]].mapData.map.getMapId() ||
                m_botData[slaves[i]].scriptData.isIndependent ||
                m_botData[slaves[i]].scriptData.activeModule != ModuleType::UNKNOWN)
            return false;
    }

    return true;
}

ScriptPathMapData ScriptModule::arrangeScriptForSlave(ScriptPathMapData s)
{
    for(int i = 0; i < s.functions.size(); i++)
    {
        if(s.functions[i].type == ScriptFunctionEnum::FIGHT)
            s.functions[i].type = ScriptFunctionEnum::UNDEFINED;
    }

    return s;
}

void ScriptModule::unloadFile(SocketIO *sender)
{
    // clear global
    m_botData[sender].scriptData.data.clear();
    m_botData[sender].scriptData.lost.clear();
    m_botData[sender].scriptData.bank.clear();
    m_botData[sender].scriptData.fileContent.clear();
    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    m_botData[sender].scriptData.isActive = false;
    foreach(SocketIO *salve, m_groupModule->getSlaves(sender))
        m_botData[salve].scriptData.isActive = false;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    m_botData[sender].scriptData.sequence = 0;
    m_botData[sender].scriptData.toExecute.clear();
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

    if(m_botData[sender].scriptData.activeModule == ModuleType::MAP)
        m_mapModule->stopMoving(sender);

    else if(m_botData[sender].scriptData.activeModule == ModuleType::INTERACTION)
        m_interactionModule->leaveNpcDialog(sender);

    // TODO: emit signal gui

    info(sender) << "Script arrêté.";
}

bool ScriptModule::loadFile(SocketIO *sender, QString p)
{
    QFile file(p);
    if (file.open(QIODevice::ReadOnly) && file.size())
    {
        m_botData[sender].scriptData.fileContent = file.readAll();
        return true;
    }

    return false;
}

int ScriptModule::parse(SocketIO *sender)
{
    // clear global
    m_botData[sender].scriptData.data.clear();
    m_botData[sender].scriptData.lost.clear();
    m_botData[sender].scriptData.bank.clear();
    m_botData[sender].scriptData.tag = ScriptTag::UNDEFINED;
    m_botData[sender].scriptData.isActive = false;
    m_botData[sender].scriptData.scriptMaxTime = INVALID;
    m_botData[sender].scriptData.sequence = 0;
    m_botData[sender].scriptData.toExecute.clear();
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
    lua_State *lua;
    lua = luaL_newstate();
    luaL_openlibs(lua);

    if(luaL_dostring(lua, m_botData[sender].scriptData.fileContent.toStdString().c_str()) != 0)
    {
        error(sender) << lua_tostring(lua, -1);
        unloadFile(sender);
        return 1;
    }

    else
    {
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

QList<MapSide> ScriptModule::getSides(QString side)
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

void ScriptModule::convertToFunction(ScriptPathMapData &s)
{
    ScriptFunction func;

    QVariantList l;
    QVariantList p;
    foreach (MapSide side, s.sides)
        l << (int)side;

    p.insert(p.end(), l);

    func.params = p;
    func.type = ScriptFunctionEnum::CHANGEMAP;

    if (!s.sides.isEmpty())
        s.functions.append(func);
}

void ScriptModule::setActivePath(SocketIO *sender, bool active)
{
    m_botData[sender].scriptData.isActive = active;
}

void ScriptModule::setPodsLimit(SocketIO *sender, ushort ratio)
{
    if(ratio >= 0 && ratio <= 100)
        m_botData[sender].scriptData.podsLimitRatio = ratio;
}
