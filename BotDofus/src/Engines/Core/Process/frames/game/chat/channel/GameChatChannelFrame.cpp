#include "GameChatChannelFrame.h"

GameChatChannelFrame::GameChatChannelFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameChatChannelFrame::reset(SocketIO *sender)
{

}

bool GameChatChannelFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ENABLEDCHANNELSMESSAGE:
        break;
    }

    return messageFound;
}
