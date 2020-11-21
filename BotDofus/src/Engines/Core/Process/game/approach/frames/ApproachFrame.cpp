#include "ApproachFrame.h"

ApproachFrame::ApproachFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void ApproachFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool ApproachFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ACCOUNTCAPABILITIESMESSAGE:
        break;

    case MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE:
    {
        AccountLoggingKickedMessage message;
        message.deserialize(&reader);

        QSqlQuery query;
        query.prepare("UPDATE accounts SET isbanned = :isbanned WHERE login = :login");
        query.bindValue(":isbanned", 1);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        QString alertMessage = "Connexion refusée. Votre compte est invalide pendant ";

        if(message.days == 1)
            alertMessage += "1 jour ";

        else if(message.days > 1)
            alertMessage += QString::number(message.days)+" jours ";

        if(message.days > 0 && message.hours > 0 && message.minutes == 0)
            alertMessage += "et ";

        if(message.hours == 1)
            alertMessage += "1 heure ";

        else if(message.hours > 1)
            alertMessage += QString::number(message.hours)+" heures ";

        if(message.days > 0 || (message.hours > 0 && message.minutes > 0))
            alertMessage += "et ";

        if(message.minutes == 1)
            alertMessage += "1 minute";

        else if(message.minutes > 1)
            alertMessage += QString::number(message.days)+" minutes";


        error(sender)<<alertMessage;
    }
        break;

    case MessageEnum::ALREADYCONNECTEDMESSAGE:
        break;

    case MessageEnum::AUTHENTICATIONTICKETACCEPTEDMESSAGE:
    {
        //qDebug()<<"CONNEXION - Communication avec le serveur"<< qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId))->getName() << "etablie";
    }
        break;

    case MessageEnum::AUTHENTICATIONTICKETREFUSEDMESSAGE:
        break;

    case MessageEnum::HELLOGAMEMESSAGE:
    {
        info(sender) << "Connecté au serveur de jeu.";

        AuthenticationTicketMessage answer;
        answer.lang = "fr";
        answer.ticket = m_botData[sender].connectionData.ticket;
        sender->send(answer);
    }
        break;

    case MessageEnum::RELOGINTOKENSTATUSMESSAGE:
        break;

    case MessageEnum::SERVEROPTIONALFEATURESMESSAGE:
        break;

    case MessageEnum::SERVERSESSIONCONSTANTSMESSAGE:
        break;

    case MessageEnum::SERVERSETTINGSMESSAGE:
        break;
    }

    return messageFound;
}
