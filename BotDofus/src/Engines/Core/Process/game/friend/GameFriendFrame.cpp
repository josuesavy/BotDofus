#include "GameFriendFrame.h"

GameFriendFrame::GameFriendFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameFriendFrame::reset(SocketIO *sender)
{

}

bool GameFriendFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::FRIENDADDFAILUREMESSAGE:
    {
        FriendAddFailureMessage message;
        message.deserialize(&reader);


        QString txt;

        switch((ListAddFailureEnum)message.reason)
        {
        case ListAddFailureEnum::LIST_ADD_FAILURE_UNKNOWN:
            txt = D2OManagerSingleton::get()->getI18N()->getText("ui.common.unknowReason");
            break;
        case ListAddFailureEnum::LIST_ADD_FAILURE_OVER_QUOTA:
            txt = D2OManagerSingleton::get()->getI18N()->getText("ui.social.friend.addFailureListFull");
            break;
        case ListAddFailureEnum::LIST_ADD_FAILURE_NOT_FOUND:
            txt = D2OManagerSingleton::get()->getI18N()->getText("ui.social.friend.addFailureNotFound");
            break;
        case ListAddFailureEnum::LIST_ADD_FAILURE_EGOCENTRIC:
            txt = D2OManagerSingleton::get()->getI18N()->getText("ui.social.friend.addFailureEgocentric");
            break;
        case ListAddFailureEnum::LIST_ADD_FAILURE_IS_DOUBLE:
            txt = D2OManagerSingleton::get()->getI18N()->getText("ui.social.friend.addFailureAlreadyInList");
            break;
        }
        error(sender) << txt;
    }
        break;

    case MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE:
        break;

    case MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE:
        break;

    case MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE:
        break;

    case MessageEnum::SPOUSESTATUSMESSAGE:
        break;
    }

    return messageFound;
}
