#ifndef GAMECONTEXTROLEPLAYFRAME_H
#define GAMECONTEXTROLEPLAYFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/flood/FloodManager.h"

class GameContextRoleplayFrame : public AbstractFrame
{
public:
    GameContextRoleplayFrame(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager, FloodManager *floodManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    MapManager *m_mapManager;
    FloodManager *m_floodManager;
};

#endif // GAMECONTEXTROLEPLAYFRAME_H
