#include "WebAnkaboxFrame.h"

WebAnkaboxFrame::WebAnkaboxFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool WebAnkaboxFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::MAILSTATUSMESSAGE:
    {
        MailStatusMessage message;
        message.deserialize(&reader);

        QString str;
        if (message.unread > 1)
            str = QString("%1 messages non lu").arg(message.unread);
        else
            str = QString("%1 message non lu").arg(message.unread);

        action(sender) << str;
    }
        break;

    case MessageEnum::NEWMAILMESSAGE:
        break;
    }

    return messageFound;
}
