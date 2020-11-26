#include "ConnectionFrame.h"

ConnectionFrame::ConnectionFrame(QMap<SocketIO *, BotData> *connectionsData, ConnectionManager *connectionManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_connectionManager(connectionManager)
{

}

void ConnectionFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool ConnectionFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CREDENTIALSACKNOWLEDGEMENTMESSAGE:
        break;

    case MessageEnum::HELLOCONNECTMESSAGE:
    {
        HelloConnectMessage message;
        message.deserialize(&reader);

        info(sender) << "Connecté au serveur d'authentification.";
        action(sender) << "Envoi des informations d'identification..";

        IdentificationMessage imsg;
        imsg.version.major = (int)DofusVersion::MAJOR;
        imsg.version.minor = (int)DofusVersion::MINOR;
        imsg.version.code = (int)DofusVersion::CODE;
        imsg.version.build = (int)DofusVersion::BUILD;
        imsg.version.buildType = (int)BuildTypeEnum::RELEASE;
        imsg.autoconnect = false;
        imsg.useCertificate = false;
        imsg.useLoginToken = false;
        imsg.lang = "fr";
        imsg.serverId = 0;
        imsg.sessionOptionalSalt = 0;
        imsg.failedAttempts = QList<uint>();
        imsg.credentials = m_connectionManager->cipherRSA(sender, message.key, message.salt);
        sender->send(imsg);

        ClientKeyMessage ckmsg;
        ckmsg.key = m_connectionManager->getFlashKey();
        sender->send(ckmsg);
    }
        break;

    case MessageEnum::IDENTIFICATIONACCOUNTFORCEMESSAGE:
        break;

    case MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE:
    {
        IdentificationFailedBannedMessage message;
        message.deserialize(&reader);

        QSqlQuery query;
        query.prepare("UPDATE accounts SET isbanned = :isbanned WHERE login = :login");
        query.bindValue(":isbanned", 1);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        error(sender)<<"Connexion refusée. Votre compte est invalide jusqu'au" <<dateToString(message.banEndDate);
    }
        break;

    case MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE:
    {
        IdentificationFailedForBadVersionMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        QString oldVersion = QString("%1.%2.%3.%4").arg((int)DofusVersion::MAJOR).arg((int)DofusVersion::MINOR).arg((int)DofusVersion::CODE).arg((int)DofusVersion::BUILD);
        QString newVersion = QString("%1.%2.%3.%4").arg(message.requiredVersion.major).arg(message.requiredVersion.minor).arg(message.requiredVersion.code).arg(message.requiredVersion.build);

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.badVersion").arg(oldVersion).arg(newVersion);

        qDebug() << "INFOS - ConnectionModule : Bad version " << oldVersion << "->" << newVersion;

        sender->disconnect();
    }
        break;

    case MessageEnum::IDENTIFICATIONSUCCESSMESSAGE:
    {
        IdentificationSuccessMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.accountId = message.accountId;
        m_botData[sender].playerData.subscriptionEndDate = message.subscriptionEndDate;
        m_botData[sender].playerData.subscriptionElapsedDuration = message.subscriptionElapsedDuration;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET isbanned = :isbanned WHERE login = :login");
        query.bindValue(":isbanned", 0);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        if(message.wasAlreadyConnected)
            warn(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.connection.disconnectAccount");

        info(sender) << "Connecté avec succès.";
    }
        break;

    case MessageEnum::IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE:
        break;

    case MessageEnum::MIGRATEDSERVERLISTMESSAGE:
        break;

    case MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE:
    case MessageEnum::SELECTEDSERVERDATAMESSAGE:
    {
        SelectedServerDataMessage message;
        message.deserialize(&reader);

        QString arg = "Connecté sur "+message.address+":";

        foreach(int port, message.ports)
            arg+=QString::number(port)+", ";

        arg.remove(arg.lastIndexOf(", "), 2);
        info(sender) << arg;

        qDebug()<<"Server IP: "<<message.address;
        qDebug()<<"Ticket: "<<message.ticket;

        m_botData[sender].connectionData.connectionInfos.serverId = message.serverId;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET serverid = :serverid WHERE login = :login");
        query.bindValue(":serverid", message.serverId);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        Writer w;
        Reader tmp;
        QByteArray data;
        for (int i = 0; i < message.ticket.size(); i++)
            w.writeByte(message.ticket[i]);

        data = w.getBuffer();

        QByteArray _IV;
        tmp.setBuffer(m_botData[sender].connectionData.aesKey);
        _IV = tmp.readBytes(0, 16);
        std::vector<byte> IV(_IV.begin(), _IV.end());

        AesManager aes;
        std::string t(aes.AESDecrypt(data.data(), data.size(), m_botData[sender].connectionData.aesKey.data(), m_botData[sender].connectionData.aesKey.size(), IV));

        m_botData[sender].connectionData.ticket = QString::fromStdString(t);
        sender->switchServer(message.address);
    }
        break;

    case MessageEnum::SELECTEDSERVERREFUSEDMESSAGE:
    {
        SelectedServerRefusedMessage message;
        message.deserialize(&reader);

        QString m_error;

        switch ((ServerConnectionErrorEnum)message.error)
        {
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_DUE_TO_STATUS:
        {
            switch((ServerStatusEnum)message.serverStatus)
            {
            case ServerStatusEnum::OFFLINE:
                m_error = m_error + "Offline";
                break;
            case ServerStatusEnum::STARTING:
                m_error = m_error + "Starting";
                break;
            case ServerStatusEnum::NOJOIN:
                m_error = m_error + "Nojoin";
                break;
            case ServerStatusEnum::SAVING:
                m_error = "serverSaving";
                break;
            case ServerStatusEnum::STOPING:
                m_error = m_error + "Stoping";
                break;
            case ServerStatusEnum::FULL:
                m_error = m_error + "Full";
                break;
                //case ServerStatusEnum::STATUS_UNKNOWN:
            default:
                m_error = m_error + "Unknown";
                break;
            }
        }
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_ACCOUNT_RESTRICTED:
            m_error = "communityNonSubscriberRestricted";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_COMMUNITY_RESTRICTED:
            m_error = "communityRestricted";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_LOCATION_RESTRICTED:
            m_error = "locationRestricted";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_SUBSCRIBERS_ONLY:
            m_error = "communityOrSubscribersRestricted";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_REGULAR_PLAYERS_ONLY:
            m_error = "regularPlayerRestricted";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_MONOACCOUNT_CANNOT_VERIFY:
            m_error = "monoaccountNotVerified";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_MONOACCOUNT_ONLY:
            m_error = "monoaccountNotMono";
            break;
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_SERVER_OVERLOAD:
            m_error = "serverFull";
            break;
            //case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_NO_REASON:
        default:
            m_error = "NoReason";
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.server.cantChoose."+m_error);
        error(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.popup.connectionRefused");

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        sender->disconnect();
    }
        break;

    case MessageEnum::SERVERSLISTMESSAGE:
    {
        ServersListMessage message;
        message.deserialize(&reader);

        action(sender)<<"Réception de la liste des serveurs.";

        if(m_botData[sender].connectionData.connectionInfos.needToCreateCharacter && !m_botData[sender].connectionData.connectionInfos.characterCreated)
        {
            QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.creation.server));
            action(sender)<<"Connexion au serveur"<<server->getName()+"...";

            ServerSelectionMessage answer;
            answer.serverId = m_botData[sender].connectionData.connectionInfos.creation.server;
            sender->send(answer);
        }

        else if(m_botData[sender].connectionData.connectionInfos.connectionTo == ConnectionTo::SERVER || m_botData[sender].connectionData.connectionInfos.serverId == INVALID)
        {
            QStringList items;

            foreach (const GameServerInformations &infos, message.servers)
            {
                if((GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_CLASSICAL || (GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_EPIC || (GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_HARDCORE)
                {
                    QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, infos.id));

                    items.append(QString("%1 - %2 (%3 pers.)").arg(infos.id).arg(server->getName()).arg(infos.charactersCount));
                }
            }

            bool ok;
            QString item = QInputDialog::getItem(nullptr, tr("Choisissez un serveur"), tr("Serveur :"), items, 0, false, &ok);
            if (ok && !item.isEmpty())
            {
                action(sender)<<"Connexion au serveur"<<item.split(" - ").at(1).split(" (").at(0)+"...";
                ServerSelectionMessage answer;
                answer.serverId = item.split(" - ").at(0).toUInt();
                sender->send(answer);
            }
            else
                sender->disconnect();
        }

        else
        {
            QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId));
            action(sender)<<"Connexion au serveur"<<server->getName()+"...";

            foreach (const GameServerInformations &infos, message.servers)
            {
                if (infos.id == m_botData[sender].connectionData.connectionInfos.serverId)
                {
                    QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId));

                    switch ((ServerStatusEnum)infos.status)
                    {
                    case ServerStatusEnum::OFFLINE:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"hors-ligne";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;

                    case ServerStatusEnum::STARTING:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"en cours de démarrage";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;

                    case ServerStatusEnum::ONLINE:
                    {
                        ServerSelectionMessage answer;
                        answer.serverId = m_botData[sender].connectionData.connectionInfos.serverId;
                        sender->send(answer);
                    }
                        break;

                    case ServerStatusEnum::NOJOIN:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"injoignable";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;

                    case ServerStatusEnum::SAVING:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"en cours de sauvegarde";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;

                    case ServerStatusEnum::STOPING:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"en cours d'extinction";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;

                    case ServerStatusEnum::FULL:
                    {
                        warn(sender)<<"Serveur"<<server->getName()<<"complet";
                        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
                        sender->disconnect();
                    }
                        break;
                    }
                }
            }
        }
    }
        break;

    case MessageEnum::SERVERSTATUSUPDATEMESSAGE:
        break;
    }

    return messageFound;
}
