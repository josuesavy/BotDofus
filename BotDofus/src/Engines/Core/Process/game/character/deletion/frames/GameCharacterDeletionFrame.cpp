#include "GameCharacterDeletionFrame.h"

GameCharacterDeletionFrame::GameCharacterDeletionFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameCharacterDeletionFrame::reset(SocketIO *sender)
{

}

bool GameCharacterDeletionFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERDELETIONERRORMESSAGE:
        break;
    }

    return messageFound;
}
