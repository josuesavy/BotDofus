#ifndef GAMEGUILDFRAME_H
#define GAMEGUILDFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"

class GameGuildFrame : public AbstractFrame
{
public:
    GameGuildFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMEGUILDFRAME_H
