#ifndef GAMECONTEXTFIGHTFRAME_H
#define GAMECONTEXTFIGHTFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/fight/FightManager.h"

class GameContextFightFrame : public AbstractFrame
{
public:
    GameContextFightFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager);

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

#endif // GAMECONTEXTFIGHTFRAME_H
