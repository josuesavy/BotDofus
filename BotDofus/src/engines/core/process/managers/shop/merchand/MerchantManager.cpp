#include "MerchantManager.h"

MerchantManager::MerchantManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::MERCHANT, connectionsData)
{

}

void MerchantManager::reset(SocketIO *sender)
{
    m_botData[sender].merchantData.requestObjectsItemToSell.clear();
    m_botData[sender].merchantData.objectsItemToSell.clear();
    m_botData[sender].merchantData.isReady = false;
}

bool MerchantManager::processMerchant(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].merchantData.requestObjectsItemToSell.isEmpty())
        return false;

    m_botData[sender].generalData.botState = BotState::MERCHANT_STATE;
    ExchangeRequestOnShopStockMessage erossmsg;
    sender->send(erossmsg);
    return true;
}

void MerchantManager::addObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    bool found = false;
    for (int i = 0; i < m_botData[sender].merchantData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchantData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchantData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        RequestObjectItemToSell requestTradeObject;
        requestTradeObject.GID = objectItemToSell.objectGID;
        requestTradeObject.UID = objectItemToSell.objectUID;
        requestTradeObject.quantity = objectItemToSell.objectPrice;
        requestTradeObject.price = objectItemToSell.quantity;

        m_botData[sender].merchantData.requestObjectsItemToSell.append(requestTradeObject);
    }
    else
        editObjectItemToSell(sender, objectItemToSell);
}

void MerchantManager::editObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    for (int i = 0; i < m_botData[sender].merchantData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchantData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchantData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            RequestObjectItemToSell requestTradeObject;
            requestTradeObject.GID = objectItemToSell.objectGID;
            requestTradeObject.UID = objectItemToSell.objectUID;
            requestTradeObject.quantity = objectItemToSell.objectPrice;
            requestTradeObject.price = objectItemToSell.quantity;

            m_botData[sender].merchantData.requestObjectsItemToSell[i] = requestTradeObject;
            break;
        }
    }
}

void MerchantManager::removeObjectItemToSell(SocketIO *sender, ObjectItemToSell objectItemToSell)
{
    for (int i = 0; i < m_botData[sender].merchantData.requestObjectsItemToSell.size(); i++)
    {
        if (m_botData[sender].merchantData.requestObjectsItemToSell[i].UID == objectItemToSell.objectUID && m_botData[sender].merchantData.requestObjectsItemToSell[i].GID == objectItemToSell.objectGID)
        {
            m_botData[sender].merchantData.requestObjectsItemToSell[i].toRemove = true;
            break;
        }
    }
}

void MerchantManager::openMerchantWithPlayer(SocketIO *sender, QString merchantName)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].merchantData.isReady)
        return;

    MerchantInfos merchant;
    QMapIterator<uint, MerchantInfos> merchants(m_botData[sender].mapData.merchantsOnMap);
    while (merchants.hasNext())
    {
        merchants.next();
        if (merchants.value().name == merchantName)
        {
            merchant.cellId = merchants.value().cellId;
            merchant.direction = merchants.value().direction;
            merchant.look = merchants.value().look;
            merchant.merchantId = merchants.value().merchantId;
            merchant.name = merchants.value().name;
            merchant.options = merchants.value().options;
            merchant.sellType = merchants.value().sellType;
        }
    }

    if (merchant.merchantId > INVALID)
    {
        m_botData[sender].generalData.botState = BotState::MERCHANT_STATE;

        ExchangeOnHumanVendorRequestMessage eohvrmsg;
        eohvrmsg.humanVendorCell = merchant.cellId;
        eohvrmsg.humanVendorId = merchant.merchantId;
        sender->send(eohvrmsg);
    }
}

void MerchantManager::buyItemFromMerchant(SocketIO *sender, uint objectToBuyId, uint quantity)
{
    if (m_botData[sender].generalData.botState != BotState::MERCHANT_STATE && m_botData[sender].merchantData.sellerId == INVALID)
        return;

    ExchangeBuyMessage ebmsg;
    ebmsg.objectToBuyId = objectToBuyId;
    ebmsg.quantity = quantity;
    sender->send(ebmsg);
}
