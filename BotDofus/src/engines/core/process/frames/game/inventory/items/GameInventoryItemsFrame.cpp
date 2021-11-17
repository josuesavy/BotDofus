#include "GameInventoryItemsFrame.h"

GameInventoryItemsFrame::GameInventoryItemsFrame(QMap<SocketIO *, BotData> *connectionsData, ExchangeManager *exchangeManager, StatsManager *statsManager):
    AbstractFrame(connectionsData),
    m_exchangeManager(exchangeManager),
    m_statsManager(statsManager)
{

}

bool GameInventoryItemsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE:
    {
        ExchangeKamaModifiedMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE && m_botData[sender].craftData.isCrafting)
            m_botData[sender].craftData.step++;

        if(message.remote)
            m_exchangeManager->updateExchange(sender);

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE:
    {
        ExchangeObjectModifiedMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.step++;
        }

        if(message.remote)
        {
            int size = m_botData[sender].exchangeData.objects.size();
            for(int i = 0; i < size; i++)
            {
                if(m_botData[sender].exchangeData.objects[i].UID == message.object->objectUID)
                {
                    InventoryObject item;
                    item.GID = message.object->objectGID;
                    item.UID = message.object->objectUID;
                    item.quantity = message.object->quantity;

                    m_botData[sender].exchangeData.objects[i] = item;
                    break;
                }
            }

            m_exchangeManager->updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE:
    {
        ExchangeObjectRemovedMessage message;
        message.deserialize(&reader);

        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.step++;
        }

        if(message.remote)
        {
            int size = m_botData[sender].exchangeData.objects.size();
            for(int i = 0; i < size; i++)
            {
                if(message.objectUID == m_botData[sender].exchangeData.objects[i].UID)
                {
                    m_botData[sender].exchangeData.objects.removeAt(i);
                    break;
                }
            }
            m_exchangeManager->updateExchange(sender);
        }

        m_botData[sender].exchangeData.step++;
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsModifiedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsRemovedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::INVENTORYCONTENTMESSAGE:
    {
        InventoryContentMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.kamas = message.kamas;

        if (!message.objects.isEmpty())
        {
            m_botData[sender].playerData.inventoryContent.clear();

            for(int i = 0; i < message.objects.size(); i++)
            {
                InventoryObject item;
                item.GID = message.objects[i]->objectGID;
                item.UID = message.objects[i]->objectUID;
                item.quantity = message.objects[i]->quantity;
                item.position = (CharacterInventoryPositionEnum)message.objects[i]->position;
                if (m_statsManager->inventoryPositions.contains(item.position))
                    item.isEquipped = true;

                for (int j = 0; j < message.objects[i]->effects.size(); j++)
                    for (int k = 0; k < message.objects[i]->effects[j]->getTypes().size(); k++)
                        if ((int)message.objects[i]->effects[j]->getTypes()[k] == 70 &&
                                qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.objects[i]->effects[j]->actionId))->getCharacteristic() == 0)
                            item.regenLife = qSharedPointerCast<ObjectEffectInteger>(message.objects[i]->effects[j])->value;

                m_botData[sender].playerData.inventoryContent<<item;

                PetFeedInfos pet;
                pet.GID = message.objects[i]->objectGID;

                if (m_statsManager->pets.keys().contains(message.objects[i]->objectGID) && !m_botData[sender].interactionData.petData.petInfos.contains(pet))
                {
                    PetFeedInfos p;
                    p.GID = message.objects[i]->objectGID;
                    p.UID = message.objects[i]->objectUID;
                    p.name = m_statsManager->pets[message.objects[i]->objectGID];
                    m_botData[sender].interactionData.petData.petInfos << p;
                }
            }

            if(m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base != m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base && m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base != 0)
                if(!m_statsManager->healEat(sender))
                    m_statsManager->healSit(sender);
        }

        else
            qDebug()<<"[GameInventoryItemsFrame] The character does not have any items in his inventory.";
    }
        break;

    case MessageEnum::INVENTORYWEIGHTMESSAGE:
    {
        InventoryWeightMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.pods.current = message.inventoryWeight;
        m_botData[sender].playerData.pods.max = message.weightMax;
        m_botData[sender].merchandData.shopWeight = message.shopWeight;
    }
        break;

    case MessageEnum::MIMICRYOBJECTERRORMESSAGE:
    {
        MimicryObjectErrorMessage message;
        message.deserialize(&reader);

        QString mimicryErrorText;

        if ((ObjectErrorEnum)message.reason == ObjectErrorEnum::SYMBIOTIC_OBJECT_ERROR)
        {
            switch (message.errorCode)
            {
            case -1:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.error.state");
                break;
            case -2:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.charSel.deletionErrorUnsecureMode");
                break;
            case -7:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.foodType");
                break;
            case -8:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.foodLevel");
                break;
            case -9:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noValidMimicry");
                break;
            case -10:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noValidHost");
                break;
            case -11:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noValidFood");
                break;
            case -16:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noMimicryAssociated");
                break;
            case -17:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.sameSkin");
                break;
            case -3:
            case -4:
            case -5:
            case -6:
            case -12:
            case -13:
            case -14:
            case -15:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.impossible_action");
                break;
            default:
                mimicryErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.common.unknownFail");
            }

            if (message.preview)
            {
                error(sender) << mimicryErrorText;
            }
            else
            {
                info(sender) << mimicryErrorText;
            }
        }
    }
        break;

    case MessageEnum::OBJECTADDEDMESSAGE:
    {
        ObjectAddedMessage message;
        message.deserialize(&reader);

        InventoryObject item;
        item.GID = message.object->objectGID;
        item.UID = message.object->objectUID;
        item.quantity = message.object->quantity;

        for (int i = 0; i < message.object->effects.size(); i++)
        {
            for (int j = 0; j < message.object->effects[i]->getTypes().size(); j++)
            {
                if ((int)message.object->effects[i]->getTypes()[j] == 70 && qSharedPointerCast<EffectData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::EFFECTS, message.object->effects[i]->actionId))->getCharacteristic() == 0)
                {
                    item.regenLife = qSharedPointerCast<ObjectEffectInteger>(message.object->effects[i])->value;
                }
            }
        }

        m_botData[sender].playerData.inventoryContent<<item;
        if (m_botData[sender].playerData.resourceMonitor.keys().contains(message.object->objectGID))
            m_botData[sender].playerData.resourceMonitor[message.object->objectGID] += message.object->quantity;

        if (m_botData[sender].farmData.resourcesToDelete.contains(item.GID))
        {
            ObjectDeleteMessage reply;
            reply.objectUID = item.UID;
            reply.quantity = item.quantity;
            sender->send(reply);
        }
    }
        break;

    case MessageEnum::OBJECTDELETEDMESSAGE:
    {
        ObjectDeletedMessage message;
        message.deserialize(&reader);

        int size = m_botData[sender].playerData.inventoryContent.size();

        for(int i = 0; i < size; i++)
        {
            if(m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent.removeAt(i);
                break;
            }
        }
    }
        break;

    case MessageEnum::OBJECTERRORMESSAGE:
    {
        ObjectErrorMessage message;
        message.deserialize(&reader);

        QString objectErrorText;
        switch((ObjectErrorEnum)message.reason)
        {
        case ObjectErrorEnum::SYMBIOTIC_OBJECT_ERROR:
            return false;
        case ObjectErrorEnum::INVENTORY_FULL:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.InventoryFull");
            break;
        case ObjectErrorEnum::CANNOT_EQUIP_TWICE:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.CannotEquipTwice");
            break;
        case ObjectErrorEnum::NOT_TRADABLE:
            return false;
        case ObjectErrorEnum::CANNOT_DROP:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.CannotDrop");
            break;
        case ObjectErrorEnum::CANNOT_DROP_NO_PLACE:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.CannotDropNoPlace");
            break;
        case ObjectErrorEnum::CANNOT_DESTROY:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.CannotDelete");
            break;
        case ObjectErrorEnum::LEVEL_TOO_LOW:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.levelTooLow");
            break;
        case ObjectErrorEnum::LIVING_OBJECT_REFUSED_FOOD:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.LivingObjectRefusedFood");
            break;
        case ObjectErrorEnum::CRITERIONS:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.criterions");
            break;
        case ObjectErrorEnum::CANNOT_EQUIP_HERE:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.cannotEquipHere");
            break;
        case ObjectErrorEnum::CANNOT_UNEQUIP:
            objectErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.objectError.cannotUnequip");
            break;
        }

        if(!objectErrorText.isEmpty())
            error(sender) << objectErrorText;
        else
            qDebug() << "No text has been found to display for ObjectErrorMessage with reason " << message.reason;
    }
        break;

    case MessageEnum::OBJECTMOVEMENTMESSAGE:
    {
        ObjectMovementMessage message;
        message.deserialize(&reader);

        for (int i = 0; i < m_botData[sender].playerData.inventoryContent.size(); i++)
        {
            if (m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent[i].position = (CharacterInventoryPositionEnum)message.position;

                if (m_statsManager->inventoryPositions.contains((CharacterInventoryPositionEnum)message.position))
                    m_botData[sender].playerData.inventoryContent[i].isEquipped = true;
                else
                    m_botData[sender].playerData.inventoryContent[i].isEquipped = false;

                qDebug() << "[GameInventoryItemsFrame] Equip test:" << m_botData[sender].playerData.inventoryContent[i].isEquipped << message.position << m_statsManager->inventoryPositions.contains((CharacterInventoryPositionEnum)message.position);
            }
        }
    }
        break;

    case MessageEnum::OBJECTQUANTITYMESSAGE:
    {
        ObjectQuantityMessage message;
        message.deserialize(&reader);

        int size = m_botData[sender].playerData.inventoryContent.size();
        for (int i = 0; i < size; i++)
        {
            if (m_botData[sender].playerData.inventoryContent[i].UID == message.objectUID)
            {
                m_botData[sender].playerData.inventoryContent[i].quantity = message.quantity;
                if (m_botData[sender].farmData.resourcesToDelete.contains(m_botData[sender].playerData.inventoryContent[i].GID))
                {
                    ObjectDeleteMessage reply;
                    reply.objectUID = m_botData[sender].playerData.inventoryContent[i].UID;
                    reply.quantity = m_botData[sender].playerData.inventoryContent[i].quantity;
                    sender->send(reply);
                }

                break;
            }
        }
    }
        break;

    case MessageEnum::OBTAINEDITEMMESSAGE:
    {
        ObtainedItemMessage message;
        message.deserialize(&reader);

        m_botData[sender].statisticsData.countTotalResourcesGather += message.baseQuantity;
    }
        break;

    case MessageEnum::WRAPPEROBJECTERRORMESSAGE:
    {
        WrapperObjectErrorMessage message;
        message.deserialize(&reader);

        if((ObjectErrorEnum)message.reason == ObjectErrorEnum::SYMBIOTIC_OBJECT_ERROR)
        {
            QString wrapperErrorText;

            switch(message.errorCode)
            {
            case -1:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.error.state");
                break;
            case -2:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.charSel.deletionErrorUnsecureMode");
                break;
            case -7:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.foodType");
                break;
            case -8:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.invalidWrapperObject");
                break;
            case -10:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noValidHost");
                break;
            case -16:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noWrapperAssociated");
                break;
            case -18:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.noAssociationWithLivingObject");
                break;
            case -19:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.alreadyWrapped");
                break;
            case -20:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.mimicry.error.invalidCriterion");
                break;
            case -3:
            case -4:
            case -6:
            case -12:
            case -14:
            case -15:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.popup.impossible_action");
                break;
            default:
                wrapperErrorText = D2OManagerSingleton::get()->getI18N()->getText("ui.common.unknownFail");
            }

            error(sender) << wrapperErrorText;
        }
    }
        break;
    }

    return messageFound;
}
