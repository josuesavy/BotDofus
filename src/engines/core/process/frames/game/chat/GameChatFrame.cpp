#include "GameChatFrame.h"

GameChatFrame::GameChatFrame(QMap<SocketIO *, BotData> *connectionsData, FightManager *fightManager):
    AbstractFrame(connectionsData),
    m_fightManager(fightManager)
{

}

bool GameChatFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHATERRORMESSAGE:
    {
        ChatErrorMessage message;
        message.deserialize(&reader);

        switch((ChatErrorEnum)message.reason)
        {
        case ChatErrorEnum::CHAT_ERROR_INTERIOR_MONOLOGUE:
        case ChatErrorEnum::CHAT_ERROR_INVALID_MAP:
        case ChatErrorEnum::CHAT_ERROR_NO_GUILD:
        case ChatErrorEnum::CHAT_ERROR_NO_PARTY:
        case ChatErrorEnum::CHAT_ERROR_RECEIVER_NOT_FOUND:
        case ChatErrorEnum::CHAT_ERROR_NO_PARTY_ARENA:
        case ChatErrorEnum::CHAT_ERROR_NO_TEAM:
        case ChatErrorEnum::CHAT_ERROR_NO_CHANNEL_COMMUNITY:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText(QString("ui.chat.error.%1").arg(message.reason));
            break;

        case ChatErrorEnum::CHAT_ERROR_ALLIANCE:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.chat.error.0");
            break;
        }
    }
        break;

    case MessageEnum::CHATSERVERCOPYMESSAGE:
    {
        ChatServerCopyMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();
        chat.output = "à <b>"+message.receiverName+"</b> : "+message.content+"";

        m_botData[sender].generalData.logMessages<<chat;
    }
        break;

    case MessageEnum::CHATSERVERMESSAGE:
    {
        ChatServerMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();
        if(message.channel == Channel::CHANNELPRIVATE)
            chat.output = "de <b>"+message.senderName+"</b> : "+message.content;
        else
            chat.output = "<b>"+message.senderName+"</b> : "+message.content;

        m_botData[sender].generalData.logMessages<<chat;

        if(message.content == "fight")
        {
            m_botData[sender].scriptData.activeModule = ManagerType::FIGHT;
            if(m_fightManager->processMonsters(sender))
                qDebug()<<"IS GOING TO FIGHT";

            else
                qDebug()<<"NO MONSTERS";
        }
    }
        break;

    case MessageEnum::CHATSERVERWITHOBJECTMESSAGE:
    {
        ChatServerWithObjectMessage message;
        message.deserialize(&reader);

        LogMessage chat;
        chat.channel = (Channel)message.channel;
        chat.timeStamp = QDateTime::currentDateTime().toTime_t();

        QString contentModified = message.content;
        foreach(QSharedPointer<ObjectItem> object, message.objects)
        {
            QSharedPointer<ItemData> itemData = D2OManagerSingleton::get()->getItem(object->objectGID);
            if(contentModified.contains("\uFFFC")) // Object replacement character
            {
                int index = contentModified.indexOf("\uFFFC");
                contentModified.replace(index,QString("\uFFFC").length(), "<b>["+itemData->getName()+"]</b>");
            }
        }

        if(message.channel == Channel::CHANNELPRIVATE)
            chat.output = "de <b>"+message.senderName+"</b> : "+contentModified;
        else
            chat.output = "<b>"+message.senderName+"</b> : "+contentModified;

        m_botData[sender].generalData.logMessages<<chat;
    }
        break;
    }

    return messageFound;
}
