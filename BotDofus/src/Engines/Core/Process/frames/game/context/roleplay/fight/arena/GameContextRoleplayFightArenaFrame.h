#ifndef GAMECONTEXTROLEPLAYFIGHTARENAFRAME_H
#define GAMECONTEXTROLEPLAYFIGHTARENAFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"

class GameContextRoleplayFightArenaFrame : public AbstractFrame
{
public:
    GameContextRoleplayFightArenaFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECONTEXTROLEPLAYFIGHTARENAFRAME_H
