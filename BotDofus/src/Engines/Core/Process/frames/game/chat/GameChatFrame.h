#ifndef GAMECHATFRAME_H
#define GAMECHATFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/fight/FightManager.h"

class GameChatFrame : public AbstractFrame
{
public:
    GameChatFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    FightManager *m_fightManager;
};

#endif // GAMECHATFRAME_H
