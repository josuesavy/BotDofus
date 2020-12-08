#include "GameContextFightFrame.h"

GameContextFightFrame::GameContextFightFrame(QMap<SocketIO *, BotData> *connectionsData, FightManager *fightManager):
    AbstractFrame(connectionsData),
    m_fightManager(fightManager)
{

}

bool GameContextFightFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEFIGHTENDMESSAGE:
    {
        GameFightEndMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters.clear();

        bool hasWon = true;

        if (!message.results.isEmpty())
        {
            if((FightOutcomeEnum)message.results.first()->outcome != FightOutcomeEnum::RESULT_VICTORY)
                hasWon = false;
        }

        m_botData[sender].fightData.hasWon = hasWon;

        if(m_botData[sender].fightData.fightType == FightTypeEnum::FIGHT_TYPE_PVP_ARENA)
        {
            m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_UNREGISTER;
            m_botData[sender].arenaData.isArenaRegistered = false;
            m_botData[sender].arenaData.arenaReadyPartyMemberIds.clear();
        }

        if(m_botData[sender].fightData.fightType == FightTypeEnum::FIGHT_TYPE_AGRESSION)
        {
            if(hasWon)
                m_botData[sender].statisticsData.countFightGetWon += 1;
            else
                m_botData[sender].statisticsData.countFightGetLost += 1;
        }

        else if(m_botData[sender].fightData.fightType == FightTypeEnum::FIGHT_TYPE_PVM)
        {
            if(hasWon)
                m_botData[sender].statisticsData.countFightSetWon += 1;
            else
                m_botData[sender].statisticsData.countFightSetLost += 1;
        }

        m_botData[sender].fightData.followingMonsterGroup = INVALID;

        int second = 0;
        second = m_fightManager->fightTimer.elapsed()/1000;

        m_botData[sender].statisticsData.speedFight += second;

        info(sender) << "Combat fini en" << second << "s.";
    }
        break;

    case MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE:
    {
        GameFightHumanReadyStateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.characterId)
            m_botData[sender].fightData.botFightData.isReady = message.isReady;

        else if(m_botData[sender].groupData.master == m_botData[sender].fightData.fighters[message.characterId].name && m_botData[sender].groupData.isInGroup)
        {
            GameFightReadyMessage answer;
            m_botData[sender].fightData.botFightData.isReady = message.isReady;
            answer.isReady = message.isReady;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTLEAVEMESSAGE:
    {
        GameFightLeaveMessage message;
        message.deserialize(&reader);

        if(message.charId = m_botData[sender].fightData.botFightData.botId)
        {
            action(sender) << "Vous avez été expulsé du combat";

            m_botData[sender].generalData.botState = INACTIVE_STATE;
        }

        else
            m_botData[sender].fightData.fighters.remove(message.charId);
    }
        break;

    case MessageEnum::GAMEFIGHTOPTIONSTATEUPDATEMESSAGE:
    {
        GameFightOptionStateUpdateMessage message;
        message.deserialize(&reader);


        if((TeamEnum)message.teamId == m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId)
        {
            if((FightOptionsEnum)message.option == FightOptionsEnum::FIGHT_OPTION_ASK_FOR_HELP)
                m_botData[sender].fightData.options.isAskingForHelp = message.state;

            else if((FightOptionsEnum)message.option == FightOptionsEnum::FIGHT_OPTION_SET_SECRET)
                m_botData[sender].fightData.options.isSecret = message.state;

            else if((FightOptionsEnum)message.option == FightOptionsEnum::FIGHT_OPTION_SET_CLOSED)
                m_botData[sender].fightData.options.isClosed = message.state;

            else if((FightOptionsEnum)message.option == FightOptionsEnum::FIGHT_OPTION_SET_TO_PARTY_ONLY)
                m_botData[sender].fightData.options.isRestrictedToOnly = message.state;
        }
    }
        break;

    case MessageEnum::GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE:
    {
        GameFightPlacementPossiblePositionsMessage message;
        message.deserialize(&reader);

        if((TeamEnum)message.teamNumber == TeamEnum::TEAM_DEFENDER)
            m_botData[sender].fightData.startingPositions = message.positionsForDefenders;

        else if((TeamEnum)message.teamNumber == TeamEnum::TEAM_CHALLENGER)
            m_botData[sender].fightData.startingPositions = message.positionsForChallengers;
    }
        break;

    case MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE:
    {
        GameFightPlacementSwapPositionsErrorMessage message;
        message.deserialize(&reader);

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.fight.swapPositionRequestError");
    }
        break;

    case MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE:
    {
        GameEntitiesDispositionMessage message;
        message.deserialize(&reader);

        foreach(QSharedPointer<IdentifiedEntityDispositionInformations> entity, message.dispositions)
            m_botData[sender].fightData.fighters[entity->id].cellId = entity->cellId;

        m_fightManager->updateFightDisposition(sender);
    }
        break;

    case MessageEnum::GAMEFIGHTRESUMEWITHSLAVESMESSAGE:
    case MessageEnum::GAMEFIGHTRESUMEMESSAGE:
    {
        GameFightResumeMessage message;
        message.deserialize(&reader);

        m_botData[sender].generalData.botState = FIGHTING_STATE;
        m_botData[sender].fightData.botFightData.durationByEffect.clear();
        m_botData[sender].fightData.botFightData.lastTurnCastBySpell.clear();
        m_botData[sender].fightData.botFightData.totalCastByCellBySpell.clear();
        m_botData[sender].fightData.botFightData.totalCastBySpell.clear();
        m_botData[sender].fightData.botFightData.processingSpells.clear();
        m_botData[sender].fightData.isBotTurn = false;

        foreach(GameFightSpellCooldown coolDown, message.spellCooldowns)
            m_botData[sender].fightData.botFightData.lastTurnCastBySpell[coolDown.spellId] = coolDown.cooldown;

        foreach(QSharedPointer<FightDispellableEffectExtendedInformations> baseEffect, message.effects)
        {
            if(baseEffect->effect->getTypes().contains(ClassEnum::FIGHTTEMPORARYBOOSTSTATEEFFECT))
            {
                QSharedPointer<FightTemporaryBoostStateEffect> effect = qSharedPointerCast<FightTemporaryBoostStateEffect>(baseEffect->effect);

                if (effect->targetId == m_botData[sender].fightData.botFightData.botId)
                {
                    if (m_botData[sender].fightData.botFightData.durationByEffect.contains(effect->stateId))
                    {
                        m_botData[sender].fightData.botFightData.durationByEffect.remove(effect->stateId);
                    }

                    m_botData[sender].fightData.botFightData.durationByEffect[effect->stateId] = effect->turnDuration;
                }
            }

            else if(baseEffect->effect->getTypes().contains(ClassEnum::FIGHTTEMPORARYBOOSTEFFECT))
            {
                QSharedPointer<FightTemporaryBoostEffect> effect = qSharedPointerCast<FightTemporaryBoostEffect>(baseEffect->effect);

                if (baseEffect->actionId == 168)
                    m_botData[sender].fightData.fighters[baseEffect->sourceId].stats.actionPoints -= effect->delta;

                else if (baseEffect->actionId == 169)
                    m_botData[sender].fightData.fighters[baseEffect->sourceId].stats.actionPoints -= effect->delta;
            }
        }

    }
        break;

    case MessageEnum::GAMEFIGHTSTARTINGMESSAGE:
    {
        GameFightStartingMessage message;
        message.deserialize(&reader);

        warn(sender) << "Commencement d'un nouveau combat !";
        m_fightManager->fightTimer.restart();
    }
        break;

    case MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE:
    {
        GameFightSynchronizeMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters.clear();

        foreach(QSharedPointer<GameFightFighterInformations> fighter, message.fighters)
        {
            m_fightManager->addFighter(sender, fighter);
        }

        if(m_botData[sender].fightData.isBotTurn)
        {
            m_fightManager->processTurn(sender);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTTURNENDMESSAGE:
    {
        GameFightTurnEndMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.id)
        {
            m_fightManager->processEndTurn(sender);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTTURNREADYREQUESTMESSAGE:
    {
        GameFightTurnReadyMessage answer;
        answer.deserialize(&reader);
        answer.isReady = true;
        sender->send(answer);
    }
        break;

    case MessageEnum::GAMEFIGHTTURNSTARTMESSAGE:
    {
        GameFightTurnStartMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.id)
        {
            debug(sender)<<"C'est mon tour.";
            m_botData[sender].fightData.botFightData.processingSpells = m_botData[sender].fightData.requestedSpells;
            m_botData[sender].fightData.botFightData.processingIA = m_botData[sender].fightData.fightIA;
            m_botData[sender].fightData.isBotTurn = true;
            m_botData[sender].fightData.botFightData.movementsWaiting = true;
            m_botData[sender].fightData.botFightData.spellsWaiting = true;
            m_botData[sender].fightData.botFightData.firstActionWaiting = true;
            m_botData[sender].fightData.botFightData.lastActionWaiting = true;
        }

        else
            m_botData[sender].fightData.isBotTurn = false;
    }
        break;

    case MessageEnum::GAMEFIGHTUPDATETEAMMESSAGE:
    {
        GameFightUpdateTeamMessage message;
        message.deserialize(&reader);

        foreach (QSharedPointer<FightTeamMemberInformations> members, message.team->teamMembers)
        {
            if (m_botData[sender].mapData.botId != members->id)
            {
                if(m_botData[sender].generalData.botState == FIGHTING_STATE && m_botData[sender].fightData.lockExpel && members->id != INVALID)
                {
                    action(sender) << "Un joueur inconnu est entré dans le combat. Expulsion de ce joueur...";
                    GameContextKickMessage gckmsg;
                    gckmsg.targetId = members->id;
                    sender->send(gckmsg);
                }
            }
        }
    }
        break;
    }

    return messageFound;
}
