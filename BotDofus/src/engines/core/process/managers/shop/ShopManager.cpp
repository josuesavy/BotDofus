#include "ShopManager.h"

ShopManager::ShopManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::SHOP, connectionsData)
{

}

void ShopManager::reset(SocketIO *sender)
{
    m_botData[sender].shopData.requestTradeObjectsInExchangeShop.clear();
}

bool ShopManager::processShop(SocketIO *sender)
{
    bool toReturn = true;

    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].generalData.botState != BotState::REGENERATING_STATE)
        toReturn = false;

    return toReturn;
}

void ShopManager::buyItem(SocketIO *sender, uint genid)
{
    ExchangeBidHouseSearchMessage ebhsmsg;
    ebhsmsg.genId = genid;
    ebhsmsg.follow = true;
    sender->send(ebhsmsg);
}
