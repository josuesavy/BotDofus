#include "CoreEngine.h"

CoreEngine::CoreEngine()
{
    QTime t;
    t.start();

    m_managers[ModuleType::MAP] = new MapManager(&m_botData);
    m_managers[ModuleType::STATS] = new StatsManager(&m_botData);
    m_managers[ModuleType::FLOOD] = new FloodManager(&m_botData);
    m_managers[ModuleType::EXCHANGE] = new ExchangeManager(&m_botData);
    m_managers[ModuleType::CONNECTION] = new ConnectionManager(&m_botData);
    m_managers[ModuleType::INTERACTION] = new InteractionManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]));
    m_managers[ModuleType::GROUP] = new GroupManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]));
    m_managers[ModuleType::FIGHT] = new FightManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]), static_cast<GroupManager*>(m_managers[ModuleType::GROUP]), static_cast<ArenaManager*>(m_managers[ModuleType::ARENA]));
    m_managers[ModuleType::FARM] = new FarmManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]));
    m_managers[ModuleType::CRAFT] = new CraftManager(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]));
    m_managers[ModuleType::ARENA] = new ArenaManager(&m_botData);
    m_managers[ModuleType::SECURITY] = new SecurityManager(&m_botData);


    m_frames.append(new CommonBasicFrame(&m_botData));
    m_frames.append(new ConnectionFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ModuleType::CONNECTION])));
    m_frames.append(new ConnectionRegisterFrame(&m_botData));
    m_frames.append(new AchievementFrame(&m_botData));
    m_frames.append(new GameActionsFrame(&m_botData));
    m_frames.append(new GameActionsFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameActionsSequenceFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameAllianceFrame(&m_botData));
    m_frames.append(new GameAlmanachFrame(&m_botData));
    m_frames.append(new GameApproachFrame(&m_botData));
    m_frames.append(new GameAtlasCompassFrame(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_frames.append(new GameBasicFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ModuleType::CONNECTION])));
    m_frames.append(new GameCharacterChoiceFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ModuleType::CONNECTION]), static_cast<GroupManager*>(m_managers[ModuleType::GROUP])));
    m_frames.append(new GameCharacterCreationFrame(&m_botData));
    m_frames.append(new GameCharacterDeletionFrame(&m_botData));
    m_frames.append(new GameCharacterStatsFrame(&m_botData, static_cast<StatsManager*>(m_managers[ModuleType::STATS])));
    m_frames.append(new GameCharacterStatusFrame(&m_botData));
    m_frames.append(new GameChatFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameContextFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT]), static_cast<MapManager*>(m_managers[ModuleType::MAP])));
    m_frames.append(new GameContextFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT])));
    m_frames.append(new GameContextFightCharacterFrame(&m_botData, static_cast<FightManager*>(m_managers[ModuleType::FIGHT]), static_cast<GroupManager*>(m_managers[ModuleType::GROUP])));
    m_frames.append(new GameContextMountFrame(&m_botData));
    m_frames.append(new GameContextNotificationFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFrame(&m_botData, static_cast<MapManager*>(m_managers[ModuleType::MAP]), static_cast<FloodManager*>(m_managers[ModuleType::FLOOD])));
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
    QMapIterator<ModuleType, AbstractManager*> manager(m_managers);
    while (manager.hasNext())
    {
        manager.next();
        delete manager.value();
    }

    foreach(AbstractFrame *frame, m_frames)
    {
        delete frame;
    }
}

MapManager &CoreEngine::getMapManager()
{
    return *static_cast<MapManager*>(m_managers[ModuleType::MAP]);
}

FloodManager &CoreEngine::getFloodManager()
{
    return *static_cast<FloodManager*>(m_managers[ModuleType::FLOOD]);
}

FightManager &CoreEngine::getFightManager()
{
    return *static_cast<FightManager*>(m_managers[ModuleType::FIGHT]);
}

FarmManager &CoreEngine::getFarmManager()
{
    return *static_cast<FarmManager*>(m_managers[ModuleType::FARM]);
}

ConnectionManager &CoreEngine::getConnectionManager()
{
    return *static_cast<ConnectionManager*>(m_managers[ModuleType::CONNECTION]);
}

StatsManager &CoreEngine::getStatsManager()
{
    return *static_cast<StatsManager*>(m_managers[ModuleType::STATS]);
}

ExchangeManager &CoreEngine::getExchangeManager()
{
    return *static_cast<ExchangeManager*>(m_managers[ModuleType::EXCHANGE]);
}

GroupManager &CoreEngine::getGroupManager()
{
    return *static_cast<GroupManager*>(m_managers[ModuleType::GROUP]);
}

CraftManager &CoreEngine::getCraftManager()
{
    return *static_cast<CraftManager*>(m_managers[ModuleType::CRAFT]);
}

InteractionManager &CoreEngine::getInteractionManager()
{
    return *static_cast<InteractionManager*>(m_managers[ModuleType::INTERACTION]);
}

SecurityManager &CoreEngine::getSecurityManager()
{
    return *static_cast<SecurityManager*>(m_managers[ModuleType::SECURITY]);
}

const BotData &CoreEngine::getData(SocketIO *sender)
{
    return m_botData[sender];
}
