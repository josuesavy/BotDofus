#include "ShopManager.h"

ShopManager::ShopManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::SHOP, connectionsData)
{

}

void ShopManager::reset(SocketIO *sender)
{
    m_botData[sender].shopData.requestTradeObjectsInMerchand.clear();
    m_botData[sender].shopData.requestTradeObjectsInExchangeShop.clear();
    m_botData[sender].shopData.tradeObjectsInMerchand.clear();
    m_botData[sender].shopData.isReadyToMerchand = false;
}

bool ShopManager::processMerchand(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].shopData.isReadyToMerchand)
        return false;

    m_botData[sender].shopData.requestTradeObjectsInMerchand.clear();

    ExchangeRequestOnShopStockMessage erossmsg;
    sender->send(erossmsg);
    return true;
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

void ShopManager::addItemToSell(SocketIO *sender, uint objectUID, int quantity, double price)
{
    ExchangeObjectMovePricedMessage eompmsg;
    eompmsg.objectUID = objectUID;
    eompmsg.quantity = quantity;
    eompmsg.price = price;
    sender->send(eompmsg);
}

bool ShopManager::getIsItemExistInMerchand(SocketIO *sender, uint objectGID)
{
    foreach(RequestTradeObject rto, m_botData[sender].shopData.requestTradeObjectsInMerchand)
    {
        if(rto.GID == objectGID)
            return true;
    }

    return false;
}
