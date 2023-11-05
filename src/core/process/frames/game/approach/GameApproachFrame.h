#ifndef APPROACHFRAME_H
#define APPROACHFRAME_H

#include <QtSql/QtSql>

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/connection/ConnectionManager.h"

class GameApproachFrame : public AbstractFrame
{
public:
    GameApproachFrame(QMap<SocketIO*, BotData> *connectionsData, ConnectionManager *connectionManager);

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

#endif // APPROACHFRAME_H
