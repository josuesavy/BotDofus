#include "FightModule.h"

bool operator<(const Point2D &left, const Point2D & right)
{
    if(left.x < right.x)
        return true;

    else if(left.x == right.x && left.y < right.y)
        return true;

    return false;
}

QMap<int, Point2D> FightModule::m_cellsPos;
QMap<Point2D, int> FightModule::m_cellsId;

FightModule::FightModule(QMap<SocketIO *, BotData> *connectionsData, MapModule *mapModule, GroupModule *groupModule, ArenaModule *arenaModule) :
    AbstractModule(ModuleType::FIGHT, connectionsData),
    m_mapModule(mapModule),
    m_groupModule(groupModule),
    m_arenaModule(arenaModule)
{
    int param4 = 0;
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int param5 = 0;

    while(param5 < MAP_HEIGHT)
    {
        param4 = 0;
        while(param4 < MAP_WIDTH)
        {
            Point2D point;
            point.x = param1 + param4;
            point.y = param2 + param4;
            m_cellsPos[param3] = point;
            param3++;
            param4++;
        }
        param1++;
        param4 = 0;
        while(param4 < MAP_WIDTH)
        {
            Point2D point;
            point.x = param1 + param4;
            point.y = param2 + param4;
            m_cellsPos[param3] = point;
            param3++;
            param4++;
        }
        param2--;
        param5++;
    }

    foreach(const int &id, m_cellsPos.keys())
        m_cellsId[m_cellsPos[id]] = id;

    connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(moveSuccess(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(moveFailure(SocketIO*)));
    connect(m_mapModule, SIGNAL(mapContentUpdated(SocketIO*)), this, SLOT(processEndFight(SocketIO*)));
}

void FightModule::reset(SocketIO *sender)
{
    m_botData[sender].fightData.botFightData = BotFightData();
    m_botData[sender].fightData.isBotTurn = false;
    m_botData[sender].fightData.followingMonsterGroup = 0;
    m_botData[sender].fightData.hasWon = true;
}

bool FightModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHATSERVERMESSAGE:
    {
        ChatServerMessage m;
        m.deserialize(&reader);

        if(m.content == "fight")
        {
            if(processMonsters(sender))
                qDebug()<<"IS GOING TO FIGHT";

            else
                qDebug()<<"NO MONSTERS";
        }
    }
        break;

    case MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE:
    case MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE:
    {
        MapRunningFightListRequestMessage answer;
        sender->send(answer);
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

    case MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE:
    {
        GameEntitiesDispositionMessage message;
        message.deserialize(&reader);

        foreach(QSharedPointer<IdentifiedEntityDispositionInformations> entity, message.dispositions)
            m_botData[sender].fightData.fighters[entity->id].cellId = entity->cellId;

        updateFightDisposition(sender);
    }
        break;

    case MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE:
    {
        GameFightHumanReadyStateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.characterId)
            m_botData[sender].fightData.botFightData.isReady = message.isReady;

        else if(m_botData[sender].groupData.master == m_botData[sender].fightData.fighters[message.characterId].name)
        {
            GameFightReadyMessage answer;
            m_botData[sender].fightData.botFightData.isReady = message.isReady;
            answer.isReady = message.isReady;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE:
    {
        MapRunningFightListMessage message;
        message.deserialize(&reader);

        foreach(FightExternalInformations fight, message.fights)
        {
            foreach(FightTeamLightInformations team, fight.fightTeams)
            {
                if(team.hasGroupMember)
                {
                    action(sender) << "Un membre de votre groupe à lancé un combat.";

                    GameFightJoinRequestMessage answer;
                    answer.fightId = fight.fightId;
                    answer.fighterId = team.leaderId;
                    sender->send(answer);

                    break;
                }
            }
        }
    }
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE:
    {
        GameRolePlayPlayerFightFriendlyRequestedMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].mapData.playersOnMap[message.sourceId].name == m_botData[sender].groupData.master)
        {
            warn(sender)<<m_botData[sender].groupData.master<<"(chef) vous défi !";
            action(sender) << "Acceptation du défi..";

            GameRolePlayPlayerFightFriendlyAnswerMessage answer;
            answer.accept = true;
            answer.fightId = message.fightId;
            sender->send(answer);
        }

        else
        {
            warn(sender)<<m_botData[sender].mapData.playersOnMap[message.sourceId].name << "vous défi !";
            action(sender) << "Refus du défi..";

            GameRolePlayPlayerFightFriendlyAnswerMessage answer;
            answer.accept = false;
            answer.fightId = message.fightId;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE:
    {
        GameRolePlayPlayerFightFriendlyAnsweredMessage message;
        message.deserialize(&reader);

        if(message.accept)
            info(sender) << "Défi de" << m_botData[sender].mapData.playersOnMap[message.sourceId].name << "accepté.";

        else
            info(sender) << "Défi de" << m_botData[sender].mapData.playersOnMap[message.sourceId].name << "refusé.";
    }
        break;

    case MessageEnum::GAMEMAPMOVEMENTMESSAGE:
    {
        if(m_botData[sender].generalData.botState == FIGHTING_STATE)
        {
            GameMapMovementMessage message;
            message.deserialize(&reader);
            m_botData[sender].fightData.fighters[message.actorId].cellId = message.keyMovements.last();
        }
    }
        break;

    case MessageEnum::GAMEMAPNOMOVEMENTMESSAGE:
    {
        if(m_botData[sender].generalData.botState == FIGHTING_STATE)
            processTurn(sender);
    }
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

    case MessageEnum::SEQUENCEENDMESSAGE:
    {
        SequenceEndMessage message;
        message.deserialize(&reader);

        if(message.authorId == m_botData[sender].fightData.botFightData.botId)
        {
            GameActionAcknowledgementMessage answer;
            answer.valid = true;
            answer.actionId = message.actionId;
            sender->send(answer);

            processTurn(sender);
        }
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

    case MessageEnum::GAMEFIGHTTURNENDMESSAGE:
    {
        GameFightTurnEndMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].fightData.botFightData.botId == message.id)
            processEndTurn(sender);
    }
        break;

    case MessageEnum::GAMEFIGHTSTARTINGMESSAGE:
    {
        GameFightStartingMessage message;
        message.deserialize(&reader);

        warn(sender) << "Commencement d'un nouveau combat !";
        m_fightTimer.restart();
    }
        break;

    case MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE:
    {
        GameFightSynchronizeMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters.clear();

        foreach(QSharedPointer<GameFightFighterInformations> fighter, message.fighters)
            addFighter(sender, fighter);

        if(m_botData[sender].fightData.isBotTurn)
            processTurn(sender);
    }
        break;

    case MessageEnum::GAMEFIGHTJOINMESSAGE:
    {
        GameFightJoinMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fightType = (FightTypeEnum)message.fightType;
        m_botData[sender].generalData.botState = FIGHTING_STATE;
        m_botData[sender].fightData.botFightData.durationByEffect.clear();
        m_botData[sender].fightData.botFightData.lastTurnCastBySpell.clear();
        m_botData[sender].fightData.botFightData.totalCastByCellBySpell.clear();
        m_botData[sender].fightData.botFightData.totalCastBySpell.clear();
        m_botData[sender].fightData.botFightData.processingSpells.clear();
        m_botData[sender].fightData.isBotTurn = false;
        m_botData[sender].fightData.botFightData.isReady = false;

        if(m_botData[sender].fightData.fightType == FightTypeEnum::FIGHT_TYPE_AGRESSION)
            warn(sender)<<"Aggression...";

        else if(m_botData[sender].fightData.fightType == FightTypeEnum::FIGHT_TYPE_PVP_ARENA)
        {
            m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_STARTING_FIGHT;
            m_botData[sender].arenaData.isArenaRegistered = false;

            action(sender)<<"Début du koli";
        }

        else
        {
            if(m_botData[sender].generalData.botState == FIGHTING_STATE)
            {
                if(m_botData[sender].fightData.lockAskForHelp && !m_botData[sender].fightData.options.isAskingForHelp)
                {
                    debug(sender)<< "Demande d'aide signalé";

                    GameFightOptionToggleMessage answer;
                    answer.option = (uint)FightOptionsEnum::FIGHT_OPTION_ASK_FOR_HELP;
                    sender->send(answer);
                }

                if(m_botData[sender].fightData.lockSecret && !m_botData[sender].fightData.options.isSecret)
                {
                    debug(sender) << "Fermeture du mode spectateur";

                    GameFightOptionToggleMessage answer;
                    answer.option = (uint)FightOptionsEnum::FIGHT_OPTION_SET_SECRET;
                    sender->send(answer);

                    //info(sender)<<D2OManagerSingleton::get()->getI18N()->getText("ui.spectator.noSpectatorForThisFight");
                }

                if(m_botData[sender].fightData.lockClosed && !m_botData[sender].fightData.options.isClosed)
                {
                    debug(sender) << "Fermeture du combat";

                    GameFightOptionToggleMessage answer;
                    answer.option = (uint)FightOptionsEnum::FIGHT_OPTION_SET_CLOSED;
                    sender->send(answer);
                }

                if(m_botData[sender].fightData.lockPartyOnly && !m_botData[sender].fightData.options.isRestrictedToOnly)
                {
                    debug(sender) << "Fermeture du combat aux personnages étranger de votre groupe";

                    GameFightOptionToggleMessage answer;
                    answer.option = (uint)FightOptionsEnum::FIGHT_OPTION_SET_TO_PARTY_ONLY;
                    sender->send(answer);
                }
            }
        }

        if(m_botData[sender].scriptData.isActive) // TODO
        {
            if(m_botData[sender].scriptData.activeModule != getType())
                emit scriptActionCancel(sender);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTENDMESSAGE:
    {
        GameFightEndMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters.clear();

        bool hasWon = true;

        if((FightOutcomeEnum)message.results.first()->outcome != FightOutcomeEnum::RESULT_VICTORY)
            hasWon = false;

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
        second = m_fightTimer.elapsed()/1000;

        m_botData[sender].statisticsData.speedFight += second;

        info(sender) << "Combat fini en" << second << "s.";
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

    case MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE:
    {
        GameActionFightDeathMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].isAlive = false;
        m_botData[sender].fightData.fighters[message.targetId].stats.lifePoints = 0;
    }
        break;

    case MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE:
    {
        GameFightShowFighterMessage message;
        message.deserialize(&reader);

        addFighter(sender, message.informations);

        if(!m_groupModule->getSlaves(sender).isEmpty())
        {
            QList<SocketIO*> slaves = m_groupModule->getSlaves(sender);
            QStringList names;

            foreach(SocketIO *slave, slaves)
                names << m_botData[slave].connectionData.connectionInfos.character;

            for(int i = 0; i < m_botData[sender].fightData.fighters.size(); i++)
            {
                if(m_botData[sender].fightData.fighters.values()[i].teamId == m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId && m_botData[sender].fightData.fighters.values()[i].cellId != m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId)
                    names.removeOne(m_botData[sender].fightData.fighters.values()[i].name);
            }

            if(names.isEmpty())
            {
                debug(sender)<<"Master ready to start fight with his"<<slaves.size()<<"slaves";
                GameFightReadyMessage answer;
                m_botData[sender].fightData.botFightData.isReady = true;
                answer.isReady = true;
                sender->send(answer);
            }
        }

        else
        {
            GameFightReadyMessage answer;
            m_botData[sender].fightData.botFightData.isReady = true;
            answer.isReady = true;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE:
    {
        GameFightShowFighterRandomStaticPoseMessage message;
        message.deserialize(&reader);

        addFighter(sender, message.informations);
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

    case MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE:
    {
        GameActionFightSlideMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].cellId = message.endCellId;
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE:
    {
        GameActionFightTeleportOnSameMapMessage message;
        message.deserialize(&reader);

        m_botData[sender].fightData.fighters[message.targetId].cellId = message.cellId;
    }
        break;

    case MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE:
    {
        GameActionFightSummonMessage message;
        message.deserialize(&reader);

        foreach(const QSharedPointer<GameFightFighterInformations> &summon, message.summons)
            addFighter(sender, summon);
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

    case MessageEnum::GAMEFIGHTSPECTATORJOINMESSAGE:
        break;

    case MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE:
        processTurn(sender);
        break;

    case MessageEnum::GAMEFIGHTTURNSTARTPLAYINGMESSAGE:
        break;

    case MessageEnum::SEQUENCESTARTMESSAGE:
        break;

    case MessageEnum::FIGHTERSTATSLISTMESSAGE:
        break;
    }

    return messageFound;
}

void FightModule::setRequestedMonsters(SocketIO *sender, RequestedMonsters requestedMonster)
{
    m_botData[sender].fightData.requestedMonsters = requestedMonster;
}

void FightModule::setFightIA(SocketIO *sender, FightIA fightIA)
{
    m_botData[sender].fightData.fightIA = fightIA;
}

void FightModule::setFightPlacementPosition(SocketIO *sender, FightPlacementPosition fightPlacementPosition)
{
    m_botData[sender].fightData.fightPlacementPosition = fightPlacementPosition;
}

void FightModule::setPartyOnly(SocketIO *sender, bool isPartyOnly)
{
    m_botData[sender].fightData.lockPartyOnly = isPartyOnly;
}

void FightModule::setSecret(SocketIO *sender, bool isSecret)
{
    m_botData[sender].fightData.lockSecret = isSecret;
}

void FightModule::setClosed(SocketIO *sender, bool isClosed)
{
    m_botData[sender].fightData.lockClosed = isClosed;
}

void FightModule::setAskForHelp(SocketIO *sender, bool isAskForHelp)
{
    m_botData[sender].fightData.lockAskForHelp = isAskForHelp;
}

void FightModule::setExpel(SocketIO *sender, bool isExpel, double id)
{
    m_botData[sender].fightData.lockExpel = isExpel;
}

void FightModule::giveUpFight(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState == BotState::FIGHTING_STATE)
    {
        action(sender) << "Abandon du combat";

        GameContextQuitMessage message;
        sender->send(message);
    }
}

void FightModule::setRequestedSpells(SocketIO *sender, QList<RequestedSpell> requestedSpells)
{
    m_botData[sender].fightData.requestedSpells = requestedSpells;
}

QList<RequestedSpell> FightModule::getRequestedSpells(SocketIO *sender) const
{
    return m_botData[sender].fightData.requestedSpells;
}

void FightModule::updateFightDisposition(SocketIO *sender)
{
    if(m_botData[sender].fightData.fightPlacementPosition != FightPlacementPosition::NONE)
    {
        if(m_botData[sender].fightData.fightPlacementPosition == FightPlacementPosition::NEARFUL)
        {
            int cibleID = INVALID;
            cibleID = getStrongestEnemy(sender);

            qDebug()<<"FightModule - Ennemi visé :"<<cibleID;

            if(cibleID != INVALID)
            {
                int cellID = INVALID;

                QList<uint> possiblePositions = m_botData[sender].fightData.startingPositions;

                foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
                {
                    if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].entityId != fighter.entityId && fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId == fighter.teamId)
                    {
                        possiblePositions.removeOne(fighter.cellId);
                    }
                }

                cellID = getClosestCell(cibleID, m_botData[sender].fightData.startingPositions);

                if(cellID != INVALID && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId != cellID)
                {
                    qDebug()<<"FightModule - Tentative de placement à la cellule"<<cellID;
                    GameFightPlacementPositionRequestMessage answer;
                    answer.cellId = cellID;
                    sender->send(answer);
                }

                else if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId == cellID)
                {
                    qDebug()<<"FightModule - Position actuelle déjà optimale";
                }
            }

            else
                qDebug()<<"FightModule - Le classement des positions a échoué";
        }

        else if(m_botData[sender].fightData.fightPlacementPosition == FightPlacementPosition::FARTHER)
        {
            QList<uint> enemies = getEnemies(sender);

            if(!enemies.isEmpty())
            {
                int cibleID = getMiddleCell(enemies);
                int cellID = INVALID;
                QList<uint> possiblePositions = m_botData[sender].fightData.startingPositions;

                foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
                {
                    if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].entityId != fighter.entityId && fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId == fighter.teamId)
                    {
                        possiblePositions.removeOne(fighter.cellId);
                    }
                }

                cellID = getFartherCell(cibleID, possiblePositions);

                if(cellID != INVALID && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId != cellID)
                {
                    qDebug()<<"FightModule - Tentative de placement à la cellule"<<cellID;
                    GameFightPlacementPositionRequestMessage answer;
                    answer.cellId = cellID;
                    sender->send(answer);
                }

                else if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId == cellID)
                {
                    qDebug()<<"FightModule - Position actuelle déjà optimale";
                }
            }

            else
                qDebug()<<"FightModule - Le classement des ennemis a échoué";
        }
    }
}

QList<uint> FightModule::getFighters(SocketIO *sender)
{
    QList<uint> fighters;
    foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.isAlive && (GameActionFightInvisibilityStateEnum)fighter.stats.invisibilityState != GameActionFightInvisibilityStateEnum::INVISIBLE)
        {
            fighters<<fighter.cellId;
        }
    }

    return fighters;
}

int FightModule::getStrongestEnemy(SocketIO *sender)
{
    int level = INVALID;
    int cellID = INVALID;

    foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId != fighter.teamId && fighter.level != INVALID && fighter.level > level)
        {
            level = fighter.level;
            cellID = fighter.cellId;
        }
    }

    return cellID;
}

int FightModule::getWeakestEnemy(SocketIO *sender)
{
    int level = 999999999;
    int cellID = INVALID;

    foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId != fighter.teamId && fighter.level != INVALID & fighter.level < level)
        {
            level = fighter.level;
            cellID = fighter.cellId;
        }
    }

    return cellID;
}

QList<uint> FightModule::getAllies(SocketIO *sender)
{
    QList<uint> allies;
    foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].entityId != fighter.entityId && fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId == fighter.teamId)
        {
            allies<<fighter.cellId;
        }
    }

    return allies;
}

QList<uint> FightModule::getEnemies(SocketIO *sender)
{
    QList<uint> enemies;
    foreach(const FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.isAlive && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].teamId != fighter.teamId && (GameActionFightInvisibilityStateEnum)fighter.stats.invisibilityState != GameActionFightInvisibilityStateEnum::INVISIBLE)
        {
            enemies<<fighter.cellId;
        }
    }

    return enemies;
}

void FightModule::processTurn(SocketIO *sender)
{
    if(m_botData[sender].fightData.botFightData.firstActionWaiting)
    {
        m_botData[sender].fightData.botFightData.firstActionWaiting = false;

        if(m_botData[sender].fightData.botFightData.processingIA == FightIA::AGGRESSIVE)
        {
            QList<uint> enemies = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getEnemies(sender));

            foreach(uint enemy, enemies)
            {
                if(moveNear(sender, enemy))
                {
                    return;
                }
            }
        }

        if(m_botData[sender].fightData.botFightData.processingIA == FightIA::FOLLOWER)
        {
            QList<uint> allies = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getAllies(sender));

            if(!allies.isEmpty())
            {
                int cibleID = getMiddleCell(allies);

                if(moveNear(sender, cibleID, 1))
                {
                    return;
                }
            }
        }
    }

    if(!m_botData[sender].fightData.botFightData.processingSpells.isEmpty())
    {
        RequestedSpell requested = m_botData[sender].fightData.botFightData.processingSpells.first();

        // Waiting to move
        if(m_botData[sender].fightData.botFightData.movementsWaiting)
        {
            if(m_botData[sender].fightData.botFightData.processingIA == FightIA::FEARFUL || m_botData[sender].fightData.botFightData.processingIA == FightIA::FOLLOWER || m_botData[sender].fightData.botFightData.processingIA == FightIA::AGGRESSIVE)
            {
                if(canCastSpell(sender, requested.spellID) == SpellInabilityReason::OK)
                {
                    QList<uint> cibles;

                    bool strictMoving = true;

                    if(requested.spellCible == SpellCible::DIRECTION)
                    {
                        strictMoving = false;
                        cibles = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getEnemies(sender));
                    }

                    if(requested.spellCible == SpellCible::ENEMY)
                    {
                        cibles = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getEnemies(sender));
                    }

                    else if(requested.spellCible == SpellCible::ALLY)
                    {
                        cibles = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getAllies(sender));
                    }

                    else if(requested.spellCible == SpellCible::SELF)
                    {
                        cibles<<m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId;
                    }

                    foreach(uint cell, cibles)
                    {
                        SpellInabilityReason reason = canCastSpellOnCell(sender, requested.spellID, cell);

                        if(reason == SpellInabilityReason::MIN_RANGE || reason == SpellInabilityReason::MAX_RANGE)
                        {
                            if(moveToRange(sender, requested.spellID, cell, strictMoving))
                            {
                                m_botData[sender].fightData.botFightData.movementsWaiting = false;
                                return;
                            }
                        }
                    }

                    if(m_botData[sender].fightData.botFightData.movementsWaiting)
                    {
                        m_botData[sender].fightData.botFightData.movementsWaiting = false;
                        processTurn(sender);
                        return;
                    }
                }

                else
                {
                    m_botData[sender].fightData.botFightData.spellsWaiting = false;
                    m_botData[sender].fightData.botFightData.movementsWaiting = false;

                    if(m_botData[sender].fightData.botFightData.processingSpells.first().castNb > 0)
                    {
                        m_botData[sender].fightData.botFightData.processingSpells.first().castNb--;
                    }
                }
            }
        }

        // Waiting for cast spells
        else if(m_botData[sender].fightData.botFightData.spellsWaiting)
        {
            m_botData[sender].fightData.botFightData.spellsWaiting = false;
            m_botData[sender].fightData.botFightData.processingSpells.first().castNb--;

            if((requested.spellCible == SpellCible::ENEMY || requested.spellCible == SpellCible::ALLY || requested.spellCible == SpellCible::SELF))
            {
                QList<uint> cibles;

                if(requested.spellCible == SpellCible::ENEMY)
                {
                    cibles = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getEnemies(sender));
                }

                else if(requested.spellCible == SpellCible::ALLY)
                {
                    cibles = getClosestCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getAllies(sender));
                }

                else if(requested.spellCible == SpellCible::SELF)
                {
                    cibles<<m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId;
                }

                foreach(uint cell, cibles)
                {
                    if(canCastSpell(sender, requested.spellID) == SpellInabilityReason::OK && canCastSpellOnCell(sender, requested.spellID, cell) == SpellInabilityReason::OK)
                    {
                        castSpell(sender, requested.spellID, cell);
                        return;
                    }
                }
            }

            else if(requested.spellCible == SpellCible::DIRECTION)
            {
                if(m_botData[sender].fightData.botFightData.processingIA == FightIA::AGGRESSIVE || m_botData[sender].fightData.botFightData.processingIA == FightIA::FEARFUL)
                {
                    if(castNear(sender, requested.spellID, getMiddleCell(getEnemies(sender))))
                    {
                        return;
                    }
                }

                else if(m_botData[sender].fightData.botFightData.processingIA == FightIA::FOLLOWER)
                {
                    QList<uint> cells = getAllies(sender);
                    cells<<m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId;

                    if(castNear(sender, requested.spellID, getMiddleCell(cells)))
                    {
                        return;
                    }
                }
            }
        }
    }

    if(!m_botData[sender].fightData.botFightData.spellsWaiting && !m_botData[sender].fightData.botFightData.movementsWaiting && !m_botData[sender].fightData.botFightData.processingSpells.isEmpty())
    {
        if(m_botData[sender].fightData.botFightData.processingSpells.first().castNb == 0)
        {
            m_botData[sender].fightData.botFightData.processingSpells.removeFirst();
            m_botData[sender].fightData.botFightData.spellsWaiting = true;
            m_botData[sender].fightData.botFightData.movementsWaiting = true;
            processTurn(sender);
            return;
        }

        else if(m_botData[sender].fightData.botFightData.processingSpells.first().castNb != 0)
        {
            m_botData[sender].fightData.botFightData.spellsWaiting = true;
            m_botData[sender].fightData.botFightData.movementsWaiting = true;

            processTurn(sender);
            return;
        }
    }

    if(!m_botData[sender].fightData.botFightData.processingSpells.isEmpty())
    {
        m_botData[sender].fightData.botFightData.spellsWaiting = true;
        m_botData[sender].fightData.botFightData.movementsWaiting = true;
    }

    else
    {
        if(m_botData[sender].fightData.botFightData.lastActionWaiting)
        {
            m_botData[sender].fightData.botFightData.lastActionWaiting = false;

            int spellWithLessPo = INVALID;
            int smallestPo = 999;

            for(int i = 0; i < m_botData[sender].fightData.requestedSpells.size(); i++)
            {
                // Get spell's range
                QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, m_botData[sender].fightData.requestedSpells[i].spellID));
                int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[m_botData[sender].fightData.requestedSpells[i].spellID].spellLevel-1];
                QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));
                int range = spellLevelData->getRange();

                if((m_botData[sender].fightData.requestedSpells[i].spellCible == SpellCible::ENEMY || m_botData[sender].fightData.requestedSpells[i].spellCible == SpellCible::DIRECTION) && range < smallestPo && canCastSpellNextTurn(sender, m_botData[sender].fightData.requestedSpells[i].spellID) == SpellInabilityReason::OK)
                {
                    spellWithLessPo =  m_botData[sender].fightData.requestedSpells[i].spellID;
                    smallestPo = range;
                }
            }

            if(spellWithLessPo != INVALID)
            {
                uint enemy = getClosestCell(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, getEnemies(sender));

                if(enemy != INVALID)
                {
                    int distance = getDistance(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, enemy);

                    if(distance != smallestPo)
                    {
                        if(m_botData[sender].fightData.botFightData.processingIA == FightIA::AGGRESSIVE)
                        {
                            if(moveToRange(sender, spellWithLessPo, enemy, false))
                            {
                                return;
                            }
                        }

                        else if(m_botData[sender].fightData.botFightData.processingIA == FightIA::FEARFUL)
                        {
                            moveAway(sender, enemy, smallestPo, false);
                        }
                    }
                }
            }
        }

        GameFightTurnFinishMessage answer;
        sender->send(answer);
    }
}

void FightModule::processEndTurn(SocketIO *sender)
{
    m_botData[sender].fightData.isBotTurn = false;

    int key = 0;
    QList<int> list;

    m_botData[sender].fightData.botFightData.totalCastBySpell.clear();
    m_botData[sender].fightData.botFightData.totalCastByCellBySpell.clear();

    for (int i = 0; i < m_botData[sender].fightData.botFightData.durationByEffect.size(); i++)
    {
        key = m_botData[sender].fightData.botFightData.durationByEffect.keys()[i];
        m_botData[sender].fightData.botFightData.durationByEffect[key]--;

        if(m_botData[sender].fightData.botFightData.durationByEffect[m_botData[sender].fightData.botFightData.durationByEffect.keys()[i]] <= 0)
        {
            list << m_botData[sender].fightData.botFightData.durationByEffect.keys()[i];
        }
    }

    while (list.size() > 0)
    {
        m_botData[sender].fightData.botFightData.durationByEffect.remove(list[0]);
        list.removeAt(0);
    }

    for (int i = 0; i < m_botData[sender].fightData.botFightData.lastTurnCastBySpell.size(); i++)
    {
        key = m_botData[sender].fightData.botFightData.lastTurnCastBySpell.keys()[i];
        m_botData[sender].fightData.botFightData.lastTurnCastBySpell[key]--;

        if(m_botData[sender].fightData.botFightData.lastTurnCastBySpell[m_botData[sender].fightData.botFightData.lastTurnCastBySpell.keys()[i]] <= 0)
        {
            list << m_botData[sender].fightData.botFightData.lastTurnCastBySpell.keys()[i];
        }
    }

    while (list.size() > 0)
    {
        m_botData[sender].fightData.botFightData.lastTurnCastBySpell.remove(list[0]);
        list.removeAt(0);
    }
}

QList<uint> FightModule::getFartherCells(uint cellID, QList<uint> cibles)
{
    cibles = getClosestCells(cellID, cibles);
    QList<uint> reversedCibles;

    for(int i = cibles.size()-1; i != -1; i--)
    {
        reversedCibles<<cibles[i];
    }

    return reversedCibles;
}

uint FightModule::getFartherCell(uint cellID, QList<uint> cibles)
{
    int fatherCellID = INVALID;
    int distance = 0;

    foreach(const uint &cibleID, cibles)
    {
        if(getDistance(cibleID, cellID) > distance)
        {
            distance = getDistance(cibleID, cellID);
            fatherCellID = cibleID;
        }
    }

    return fatherCellID;
}

QList<uint> FightModule::getClosestCells(uint cellID, QList<uint> cibles)
{
    QMultiMap<int, uint> associatedDistances;
    QList<int> distances;

    for(int i = 0; i < cibles.size(); i++)
    {
        int distance = getDistance(cibles[i], cellID);
        distances<<distance;
        associatedDistances.insert(distance, cibles[i]);
    }

    qSort(distances);
    cibles.clear();


    for(int i = 0; i < distances.size(); i++)
    {
        cibles << associatedDistances.values(distances[i]);
    }

    return cibles;
}

uint FightModule::getClosestCell(uint cellID, QList<uint> cibles)
{
    int closestCellID = INVALID;
    int distance = 99999;

    foreach(const uint &cibleID, cibles)
    {
        if(getDistance(cibleID, cellID) < distance)
        {
            distance = getDistance(cibleID, cellID);
            closestCellID = cibleID;
        }
    }

    return closestCellID;
}

uint FightModule::getMiddleCell(QList<uint> cibles)
{
    int cibleID = INVALID;

    if(!cibles.isEmpty())
    {
        int xSum = 0;
        int ySum = 0;

        foreach(const uint &cell, cibles)
        {
            Point2D point = getCoordsbyCellID(cell);
            xSum += point.x;
            ySum += point.y;
        }

        Point2D cibleCoords;
        cibleCoords.x = xSum/cibles.size();
        cibleCoords.y = ySum/cibles.size();

        cibleID = getCellIDFromCoords(cibleCoords);
    }

    return cibleID;
}

QList<uint> FightModule::getSurroundingCells(int cellID, int minRadius, int radius)
{
    int param7= 0;
    QList<uint> possibleCells;
    Point2D param3 = getCoordsbyCellID(cellID);
    int param4 = param3.x;
    int param5 = param3.y;

    if(radius == 0 && minRadius == 0)
    {
        possibleCells<<cellID;
    }

    else
    {
        int param8 = 1;
        int param9 = 0;
        int  param6 = param4 - radius;

        while(param6 <= param4 + radius)
        {
            param7 = -param9;

            while(param7 <= param9)
            {
                if(!minRadius || qAbs(param4 - param6) + qAbs(param7) >= minRadius)
                {
                    Point2D point;
                    point.x = param6;
                    point.y = param5 + param7;

                    if(point.x + point.y >= 0 && point.x - point.y >= 0 && point.x - point.y < MAP_HEIGHT * 2 && point.x + point.y < MAP_WIDTH * 2)
                    {
                        possibleCells<<getCellIDFromCoords(point);
                    }
                }
                param7++;
            }

            if(param9 == radius)
            {
                param8 *= -1;
            }

            param9 +=  param8;
            param6++;
        }
    }

    return possibleCells;
}

SpellInabilityReason FightModule::canCastSpellNextTurn(SocketIO *sender, int spellID)
{
    QMap<int, int> lastTurnCastBySpell = m_botData[sender].fightData.botFightData.lastTurnCastBySpell;
    QMap<int ,int> totalCastBySpell = m_botData[sender].fightData.botFightData.totalCastBySpell;
    QMap<int, int> durationByEffect = m_botData[sender].fightData.botFightData.durationByEffect;
    QMap<int, QMap<int, int> > totalCastByCellBySpell = m_botData[sender].fightData.botFightData.totalCastByCellBySpell;
    int actionPoints = m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints;

    m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints += 6;

    if(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].level >= 100)
    {
        m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints ++;
    }

    processEndTurn(sender);
    SpellInabilityReason reason = canCastSpell(sender, spellID);

    m_botData[sender].fightData.botFightData.lastTurnCastBySpell = lastTurnCastBySpell;
    m_botData[sender].fightData.botFightData.totalCastBySpell = totalCastBySpell;
    m_botData[sender].fightData.botFightData.durationByEffect = durationByEffect;
    m_botData[sender].fightData.botFightData.totalCastByCellBySpell = totalCastByCellBySpell;
    m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints = actionPoints;

    return reason;
}

SpellInabilityReason FightModule::canCastSpell(SocketIO *sender, int spellID)
{
    QSharedPointer<WeaponData> weaponData;

    QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
    int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];

    if(spellLevelID == 0)
    {
        foreach(const InventoryObject &item, m_botData[sender].playerData.inventoryContent)
        {
            if(item.position == CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON)
            {
                weaponData = qSharedPointerCast<WeaponData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, item.GID));
                break;
            }
        }
    }

    QSharedPointer<SpellLevelData> spellLevelsData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));

    if (spellLevelsData.data() == NULL)
    {
        return SpellInabilityReason::UNKNOWN;
    }

    if ((spellLevelID != 0 && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints < spellLevelsData->getApCost()) || (weaponData.data() != NULL && m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.actionPoints < weaponData->getApCost()))
    {
        return SpellInabilityReason::ACTION_POINTS;
    }


    if (m_botData[sender].fightData.botFightData.totalCastBySpell.contains(spellID) && m_botData[sender].fightData.botFightData.totalCastBySpell[spellID] >= spellLevelsData->getMaxCastPerTurn() && spellLevelsData->getMaxCastPerTurn() > 0)
    {
        return SpellInabilityReason::TOO_MANY_LAUNCH;
    }

    if (m_botData[sender].fightData.botFightData.lastTurnCastBySpell.contains(spellID))
    {
        return SpellInabilityReason::COOL_DOWN;
    }

    QList<EffectInstanceDiceData> effects = spellLevelsData->getEffects();

    int invocationNumber = 0;
    foreach (FightEntityInfos fighter, m_botData[sender].fightData.fighters)
    {
        if (fighter.stats.summoner == m_botData[sender].fightData.botFightData.botId)
        {
            invocationNumber ++;
        }
    }

    if (effects.size() > 0 && effects[0].getEffectId() == 181)
    {
        Stats stats = m_botData[sender].playerData.stats;
        int total = stats.summonableCreaturesBoost.base + stats.summonableCreaturesBoost.objectsAndMountBonus + stats.summonableCreaturesBoost.alignGiftBonus + stats.summonableCreaturesBoost.contextModif;

        if (invocationNumber >= total)
        {
            return SpellInabilityReason::TOO_MANY_INVOCATIONS;
        }
    }

    QList<int> listOfStates = spellLevelsData->getStatesRequired();
    foreach (const int &state, listOfStates)
    {
        if (!(m_botData[sender].fightData.botFightData.durationByEffect.contains(state)))
        {
            return SpellInabilityReason::REQUIRED_STATE;
        }
    }

    listOfStates = spellLevelsData->getStatesForbidden();
    foreach (const int &state, listOfStates)
    {
        if (m_botData[sender].fightData.botFightData.durationByEffect.contains(state))
        {
            return SpellInabilityReason::FORBIDDEN_STATE;
        }
    }

    return SpellInabilityReason::OK;
}

SpellInabilityReason FightModule::canCastSpellOnCell(SocketIO *sender, int spellID, int cellID)
{
    QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
    int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];

    QSharedPointer<WeaponData> weaponData;

    if(spellLevelID == 0)
    {
        foreach(const InventoryObject &item, m_botData[sender].playerData.inventoryContent)
        {
            if(item.position == CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON)
            {
                weaponData = qSharedPointerCast<WeaponData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, item.GID));
                break;
            }
        }
    }

    QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));

    if (spellLevelData == NULL)
    {
        return SpellInabilityReason::UNKNOWN;
    }

    Point2D characterPoint = getCoordsbyCellID(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId);
    Point2D targetPoint = getCoordsbyCellID(cellID);

    int distanceToTarget = getDistance(characterPoint, targetPoint);
    int minRange = (spellLevelID != 0) ? (int)spellLevelData->getMinRange() : weaponData->getMinRange();

    if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
    {
        minRange *= 2;
    }

    if (minRange < 0)
    {
        minRange = 0;
    }

    int maxRange = (spellLevelID != 0) ? (int)(spellLevelData->getRange() + (spellLevelData->getRangeCanBeBoosted() ? m_botData[sender].playerData.stats.range.objectsAndMountBonus : 0)) : spellLevelData->getRange();

    if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
    {
        maxRange = (maxRange * 2);
    }

    if (maxRange < 0)
    {
        maxRange = 0;
    }

    if (distanceToTarget < minRange)
    {
        return SpellInabilityReason::MIN_RANGE;
    }

    if (distanceToTarget > maxRange)
    {
        return SpellInabilityReason::MAX_RANGE;
    }

    if (((spellLevelID != 0 && spellLevelData->getCastInLine()) || (weaponData != NULL && weaponData->getCastInLine())) && characterPoint.x != targetPoint.x && characterPoint.y != targetPoint.y)
    {
        return SpellInabilityReason::NOT_IN_LINE;
    }

    if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
    {
        QList<Point2D> list = getLine(characterPoint.x, characterPoint.y, targetPoint.x, targetPoint.y);

        int i = 0;
        while (i < list.size() - 1)
        {
            Point2D actualPoint = list[i];
            Point2D nextPoint = list[i + 1];
            i += 1;

            if (actualPoint.x == nextPoint.x + 1 && actualPoint.y == nextPoint.y + 1)
            {
                continue;
            }

            else if (actualPoint.x == nextPoint.x - 1 && actualPoint.y == nextPoint.y - 1)
            {
                continue;
            }

            else if (actualPoint.x == nextPoint.x + 1 && actualPoint.y == nextPoint.y - 1)
            {
                continue;
            }

            else if (actualPoint.x == nextPoint.x - 1 && actualPoint.y == nextPoint.y + 1)
            {
                continue;
            }

            return SpellInabilityReason::NOT_IN_DIAGONAL;
        }
    }

    if (((spellLevelID != 0 && spellLevelData->getCastTestLos()) || (weaponData != NULL && weaponData->getCastTestLos())) && distanceToTarget > 1)
    {
        QList<Point2D> list = getLine(characterPoint.x, characterPoint.y, targetPoint.x, targetPoint.y);

        int i = 0;
        while (i < list.size() - 1)
        {
            Point2D point3 = list[i];

            Point2D point4;
            point4.x = qFloor(point3.x);
            point4.y = qFloor(point3.y);

            int point4CellId = getCellIDFromCoords(point4);

            if (!(isFreeCell(sender, point4CellId)) || !(m_botData[sender].mapData.map.getCellData()[point4CellId].isLos()))
            {
                return SpellInabilityReason::LINE_OF_SIGHT;
            }

            i ++;
        }
    }

    int targetPointCellID = (targetPoint.x - targetPoint.y) * MAP_WIDTH + targetPoint.y + (targetPoint.x - targetPoint.y) / 2;

    if ((m_botData[sender].fightData.botFightData.totalCastByCellBySpell.contains(spellID) && m_botData[sender].fightData.botFightData.totalCastByCellBySpell[spellID].contains(targetPointCellID)) && m_botData[sender].fightData.botFightData.totalCastByCellBySpell[spellID][targetPointCellID] >= spellLevelData->getMaxCastPerTarget() && spellLevelData->getMaxCastPerTarget() > 0)
    {
        return SpellInabilityReason::TOO_MANY_LAUNCH_ON_CELL;
    }

    if (isFreeCell(sender, cellID))
    {
        if (spellLevelData->getNeedTakenCell())
        {
            return SpellInabilityReason::NEED_TAKEN_CELL;
        }
    }

    else if (spellLevelData->getNeedFreeCell())
    {
        return SpellInabilityReason::NEED_FREE_CELL;
    }

    return SpellInabilityReason::OK;
}

bool FightModule::isFreeCell(SocketIO *sender, int cellID)
{
    foreach(const FightEntityInfos &fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.cellId == cellID)
        {
            return false;
        }
    }

    return true;
}

QList<Point2D> FightModule::getLine(int x1, int y1, int x2, int y2)
{
    int z1 = 0;
    int z2 = 0;
    int i = 0;
    int erreurSupArrondis = 0;
    int erreurInfArrondis = 0;
    float beforeY = INVALID;
    float afterY = INVALID;
    float diffBeforeCenterY = INVALID;
    float diffCenterAfterY = INVALID;
    float beforeX = INVALID;
    float afterX = INVALID;
    float diffBeforeCenterX = INVALID;
    float diffCenterAfterX = INVALID;
    uint y = 0;
    uint x = 0;
    QList<Point2D> line;

    Point3D pFrom;
    pFrom.x = x1;
    pFrom.y = y1;
    pFrom.z = z1;

    Point3D pTo;
    pTo.x = x2;
    pTo.y = y2;
    pTo.z = z2;

    Point3D pStart;
    pStart.x = pFrom.x + 0.5;
    pStart.y = pFrom.y + 0.5;
    pStart.z = pFrom.z;

    Point3D pEnd;
    pEnd.x = pTo.x + 0.5;
    pEnd.y = pTo.y + 0.5;
    pEnd.z = pTo.z;

    double padX = 0;
    double padY = 0;
    double padZ = 0;
    double steps = 0;
    bool descending = pStart.z > pEnd.z;

    QList<int> xToTest;
    QList<int> yToTest;
    uint cas = 0;

    if (abs(pStart.x - pEnd.x) == abs(pStart.y - pEnd.y))
    {
        steps = abs(pStart.x - pEnd.x);
        padX = pEnd.x > pStart.x ? 1 : -1;
        padY = pEnd.y > pStart.y ? 1 : -1;
        padZ = steps == 0 ? 0 : descending?(pFrom.z - pTo.z) / steps : (pTo.z - pFrom.z) / steps;
        cas = 1;
    }
    else if (abs(pStart.x - pEnd.x) > abs(pStart.y - pEnd.y))
    {
        steps = abs(pStart.x - pEnd.x);
        padX = pEnd.x > pStart.x ? 1 : -1;
        padY = pEnd.y > pStart.y ? abs(pStart.y - pEnd.y) == 0 ? 0 : abs(pStart.y - pEnd.y) / steps : -abs(pStart.y - pEnd.y) / steps;
        padY = padY * 100;
        padY = ceil(padY) / 100;
        padZ = steps == 0 ? 0 : descending ? (pFrom.z - pTo.z) / steps : (pTo.z - pFrom.z) / steps;
        cas = 2;
    }
    else
    {
        steps = abs(pStart.y - pEnd.y);
        padX = pEnd.x > pStart.x ? abs(pStart.x - pEnd.x) == 0 ? 0 : abs(pStart.x - pEnd.x) / steps : -abs(pStart.x - pEnd.x) / steps;
        padX = padX * 100;
        padX = ceil(padX) / 100;
        padY = pEnd.y > pStart.y ? 1 : -1;
        padZ = steps == 0 ? 0 : descending ? (pFrom.z - pTo.z) / steps : (pTo.z - pFrom.z) / steps;
        cas = 3;
    }

    while (i < steps)
    {
        erreurSupArrondis = (int)(3 + steps / 2);
        erreurInfArrondis = (int)(97 - steps / 2);

        if (cas == 2)
        {

            beforeY = ceil(pStart.y * 100 + padY * 50) / 100;
            afterY = floor(pStart.y * 100 + padY * 150) / 100;
            diffBeforeCenterY = floor(abs(floor(beforeY) * 100 - beforeY * 100)) / 100;
            diffCenterAfterY = ceil(abs(ceil(afterY) * 100 - afterY * 100)) / 100;
            qDebug() << padY << pStart.y;

            if (floor(beforeY) == floor(afterY))
            {
                yToTest.clear();
                yToTest.append(floor(pStart.y + padY));
                if ((beforeY == yToTest[0]) && (afterY < yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(ceil(pStart.y + padY));
                }

                else if((beforeY == yToTest[0]) && (afterY > yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(floor(pStart.y + padY));
                }

                else if((afterY == yToTest[0]) && (beforeY < yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(ceil(pStart.y + padY));
                }

                else if((afterY == yToTest[0]) && (beforeY > yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(floor(pStart.y + padY));
                }
            }

            else if (ceil(beforeY) == ceil(afterY))
            {
                yToTest.clear();
                yToTest.append(ceil(pStart.y + padY));
                if((beforeY == yToTest[0]) && (afterY < yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(floor(pStart.y + padY));
                }

                else if((beforeY == yToTest[0]) && (afterY > yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(ceil(pStart.y + padY));
                }

                else if((afterY == yToTest[0]) && (beforeY < yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(floor(pStart.y + padY));
                }

                else if((afterY == yToTest[0]) && (beforeY > yToTest[0]))
                {
                    yToTest.clear();
                    yToTest.append(ceil(pStart.y + padY));
                }
            }

            else if ((int)(diffBeforeCenterY * 100) <= erreurSupArrondis)
            {
                yToTest.clear();
                yToTest.append(floor(afterY));
            }

            else if ((int)(diffCenterAfterY * 100) >= erreurInfArrondis)
            {
                yToTest.clear();
                yToTest.append(floor(beforeY));
            }

            else
            {
                yToTest.clear();
                yToTest.append(floor(beforeY));
                yToTest.append(floor(afterY));
            }
        }

        else if (cas == 3)
        {
            beforeX = ceil(pStart.x * 100 + padX * 50) / 100;
            afterX = floor(pStart.x * 100 + padX * 150) / 100;
            diffBeforeCenterX = floor(abs(floor(beforeX) * 100 - beforeX * 100)) / 100;
            diffCenterAfterX = ceil(abs(ceil(afterX) * 100 - afterX * 100)) / 100;

            if (floor(beforeX) == floor(afterX))
            {
                xToTest.clear();
                xToTest.append(floor(pStart.x + padX));
                if ((beforeX == xToTest[0]) && (afterX < xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(ceil(pStart.x + padX));
                }

                else if ((beforeX == xToTest[0]) && (afterX > xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(floor(pStart.x + padX));
                }

                else if ((afterX == xToTest[0]) && (beforeX < xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(ceil(pStart.x + padX));
                }

                else if ((afterX == xToTest[0]) && (beforeX > xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(floor(pStart.x + padX));
                }
            }

            else if (ceil(beforeX) == ceil(afterX))
            {
                xToTest.clear();
                xToTest.append(ceil(pStart.x + padX));
                if ((beforeX == xToTest[0]) && (afterX < xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(floor(pStart.x + padX));
                }

                else if ((beforeX == xToTest[0]) && (afterX > xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(ceil(pStart.x + padX));
                }

                else if ((afterX == xToTest[0]) && (beforeX < xToTest[0]))
                {
                    xToTest.clear();
                    xToTest.append(floor(pStart.x + padX));
                }

                else if ((afterX == xToTest[0]) && (beforeX > xToTest[0]))
                {
                    xToTest.append(ceil(pStart.x + padX));
                }
            }

            else if ((int)(diffBeforeCenterX * 100) <= erreurSupArrondis)
            {
                xToTest.clear();
                xToTest.append(floor(afterX));
            }

            else if ((int)(diffCenterAfterX * 100) >= erreurInfArrondis)
            {
                xToTest.clear();
                xToTest.append(floor(beforeX));
            }

            else
            {
                xToTest.clear();
                xToTest.append(floor(beforeX));
                xToTest.append(floor(afterX));
            }
        }

        if (!yToTest.isEmpty())
        {
            y = 0;
            while (y < yToTest.size())
            {
                Point2D cell;
                cell.x = floor(pStart.x + padX);
                cell.y = yToTest.at(y);

                line.append(cell);
                y++;
            }
        }

        else if (!xToTest.isEmpty())
        {
            x = 0;
            while(x < xToTest.size())
            {
                Point2D cell;
                cell.x = xToTest.at(x);
                cell.y = floor(pStart.y + padY);

                line.append(cell);
                x++;
            }
        }
        else if (cas == 1)
        {
            Point2D cell;
            cell.x = floor(pStart.x + padX);
            cell.y = floor(pStart.y + padY);

            line.append(cell);
        }

        pStart.x = (pStart.x * 100 + padX * 100) / 100;
        pStart.y = (pStart.y * 100 + padY * 100) / 100;
        i++;
    }

    return line;
}

void FightModule::castSpell(SocketIO *sender, int spellID, int cellID)
{
    foreach(const FightEntityInfos &fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.cellId == cellID && fighter.isAlive)
        {
            GameActionFightCastOnTargetRequestMessage answer;
            answer.spellId = spellID;
            answer.targetId = fighter.entityId;
            sender->send(answer);
            return;
        }
    }

    GameActionFightCastRequestMessage answer;
    answer.spellId = spellID;
    answer.cellId = cellID;
    sender->send(answer);
}

void FightModule::moveToCell(SocketIO *sender, QList<uint> path)
{
    GameMapMovementRequestMessage message;
    message.mapId = m_botData[sender].mapData.map.getMapId();
    message.keyMovements = path;
    sender->send(message);
}

void FightModule::addFighter(SocketIO *sender, const QSharedPointer<GameFightFighterInformations> &fighter)
{
    FightEntityInfos infos;
    infos.isAlive = fighter->spawnInfo->alive;
    infos.entityId = fighter->contextualId;
    infos.stats = *fighter->stats;
    infos.cellId = fighter->disposition->cellId;
    infos.direction = fighter->disposition->direction;
    infos.teamId = (TeamEnum)fighter->spawnInfo->teamId;

    if(fighter->getTypes().contains(ClassEnum::GAMEFIGHTFIGHTERNAMEDINFORMATIONS))
    {
        QSharedPointer<GameFightFighterNamedInformations> namedFighter = qSharedPointerCast<GameFightFighterNamedInformations>(fighter);
        infos.name = namedFighter->name;

        if(namedFighter->name ==  m_botData[sender].connectionData.connectionInfos.character)
        {
            m_botData[sender].fightData.botFightData.botId = fighter->contextualId;
        }
    }

    if(fighter->getTypes().contains(ClassEnum::GAMEFIGHTCHARACTERINFORMATIONS))
    {
        QSharedPointer<GameFightCharacterInformations> characterFighter = qSharedPointerCast<GameFightCharacterInformations>(fighter);
        infos.level = characterFighter->level;
    }

    m_botData[sender].fightData.fighters[fighter->contextualId] = infos;
}

bool FightModule::castNear(SocketIO *sender, int spellID, int cibleID)
{
    qDebug()<<"CAST NEAR";

    if(cibleID != INVALID && canCastSpell(sender, spellID) == SpellInabilityReason::OK)
    {
        QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
        int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];
        QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));

        QSharedPointer<WeaponData> weaponData;

        if(spellLevelID == 0)
        {
            foreach(const InventoryObject &item, m_botData[sender].playerData.inventoryContent)
            {
                if(item.position == CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON)
                {
                    weaponData = qSharedPointerCast<WeaponData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, item.GID));
                    break;
                }
            }
        }

        int minRange = (spellLevelID != 0) ? (int)spellLevelData->getMinRange() : weaponData->getMinRange();

        if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
        {
            minRange *= 2;
        }

        if (minRange <= 0)
        {
            minRange = 1;
        }

        int maxRange = (spellLevelID != 0) ? (int)(spellLevelData->getRange() + (spellLevelData->getRangeCanBeBoosted() ? m_botData[sender].playerData.stats.range.objectsAndMountBonus : 0)) : spellLevelData->getRange();

        if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
        {
            maxRange = (maxRange * 2);
        }

        if (maxRange <= 0)
        {
            maxRange = 1;
        }

        QList<uint> possibleCells = getSurroundingCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, minRange, maxRange);

        QMultiMap<int, uint> associatedDistances;
        QList<int> distances;

        for(int i = 0; i < possibleCells.size(); i++)
        {
            int distance = getDistance(possibleCells[i], cibleID);
            distances<<distance;
            associatedDistances.insert(distance, possibleCells[i]);
        }

        qSort(distances);
        possibleCells.clear();

        for(int i = 0; i < distances.size(); i++)
        {
            possibleCells << associatedDistances.values(distances[i]);
        }

        for(int i = 0; i < possibleCells.size(); i++)
        {
            if(canCastSpellOnCell(sender, spellID, possibleCells[i]) == SpellInabilityReason::OK)
            {
                castSpell(sender, spellID, possibleCells[i]);
                return true;
            }
        }
    }

    return false;
}

bool FightModule::castAway(SocketIO *sender, int spellID, int cibleID)
{
    qDebug()<<"CAST AWAY";

    if(cibleID != INVALID && canCastSpell(sender, spellID) == SpellInabilityReason::OK)
    {
        QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
        int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];
        QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));

        QSharedPointer<WeaponData> weaponData;

        if(spellLevelID == 0)
        {
            foreach(const InventoryObject &item, m_botData[sender].playerData.inventoryContent)
            {
                if(item.position == CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON)
                {
                    weaponData = qSharedPointerCast<WeaponData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, item.GID));
                    break;
                }
            }
        }

        int minRange = (spellLevelID != 0) ? (int)spellLevelData->getMinRange() : weaponData->getMinRange();

        if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
        {
            minRange *= 2;
        }

        if (minRange <= 0)
        {
            minRange = 1;
        }

        int maxRange = (spellLevelID != 0) ? (int)(spellLevelData->getRange() + (spellLevelData->getRangeCanBeBoosted() ? m_botData[sender].playerData.stats.range.objectsAndMountBonus : 0)) : spellLevelData->getRange();

        if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
        {
            maxRange = (maxRange * 2);
        }

        if (maxRange <= 0)
        {
            maxRange = 1;
        }

        QList<uint> possibleCells = getSurroundingCells(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, minRange, maxRange);

        QMultiMap<int, uint> associatedDistances;
        QList<int> distances;

        for(int i = 0; i < possibleCells.size(); i++)
        {
            int distance = getDistance(possibleCells[i], cibleID);
            distances<<distance;
            associatedDistances.insert(distance, possibleCells[i]);
        }

        qSort(distances);
        possibleCells.clear();

        for(int i = 0; i < distances.size(); i++)
        {
            possibleCells << associatedDistances.values(distances[distances.size()-1-i]);
        }

        for(int i = 0; i < possibleCells.size(); i++)
        {
            if(canCastSpellOnCell(sender, spellID, possibleCells[i]) == SpellInabilityReason::OK)
            {
                castSpell(sender, spellID, possibleCells[i]);
                return true;
            }
        }
    }

    return false;
}

bool FightModule::moveNear(SocketIO *sender, int cibleID, int distanceWanted, bool moveOnlyIfDistancePossible)
{
    int movementPoints = m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.movementPoints;

    if(movementPoints != 0 && cibleID != INVALID)
    {
        qDebug()<<"CONSIDERED CIBLE"<<cibleID;

        qDebug()<<"MOVE NEAR";

        QList<uint> fighters = getFighters(sender);
        fighters.removeOne(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId);
        fighters.removeOne(cibleID);

        PathInfos pathInfos = Pathfinding().findPath(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, cibleID, m_botData[sender].mapData.map.getMapId(), false, false, fighters);

        qDebug()<<m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId<<cibleID<<pathInfos.path;

        if(pathInfos.path.size() > 2)
        {
            if(pathInfos.path.size() > movementPoints+1)
            {
                while(movementPoints < pathInfos.path.size()-1)
                {
                    pathInfos.path.removeLast();
                }
            }

            while(getDistance(pathInfos.path.last(), cibleID) < distanceWanted)
            {
                pathInfos.path.removeLast();
            }

            if(distanceWanted == getDistance(pathInfos.path.last(), cibleID) || !moveOnlyIfDistancePossible)
            {
                qDebug()<<"SIZE"<<getDistance(pathInfos.path.last(), cibleID)<<pathInfos.path.size();
                qDebug()<<"PM"<<movementPoints<<distanceWanted;

                moveToCell(sender, pathInfos.path);

                qDebug()<<"MOVE NEAR SEND"<<pathInfos.path;

                return true;
            }
        }
    }

    qDebug()<<"MOVE NEAR REFUSED";

    return false;
}

bool FightModule::moveAway(SocketIO *sender, int cibleID, int distanceWanted, bool moveOnlyIfDistancePossible)
{
    int movementPoints = m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].stats.movementPoints;

    if(movementPoints != 0 && cibleID != INVALID)
    {
        qDebug()<<"MOVE AWAY"<<distanceWanted;
        qDebug()<<"CONSIDERED CIBLE"<<cibleID;

        int cellID = m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId;
        int originalDistance = getDistance(cellID, cibleID);

        QList<uint> possibleCells = getSurroundingCells(cellID, 0, movementPoints);

        foreach(const uint &possibleCell, possibleCells)
        {
            if(!isFreeCell(sender, possibleCell) || m_botData[sender].mapData.map.getCellData()[possibleCell].isNonWalkableDuringFight())
            {
                possibleCells.removeOne(possibleCell);
            }
        }

        QMultiMap<int, uint> associatedDistances;
        QList<int> distances;

        for(int i = 0; i < possibleCells.size(); i++)
        {
            int distance = getDistance(possibleCells[i], cibleID);

            if((moveOnlyIfDistancePossible && distance == distanceWanted) ||
                    (!moveOnlyIfDistancePossible && distance > originalDistance && distance <= distanceWanted) ||
                    distanceWanted == -1)
            {
                if(!distances.contains(distance))
                {
                    distances<<distance;
                }

                associatedDistances.insert(distance, possibleCells[i]);
            }
        }

        qSort(distances);
        possibleCells.clear();

        for(int i = 0; i < distances.size(); i++)
        {
            possibleCells << associatedDistances.values(distances[distances.size()-1-i]);
        }

        QList<uint> path;
        int distance = 0;
        QList<uint> fighters = getFighters(sender);

        for(int i = 0; i < possibleCells.size(); i++)
        {
            QList<uint> fightersAlias = fighters;
            fightersAlias.removeOne(cellID);
            //fightersAlias.removeOne(possibleCells[i]);

            Pathfinding pathfinder;
            PathInfos test = pathfinder.findPath(cellID, possibleCells[i], m_botData[sender].mapData.map.getMapId(), false, false, fightersAlias);

            if(test.path.size() > 0 && test.path.size()-1 <= movementPoints && (path.isEmpty() || ((path.size() > test.path.size() && getDistance(test.path.last(), cibleID) == distance) || getDistance(test.path.last(), cibleID) > distance)))
            {
                bool isOk = true;

                foreach(uint pathCell, test.path)
                {
                    if(getDistance(pathCell, cibleID) < getDistance(cellID, cibleID))
                    {
                        isOk = false;
                    }
                }

                if(isOk)
                {
                    distance = getDistance(test.path.last(), cibleID);
                    path = test.path;
                }
            }
        }

        if(path.isEmpty())
        {
            qDebug()<<"MOVE AWAY REFUSED";
            return false;
        }

        moveToCell(sender, path);

        qDebug()<<"MOVE AWAY SEND"<<path;

        return true;
    }

    qDebug()<<"MOVE AWAY REFUSED";
    return false;
}

bool FightModule::moveToRange(SocketIO *sender, int spellID, int cellID, bool moveOnlyIfDistancePossible)
{
    QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
    int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];
    QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));

    QSharedPointer<WeaponData> weaponData;

    if(spellLevelID == 0)
    {
        foreach(const InventoryObject &item, m_botData[sender].playerData.inventoryContent)
        {
            if(item.position == CharacterInventoryPositionEnum::ACCESSORY_POSITION_WEAPON)
            {
                weaponData = qSharedPointerCast<WeaponData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMS, item.GID));
                break;
            }
        }
    }

    int distanceToTarget = getDistance(m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId, cellID);
    qDebug()<<"DistanceToTarget"<<distanceToTarget<<m_botData[sender].fightData.fighters[m_botData[sender].fightData.botFightData.botId].cellId<<cellID;
    int minRange = (spellLevelID != 0) ? (int)spellLevelData->getMinRange() : weaponData->getMinRange();

    if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
    {
        minRange *= 2;
    }

    if (minRange <= 0)
    {
        minRange = 1;
    }

    int maxRange = (spellLevelID != 0) ? (int)(spellLevelData->getRange() + (spellLevelData->getRangeCanBeBoosted() ? m_botData[sender].playerData.stats.range.objectsAndMountBonus : 0)) : spellLevelData->getRange();

    if ((spellLevelID != 0 && spellLevelData->getCastInDiagonal()) || (weaponData != NULL && weaponData->getCastInDiagonal()))
    {
        maxRange = (maxRange * 2);
    }

    if (maxRange <= 0)
    {
        maxRange = 1;
    }

    if(getSpellType(sender, spellID) == SpellType::SUMMON)
    {
        minRange++;
        maxRange++;
    }

    qDebug()<<"CONSIDERING"<<minRange<<maxRange;

    if (distanceToTarget < minRange)
    {
        return moveAway(sender, cellID, minRange, moveOnlyIfDistancePossible);
    }

    else if (distanceToTarget > maxRange)
    {
        return moveNear(sender, cellID, maxRange, moveOnlyIfDistancePossible);
    }
}

Point2D FightModule::getCoordsbyCellID(int cellID)
{
    return m_cellsPos[cellID];
}

int FightModule::getCellIDFromCoords(Point2D coords)
{
    return m_cellsId[coords];
}

int FightModule::getDistance(Point2D source, Point2D destination)
{
    return qAbs(source.x - destination.x) + qAbs(source.y - destination.y);
}

int FightModule::getDistance(int sourceCellID, int destinationCellID)
{
    return getDistance(getCoordsbyCellID(sourceCellID), getCoordsbyCellID(destinationCellID));
}

QMap<int, int> FightModule::getSuddenDamage(SocketIO *sender, int spellID, int cellID)
{
    int elementSpell = -1;
    QList<int> origineDamageMin;
    QList<int> origineDamageMax;
    int puissance = 0;
    int characteristic = 0;
    int fixedDamageBonus = 0;
    QMap<int, int> globalDamage;
    int fixedResistance = 0;
    int resistancePercent = 0;
    QMap<int, int> suddenDamage;

    foreach(const Spell &spell, m_botData[sender].playerData.spells)
    {
        if(spell.spellID == spellID)
        {
            QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spell.spellID));
            foreach(uint spellLevel, spellData->m_spellLevels)
            {
                if(spell.spellLevel == spellLevel)
                {
                    QSharedPointer<SpellLevelData> m_spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellData->m_id));
                    foreach(EffectInstanceDiceData effect, m_spellLevelData->m_effects)
                    {
                        origineDamageMin.append(effect.m_diceNum);
                        origineDamageMax.append(effect.m_diceSide);
                        puissance = m_botData[sender].playerData.stats.damagesBonusPercent.base + m_botData[sender].playerData.stats.damagesBonusPercent.additionnal + m_botData[sender].playerData.stats.damagesBonusPercent.contextModif + m_botData[sender].playerData.stats.damagesBonusPercent.alignGiftBonus + m_botData[sender].playerData.stats.damagesBonusPercent.objectsAndMountBonus;

                        if(D2OManagerSingleton::get()->getI18N()->getText(spellData->m_descriptionId).contains("dommages Feu"))
                        {
                            characteristic = m_botData[sender].playerData.stats.intelligence.base + m_botData[sender].playerData.stats.intelligence.additionnal + m_botData[sender].playerData.stats.intelligence.contextModif + m_botData[sender].playerData.stats.intelligence.alignGiftBonus + m_botData[sender].playerData.stats.intelligence.objectsAndMountBonus;
                            fixedDamageBonus = m_botData[sender].playerData.stats.allDamagesBonus.base + m_botData[sender].playerData.stats.allDamagesBonus.additionnal + m_botData[sender].playerData.stats.allDamagesBonus.contextModif + m_botData[sender].playerData.stats.allDamagesBonus.alignGiftBonus + m_botData[sender].playerData.stats.allDamagesBonus.objectsAndMountBonus + m_botData[sender].playerData.stats.fireDamageBonus.base + m_botData[sender].playerData.stats.fireDamageBonus.additionnal + m_botData[sender].playerData.stats.fireDamageBonus.contextModif + m_botData[sender].playerData.stats.fireDamageBonus.alignGiftBonus + m_botData[sender].playerData.stats.fireDamageBonus.objectsAndMountBonus;
                            elementSpell = 0;
                        }

                        else if(D2OManagerSingleton::get()->getI18N()->getText(spellData->m_descriptionId).contains("dommages Air"))
                        {
                            characteristic = m_botData[sender].playerData.stats.agility.base + m_botData[sender].playerData.stats.agility.additionnal + m_botData[sender].playerData.stats.agility.contextModif + m_botData[sender].playerData.stats.agility.alignGiftBonus + m_botData[sender].playerData.stats.agility.objectsAndMountBonus;
                            fixedDamageBonus = m_botData[sender].playerData.stats.allDamagesBonus.base + m_botData[sender].playerData.stats.allDamagesBonus.additionnal + m_botData[sender].playerData.stats.allDamagesBonus.contextModif + m_botData[sender].playerData.stats.allDamagesBonus.alignGiftBonus + m_botData[sender].playerData.stats.allDamagesBonus.objectsAndMountBonus + m_botData[sender].playerData.stats.airDamageBonus.base + m_botData[sender].playerData.stats.airDamageBonus.additionnal + m_botData[sender].playerData.stats.airDamageBonus.contextModif + m_botData[sender].playerData.stats.airDamageBonus.alignGiftBonus + m_botData[sender].playerData.stats.airDamageBonus.objectsAndMountBonus;
                            elementSpell = 1;
                        }

                        else if(D2OManagerSingleton::get()->getI18N()->getText(spellData->m_descriptionId).contains("dommages Terre"))
                        {
                            characteristic = m_botData[sender].playerData.stats.strength.base + m_botData[sender].playerData.stats.strength.additionnal + m_botData[sender].playerData.stats.strength.contextModif + m_botData[sender].playerData.stats.strength.alignGiftBonus + m_botData[sender].playerData.stats.strength.objectsAndMountBonus;
                            fixedDamageBonus = m_botData[sender].playerData.stats.allDamagesBonus.base + m_botData[sender].playerData.stats.allDamagesBonus.additionnal + m_botData[sender].playerData.stats.allDamagesBonus.contextModif + m_botData[sender].playerData.stats.allDamagesBonus.alignGiftBonus + m_botData[sender].playerData.stats.allDamagesBonus.objectsAndMountBonus + m_botData[sender].playerData.stats.earthDamageBonus.base + m_botData[sender].playerData.stats.earthDamageBonus.additionnal + m_botData[sender].playerData.stats.earthDamageBonus.contextModif + m_botData[sender].playerData.stats.earthDamageBonus.alignGiftBonus + m_botData[sender].playerData.stats.earthDamageBonus.objectsAndMountBonus;
                            elementSpell = 2;
                        }

                        else if(D2OManagerSingleton::get()->getI18N()->getText(spellData->m_descriptionId).contains("dommages Eau"))
                        {
                            characteristic = m_botData[sender].playerData.stats.chance.base + m_botData[sender].playerData.stats.chance.additionnal + m_botData[sender].playerData.stats.chance.contextModif + m_botData[sender].playerData.stats.chance.alignGiftBonus + m_botData[sender].playerData.stats.chance.objectsAndMountBonus;
                            fixedDamageBonus = m_botData[sender].playerData.stats.allDamagesBonus.base + m_botData[sender].playerData.stats.allDamagesBonus.additionnal + m_botData[sender].playerData.stats.allDamagesBonus.contextModif + m_botData[sender].playerData.stats.allDamagesBonus.alignGiftBonus + m_botData[sender].playerData.stats.allDamagesBonus.objectsAndMountBonus + m_botData[sender].playerData.stats.waterDamageBonus.base + m_botData[sender].playerData.stats.waterDamageBonus.additionnal + m_botData[sender].playerData.stats.waterDamageBonus.contextModif + m_botData[sender].playerData.stats.waterDamageBonus.alignGiftBonus + m_botData[sender].playerData.stats.waterDamageBonus.objectsAndMountBonus;
                            elementSpell = 3;
                        }

                        for(int i = 0; i < origineDamageMin.size(); i++)
                        {
                            // Dégâts totaux = dégâts de base + dégâts de base * ((Puissance + caractéristique) / 100) + bonus aux dégâts fixe.
                            globalDamage.insert(origineDamageMin.at(i) + origineDamageMin.at(i) * ((puissance + characteristic) / 100) + fixedDamageBonus, origineDamageMax.at(i) + origineDamageMax.at(i) * ((puissance + characteristic) / 100) + fixedDamageBonus);
                        }
                    }
                }
            }
        }
    }


    foreach(const FightEntityInfos &fighter, m_botData[sender].fightData.fighters)
    {
        if(fighter.cellId == cellID && fighter.isAlive)
        {
            switch (elementSpell)
            {
            case 0: // Feu
            {
                fixedResistance = fighter.stats.fireElementReduction;
                resistancePercent = fighter.stats.fireElementResistPercent;
            }
                break;
            case 1: // Air
            {
                fixedResistance = fighter.stats.airElementReduction;
                resistancePercent = fighter.stats.airElementResistPercent;
            }
                break;
            case 2: // Terre
            {
                fixedResistance = fighter.stats.earthElementReduction;
                resistancePercent = fighter.stats.earthElementResistPercent;
            }
                break;
            case 3: // Eau
            {
                fixedResistance = fighter.stats.waterElementReduction;
                resistancePercent = fighter.stats.waterElementResistPercent;
            }
                break;
            }
            break;
        }
    }

    for(int i = 0; i < globalDamage.size(); i++)
    {
        // Dégâts subis =dégâts totaux - résistance fixe - (dégâts totaux / 100/pourcentage de résistance)
        suddenDamage.insert(globalDamage.keys().at(i) - fixedResistance - (globalDamage.keys().at(i) / 100 / resistancePercent), globalDamage.values().at(i) - fixedResistance - (globalDamage.values().at(i) / 100 / resistancePercent));
    }

    return suddenDamage;
}

SpellType FightModule::getSpellType(SocketIO *sender, int spellID)
{
    QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spellID));
    int spellLevelID = spellData->getSpellLevels()[m_botData[sender].playerData.spells[spellID].spellLevel-1];
    QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellLevelID));
    int effectID = spellLevelData->getEffects().first().getEffectId();

    switch(effectID)
    {
    default:
        return SpellType::UNKOWN;
        break;

    case 181:
    case 180:
        return SpellType::SUMMON;

    case 81:
    case 108:
    case 1109:
    case 90:
        return SpellType::HEAL;

    case 1012:
    case 1013:
    case 1014:
    case 1015:
    case 1016:
    case 1067:
    case 1068:
    case 1069:
    case 1070:
    case 1071:
        return SpellType::ATTACK;

    case 110:
    case 111:
    case 112:
    case 115:
    case 117:
    case 118:
    case 119:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 128:
    case 136:
    case 137:
    case 138:
    case 142:
    case 158:
    case 160:
    case 161:
    case 752:
    case 753:
    case 165:
    case 174:
    case 176:
    case 178:
    case 182:
    case 183:
    case 184:
    case 210:
    case 211:
    case 212:
    case 213:
    case 214:
    case 225:
    case 226:
    case 240:
    case 241:
    case 242:
    case 243:
    case 244:
    case 250:
    case 251:
    case 252:
    case 253:
    case 254:
    case 260:
    case 261:
    case 262:
    case 263:
    case 264:
    case 1039:
    case 1040:
    case 514:
    case 281:
    case 282:
    case 283:
    case 284:
    case 285:
    case 286:
    case 287:
    case 288:
    case 289:
    case 290:
    case 291:
    case 292:
    case 293:
    case 414:
    case 750:
    case 751:
    case 776:
    case 1076:
    case 1077:
    case 1078:
        return SpellType::BOOST;
    }
}

QList<MonsterGroup> FightModule::getMonstersToFight(SocketIO *sender)
{
    // TODO: Reprogram monsters
    QList<MonsterGroup> groups;

    if(m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY && !m_botData[sender].mapData.monsterGroupsOnMap.isEmpty())
    {
        groups = m_botData[sender].mapData.monsterGroupsOnMap.values();

        for(int i = 0; i < m_botData[sender].mapData.monsterGroupsOnMap.values().size(); i++)
        {
            bool isOk = true;

            // Check level monster group
            if(m_botData[sender].fightData.requestedMonsters.groupLevelMax != INVALID && m_botData[sender].fightData.requestedMonsters.groupLevelMin != INVALID)
            {
                if(m_botData[sender].mapData.monsterGroupsOnMap.values()[i].level > m_botData[sender].fightData.requestedMonsters.groupLevelMax || m_botData[sender].mapData.monsterGroupsOnMap.values()[i].level < m_botData[sender].fightData.requestedMonsters.groupLevelMin)
                {
                    groups.removeAt(i);
                    continue;
                }
            }

            // Check nbr monster in the group
            if(m_botData[sender].fightData.requestedMonsters.mnNbMonsters != INVALID && m_botData[sender].fightData.requestedMonsters.mxNbMonsters != INVALID)
            {
                if(m_botData[sender].mapData.monsterGroupsOnMap.values()[i].monsters.size() > m_botData[sender].fightData.requestedMonsters.mxNbMonsters || m_botData[sender].mapData.monsterGroupsOnMap.values()[i].monsters.size() < m_botData[sender].fightData.requestedMonsters.mnNbMonsters)
                {
                    groups.removeAt(i);
                    continue;
                }
            }

            // Check monsters forbidden or mandatory
            if(!m_botData[sender].fightData.requestedMonsters.monsterConditions.isEmpty())
            {
                foreach(Monster monster, m_botData[sender].mapData.monsterGroupsOnMap.values()[i].monsters)
                {
                    foreach(MonsterCondition condition, m_botData[sender].fightData.requestedMonsters.monsterConditions)
                    {
                        if(condition.id == monster.id && condition.monsterInclusion == MonsterInclusion::ALL_EXCEPT)
                        {
                            groups.removeAt(i);
                            continue;
                        }
                    }
                }

                bool find = false;
                foreach(Monster monster, m_botData[sender].mapData.monsterGroupsOnMap.values()[i].monsters)
                {
                    foreach(MonsterCondition condition, m_botData[sender].fightData.requestedMonsters.monsterConditions)
                    {
                        if(condition.id == monster.id && condition.monsterInclusion == MonsterInclusion::NONE_EXCEPT)
                        {
                            find=true;
                            break;
                        }
                    }

                    if(find)
                        break;
                }

                if(!find)
                {
                    groups.removeAt(i);
                    continue;
                }
            }
        }
    }

    return groups;
}

bool FightModule::isMonstersToFight(SocketIO *sender)
{
    return !getMonstersToFight(sender).isEmpty();
}

bool FightModule::isSummon(SocketIO *sender, double ennemie)
{
    QMapIterator<double, FightEntityInfos> module(m_botData[sender].fightData.fighters);
    while (module.hasNext())
    {
        module.next();
        if(module.key() == ennemie && module.value().stats.summoned)
            return true;
    }

    return false;
}

bool FightModule::processMonsters(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].scriptData.activeModule == getType())
    {
        QList<MonsterGroup> groups = getMonstersToFight(sender);

        if(!groups.isEmpty())
        {
            for(int i = 0; i < groups.size(); i++)
            {
                if(getDistance(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId, groups[i].cellID) <= 1 || m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == groups[i].cellID)
                {
                    GameRolePlayAttackMonsterRequestMessage answer;
                    answer.monsterGroupId = groups[i].contextualID;
                    sender->send(answer);
                    return true;
                }

                else if(m_mapModule->changeToNearestCell(sender, groups[i].cellID))
                {
                    QString des;
                    foreach(Monster m, groups[i].monsters)
                    {
                        QSharedPointer<MonsterData> monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, m.id));
                        des += " "+monsterData->getName();
                    }

                    action(sender)<<"Deplacement vers un groupe de monstre"+des;
                    m_botData[sender].fightData.followingMonsterGroup = groups[i].contextualID;
                    return true;
                }
            }
        }

        else
        {

        }
    }

    return false;
}

void FightModule::processEndFight(SocketIO *sender)
{
    if(m_botData[sender].generalData.botState == FIGHTING_STATE && m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        m_botData[sender].generalData.botState = INACTIVE_STATE;

        if(m_botData[sender].fightData.hasWon)
            qDebug()<<"Fin du combat - Victoire";

        else
            qDebug()<<"Fin du combat - Défaite";

        if(m_botData[sender].scriptData.isActive && m_botData[sender].scriptData.activeModule == getType())
        {
            if(m_botData[sender].fightData.hasWon && isMonstersToFight(sender))
            {
                qDebug()<<"FightModule - Il reste des monstres à combattre sur cette carte X:" <<m_botData[sender].mapData.map.getPosition().getX()<<" Y:" <<m_botData[sender].mapData.map.getPosition().getY();

                emit scriptActionRepeat(sender);
            }

            else
            {
                if(!m_botData[sender].fightData.hasWon)
                {
                    qDebug()<<"FightModule - Plus de monstres à combattre sur cette carte X:" <<m_botData[sender].mapData.map.getPosition().getX()<<" Y:" <<m_botData[sender].mapData.map.getPosition().getY();
                }

                 QTimer::singleShot(500, this, [this, sender] () { emit scriptActionDone(sender); });

                //emit scriptActionDone(sender);
            }
        }
    }
}

void FightModule::moveSuccess(SocketIO *sender)
{
    if(m_botData[sender].fightData.followingMonsterGroup != INVALID && m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId == m_botData[sender].mapData.monsterGroupsOnMap[m_botData[sender].fightData.followingMonsterGroup].cellID)
    {
        GameRolePlayAttackMonsterRequestMessage answer;
        answer.monsterGroupId = m_botData[sender].fightData.followingMonsterGroup;
        sender->send(answer);
        m_botData[sender].fightData.followingMonsterGroup = 0;
    }

    else if(m_botData[sender].fightData.followingMonsterGroup != INVALID)
    {
        if(!processMonsters(sender) && m_botData[sender].scriptData.activeModule == getType())
        {
            emit scriptActionDone(sender);
        }
    }
}

void FightModule::moveFailure(SocketIO *sender)
{
    m_botData[sender].fightData.followingMonsterGroup = 0;
}
