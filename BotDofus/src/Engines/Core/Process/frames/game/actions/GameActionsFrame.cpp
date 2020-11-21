#include "GameActionsFrame.h"

GameActionsFrame::GameActionsFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameActionsFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool GameActionsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ABSTRACTGAMEACTIONMESSAGE:
        break;

    case MessageEnum::ABSTRACTGAMEACTIONWITHACKMESSAGE:
        break;

    case MessageEnum::GAMEACTIONACKNOWLEDGEMENTMESSAGE:
        break;

    case MessageEnum::GAMEACTIONNOOPMESSAGE:
        break;

    case MessageEnum::GAMEACTIONSPAMMESSAGE:
        break;
    }

    return messageFound;
}
