#ifndef GAMEBASICFRAME_H
#define GAMEBASICFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/connection/ConnectionManager.h"
#include "src/Engines/IO/D2O/Misc/ParamsDecoder.h"

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
