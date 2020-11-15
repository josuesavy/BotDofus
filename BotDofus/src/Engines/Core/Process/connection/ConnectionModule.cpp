#include "ConnectionModule.h"

ConnectionModule::ConnectionModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractModule(ModuleType::CONNECTION, connectionsData),
    m_connectionsData(connectionsData)
{
    //    QObject::connect(&m_rawDataModule, SIGNAL(translateSucess(SocketIO*,int,QList<int>)), this, SLOT(processAntiBotReply(SocketIO*,int,QList<int>)));
    //    QObject::connect(&m_rawDataModule, SIGNAL(translateFailure(SocketIO*,int,FailureReasonsEnum)), this, SLOT(processAntiBotFailure(SocketIO*,int,FailureReasonsEnum)));
    //    QObject::connect(&m_rawDataModule, SIGNAL(serverConnectionFailed(SocketIO*)), this, SLOT(processBotServerConnectionFailure(SocketIO*)));
}

void ConnectionModule::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
    m_botData[sender].connectionData.greetingMessageIsInitialized = 0;
    m_botData[sender].connectionData.sequenceNumber = 0;
}

bool ConnectionModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);
    
    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;
        
    case MessageEnum::PROTOCOLREQUIRED:
    {
        ProtocolRequired message;
        message.deserialize(&reader);

//        if(message.currentVersion < message.requiredVersion)
//        {
//            QString str = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.protocolError");
//            str.replace("%1", QString::number(message.currentVersion));
//            str.replace("%2", QString::number(message.requiredVersion));
//            error(sender) << str;
//        }
    }
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

        //
        QByteArray keyRaw;
        foreach (int number, message.key)
            keyRaw.append(number);

        RsaManager keyDecoder;
        QByteArray decodedPublicKey = keyDecoder.publicKeyDecrypt(keyRaw);
        keyDecoder.setLoginPublicKey(decodedPublicKey);

        m_botData[sender].connectionData.aesKey = AesManager::generateRandomAESKey();

        imsg.credentials = keyDecoder.generateCredentials(message.salt, m_botData[sender].connectionData.aesKey, m_botData[sender].connectionData.connectionInfos.login, m_botData[sender].connectionData.connectionInfos.password);
        //

        sender->send(imsg);


        QString randomChars;
        for (int i = 0; i < 20; i++)
        {
            int random =  qCeil(rand()%101);

            if (random <= 40)
                randomChars += char(qFloor(rand() % 27) + 65);

            else if (random <= 80)
                randomChars +=char(qFloor(rand() % 27) + 97);

            else
                randomChars += char(qFloor(rand() % 11) + 48);
        }

        int signature = 0;
        for (int i = 0; i < randomChars.size(); i++)
            signature += (int(randomChars.toStdString()[i]) % 16);

        QString checksum = QByteArray(1,char(signature%16)).toHex().remove(0,1).toUpper();
        QString key = randomChars + checksum;

        ClientKeyMessage ckmsg;
        ckmsg.key = key;
        sender->send(ckmsg);
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
        
    case MessageEnum::LOGINQUEUESTATUSMESSAGE:
    {
        LoginQueueStatusMessage message;
        message.deserialize(&reader);
        
        if (message.position != 0)
            action(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.queue.number").arg(message.position).arg(message.total);
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

    case MessageEnum::IDENTIFICATIONFAILEDMESSAGE:
    {
        IdentificationFailedMessage message;
        message.deserialize(&reader);
        
        QString failReason;
        switch ((IdentificationFailureReasonEnum)message.reason)
        {
        case IdentificationFailureReasonEnum::WRONG_CREDENTIALS:
            failReason = "Nom de compte ou mot de passe incorrect.";
            break;
            
        case IdentificationFailureReasonEnum::BANNED:
        {
            QSqlQuery query;
            query.prepare("UPDATE accounts SET isbanned = :isbanned WHERE login = :login");
            query.bindValue(":isbanned", 1);
            query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
            query.exec();

            failReason = "Le compte est banni définitivement - N'hesitez pas à le reporter sur le forum";
        }
            break;
            
        case IdentificationFailureReasonEnum::KICKED:
            failReason = "Expulsé";
            break;
            
        case IdentificationFailureReasonEnum::IN_MAINTENANCE:
            failReason = D2OManagerSingleton::get()->getI18N()->getText(412383);
            break;
            
        case IdentificationFailureReasonEnum::TOO_MANY_ON_IP:
            failReason = "Un défaut de sécurité de votre connexion Internet a été relevé : votre adresse IP publique n'est pas constante, et ne permet pas d'authentifier votre connexion. Contactez votre administrateur réseau ou votre FAI, afin de vous assurer que votre connexion puisse conserver une IP identique entre l'identification et le choix du serveur de jeu. Cette 'inconstance' de l'IP se produit principalement dans les réseaux possédant plusieurs connexion Internet en parallèle, lorsque les connexions réseau sont balancées entre les différents points d'accès Internet.";
            break;
            
        case IdentificationFailureReasonEnum::TIME_OUT:
            failReason = "Temps de connexion écoulé";
            break;
            
        case IdentificationFailureReasonEnum::BAD_IPRANGE:
            failReason = "Adresse ip incorrecte";
            break;
            
        case IdentificationFailureReasonEnum::CREDENTIALS_RESET:
            failReason = "Reset des identifiants";
            break;
            
        case IdentificationFailureReasonEnum::EMAIL_UNVALIDATED:
            failReason = "Email du compte non-verifié";
            break;
            
        case IdentificationFailureReasonEnum::OTP_TIMEOUT:
            failReason = "Temps de connexion écoulé";
            break;
            
        case IdentificationFailureReasonEnum::SERVICE_UNAVAILABLE:
            failReason = "Service non disponible";
            break;
            
        case IdentificationFailureReasonEnum::UNKNOWN_AUTH_ERROR:
            failReason = "Erreur de connexion inconnue";
            break;
            
        case IdentificationFailureReasonEnum::SPARE:
            failReason = "Erreur de connexion inconnue : Spare";
            break;
        }
        
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
        
        error(sender)<<"Connexion refusée."<<failReason;
        sender->disconnect();
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

    case MessageEnum::NICKNAMEREGISTRATIONMESSAGE:
    {
        bool ok;
        QString text = QInputDialog::getText(nullptr, tr("Choix du pseudo de compte"), tr("Pseudo :"), QLineEdit::Normal, QString(), &ok);
        if (ok && !text.isEmpty())
        {
            NicknameChoiceRequestMessage answer;
            answer.nickname = text;
            sender->send(answer);
        }
        else
            sender->disconnect();
    }
        break;

    case MessageEnum::NICKNAMEREFUSEDMESSAGE:
    {
        NicknameRefusedMessage message;
        message.deserialize(&reader);

        switch ((NicknameErrorEnum)message.reason)
        {
        case NicknameErrorEnum::ALREADY_USED:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.alreadyUsed");
            break;

        case NicknameErrorEnum::INVALID_NICK:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.invalid");
            break;

        case NicknameErrorEnum::SAME_AS_LOGIN:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.equalsLogin");
            break;

        case NicknameErrorEnum::UNKNOWN_NICK_ERROR:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.unknown");
            break;

        case NicknameErrorEnum::TOO_SIMILAR_TO_LOGIN:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.nickname.similarToLogin");
            break;
        }

        error(sender) << "Pseudo refusé.";
        sender->disconnect();
    }
        break;

    case MessageEnum::NICKNAMEACCEPTEDMESSAGE:
    {
        info(sender) << "Pseudo accepté avec succès.";
    }
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
        
    case MessageEnum::CREDENTIALSACKNOWLEDGEMENTMESSAGE:
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
        
    case MessageEnum::HELLOGAMEMESSAGE:
    {
        info(sender) << "Connecté au serveur de jeu.";

        AuthenticationTicketMessage answer;
        answer.lang = "fr";
        answer.ticket = m_botData[sender].connectionData.ticket;
        sender->send(answer);
    }
        break;
        
    case MessageEnum::AUTHENTICATIONTICKETACCEPTEDMESSAGE:
    {
        //qDebug()<<"CONNEXION - Communication avec le serveur"<< qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, m_botData[sender].connectionData.connectionInfos.serverId))->getName() << "etablie";
    }
        break;
        
    case MessageEnum::TRUSTSTATUSMESSAGE:
    {
        CharactersListRequestMessage answer;
        sender->send(answer);
    }
        break;
        
    case MessageEnum::QUEUESTATUSMESSAGE:
    {
        QueueStatusMessage message;
        message.deserialize(&reader);
        
        if (message.position != 0)
            action(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.queue.number").arg(message.position).arg(message.total);
    }
        break;
        
    case MessageEnum::BASICCHARACTERSLISTMESSAGE:
    {
        BasicCharactersListMessage message;
        message.deserialize(&reader);

        foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
        {
            //debug(sender)<<"\t->"<<infos->name<<"niveau"<<infos->level;

            if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
            {
                m_botData[sender].mapData.botId = infos->id;
                m_botData[sender].playerData.breed = infos->breed;
            }
        }

    }
        break;

    case MessageEnum::CHARACTERSLISTMESSAGE:
    {
        action(sender)<<"Réception de la liste des personnages.";
        CharactersListMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].connectionData.connectionInfos.needToCreateCharacter && !m_botData[sender].connectionData.connectionInfos.characterCreated)
        {
            if(m_botData[sender].connectionData.connectionInfos.creation.name.isEmpty())
            {
                CharacterNameSuggestionRequestMessage cnsrmsg;
                sender->send(cnsrmsg);
            }

            else
            {
                action(sender) << "Création du personnage "+m_botData[sender].connectionData.connectionInfos.creation.name+"..";
                CharacterCreationRequestMessage ccrmsg;
                ccrmsg.name = m_botData[sender].connectionData.connectionInfos.creation.name;
                ccrmsg.breed = m_botData[sender].connectionData.connectionInfos.creation.breed;
                ccrmsg.sex = m_botData[sender].connectionData.connectionInfos.creation.sex;
                ccrmsg.colors = m_botData[sender].connectionData.connectionInfos.creation.colors;
                ccrmsg.cosmeticId = m_botData[sender].connectionData.connectionInfos.creation.head;

                sender->send(ccrmsg);
            }
        }

        else if(!m_botData[sender].connectionData.connectionInfos.needToCreateCharacter && m_botData[sender].connectionData.connectionInfos.characterCreated)
        {
            action(sender) << "Sélection du personnage" << message.characters.first()->name + "...";
            m_botData[sender].playerData.breed = message.characters.first()->breed;

            CharacterFirstSelectionMessage answer;
            answer.doTutorial = false;
            answer.id = message.characters.at(0)->id;
            sender->send(answer);
        }

        else if(m_botData[sender].connectionData.connectionInfos.connectionTo == ConnectionTo::CHARACTER || m_botData[sender].connectionData.connectionInfos.connectionTo == ConnectionTo::SERVER || m_botData[sender].connectionData.connectionInfos.character.isEmpty())
        {
            QStringList items;
            foreach(QSharedPointer<CharacterBaseInformations> infos, message.characters)
                items.append(QString("%1 - %2 Niv.%3").arg(QString::number(infos->id, 'f', 0)).arg(infos->name).arg(infos->level));

            bool ok;
            QString item = QInputDialog::getItem(nullptr, tr("Choisissez un personnage"), tr("Personnage :"), items, 0, false, &ok);
            if (ok && !item.isEmpty())
            {
                action(sender) << "Sélection du personnage" << item.split(" - ").at(1).split(" Niv.").at(0) + "...";
                CharacterSelectionMessage answer;
                answer.id = item.split(" - ").at(0).toDouble();
                sender->send(answer);
            }

            else
                sender->disconnect();
        }

        else if(message.characters.isEmpty())
        {
            error(sender)<<"Vous n'avez pas de personnage sur ce serveur.";
            sender->disconnect();
        }

        else
        {
            action(sender) << "Sélection du personnage" << m_botData[sender].connectionData.connectionInfos.character + "...";

            foreach (QSharedPointer<CharacterBaseInformations> infos, message.characters)
            {
                if (infos->name == m_botData[sender].connectionData.connectionInfos.character)
                {
                    m_botData[sender].mapData.botId = infos->id;
                    m_botData[sender].playerData.breed = infos->breed;
                }
            }

            if (m_botData[sender].mapData.botId != INVALID)
            {
                CharacterSelectionMessage answer;
                answer.id = m_botData[sender].mapData.botId;
                sender->send(answer);
            }

            else
            {
                error(sender)<<"Le personnage"<<m_botData[sender].connectionData.connectionInfos.character<<"n'existe pas ou n'est pas sur ce serveur.";
                sender->disconnect();
            }
        }
    }
        break;

    case MessageEnum::CHARACTERSELECTEDERRORMESSAGE:
    {
        CharacterSelectedErrorMessage message;
        message.deserialize(&reader);

        error(sender)<<"Sélection du personnage refusé.";
        sender->disconnect();
    }
        break;
        
    case MessageEnum::CHARACTERSELECTEDFORCEMESSAGE:
    {
        CharacterSelectedForceMessage message;
        message.deserialize(&reader);

        m_botData[sender].mapData.botId = message.id;

        CharacterSelectedForceReadyMessage answer;
        sender->send(answer);

        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;
        
        FriendsGetListMessage answer1;
        sender->send(answer1);
        
        IgnoredGetListMessage answer2;
        sender->send(answer2);
        
        QString randomChars;
        for (int i = 0; i < 20; i++)
        {
            int random =  qCeil(rand()%101);
            
            if (random <= 40)
                randomChars += char(qFloor(rand() % 27) + 65);
            
            else if (random <= 80)
                randomChars +=char(qFloor(rand() % 27) + 97);
            
            else
                randomChars += char(qFloor(rand() % 11) + 48);
        }

        int signature = 0;
        for (int i = 0; i < randomChars.size(); i++)
            signature += (int(randomChars.toStdString()[i]) % 16);
        
        QString checksum = QByteArray(1,char(signature%16)).toHex().remove(0,1).toUpper();
        QString key = randomChars + checksum;
        
        ClientKeyMessage answer3;
        answer3.key = key;
        sender->send(answer3);
        
        GameContextCreateRequestMessage answer4;
        sender->send(answer4);
        
        ChannelEnablingMessage answer5;
        for (int i = 0; i < 13; i++)
        {
            answer5.channel = i;
            answer5.enable = true;
            sender->send(answer5);
        }
    }
        break;

    case MessageEnum::CHARACTERCREATIONRESULTMESSAGE:
    {
        CharacterCreationResultMessage message;
        message.deserialize(&reader);

        if(message.result > 0)
        {
            switch((CharacterCreationResultEnum)message.result)
            {
            case CharacterCreationResultEnum::ERR_INVALID_NAME:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.invalidName");
                break;
            case CharacterCreationResultEnum::ERR_NAME_ALREADY_EXISTS:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.nameAlreadyExist");
                break;
            case CharacterCreationResultEnum::ERR_NOT_ALLOWED:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.notSubscriber");
                break;
            case CharacterCreationResultEnum::ERR_TOO_MANY_CHARACTERS:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.tooManyCharacters");
                break;
            case CharacterCreationResultEnum::ERR_NO_REASON:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.noReason");
                break;
            case CharacterCreationResultEnum::ERR_RESTRICED_ZONE:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.charSel.deletionErrorUnsecureMode");
                break;
            case CharacterCreationResultEnum::ERR_INCONSISTENT_COMMUNITY:
                error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.popup.charcrea.wrongCommunity");
                break;
            }

            m_botData[sender].connectionData.connectionInfos.characterCreated = false;
            m_botData[sender].connectionData.connectionInfos.needToCreateCharacter = false;

            sender->disconnect();
        }

        else
        {
            info(sender) << "Personnage créer !";
            m_botData[sender].connectionData.connectionInfos.characterCreated = true;
            m_botData[sender].connectionData.connectionInfos.needToCreateCharacter = false;
        }

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
    }
        break;

    case MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE:
    {
        CharacterNameSuggestionSuccessMessage message;
        message.deserialize(&reader);

        action(sender) << "Création du personnage "+message.suggestion+"..";

        CharacterCreationRequestMessage ccrmsg;
        ccrmsg.name = message.suggestion;
        ccrmsg.breed = m_botData[sender].connectionData.connectionInfos.creation.breed;
        ccrmsg.sex = m_botData[sender].connectionData.connectionInfos.creation.sex;
        ccrmsg.colors = m_botData[sender].connectionData.connectionInfos.creation.colors;
        ccrmsg.cosmeticId = m_botData[sender].connectionData.connectionInfos.creation.head;

        sender->send(ccrmsg);
    }
        break;

    case MessageEnum::TEXTINFORMATIONMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized == 0)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;
            
            FriendsGetListMessage answer1;
            sender->send(answer1);

            AcquaintancesGetListMessage answer2;
            sender->send(answer2);
            
            IgnoredGetListMessage answer3;
            sender->send(answer3);
            
            QString randomChars;
            for (int i = 0; i < 20; i++)
            {
                int random =  qCeil(rand()%101);
                
                if (random <= 40)
                    randomChars += char(qFloor(rand() % 27) + 65);
                
                else if (random <= 80)
                    randomChars +=char(qFloor(rand() % 27) + 97);
                
                else
                    randomChars += char(qFloor(rand() % 11) + 48);
            }
            
            int signature = 0;
            for (int i = 0; i < randomChars.size(); i++)
                signature += (int(randomChars.toStdString()[i]) % 16);
            
            QString checksum = QByteArray(1,char(signature%16)).toHex().remove(0,1).toUpper();
            QString key = randomChars + checksum;
            
            ClientKeyMessage answer4;
            answer4.key = key;
            sender->send(answer4);
            
            GameContextCreateRequestMessage answer5;
            sender->send(answer5);
            
            ChannelEnablingMessage answer6;
            for (int i = 0; i < 13; i++)
            {
                answer6.channel = i;
                answer6.enable = true;
                sender->send(answer6);
            }
        }
        
        else if (m_botData[sender].connectionData.greetingMessageIsInitialized == 1)
        {
            m_botData[sender].connectionData.greetingMessageIsInitialized++;
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }
    }
        break;
        
    case MessageEnum::SEQUENCENUMBERREQUESTMESSAGE:
    {
        if (m_botData[sender].connectionData.greetingMessageIsInitialized > 1)
        {
            m_botData[sender].connectionData.sequenceNumber++;
            SequenceNumberMessage answer;
            answer.number = m_botData[sender].connectionData.sequenceNumber;
            sender->send(answer);
        }
    }
        break;
        
    case MessageEnum::BASICLATENCYSTATSREQUESTMESSAGE:
    {
        BasicLatencyStatsMessage answer;
        qDebug()<<"Stats connexion (en ms) - AVG"<<sender->getLatencyAverage()<<"SAMPLES"<<sender->getSampleCount()<<"MAX"<<sender->getMaxLatency();
        
        if(sender->getLatencyAverage() > 32767)
            answer.latency = 32767;
        else
            answer.latency = sender->getLatencyAverage();
        
        answer.sampleCount = sender->getSampleCount();
        answer.max = sender->getMaxLatency();
        
        sender->send(answer);
    }
        break;
        
    case MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE:
    {
        CharacterSelectedSuccessMessage message;
        message.deserialize(&reader);

        m_botData[sender].connectionData.connectionInfos.character = message.infos->name;
        m_botData[sender].mapData.botId = message.infos->id;
        m_botData[sender].playerData.breed = message.infos->breed;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET character = :character WHERE login = :login");
        query.bindValue(":character", m_botData[sender].connectionData.connectionInfos.character);
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        info(sender)<<"Personnage"<<message.infos->name<<"sélectionné.";
    }
        break;
        
    case MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE:
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::CONNECTED;
    }
        break;
        
    case MessageEnum::RAWDATAMESSAGE:
    {
        action(sender) << "Veuillez patienter s'il vous plaît...";

        RawDataMessage message;
        message.deserialize(&reader);

        QFile a("‪C:\\Users\\XXXX\\Desktop\\FDP.swf");
        a.open(QIODevice::WriteOnly);
        a.write(message.content);

        // TODO : Bypass antibot if necessary
        action(sender) << "Veuillez patienter s'il vous plaît...";

        QList<int> data;
        CheckIntegrityMessage reply;
        for (int i = 0; i < 256; i++)
            data << i;

        reply.data = data;
        sender->send(reply);

        //info(sender)<<"Communication avec <b>AnonymServer</b>";
        //m_botData[sender].connectionData.rawDataRequestIndex = m_rawDataModule.requestTranslate(sender, message.content, m_botData[sender].connectionData.ticket);
    }
        break;

    case MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE:
    {
        SystemMessageDisplayMessage message;
        message.deserialize(&reader);

        QSharedPointer<InfoMessageData> infoData = qSharedPointerCast<InfoMessageData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INFOMESSAGES, 40000 + message.msgId));

        error(sender) << ParamsDecoder::applyParams(infoData->getText(), message.parameters);
    }
        break;

    case MessageEnum::ALMANACHCALENDARDATEMESSAGE:
    {
        AlmanachCalendarDateMessage message;
        message.deserialize(&reader);

        QSharedPointer<AlmanaxCalendarData> almanaxData = qSharedPointerCast<AlmanaxCalendarData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ALMANAXCALENDARS, message.date));
        QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, almanaxData->getNpcId()));

        action(sender) << "[Almanax]" << D2OManagerSingleton::get()->getI18N()->getText(almanaxData->getDescId());
        action(sender) << "[Almanax]" << D2OManagerSingleton::get()->getI18N()->getText("ui.almanax.offeringTo").arg(npcData->getName());
    }
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

    case MessageEnum::EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE:
        break;
    }
    
    return messageFound;
}

SocketIO *ConnectionModule::addConnection(const ConnectionInfos &connectionInfos)
{
    QMapIterator<SocketIO*, BotData> i(m_botData);

    while(i.hasNext())
    {
        i.next();

        if(i.value().connectionData.connectionInfos.character == connectionInfos.character && i.value().connectionData.connectionInfos.login == connectionInfos.login)
        {
            delete i.key();
            m_botData.remove(i.key());
            break;
        }
    }
    
    SocketIO *socket = new SocketIO;
    
    m_botData[socket].connectionData.connectionInfos = connectionInfos;
    m_botData[socket].connectionData.connectionInfos.isCharged = true;

    connectionAdded(socket);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(hasConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(hasDisconnected()));
    
    return socket;
}

void ConnectionModule::removeConnection(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            disconnect(sender);

        m_botData[sender].connectionData.connectionInfos.isCharged = false;
        m_botData.erase(m_botData.find(sender));

        delete sender;
    }
}

void ConnectionModule::reconnect(SocketIO *sender)
{
    m_botData[sender].statisticsData.countTotalReconnection += 1;
    action(sender)<<"Procédure de reconnexion initiée"<<QString::number(WAIT_TIME_CONNECTION/1000)+"s...";

    m_botData[sender].connectionData.hasRequestedReconnection = true;

    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
        disconnect(sender);

    else if(m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
        connect(sender);
}

void ConnectionModule::setReconnectionAuto(SocketIO *sender, bool active)
{
    m_botData[sender].connectionData.reconnectionAuto = active;
}

void ConnectionModule::connect(SocketIO *sender)
{
    if(m_botData.contains(sender) &&  m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = false;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET lastconnection = :lastconnection WHERE login = :login");
        query.bindValue(":lastconnection", QDateTime::currentDateTime().toTime_t());
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        sender->connect(false);
    }
    
    else if(!m_botData.contains(sender))
        qDebug()<<"ERREUR - ConnectionModule ne connait pas cette connexion";
}

void ConnectionModule::disconnect(SocketIO *sender)
{
    if (m_botData.contains(sender) && m_botData[sender].connectionData.connectionState != ConnectionState::DISCONNECTED)
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = true;
        sender->disconnect();
    }
    
    else
        qDebug()<<"ERREUR - ConnectionModule ne connait pas cette connexion";
}

void ConnectionModule::hasConnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());
    m_botData[sender].connectionData.timeElapsed.start();
    m_botData[sender].generalData.botState = INACTIVE_STATE;
    m_botData[sender].connectionData.hasRequestedReconnection = false;
    m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
    info(sender) << "Connecté sur " << sender->getCurrentHostIp()+":"+QString::number(sender->getCurrentHostPort());
}

void ConnectionModule::hasDisconnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());
    
    if(m_botData.contains(sender))
    {
        if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            warn(sender)<<"La connexion avec le serveur a été interrompue.";

        info(sender)<<"Déconnecté";

        if((m_botData[sender].connectionData.hasRequestedDisconnection && m_botData[sender].connectionData.reconnectionAuto) || m_botData[sender].connectionData.hasRequestedReconnection)
        {
            m_botData[sender].connectionData.autoReconnectionTimer = QSharedPointer<QTimer>(new QTimer);
            m_botData[sender].connectionData.autoReconnectionTimer->setSingleShot(true);
            m_botData[sender].connectionData.autoReconnectionTimer->setInterval(WAIT_TIME_CONNECTION);
            m_botData[sender].connectionData.autoReconnectionTimer->start();
            QObject::connect(m_botData[sender].connectionData.autoReconnectionTimer.data(), SIGNAL(timeout()), this, SLOT(processReconnection()));

            action(sender)<<"Tentative de reconnexion dans"<<QString::number(WAIT_TIME_CONNECTION/1000)+"s...";
        }


        m_botData[sender].playerData.headPixmap = QPixmap(":/icons/user.png");
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        emit botDisconnected(sender);
    }
}

void ConnectionModule::processReconnection()
{
    QTimer *timer = static_cast<QTimer*>(QObject::sender());

    QMapIterator<SocketIO*, BotData> i(m_botData);

    while (i.hasNext())
    {
        i.next();

        if(i.value().connectionData.autoReconnectionTimer == timer)
        {
            connect(i.key());
            break;
        }
    }
}

//void ConnectionModule::processAntiBotReply(SocketIO *sender, int requestIndex, QList<int> answerData)
//{
//    if(m_botData.contains(sender) && m_botData[sender].connectionData.rawDataRequestIndex == requestIndex)
//    {
//        if (!answerData.isEmpty())
//        {
//            CheckIntegrityMessage message;
//            message.data = answerData;
//            sender->send(message);
//            qDebug()<<"ConnectionModule - CheckIntegrityMessage sent";
//        }
//    }
//}

//void ConnectionModule::processAntiBotFailure(SocketIO *sender, int requestIndex, FailureReasonsEnum reason)
//{
//    if(m_botData.contains(sender) && m_botData[sender].connectionData.rawDataRequestIndex == requestIndex)
//    {
//        switch(reason)
//        {
//        case FailureReasonsEnum::WRONGCREDENTIALS:
//            alert(sender)<<"Le compte AnonymBot configuré n'existe pas";
//            break;

//        case FailureReasonsEnum::NOTPREMIUM:
//            alert(sender)<<"Le compte AnonymBot configuré n'est pas premium";
//            break;

//        case FailureReasonsEnum::BANNED:
//            alert(sender)<<"Le compte AnonymBot configuré a été banni";
//            break;
//        }

//        m_botData[sender].connectionData.hasRequestedDisconnection = true;
//        sender->disconnect();
//        emit requestUpdate(sender);
//    }
//}

//void ConnectionModule::processBotServerConnectionFailure(SocketIO *sender)
//{
//    if(m_botData.contains(sender))
//    {
//        m_botData[sender].connectionData.hasRequestedDisconnection = true;
//        alert(sender)<<"Impossible de joindre <b>AnonymServer</b> pour l'instant, veuillez réessayer dans quelques instants...";
//        sender->disconnect();
//    }
//}
