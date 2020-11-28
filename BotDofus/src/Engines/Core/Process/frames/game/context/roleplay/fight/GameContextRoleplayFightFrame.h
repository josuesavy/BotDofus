#ifndef GAMECONTEXTROLEPLAYFIGHTFRAME_H
#define GAMECONTEXTROLEPLAYFIGHTFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"

class GameContextRoleplayFightFrame : public AbstractFrame
{
public:
    GameContextRoleplayFightFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECONTEXTROLEPLAYFIGHTFRAME_H
