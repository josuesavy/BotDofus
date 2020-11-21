#ifndef ALMANACHFRAME_H
#define ALMANACHFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"

class GameAlmanachFrame : public AbstractFrame
{
public:
    GameAlmanachFrame(QMap<SocketIO*, BotData> *connectionsData);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);


    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);
};

#endif // ALMANACHFRAME_H
