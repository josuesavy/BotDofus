#include "GameSubscriberFrame.h"

GameSubscriberFrame::GameSubscriberFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameSubscriberFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::SUBSCRIPTIONLIMITATIONMESSAGE:
    {
        SubscriptionLimitationMessage message;
        message.deserialize(&reader);


        QString text;

        switch((SubscriptionRequiredEnum)message.reason)
        {
        case SubscriptionRequiredEnum::LIMIT_ON_JOB_XP:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limitJobXp");
            break;
        case SubscriptionRequiredEnum::LIMIT_ON_JOB_USE:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limitJobXp");
            break;
        case SubscriptionRequiredEnum::LIMIT_ON_MAP:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limit");
            break;
        case SubscriptionRequiredEnum::LIMIT_ON_ITEM:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limitItem");
            break;
        case SubscriptionRequiredEnum::LIMIT_ON_VENDOR:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limitVendor");
            break;
//        case SubscriptionRequiredEnum::LIMIT_ON_HAVENBAG:
//            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limit");
//            break;
        case SubscriptionRequiredEnum::LIMITED_TO_SUBSCRIBER:
            text = D2OManagerSingleton::get()->getI18N()->getText("ui.payzone.limit");
            break;
        }

        info(sender) << text;
    }
        break;
    }

    return messageFound;
}
