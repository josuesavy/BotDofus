#include "GameCharacterStatsFrame.h"

GameCharacterStatsFrame::GameCharacterStatsFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameCharacterStatsFrame::reset(SocketIO *sender)
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
        Stats temp;
        temp.spellsPoints = message.stats.spellsPoints;
        temp.lifePoints = message.stats.lifePoints;
        temp.maxLifePoints = message.stats.maxLifePoints;
        temp.energyPoints = message.stats.energyPoints;
        temp.maxEnergyPoints = message.stats.maxEnergyPoints;
        temp.actionPointsCurrent = message.stats.actionPointsCurrent;
        temp.movementPointsCurrent = message.stats.movementPointsCurrent;
        temp.initiative = message.stats.initiative;
        temp.prospecting = message.stats.prospecting;
        temp.actionPoints = message.stats.actionPoints;
        temp.movementPoints = message.stats.movementPoints;
        temp.strength = message.stats.strength;
        temp.vitality = message.stats.vitality;
        temp.wisdom = message.stats.wisdom;
        temp.chance = message.stats.chance;
        temp.agility = message.stats.agility;
        temp.intelligence = message.stats.intelligence;
        temp.range = message.stats.range;
        temp.summonableCreaturesBoost = message.stats.summonableCreaturesBoost;
        temp.reflect = message.stats.reflect;
        temp.criticalHit = message.stats.criticalHit;
        temp.criticalHitWeapon = message.stats.criticalHitWeapon;
        temp.criticalMiss = message.stats.criticalMiss;
        temp.healBonus = message.stats.healBonus;
        temp.allDamagesBonus = message.stats.allDamagesBonus;
        temp.weaponDamagesBonusPercent = message.stats.weaponDamagesBonusPercent;
        temp.damagesBonusPercent = message.stats.damagesBonusPercent;
        temp.trapBonus = message.stats.trapBonus;
        temp.glyphBonusPercent = message.stats.glyphBonusPercent;
        temp.trapBonusPercent = message.stats.trapBonusPercent;
        temp.permanentDamagePercent = message.stats.permanentDamagePercent;
        temp.tackleBlock = message.stats.tackleBlock;
        temp.tackleEvade = message.stats.tackleEvade;
        temp.PAAttack = message.stats.PAAttack;
        temp.PMAttack = message.stats.PMAttack;
        temp.pushDamageBonus = message.stats.pushDamageBonus;
        temp.criticalDamageBonus = message.stats.criticalDamageBonus;
        temp.neutralDamageBonus = message.stats.neutralDamageBonus;
        temp.earthDamageBonus = message.stats.earthDamageBonus;
        temp.waterDamageBonus = message.stats.waterDamageBonus;
        temp.airDamageBonus = message.stats.airDamageBonus;
        temp.fireDamageBonus = message.stats.fireDamageBonus;
        temp.dodgePALostProbability = message.stats.dodgePALostProbability;
        temp.dodgePMLostProbability = message.stats.dodgePMLostProbability;
        temp.neutralElementResistPercent = message.stats.neutralElementResistPercent;
        temp.earthElementResistPercent = message.stats.earthElementResistPercent;
        temp.waterElementResistPercent = message.stats.waterElementResistPercent;
        temp.airElementResistPercent = message.stats.airElementResistPercent;
        temp.fireElementResistPercent = message.stats.fireElementResistPercent;
        temp.neutralElementReduction = message.stats.neutralElementReduction;
        temp.earthElementReduction = message.stats.earthElementReduction;
        temp.waterElementReduction = message.stats.waterElementReduction;
        temp.airElementReduction = message.stats.airElementReduction;
        temp.fireElementReduction = message.stats.fireElementReduction;
        temp.pushDamageReduction = message.stats.pushDamageReduction;
        temp.criticalDamageReduction = message.stats.criticalDamageReduction;
        temp.pvpNeutralElementResistPercent = message.stats.pvpNeutralElementResistPercent;
        temp.pvpEarthElementResistPercent = message.stats.pvpEarthElementResistPercent;
        temp.pvpWaterElementResistPercent = message.stats.pvpWaterElementResistPercent;
        temp.pvpAirElementResistPercent = message.stats.pvpAirElementResistPercent;
        temp.pvpFireElementResistPercent = message.stats.pvpFireElementResistPercent;
        temp.pvpNeutralElementReduction = message.stats.pvpNeutralElementReduction;
        temp.pvpEarthElementReduction = message.stats.pvpEarthElementReduction;
        temp.pvpWaterElementReduction = message.stats.pvpWaterElementReduction;
        temp.pvpAirElementReduction = message.stats.pvpAirElementReduction;
        temp.pvpFireElementReduction = message.stats.pvpFireElementReduction;
        temp.experience = message.stats.experience;
        temp.experienceLevelFloor = message.stats.experienceLevelFloor;
        temp.experienceNextLevelFloor = message.stats.experienceNextLevelFloor;
        temp.spellsPoints = message.stats.spellsPoints;
        temp.statsPoints = message.stats.statsPoints;

        if (temp.pods.max == 0)
            temp.pods = m_botData[sender].playerData.stats.pods;

        m_botData[sender].playerData.stats = temp;
        m_botData[sender].playerData.kamas = message.stats.kamas;

        updateRequiredStats(sender);

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
            regenOptimizer(sender);
    }
        break;

    case MessageEnum::FIGHTERSTATSLISTMESSAGE:
        break;

    case MessageEnum::LIFEPOINTSREGENBEGINMESSAGE:
    {
        LifePointsRegenBeginMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_passiveRegen);
        while (i.hasNext())
            if (i.next().sender == sender)
                i.remove();

        LifeRegenQueue queue;
        queue.sender = sender;
        queue.timer = new QTimer(this);
        m_botData[sender].playerData.regenRate = message.regenRate/10;

        QObject::connect(queue.timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
        queue.timer->setSingleShot(false);
        queue.timer->setInterval(1000);
        queue.timer->start();
        m_passiveRegen << queue;

        if (m_botData[sender].generalData.botState == BotState::REGENERATING_STATE)
        {
            double p = (double)m_botData[sender].playerData.healPercentage/100.0;
            int max = m_botData[sender].playerData.stats.maxLifePoints;
            int life = m_botData[sender].playerData.stats.lifePoints;

            if (p*max >= life)
            {
                m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;

                emit healed(sender);

                if(m_botData[sender].scriptData.activeModule == getType())
                    emit scriptActionDone(sender);
            }

            else
            {
                LifeRegenQueue q;
                q.interval = ((p*max - life)/message.regenRate)*100;
                q.sender = sender;
                q.time.start();

                m_regenQueue << q;
                QTimer::singleShot(q.interval*1000, this, SLOT(healFinished()));
            }
        }
    }
        break;

    case MessageEnum::LIFEPOINTSREGENENDMESSAGE:
    {
        LifePointsRegenEndMessage message;
        message.deserialize(&reader);

        QMutableListIterator<LifeRegenQueue> i(m_passiveRegen);
        while (i.hasNext())
        {
            LifeRegenQueue q = i.next();
            if (q.sender == sender)
            {
                QObject::disconnect(q.timer, SIGNAL(timeout()), this, SLOT(passiveHealing()));
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
        m_botData[sender].playerData.stats.lifePoints = message.lifePoints;
        m_botData[sender].playerData.stats.maxLifePoints = message.maxLifePoints;
    }
        break;
    }

    return messageFound;
}
