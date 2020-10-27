#ifndef CONNECTIONMODULE_H
#define CONNECTIONMODULE_H

#define USER_DATA_PATH getRessourcesPath()+"/database.db"

/*!
 * \class The ConnectionModule class handle the connections, the security, the character selection.
 * \brief Module to handle the connections
 * \author AnonymHax & G0hu
 * \version Beta
 */


#include <QObject>
#include <QList>
#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QInputDialog>
#include <QListWidget>
#include <QGridLayout>
#include <QtSql/QtSql>


#include "src/Engines/Core/Process/abstract/AbstractModule.h"
#include "src/Engines/Security/RsaManager.h"
#include "src/Engines/IO/D2O/Misc/ParamsDecoder.h"
#include "src/Engines/Misc/EntityLook/EntityLookParser.h"
#include "src/Engines/IO/D2O/GameDataTypeDeclarator.h"
#include "src/Engines/Storage/DataHandler.h"
#include "src/Public.h"

enum class DofusVersion
{
    MAJOR = 2,
    MINOR = 57,
    CODE = 6,
    BUILD = 8,
};

class ConnectionModule : public AbstractModule
{
    Q_OBJECT

public:
    ConnectionModule(QMap<SocketIO*, BotData> *connectionsData);


    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);


    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);


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

private:
    QMap<SocketIO *, BotData> *m_connectionsData;
};

#endif // CONNECTIONMODULE_H
