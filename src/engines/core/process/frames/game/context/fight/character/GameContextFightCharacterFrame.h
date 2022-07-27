#ifndef GAMECONTEXTFIGHTCHARACTERFRAME_H
#define GAMECONTEXTFIGHTCHARACTERFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/fight/FightManager.h"
#include "src/engines/core/process/managers/group/GroupManager.h"

class GameContextFightCharacterFrame : public AbstractFrame
{
public:
    GameContextFightCharacterFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager, GroupManager *groupManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    FightManager *m_fightManager;
    GroupManager *m_groupManager;
};

#endif // GAMECONTEXTFIGHTCHARACTERFRAME_H
