#include "GameInventoryExchangesFrame.h"

GameInventoryExchangesFrame::GameInventoryExchangesFrame(QMap<SocketIO *, BotData> *connectionsData, CraftManager *craftManager, ExchangeManager *exchangeManager):
    AbstractFrame(connectionsData),
    m_craftManager(craftManager),
    m_exchangeManager(exchangeManager)
{

}

bool GameInventoryExchangesFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = true;
            if (m_craftManager->compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients))
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                m_craftManager->processCrafting(sender);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
            m_botData[sender].craftData.step++;
    }
        break;

    case MessageEnum::EXCHANGEERRORMESSAGE:
    {
        ExchangeErrorMessage message;
        message.deserialize(&reader);

        QString typeError = "ui.exchange.";

        switch ((ExchangeErrorEnum)message.errorType)
        {
        case ExchangeErrorEnum::BUY_ERROR:
            typeError += "cantExchangeBuyError";
            break;
        case ExchangeErrorEnum::SELL_ERROR:
            typeError += "cantExchangeSellError";
            break;
        case ExchangeErrorEnum::BID_SEARCH_ERROR:
            typeError += "cantExchangeBIDSearchError";
            break;
        case ExchangeErrorEnum::REQUEST_IMPOSSIBLE:
            typeError += "cantExchange";
            break;
        case ExchangeErrorEnum::MOUNT_PADDOCK_ERROR:
            typeError += "cantExchangeMountPaddockError";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_GUEST:
            typeError += "cantExchangeCharacterGuest";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_OCCUPIED:
            typeError += "cantExchangeCharacterOccupied";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_OVERLOADED:
            typeError += "cantExchangeCharacterOverloaded";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_RESTRICTED:
            typeError += "cantExchangeCharacterRestricted";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_TOOL_TOO_FAR:
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_NOT_SUSCRIBER:
            typeError += "cantExchangeCharacterNotSuscriber";
            break;
        case ExchangeErrorEnum::REQUEST_CHARACTER_JOB_NOT_EQUIPED:
            typeError += "cantExchangeCharacterJobNotEquiped";
            break;
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText(typeError);
    }
        break;

    case MessageEnum::EXCHANGEISREADYMESSAGE:
    {
        ExchangeIsReadyMessage message;
        message.deserialize(&reader);

        if(message.ready)
        {
            ExchangeReadyMessage answer;
            answer.ready = true;
            answer.step = m_botData[sender].exchangeData.step;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE:
    {
        ExchangeItemAutoCraftStopedMessage message;
        message.deserialize(&reader);

        switch((ExchangeReplayStopReasonEnum)message.reason)
        {
        case ExchangeReplayStopReasonEnum::STOPPED_REASON_IMPOSSIBLE_MODIFICATION:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.craft.autoCraftStopedInvalidRecipe");
            break;
        case ExchangeReplayStopReasonEnum::STOPPED_REASON_MISSING_RESSOURCE:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.craft.autoCraftStopedNoRessource");
            break;
        case ExchangeReplayStopReasonEnum::STOPPED_REASON_OK:
            break;
        case ExchangeReplayStopReasonEnum::STOPPED_REASON_USER:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.craft.autoCraftStoped");
            break;
        }
    }
        break;

    case MessageEnum::EXCHANGELEAVEMESSAGE:
    {
        ExchangeLeaveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].generalData.botState == EXCHANGING_STATE)
        {
            m_botData[sender].generalData.botState = INACTIVE_STATE;

            if(message.success)
            {
                m_exchangeManager->updateExchange(sender);
                action(sender)<<"Succès de l'échange";
            }

            else
                error(sender)<<"Echec de l'échange";
        }

        else
            m_botData[sender].generalData.botState = INACTIVE_STATE;

        if ((m_botData[sender].generalData.botState == BotState::BANKING_STATE) || (m_botData[sender].interactionData.interactionType == CurrentInteraction::BANK))
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }

        if(m_botData[sender].shopData.isReadyToMerchand)
        {
            if(message.success)
                qDebug() << "[GameInventoryExchangesFrame] Merchant mode did not work";
        }
    }
        break;

    case MessageEnum::EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE:
    {
        ExchangeMountsTakenFromPaddockMessage message;
        message.deserialize(&reader);

        info(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.mount.takenFromPaddock").arg(message.name).arg(QString("[%1,%2").arg(message.worldX).arg(message.worldY)).arg(message.ownername);
    }
        break;

    case MessageEnum::EXCHANGEOBJECTADDEDMESSAGE:
    {
        ExchangeObjectAddedMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.step++;
            m_craftManager->addCraftComponent(sender, message.object);

            if (m_craftManager->compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients) && m_botData[sender].craftData.countSet)
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                m_craftManager->processCrafting(sender);
            }
        }

        if(message.remote)
        {
            InventoryObject item;
            item.GID = message.object->objectGID;
            item.UID = message.object->objectUID;
            item.quantity = message.object->quantity;

            m_botData[sender].exchangeData.objects<<item;
            m_exchangeManager->updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSADDEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsAddedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
            foreach (QSharedPointer<ObjectItem> o, message.object)
                m_craftManager->addCraftComponent(sender, o);

            if (m_craftManager->compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients) && m_botData[sender].craftData.countSet)
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                m_craftManager->processCrafting(sender);
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

    case MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE:
    {
        ExchangeRequestedTradeMessage message;
        message.deserialize(&reader);

        warn(sender)<<m_botData[sender].mapData.playersOnMap[message.source].name << "veut faire échange avec vous !";

        m_botData[sender].exchangeData.sourceId = message.source;

        if((m_botData[sender].exchangeData.isActive || m_botData[sender].mapData.playersOnMap[message.source].name == m_botData[sender].groupData.master) && m_botData[sender].generalData.botState == INACTIVE_STATE)
        {
            action(sender) << "Accept de l'echange...";
            ExchangeAcceptMessage answer;
            sender->send(answer);

            info(sender) << "Vous acceptez de faire échange avec" << m_botData[sender].mapData.playersOnMap[message.source].name+".";
        }

        else
        {
            action(sender) << "Refus de l'echange...";
            LeaveDialogRequestMessage answer;
            sender->send(answer);

            info(sender)<<"Vous avez refuser de faire un echange avec"<<m_botData[sender].mapData.playersOnMap[message.source].name;

            if(m_botData[sender].generalData.botState != INACTIVE_STATE)
                qDebug()<<"[GameInventoryExchangesFrame] Cannot launch the exchange because the character is other than inactive";
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

    case MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE:
    {
        ExchangeStartedBidSellerMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE:
    {
        ExchangeStartedTaxCollectorShopMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE:
    {
        m_botData[sender].exchangeData.currentKamas = 0;
        m_botData[sender].generalData.botState = EXCHANGING_STATE;
        m_botData[sender].exchangeData.step = 0;
        m_botData[sender].exchangeData.objects.clear();

        if(m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name == m_botData[sender].groupData.master)
        {
            m_botData[sender].exchangeData.isExchangingWithMaster = true;
            info(sender)<<"Vous êtes actuellement en échange avec"<<m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name<<"(chef)..";
            ExchangeObjectMoveKamaMessage answer;
            answer.quantity = m_botData[sender].playerData.kamas;
            sender->send(answer);
        }

        else
        {
            m_botData[sender].exchangeData.isExchangingWithMaster = false;
            info(sender)<<"Vous êtes actuellement en échange avec"<<m_botData[sender].mapData.playersOnMap[m_botData[sender].exchangeData.sourceId].name<<"..";
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE:
    {
        if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
                && m_botData[sender].generalData.botState == BotState::INACTIVE_STATE
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].generalData.botState = BotState::BANKING_STATE;
            m_botData[sender].interactionData.interactionType = CurrentInteraction::BANK;
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKCRAFTMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = false;
            m_botData[sender].craftData.recipeStack.clear();

            foreach (int r, m_botData[sender].craftData.toCraft.ingredients.keys())
            {
                ExchangeObjectMoveMessage message;
                message.quantity = m_botData[sender].craftData.toCraft.ingredients[r];
                message.objectUID = r;

                sender->send(message);
            }

            ExchangeCraftCountRequestMessage message;
            message.count = m_botData[sender].craftData.recipeQuantities[m_botData[sender].craftData.toCraft.recipeId];
            sender->send(message);
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = false;
            m_botData[sender].craftData.recipeStack.clear();

            foreach (int r, m_botData[sender].craftData.toCraft.ingredients.keys())
            {
                ExchangeObjectMoveMessage message;
                message.quantity = m_botData[sender].craftData.toCraft.ingredients[r];
                message.objectUID = r;

                sender->send(message);
            }

            ExchangeCraftCountRequestMessage message;
            message.count = m_botData[sender].craftData.recipeQuantities[m_botData[sender].craftData.toCraft.recipeId];
            sender->send(message);
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE:
    {
        ExchangeStartOkEvolutiveObjectRecycleTradeMessage message;
        message.deserialize(&reader);
    }
        break;

    case MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE:
    {
        ExchangeStartOkNpcShopMessage message;
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
    }

    return messageFound;
}
