#ifndef GAMECONTEXTFRAME_H
#define GAMECONTEXTFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/fight/FightManager.h"
#include "src/Engines/Core/Process/Managers/map/MapManager.h"

class GameContextFrame : public AbstractFrame
{
public:
    GameContextFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager, MapManager *mapManager);

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
    FightManager *m_fightManager;
    MapManager *m_mapManager;
};

#endif // GAMECONTEXTFRAME_H
