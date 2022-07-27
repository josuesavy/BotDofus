#include "GameModerationFrame.h"

GameModerationFrame::GameModerationFrame(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager):
    AbstractFrame(connectionsData),
    m_mapManager(mapManager)
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

        // TODO: make a timer for request close the popup, it will better human
        PopupWarningCloseRequestMessage answer;
        sender->send(answer);

        // TODO : Stop all actions if it's a modo :s
        m_mapManager->stopMoving(sender);
    }
        break;
    }

    return messageFound;
}
