#include "ConnectionManager.h"

ConnectionManager::ConnectionManager(QMap<SocketIO*, BotData> *connectionsData):
    AbstractManager(ManagerType::CONNECTION, connectionsData)
{

}

void ConnectionManager::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
    m_botData[sender].connectionData.greetingMessageIsInitialized = 0;
    m_botData[sender].connectionData.sequenceNumber = 0;

    if (m_botData[sender].connectionData.serverActivityTimer)
    {
        m_botData[sender].connectionData.serverActivityTimer->stop();
        m_botData[sender].connectionData.serverActivityTimer->disconnect();
        m_botData[sender].connectionData.serverActivityTimer.clear();
    }
}

SocketIO *ConnectionManager::addConnection(const ConnectionInfos &connectionInfos)
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
    m_botData[socket].connectionData.connectionInfos.isLoaded = true;

    connectionAdded(socket);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(hasConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(hasDisconnected()));

    return socket;
}

void ConnectionManager::removeConnection(SocketIO *sender)
{
    if(m_botData.contains(sender))
    {
        if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            disconnect(sender);

        m_botData[sender].connectionData.connectionInfos.isLoaded = false;
        m_botData.erase(m_botData.find(sender));

        delete sender;
    }
}

void ConnectionManager::reconnect(SocketIO *sender)
{
    m_botData[sender].statisticsData.countTotalReconnection += 1;
    action(sender)<<"Procédure de reconnexion initiée"<<QString::number(WAIT_TIME_CONNECTION/1000)+"s...";

    m_botData[sender].connectionData.hasRequestedReconnection = true;

    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
        disconnect(sender);

    else if(m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
        connect(sender);

    emit requestUpdate(sender);
}

void ConnectionManager::setReconnectionAuto(SocketIO *sender, bool active)
{
    m_botData[sender].connectionData.reconnectionAuto = active;
}

void ConnectionManager::setPreventInactivityDisconnects(SocketIO *sender, bool active)
{
    m_botData[sender].connectionData.preventInactivityDisconnects = active;
}

void ConnectionManager::connect(SocketIO *sender)
{
    if(m_botData.contains(sender) &&  m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED)
    {
        action(sender) << "Connexion en cours...";

        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = false;

        QSqlQuery query;
        query.prepare("UPDATE accounts SET lastconnection = :lastconnection WHERE login = :login");
        query.bindValue(":lastconnection", QDateTime::currentDateTime().toTime_t());
        query.bindValue(":login", m_botData[sender].connectionData.connectionInfos.login);
        query.exec();

        emit requestUpdate(sender);

        sender->connect(false);
    }

    else if(!m_botData.contains(sender))
        qDebug()<<"[ERROR] (ConnectionManager) connect: does not know this connection";
}

void ConnectionManager::disconnect(SocketIO *sender)
{
    if (m_botData.contains(sender) && m_botData[sender].connectionData.connectionState != ConnectionState::DISCONNECTED)
    {
        m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
        m_botData[sender].connectionData.hasRequestedDisconnection = true;

        if (m_botData[sender].connectionData.serverActivityTimer)
        {
            m_botData[sender].connectionData.serverActivityTimer->stop();
            m_botData[sender].connectionData.serverActivityTimer->disconnect();
            m_botData[sender].connectionData.serverActivityTimer.clear();
        }

        sender->disconnect();
    }

    else
        qDebug()<<"[ERROR] (ConnectionManager) disconnect: does not know this connection";
}

QList<int> ConnectionManager::cipherRSA(SocketIO *sender, QList<int> keys, QString salt)
{
    QList<int> credentials;

    QByteArray keyRaw;
    foreach (int number, keys)
        keyRaw.append(number);

    RsaManager keyDecoder;
    QByteArray decodedPublicKey = keyDecoder.publicKeyDecrypt(keyRaw);
    keyDecoder.setLoginPublicKey(decodedPublicKey);

    m_botData[sender].connectionData.aesKey = AesManager::generateRandomAESKey();

    // ---
    curl_global_init(CURL_GLOBAL_ALL);

    CURL *curl;
    curl = curl_easy_init();
    if(curl)
    {
        static const char *postthis = QString("login=%1&password=%2&game_id=%3&long_life_token=true&shop_key=ZAAP&payment_mode=OK&lang=en").arg(m_botData[sender].connectionData.connectionInfos.login).arg(m_botData[sender].connectionData.connectionInfos.password).arg(102).toStdString().c_str();
        struct curl_slist *chunk = NULL;

        chunk = curl_slist_append(chunk, "user-agent: Zaap 3.6.15");

        curl_easy_setopt(curl, CURLOPT_URL, "https://haapi.ankama.com/json/Ankama/v5/Api/CreateApiKey");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        CURLcode res;
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(chunk);
    }
    curl_global_cleanup();
    // ---

    credentials = keyDecoder.generateCredentials(salt, m_botData[sender].connectionData.aesKey, m_botData[sender].connectionData.connectionInfos.login, m_botData[sender].connectionData.connectionInfos.password);

    return credentials;
}

QString ConnectionManager::getFlashKey()
{
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

    return key;
}

DofusVersion ConnectionManager::getDofusVersion()
{
    QString dofusPath;
    QSqlQuery query;
    query.prepare("SELECT dofus_path FROM globalParameters");

    if(query.exec())
    {
        while(query.next())
        {
            dofusPath = query.value(0).toString();
        }
    }

    DofusVersion dofusVersion;
    if (!dofusPath.isEmpty())
    {
        QFile file(dofusPath + "/VERSION");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while (!file.atEnd())
            {
                QString line = file.readLine();
                if (line.contains('.'))
                {
                    dofusVersion.major = line.split(".").at(0).toInt();
                    dofusVersion.minor = line.split(".").at(1).toInt();
                    dofusVersion.code = line.split(".").at(2).toInt();
                    dofusVersion.build = line.split(".").at(3).toInt();
                }
            }
        }
    }

    return dofusVersion;
}

void ConnectionManager::updateServerInactivityDelay(SocketIO *sender, bool systemFastPing)
{
    int serverInactivityDelay = SERVER_INACTIVITY_DELAY;

    if (systemFastPing)
    {
        serverInactivityDelay = SERVER_INACTIVITY_SPEED_PING_DELAY;
    }

    if (m_botData[sender].connectionData.serverActivityTimer)
    {
        if (m_botData[sender].connectionData.serverActivityTimer->isActive())
        {
            m_botData[sender].connectionData.serverActivityTimer->stop();
        }

        m_botData[sender].connectionData.serverActivityTimer->disconnect();
        m_botData[sender].connectionData.serverActivityTimer.clear();
    }

    m_botData[sender].connectionData.serverActivityTimer = QSharedPointer<QTimer>(new QTimer);
    m_botData[sender].connectionData.serverActivityTimer->setSingleShot(true);
    m_botData[sender].connectionData.serverActivityTimer->setInterval(serverInactivityDelay);
    m_botData[sender].connectionData.serverActivityTimer->start();
    QObject::connect(m_botData[sender].connectionData.serverActivityTimer.data(), &QTimer::timeout, this, [this, sender] () { serverActivityTimerUp(sender); });
}

void ConnectionManager::hasConnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());

    m_botData[sender].connectionData.timeElapsed.start();
    m_botData[sender].generalData.botState = INACTIVE_STATE;
    m_botData[sender].connectionData.hasRequestedReconnection = false;
    m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
    m_botData[sender].playerData.playerStatus = PlayerStatusEnum::PLAYER_STATUS_AVAILABLE;

    info(sender) << "Connecté sur " << sender->getCurrentHostIp()+":"+QString::number(sender->getCurrentHostPort());

    emit requestUpdate(sender);
}

void ConnectionManager::hasDisconnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());

    if(m_botData.contains(sender))
    {
        if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
            warn(sender)<< D2OManagerSingleton::get()->getI18N()->getText("ui.popup.unexpectedSocketClosure.text").replace("\n", "");

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
        m_botData[sender].playerData.fullPixmap = QPixmap(":/icons/character.png");
        m_botData[sender].playerData.characterFaceUrl.clear();
        m_botData[sender].playerData.characterFullUrl.clear();
        m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;

        emit requestUpdate(sender);
        emit botDisconnected(sender);
    }
}

void ConnectionManager::processReconnection()
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

void ConnectionManager::serverActivityTimerUp(SocketIO *sender)
{
    if (m_botData.contains(sender))
    {
        if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED &&
                m_botData[sender].connectionData.preventInactivityDisconnects)
        {
            BasicPingMessage answer;
            answer.quiet = true;
            sender->send(answer);
        }

        m_botData[sender].connectionData.serverActivityTimer->start();
    }
}
