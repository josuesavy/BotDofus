#ifndef GAMECONTEXTROLEPLAYTREASUREHUNTFRAME_H
#define GAMECONTEXTROLEPLAYTREASUREHUNTFRAME_H

#include "src/Engines/Core/Process/frames/AbstractFrame.h"

class GameContextRoleplayTreasureHuntFrame : public AbstractFrame
{
public:
    GameContextRoleplayTreasureHuntFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECONTEXTROLEPLAYTREASUREHUNTFRAME_H
