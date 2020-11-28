#include "GameCharacterDeletionFrame.h"

GameCharacterDeletionFrame::GameCharacterDeletionFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
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
    }

    return messageFound;
}
