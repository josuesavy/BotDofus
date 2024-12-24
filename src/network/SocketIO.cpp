#include "SocketIO.h"

//QNetworkProxy SocketIO::m_proxy;
//BotStatsModule SocketIO::m_botStatsModule;

SocketIO::SocketIO(const bool tryConnect) :
    m_maxLatency(0),
    m_latencyTotal(0),
    m_sampleCount(0),
    m_sampleTotalCount(0),
    m_isActive(false),
    m_isServerSwitched(false),
    m_socket(nullptr),
    m_port(0),
  m_tryUntilConnect(false)
{
    m_socket = new QTcpSocket();
    m_socket->setProxy(m_proxy);

    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnection()));
    QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(socketConnectionSucess()));
    QObject::connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketConnectionFailure()));

    if (tryConnect)
        connect(false);
}

SocketIO::~SocketIO()
{
    disconnect();
    delete m_socket;
}

void SocketIO::connect(bool tryUntilConnect)
{
//    if(SecurityModuleSingleton::get()->isAuthentificated())
//    {
        if(!m_isServerSwitched)
        {
            m_randMainServerIp = MAIN_SERVER_IP;
            processRandomPort();
        }

        m_tryUntilConnect = tryUntilConnect;

        m_socket->connectToHost(getCurrentHostIp(), getCurrentHostPort());
//    }
}

void SocketIO::send(const QByteArray &data)
{
//    if(SecurityModuleSingleton::get()->isAuthentificated())
//    {
        if (!m_isActive)
            connect(true);

        m_socket->write(data);

        m_timers<<QElapsedTimer();
        m_timers.last().start();
//    }

//    else
//        disconnect();
}

void SocketIO::send(AbstractMessage &message)
{
//    if(SecurityModuleSingleton::get()->isAuthentificated())
//    {

        if(m_isActive)
        {
            Writer writer = writePacket(message);
            send(writer.getBuffer());
        }
//    }

//    else
//        disconnect();
}

void SocketIO::disconnect()
{
    if(m_isActive)
    {
        m_socket->disconnectFromHost();
        m_isActive = false;
    }
}

bool SocketIO::isActive() const
{
    return m_isActive;
}

void SocketIO::dataReceived()
{    
    if (m_socket->isValid()/* && SecurityModuleSingleton::get()->isAuthentificated()*/)
    {
        QList<MessageInfos> messages = readPacket(m_socket->read(m_socket->bytesAvailable()));

        foreach(const MessageInfos &message, messages)
        {
            if(message.messageType == MessageEnum::BASICACKMESSAGE)
            {
                m_sampleCount++;
                m_sampleTotalCount++;

                if (!m_timers.isEmpty())
                {
                    int latency = m_timers.first().elapsed();
                    m_timers.removeFirst();

                    m_latencyList<<latency;
                    m_latencyTotal += latency;

                    if(latency > m_maxLatency)
                        m_maxLatency = latency;

                    if(m_latencyList.size() > LATENCY_BUFFER_SIZE)
                    {
                        int toBeRemoved = m_latencyList.first();
                        m_latencyList.removeFirst();
                        m_latencyTotal -= toBeRemoved;
                        m_sampleCount--;

                        if(toBeRemoved == m_maxLatency)
                        {
                            int maxLatency = m_latencyList.first();

                            for(int i = 0; i < m_latencyList.size(); i++)
                            {
                                if(maxLatency < m_latencyList[i])
                                    maxLatency = m_latencyList[i];
                            }

                            m_maxLatency = maxLatency;
                        }
                    }
                }
            }
        }

        emit dataReceived(messages);
    }

//    else if(!SecurityModuleSingleton::get()->isAuthentificated())
//        disconnect();

    else
        qCritical()<< "(Socket) INVALID SOCKET";
}

bool SocketIO::switchServer(QString hostAdress)
{
    if (!m_isServerSwitched /*&& SecurityModuleSingleton::get()->isAuthentificated()*/)
    {
        m_socket->disconnectFromHost();
        qDebug()<<"(Socket) SERVER SWITCH FROM IP:"<<getCurrentHostIp()<<" to IP:"<<hostAdress;
        m_serverIp = hostAdress;
        m_isServerSwitched = true;
        connect(true);

        return true;
    }

    return false;
}

void SocketIO::socketDisconnection()
{
//    m_botStatsModule.removeActiveBot();
    qDebug()<<"(Socket) COMPLETED CONNECTION - IP:"<<getCurrentHostIp()<<" PORT:"<<QString::number(getCurrentHostPort());
    m_isActive = false;
    m_timers.clear();
    reset();

    emit disconnected();

    if (m_isServerSwitched)
    {
        m_isServerSwitched = false;
    }
}

void SocketIO::socketConnectionSucess()
{
//    m_botStatsModule.addActiveBot();
    m_isActive = true;

    qDebug()<<"(Socket) SERVER CONNECTION - IP:"<<getCurrentHostIp()<<" PORT:"<<QString::number(getCurrentHostPort())<<"SUCCESSFUL";

    //if (!m_isServerSwitched)
        emit connected();
}

void SocketIO::socketConnectionFailure()
{
    qDebug()<<"(Socket) SERVER CONNECTION - IP:"<< getCurrentHostIp()<<" PORT: "<<QString::number(getCurrentHostPort())<<"FAILED";
    qDebug()<<"(Socket) REASON :"<<m_socket->errorString();

    // Connection to proxy refused : QAbstractSocket::ProxyConnectionRefusedError

    if (m_tryUntilConnect && !m_isActive)
        QTimer::singleShot(WAIT_TIME_CONNECTION, this, SLOT(connect()));

    //else if (!m_isServerSwitched)
        emit disconnected();

    m_isActive = false;
}

void SocketIO::setProxy(const ProxyInfos &proxyInfos)
{
    if (proxyInfos.adress.isEmpty())
    {
        m_proxy.setType(QNetworkProxy::NoProxy);
        m_socket->setProxy(m_proxy);
    }

    else
    {
        m_proxy.setType(proxyInfos.type);
        m_proxy.setHostName(proxyInfos.adress);
        m_proxy.setPort(proxyInfos.port);
        m_proxy.setUser(proxyInfos.username);
        m_proxy.setPassword(proxyInfos.password);
        m_socket->setProxy(m_proxy);
    }
}

QNetworkProxy SocketIO::proxy() const
{
    return m_socket->proxy();
}

QString SocketIO::getCurrentHostIp() const
{
    if(m_isServerSwitched)
        return m_serverIp;

    return m_randMainServerIp;
}

unsigned short SocketIO::getCurrentHostPort() const
{
    return m_port;
}

int SocketIO::getLatencyAverage() const
{
    if(m_sampleCount != 0)
        return m_latencyTotal/m_sampleCount;

    else
        return 0;
}

int SocketIO::getSampleCount() const
{
    return m_sampleCount;
}

int SocketIO::getSampleTotalCount() const
{
    return m_sampleTotalCount;
}

int SocketIO::getMaxLatency() const
{
    return m_maxLatency;
}

const QList<int> &SocketIO::getLatencyList() const
{
    return m_latencyList;
}

void SocketIO::processRandomPort()
{
    int random =  (rand() % (2));

    if(random == 0)
        m_port = MAIN_SERVER_PORT_1;

    else if(random == 1)
        m_port = MAIN_SERVER_PORT_2;
}
