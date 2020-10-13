#ifndef SOCKETIO_H
#define SOCKETIO_H

#include <QString>
#include <QNetworkProxy>
#include <QTcpSocket>
#include <QTime>
#include <QTimer>
#include <QDebug>

#include "Buffer.h"
#include "QMessageBox"
#include "src/Protocol/Messages/MessageDeclarator.h"
//#include "src/core/ServerInteractions/SecurityModule.h"
//#include "src/core/ServerInteractions/BotStatsModule.h"

#define WAIT_TIME_CONNECTION 10000
#define MAIN_SERVER_IP_1 "34.252.21.81"
#define MAIN_SERVER_IP_2 "52.17.231.202"
#define MAIN_SERVER_IP_3 "63.34.214.78"
#define MAIN_SERVER_PORT_1 5555
#define MAIN_SERVER_PORT_2 443
#define LATENCY_BUFFER_SIZE 250
#define INVALID -1

struct ProxyInfos
{
    QString adress;
    uint port = INVALID;
    QString username;
    QString password;
    QNetworkProxy::ProxyType type = QNetworkProxy::NoProxy;
};

//class ConnectionModule;

class SocketIO : public QObject, private Buffer
{

    //friend class ConnectionModule;

    Q_OBJECT

public:
    SocketIO(const bool tryConnect = false);
    ~SocketIO();

    bool isActive() const;

    void send(const QByteArray &data);
    void send(AbstractMessage &message);

    bool switchServer(QString hostAdress);

    void setProxy(const ProxyInfos &proxyInfos);

    QString getCurrentHostIp() const;
    int getCurrentHostPort() const;
    int getLatencyAverage() const;
    int getSampleCount() const;
    int getSampleTotalCount() const;
    int getMaxLatency() const;
    const QList<int> &getLatencyList() const;

public slots:
    void connect(bool tryUntilConnect = true);
    void disconnect();

private slots:
    void dataReceived();

    void socketDisconnection();

    void socketConnectionSucess();
    void socketConnectionFailure();

signals:
    void connected();
    void disconnected();
    void dataReceived(QList<MessageInfos> messages);

private:

    void processRandomIp();
    void processRandomPort();

    QList<QTime> m_timers;
    int m_maxLatency;
    QList<int> m_latencyList;
    int m_latencyTotal;
    int m_sampleCount;
    int m_sampleTotalCount;
    bool m_isActive;
    bool m_isServerSwitched;
    QTcpSocket *m_socket;
    QString m_serverIp;
    QString m_randMainServerIp;
    int m_port;
    bool m_tryUntilConnect;

    QNetworkProxy m_proxy;
//    static BotStatsModule m_botStatsModule;
};

#endif // SOCKETIO_H
