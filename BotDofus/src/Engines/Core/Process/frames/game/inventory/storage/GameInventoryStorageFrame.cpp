#include "GameInventoryStorageFrame.h"

GameInventoryStorageFrame::GameInventoryStorageFrame(QMap<SocketIO *, BotData> *connectionsData, InteractionManager *interactionManager):
    AbstractFrame(connectionsData),
    m_interactionManager(interactionManager)
{

}

bool GameInventoryStorageFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::STORAGEINVENTORYCONTENTMESSAGE:
    {
        StorageInventoryContentMessage message;
        message.deserialize(&reader);

        if ((m_botData[sender].interactionData.interactionType == CurrentInteraction::BANK)
                && m_botData[sender].generalData.botState == BotState::BANKING_STATE
                && (m_botData[sender].interactionData.interactionId != INVALID))
        {
            QList<QSharedPointer<ObjectItem>> toTake;
            QMap<int, int> toTakeQuantity;
            QList<InventoryObject> toDeposit;
            QMap<int, int> toDepositQuantity;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].generalData.botState = BotState::BANKING_STATE;

            //Process deposit items
            foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
                if (m_interactionManager->concernedByBankDeposit(sender, o.GID))
                    toDeposit << o;

            for (int i = 0; i < toDeposit.size(); i++)
                for (int j = 0; j < m_botData[sender].interactionData.bankData.deposit.size(); j++)
                    if (toDeposit[i].GID == m_botData[sender].interactionData.bankData.deposit[j].itemId)
                        toDepositQuantity[toDeposit[i].UID] = qCeil(toDeposit[i].quantity * (float)(m_botData[sender].interactionData.bankData.deposit[j].pods / 100.0));

            //Process take items
            foreach (QSharedPointer<ObjectItem> o, message.objects)
                if (m_interactionManager->concernedByBankTake(sender, o->objectGID))
                    toTake << o;

            int freePods = m_botData[sender].playerData.stats.pods.max - m_botData[sender].playerData.stats.pods.current;
            for (int i = 0; i < toTake.size(); i++)
            {
                for (int j = 0; j < m_botData[sender].interactionData.bankData.take.size(); j++)
                {
                    if (toTake[i]->objectGID == m_botData[sender].interactionData.bankData.take[j].itemId)
                    {
                        int quantity = std::fmin(toTake[i]->quantity, qCeil(freePods * (m_botData[sender].interactionData.bankData.take[j].pods /100)));
                        toTakeQuantity[toTake[i]->objectUID] = quantity;
                        freePods -= quantity;
                    }
                }
            }

            m_botData[sender].interactionData.bankData.toDepositQuantity = toDepositQuantity;
            m_botData[sender].interactionData.bankData.toTakeQuantity = toTakeQuantity;

            if (m_botData[sender].interactionData.bankData.toDepositQuantity.size())
            {
                ExchangeObjectMoveMessage depositMessage;
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey();
                depositMessage.quantity = m_botData[sender].interactionData.bankData.toDepositQuantity.first();
                sender->send(depositMessage);

                info(sender) << "Depot en banque de" << m_botData[sender].interactionData.bankData.toDepositQuantity.first() << m_interactionManager->nameFromUid(sender, m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.remove(depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
            }

            else if (m_botData[sender].interactionData.bankData.toTakeQuantity.size())
            {
                ExchangeObjectMoveMessage takeMessage;
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey();
                takeMessage.quantity = m_botData[sender].interactionData.bankData.toTakeQuantity.first();
                sender->send(takeMessage);

                info(sender) << "Prise en banque de" << m_botData[sender].interactionData.bankData.toTakeQuantity.first() << m_interactionManager->nameFromUid(sender, m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.remove(m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
            }

            else
            {
                LeaveDialogRequestMessage reply;
                sender->send(reply);
            }
        }
    }
        break;

    case MessageEnum::STORAGEOBJECTUPDATEMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::BANKING_STATE)
        {
            if (m_botData[sender].interactionData.bankData.toDepositQuantity.size())
            {
                ExchangeObjectMoveMessage depositMessage;
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey();
                depositMessage.quantity = m_botData[sender].interactionData.bankData.toDepositQuantity.first();
                sender->send(depositMessage);

                info(sender) << "Depot en banque de" << m_botData[sender].interactionData.bankData.toDepositQuantity.first() << m_interactionManager->nameFromUid(sender, m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
                depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.remove(depositMessage.objectUID = m_botData[sender].interactionData.bankData.toDepositQuantity.firstKey());
            }

            else if (m_botData[sender].interactionData.bankData.toTakeQuantity.size())
            {
                ExchangeObjectMoveMessage takeMessage;
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey();
                takeMessage.quantity = m_botData[sender].interactionData.bankData.toTakeQuantity.first();
                sender->send(takeMessage);

                info(sender) << "Prise en banque de" << m_botData[sender].interactionData.bankData.toTakeQuantity.first() << m_interactionManager->nameFromUid(sender, m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
                takeMessage.objectUID = m_botData[sender].interactionData.bankData.toTakeQuantity.remove(m_botData[sender].interactionData.bankData.toTakeQuantity.firstKey());
            }

            else
            {
                LeaveDialogRequestMessage reply;
                sender->send(reply);
            }
        }

        else
        {
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.finishedAction = true;
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
        }
    }
        break;
    }

    return messageFound;
}
