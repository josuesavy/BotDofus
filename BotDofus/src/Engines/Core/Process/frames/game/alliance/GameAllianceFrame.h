#ifndef ALLIANCEFRAME_H
#define ALLIANCEFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"

class GameAllianceFrame : public AbstractFrame
{
public:
    GameAllianceFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // ALLIANCEFRAME_H
