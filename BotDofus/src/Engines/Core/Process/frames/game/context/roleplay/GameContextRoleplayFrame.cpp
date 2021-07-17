#include "GameContextRoleplayFrame.h"

GameContextRoleplayFrame::GameContextRoleplayFrame(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager, FloodManager *floodManager):
    AbstractFrame(connectionsData),
    m_mapManager(mapManager),
    m_floodManager(floodManager)
{

}

bool GameContextRoleplayFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
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

    case MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE:
    {
        GameRolePlayShowActorMessage message;
        message.deserialize(&reader);

        if (message.informations->contextualId  > 0)
        {
            QSharedPointer<GameRolePlayCharacterInformations> rolePlay = qSharedPointerCast<GameRolePlayCharacterInformations>(message.informations);

            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].entityId = rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].cellId = rolePlay->disposition->cellId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].level = rolePlay->alignmentInfos.characterPower - rolePlay->contextualId;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].direction = rolePlay->disposition->direction;
            m_botData[sender].mapData.playersOnMap[rolePlay->contextualId].name = rolePlay->name;

            if (m_botData[sender].floodData.channelList.contains(CHANNELPRIVATE))
            {
                if (m_botData[sender].generalData.botState == INACTIVE_STATE &&
                        (rolePlay->alignmentInfos.characterPower - rolePlay->contextualId) >= m_botData[sender].floodData.levelMin &&
                        (rolePlay->alignmentInfos.characterPower - rolePlay->contextualId) <= m_botData[sender].floodData.levelMax)
                {
                    QStringList splited = m_botData[sender].floodData.floodMessage.split("##", QString::SkipEmptyParts);
                    for (int i = 0; i < splited.size(); i++)
                    {
                        if (splited[i] == "NAME")
                            splited.replace(i, rolePlay->name);
                    }

                    QString randomPart = m_floodManager->randomizeFloodMessage();
                    m_floodManager->sendChatMessage(sender, splited.join(" ")+randomPart, rolePlay->name);
                }


                else if (m_botData[sender].generalData.botState != INACTIVE_STATE)
                    qDebug()<<"[GameContextRoleplayFrame] Cannot start the flood because the character is busy";
            }
        }

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

    case MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE:
    {
        MapComplementaryInformationsDataMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY &&  m_botData[sender].generalData.botState != FIGHTING_STATE)
            m_botData[sender].generalData.botState = INACTIVE_STATE;


        // Get interactive elements
        m_botData[sender].mapData.doorsOnMap.clear();
        m_botData[sender].mapData.interactivesOnMap.clear();

        foreach(QSharedPointer<InteractiveElement> interactiveClass, message.interactiveElements)
        {
//            QList<int> doorSkillIds = { 184, 183, 187, 198, 114 };
//            QList<int> doorTypeIds = { -1, 128, 168, 16 };

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

//                if (doorTypeIds.contains(interactiveClass->elementTypeId) && interactiveClass->enabledSkills.size() > 0 && doorSkillIds.contains(interactiveClass->enabledSkills.first()->skillId))
//                {
//                    QList<Layer> layers = m_botData[sender].mapData.map.getLayers();
//                    foreach (Layer layer, layers)
//                    {
//                        QList<MapCell> cells = layer.getCells();
//                        foreach (MapCell cell, cells)
//                        {
//                            QList<BasicElement> basicElements = cell.getElements();
//                            foreach (BasicElement basicElement, basicElements)
//                            {
//                                QSharedPointer<GraphicalElement> graphicalElement = qSharedPointerCast<GraphicalElement>(basicElement.getElementFromType());
//                                if (graphicalElement->getIdentifier() == interactiveClass->elementId)
//                                {
//                                    m_botData[sender].mapData.doorsOnMap<<mainElementInfos;
//                                }
//                            }
//                        }
//                    }
//                }

//                else
//                {
//                    m_botData[sender].mapData.interactivesOnMap<<mainElementInfos;
//                }

                if (interactiveClass->elementTypeId >= 0)
                {
                    QSharedPointer<InteractiveData> element = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, interactiveClass->elementTypeId));
                    qDebug()<<"[InteractiveElement] Name:"<<element->getName()<<" CellID:"<<m_botData[sender].mapData.map.getInteractiveElementCellID(interactiveClass->elementId)<<" TypeID:"<<interactiveClass->elementTypeId;
                }
            }
        }


        // Browser StatedElements
        foreach (StatedElement statedElement, message.statedElements)
        {
            if (statedElement.onCurrentMap)
            {
                m_botData[sender].mapData.map.getInteractiveElementCellID(statedElement.elementId);
            }
        }


        // Get actors in map
        m_botData[sender].mapData.playersOnMap.clear();
        m_botData[sender].mapData.npcsOnMap.clear();
        m_botData[sender].mapData.npcsQuestOnMap.clear();
        m_botData[sender].mapData.merchantsOnMap.clear();
        m_botData[sender].mapData.monsterGroupsOnMap.clear();

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
                qDebug()<<"GameRolePlay - Name:"<<infos.name<<" Level:"<<infos.level<<" CellID:"<<infos.cellId<<" ContextualID:"<<rolePlay->contextualId;
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
                qDebug()<<"NPC - Name:"<<qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc->npcId))->getName()<<"CellId:"<<npc->disposition->cellId<<" ContextualID:"<<npc->contextualId;
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
                qDebug()<<"NPC QUEST - Name:"<<qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc->npcId))->getName()<<"CellId:"<<npc->disposition->cellId<<" ContextualID:"<<npc->contextualId;
            }

            // Get merchants
            else if(base->getTypes().contains(ClassEnum::GAMEROLEPLAYMERCHANTINFORMATIONS))
            {
                QSharedPointer<GameRolePlayMerchantInformations> merchant = qSharedPointerCast<GameRolePlayMerchantInformations>(base);

                MerchantInfos infos;
                infos.name = merchant->name;
                infos.look = merchant->look;
                infos.direction = merchant->disposition->direction;
                infos.merchantId = merchant->contextualId;
                infos.sellType = merchant->sellType;
                infos.options = merchant->options;
                infos.cellId = merchant->disposition->cellId;

                m_botData[sender].mapData.merchantsOnMap[merchant->sellType] = infos;
                qDebug()<<"MERCHANT - Name:"<<infos.name<<"CellId:"<<infos.merchantId<<" ContextualID:"<<infos.merchantId;
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

                qDebug()<<"GroupMonster - monster's name p. :"<<qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, monsterGroup->staticInfos->mainCreatureLightInfos.genericId))->getName() <<" groupe's level :"<<totalLevel <<" number of monstres :"<<monsterGroup->staticInfos->underlings.size()+1 <<" CellID :"<<monsterGroup->disposition->cellId <<" ContextualID :"<<monsterGroup->contextualId;
            }

            else
                qDebug() << "[GameContextRoleplayFrame] Don't found actor type.";
        }


        m_botData[sender].interactionData.interactives.clear();
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
        {
            InteractiveDisplayInfos i;
            i.id = e.elementId;
            i.cellId = m_botData[sender].mapData.map.getInteractiveElementCellID(e.elementId);
            i.name = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName();

            m_botData[sender].interactionData.interactives << i;
        }

        foreach (InteractiveElementInfos interactiveElementInfos, m_botData[sender].mapData.doorsOnMap)
        {
            InteractiveDisplayInfos interactiveDisplayInfos;
            interactiveDisplayInfos.id = interactiveElementInfos.elementId;
            interactiveDisplayInfos.cellId = m_botData[sender].mapData.map.getInteractiveElementCellID(interactiveElementInfos.elementId);
            //interactiveDisplayInfos.name = qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, interactiveElementInfos.elementTypeId))->getName();

            m_botData[sender].interactionData.interactives << interactiveDisplayInfos;
        }

        foreach (uint npc, m_botData[sender].mapData.npcsOnMap.keys())
        {
            InteractiveDisplayInfos i;
            i.id = npc;
            i.cellId = m_botData[sender].mapData.npcsOnMap[npc].cellId;
            i.name = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc))->getName();

            m_botData[sender].interactionData.interactives << i;
        }

        foreach (uint npc, m_botData[sender].mapData.npcsQuestOnMap.keys())
        {
            InteractiveDisplayInfos i;
            i.id = npc;
            i.cellId = m_botData[sender].mapData.npcsQuestOnMap[npc].cellId;
            i.name = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, npc))->getName();

            m_botData[sender].interactionData.interactives << i;
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
                qDebug()<<"[GameContextRoleplayFrame] Changing the map area";

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
                    qDebug()<<"[GameContextRoleplayFrame] Don't have map"<<m_botData[sender].mapData.requestedMaps.first().mapId<< "around the"<< m_botData[sender].mapData.map.getMapId();
            }

            m_mapManager->changeMap(sender, side, m_botData[sender].mapData.requestedMaps.first().cellId);
        }

        else if(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE && m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == ManagerType::MAP)
        {
            //action(sender)<<"Moving DONE";
            emit scriptActionDone(sender);
        }

        emit m_mapManager->mapContentUpdated(sender);

        MapRunningFightListRequestMessage answer;
        sender->send(answer);
    }
        break;

    case MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE:
    {
        MapRunningFightListMessage message;
        message.deserialize(&reader);

        foreach(FightExternalInformations fight, message.fights)
        {
            foreach(FightTeamLightInformations team, fight.fightTeams)
            {
                if(team.hasGroupMember)
                {
                    GameFightJoinRequestMessage answer;
                    answer.fightId = fight.fightId;
                    answer.fighterId = team.leaderId;
                    sender->send(answer);

                    break;
                }
            }
        }
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
