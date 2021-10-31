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

    case MessageEnum::EXCHANGEBUYOKMESSAGE:
    {
        ExchangeBuyOkMessage message;
        message.deserialize(&reader);
    }
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

        if (message.success)
        {
            switch ((DialogTypeEnum)message.dialogType)
            {
            case DialogTypeEnum::DIALOG_EXCHANGE:
            {
                if (m_botData[sender].generalData.botState == MERCHANT_STATE)
                {
                    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                    if(m_botData[sender].merchantData.isReady)
                    {
                        ExchangeStartAsVendorMessage esavmsg;
                        sender->send(esavmsg);
                    }

                    m_botData[sender].merchantData.isReady = false;
                    m_botData[sender].merchantData.requestObjectsItemToSell.clear();
                    m_botData[sender].merchantData.sellerId = INVALID;
                    m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop.clear();
                }

                else if (m_botData[sender].generalData.botState == EXCHANGING_STATE)
                {
                    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                    m_exchangeManager->updateExchange(sender);
                    info(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.exchange.success");
                }

                else if ((m_botData[sender].generalData.botState == BotState::BANKING_STATE) || (m_botData[sender].interactionData.interactionType == CurrentInteraction::BANK))
                {
                    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
                    m_botData[sender].interactionData.interactionId = INVALID;
                    m_botData[sender].interactionData.finishedAction = true;
                    m_botData[sender].interactionData.actionID = INVALID;
                    m_botData[sender].interactionData.npcDialogs.clear();
                    emit scriptActionDone(sender);
                }

                else
                    m_botData[sender].generalData.botState = INACTIVE_STATE;

            }
                break;

            case DialogTypeEnum::DIALOG_ALLIANCE_CREATE:
            case DialogTypeEnum::DIALOG_ALLIANCE_INVITATION:
            case DialogTypeEnum::DIALOG_ALLIANCE_RENAME:
            case DialogTypeEnum::DIALOG_BOOK:
            case DialogTypeEnum::DIALOG_DIALOG:
            case DialogTypeEnum::DIALOG_DUNGEON_MEETING:
            case DialogTypeEnum::DIALOG_GUILD_CREATE:
            case DialogTypeEnum::DIALOG_GUILD_INVITATION:
            case DialogTypeEnum::DIALOG_GUILD_RENAME:
            case DialogTypeEnum::DIALOG_HAVENBAG_MEETING:
            case DialogTypeEnum::DIALOG_LOCKABLE:
            case DialogTypeEnum::DIALOG_MARRIAGE:
            case DialogTypeEnum::DIALOG_PURCHASABLE:
            case DialogTypeEnum::DIALOG_SPELL_FORGET:
            case DialogTypeEnum::DIALOG_TELEPORTER:
                break;
            }
        }

        else
            info(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.exchange.cancel");
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

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
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
    }
        break;

    case MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE:
    {
        ExchangeRequestedTradeMessage message;
        message.deserialize(&reader);

        warn(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.exchange.resquestMessage").arg(m_botData[sender].mapData.playersOnMap[message.source].name);

        m_botData[sender].exchangeData.sourceId = message.source;

        if((m_botData[sender].exchangeData.isActive || m_botData[sender].mapData.playersOnMap[message.source].name == m_botData[sender].groupData.master) && m_botData[sender].generalData.botState == INACTIVE_STATE)
        {
            action(sender) << "Accept de l'echange...";
            ExchangeAcceptMessage answer;
            sender->send(answer);
        }

        else
        {
            action(sender) << "Refus de l'echange...";
            LeaveDialogRequestMessage answer;
            sender->send(answer);

            if(m_botData[sender].generalData.botState != INACTIVE_STATE)
                qDebug()<<"[GameInventoryExchangesFrame] Cannot launch the exchange because the character is other than inactive";
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKSTARTEDMESSAGE:
    {
        ExchangeShopStockStartedMessage message;
        message.deserialize(&reader);

        // Add object item to sell already added
        m_botData[sender].merchantData.objectsItemToSell.clear();
        foreach(QSharedPointer<ObjectItemToSell> objectItemToSell, message.objectsInfos)
        {
            m_botData[sender].merchantData.objectsItemToSell << objectItemToSell;
        }

        // Add object item to sell to add
        if(!m_botData[sender].merchantData.requestObjectsItemToSell.isEmpty() && !m_botData[sender].merchantData.objectsItemToSell.isEmpty())
        {
            foreach(RequestObjectItemToSell requestTradeObject, m_botData[sender].merchantData.requestObjectsItemToSell)
            {
                foreach(QSharedPointer<ObjectItemToSell> objectItemToSell, m_botData[sender].merchantData.objectsItemToSell)
                {
                    if(requestTradeObject.UID == objectItemToSell->objectUID && (requestTradeObject.price != objectItemToSell->objectPrice || requestTradeObject.quantity != objectItemToSell->quantity))
                    {
                        ExchangeObjectModifyPricedMessage eompmsg;
                        eompmsg.price = requestTradeObject.price;
                        eompmsg.objectUID = requestTradeObject.UID;
                        eompmsg.quantity = requestTradeObject.quantity;
                        sender->send(eompmsg);
                    }

                    else if(requestTradeObject.UID != objectItemToSell->objectUID && requestTradeObject.toRemove)
                    {
                        ExchangeObjectMoveMessage eommsg;
                        eommsg.objectUID = objectItemToSell->objectUID;
                        eommsg.quantity = objectItemToSell->quantity;
                        sender->send(eommsg);
                    }

                    else
                    {
                        ExchangeObjectMovePricedMessage eompmsg;
                        eompmsg.price = requestTradeObject.price;
                        eompmsg.objectUID = requestTradeObject.GID;
                        eompmsg.quantity = requestTradeObject.quantity;
                        sender->send(eompmsg);
                    }
                }
            }
        }

        if (!m_botData[sender].merchantData.objectsItemToSell.isEmpty())
        {
            m_botData[sender].merchantData.isReady = true;
            if(m_botData[sender].merchantData.isReady)
            {
                ExchangeShowVendorTaxMessage esvtmsg;
                sender->send(esvtmsg);
            }
        }
        else
        {
            m_botData[sender].merchantData.isReady = false;
            LeaveDialogRequestMessage ldrmsg;
            sender->send(ldrmsg);
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE:
    {
        ExchangeShopStockMovementUpdatedMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].merchantData.sellerId > 0)
        {
            QSharedPointer <ObjectItemToSellInHumanVendorShop> objectItemToSellInHumanVendorShop;
            objectItemToSellInHumanVendorShop->effects = message.objectInfo->effects;
            objectItemToSellInHumanVendorShop->objectGID = message.objectInfo->objectGID;
            objectItemToSellInHumanVendorShop->objectPrice = message.objectInfo->objectPrice;
            objectItemToSellInHumanVendorShop->objectUID = message.objectInfo->objectUID;
            objectItemToSellInHumanVendorShop->quantity = message.objectInfo->quantity;

            for (int i = 0; i < m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop.size(); i++)
            {
                if (m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop[i]->objectGID == message.objectInfo->objectGID && m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop[i]->objectUID == message.objectInfo->objectUID)
                {
                    m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop.replace(i, objectItemToSellInHumanVendorShop);
                }
            }
        }

        else
        {
            if (m_botData[sender].merchantData.objectsItemToSell.contains(message.objectInfo))
            {
                int index = m_botData[sender].merchantData.objectsItemToSell.indexOf(message.objectInfo);
                m_botData[sender].merchantData.objectsItemToSell.replace(index, message.objectInfo);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE:
    {
        ExchangeShopStockMovementRemovedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].merchantData.objectsItemToSell.size(); i++)
        {
            if(m_botData[sender].merchantData.objectsItemToSell.at(i)->objectUID == message.objectId)
                m_botData[sender].merchantData.objectsItemToSell.removeAt(i);
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE:
    {
        ExchangeShopStockMultiMovementUpdatedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < message.objectInfoList.size(); i++)
        {
            if (m_botData[sender].merchantData.objectsItemToSell.contains(message.objectInfoList.at(i)))
            {
                int index = m_botData[sender].merchantData.objectsItemToSell.indexOf(message.objectInfoList.at(i));
                m_botData[sender].merchantData.objectsItemToSell.replace(index, message.objectInfoList.at(i));
            }
        }
    }
        break;

    case MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE:
    {
        ExchangeShopStockMultiMovementRemovedMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < m_botData[sender].merchantData.objectsItemToSell.size(); i++)
        {
            for(int j = 0; j < message.objectIdList.size(); j++)
            {
                if(message.objectIdList.at(j) == m_botData[sender].merchantData.objectsItemToSell.at(i)->objectUID)
                    m_botData[sender].merchantData.objectsItemToSell.removeAt(i);
            }
        }
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

    case MessageEnum::EXCHANGESTARTOKHUMANVENDORMESSAGE:
    {
        ExchangeStartOkHumanVendorMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].mapData.merchantsOnMap.contains(message.sellerId))
        {
            m_botData[sender].merchantData.objectsItemToSellInHumanVendorShop = message.objectsInfos;
            m_botData[sender].merchantData.sellerId = message.sellerId;
        }
        else
        {
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            error(sender) << "Unable to find the seller character in the entityFrame";
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
            foreach(RequestObjectItemToSell o, m_botData[sender].shopData.requestTradeObjectsInExchangeShop)
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
    }

    return messageFound;
}
