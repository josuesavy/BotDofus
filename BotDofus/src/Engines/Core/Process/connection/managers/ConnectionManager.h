#ifndef AUTHENTIFICATIONMANAGER_H
#define AUTHENTIFICATIONMANAGER_H

#include <QtSql/QtSql>

#include "src/Engines/Security/RsaManager.h"
#include "src/Engines/Storage/DataHandler.h"

class ConnectionManager : public QObject, public DataHandler
{
    Q_OBJECT

public:
    ConnectionManager();

    /*!
     * \brief Add new connection to data handlers
     * \param connectionInfos Account login informations
     * \return SocketIO Bot's particular connection
     */
    SocketIO *addConnection(const ConnectionInfos &connectionInfos);


    /*!
     * \brief Disconnect and delete the connection in data handlers
     * \param sender Bot's particular connection
     */
    void removeConnection(SocketIO *sender);


    /*!
     * \brief Reconnect a previously disconnected connection and added to data handlers
     * \param sender Bot's particular connection
     */
    void reconnect(SocketIO *sender);


    /*!
     * \brief Enable the reconnection automatic
     * \param sender Bot's particular connection
     * \param active Activation
     */
    void setReconnectionAuto(SocketIO *sender, bool active);


    /*!
     * \brief Start connection
     * \param sender Bot's particular connection
     */
    void connect(SocketIO *sender);


    /*!
     * \brief Stop the connection
     * \param sender Bot's particular connection
     *
     * Disconnect the bot in game
     */
    void disconnect(SocketIO *sender);

    QList<int> cipherRSA(SocketIO *sender, QList<int> keys, QString salt);

    static QString getFlashKey();



private slots:

    /*!
     * \brief Event when the socket is connected
     */
    void hasConnected();


    /*!
     * \brief Event when the socket is disconnected
     */
    void hasDisconnected();


    /*!
     * \brief Reconnect the socket previously disconnected
     */
    void processReconnection();



signals:

    /*!
     * \brief Signal to inform that a connection has been added
     * \param sender Bot's particular connection
     */
    void connectionAdded(SocketIO *sender);


    /*!
     * \brief Signal to inform that a bot has been disconnected
     * \param sender Bot's particular connection
     */
    void botDisconnected(SocketIO *sender);
};

#endif // AUTHENTIFICATIONMANAGER_H
