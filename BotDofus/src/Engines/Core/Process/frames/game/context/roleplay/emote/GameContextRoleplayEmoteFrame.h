#ifndef GAMECONTEXTROLEPLAYEMOTEFRAME_H
#define GAMECONTEXTROLEPLAYEMOTEFRAME_H

#include "src/Engines/Core/Process/frames/AbstractFrame.h"

class GameContextRoleplayEmoteFrame : public AbstractFrame
{
public:
    GameContextRoleplayEmoteFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECONTEXTROLEPLAYEMOTEFRAME_H
