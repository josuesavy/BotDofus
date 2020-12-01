#ifndef GAMETINSELFRAME_H
#define GAMETINSELFRAME_H

#include "src/Engines/Core/Process/frames/AbstractFrame.h"

class GameTinselFrame : public AbstractFrame
{
public:
    GameTinselFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // GAMETINSELFRAME_H
