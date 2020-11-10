#include "MapModule.h"

MapModule::MapModule(QMap<SocketIO*, BotData> *connectionsData):
    AbstractModule(ModuleType::MAP, connectionsData)
{
    qRegisterMetaType<QList<ChangeMapRequest>>("QList<ChangeMapRequest>");
}

MapModule::~MapModule()
{
}

void MapModule::reset(SocketIO *sender)
{
    m_botData[sender].mapData.botId = INVALID;
    m_botData[sender].mapData.requestedMaps.clear();
    m_botData[sender].mapData.confirmationRequest.timer.clear();
    m_botData[sender].mapData.map = D2PManagerSingleton::get()->getMap(0);
}

bool MapModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE:
    {
        GameRolePlayShowActorMessage message;
        message.deserialize(&reader);

        if(message.informations->getTypes().contains(ClassEnum::GAMEROLEPLAYCHARACTERINFORMATIONS))
        {
            QSharedPointer<GameRolePlayCharacterInformations> rolePlay = qSharedPointerCast<GameRolePlayCharacterInformations>(message.informations);

            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].entityId = rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].cellId = rolePlay->disposition->cellId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].level = rolePlay->alignmentInfos.characterPower - rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].direction = rolePlay->disposition->direction;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].name = rolePlay->name;


            if(rolePlay->contextualId != m_botData[sender].mapData.botId)
            {
                if(!m_botData[sender].statisticsData.countTotalMetPlayers.contains(rolePlay->name))
                    m_botData[sender].statisticsData.countTotalMetPlayers.append(rolePlay->name);
            }
        }

        else if(message.informations->getTypes().contains(ClassEnum::GAMEROLEPLAYGROUPMONSTERINFORMATIONS))
        {
            QSharedPointer<GameRolePlayGroupMonsterInformations> monsterGroup = qSharedPointerCast<GameRolePlayGroupMonsterInformations>(message.informations);

            MonsterGroup botMonsterGroup;
            botMonsterGroup.cellID = monsterGroup->disposition->cellId;
            botMonsterGroup.contextualID = monsterGroup->contextualId;

            int totalLevel = 0;

            QSharedPointer<MonsterData> monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monsterGroup->staticInfos->mainCreatureLightInfos.genericId));
            foreach(MonsterGradeData grade, monsterData->getGrades())
            {

                if(grade.getGrade() == monsterGroup->staticInfos->mainCreatureLightInfos.grade)
                {
                    Monster botMonster;
                    botMonster.id = monsterData->getId();
                    botMonster.level = grade.getLevel();

                    botMonsterGroup.monsters<<botMonster;

                    totalLevel += grade.getLevel();
                    break;
                }
            }

            foreach(QSharedPointer<MonsterInGroupInformations> monster, monsterGroup->staticInfos->underlings)
            {
                monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monster->genericId));

                foreach(MonsterGradeData grade, monsterData->getGrades())
                {
                    if(grade.getGrade() == monster->grade)
                    {
                        Monster botMonster;
                        botMonster.id = monsterData->getId();
                        botMonster.level = grade.getLevel();

                        botMonsterGroup.monsters<<botMonster;

                        totalLevel += grade.getLevel();
                        break;
                    }
                }
            }

            botMonsterGroup.level = totalLevel;

            m_botData[sender].mapData.monsterGroupsOnMap[monsterGroup->contextualId] = botMonsterGroup;
        }

    }
        break;

    case MessageEnum::GAMEMAPMOVEMENTMESSAGE:
    {
        GameMapMovementMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            if (m_botData[sender].mapData.botId == message.actorId)
            {
                m_botData[sender].mapData.confirmationRequest.elapsedTime.start();
                m_botData[sender].mapData.requestedPath.timer.start();
                m_botData[sender].mapData.confirmationRequest.timer->setSingleShot(true);
                m_botData[sender].mapData.confirmationRequest.timer->setInterval(m_botData[sender].mapData.confirmationRequest.estimatedTime);
                connect(m_botData[sender].mapData.confirmationRequest.timer.data(), SIGNAL(timeout()), this, SLOT(processConfirmation()));
                m_botData[sender].mapData.confirmationRequest.timer->start();

                if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }

            if(m_botData[sender].mapData.playersOnMap.contains(message.actorId))
            {
                m_botData[sender].mapData.playersOnMap[message.actorId].cellId = message.keyMovements.last();
                m_botData[sender].mapData.playersOnMap[message.actorId].keyMovements = message.keyMovements;
            }

            else if(m_botData[sender].mapData.monsterGroupsOnMap.contains(message.actorId))
            {
                m_botData[sender].mapData.monsterGroupsOnMap[message.actorId].cellID = message.keyMovements.last();
                m_botData[sender].mapData.monsterGroupsOnMap[message.actorId].keyMovements = message.keyMovements;
            }
        }
    }
        break;

    case MessageEnum::GAMEMAPNOMOVEMENTMESSAGE:
    {
        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            //qDebug() << "timer isNull?:" <<m_botData[sender].mapData.confirmationRequest.timer.isNull();

            m_botData[sender].mapData.confirmationRequest.timer->disconnect(); // QObject::disconnect: Unexpected null parameter (>=2 accounts)
            m_botData[sender].mapData.confirmationRequest.timer.clear();

            if(m_botData[sender].generalData.botState == MOVING_STATE)
                m_botData[sender].generalData.botState = INACTIVE_STATE;

            emit couldNotMove(sender);
        }
    }
        break;

    case MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE:
    {
        GameCautiousMapMovementMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
        {
            if (m_botData[sender].mapData.botId == message.actorId)
            {
                action(sender)<< "Vous êtes dans l'obligation de marcher";
                m_botData[sender].mapData.confirmationRequest.elapsedTime.start();
                m_botData[sender].mapData.requestedPath.timer.start();
                m_botData[sender].mapData.confirmationRequest.timer->setSingleShot(true);
                m_botData[sender].mapData.confirmationRequest.timer->setInterval(m_botData[sender].mapData.confirmationRequest.estimatedTime);
                connect(m_botData[sender].mapData.confirmationRequest.timer.data(), SIGNAL(timeout()), this, SLOT(processConfirmation()));
                m_botData[sender].mapData.confirmationRequest.timer->start();

                if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }
        }
    }
        break;

    case MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE:
    {
        MapComplementaryInformationsDataMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY &&  m_botData[sender].generalData.botState != FIGHTING_STATE)
            m_botData[sender].generalData.botState = INACTIVE_STATE;

        m_botData[sender].mapData.playersOnMap.clear();
        m_botData[sender].mapData.interactivesOnMap.clear();
        m_botData[sender].mapData.npcsOnMap.clear();
        m_botData[sender].mapData.monsterGroupsOnMap.clear();

        // Get interactive elements
        foreach(QSharedPointer<InteractiveElement> interactiveClass, message.interactiveElements)
        {
            if(interactiveClass->onCurrentMap)
            {
                InteractiveElementInfos mainElementInfos;
                mainElementInfos.elementId = interactiveClass->elementId;
                mainElementInfos.elementTypeId = interactiveClass->elementTypeId;

                // Enable skills
                foreach(QSharedPointer<InteractiveElementSkill> skill, interactiveClass->enabledSkills)
                {
                    InteractiveSkillInfos enabledInfos;
                    enabledInfos.ID = skill->skillId;
                    enabledInfos.UID = skill->skillInstanceUid;
                    mainElementInfos.enabledSkills<<enabledInfos;
                }

                // Disable skills
                foreach (QSharedPointer<InteractiveElementSkill> skill, interactiveClass->disabledSkills)
                {
                    InteractiveSkillInfos disabledInfos;
                    disabledInfos.ID = skill->skillId;
                    disabledInfos.UID = skill->skillInstanceUid;
                    mainElementInfos.disabledSkills<<disabledInfos;
                }

                m_botData[sender].mapData.interactivesOnMap<<mainElementInfos;

                m_botData[sender].interactionData.interactives.clear();
                foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
                {
                    InteractiveDisplayInfos i;
                    i.id = e.elementId;
                    i.cellId = m_botData[sender].mapData.map.getInteractiveElementCellID(e.elementId);

                    if(e.elementTypeId > 0 && e.elementTypeId < 337) // Le max c'est 336 pour les elements interactifs
                        i.name = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName();

                    m_botData[sender].interactionData.interactives << i;
                }

                if(interactiveClass->elementTypeId >= 0)
                {
                    QSharedPointer<InteractiveData> element = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, interactiveClass->elementTypeId));
                    qDebug()<<"InteractiveElement - Nom :"<<element->getName()<<" CellID :"<<m_botData[sender].mapData.map.getInteractiveElementCellID(interactiveClass->elementId)<<" TypeID :"<<interactiveClass->elementTypeId;
                }
            }
        }

        // Get actors in map
        foreach(QSharedPointer<GameRolePlayActorInformations> base, message.actors)
        {
            // Get players
            if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYCHARACTERINFORMATIONS))
            {
                QSharedPointer<GameRolePlayCharacterInformations> rolePlay = qSharedPointerCast<GameRolePlayCharacterInformations>(base);

                EntityInfos infos;
                infos.entityId = rolePlay->contextualId;
                infos.cellId = rolePlay->disposition->cellId;
                infos.level = rolePlay->alignmentInfos.characterPower - rolePlay->contextualId;
                infos.direction = rolePlay->disposition->direction;
                infos.name = rolePlay->name;
                infos.look = rolePlay->look;

                if(rolePlay->contextualId != m_botData[sender].mapData.botId)
                {
                    if(!m_botData[sender].statisticsData.countTotalMetPlayers.contains(rolePlay->name))
                        m_botData[sender].statisticsData.countTotalMetPlayers.append(rolePlay->name);
                }

                m_botData[sender].mapData.playersOnMap[infos.entityId] = infos;
                qDebug()<<"GameRolePlay - Nom :"<<infos.name<<" Niveau :"<<infos.level<<" CellID :"<<infos.cellId<<" ContextualID :"<<rolePlay->contextualId;
            }

            // Get NPC
            else if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYNPCINFORMATIONS))
            {
                QSharedPointer<GameRolePlayNpcInformations> npc = qSharedPointerCast<GameRolePlayNpcInformations>(base);

                NpcInfos infos;
                infos.npcId = npc->npcId;
                infos.contextualId = npc->contextualId;
                infos.cellId = npc->disposition->cellId;

                m_botData[sender].mapData.npcsOnMap[npc->npcId] = infos;
                qDebug()<<"NPC - Nom :"<<qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc->npcId))->getName()<<"CellId :"<<npc->disposition->cellId<<" ContextualID :"<<npc->contextualId;
            }

            // Get NPC with quest
            else if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYNPCWITHQUESTINFORMATIONS))
            {
                QSharedPointer<GameRolePlayNpcWithQuestInformations> npc = qSharedPointerCast<GameRolePlayNpcWithQuestInformations>(base);

                NpcQuestInfos infos;
                infos.npcId = npc->npcId;
                infos.contextualId = npc->contextualId;
                infos.cellId = npc->disposition->cellId;

                m_botData[sender].mapData.npcsQuestOnMap[npc->npcId] = infos;
                qDebug()<<"NPC QUEST - Nom :"<<qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc->npcId))->getName()<<"CellId :"<<npc->disposition->cellId<<" ContextualID :"<<npc->contextualId;
            }

            // Get merchants
            else if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYMERCHANTINFORMATIONS))
            {
                QSharedPointer<GameRolePlayMerchantInformations> merchant = qSharedPointerCast<GameRolePlayMerchantInformations>(base);

                MerchantInfos infos;
                infos.name = merchant->name;
                infos.merchantId = merchant->contextualId;
                infos.sellType = merchant->sellType;
                infos.options = merchant->options;
                infos.cellId = merchant->disposition->cellId;

                m_botData[sender].mapData.merchantsOnMap[merchant->sellType] = infos;
                qDebug()<<"MERCHANT - Nom :"<<infos.name<<"CellId :"<<infos.merchantId<<" ContextualID :"<<infos.merchantId;
            }

            // Get groups monsters
            else if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYGROUPMONSTERINFORMATIONS))
            {
                QSharedPointer<GameRolePlayGroupMonsterInformations> monsterGroup = qSharedPointerCast<GameRolePlayGroupMonsterInformations>(base);

                MonsterGroup botMonsterGroup;
                botMonsterGroup.cellID = monsterGroup->disposition->cellId;
                botMonsterGroup.contextualID = monsterGroup->contextualId;

                int totalLevel = 0;

                QSharedPointer<MonsterData> monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monsterGroup->staticInfos->mainCreatureLightInfos.genericId));
                foreach(MonsterGradeData grade, monsterData->getGrades())
                {

                    if(grade.getGrade() == monsterGroup->staticInfos->mainCreatureLightInfos.grade)
                    {
                        Monster botMonster;
                        botMonster.id = monsterData->getId();
                        botMonster.level = grade.getLevel();

                        botMonsterGroup.monsters<<botMonster;

                        totalLevel += grade.getLevel();
                        break;
                    }
                }

                foreach(QSharedPointer<MonsterInGroupInformations> monster, monsterGroup->staticInfos->underlings)
                {
                    monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monster->genericId));

                    foreach(MonsterGradeData grade, monsterData->getGrades())
                    {
                        if(grade.getGrade() == monster->grade)
                        {
                            Monster botMonster;
                            botMonster.id = monsterData->getId();
                            botMonster.level = grade.getLevel();

                            botMonsterGroup.monsters<<botMonster;

                            totalLevel += grade.getLevel();
                            break;
                        }
                    }
                }

                botMonsterGroup.level = totalLevel;

                m_botData[sender].mapData.monsterGroupsOnMap[monsterGroup->contextualId] = botMonsterGroup;

                qDebug()<<"GroupMonster - Nom du monstre p. :"<<qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monsterGroup->staticInfos->mainCreatureLightInfos.genericId))->getName() <<" Niveau du groupe :"<<totalLevel <<" N. de monstres :"<<monsterGroup->staticInfos->underlings.size()+1 <<" CellID :"<<monsterGroup->disposition->cellId <<" ContextualID :"<<monsterGroup->contextualId;
            }

            else
                qDebug() << "ERROR - MapModule don't found actor type.";
        }

        if(!m_botData[sender].mapData.requestedMaps.isEmpty())
        {
            MapSide side;

            if(m_botData[sender].mapData.map.getTopMapId() == m_botData[sender].mapData.requestedMaps.first().mapId)
                side = MapSide::TOP;

            else if(m_botData[sender].mapData.map.getBottomMapId() == m_botData[sender].mapData.requestedMaps.first().mapId)
                side = MapSide::BOTTOM;

            else if(m_botData[sender].mapData.map.getRightMapId() == m_botData[sender].mapData.requestedMaps.first().mapId)
                side = MapSide::RIGHT;

            else if(m_botData[sender].mapData.map.getLeftMapId() == m_botData[sender].mapData.requestedMaps.first().mapId)
                side = MapSide::LEFT;

            else
            {
                qDebug()<<"MapModule - Changement de zone à la carte";

                Map requestedMap = D2PManagerSingleton::get()->getMap(m_botData[sender].mapData.requestedMaps.first().mapId);

                if(m_botData[sender].mapData.map.getPosition().getX() == requestedMap.getPosition().getX() && m_botData[sender].mapData.map.getPosition().getY()-1 == requestedMap.getPosition().getY())
                {
                    side = MapSide::TOP;
                    m_botData[sender].mapData.requestedMaps[0].mapId = m_botData[sender].mapData.map.getTopMapId();
                }

                else if(m_botData[sender].mapData.map.getPosition().getX() == requestedMap.getPosition().getX() && m_botData[sender].mapData.map.getPosition().getY()+1 == requestedMap.getPosition().getY())
                {
                    side = MapSide::BOTTOM;
                    m_botData[sender].mapData.requestedMaps[0].mapId = m_botData[sender].mapData.map.getBottomMapId();
                }

                else if(m_botData[sender].mapData.map.getPosition().getX()+1 == requestedMap.getPosition().getX() && m_botData[sender].mapData.map.getPosition().getY() == requestedMap.getPosition().getY())
                {
                    side = MapSide::RIGHT;
                    m_botData[sender].mapData.requestedMaps[0].mapId = m_botData[sender].mapData.map.getRightMapId();
                }

                else if(m_botData[sender].mapData.map.getPosition().getX()-1 == requestedMap.getPosition().getX() && m_botData[sender].mapData.map.getPosition().getY() == requestedMap.getPosition().getY())
                {
                    side = MapSide::LEFT;
                    m_botData[sender].mapData.requestedMaps[0].mapId = m_botData[sender].mapData.map.getLeftMapId();
                }

                else
                    qDebug()<<"ERREUR - MapModule n'a pas de map"<<m_botData[sender].mapData.requestedMaps.first().mapId<< "autour de la"<< m_botData[sender].mapData.map.getMapId();
            }

            changeMap(sender, side, m_botData[sender].mapData.requestedMaps.first().cellId);
        }

        else if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
        {
            //action(sender)<<"Moving DONE";
            emit scriptActionDone(sender);
        }

        emit mapContentUpdated(sender);
    }
        break;

    case MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE:
    {
        GameContextRemoveElementMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.playersOnMap.remove(message.id);
        m_botData[sender].mapData.npcsOnMap.remove(message.id);
        m_botData[sender].mapData.monsterGroupsOnMap.remove(message.id);
        m_botData[sender].mapData.merchantsOnMap.remove(message.id);
        m_botData[sender].mapData.npcsQuestOnMap.remove(message.id);
    }
        break;

    case MessageEnum::GAMECONTEXTCREATEMESSAGE:
    {
        GameContextCreateMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.gameContext = (GameContextEnum)message.context;
    }
        break;

    case MessageEnum::CURRENTMAPMESSAGE:
    {
        CurrentMapMessage message;
        message.deserialize(&reader);

//        if(m_botData[sender].mapData.map.getMapId() != message.mapId)
//            debug(sender)<<"MAP CHANGE FROM "<<m_botData[sender].mapData.map.getPosition().getX()<<m_botData[sender].mapData.map.getPosition().getY()<<" TO "<<D2PManagerSingleton::get()->getMap(message.mapId).getPosition().getX()<<D2PManagerSingleton::get()->getMap(message.mapId).getPosition().getY();

        m_botData[sender].mapData.map = D2PManagerSingleton::get()->getMap(message.mapId);
        MapInformationsRequestMessage answer;
        answer.mapId = message.mapId;
        sender->send(answer);
    }
        break;

    case MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE:
    {
        GameContextRefreshEntityLookMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.playersOnMap[message.id].look = message.look;
    }
        break;

    case MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE:
    {
        CharacterLevelUpInformationMessage message;
        message.deserialize(&reader);

        info(sender) << message.name << "vient de passer niveau" << message.newLevel;
    }
        break;

    case MessageEnum::POPUPWARNINGMESSAGE:
    {
        PopupWarningMessage message;
        message.deserialize(&reader);

        warn(sender) << message.author << ":" << message.content;
        warn(sender) << "Détails :" << message.lockDuration;

        // TODO : Stop all actions if it's a modo :s
        stopMoving(sender);
    }
        break;

    case MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE:
    {
        m_botData[sender].mapData.objectGroundListAdded.clear();

        ObjectGroundListAddedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < message.cells.size(); i++)
            m_botData[sender].mapData.objectGroundListAdded.insert(message.cells.at(i), message.referenceIds.at(i));
    }
        break;

    case MessageEnum::OBJECTGROUNDADDEDMESSAGE:
    {
        ObjectGroundAddedMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.objectGroundListAdded.insert(message.cellId, message.objectGID);
    }
        break;

    case MessageEnum::OBJECTGROUNDREMOVEDMESSAGE:
    {
        ObjectGroundRemovedMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.objectGroundListAdded.remove(message.cell);
    }
        break;

    case MessageEnum::TELEPORTONSAMEMAPMESSAGE:
    {
        TeleportOnSameMapMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].mapData.botId != message.targetId)
        {

        }


//        info(sender) << "Vous vous êtes téléporté à côté de" << message.targetId;
    }
        break;
    }

    return messageFound;
}

void MapModule::stopMoving(SocketIO *sender)
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

bool MapModule::changeCell(SocketIO *sender, uint cellId)
{
    if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || (m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType()))
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

        QTime mesure;
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
}

bool MapModule::changeToNearestCell(SocketIO *sender, uint cellId)
{
    if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || (m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType()))
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

        QTime mesure;
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

bool MapModule::changeMap(SocketIO *sender, MapSide mapSide, int cellId)
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
//                qDebug() << "current:" << m_botData[sender].mapData.map.getMapId();
//                qDebug() << "subarea:" << m_botData[sender].mapData.map.getSubAreaId();
//                qDebug() << "position-> x:" << m_botData[sender].mapData.map.getPosition().getX() << "y:" << m_botData[sender].mapData.map.getPosition().getY();
//                qDebug() << "top:" << m_botData[sender].mapData.map.getTopMapId();
//                qDebug() << "left:" << m_botData[sender].mapData.map.getLeftMapId();
//                qDebug() << "right:" << m_botData[sender].mapData.map.getRightMapId();
//                qDebug() << "bottom:" << m_botData[sender].mapData.map.getBottomMapId();
            }

            // Fix: bug when you want to change map but it was not possible because there is map not exist
            if(!adjacentMap.isInit())
            {
                qDebug()<<"ERREUR - MapModule ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car il n'existe pas de map";
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


        qDebug()<<"ERREUR - MapModule ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car il n'existe pas de tel chemin";

        return false;
    }

    else
        qDebug()<<"ERREUR - MapModule ne peut pas faire changer le bot"<< m_botData[sender].connectionData.connectionInfos.character<<"de map car le bot est occupé";

    stopMoving(sender);
    error(sender)<<"Un bug est survenu, reset du module de deplacement";

    return false;
}

bool MapModule::changeMap(SocketIO *sender, int x, int y)
{
    QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
    QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

    return changeMap(sender, PathfindingMap::coordsToMapId(x, y, area->getSuperAreaId()));
}

bool MapModule::changeMap(SocketIO *sender, uint mapId)
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

void MapModule::processConfirmation()
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

            m_botData[i.key()].generalData.botState = INACTIVE_STATE;
            emit hasFinishedMoving(i.key());

            if (!m_botData[i.key()].mapData.requestedMaps.isEmpty())
            {
                i.value().mapData.requestedMaps.first().cellId;

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
        qDebug()<<"ERREUR - MapModule - processConfirmation - Sender not found";
}

void MapModule::processMapPath(QList<ChangeMapRequest> requestedMaps, SocketIO *sender)
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
                qDebug()<<"ERREUR - MapModule n'a pas de map"<<requestedMaps.first().mapId<<
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
        qDebug()<<"ERREUR - MapModule n'a pas trouvé de chemin pour la carte d'arrivée demandée";
        error(sender)<<"Le bot ne peut pas se rendre à la position demandée";
        emit couldNotMove(sender);
    }
}

Directions MapModule::processDirection(int character, int element)
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

void MapModule::changeDirection(SocketIO *sender, Directions dir)
{
    GameMapChangeOrientationRequestMessage message;
    message.direction = (uint)dir;
    sender->send(message);
}

void MapModule::rejoinCharacter(SocketIO *sender, QString character)
{
    FriendJoinRequestMessage message;
    message.name = character;
    sender->send(message);
}
