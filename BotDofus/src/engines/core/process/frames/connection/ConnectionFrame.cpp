#include "ConnectionFrame.h"

ConnectionFrame::ConnectionFrame(QMap<SocketIO *, BotData> *connectionsData, ConnectionManager *connectionManager):
    AbstractFrame(connectionsData),
    m_connectionManager(connectionManager)
{

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

        qDebug() << "[ConnectionFrame] Bad version " << oldVersion << "->" << newVersion;

        sender->disconnect();
    }
        break;

    case MessageEnum::IDENTIFICATIONFAILEDMESSAGE:
    {
        IdentificationFailedMessage message;
        message.deserialize(&reader);

        QString failReason;
        switch ((IdentificationFailureReasonEnum)message.reason)
        {

        case IdentificationFailureReasonEnum::BAD_VERSION:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.badVersion");
            break;

        case IdentificationFailureReasonEnum::WRONG_CREDENTIALS:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.wrongCredentials");
            break;

        case IdentificationFailureReasonEnum::BANNED:
        {
            QSqlQuery query;
            query.prepare("UPDATE accounts SET isbanned = :isbanned WHERE login = :login");
            query.bindValue(":isbanned", 1);
            query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
            query.exec();

            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.banned");
        }
            break;

        case IdentificationFailureReasonEnum::KICKED:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.kicked");
            break;

        case IdentificationFailureReasonEnum::IN_MAINTENANCE:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.inMaintenance");
            break;

        case IdentificationFailureReasonEnum::TOO_MANY_ON_IP:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.toomanyonip");
            break;

        case IdentificationFailureReasonEnum::TIME_OUT:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.timeout");
            break;

        case IdentificationFailureReasonEnum::BAD_IPRANGE:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.badIpRange");
            break;

        case IdentificationFailureReasonEnum::CREDENTIALS_RESET:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.credentialsReset");
            break;

        case IdentificationFailureReasonEnum::EMAIL_UNVALIDATED:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.unvalidatedEmail");
            break;

        case IdentificationFailureReasonEnum::OTP_TIMEOUT:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.otpTimeout");
            break;

        case IdentificationFailureReasonEnum::LOCKED:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.locked");
            break;

        case IdentificationFailureReasonEnum::ANONYMOUS_IP_FORBIDDEN:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.anonymousIp");
            break;

        case IdentificationFailureReasonEnum::SERVICE_UNAVAILABLE:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.serviceUnavailable");
            break;

        case IdentificationFailureReasonEnum::EXTERNAL_ACCOUNT_LINK_REFUSED:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.guestAccountNotFound");
            break;

        case IdentificationFailureReasonEnum::EXTERNAL_ACCOUNT_ALREADY_LINKED:
            break;

        case IdentificationFailureReasonEnum::UNKNOWN_AUTH_ERROR:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied.unknown");
            break;

        case IdentificationFailureReasonEnum::SPARE:
            failReason = "Erreur de connexion inconnue : Spare";
            break;

        default:
            failReason = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.accessDenied");
        break;
        }

        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        error(sender)<<failReason;
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

    case MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE:
    case MessageEnum::SELECTEDSERVERDATAMESSAGE:
    {
        SelectedServerDataMessage message;
        message.deserialize(&reader);

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
            case ServerStatusEnum::STATUS_UNKNOWN:
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
        case ServerConnectionErrorEnum::SERVER_CONNECTION_ERROR_NO_REASON:
        default:
            m_error = "NoReason";
            break;
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.server.cantChoose."+m_error);
        error(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.popup.connectionRefused");

        QSqlQuery query;
        query.prepare("SELECT idaccounts FROM accounts WHERE login = (:login)");
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);

        if (query.exec())
        {
            if (query.next())
            {
                int idAccount = query.value(0).toInt();

                query.prepare("DELETE FROM creation WHERE idaccounts = :idaccounts");
                query.bindValue(":idaccounts", idAccount);
                query.exec();
            }
        }

        m_botData[sender].connectionData.connectionInfos.characterCreated = false;
        m_botData[sender].connectionData.connectionInfos.needToCreateCharacter = false;

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
            TreeWidgetDialog treeWidgetDialog;
            treeWidgetDialog.setParent(nullptr, Qt::Dialog);

            foreach (const GameServerInformations &infos, message.servers)
            {
                if((GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_CLASSICAL || (GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_EPIC || (GameServerTypeEnum)infos.type == GameServerTypeEnum::SERVER_TYPE_HARDCORE)
                {
                    QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, infos.id));

                    QIcon statusServer;
                    switch ((ServerStatusEnum)infos.status)
                    {
                    case ServerStatusEnum::SAVING:
                    case ServerStatusEnum::STARTING:
                        statusServer = QIcon(":/icons/bullet_orange_32px.ico");
                        break;

                    case ServerStatusEnum::ONLINE:
                        statusServer = QIcon(":/icons/bullet_green_32px.ico");
                        break;
                    case ServerStatusEnum::OFFLINE:
                    case ServerStatusEnum::STOPING:
                    case ServerStatusEnum::NOJOIN:
                        statusServer = QIcon(":/icons/bullet_red_32px.ico");
                        break;

                    case ServerStatusEnum::FULL:
                        statusServer = QIcon(":/icons/bullet_blue_32px.ico");
                        break;
                    }

                    QPair<double, QPair<QIcon, QString>> serverItem;
                    serverItem.first = infos.id;
                    serverItem.second.first = statusServer;
                    serverItem.second.second = QString("%1 (%2)").arg(server->getName()).arg(infos.charactersCount);

                    treeWidgetDialog.addItem(serverItem);
                }
            }

            if(treeWidgetDialog.exec() == QDialog::Accepted)
            {
                QPair<double, QPair<QIcon, QString>> serverItem;
                serverItem = treeWidgetDialog.getItemSelected();

                action(sender)<<"Connexion au serveur"<<serverItem.second.second.split('(').at(0) +"...";
                ServerSelectionMessage answer;
                answer.serverId = (uint)serverItem.first;
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
    }

    return messageFound;
}
