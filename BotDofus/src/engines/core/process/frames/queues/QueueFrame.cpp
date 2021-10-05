#include "QueueFrame.h"

QueueFrame::QueueFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool QueueFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::LOGINQUEUESTATUSMESSAGE:
    {
        LoginQueueStatusMessage message;
        message.deserialize(&reader);

        if (message.position != 0)
        {
            action(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.queue.number").arg(message.position).arg(message.total);
        }
    }
        break;

    case MessageEnum::QUEUESTATUSMESSAGE:
    {
        QueueStatusMessage message;
        message.deserialize(&reader);

        if (message.position != 0)
        {
            action(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.queue.number").arg(message.position).arg(message.total);
        }
    }
        break;
    }

    return messageFound;
}
