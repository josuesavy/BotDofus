#ifndef GAMECHARACTERSTATUSFRAME_H
#define GAMECHARACTERSTATUSFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"

class GameCharacterStatusFrame : public AbstractFrame
{
public:
    GameCharacterStatusFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMECHARACTERSTATUSFRAME_H
