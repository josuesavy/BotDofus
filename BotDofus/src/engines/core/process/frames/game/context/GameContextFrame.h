#ifndef GAMECONTEXTFRAME_H
#define GAMECONTEXTFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/fight/FightManager.h"
#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/flood/FloodManager.h"

class GameContextFrame : public AbstractFrame
{
    Q_OBJECT

public:
    GameContextFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager, MapManager *mapManager, FloodManager *floodManager);

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
    FloodManager *m_floodManager;
};

#endif // GAMECONTEXTFRAME_H
