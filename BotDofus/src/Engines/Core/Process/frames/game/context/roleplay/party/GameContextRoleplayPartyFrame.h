#ifndef GAMECONTEXTROLEPLAYPARTYFRAME_H
#define GAMECONTEXTROLEPLAYPARTYFRAME_H

#include "src/Engines/Core/Process/Frames/AbstractFrame.h"
#include "src/Engines/Core/Process/Managers/map/MapManager.h"

class GameContextRoleplayPartyFrame : public AbstractFrame
{
public:
    GameContextRoleplayPartyFrame(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    MapManager *m_mapManager;
};

#endif // GAMECONTEXTROLEPLAYPARTYFRAME_H
