#ifndef GAMEINITIALIZATIONFRAME_H
#define GAMEINITIALIZATIONFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/group/GroupManager.h"

class GameInitializationFrame : public AbstractFrame
{
public:
    GameInitializationFrame(QMap<SocketIO*, BotData> *connectionsData, GroupManager *groupManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    GroupManager *m_groupManager;
};

#endif // GAMEINITIALIZATIONFRAME_H
