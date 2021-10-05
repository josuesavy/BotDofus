#include "ShopModule.h"

ShopModule::ShopModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::SHOP, connectionsData)
{

}

void ShopModule::reset(SocketIO *sender)
{
    m_botData[sender].shopData.requestTradeObjectsInMerchand.clear();
    m_botData[sender].shopData.requestTradeObjectsInExchangeShop.clear();
    m_botData[sender].shopData.tradeObjectsInMerchand.clear();
    m_botData[sender].shopData.isReadyToMerchand = false;
}

bool ShopModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default:
        messageFound = false;
        break;

    case MessageEnum::EXCHANGESHOPSTOCKSTARTEDMESSAGE:
    {
        ExchangeShopStockStartedMessage message;
        message.deserialize(&reader);

        m_botData[sender].shopData.tradeObjectsInMerchand.clear();

        foreach(QSharedPointer<ObjectItemToSell> o, message.objectsInfos)
        {
            RequestTradeObject requestTradeObject;
            requestTradeObject.GID = o->objectGID;
            requestTradeObject.UID = o->objectUID;
            requestTradeObject.price = o->objectPrice;
            requestTradeObject.quantity = o->quantity;

            m_botData[sender].shopData.tradeObjectsInMerchand << requestTradeObject;
        }

        if(!m_botData[sender].shopData.requestTradeObjectsInMerchand.isEmpty())
        {
            foreach(RequestTradeObject requestTradeObject, m_botData[sender].shopData.requestTradeObjectsInMerchand)
            {
                foreach(RequestTradeObject tradeObject, m_botData[sender].shopData.tradeObjectsInMerchand)
                {
                    if(requestTradeObject.UID == tradeObject.UID && (requestTradeObject.price != tradeObject.price || requestTradeObject.quantity != tradeObject.quantity))
                    {
                        ExchangeObjectModifyPricedMessage eompmsg;
                        eompmsg.price = requestTradeObject.price;
                        eompmsg.objectUID = requestTradeObject.UID;
                        eompmsg.quantity = requestTradeObject.quantity;
                        sender->send(eompmsg);
                    }

                    else if(requestTradeObject.UID != tradeObject.UID)
                    {
                        ExchangeObjectMoveMessage eommsg;
                        eommsg.objectUID = tradeObject.UID;
                        eommsg.quantity = -tradeObject.quantity;
                        sender->send(eommsg);

                        ExchangeObjectMovePricedMessage eompmsg;
                        eompmsg.price = requestTradeObject.price;
                        eompmsg.objectUID = requestTradeObject.GID;
                        eompmsg.quantity = requestTradeObject.quantity;
                        sender->send(eompmsg);
                    }
                }
            }
        }

        m_botData[sender].shopData.isReadyToMerchand = true;

        if(m_botData[sender].shopData.isReadyToMerchand)
        {
            ExchangeShowVendorTaxMessage esvtmsg;
            sender->send(esvtmsg);
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE:
    {
        ExchangeShopStockMovementUpdatedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].shopData.tradeObjectsInMerchand.size(); i++)
        {
            if(m_botData[sender].shopData.tradeObjectsInMerchand.at(i).GID == message.objectInfo->objectGID)
            {
                m_botData[sender].shopData.tradeObjectsInMerchand.removeAt(i);

                RequestTradeObject requestTradeObject;
                requestTradeObject.GID = message.objectInfo->objectGID;
                requestTradeObject.UID = message.objectInfo->objectUID;
                requestTradeObject.price = message.objectInfo->objectPrice;
                requestTradeObject.quantity = message.objectInfo->quantity;

                m_botData[sender].shopData.tradeObjectsInMerchand.replace(i, requestTradeObject);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE:
    {
        ExchangeShopStockMovementRemovedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].shopData.tradeObjectsInMerchand.size(); i++)
        {
            if(m_botData[sender].shopData.tradeObjectsInMerchand.at(i).UID == message.objectId)
                m_botData[sender].shopData.tradeObjectsInMerchand.removeAt(i);
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE:
    {
        ExchangeShopStockMultiMovementUpdatedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].shopData.tradeObjectsInMerchand.size(); i++)
        {
            for(int j = 0; j < message.objectInfoList.size(); j++)
            {
                if(message.objectInfoList.at(j)->objectUID == m_botData[sender].shopData.tradeObjectsInMerchand.at(i).UID)
                {
                    RequestTradeObject requestTradeObject;
                    requestTradeObject.GID = message.objectInfoList.at(j)->objectGID;
                    requestTradeObject.UID = message.objectInfoList.at(j)->objectUID;
                    requestTradeObject.price = message.objectInfoList.at(j)->objectPrice;
                    requestTradeObject.quantity = message.objectInfoList.at(j)->quantity;

                    m_botData[sender].shopData.tradeObjectsInMerchand.replace(i, requestTradeObject);
                }
            }
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE:
    {
        ExchangeShopStockMultiMovementRemovedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].shopData.tradeObjectsInMerchand.size(); i++)
        {
            for(int j = 0; j < message.objectIdList.size(); j++)
            {
                if(message.objectIdList.at(j) == m_botData[sender].shopData.tradeObjectsInMerchand.at(i).UID)
                    m_botData[sender].shopData.tradeObjectsInMerchand.removeAt(i);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGEREPLYTAXVENDORMESSAGE:
    {
        ExchangeReplyTaxVendorMessage message;
        message.deserialize(&reader);

        warn(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.humanVendor.taxPriceMessage").replace("%1", QString::number(message.totalTaxValue));

        LeaveDialogRequestMessage ldrmsg;
        sender->send(ldrmsg);

        ExchangeStartAsVendorMessage esavmsg;
        sender->send(esavmsg);
    }
        break;

    case MessageEnum::EXCHANGELEAVEMESSAGE:
    {
        ExchangeLeaveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].shopData.isReadyToMerchand)
        {
            if(message.success)
                qDebug() << "ShopModule - Erreur le mode marchand n'a pas fonctionné";
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE:
    {
        ExchangeStartOkNpcShopMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE:
    {
        ExchangeStartedTaxCollectorShopMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE:
    {
        ExchangeStartOkEvolutiveObjectRecycleTradeMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTOKNPCTRADEMESSAGE:
    {
        ExchangeStartOkNpcTradeMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE:
    {
        ExchangeStartOkRecycleTradeMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTOKRUNESTRADEMESSAGE:
    {
        ExchangeStartOkRunesTradeMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTEDBIDBUYERMESSAGE:
    {
        ExchangeStartedBidBuyerMessage message;
        message.deserialize(&reader);

        m_botData[sender].generalData.botState = BotState::EXCHANGING_STATE;

        m_botData[sender].shopData.typesItemsCanSell << message.buyerDescriptor.types;
        m_botData[sender].shopData.maxItemLevel = message.buyerDescriptor.maxItemLevel;
        m_botData[sender].shopData.maxItemPerAccount = message.buyerDescriptor.maxItemPerAccount;

        if(m_botData[sender].shopData.requestTradeObjectsInExchangeShop.size())
        {
            foreach(RequestTradeObject o, m_botData[sender].shopData.requestTradeObjectsInExchangeShop)
            {
                QSharedPointer<ItemData> item = qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getItem(o.GID));

                if(m_botData[sender].shopData.typesItemsCanSell.contains(item->getTypeId()))
                {
                    ExchangeBidHouseTypeMessage ebhtmsg;
                    ebhtmsg.type = item->getTypeId();
                    ebhtmsg.follow = true;
                    sender->send(ebhtmsg);
                }
            }

            //ExchangeBidHouseSearchMessage eb
        }
    }
        break;

    case MessageEnum::EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE:
    {
        ExchangeTypesExchangerDescriptionForUserMessage message;
        message.deserialize(&reader);

        m_botData[sender].shopData.itemInSell << message.typeDescription;
    }
        break;

    case MessageEnum::EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE:
    {
        ExchangeTypesItemsExchangerDescriptionForUserMessage message;
        message.deserialize(&reader);


    }
        break;

    case MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE:
    {
        ExchangeStartedBidSellerMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::HAAPISHOPAPIKEYMESSAGE:
    {
        HaapiShopApiKeyMessage message;
        message.deserialize(&reader);
    }
        break;
    }

    return messageFound;
}

bool ShopModule::processMerchand(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].shopData.isReadyToMerchand)
        return false;

    m_botData[sender].shopData.requestTradeObjectsInMerchand.clear();

    ExchangeRequestOnShopStockMessage erossmsg;
    sender->send(erossmsg);
    return true;
}

bool ShopModule::processShop(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].generalData.botState != BotState::REGENERATING_STATE)
        return false;
}

void ShopModule::buyItem(SocketIO *sender, uint genid)
{
    ExchangeBidHouseSearchMessage ebhsmsg;
    ebhsmsg.genId = genid;
    ebhsmsg.follow = true;
    sender->send(ebhsmsg);
}

void ShopModule::addItemToSell(SocketIO *sender, uint objectUID, int quantity, double price)
{
    ExchangeObjectMovePricedMessage eompmsg;
    eompmsg.objectUID = objectUID;
    eompmsg.quantity = quantity;
    eompmsg.price = price;
    sender->send(eompmsg);
}

bool ShopModule::getIsItemExistInMerchand(SocketIO *sender, uint objectGID)
{
    foreach(RequestTradeObject rto, m_botData[sender].shopData.requestTradeObjectsInMerchand)
    {
        if(rto.GID == objectGID)
            return true;
    }

    return false;
}
