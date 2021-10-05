#include "GameContextFightCharacterFrame.h"

GameContextFightCharacterFrame::GameContextFightCharacterFrame(QMap<SocketIO *, BotData> *connectionsData, FightManager *fightManager, GroupManager *groupManager):
    AbstractFrame(connectionsData),
    m_fightManager(fightManager),
    m_groupManager(groupManager)
{

}

bool GameContextFightCharacterFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE:
    {
        GameFightShowFighterMessage message;
        message.deserialize(&reader);

        m_fightManager->addFighter(sender, message.informations);

        if(!m_groupManager->getSlaves(sender).isEmpty())
        {
            QList<SocketIO*> slaves = m_groupManager->getSlaves(sender);
            QStringList names;

            foreach(SocketIO *slave, slaves)
                names << m_botData[slave].connectionData.connectionInfos.character;

            for(int i = 0; i < m_botData[sender].fightData.fighters.size(); i++)
            {
                if(m_botData[sender].fightData.fighters.values()[i].teamId == m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId && m_botData[sender].fightData.fighters.values()[i].cellId != m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId)
                    names.removeOne(m_botData[sender].fightData.fighters.values()[i].name);
            }

            if(names.isEmpty())
            {
                debug(sender)<<"Master ready to start fight with his"<<slaves.size()<<"slaves";
                GameFightReadyMessage answer;
                m_botData[sender].fightData.botFightData.isReady = true;
                answer.isReady = true;
                sender->send(answer);
            }
        }

        else
        {
            GameFightReadyMessage answer;
            m_botData[sender].fightData.botFightData.isReady = true;
            answer.isReady = true;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE:
    {
        GameFightShowFighterRandomStaticPoseMessage message;
        message.deserialize(&reader);

        m_fightManager->addFighter(sender, message.informations);
    }
        break;
    }

    return messageFound;
}
