#ifndef GAMECONTEXTFRAME_H
#define GAMECONTEXTFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/fight/FightManager.h"
#include "src/core/process/managers/map/MapManager.h"

class GameContextFrame : public AbstractFrame
{
    Q_OBJECT

public:
    GameContextFrame(QMap<SocketIO*, BotData> *connectionsData, FightManager *fightManager, MapManager *mapManager);

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
