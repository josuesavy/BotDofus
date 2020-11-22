#include "GameInitializationFrame.h"

GameInitializationFrame::GameInitializationFrame(QMap<SocketIO *, BotData> *connectionsData, GroupManager *groupManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_groupManager(groupManager)
{

}

void GameInitializationFrame::reset(SocketIO *sender)
{

}

bool GameInitializationFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERCAPABILITIESMESSAGE:
        break;

    case MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE:
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;

        if(!m_botData[sender].connectionData.connectionInfos.masterGroup.isEmpty())
        {
            m_groupManager->updateTeams();
        }
    }
        break;
    }

    return messageFound;
}
