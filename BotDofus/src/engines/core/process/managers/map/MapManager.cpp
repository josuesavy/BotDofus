#include "MapManager.h"

MapManager::MapManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::MAP, connectionsData)
{
    qRegisterMetaType<QList<ChangeMapRequest>>("QList<ChangeMapRequest>");

    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SKILLS))
    {
        QSharedPointer<SkillData> skill = qSharedPointerCast<SkillData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SKILLS, index));

        if (skill->getGatheredRessourceItem() == 0 || skill->getGatheredRessourceItem() == INVALID)
        {
            if (skill->getCraftableItemIds().isEmpty() && skill->getModifiableItemTypeIds().isEmpty())
            {
                if (skill->getCursor() == 0 || skill->getCursor() == 8)
                {
                    m_doorSkillIds << index;
                }
            }
        }
    }
}

MapManager::~MapManager()
{

}

void MapManager::reset(SocketIO *sender)
{
    m_botData[sender].mapData.botId = INVALID;
    m_botData[sender].mapData.requestedMaps.clear();
    m_botData[sender].mapData.confirmationRequest.timer.clear();
    m_botData[sender].mapData.map = D2PManagerSingleton::get()->getMap(0);
}

void MapManager::stopMoving(SocketIO *sender)
{
    if (m_pathfindingThreads.contains(sender))
    {
        m_pathfindingThreads[sender]->stopThread();

        if(m_pathfindingThreads[sender]->isRunning())
            m_pathfindingThreads[sender]->wait();

        delete m_pathfindingThreads[sender];
        m_pathfindingThreads.remove(sender);
    }

    if (!m_botData[sender].mapData.requestedMaps.isEmpty())
    {
        m_botData[sender].mapData.requestedMaps.clear();

        if(m_botData[sender].generalData.botState == MOVING_STATE)
        {
            m_botData[sender].mapData.confirmationRequest.timer->disconnect();
            m_botData[sender].mapData.confirmationRequest.timer.clear();

            double timeElapsed = m_botData[sender].mapData.requestedPath.timer.elapsed();
            double time = m_botData[sender].mapData.requestedPath.path.time;
            int index = m_botData[sender].mapData.requestedPath.path.path.size()-1;

            if(timeElapsed < time)
            {
                double size = m_botData[sender].mapData.requestedPath.path.path.size();
                double indexD = ((timeElapsed/time)*size);
                index = round(indexD);

                if(index > 1)
                    index--;
            }

            uint cellId = m_botData[sender].mapData.requestedPath.path.path[index];
            GameMapMovementCancelMessage answer;
            answer.cellId = cellId;
            sender->send(answer);
            m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId = cellId;

            m_botData[sender].generalData.botState = INACTIVE_STATE;
            emit hasFinishedMoving(sender);
        }
    }

    if(m_botData[sender].generalData.botState == CALCULATING_STATE)
        m_botData[sender].generalData.botState = INACTIVE_STATE;
}

bool MapManager::changeCell(SocketIO *sender, uint cellId)
{
    if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || (m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == ManagerType::MAP))
    {
        // Check if the bot is already in the cell
        if(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == cellId)
        {
            qDebug()<<"Déjà sur la cellule"<<cellId;
            return false;
        }

        // Define monster's cell for not walkable
        QList<uint> cells;
        foreach (MonsterGroup g, m_botData[sender].mapData.monsterGroupsOnMap)
            cells << g.cellID;

        // Define player's cell for not walkable
        foreach (EntityInfos p, m_botData[sender].mapData.playersOnMap)
            cells << p.cellId;

        // Define npc's cell for not walkable
        foreach(NpcInfos n, m_botData[sender].mapData.npcsOnMap)
            cells << n.cellId;

        // Define merchant's cell for not walkable
        foreach(MerchantInfos m, m_botData[sender].mapData.merchantsOnMap)
            cells << m.cellId;

        QElapsedTimer mesure;
        mesure.start();
        PathInfos path;
        Pathfinding pathfinding;
        path = pathfinding.findPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, cellId, m_botData[sender].mapData.map.getMapId(), false, true, cells);
        qDebug()<<"Temps pour trouver le chemin (ms):"<<mesure.elapsed()<<"("<<cellId<<")";

        if(path.path.size() != 0)
        {
            GameMapMovementRequestMessage answer;
            answer.mapId = m_botData[sender].mapData.map.getMapId();
            answer.keyMovements = path.path;
            sender->send(answer);
            qDebug()<<"Liste des ids du chemin :"<< path.path;

            PathInfos toSave;
            toSave.path = path.path;
            toSave.time = path.time;
            m_botData[sender].mapData.requestedPath.path = toSave;
            m_botData[sender].mapData.requestedPath.timer.start();

            MovingConfirmationRequest request;
            request.estimatedTime = path.time;
            request.elapsedTime.start();
            request.timer = QSharedPointer<QTimer>(new QTimer());
            m_botData[sender].mapData.confirmationRequest = request;

            m_botData[sender].generalData.botState = MOVING_STATE;

            return true;
        }

        return false;
    }

    return false;
}

bool MapManager::changeToNearestCell(SocketIO *sender, uint cellId)
{
    if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || (m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == ManagerType::MAP))
    {
        // Define monster's cell for not walkable
        QList<uint> cells;
        foreach (MonsterGroup g, m_botData[sender].mapData.monsterGroupsOnMap)
            cells << g.cellID;

        // Define player's cell for not walkable
        foreach (EntityInfos p, m_botData[sender].mapData.playersOnMap)
            cells << p.cellId;

        // Define npc's cell for not walkable
        foreach(NpcInfos n, m_botData[sender].mapData.npcsOnMap)
            cells << n.cellId;

        // Define merchant's cell for not walkable
        foreach(MerchantInfos m, m_botData[sender].mapData.merchantsOnMap)
            cells << m.cellId;

        QElapsedTimer mesure;
        mesure.start();
        NearestPathInfos path;
        Pathfinding pathfinding;
        path = pathfinding.findNearestPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, cellId, m_botData[sender].mapData.map.getMapId(), false, true, cells);
        qDebug()<<"Temps pour trouver le chemin (ms):"<<mesure.elapsed()<<"(near"<<cellId<<")";

        if(path.path.size() != 0)
        {
            // Request Dofus's server about change cell
            GameMapMovementRequestMessage answer;
            answer.mapId = m_botData[sender].mapData.map.getMapId();
            answer.keyMovements = path.path;
            sender->send(answer);
            qDebug()<<"Liste des ids du chemin :"<< path.path;

            // Save the infos the cells and time about change cell
            PathInfos toSave;
            toSave.path = path.path;
            toSave.time = path.time;
            m_botData[sender].mapData.requestedPath.path = toSave;
            m_botData[sender].mapData.requestedPath.timer.start();

            // Request Dofus's server about moving confirmation
            MovingConfirmationRequest request;
            request.estimatedTime = path.time;
            request.elapsedTime.start();
            request.timer = QSharedPointer<QTimer>(new QTimer());
            m_botData[sender].mapData.confirmationRequest = request;

            // Set bot state
            m_botData[sender].generalData.botState = MOVING_STATE;

            return true;
        }

        return false;
    }

    else
        return false;
}

bool MapManager::changeMap(SocketIO *sender, MapSide mapSide, int cellId)
{
    if (m_botData[sender].generalData.botState == INACTIVE_STATE)
    {
        QList<uint> edgeCells;

        if(cellId == INVALID)
        {
            QList<uint> adjacentCells;
            Map adjacentMap;

            if(mapSide == MapSide::TOP)
            {
                edgeCells<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13;
                adjacentCells<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559;
                adjacentMap = D2PManagerSingleton::get()->getMap(m_botData[sender].mapData.map.getTopMapId());
            }

            else if(mapSide == MapSide::BOTTOM)
            {
                edgeCells<<546<<547<<548<<549<<550<<551<<552<<553<<554<<555<<556<<557<<558<<559;
                adjacentCells<<0<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10<<11<<12<<13;
                adjacentMap = D2PManagerSingleton::get()->getMap(m_botData[sender].mapData.map.getBottomMapId());
            }

            else if(mapSide == MapSide::LEFT)
            {
                edgeCells<<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;
                adjacentCells<<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
                adjacentMap = D2PManagerSingleton::get()->getMap(m_botData[sender].mapData.map.getLeftMapId());
            }

            else if(mapSide == MapSide::RIGHT)
            {
                edgeCells<<27<<55<<83<<111<<139<<167<<195<<223<<251<<279<<307<<335<<363<<391<<419<<447<<475<<503<<531<<559;
                adjacentCells<<0<<28<<56<<84<<112<<140<<168<<196<<224<<252<<280<<308<<336<<364<<392<<420<<448<<476<<504<<532;
                adjacentMap = D2PManagerSingleton::get()->getMap(m_botData[sender].mapData.map.getRightMapId());
            }

            // Fix: bug when you want to change map but it was not possible because there is map not exist
            if(!adjacentMap.isInit())
            {
                qDebug()<<"ERROR - MapManager ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car il n'existe pas de map";
                return false;
            }

            // Remove cells that are not walkable and the one where the bot is currently there in the currently map
            for(int i = 0; i < edgeCells.size(); i++)
            {
                if ((!m_botData[sender].mapData.map.getCellData()[edgeCells[i]].isWalkable()) || (edgeCells[i] == m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId))
                {
                    edgeCells.removeAt(i);
                    adjacentCells.removeAt(i);
                    i--;
                }
            }


            int originalSize =  edgeCells.size();
            int deleteCount = 0;

            // Remove cells that are not walkable in the adjacent map
            for(int i = 0; i < originalSize; i++)
            {
                if(!adjacentMap.getCellData()[adjacentCells[i]].isWalkable())
                {
                    edgeCells.removeAt(i - deleteCount);
                    deleteCount++;
                }
            }
        }

        else
            edgeCells<<cellId;

        while(!edgeCells.isEmpty())
        {
            int randPosition = (rand() % (edgeCells.size()));
            qDebug()<<"Choix de la cellule d'arrivée :"<<edgeCells[randPosition];

            qDebug() << "ChangeMap";
            if(changeCell(sender, edgeCells[randPosition]))
            {
                uint requestedMap;

                if (mapSide == MapSide::TOP)
                    requestedMap = m_botData[sender].mapData.map.getTopMapId();

                else if (mapSide == MapSide::BOTTOM)
                    requestedMap = m_botData[sender].mapData.map.getBottomMapId();

                else if (mapSide == MapSide::LEFT)
                    requestedMap = m_botData[sender].mapData.map.getLeftMapId();

                else if (mapSide == MapSide::RIGHT)
                    requestedMap = m_botData[sender].mapData.map.getRightMapId();

                bool hasFound = false;
                foreach (const ChangeMapRequest &request, m_botData[sender].mapData.requestedMaps)
                {
                    if(request.mapId == requestedMap)
                    {
                        hasFound = true;
                        break;
                    }
                }

                if (!hasFound)
                {
                    ChangeMapRequest changeMap;
                    changeMap.mapId = requestedMap;
                    m_botData[sender].mapData.requestedMaps<<changeMap;
                }


                return true;
            }

            edgeCells.removeAt(randPosition);
        }


        qDebug()<<"ERREUR - MapManager ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car il n'existe pas de tel chemin";

        return false;
    }

    else
        qDebug()<<"ERREUR - MapManager ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car le bot est occupé";

    stopMoving(sender);
    error(sender)<<"Un bug est survenu, reset du module de deplacement";

    return false;
}

bool MapManager::changeMap(SocketIO *sender, int x, int y)
{
    QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
    QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

    return changeMap(sender, PathfindingMap::coordsToMapId(x, y, area->getSuperAreaId()));
}

bool MapManager::changeMap(SocketIO *sender, uint mapId)
{
    if((m_botData[sender].generalData.botState == INACTIVE_STATE || m_botData[sender].generalData.botState == MOVING_STATE || m_botData[sender].generalData.botState == CALCULATING_STATE) && m_botData[sender].mapData.map.getMapId() != mapId)
    {
        stopMoving(sender);
        m_botData[sender].generalData.botState = CALCULATING_STATE;

        m_pathfindingThreads[sender] = new PathfindingMap();
        connect(this, SIGNAL(findMapPath(uint,uint,int,SocketIO*)), m_pathfindingThreads[sender], SLOT(requestPath(uint,uint,int,SocketIO*)));
        connect(m_pathfindingThreads[sender], SIGNAL(foundPath(QList<ChangeMapRequest>,SocketIO*)), this, SLOT(processMapPath(QList<ChangeMapRequest>,SocketIO*)));
        m_pathfindingThreads[sender]->start();

        emit findMapPath(m_botData[sender].mapData.map.getMapId(), mapId, m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, sender);

        disconnect(this, SIGNAL(findMapPath(uint,uint,int,SocketIO*)), m_pathfindingThreads[sender], SLOT(requestPath(uint,uint,int,SocketIO*)));

        return true;
    }

    return false;
}

void MapManager::processConfirmation()
{
    QTimer *timer = static_cast<QTimer*>(QObject::sender());
    bool found = false;

    QMapIterator<SocketIO*, BotData> i(m_botData);

    while (i.hasNext())
    {
        i.next();

        if(i.value().mapData.confirmationRequest.timer == timer)
        {
            found = true;

            timer->disconnect();

            if (i.value().generalData.botState == MOVING_STATE)
            {
                GameMapMovementConfirmMessage answer;
                i.key()->send(answer);
            }

            m_botData[i.key()].mapData.playersOnMap[m_botData[i.key()].mapData.botId].keyMovements.clear();
            m_botData[i.key()].generalData.botState = INACTIVE_STATE;
            emit hasFinishedMoving(i.key());

            if (!m_botData[i.key()].mapData.requestedMaps.isEmpty())
            {
                //i.value().mapData.requestedMaps.first().cellId;

                ChangeMapMessage answer2;
                answer2.mapId = i.value().mapData.requestedMaps.first().mapId;
                answer2.autopilot = false;
                i.key()->send(answer2);

                m_botData[i.key()].generalData.botState = MAP_TRANSITION_STATE;
                m_botData[i.key()].mapData.requestedMaps.removeFirst();
            }

            m_botData[i.key()].mapData.confirmationRequest.timer.clear();
            break;
        }
    }

    if(!found)
        qDebug()<<"ERROR - MapManager - processConfirmation - Sender not found";
}

void MapManager::processMapPath(QList<ChangeMapRequest> requestedMaps, SocketIO *sender)
{
    m_botData[sender].generalData.botState = INACTIVE_STATE;
    stopMoving(sender);

    if(!requestedMaps.isEmpty())
    {
        MapSide side = MapSide::NONE;

        if(m_botData[sender].mapData.map.getTopMapId() == requestedMaps.first().mapId)
            side = MapSide::TOP;

        else if(m_botData[sender].mapData.map.getBottomMapId() == requestedMaps.first().mapId)
            side = MapSide::BOTTOM;

        else if(m_botData[sender].mapData.map.getRightMapId() == requestedMaps.first().mapId)
            side = MapSide::RIGHT;

        else if(m_botData[sender].mapData.map.getLeftMapId() == requestedMaps.first().mapId)
            side = MapSide::LEFT;


        else
        {
            Map requestedMap = D2PManagerSingleton::get()->getMap(requestedMaps.first().mapId);

            if(m_botData[sender].mapData.map.getPosition().getX() == requestedMap.getPosition().getX()
                    && m_botData[sender].mapData.map.getPosition().getY()-1 == requestedMap.getPosition().getY())
            {
                side = MapSide::TOP;
            }

            else if(m_botData[sender].mapData.map.getPosition().getX() == requestedMap.getPosition().getX()
                    && m_botData[sender].mapData.map.getPosition().getY()+1 == requestedMap.getPosition().getY())
            {
                side = MapSide::BOTTOM;
            }


            else if(m_botData[sender].mapData.map.getPosition().getX()+1 == requestedMap.getPosition().getX()
                    && m_botData[sender].mapData.map.getPosition().getY() == requestedMap.getPosition().getY())
            {
                side = MapSide::RIGHT;
            }


            else if(m_botData[sender].mapData.map.getPosition().getX()-1 == requestedMap.getPosition().getX()
                    && m_botData[sender].mapData.map.getPosition().getY() == requestedMap.getPosition().getY())
            {
                side = MapSide::LEFT;
            }

            else
            {
                qDebug()<<"ERREUR - MapManager n'a pas de map"<<requestedMaps.first().mapId<<
                          "autour de la"<< m_botData[sender].mapData.map.getMapId();

                stopMoving(sender);
                error(sender)<<"Un bug est survenu, reset du module de deplacement";
            }
        }

        if(side != MapSide::NONE)
            changeMap(sender, side, requestedMaps.first().cellId);

        requestedMaps.removeFirst();
        m_botData[sender].mapData.requestedMaps<<requestedMaps;
    }

    else
    {
        qDebug()<<"ERREUR - MapManager n'a pas trouvé de chemin pour la carte d'arrivée demandée";
        error(sender)<<"Le bot ne peut pas se rendre à la position demandée";
        emit couldNotMove(sender);
    }
}

Directions MapManager::processDirection(int character, int element)
{
    QPoint characterPos(Pathfinding::getCoordinates(character).first, Pathfinding::getCoordinates(character).second);
    QPoint elementPos(Pathfinding::getCoordinates(element).first, Pathfinding::getCoordinates(element).second);

    int a = elementPos.x() - characterPos.x();
    int b = characterPos.y() - elementPos.y();
    int c = acos(a / sqrt(pow(a, 2) + pow(b, 2))) * 180 / M_PI * (elementPos.y() > characterPos.y() ? -1 : 1);
    c = round(c / 45) + 1;

    if (c < 0)
        c += 8;

    return (Directions)c;
}

void MapManager::changeDirection(SocketIO *sender, Directions dir)
{
    GameMapChangeOrientationRequestMessage message;
    message.direction = (uint)dir;
    sender->send(message);
}

void MapManager::rejoinCharacter(SocketIO *sender, QString character)
{
    QSharedPointer<PlayerSearchCharacterNameInformation> playerSearchCharacterNameInformation = QSharedPointer<PlayerSearchCharacterNameInformation>(new PlayerSearchCharacterNameInformation);;
    playerSearchCharacterNameInformation->name = character;

    FriendJoinRequestMessage message;
    message.target = playerSearchCharacterNameInformation;
    sender->send(message);
}

QList<int> MapManager::getDoorSkillIds()
{
    return m_doorSkillIds;
}
