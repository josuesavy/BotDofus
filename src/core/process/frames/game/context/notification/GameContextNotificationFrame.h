#ifndef GAMECONTEXTNOTIFICATIONFRAME_H
#define GAMECONTEXTNOTIFICATIONFRAME_H

#include "src/core/process/frames/AbstractFrame.h"

class GameContextNotificationFrame : public AbstractFrame
{
public:
    GameContextNotificationFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECONTEXTNOTIFICATIONFRAME_H
