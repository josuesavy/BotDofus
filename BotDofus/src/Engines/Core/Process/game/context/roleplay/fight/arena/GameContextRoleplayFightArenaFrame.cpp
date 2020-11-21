#include "GameContextRoleplayFightArenaFrame.h"

GameContextRoleplayFightArenaFrame::GameContextRoleplayFightArenaFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayFightArenaFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayFightArenaFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
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
