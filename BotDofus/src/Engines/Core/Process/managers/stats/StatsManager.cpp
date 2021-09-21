#include "StatsManager.h"

StatsManager::StatsManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::STATS, connectionsData)
{
    inventoryPositions << CharacterInventoryPositionEnum::ACCESSORY_POSITION_HAT << CharacterInventoryPositionEnum::ACCESSORY_POSITION_BELT <<
                            CharacterInventoryPositionEnum::ACCESSORY_POSITION_AMULET << CharacterInventoryPositionEnum::ACCESSORY_POSITION_BOOTS <<
                            CharacterInventoryPositionEnum::ACCESSORY_POSITION_PETS << CharacterInventoryPositionEnum::ACCESSORY_POSITION_SHIELD <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_ENTITY << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_1 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_2 << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_3 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_4 <<CharacterInventoryPositionEnum::ACCESSORY_POSITION_CAPE <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_5 << CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_6 <<
                            CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_LEFT << CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_RIGHT <<
                          CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON;
}

void StatsManager::reset(SocketIO *sender)
{
    m_botData[sender].playerData.isRequestingFreeSoul = false;
    m_botData[sender].playerData.hasSentRequestFreeSoul = false;
    m_botData[sender].generalData.botState = INVALID_STATE;
}

void StatsManager::increaseStat(SocketIO *sender, PlayerD2OFields stat)
{
    action(sender)<<"Augmentation des caractéristiques...";

    StatsUpgradeRequestMessage message;
    message.useAdditionnal = false;
    message.statId = (uint)stat;

    switch(stat)
    {
    case PlayerD2OFields::AGILITY:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredAgility;
        m_botData[sender].statisticsData.countTotalPointAgility += m_botData[sender].playerData.statsRequiredAgility;
    }
        break;

    case PlayerD2OFields::STRENGTH:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredStrength;
        m_botData[sender].statisticsData.countTotalPointStrength += m_botData[sender].playerData.statsRequiredStrength;
    }
        break;

    case PlayerD2OFields::INTELLIGENCE:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredIntelligence;
        m_botData[sender].statisticsData.countTotalPointIntelligence += m_botData[sender].playerData.statsRequiredIntelligence;
    }
        break;

    case PlayerD2OFields::CHANCE:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredChance;
        m_botData[sender].statisticsData.countTotalPointChance += m_botData[sender].playerData.statsRequiredChance;
    }
        break;

    case PlayerD2OFields::WISDOM:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredWisdom;
        m_botData[sender].statisticsData.countTotalPointWisdom += m_botData[sender].playerData.statsRequiredWisdom;
    }
        break;

    case PlayerD2OFields::VITALITY:
    {
        message.boostPoint = m_botData[sender].playerData.statsRequiredVitality;
        m_botData[sender].statisticsData.countTotalPointVitality += m_botData[sender].playerData.statsRequiredVitality;
    }
        break;
    }

    m_botData[sender].playerData.increaseStatId = (uint)stat;
    sender->send(message);
}

void StatsManager::resetStat(SocketIO *sender)
{
    if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED && m_botData[sender].generalData.botState != FIGHTING_STATE)
    {
        m_botData[sender].statisticsData.countTotalPointVitality = 0;
        m_botData[sender].statisticsData.countTotalPointWisdom = 0;
        m_botData[sender].statisticsData.countTotalPointStrength = 0;
        m_botData[sender].statisticsData.countTotalPointIntelligence = 0;
        m_botData[sender].statisticsData.countTotalPointChance = 0;
        m_botData[sender].statisticsData.countTotalPointAgility = 0;

        ResetCharacterStatsRequestMessage rcsrmsg;
        sender->send(rcsrmsg);
    }
}

void StatsManager::updateRequiredStats(SocketIO *sender)
{
    QSharedPointer<BreedData> breed = qSharedPointerCast<BreedData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::BREEDS, (int)m_botData[sender].playerData.breed));

    for(int i = 0; i < breed->getStatsPointsForVitality().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::VITALITY].base < breed->getStatsPointsForVitality()[i][0])
        {
            m_botData[sender].playerData.statsRequiredVitality = breed->getStatsPointsForVitality()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredVitality = breed->getStatsPointsForVitality()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForWisdom().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::WISDOM].base < breed->getStatsPointsForWisdom()[i][0])
        {
            m_botData[sender].playerData.statsRequiredWisdom = breed->getStatsPointsForWisdom()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredWisdom = breed->getStatsPointsForWisdom()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForStrength().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::STRENGTH].base < breed->getStatsPointsForStrength()[i][0])
        {
            m_botData[sender].playerData.statsRequiredStrength = breed->getStatsPointsForStrength()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredStrength = breed->getStatsPointsForStrength()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForIntelligence().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::INTELLIGENCE].base < breed->getStatsPointsForIntelligence()[i][0])
        {
            m_botData[sender].playerData.statsRequiredIntelligence = breed->getStatsPointsForIntelligence()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredIntelligence = breed->getStatsPointsForIntelligence()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForChance().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::CHANCE].base < breed->getStatsPointsForChance()[i][0])
        {
            m_botData[sender].playerData.statsRequiredChance = breed->getStatsPointsForChance()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredChance = breed->getStatsPointsForChance()[i][1];
    }

    for(int i = 0; i < breed->getStatsPointsForAgility().size(); i++)
    {
        if(m_botData[sender].playerData.stats[(int)StatIds::AGILITY].base < breed->getStatsPointsForAgility()[i][0])
        {
            m_botData[sender].playerData.statsRequiredAgility = breed->getStatsPointsForAgility()[i - 1][1];
            break;
        }

        else
            m_botData[sender].playerData.statsRequiredAgility = breed->getStatsPointsForAgility()[i][1];
    }
}

void StatsManager::throwItem(SocketIO *sender, uint uid, uint quantity)
{
    ObjectDropMessage message;
    foreach (InventoryObject item, m_botData[sender].playerData.inventoryContent)
    {
        if (item.UID == uid)
        {
            message.objectUID = item.UID;
            message.quantity = std::min(quantity, (uint)item.quantity);
            action(sender) << "Vous venez de jeter <b>" << D2OManagerSingleton::get()->getItem(item.GID)->getName() << "</b> (x" << message.quantity << ")";
            sender->send(message);
            break;
        }
    }
}

void StatsManager::destroyItem(SocketIO *sender, uint uid, uint quantity)
{
    ObjectDeleteMessage message;
    foreach (InventoryObject item, m_botData[sender].playerData.inventoryContent)
    {
        if (item.UID == uid)
        {
            message.objectUID = item.UID;
            message.quantity = std::min(quantity, (uint)item.quantity);
            sender->send(message);
            break;
        }
    }
}

void StatsManager::useItem(SocketIO *sender, uint uid)
{
    ObjectUseMessage message;
    message.objectUID = uid;
    sender->send(message);

    qDebug() << "USE ITEM" << uid;
}

void StatsManager::freeSoul(SocketIO *sender)
{
    if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_TOMBSTONE)
    {
        m_botData[sender].playerData.isRequestingFreeSoul = true;
        m_botData[sender].playerData.hasSentRequestFreeSoul = false;

        if(m_botData[sender].mapData.map.isInit() && m_botData[sender].generalData.botState == INACTIVE_STATE && !m_botData[sender].playerData.hasSentRequestFreeSoul)
        {
            m_botData[sender].playerData.hasSentRequestFreeSoul = true;

            GameRolePlayFreeSoulRequestMessage request;
            sender->send(request);
        }
    }
}

QString StatsManager::getMountEffects(SocketIO *sender)
{
    QString t;
    for (int i = 0; i < m_botData[sender].playerData.mountData.effects.size(); i++)
        t.append(m_botData[sender].playerData.mountData.effects.at(i) + QString('\n'));

    t.remove(t.size() - 1);
    return t;
}

void StatsManager::updateMountXpRatio(SocketIO *sender, uint ratio)
{
    MountSetXpRatioRequestMessage message;
    message.xpRatio = ratio;

    sender->send(message);
}

bool StatsManager::healSit(SocketIO* sender)
{
    if (m_botData[sender].generalData.botState != BotState::INACTIVE_STATE && m_botData[sender].generalData.botState != BotState::REGENERATING_STATE)
        return false;

    action(sender) << "Début de la régénération assise...";
    EmotePlayRequestMessage message;
    message.emoteId = 1;
    sender->send(message);

    m_botData[sender].generalData.botState = BotState::REGENERATING_STATE;
    return true;
}

bool StatsManager::healEat(SocketIO* sender)
{
    if (m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    QList<InventoryObject> regenItems;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.regenLife && qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, o.GID))->getUsable() && qSharedPointerCast<ItemData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, o.GID))->getTargetable())
            regenItems << o;

    if (regenItems.isEmpty())
    {
        warn(sender) << "Vous n'avez plus d'objets consommables pour vous régénérer";
        healSit(sender);
        return false;
    }

    std::sort(regenItems.begin(), regenItems.end());
    std::reverse(regenItems.begin(), regenItems.end());
    m_botData[sender].playerData.healInventory.clear();
    m_botData[sender].playerData.healInventory = regenItems;

    return true;
}

bool StatsManager::needsHeal(SocketIO *sender)
{
    float ratio = (((float)m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base-0)/((float)m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base-0))*100;

    if(ratio <= m_botData[sender].playerData.minRegenRatio)
        return true;

    return false;
}

bool StatsManager::needsToGoToPhoenix(SocketIO *sender)
{
    if(m_botData[sender].playerData.lifeStatus == PlayerLifeStatusEnum::STATUS_ALIVE_AND_KICKING)
        return false;

    return true;
}

bool StatsManager::needsToGoToBank(SocketIO *sender)
{
    float ratio = (float)m_botData[sender].playerData.pods.current/(float)m_botData[sender].playerData.pods.max*100;

    if(ratio >= m_botData[sender].scriptData.podsLimitRatio)
        return true;

    return false;
}

void StatsManager::setRegenerationRatio(SocketIO *sender, uint min, uint max)
{
    m_botData[sender].playerData.minRegenRatio = min;
    m_botData[sender].playerData.maxRegenRatio = max;
}

void StatsManager::setPlayerStatusUpdate(SocketIO *sender, PlayerStatusEnum statusId, QString message)
{
    PlayerStatusUpdateRequestMessage psurmsg;

    if(message.isEmpty())
    {
        QSharedPointer<PlayerStatus> statusTest = QSharedPointer<PlayerStatus>(new PlayerStatus);
        statusTest->statusId = (int)statusId;
        psurmsg.status = statusTest;
    }
    else
    {
        QSharedPointer<PlayerStatusExtended> statusTest = QSharedPointer<PlayerStatusExtended>(new PlayerStatusExtended);
        statusTest->statusId = (int)statusId;
        statusTest->message = message;
        psurmsg.status = statusTest;
    }

    sender->send(psurmsg);
}

void StatsManager::setAutomaticallyAcceptAchievement(SocketIO *sender, bool active)
{
    m_botData[sender].playerData.automaticallyAcceptAchievement = active;
}

void StatsManager::defineSkinHead(SocketIO *sender, QPixmap pixmap)
{
    m_botData[sender].playerData.headPixmap = pixmap;
}

void StatsManager::quitDidactiel(SocketIO *sender)
{
    if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED && m_botData[sender].generalData.botState == BotState::INACTIVE_STATE)
    {
        GuidedModeQuitRequestMessage gmqrmsg;
        sender->send(gmqrmsg);
    }
}

int StatsManager::getHealthPoints(SocketIO *sender)
{
    return getMaxHealthPoints(sender) + m_botData[sender].playerData.stats[(uint)StatIds::CUR_LIFE].base + m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base;
}

int StatsManager::getMaxHealthPoints(SocketIO *sender)
{
    return m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base + m_botData[sender].playerData.stats[(uint)StatIds::VITALITY].base - m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base;
}

void StatsManager::setRegenUseObjectsEnabled(SocketIO *sender, bool enabled)
{
    m_botData[sender].playerData.regenUseObjects = enabled;
}

void StatsManager::regenOptimizer(SocketIO *sender)
{
    int life = m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base;
    int maxLife = m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base;
    double p = (double)m_botData[sender].playerData.healPercentage/100.0;

    int wanted = p*maxLife;
    int diff = maxLife - life;

    QMutableListIterator<LifeRegenQueue> i(m_preventRegenBlocked);
    while (i.hasNext())
        if (i.next().sender == sender)
            i.remove();

    if (life >= wanted || !(m_botData[sender].generalData.botState == BotState::INACTIVE_STATE || m_botData[sender].generalData.botState == BotState::REGENERATING_STATE))
    {
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].playerData.healInventory.clear();

        emit healed(sender);

        if(m_botData[sender].scriptData.activeModule == ManagerType::STATS)
            emit scriptActionDone(sender);

        return;
    }

    if (m_botData[sender].playerData.healInventory.isEmpty())
    {
        warn(sender) << "Vous n'avez plus d'objets consommables pour vous régénérer";
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].playerData.healInventory.clear();
        healSit(sender);
        return;
    }

    bool hasEaten = false;
    m_botData[sender].generalData.botState = BotState::REGENERATING_STATE;
    for (int i = 0; i < m_botData[sender].playerData.healInventory.size(); i++)
    {
        if (diff >= m_botData[sender].playerData.healInventory[i].regenLife)
        {
            hasEaten = true;
            ObjectUseMessage message;
            message.objectUID = m_botData[sender].playerData.healInventory[i].UID;

            m_botData[sender].playerData.healInventory[i].quantity -= 1;
            if (m_botData[sender].playerData.healInventory[i].quantity <= 0)
                m_botData[sender].playerData.healInventory.removeAt(i);

            break;
        }
    }

    if (!hasEaten && (diff > 50))
    {
        ObjectUseMessage message;
        message.objectUID = m_botData[sender].playerData.healInventory.last().UID;

        m_botData[sender].playerData.healInventory.last().quantity -= 1;
        if (m_botData[sender].playerData.healInventory.last().quantity <= 0)
            m_botData[sender].playerData.healInventory.removeLast();
    }
    else if (!hasEaten && (diff <= 50))
    {
        healSit(sender);
        return;
    }

    LifeRegenQueue queue;
    queue.time.start();
    queue.sender = sender;
    queue.interval = 30000;

    m_preventRegenBlocked << queue;
    QTimer::singleShot(30000, this, SLOT(preventRegenBlocked()));
}

void StatsManager::healFinished()
{
    int index;
    int min = 1000000;
    SocketIO* sender = NULL;
    for (int i = 0; i < regenQueue.size(); i++)
    {
        if ((regenQueue[i].time.elapsed() - regenQueue[i].interval) < min)
        {
            min = regenQueue[i].time.elapsed() - regenQueue[i].interval;
            sender = regenQueue[i].sender;
            index = i;
        }
    }

    if (!sender)
        return;

    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].playerData.healInventory.clear();
    regenQueue.removeAt(index);

    emit healed(sender);

    if(m_botData[sender].scriptData.activeModule == ManagerType::STATS)
        emit scriptActionDone(sender);
}

void StatsManager::preventRegenBlocked()
{
    QMutableListIterator<LifeRegenQueue> i(m_preventRegenBlocked);
    while (i.hasNext())
    {
        LifeRegenQueue q = i.next();
        if (q.time.elapsed() >= 30000)
        {
            error(q.sender) << "La régénération du bot était bloquée, reset du module des caractéristiques";
            m_botData[q.sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[q.sender].playerData.healInventory.clear();

            emit healed(q.sender);

            if(m_botData[q.sender].scriptData.activeModule == ManagerType::STATS)
                emit scriptActionDone(q.sender);

            i.remove();
        }
    }
}

void StatsManager::passiveHealing()
{
    int index;
    SocketIO *sender;
    QTimer *timer = static_cast<QTimer*>(QObject::sender());
    for (int i = 0; i < passiveRegen.size(); i++)
    {
        if (passiveRegen[i].timer == timer)
        {
            index = i;
            sender = passiveRegen[i].sender;
        }
    }

    if (passiveRegen.isEmpty() || (m_botData[sender].connectionData.connectionState == ConnectionState::DISCONNECTED))
    {
        QObject::disconnect(timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
        delete passiveRegen[index].timer;
        passiveRegen.removeAt(index);
    }

    int life = m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base + m_botData[sender].playerData.regenRate;
    //m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base = (life >= m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base) ? m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base : life;
    m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base = (life >= getMaxHealthPoints(sender)) ? getMaxHealthPoints(sender) : life;
}

bool StatsManager::canEquipItem(uint gid)
{
    QList<SuperTypeId> l;
    l << SuperTypeId::AMULET << SuperTypeId::BELT << SuperTypeId::BOOTS
      << SuperTypeId::COMPANION << SuperTypeId::DOFUS << SuperTypeId::HAT
      << SuperTypeId::PETS_OR_MOUNT << SuperTypeId::RING << SuperTypeId::SHIELD
      << SuperTypeId::WEAPON;

    SuperTypeId s = (SuperTypeId)qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, D2OManagerSingleton::get()->getItem(gid)->getTypeId()))->getSuperTypeId();

    if (l.contains(s))
        return true;
    return false;
}

void StatsManager::equipItem(SocketIO *sender, uint uid)
{
    InventoryObject inventoryObject;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            inventoryObject = o;

    qDebug() << "Equip Item" << uid << inventoryObject.GID << inventoryObject.isEquipped;
    if (inventoryObject.isEquipped)
        return;

    SuperTypeId superTypeId = (SuperTypeId)qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, D2OManagerSingleton::get()->getItem(inventoryObject.GID)->getTypeId()))->getSuperTypeId();
    CharacterInventoryPositionEnum characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;

    switch (superTypeId)
    {
    case SuperTypeId::AMULET:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_AMULET;
        break;

    case SuperTypeId::BELT:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_BELT;
        break;

    case SuperTypeId::CAPE:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_CAPE;
        break;

    case SuperTypeId::BOOTS:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_BOOTS;
        break;

    case SuperTypeId::COMPANION:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_ENTITY;
        break;

    case SuperTypeId::HAT:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_HAT;
        break;

    case SuperTypeId::PETS_OR_MOUNT:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_PETS;
        break;

    case SuperTypeId::SHIELD:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_SHIELD;
        break;

    case SuperTypeId::WEAPON:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON;
        break;

    case SuperTypeId::RING:
    {
        if (m_botData[sender].playerData.ring)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_LEFT;
        else
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_RING_RIGHT;

        m_botData[sender].playerData.ring = !m_botData[sender].playerData.ring;
    }
        break;

    case SuperTypeId::DOFUS:
    {
        if (m_botData[sender].playerData.dofus == 0)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_1;
        else if (m_botData[sender].playerData.dofus == 1)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_2;
        else if (m_botData[sender].playerData.dofus == 2)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_3;
        else if (m_botData[sender].playerData.dofus == 3)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_4;
        else if (m_botData[sender].playerData.dofus == 4)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_5;
        else if (m_botData[sender].playerData.dofus == 5)
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_DOFUS_6;
        else
            characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;

        m_botData[sender].playerData.dofus = (m_botData[sender].playerData.dofus + 1) % 6;
    }
        break;

    default:
        characterInventoryPositionEnum = CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;
        break;

    }

    ObjectSetPositionMessage m;
    m.objectUID = uid;
    m.quantity = 1;
    m.position = (int)characterInventoryPositionEnum;
    sender->send(m);
}

void StatsManager::unequipItem(SocketIO *sender, uint uid)
{
    InventoryObject e;
    foreach (InventoryObject o, m_botData[sender].playerData.inventoryContent)
        if (o.UID == uid)
            e = o;

    if (e.isEquipped)
    {
        ObjectSetPositionMessage m;
        m.objectUID = uid;
        m.quantity = 1;
        m.position = (int)CharacterInventoryPositionEnum::INVENTORY_POSITION_NOT_EQUIPED;
        sender->send(m);
    }
}
