#include "GameActionsFightFrame.h"

GameActionsFightFrame::GameActionsFightFrame(QMap<SocketIO *, BotData> *connectionsData, FightManager *fightManager):
    AbstractFrame(connectionsData),
    m_fightManager(fightManager)
{

}

bool GameActionsFightFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE:
    {
        GameActionFightDeathMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].isAlive = false;
        m_botData[sender].fightData.fighters[message.targetId].stats.lifePoints = 0;
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE:
    {
        GameActionFightDispellableEffectMessage message;
        message.deserialize(&reader);

        if(message.effect->getTypes().contains(ClassEnum::FIGHTTEMPORARYBOOSTSTATEEFFECT))
        {
            QSharedPointer<FightTemporaryBoostStateEffect> effect = qSharedPointerCast<FightTemporaryBoostStateEffect>(message.effect);

            if (effect->targetId == m_botData[sender].fightData.botFightData.botId)
            {
                if (m_botData[sender].fightData.botFightData.durationByEffect.contains(effect->stateId))
                    m_botData[sender].fightData.botFightData.durationByEffect.remove(effect->stateId);

                m_botData[sender].fightData.botFightData.durationByEffect[effect->stateId] = effect->turnDuration;
            }
        }

        else if(message.effect->getTypes().contains(ClassEnum::FIGHTTEMPORARYBOOSTEFFECT))
        {
            QSharedPointer<FightTemporaryBoostEffect> effect = qSharedPointerCast<FightTemporaryBoostEffect>(message.effect);

            if (message.actionId == 168)
                m_botData[sender].fightData.fighters[message.sourceId].stats.actionPoints -= effect->delta;

            else if (message.actionId == 169)
                m_botData[sender].fightData.fighters[message.sourceId].stats.actionPoints -= effect->delta;
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE:
    {
        GameActionFightLifeAndShieldPointsLostMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].stats.lifePoints -= message.loss;
        m_botData[sender].fightData.fighters[message.targetId].stats.maxLifePoints -= message.permanentDamages;

        if(m_botData[sender].fightData.botFightData.botId == message.targetId)
        {
            m_botData[sender].playerData.stats.lifePoints -= message.loss;
            m_botData[sender].playerData.stats.maxLifePoints -= message.permanentDamages;
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE:
    {
        GameActionFightLifePointsGainMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].stats.lifePoints += message.delta;

        if(m_botData[sender].fightData.botFightData.botId == message.targetId)
            m_botData[sender].playerData.stats.lifePoints += message.delta;
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE:
    {
        GameActionFightLifePointsLostMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].stats.lifePoints -= message.loss;
        m_botData[sender].fightData.fighters[message.targetId].stats.maxLifePoints -= message.permanentDamages;

        if(m_botData[sender].fightData.botFightData.botId == message.targetId)
        {
            m_botData[sender].playerData.stats.lifePoints -= message.loss;
            m_botData[sender].playerData.stats.maxLifePoints -= message.permanentDamages;
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE:
        m_fightManager->processTurn(sender);
        break;

    case MessageEnum::GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE:
    {
        GameActionFightPointsVariationMessage message;
        message.deserialize(&reader);

        switch (message.actionId)
        {
        case 101:
        case 102:
        case 120:
            m_botData[sender].fightData.fighters[message.sourceId].stats.actionPoints += message.delta;
            break;
        case 78:
        case 127:
        case 129:
            m_botData[sender].fightData.fighters[message.sourceId].stats.movementPoints += message.delta;
            break;
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE:
    {
        GameActionFightSlideMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].cellId = message.endCellId;
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTSPELLCASTMESSAGE:
    {
        GameActionFightSpellCastMessage message;
        message.deserialize(&reader);

        if(message.sourceId == m_botData[sender].fightData.botFightData.botId)
        {
            QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, message.spellId));
            QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellData->getSpellLevels()[message.spellLevel-1]));

            if(message.spellLevel != -1)
            {
                if (spellLevelData->getMinCastInterval() > 0 && !(m_botData[sender].fightData.botFightData.lastTurnCastBySpell.contains(message.spellId)))
                    m_botData[sender].fightData.botFightData.lastTurnCastBySpell[message.spellId] = spellLevelData->getMinCastInterval();

                if (m_botData[sender].fightData.botFightData.totalCastBySpell.contains(message.spellId)) //Si on a déjà utilisé ce sort ce tour
                    m_botData[sender].fightData.botFightData.totalCastBySpell[message.spellId]++;

                else
                    m_botData[sender].fightData.botFightData.totalCastBySpell[message.spellId] = 1;

                if (m_botData[sender].fightData.botFightData.totalCastByCellBySpell.contains(message.spellId)) //Si on a déjà utilisé ce sort ce tour
                {
                    if (m_botData[sender].fightData.botFightData.totalCastByCellBySpell[message.spellId].contains(message.destinationCellId)) //Si on a déjà utilisé ce sort sur cette case
                        m_botData[sender].fightData.botFightData.totalCastByCellBySpell[message.spellId][message.destinationCellId]++;

                    else
                        m_botData[sender].fightData.botFightData.totalCastByCellBySpell[message.spellId][message.destinationCellId] = 1;
                }

                else
                {
                    QMap<int, int> temp;
                    temp[message.destinationCellId] = 1;

                    m_botData[sender].fightData.botFightData.totalCastByCellBySpell[message.spellId] = temp;
                }
            }
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE:
    {
        GameActionFightSpellCooldownVariationMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.targetId)
        {
            m_botData[sender].fightData.botFightData.lastTurnCastBySpell[message.spellId] = message.value;
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE:
    {
        GameActionFightSummonMessage message;
        message.deserialize(&reader);

        foreach(const QSharedPointer<GameFightFighterInformations> &summon, message.summons)
        {
            m_fightManager->addFighter(sender, summon);
        }
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE:
    {
        GameActionFightTeleportOnSameMapMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].cellId = message.cellId;
    }
        break;
    }

    return messageFound;
}
