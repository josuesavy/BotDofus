#ifndef GAMEBASICFRAME_H
#define GAMEBASICFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/connection/ConnectionManager.h"
#include "src/engines/utils/ParamsDecoder.h"

class GameBasicFrame : public AbstractFrame
{
public:
    GameBasicFrame(QMap<SocketIO*, BotData> *connectionsData, ConnectionManager *connectionManager);

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

#endif // GAMEBASICFRAME_H
