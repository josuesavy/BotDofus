#include "SubscriptionFrame.h"

SubscriptionFrame::SubscriptionFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool SubscriptionFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ACCOUNTINFORMATIONSUPDATEMESSAGE:
        break;
    }

    return messageFound;
}
