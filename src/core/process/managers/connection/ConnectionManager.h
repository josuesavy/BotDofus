#ifndef AUTHENTIFICATIONMANAGER_H
#define AUTHENTIFICATIONMANAGER_H

#include <QtSql/QtSql>

#include "curl/curl.h"

#include "src/engines/security/RsaManager.h"
#include "src/engines/core/process/managers/AbstractManager.h"

class ConnectionManager : public AbstractManager
{
    Q_OBJECT

public:
    ConnectionManager(QMap<SocketIO *, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

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
     * \brief Enable the prevent inactivity disconnects
     * \param sender Bot's particula connection
     * \param active Activation
     */
    void setPreventInactivityDisconnects(SocketIO *sender, bool active);


    /*!
     * \brief Start connection
     * \param sender Bot's particular connection
     */
    void connect(SocketIO *sender);


    /*!
     * \brief Stop the connection
     * \param sender Bot's particular connection
     */
    void disconnect(SocketIO *sender);


    QList<int> cipherRSA(SocketIO *sender, QList<int> keys, QString salt);

    QString getFlashKey();

    DofusVersion getDofusVersion();


    /*!
     * \brief Set timer for send events about inactivity
     * \param sender Bot's particular connection
     * \param systemFastPing System fast ping or not
     */
    void updateServerInactivityDelay(SocketIO *sender, bool systemFastPing);

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


    /*!
     * \brief Event send ping to the server when the timer has time out
     * \param sender Bot's particular connection
     */
    void serverActivityTimerUp(SocketIO *sender);


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
