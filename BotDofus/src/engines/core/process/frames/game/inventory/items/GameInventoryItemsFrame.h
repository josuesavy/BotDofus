#ifndef GAMEINVENTORYITEMSFRAME_H
#define GAMEINVENTORYITEMSFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/exchange/ExchangeManager.h"
#include "src/engines/core/process/managers/stats/StatsManager.h"

class GameInventoryItemsFrame : public AbstractFrame
{
public:
    GameInventoryItemsFrame(QMap<SocketIO*, BotData> *connectionsData, ExchangeManager *exchangeManager, StatsManager *statsManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    ExchangeManager *m_exchangeManager;
    StatsManager *m_statsManager;
};

#endif // GAMEINVENTORYITEMSFRAME_H
