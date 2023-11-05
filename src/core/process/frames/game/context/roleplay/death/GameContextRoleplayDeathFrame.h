#ifndef GAMECONTEXTROLEPLAYDEATHFRAME_H
#define GAMECONTEXTROLEPLAYDEATHFRAME_H

#include "src/core/process/frames/AbstractFrame.h"
#include "src/core/process/managers/stats/StatsManager.h"

class GameContextRoleplayDeathFrame : public AbstractFrame
{
public:
    GameContextRoleplayDeathFrame(QMap<SocketIO*, BotData> *connectionsData, StatsManager *statsManager);

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

#endif // GAMECONTEXTROLEPLAYDEATHFRAME_H
