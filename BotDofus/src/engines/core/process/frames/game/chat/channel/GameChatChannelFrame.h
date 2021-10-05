#ifndef GAMECHATCHANNELFRAME_H
#define GAMECHATCHANNELFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"

class GameChatChannelFrame : public AbstractFrame
{
public:
    GameChatChannelFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECHATCHANNELFRAME_H
