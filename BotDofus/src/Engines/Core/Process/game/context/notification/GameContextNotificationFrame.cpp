#include "GameContextNotificationFrame.h"

GameContextNotificationFrame::GameContextNotificationFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextNotificationFrame::reset(SocketIO *sender)
{

}

bool GameContextNotificationFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::NOTIFICATIONBYSERVERMESSAGE:
    {
        NotificationByServerMessage message;
        message.deserialize(&reader);

        QList<QString> a;
        foreach(QString param, message.parameters)
            a.append(param);

        QSharedPointer<NotificationData> notif = qSharedPointerCast<NotificationData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NOTIFICATIONS, message.id));
        QString title = D2OManagerSingleton::get()->getI18N()->getText(notif->getTitleId());
        QString text = D2OManagerSingleton::get()->getI18N()->getText(notif->getMessageId());

        for(int i = 0; i < a.size(); i++)
            text.replace(text.indexOf("%"), 1, a[i-1]);

        warn(sender) << "<b>" << title << "</b>" << text;
    }
        break;
    }

    return messageFound;
}
