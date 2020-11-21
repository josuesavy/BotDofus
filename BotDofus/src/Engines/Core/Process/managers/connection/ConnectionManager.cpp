#include "ConnectionManager.h"

ConnectionManager::ConnectionManager(QMap<SocketIO*, BotData> *connectionsData):
    AbstractManager(ModuleType::CONNECTION, connectionsData)
{

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
    m_botData[socket].connectionData.connectionInfos.isCharged = true;

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

        m_botData[sender].connectionData.connectionInfos.isCharged = false;
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
}

void ConnectionManager::setReconnectionAuto(SocketIO *sender, bool active)
{
    m_botData[sender].connectionData.reconnectionAuto = active;
}

void ConnectionManager::connect(SocketIO *sender)
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

void ConnectionManager::disconnect(SocketIO *sender)
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

void ConnectionManager::hasConnected()
{
    SocketIO *sender = static_cast<SocketIO*>(QObject::sender());
    m_botData[sender].connectionData.timeElapsed.start();
    m_botData[sender].generalData.botState = INACTIVE_STATE;
    m_botData[sender].connectionData.hasRequestedReconnection = false;
    m_botData[sender].connectionData.connectionState = ConnectionState::TRANSITION;
    info(sender) << "Connecté sur " << sender->getCurrentHostIp()+":"+QString::number(sender->getCurrentHostPort());
}

void ConnectionManager::hasDisconnected()
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
