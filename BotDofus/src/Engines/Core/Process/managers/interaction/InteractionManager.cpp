#include "InteractionManager.h"

InteractionManager::InteractionManager(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager):
    AbstractManager(ManagerType::INTERACTION, connectionsData),
    m_mapManager(mapManager)
{

}

void InteractionManager::reset(SocketIO *sender)
{
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
}

bool InteractionManager::processZaap(SocketIO *sender, int mapId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE) || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId != INVALID || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    bool found = false;
    InteractiveElementInfos element;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaap")
        {
            found = true;
            element = e;
        }
    }

    if (!found)
        return false;

    m_botData[sender].interactionData.interactionId = mapId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ZAAP;
    connect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapManager->changeCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(element.elementId));
}

bool InteractionManager::processZaapi(SocketIO *sender, int mapId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE) || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId != INVALID || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    bool found = false;
    InteractiveElementInfos element;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaapi")
        {
            found = true;
            element = e;
        }
    }

    if (!found)
        return false;

    m_botData[sender].interactionData.interactionId = mapId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ZAAPI;
    connect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapManager->changeCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(element.elementId));
}

bool InteractionManager::processNpcInteraction(SocketIO *sender, int cellId)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE) || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId != INVALID || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    NpcInfos npc;
    bool found = false;
    foreach (NpcInfos pnj, m_botData[sender].mapData.npcsOnMap.values())
    {
        if (pnj.cellId == cellId)
        {
            npc = pnj;
            found = true;
        }
    }

    if (!found)
    {
        error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(npc.npcId) + ")";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        return false;
    }

    QMap<int, QString> actions;
    m_botData[sender].interactionData.interactionId = npc.npcId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NPC;
    foreach (int j, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCACTIONS))
    {
        QSharedPointer<NpcActionData> npcAction = qSharedPointerCast<NpcActionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCACTIONS, j));
        actions[npcAction->getId()] = npcAction->getName();
    }

    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
    {
        QSharedPointer<NpcData> npcData = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));
        if (npcData->getId() == npc.npcId)
        {
            for (int k = 0; k < npcData->getActions().size(); k++)
            {
                if (actions[npcData->getActions()[k]] == "Parler")
                {
                    NpcGenericActionRequestMessage message;
                    message.npcMapId = m_botData[sender].mapData.map.getMapId();
                    message.npcActionId = npcData->getActions()[k];
                    message.npcId = npc.contextualId;

                    finishedAction << sender;
                    QTimer::singleShot(15000, this, SLOT(finishAction()));
                    m_botData[sender].interactionData.finishedAction = false;

                    sender->send(message);
                    return true;
                }
            }
        }
    }

    error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(npc.npcId) + ")";
    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    return false;
}

bool InteractionManager::processUse(SocketIO *sender, int id)
{
    if ((m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE) || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId != INVALID || !m_botData[sender].interactionData.npcDialogs.isEmpty())
        return false;

    int skill = INVALID;
    InteractiveElementInfos elem;
    foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
    {
        if (e.elementId == id)
        {
            elem = e;
            break;
        }
    }

    if (elem.enabledSkills.size())
        skill = elem.enabledSkills.first().ID;

    if (skill == INVALID)
        return false;

    m_botData[sender].interactionData.actionID = skill;
    m_botData[sender].interactionData.interactionId = elem.elementId;
    m_botData[sender].interactionData.interactionType = CurrentInteraction::ITEM;
    connect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    connect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));
    m_mapManager->changeToNearestCell(sender, m_botData[sender].mapData.map.getInteractiveElementCellID(elem.elementId));

    return true;
}

bool InteractionManager::processNpcDialog(SocketIO *sender, QString dialog)
{
    if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId == INVALID || m_botData[sender].interactionData.npcDialogs.isEmpty())
    {
        error(sender) << "InteractionManager - Le bot n'a pas pu dialoguer avec le PNJ (id:" + QString::number(m_botData[sender].interactionData.interactionId) + ")";
        return false;
    }

    int replyID = INVALID;
    QMap<int, QPoint> replies;
    foreach (int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::NPCS))
    {
        QSharedPointer<NpcData> npc = qSharedPointerCast<NpcData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::NPCS, index));
        if (npc->getId() == m_botData[sender].interactionData.interactionId)
        {
            for (int i = 0; i < npc->getDialogReplies().size(); i++)
                for (int j = 0; j < npc->getDialogReplies()[i].size(); j++)
                    for (int k = 0; k < m_botData[sender].interactionData.npcDialogs.size(); k++)
                        if (m_botData[sender].interactionData.npcDialogs[k] == npc->getDialogReplies()[i][j])
                            replies[m_botData[sender].interactionData.npcDialogs[k]] = QPoint(i, j);

            foreach (int id, replies.keys())
            {
                if (D2OManagerSingleton::get()->getI18N()->getText((npc->getDialogReplies().at(replies[id].x()).at(replies[id].y()+1))).indexOf(dialog, 0, Qt::CaseInsensitive) >= 0)
                {
                    replyID = id;
                    break;
                }
            }
        }
    }

    if (replyID == INVALID)
    {
        error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec le PNJ (id:" + QString::number(m_botData[sender].interactionData.interactionId) + ") car le dialogue n'existe pas.";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        return false;
    }

    NpcDialogReplyMessage msg;
    msg.replyId = replyID;

    finishedAction << sender;
    QTimer::singleShot(15000, this, SLOT(finishAction()));
    m_botData[sender].interactionData.finishedAction = false;

    sender->send(msg);
    return true;
}

bool InteractionManager::leaveNpcDialog(SocketIO *sender)
{
    m_botData[sender].interactionData.interactionId = INVALID;
    if (m_botData[sender].interactionData.interactionType != CurrentInteraction::NONE)
    {
        LeaveDialogRequestMessage message;
        sender->send(message);
        return true;
    }

    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    return false;
}

void InteractionManager::moved(SocketIO *sender)
{
    disconnect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    disconnect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));

    if (m_botData[sender].interactionData.interactionType == CurrentInteraction::NONE || m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].interactionData.interactionId == INVALID)
    {
        error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (npc, zaap(i), item).";
        m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
        m_botData[sender].interactionData.interactionId = INVALID;
        m_botData[sender].interactionData.finishedAction = true;
        m_botData[sender].interactionData.actionID = INVALID;
        m_botData[sender].interactionData.npcDialogs.clear();
        emit scriptActionDone(sender);
    }

    else if (m_botData[sender].interactionData.interactionType == CurrentInteraction::ZAAP || m_botData[sender].interactionData.interactionType == CurrentInteraction::ZAAPI)
    {
        int id = INVALID;
        int skill = INVALID;
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
        {
            if (qSharedPointerCast<InteractiveData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::INTERACTIVES, e.elementTypeId))->getName() == "Zaap")
            {
                id = e.elementId;
                skill = e.enabledSkills.first().UID;
            }
        }

        if ((skill == INVALID) || (id == INVALID))
        {
            error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément spécifié (zaap(i) ou élément interactif).";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
            return;
        }

        InteractiveUseRequestMessage message;
        message.skillInstanceUid = skill;
        message.elemId = id;

        finishedAction << sender;
        QTimer::singleShot(15000, this, SLOT(finishAction()));
        m_botData[sender].interactionData.finishedAction = false;

        sender->send(message);
    }

    else if (m_botData[sender].interactionData.interactionType == CurrentInteraction::ITEM)
    {
        int skill = INVALID;
        foreach (InteractiveElementInfos e, m_botData[sender].mapData.interactivesOnMap)
            foreach (InteractiveSkillInfos s, e.enabledSkills)
                if (s.ID == m_botData[sender].interactionData.actionID)
                    skill = s.UID;

        if (skill == INVALID)
        {
            error(sender) << "Interaction Module - Le bot n'a pas pu interagir avec l'élément interactif (id:" << m_botData[sender].interactionData.interactionId << ").";
            m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
            m_botData[sender].interactionData.interactionId = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            m_botData[sender].interactionData.actionID = INVALID;
            m_botData[sender].interactionData.npcDialogs.clear();
            emit scriptActionDone(sender);
        }

        InteractiveUseRequestMessage message;
        message.skillInstanceUid = skill;
        message.elemId = m_botData[sender].interactionData.interactionId;

        finishedAction << sender;
        QTimer::singleShot(15000, this, SLOT(finishAction()));
        m_botData[sender].interactionData.finishedAction = false;

        sender->send(message);
    }
}

void InteractionManager::noMovement(SocketIO *sender)
{
    disconnect(m_mapManager, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moved(SocketIO*)));
    disconnect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(noMovement(SocketIO*)));

    m_botData[sender].interactionData.interactionType = CurrentInteraction::NONE;
    m_botData[sender].interactionData.interactionId = INVALID;
    m_botData[sender].interactionData.finishedAction = true;
    m_botData[sender].interactionData.actionID = INVALID;
    m_botData[sender].interactionData.npcDialogs.clear();
    emit scriptActionDone(sender);
}

void InteractionManager::finishAction()
{
    if (m_botData[finishedAction.first()].interactionData.interactionType == CurrentInteraction::NPC)
    {
        LeaveDialogRequestMessage message;
        finishedAction.first()->send(message);

        m_botData[finishedAction.first()].interactionData.finishedAction = true;
        finishedAction.removeFirst();
        return;
    }

    if (!m_botData[finishedAction.first()].interactionData.finishedAction)
        emit scriptActionDone(finishedAction.first());

    m_botData[finishedAction.first()].interactionData.finishedAction = true;
    finishedAction.removeFirst();
}

void InteractionManager::confirmAction()
{
    emit scriptActionDone(m_confirmAction.first());
    m_confirmAction.removeFirst();
}

void InteractionManager::clearBankData(SocketIO *sender)
{
    m_botData[sender].interactionData.bankData.deposit.clear();
    m_botData[sender].interactionData.bankData.take.clear();
}

BankData InteractionManager::getBankData(SocketIO *sender)
{
    return m_botData[sender].interactionData.bankData;
}

void InteractionManager::addDepositBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.deposit.append(item);
}

void InteractionManager::addTakeBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.take.append(item);
}

void InteractionManager::removeDepositBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.deposit.removeOne(item);
}

void InteractionManager::removeTakeBankItem(SocketIO *sender, BankItem item)
{
    m_botData[sender].interactionData.bankData.take.removeOne(item);
}

void InteractionManager::updateTakeBankItem(SocketIO *sender, uint itemId, uint pods)
{
    for (int i = 0; i < m_botData[sender].interactionData.bankData.take.size(); i++)
        if (m_botData[sender].interactionData.bankData.take[i].itemId == itemId)
            m_botData[sender].interactionData.bankData.take[i].pods = pods;
}

void InteractionManager::updateDepositBankItem(SocketIO *sender, uint itemId, uint pods)
{
    for (int i = 0; i < m_botData[sender].interactionData.bankData.deposit.size(); i++)
        if (m_botData[sender].interactionData.bankData.deposit[i].itemId == itemId)
            m_botData[sender].interactionData.bankData.deposit[i].pods = pods;
}

void InteractionManager::setTakeCondition(SocketIO *sender, BankInclusion condition)
{
    m_botData[sender].interactionData.bankData.takeCondition = condition;
}

void InteractionManager::setDepositCondition(SocketIO *sender, BankInclusion condition)
{
    m_botData[sender].interactionData.bankData.depositCondition = condition;
}

void InteractionManager::toggleFeed(SocketIO *sender, bool toggle)
{
    m_botData[sender].interactionData.petData.toggleFeed = toggle;
    if (!toggle)
    {
        for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
            m_botData[sender].interactionData.petData.petInfos[i].timer->stop();

        return;
    }

    foreach (PetFeedInfos pet, m_botData[sender].interactionData.petData.petInfos)
    {
        if (pet.foodId != INVALID && pet.waitingTime != INVALID)
        {
            if (pet.timer != NULL)
                pet.timer->stop();

            else if (pet.timer == NULL)
            {
                pet.timer = QSharedPointer<QTimer>(new QTimer(this));
                QObject::connect(pet.timer.data(), SIGNAL(timeout()), this, SLOT(feed()));
            }

            pet.timer->setSingleShot(true);
            pet.timer->setInterval(pet.waitingTime*3600000);
            pet.timer->start();
        }
    }
}

void InteractionManager::setPetFood(SocketIO *sender, uint id, int food)
{
    for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        if (m_botData[sender].interactionData.petData.petInfos[i].GID == id)
            m_botData[sender].interactionData.petData.petInfos[i].foodId = food;
}

void InteractionManager::setFeedTimer(SocketIO *sender, uint id, int timer)
{
    for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        if (m_botData[sender].interactionData.petData.petInfos[i].GID == id)
            m_botData[sender].interactionData.petData.petInfos[i].waitingTime = timer;
}

void InteractionManager::feed()
{
    QTimer *t = static_cast<QTimer*>(QObject::sender());
    foreach (SocketIO *sender, m_botData.keys())
    {
        foreach (PetFeedInfos pet, m_botData[sender].interactionData.petData.petInfos)
        {
            if (pet.timer == t)
            {
                int foodUid = getFoodUID(sender, pet.UID, pet.foodId);
                if (pet.toRemove || (pet.foodId == INVALID) || m_botData[sender].interactionData.petData.toggleFeed || (foodUid == INVALID))
                    return;

                ObjectFeedMessage message;
                message.meal[0].objectUID = foodUid;
                message.meal[0].quantity = 1;
                message.objectUID = pet.UID;

                pet.timer->setSingleShot(true);
                pet.timer->setInterval(pet.waitingTime*3600000);
                pet.timer->start();
            }
        }
    }
}

QString InteractionManager::nameFromUid(SocketIO *sender, int uid)
{
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            return D2OManagerSingleton::get()->getItem(o.GID)->getName();

    return "";
}

bool InteractionManager::concernedByBankTake(SocketIO *sender, int id)
{
    QList<int> itemsId;
    foreach (BankItem b, m_botData[sender].interactionData.bankData.take)
        itemsId << b.itemId;

    if (m_botData[sender].interactionData.bankData.takeCondition == BankInclusion::NONE_EXCEPT)
        if (itemsId.contains(id))
            return true;
    else if (m_botData[sender].interactionData.bankData.takeCondition == BankInclusion::ALL_EXCEPT)
        if (!itemsId.contains(id))
            return true;

    return false;
}

bool InteractionManager::concernedByBankDeposit(SocketIO *sender, int id)
{
    QList<int> itemsId;
    foreach (BankItem b, m_botData[sender].interactionData.bankData.deposit)
        itemsId << b.itemId;

    if (m_botData[sender].interactionData.bankData.depositCondition == BankInclusion::NONE_EXCEPT)
        if (itemsId.contains(id))
            return true;
    else if (m_botData[sender].interactionData.bankData.depositCondition == BankInclusion::ALL_EXCEPT)
        if (!itemsId.contains(id))
            return true;

    return false;
}

int InteractionManager::getFoodUID(SocketIO *sender, int uid, int food)
{
    int foodUid = INVALID;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.GID = food)
            foodUid = o.GID;

    if (foodUid == INVALID)
    {
        for (int i = 0; i < m_botData[sender].interactionData.petData.petInfos.size(); i++)
        {
            if (m_botData[sender].interactionData.petData.petInfos[i].UID = uid)
            {
                m_botData[sender].interactionData.petData.petInfos[i].foodId = INVALID;
                m_botData[sender].interactionData.petData.petInfos[i].toRemove = true;
                return INVALID;
            }
        }
    }

    else
        return foodUid;
}
