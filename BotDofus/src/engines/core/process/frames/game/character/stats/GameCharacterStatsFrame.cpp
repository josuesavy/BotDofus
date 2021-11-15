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

        QMap<uint,Stats> temp;

        foreach (QSharedPointer<CharacterCharacteristic> characterCharacteristic, message.stats->characteristics)
        {
            if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERUSABLECHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterUsableCharacteristicDetailed> characterUsableCharacteristicDetailed = qSharedPointerCast<CharacterUsableCharacteristicDetailed>(characterCharacteristic);

                UsableStats usableStats;
                usableStats.base = characterUsableCharacteristicDetailed->base;
                usableStats.additional = characterUsableCharacteristicDetailed->additional;
                usableStats.objectsAndMountBonus = characterUsableCharacteristicDetailed->objectsAndMountBonus;
                usableStats.alignGiftBonus = characterUsableCharacteristicDetailed->alignGiftBonus;
                usableStats.contextModif = characterUsableCharacteristicDetailed->contextModif;
                usableStats.used = characterUsableCharacteristicDetailed->used;
                usableStats.total = usableStats.base + usableStats.additional + usableStats.objectsAndMountBonus + usableStats.alignGiftBonus + usableStats.contextModif;

                temp[characterCharacteristic->characteristicId] = usableStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterCharacteristicDetailed> characterCharacteristicDetailed = qSharedPointerCast<CharacterCharacteristicDetailed>(characterCharacteristic);

                DetailedStats detailedStats;
                detailedStats.base = characterCharacteristicDetailed->base;
                detailedStats.additional = characterCharacteristicDetailed->additional;
                detailedStats.objectsAndMountBonus = characterCharacteristicDetailed->objectsAndMountBonus;
                detailedStats.alignGiftBonus = characterCharacteristicDetailed->alignGiftBonus;
                detailedStats.contextModif = characterCharacteristicDetailed->contextModif;
                detailedStats.total = detailedStats.base + detailedStats.additional + detailedStats.objectsAndMountBonus + detailedStats.alignGiftBonus + detailedStats.contextModif;

                temp[characterCharacteristic->characteristicId] = detailedStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICVALUE))
            {
                QSharedPointer<CharacterCharacteristicValue> characterCharacteristicValue = qSharedPointerCast<CharacterCharacteristicValue>(characterCharacteristic);

                Stats stats;
                stats.total = characterCharacteristicValue->total;

                temp[characterCharacteristicValue->characteristicId] = stats;
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

        m_botData[sender].playerData.regenRate = message.regenRate;

//        QObject::connect(m_botData[sender].playerData.basicRegen, SIGNAL(timeout()), m_statsManager, SLOT(passiveHealing()));
//        m_botData[sender].playerData.basicRegen->setSingleShot(false);
//        m_botData[sender].playerData.basicRegen->setInterval(message.regenRate*100);
//        m_botData[sender].playerData.basicRegen->start();
    }
        break;

    case MessageEnum::LIFEPOINTSREGENENDMESSAGE:
    {
        LifePointsRegenEndMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.stats[(uint)StatIds::CUR_LIFE].total = message.lifePoints - message.maxLifePoints - m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].total;
        m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].total = message.maxLifePoints;

        if(message.lifePointsGained > 0)
            info(sender) << "Vous avez récupéré" << message.lifePointsGained << "points de vie.";
    }
        break;

    case MessageEnum::FIGHTERSTATSLISTMESSAGE:
    {
        FighterStatsListMessage message;
        message.deserialize(&reader);

        QMap<uint,Stats> temp;

        foreach (QSharedPointer<CharacterCharacteristic> characterCharacteristic, message.stats->characteristics)
        {
            if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERUSABLECHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterUsableCharacteristicDetailed> characterUsableCharacteristicDetailed = qSharedPointerCast<CharacterUsableCharacteristicDetailed>(characterCharacteristic);

                UsableStats usableStats;
                usableStats.base = characterUsableCharacteristicDetailed->base;
                usableStats.additional = characterUsableCharacteristicDetailed->additional;
                usableStats.objectsAndMountBonus = characterUsableCharacteristicDetailed->objectsAndMountBonus;
                usableStats.alignGiftBonus = characterUsableCharacteristicDetailed->alignGiftBonus;
                usableStats.contextModif = characterUsableCharacteristicDetailed->contextModif;
                usableStats.used = characterUsableCharacteristicDetailed->used;
                usableStats.total = usableStats.base + usableStats.additional + usableStats.objectsAndMountBonus + usableStats.alignGiftBonus + usableStats.contextModif;

                temp[characterCharacteristic->characteristicId] = usableStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICDETAILED))
            {
                QSharedPointer<CharacterCharacteristicDetailed> characterCharacteristicDetailed = qSharedPointerCast<CharacterCharacteristicDetailed>(characterCharacteristic);

                DetailedStats detailedStats;
                detailedStats.base = characterCharacteristicDetailed->base;
                detailedStats.additional = characterCharacteristicDetailed->additional;
                detailedStats.objectsAndMountBonus = characterCharacteristicDetailed->objectsAndMountBonus;
                detailedStats.alignGiftBonus = characterCharacteristicDetailed->alignGiftBonus;
                detailedStats.contextModif = characterCharacteristicDetailed->contextModif;
                detailedStats.total = detailedStats.base + detailedStats.additional + detailedStats.objectsAndMountBonus + detailedStats.alignGiftBonus + detailedStats.contextModif;

                temp[characterCharacteristic->characteristicId] = detailedStats;
            }

            else if (characterCharacteristic->getTypes().contains(ClassEnum::CHARACTERCHARACTERISTICVALUE))
            {
                QSharedPointer<CharacterCharacteristicValue> characterCharacteristicValue = qSharedPointerCast<CharacterCharacteristicValue>(characterCharacteristic);

                Stats stats;
                stats.total = characterCharacteristicValue->total;

                temp[characterCharacteristicValue->characteristicId] = stats;
            }
        }

        m_botData[sender].playerData.experience = message.stats->experience;
        m_botData[sender].playerData.experienceLevelFloor = message.stats->experienceLevelFloor;
        m_botData[sender].playerData.experienceNextLevelFloor = message.stats->experienceNextLevelFloor;
        m_botData[sender].playerData.spellModifications = message.stats->spellModifications;

        m_botData[sender].playerData.stats = temp;
        m_botData[sender].playerData.kamas = message.stats->kamas;
    }
        break;

    case MessageEnum::UPDATELIFEPOINTSMESSAGE:
    {
        UpdateLifePointsMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.stats[(int)StatIds::LIFE_POINTS].total = message.lifePoints;
        m_botData[sender].playerData.stats[(int)StatIds::MAX_LIFE].total = message.maxLifePoints;
    }
        break;
    }

    return messageFound;
}
