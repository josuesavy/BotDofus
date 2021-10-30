#include "MerchandManager.h"

MerchandManager::MerchandManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::MERCHAND, connectionsData)
{

}

void MerchandManager::reset(SocketIO *sender)
{
    m_botData[sender].merchandData.requestObjectsItemToSell.clear();
    m_botData[sender].merchandData.objectsItemToSell.clear();
    m_botData[sender].merchandData.isReady = false;
}

bool MerchandManager::processMerchand(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].merchandData.requestObjectsItemToSell.isEmpty())
        return false;

    m_botData[sender].generalData.botState = BotState::MERCHAND_STATE;
    ExchangeRequestOnShopStockMessage erossmsg;
    sender->send(erossmsg);
    return true;
}

bool MerchandManager::objectItemToSellAlreadyExist(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    bool found = false;
    for (int i = 0; i < m_botData[sender].merchandData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchandData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchandData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            found = true;
            break;
        }
    }
    return found;
}

void MerchandManager::addObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    bool found = objectItemToSellAlreadyExist(sender, objectItemToSell);
    if (!found)
    {
        RequestObjectItemToSell requestTradeObject;
        requestTradeObject.GID = objectItemToSell.objectGID;
        requestTradeObject.UID = objectItemToSell.objectUID;
        requestTradeObject.quantity = objectItemToSell.objectPrice;
        requestTradeObject.price = objectItemToSell.quantity;

        m_botData[sender].merchandData.requestObjectsItemToSell.append(requestTradeObject);
    }
    else
        editObjectItemToSell(sender, objectItemToSell);
}

void MerchandManager::editObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    for (int i = 0; i < m_botData[sender].merchandData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchandData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchandData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            RequestObjectItemToSell requestTradeObject;
            requestTradeObject.GID = objectItemToSell.objectGID;
            requestTradeObject.UID = objectItemToSell.objectUID;
            requestTradeObject.quantity = objectItemToSell.objectPrice;
            requestTradeObject.price = objectItemToSell.quantity;

            m_botData[sender].merchandData.requestObjectsItemToSell[i] = requestTradeObject;
            break;
        }
    }
}

void MerchandManager::removeObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    for (int i = 0; i < m_botData[sender].merchandData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchandData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchandData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            m_botData[sender].merchandData.requestObjectsItemToSell[i].toRemove = true;
            break;
        }
    }
}
