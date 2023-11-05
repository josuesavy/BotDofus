#ifndef GAMEINVENTORYEXCHANGESFRAME_H
#define GAMEINVENTORYEXCHANGESFRAME_H

#include "src/engines/core/process/frames/AbstractFrame.h"
#include "src/engines/core/process/managers/craft/CraftManager.h"
#include "src/engines/core/process/managers/exchange/ExchangeManager.h"

class GameInventoryExchangesFrame : public AbstractFrame
{
public:
    GameInventoryExchangesFrame(QMap<SocketIO*, BotData> *connectionsData, CraftManager *craftManager, ExchangeManager *exchangeManager);

    /*!
     * \brief Process message of the connection
     * \param data The message to process
     * \param sender Bot's particular connection
     * \return bool The message has been process
     */
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

private:
    CraftManager *m_craftManager;
    ExchangeManager *m_exchangeManager;
};

#endif // GAMEINVENTORYEXCHANGESFRAME_H
