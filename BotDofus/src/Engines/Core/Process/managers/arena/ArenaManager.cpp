#include "ArenaManager.h"

ArenaManager::ArenaManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::ARENA, connectionsData)
{

}

void ArenaManager::reset(SocketIO *sender)
{
    m_botData[sender].arenaData.arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_UNREGISTER;
    m_botData[sender].arenaData.arenaTypeFight = INVALID;
    m_botData[sender].arenaData.isArenaRegistered = false;
    m_botData[sender].arenaData.arenaAlliesIds.clear();
    m_botData[sender].arenaData.arenaReadyPartyMemberIds.clear();
}

bool ArenaManager::processArena(SocketIO *sender, PvpArenaTypeEnum fightTypeId)
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

void ArenaManager::arenaRegister(SocketIO *sender, PvpArenaTypeEnum fightTypeId)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        GameRolePlayArenaRegisterMessage message;
        message.battleMode = (uint)fightTypeId;
        sender->send(message);

        action(sender) << "Inscription au Kolizéum...";
    }
}

void ArenaManager::arenaUnregister(SocketIO *sender)
{
    if (m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        GameRolePlayArenaUnregisterMessage message;
        sender->send(message);
        action(sender) << "Désinscription au Kolizéum...";
    }
}

void ArenaManager::arenaFightAnswer(SocketIO *sender, PvpArenaTypeEnum fightTypeId, bool accept)
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
