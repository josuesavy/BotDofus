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
                if (skill->getCursor() == 0 || skill->getCursor() == 8 || skill->getCursor() == 11)
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
    if(m_botData.contains(sender))
    {
        m_botData[sender].mapData.botId = INVALID;
        m_botData[sender].mapData.requestedMaps.clear();
        m_botData[sender].mapData.confirmationRequest.timer.clear();
        m_botData[sender].mapData.map = D2PManagerSingleton::get()->getMap(0);
    }

    else
        qDebug()<<"[ERROR] (MapManager) reset: this connection is unknown.";
}

void MapManager::stopMoving(SocketIO *sender)
{
    if(m_botData.contains(sender))
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

    else
        qDebug()<<"[ERROR] (MapManager) stopMoving: this connection is unknown.";
}

bool MapManager::changeCell(SocketIO *sender, uint cellId)
{
    if (m_botData.contains(sender))
    {
        if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || (m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == ManagerType::MAP))
        {
            // Check if the bot is already in the cell
            if(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == cellId)
            {
                qDebug()<<"[WARNING] (MapManager) changeCell: Already on the cell"<<cellId;
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

            Pathfinder pathfinder;
            pathfinder.setMap(m_botData[sender].mapData.map, cells, true);
            QList<QSharedPointer<NodeWithOrientation>> paths = pathfinder.getPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, cellId);
            path.path = PathingUtils::getCompressedPath(paths);
            path.time = PathingUtils::processTime(paths, false);
            qDebug()<<"[INFO] (MapManager) changeCell: Time for find the path (ms):"<<mesure.elapsed()<<"("<<cellId<<")";

            if(path.path.size() != 0)
            {
                GameMapMovementRequestMessage answer;
                answer.mapId = m_botData[sender].mapData.map.getMapId();
                answer.keyMovements = path.path;
                sender->send(answer);
                qDebug()<<"[INFO] (MapManager) changeCell: List of path ids :"<< path.path;

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
        }

        return false;
    }

    else
        qDebug()<<"[ERROR] (MapManager) changeCell: this connection is unknown.";

    return false;
}

bool MapManager::changeToNearestCell(SocketIO *sender, uint cellId)
{
    if (m_botData.contains(sender))
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
            Pathfinder pathfinder;
            pathfinder.setMap(m_botData[sender].mapData.map, cells, true);
            QList<QSharedPointer<NodeWithOrientation>> paths = pathfinder.getPath(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, cellId);
            path.path = PathingUtils::getCompressedPath(paths);
            path.time = PathingUtils::processTime(paths, false);

            qDebug()<<"[INFO] (MapManager) changeToNearestCell: Time for find the path (ms):"<<mesure.elapsed()<<"(near"<<cellId<<")";

            if(path.path.size() != 0)
            {
                // Request Dofus's server about change cell
                GameMapMovementRequestMessage answer;
                answer.mapId = m_botData[sender].mapData.map.getMapId();
                answer.keyMovements = path.path;
                sender->send(answer);
                qDebug()<<"[INFO] (MapManager) changeToNearestCell: List of path ids :"<< path.path;

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

    else
        qDebug()<<"[ERROR] (MapManager) changeToNearestCell: this connection is unknown.";

    return false;
}

bool MapManager::changeMap(SocketIO *sender, MapSide mapSide, int cellId)
{
    if (m_botData.contains(sender))
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

                if(!adjacentMap.isInit())
                {
                    QSharedPointer<MapScrollActionData> mapScrollActionData = qSharedPointerCast<MapScrollActionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MAPSCROLLACTIONS, m_botData[sender].mapData.map.getMapId()));
                    if (mapScrollActionData)
                    {
                        if(mapSide == MapSide::TOP && mapScrollActionData->getTopExists())
                            adjacentMap = D2PManagerSingleton::get()->getMap(mapScrollActionData->getTopMapId());

                        else if(mapSide == MapSide::BOTTOM && mapScrollActionData->getBottomExists())
                            adjacentMap = D2PManagerSingleton::get()->getMap(mapScrollActionData->getBottomMapId());

                        else if(mapSide == MapSide::LEFT && mapScrollActionData->getLeftExists())
                            adjacentMap = D2PManagerSingleton::get()->getMap(mapScrollActionData->getLeftMapId());

                        else if(mapSide == MapSide::RIGHT && mapScrollActionData->getRightExists())
                            adjacentMap = D2PManagerSingleton::get()->getMap(mapScrollActionData->getRightMapId());


                        if (!adjacentMap.isInit())
                        {
                            qDebug()<<"[ERROR] (MapManager) changeMap: Cannot change the"<< m_botData[sender].connectionData.connectionInfos.character<<"bot from map because there is no map";
                            return false;
                        }
                    }
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

                QList<uint> backUpEdgeCells = edgeCells;
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

                // If on the adjacent map there are nothing cell walkable adjacent
                // to the cells walkable on the current map but the adjacent map really exist
                // we backup the cell walkable on the current map allow to change map
                if (edgeCells.isEmpty())
                    edgeCells = backUpEdgeCells;
            }

            else
                edgeCells<<cellId;

            while(!edgeCells.isEmpty())
            {
                int randPosition = (rand() % (edgeCells.size()));
                qDebug()<<"[INFO] (MapManager) changeMap: Choice of end cell:"<<edgeCells[randPosition];

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


            qDebug()<<"[ERROR] (MapManager) changeMap: cannot change the"<< m_botData[sender].connectionData.connectionInfos.character<<"bot to map because there is no such path";

            return false;
        }

        else
            qDebug()<<"[ERROR] (MapManager) changeMap: cannot change the"<< m_botData[sender].connectionData.connectionInfos.character<<"bot to map because he is busy";

        stopMoving(sender);
        error(sender)<<"An error has occurred, reset the displacement module";

        return false;
    }

    else
        qDebug()<<"[ERROR] (MapManager) changeMap: this connection is unknown.";

    return false;
}

bool MapManager::changeMap(SocketIO *sender, int x, int y)
{
    if (m_botData.contains(sender))
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        return changeMap(sender, PathfindingMap::coordsToMapId(x, y, area->getSuperAreaId()));
    }

    else
        qDebug()<<"[ERROR] (MapManager) changeMap: this connection is unknown.";

    return false;
}

bool MapManager::changeMap(SocketIO *sender, uint mapId)
{
    if (m_botData.contains(sender))
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

    else
        qDebug()<<"[ERROR] (MapManager) changeMap: this connection is unknown.";

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

                if (m_botData[i.key()].mapData.playersOnMap[m_botData[i.key()].mapData.botId].cellId == m_botData[i.key()].mapData.requestedPath.path.path.last())
                {
                    ChangeMapMessage answer2;
                    answer2.mapId = i.value().mapData.requestedMaps.first().mapId;
                    answer2.autopilot = false;
                    i.key()->send(answer2);
                }

                m_botData[i.key()].generalData.botState = MAP_TRANSITION_STATE;
                m_botData[i.key()].mapData.requestedMaps.removeFirst();
            }

            m_botData[i.key()].mapData.confirmationRequest.timer.clear();
            break;
        }
    }

    if(!found)
        qDebug()<<"[ERROR] (MapManager) processConfirmation: connection not found";
}

void MapManager::processMapPath(QList<ChangeMapRequest> requestedMaps, SocketIO *sender)
{
    if (m_botData.contains(sender))
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
                    qDebug()<<"[ERROR] (MapManager) processMapPath: has no map"<<requestedMaps.first().mapId<<
                              "around the"<< m_botData[sender].mapData.map.getMapId();

                    stopMoving(sender);
                    error(sender)<<"An error has occurred, reset the displacement module";
                }
            }

            if(side != MapSide::NONE)
                changeMap(sender, side, requestedMaps.first().cellId);

            requestedMaps.removeFirst();
            m_botData[sender].mapData.requestedMaps<<requestedMaps;
        }

        else
        {
            qDebug()<<"[ERROR] (MapManager) processMapPath: no path found for the requested arrival map.";
            error(sender)<<"The bot cannot get to the requested position";
            emit couldNotMove(sender);
        }
    }

    else
        qDebug()<<"[ERROR] (MapManager) processMapPath: this connection is unknown.";
}

void MapManager::changeDirection(SocketIO *sender, Directions dir)
{
    if (m_botData.contains(sender))
    {
        GameMapChangeOrientationRequestMessage message;
        message.direction = (uint)dir;
        sender->send(message);
    }

    else
        qDebug()<<"[ERROR] (MapManager) changeDirection: this connection is unknown.";
}

void MapManager::rejoinCharacter(SocketIO *sender, QString character)
{
    if (m_botData.contains(sender))
    {
        QSharedPointer<PlayerSearchCharacterNameInformation> playerSearchCharacterNameInformation = QSharedPointer<PlayerSearchCharacterNameInformation>(new PlayerSearchCharacterNameInformation);;
        playerSearchCharacterNameInformation->name = character;

        FriendJoinRequestMessage message;
        message.target = playerSearchCharacterNameInformation;
        sender->send(message);
    }

    else
        qDebug()<<"[ERROR] (MapManager) rejoinCharacter: this connection is unknown.";
}

QList<int> MapManager::getDoorSkillIds()
{
    return m_doorSkillIds;
}
