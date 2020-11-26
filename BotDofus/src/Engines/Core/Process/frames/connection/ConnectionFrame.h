#ifndef CONNECTIONFRAME_H
#define CONNECTIONFRAME_H

#include <QInputDialog>
#include <QtSql/QtSql>

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"

enum class DofusVersion
{
    MAJOR = 2,
    MINOR = 57,
    CODE = 9,
    BUILD = 13,
};

class ConnectionFrame : public AbstractFrame
{
public:
    ConnectionFrame(QMap<SocketIO*, BotData> *connectionsData, ConnectionManager *connectionManager);

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

private:
    ConnectionManager *m_connectionManager;
};

#endif // CONNECTIONFRAME_H
