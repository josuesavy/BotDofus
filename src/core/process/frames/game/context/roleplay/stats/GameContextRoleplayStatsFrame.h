#ifndef GAMECONTEXTROLEPLAYSTATSFRAME_H
#define GAMECONTEXTROLEPLAYSTATSFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/stats/StatsManager.h"

class GameContextRoleplayStatsFrame : public AbstractFrame
{
public:
    GameContextRoleplayStatsFrame(QMap<SocketIO*, BotData> *connectionsData, StatsManager *statsManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    StatsManager *m_statsManager;
};

#endif // GAMECONTEXTROLEPLAYSTATSFRAME_H
