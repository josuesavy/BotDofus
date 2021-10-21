#include "GameCharacterStatsFrame.h"

GameCharacterStatsFrame::GameCharacterStatsFrame(QMap<SocketIO *, BotData> *connectionsData, StatsManager *statsManager):
    AbstractFrame(connectionsData),
    m_statsManager(statsManager)
{

}

bool GameCharacterStatsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTEREXPERIENCEGAINMESSAGE:
    {
        CharacterExperienceGainMessage message;
        message.deserialize(&reader);

        if(message.experienceCharacter > 0)
        {
            m_botData[sender].statisticsData.countTotalExperience += message.experienceCharacter;
            info(sender) << "Vous avez gagné" << message.experienceCharacter << "points d'expérience.";
        }

        if(message.experienceMount > 0)
        {
            m_botData[sender].statisticsData.countTotalExperienceMount += message.experienceMount;
            info(sender) << "Votre monture a gagné" << message.experienceMount << "points d'expérience.";
        }

        if(message.experienceGuild > 0)
        {
            m_botData[sender].statisticsData.countTotalExperienceGuild += message.experienceGuild;
            info(sender) << "Votre guilde a gagné" << message.experienceGuild << "points d'expérience.";
        }

        if(message.experienceIncarnation > 0)
        {
            m_botData[sender].statisticsData.countTotalExperienceIncarnation += message.experienceIncarnation;
            info(sender) << "Votre incarnation a gagné" << message.experienceIncarnation << "points d'expérience.";
        }
    }
        break;

    case MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE:
    {
        CharacterLevelUpInformationMessage message;
        message.deserialize(&reader);

        info(sender) << message.name << "vient de passer niveau" << message.newLevel;
    }
        break;

    case MessageEnum::CHARACTERLEVELUPMESSAGE:
    {
        CharacterLevelUpMessage message;
        message.deserialize(&reader);

        m_botData[sender].statisticsData.countTotalGetNewLevel += 1;
        info(sender) << "Vous êtes maintenant niveau" << message.newLevel << "!";
    }
        break;

    case MessageEnum::CHARACTERSTATSLISTMESSAGE:
    {
        CharacterStatsListMessage message;
        message.deserialize(&reader);

        QMap<uint,UsableStats> temp;

        foreach (QSharedPointer<CharacterCharacteristic> characterCharacteristic, message.stats->characteristics)
        {
            UsableStats usableStats;

            if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERUSABLECHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterUsableCharacteristicDetailed> characterUsableCharacteristicDetailed = qSharedPointerCast<CharacterUsableCharacteristicDetailed>(characterCharacteristic);

                usableStats.base = characterUsableCharacteristicDetailed->base;
                usableStats.additional = characterUsableCharacteristicDetailed->additional;
                usableStats.objectsAndMountBonus = characterUsableCharacteristicDetailed->objectsAndMountBonus;
                usableStats.alignGiftBonus = characterUsableCharacteristicDetailed->alignGiftBonus;
                usableStats.contextModif = characterUsableCharacteristicDetailed->contextModif;
                usableStats.used = characterUsableCharacteristicDetailed->used;

                temp[characterCharacteristic->characteristicId] = usableStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterCharacteristicDetailed> characterCharacteristicDetailed = qSharedPointerCast<CharacterCharacteristicDetailed>(characterCharacteristic);

                usableStats.base = characterCharacteristicDetailed->base;
                usableStats.additional = characterCharacteristicDetailed->additional;
                usableStats.objectsAndMountBonus = characterCharacteristicDetailed->objectsAndMountBonus;
                usableStats.alignGiftBonus = characterCharacteristicDetailed->alignGiftBonus;
                usableStats.contextModif = characterCharacteristicDetailed->contextModif;

                temp[characterCharacteristic->characteristicId] = usableStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICVALUE))
            {
                QSharedPointer<CharacterCharacteristicValue> characterCharacteristicValue = qSharedPointerCast<CharacterCharacteristicValue>(characterCharacteristic);

                usableStats.total = characterCharacteristicValue->total;

                temp[characterCharacteristicValue->characteristicId] = usableStats;
            }
        }

        m_botData[sender].playerData.experience = message.stats->experience;
        m_botData[sender].playerData.experienceLevelFloor = message.stats->experienceLevelFloor;
        m_botData[sender].playerData.experienceNextLevelFloor = message.stats->experienceNextLevelFloor;
        m_botData[sender].playerData.spellModifications = message.stats->spellModifications;

        m_botData[sender].playerData.stats = temp;
        m_botData[sender].playerData.kamas = message.stats->kamas;

        m_statsManager->updateRequiredStats(sender);

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
            m_statsManager->regenOptimizer(sender);
    }
        break;

    case MessageEnum::LIFEPOINTSREGENBEGINMESSAGE:
    {
        LifePointsRegenBeginMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_statsManager->passiveRegen);
        while (i.hasNext())
            if (i.next().sender == sender)
                i.remove();

        LifeRegenQueue queue;
        queue.sender = sender;
        queue.timer = new QTimer(this);
        m_botData[sender].playerData.regenRate = message.regenRate/10;

        QObject::connect(queue.timer, SIGNAL(timeout()), m_statsManager, SLOT(passiveHealing()));
        queue.timer->setSingleShot(false);
        queue.timer->setInterval(1000);
        queue.timer->start();
        m_statsManager->passiveRegen << queue;

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
        {
            double p = (double)m_botData[sender].playerData.healPercentage/100.0;
            int max = m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base;
            int life = m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base;

            if (p*max >= life)
            {
                m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                emit m_statsManager->healed(sender);

                if(m_botData[sender].scriptData.activeManager == ManagerType::STATS)
                    emit scriptActionDone(sender);
            }

            else
            {
                LifeRegenQueue q;
                q.interval = ((p*max - life)/message.regenRate)*100;
                q.sender = sender;
                q.time.start();

                m_statsManager->regenQueue << q;
                QTimer::singleShot(q.interval*1000, m_statsManager, SLOT(healFinished()));
            }
        }
    }
        break;

    case MessageEnum::LIFEPOINTSREGENENDMESSAGE:
    {
        LifePointsRegenEndMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_statsManager->passiveRegen);
        while (i.hasNext())
        {
            LifeRegenQueue q = i.next();
            if (q.sender == sender)
            {
                QObject::disconnect(q.timer, SIGNAL(timeout()), m_statsManager, SLOT(passiveHealing()));
                q.timer->stop();
                delete q.timer;
                i.remove();
            }
        }

        if(message.lifePointsGained != 0)
            info(sender) << "Vous avez récupéré" << message.lifePointsGained << "points de vie.";
    }
        break;

    case MessageEnum::UPDATELIFEPOINTSMESSAGE:
    {
        UpdateLifePointsMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.stats[(int)StatIds::LIFE_POINTS].base = message.lifePoints;
        m_botData[sender].playerData.stats[(int)StatIds::MAX_LIFE].base = message.maxLifePoints;
    }
        break;
    }

    return messageFound;
}
