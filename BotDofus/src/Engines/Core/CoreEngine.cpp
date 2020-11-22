#include "CoreEngine.h"

CoreEngine::CoreEngine()
{
    QTime t;
    t.start();

    m_managers[ModuleType::MAP] = new MapManager(&m_botData));
    m_managers.append(ModuleType::ARENA, new ArenaManager(&m_botData));
    m_managers.append(ModuleType::CONNECTION, new ConnectionManager(&m_botData));
    m_managers.append(ModuleType::FARM, new FarmManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_managers.append(ModuleType::CRAFT, new CraftManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_managers.append(ModuleType::GROUP, new GroupManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_managers.append(ModuleType::FIGHT, new FightManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]), static_cast<ArenaManager*>(m_managers[ModuleType::ARENA])));
    m_managers.append(ModuleType::SECURITY, new SecurityManager(&m_botData));
    m_managers.append(ModuleType::STATS, new StatsManager(&m_botData));
    m_managers.append(ModuleType::INTERACTION, new InteractionManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_managers.append(ModuleType::EXCHANGE, new ExchangeManager(&m_botData));
    m_managers.append(ModuleType::FLOOD, new FloodManager(&m_botData));


    m_frames.append(new CommonBasicFrame(&m_botData));
    m_frames.append(new ConnectionFrame(&m_botData));
    m_frames.append(new ConnectionRegisterFrame(&m_botData));
    m_frames.append(new AchievementFrame(&m_botData));
    m_frames.append(new GameActionsFrame(&m_botData));
    m_frames.append(new GameActionsFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameActionsSequenceFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameAllianceFrame(&m_botData));
    m_frames.append(new GameAlmanachFrame(&m_botData));
    m_frames.append(new GameApproachFrame(&m_botData));
    m_frames.append(new GameAtlasCompassFrame(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_frames.append(new GameBasicFrame(&m_botData));
    m_frames.append(new GameCharacterChoiceFrame(&m_botData, static_cast<GroupManager*>(m_managers[ModuleType::GROUP])));
    m_frames.append(new GameCharacterCreationFrame(&m_botData));
    m_frames.append(new GameCharacterDeletionFrame(&m_botData));
    m_frames.append(new GameCharacterStatsFrame(&m_botData, static_cast<StatsManager*>(m_managers[ModuleType::STATS])));
    m_frames.append(new GameCharacterStatusFrame(&m_botData));
    m_frames.append(new GameChatFrame(&m_botData));
    m_frames.append(new GameContextFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameContextFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameContextFightCharacterFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT]), static_cast<GroupManager*>(m_managers[ModuleType::GROUP])));
    m_frames.append(new GameContextMountFrame(&m_botData));
    m_frames.append(new GameContextNotificationFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFrame(&m_botData, static_cast<FloodManager*>(m_managers[ModuleType::FLOOD])));
    m_frames.append(new GameContextRoleplayDeathFrame(&m_botData, static_cast<StatsManager*>(m_managers[ModuleType::STATS])));
    m_frames.append(new GameContextRoleplayFightFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFightArenaFrame(&m_botData));
    m_frames.append(new GameContextRoleplayJobFrame(&m_botData));
    m_frames.append(new GameContextRoleplayNpcFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION])));
    m_frames.append(new GameContextRoleplayObjectsFrame(&m_botData));
    m_frames.append(new GameContextRoleplayPartyFrame(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_frames.append(new GameContextRoleplayQuestFrame(&m_botData));
    m_frames.append(new GameContextRoleplayStatsFrame(&m_botData, static_cast<StatsManager*>(m_managers[ModuleType::STATS])));
    m_frames.append(new GameDialogFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION])));
    m_frames.append(new GameFriendFrame(&m_botData));
    m_frames.append(new GameGuildFrame(&m_botData));
    m_frames.append(new GameInitializationFrame(&m_botData, static_cast<GroupManager*>(m_managers[ModuleType::GROUP])));
    m_frames.append(new GameInteractiveFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION]), static_cast<FarmManager*>(m_managers[ModuleType::FARM])));
    m_frames.append(new GameInteractiveZaapFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION])));
    m_frames.append(new GameInventoryFrame(&m_botData));
    m_frames.append(new GameInventoryExchangesFrame(&m_botData, static_cast<CraftManager*>(m_managers[ModuleType::CRAFT]), static_cast<ExchangeManager*>(m_managers[ModuleType::EXCHANGE])));
    m_frames.append(new GameInventoryItemsFrame(&m_botData, static_cast<ExchangeManager*>(m_managers[ModuleType::EXCHANGE]), static_cast<StatsManager*>(m_managers[ModuleType::STATS])));
    m_frames.append(new GameInventorySpellsFrame(&m_botData));
    m_frames.append(new GameInventoryStorageFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION])));
    m_frames.append(new GameModerationFrame(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_frames.append(new GameSubscriberFrame(&m_botData));
    m_frames.append(new HandshakeFrame(&m_botData));
    m_frames.append(new QueueFrame(&m_botData));
    m_frames.append(new SecureFrame(&m_botData));
    m_frames.append(new SecurityFrame(&m_botData));
    m_frames.append(new ServerBasicFrame(&m_botData));
    m_frames.append(new SubscriptionFrame(&m_botData));
    m_frames.append(new WebAnkaboxFrame(&m_botData));

    qDebug()<<"[CoreEngine] Initialized ! ("<<t.elapsed()<<"ms)";
}

CoreEngine::~CoreEngine()
{
    foreach(AbstractFrame *frame, m_frames)
    {
        delete frame;
    }
}

const BotData &CoreEngine::getData(SocketIO *sender)
{
    return m_botData[sender];
}
