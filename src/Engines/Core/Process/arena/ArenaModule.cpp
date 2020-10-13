#include "ArenaModule.h"

ArenaModule::ArenaModule(QMap<SocketIO *, BotData> *connectionsData):
    AbstractModule(ModuleType::ARENA, connectionsData)
{

}

ArenaModule::~ArenaModule()
{

}

void ArenaModule::reset(SocketIO *sender)
{
    m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_UNREGISTER;
    m_botData[sender].arenaData.arenaTypeFight = INVALID;
    m_botData[sender].arenaData.isArenaRegistered = false;
    m_botData[sender].arenaData.arenaAlliesIds.clear();
    m_botData[sender].arenaData.arenaReadyPartyMemberIds.clear();
}

bool ArenaModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE:
    {
        GameRolePlayArenaRegistrationStatusMessage message;

        if(message.registered)
        {
            m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_REGISTRED;
            m_botData[sender].arenaData.isArenaRegistered = true;
        }

        else
        {
            m_botData[sender].arenaData.arenaCurrentStatus = (PvpArenaStepEnum)message.step;
            m_botData[sender].arenaData.isArenaRegistered = false;
        }
    }
        break;

    case MessageEnum::GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE:
    {
        GameRolePlayArenaFightPropositionMessage message;
        m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_WAITING_FIGHT;

        info(sender) << "Un combat a été trouvé.";

        foreach(double allyId, message.alliesId)
        {
            action(sender) << "\t->"<<allyId;

            m_botData[sender].arenaData.arenaAlliesIds.append(allyId);
        }
    }
        break;

    case MessageEnum::GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE:
    {
        GameRolePlayArenaFighterStatusMessage message;

        if(!message.accepted)
        {
            if(message.playerId == m_botData[sender].mapData.botId)
            {
                m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_UNREGISTER;
                m_botData[sender].arenaData.isArenaRegistered = false;
            }
            else
            {
                m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_REGISTRED;
            }

            m_botData[sender].arenaData.arenaReadyPartyMemberIds.clear();
            m_botData[sender].arenaData.arenaAlliesIds.clear();
        }
        else
        {
            m_botData[sender].arenaData.arenaReadyPartyMemberIds.append(message.playerId);
        }
    }
        break;

        // Utiliser pour alimenter l'ui des joueurs donc ça sert a rien pour le bot mais j'ai fait quand meme ptdr
    case MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE:
    {
        // TODO : En attente d'actualisation du Protocol Dofus2
        GameRolePlayArenaUpdatePlayerInfosMessage message;

        // ArenaRankSoloInfos
        if(message.solo.fightcount)
            m_botData[sender].arenaData.arenaRankSoloInfos.todayFightCount = message.solo.fightcount;

        if(message.solo.victoryCount)
            m_botData[sender].arenaData.arenaRankSoloInfos.todayVictoryCount = message.solo.victoryCount;

        if(message.solo.numFightNeededForLadder)
            m_botData[sender].arenaData.arenaRankSoloInfos.numFightNeededForLadder = message.solo.numFightNeededForLadder;

        if(message.solo.leagueRanking)
        {
            m_botData[sender].arenaData.arenaRankSoloInfos.rank = message.solo.leagueRanking->rank;
            m_botData[sender].arenaData.arenaRankSoloInfos.leagueId = message.solo.leagueRanking->leagueId;
            m_botData[sender].arenaData.arenaRankSoloInfos.leagueProgression = message.solo.leagueRanking->leaguePoints;
            m_botData[sender].arenaData.arenaRankSoloInfos.ladderPosition = message.solo.leagueRanking->ladderPosition;
            m_botData[sender].arenaData.arenaRankSoloInfos.totalLeaguePoint = message.solo.leagueRanking->totalLeaguePoints;
        }

        else if(message.solo.ranking)
        {
            m_botData[sender].arenaData.arenaRankSoloInfos.rank = message.solo.ranking->rank;
            m_botData[sender].arenaData.arenaRankSoloInfos.maxRank = message.solo.ranking->bestRank;
        }

        if(data.messageType == MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSALLQUEUESMESSAGE)
        {
            GameRolePlayArenaUpdatePlayerInfosAllQueuesMessage message;

            // ArenaRankDuelInfos
            if(message.team.fightcount)
                m_botData[sender].arenaData.arenaRankGroupInfos.todayFightCount = message.team.fightcount;

            if(message.team.victoryCount)
                m_botData[sender].arenaData.arenaRankGroupInfos.todayVictoryCount = message.team.victoryCount;

            if(message.team.numFightNeededForLadder)
                m_botData[sender].arenaData.arenaRankGroupInfos.numFightNeededForLadder = message.team.numFightNeededForLadder;

            if(message.team.leagueRanking)
            {
                m_botData[sender].arenaData.arenaRankGroupInfos.rank = message.team.leagueRanking->rank;
                m_botData[sender].arenaData.arenaRankGroupInfos.leagueId = message.team.leagueRanking->leagueId;
                m_botData[sender].arenaData.arenaRankGroupInfos.leagueProgression = message.team.leagueRanking->leaguePoints;
                m_botData[sender].arenaData.arenaRankGroupInfos.ladderPosition = message.team.leagueRanking->ladderPosition;
                m_botData[sender].arenaData.arenaRankGroupInfos.totalLeaguePoint = message.team.leagueRanking->totalLeaguePoints;
            }

            else if(message.team.ranking)
            {
                m_botData[sender].arenaData.arenaRankGroupInfos.rank = message.team.ranking->rank;
                m_botData[sender].arenaData.arenaRankGroupInfos.maxRank = message.team.ranking->bestRank;
            }


            // ArenaRankDuelInfos
            if(message.duel.fightcount)
                m_botData[sender].arenaData.arenaRankDuelInfos.todayFightCount = message.duel.fightcount;

            if(message.duel.victoryCount)
                m_botData[sender].arenaData.arenaRankDuelInfos.todayVictoryCount = message.duel.victoryCount;

            if(message.duel.numFightNeededForLadder)
                m_botData[sender].arenaData.arenaRankDuelInfos.numFightNeededForLadder = message.duel.numFightNeededForLadder;

            if(message.duel.leagueRanking)
            {
                m_botData[sender].arenaData.arenaRankDuelInfos.rank = message.duel.leagueRanking->rank;
                m_botData[sender].arenaData.arenaRankDuelInfos.leagueId = message.duel.leagueRanking->leagueId;
                m_botData[sender].arenaData.arenaRankDuelInfos.leagueProgression = message.duel.leagueRanking->leaguePoints;
                m_botData[sender].arenaData.arenaRankDuelInfos.ladderPosition = message.duel.leagueRanking->ladderPosition;
                m_botData[sender].arenaData.arenaRankDuelInfos.totalLeaguePoint = message.duel.leagueRanking->totalLeaguePoints;
            }

            else if(message.duel.ranking)
            {
                m_botData[sender].arenaData.arenaRankDuelInfos.rank = message.duel.ranking->rank;
                m_botData[sender].arenaData.arenaRankDuelInfos.maxRank = message.duel.ranking->bestRank;
            }

        }
    }
        break;
    }

    return messageFound;
}

bool ArenaModule::processArena(SocketIO *sender, PvpArenaTypeEnum fightTypeId)
{
    if(m_botData[sender].generalData.botState != BotState::INACTIVE_STATE || m_botData[sender].generalData.botState != BotState::REGENERATING_STATE)
        return false;

    if(m_botData[sender].arenaData.isArenaRegistered || m_botData[sender].arenaData.arenaCurrentStatus == PvpArenaStepEnum::ARENA_STEP_REGISTRED)
    {
        error(sender) << "Vous êtes déjà inscrit en Kolizéum.";
        return false;
    }

    else if(m_botData[sender].arenaData.arenaCurrentStatus == PvpArenaStepEnum::ARENA_STEP_WAITING_FIGHT)
    {
        error(sender) << "Vous êtes déjà inscrit en Kolizéum et vous avez un combat en attente...";
        return false;
    }

    if(fightTypeId == PvpArenaTypeEnum::ARENA_TYPE_3VS3_TEAM && !m_botData[sender].groupData.isInGroup)
    {
        error(sender) << "Vous n'avez pas de groupe.";
        return false;
    }

    if(fightTypeId == PvpArenaTypeEnum::ARENA_TYPE_3VS3_TEAM && m_botData[sender].groupData.isInGroup && m_botData[sender].groupData.masterId != m_botData[sender].mapData.botId)
    {
        error(sender) << "Vous n'êtes pas le chef du groupe.";
        return false;
    }

    if(fightTypeId == PvpArenaTypeEnum::ARENA_TYPE_1VS1 || fightTypeId == PvpArenaTypeEnum::ARENA_TYPE_3VS3_SOLO && m_botData[sender].groupData.isInGroup)
    {
        error(sender) << "Vous êtes dans un groupe.";
        return false;
    }

    arenaRegister(sender, fightTypeId);
    return true;
}

void ArenaModule::arenaRegister(SocketIO *sender, PvpArenaTypeEnum fightTypeId)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        GameRolePlayArenaRegisterMessage message;
        message.battleMode = (uint)fightTypeId;
        sender->send(message);

        action(sender) << "Inscription au Kolizéum...";
    }
}

void ArenaModule::arenaUnregister(SocketIO *sender)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        GameRolePlayArenaUnregisterMessage message;
        sender->send(message);
        action(sender) << "Désinscription au Kolizéum...";
    }
}

void ArenaModule::arenaFightAnswer(SocketIO *sender, PvpArenaTypeEnum fightTypeId, bool accept)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        GameRolePlayArenaFightAnswerMessage message;
        message.fightId = (uint)fightTypeId;
        message.accept = accept;
        sender->send(message);

        if(accept)
            action(sender) << "Vous avez accepté l'invitation au Kolizéum";
        else
            action(sender) << "Vous avez refusé l'invitation au Kolizéum";
    }
}
