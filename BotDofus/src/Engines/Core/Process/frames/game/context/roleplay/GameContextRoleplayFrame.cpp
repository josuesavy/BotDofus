#include "GameContextRoleplayFrame.h"

GameContextRoleplayFrame::GameContextRoleplayFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayFrame::reset(SocketIO *sender)
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

                    QString randomPart = randomizeFloodMessage();
                    sendChatMessage(sender, splited.join(" ")+randomPart, rolePlay->name);
                }


                else if (m_botData[sender].generalData.botState != INACTIVE_STATE)
                    qDebug()<<"ERREUR - FloodModule ne peut lancer le flood car le bot est occupé";
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
