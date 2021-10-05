#ifndef SNIFFER_H
#define SNIFFER_H

#include "src/protocol/messages/MessageUtils.h"
#include "src/protocol/messages/MessageDeclarator.h"
#include "SocketIO.h"

#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QString>

class Sniffer : QObject
{
    Q_OBJECT

public:
    Sniffer();

private slots:
    void reset();
    void clientDisconnection();
    void serverDisconnection();
    void getClient();
    void processClientData();
    void processServerData();

private:
    QTcpServer m_listener;
    QTcpSocket m_server;
    QTcpSocket *m_client;
    QString m_hostAddress;
    Buffer m_serverBuffer;
    Buffer m_clientBuffer;
    bool m_expectedClientDisconnection;
    bool m_expectedServerDisconnection;
};

#endif // SNIFFER_H
