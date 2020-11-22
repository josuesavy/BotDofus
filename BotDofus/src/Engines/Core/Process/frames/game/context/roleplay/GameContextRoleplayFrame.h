#ifndef GAMECONTEXTROLEPLAYFRAME_H
#define GAMECONTEXTROLEPLAYFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/flood/FloodManager.h"

class GameContextRoleplayFrame : public AbstractFrame
{
public:
    GameContextRoleplayFrame(QMap<SocketIO*, BotData> *connectionsData, FloodManager *floodManager);

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

private:
    FloodManager *m_floodManager;
};

#endif // GAMECONTEXTROLEPLAYFRAME_H
