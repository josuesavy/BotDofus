#include "GameApproachFrame.h"

GameApproachFrame::GameApproachFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameApproachFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool GameApproachFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
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

    case MessageEnum::HELLOGAMEMESSAGE:
    {
        info(sender) << "Connecté au serveur de jeu.";

        AuthenticationTicketMessage answer;
        answer.lang = "fr";
        answer.ticket = m_botData[sender].connectionData.ticket;
        sender->send(answer);
    }
        break;
    }

    return messageFound;
}
