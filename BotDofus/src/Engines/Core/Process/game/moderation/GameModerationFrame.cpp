#include "GameModerationFrame.h"

GameModerationFrame::GameModerationFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameModerationFrame::reset(SocketIO *sender)
{

}

bool GameModerationFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
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
    }

    return messageFound;
}
