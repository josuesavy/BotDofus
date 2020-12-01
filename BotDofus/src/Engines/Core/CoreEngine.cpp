#include "CoreEngine.h"

CoreEngine::CoreEngine()
{
    QTime t;
    t.start();

    m_managers[ManagerType::MAP] = new MapManager(&m_botData);
    m_managers[ManagerType::STATS] = new StatsManager(&m_botData);
    m_managers[ManagerType::FLOOD] = new FloodManager(&m_botData);
    m_managers[ManagerType::EXCHANGE] = new ExchangeManager(&m_botData);
    m_managers[ManagerType::CONNECTION] = new ConnectionManager(&m_botData);
    m_managers[ManagerType::INTERACTION] = new InteractionManager(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]));
    m_managers[ManagerType::GROUP] = new GroupManager(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]));
    m_managers[ManagerType::FIGHT] = new FightManager(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]), static_cast<GroupManager*>(m_managers[ManagerType::GROUP]), static_cast<ArenaManager*>(m_managers[ManagerType::ARENA]));
    m_managers[ManagerType::FARM] = new FarmManager(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]));
    m_managers[ManagerType::CRAFT] = new CraftManager(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]));
    m_managers[ManagerType::ARENA] = new ArenaManager(&m_botData);
    m_managers[ManagerType::SECURITY] = new SecurityManager(&m_botData);


    m_frames.append(new CommonBasicFrame(&m_botData));
    m_frames.append(new ConnectionFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ManagerType::CONNECTION])));
    m_frames.append(new ConnectionRegisterFrame(&m_botData));
    m_frames.append(new ConnectionSearchFrame(&m_botData));
    m_frames.append(new AchievementFrame(&m_botData));
    m_frames.append(new GameActionsFrame(&m_botData));
    m_frames.append(new GameActionsFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT])));
    m_frames.append(new GameActionsSequenceFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT])));
    m_frames.append(new GameAllianceFrame(&m_botData));
    m_frames.append(new GameAlmanachFrame(&m_botData));
    m_frames.append(new GameApproachFrame(&m_botData));
    m_frames.append(new GameAtlasCompassFrame(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP])));
    m_frames.append(new GameBasicFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ManagerType::CONNECTION])));
    m_frames.append(new GameCharacterChoiceFrame(&m_botData, static_cast<ConnectionManager*>(m_managers[ManagerType::CONNECTION]), static_cast<GroupManager*>(m_managers[ManagerType::GROUP])));
    m_frames.append(new GameCharacterCreationFrame(&m_botData));
    m_frames.append(new GameCharacterDeletionFrame(&m_botData));
    m_frames.append(new GameCharacterStatsFrame(&m_botData, static_cast<StatsManager*>(m_managers[ManagerType::STATS])));
    m_frames.append(new GameCharacterStatusFrame(&m_botData));
    m_frames.append(new GameChatFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT])));
    m_frames.append(new GameContextFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT]), static_cast<MapManager*>(m_managers[ManagerType::MAP])));
    m_frames.append(new GameContextFightFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT])));
    m_frames.append(new GameContextFightCharacterFrame(&m_botData, static_cast<FightManager*>(m_managers[ManagerType::FIGHT]), static_cast<GroupManager*>(m_managers[ManagerType::GROUP])));
    m_frames.append(new GameContextMountFrame(&m_botData));
    m_frames.append(new GameContextNotificationFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFrame(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP]), static_cast<FloodManager*>(m_managers[ManagerType::FLOOD])));
    m_frames.append(new GameContextRoleplayDeathFrame(&m_botData, static_cast<StatsManager*>(m_managers[ManagerType::STATS])));
    m_frames.append(new GameContextRoleplayEmoteFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFightFrame(&m_botData));
    m_frames.append(new GameContextRoleplayFightArenaFrame(&m_botData));
    m_frames.append(new GameContextRoleplayJobFrame(&m_botData));
    m_frames.append(new GameContextRoleplayNpcFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION])));
    m_frames.append(new GameContextRoleplayObjectsFrame(&m_botData));
    m_frames.append(new GameContextRoleplayPartyFrame(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP])));
    m_frames.append(new GameContextRoleplayQuestFrame(&m_botData));
    m_frames.append(new GameContextRoleplayStatsFrame(&m_botData, static_cast<StatsManager*>(m_managers[ManagerType::STATS])));
    m_frames.append(new GameDialogFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION])));
    m_frames.append(new GameFriendFrame(&m_botData));
    m_frames.append(new GameGuildFrame(&m_botData));
    m_frames.append(new GameInitializationFrame(&m_botData, static_cast<GroupManager*>(m_managers[ManagerType::GROUP])));
    m_frames.append(new GameInteractiveFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION]), static_cast<FarmManager*>(m_managers[ManagerType::FARM])));
    m_frames.append(new GameInteractiveZaapFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION])));
    m_frames.append(new GameInventoryFrame(&m_botData));
    m_frames.append(new GameInventoryExchangesFrame(&m_botData, static_cast<CraftManager*>(m_managers[ManagerType::CRAFT]), static_cast<ExchangeManager*>(m_managers[ManagerType::EXCHANGE])));
    m_frames.append(new GameInventoryItemsFrame(&m_botData, static_cast<ExchangeManager*>(m_managers[ManagerType::EXCHANGE]), static_cast<StatsManager*>(m_managers[ManagerType::STATS])));
    m_frames.append(new GameInventorySpellsFrame(&m_botData));
    m_frames.append(new GameInventoryStorageFrame(&m_botData, static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION])));
    m_frames.append(new GameModerationFrame(&m_botData, static_cast<MapManager*>(m_managers[ManagerType::MAP])));
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
    QMapIterator<ManagerType, AbstractManager*> manager(m_managers);
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
    return *static_cast<MapManager*>(m_managers[ManagerType::MAP]);
}

FloodManager &CoreEngine::getFloodManager()
{
    return *static_cast<FloodManager*>(m_managers[ManagerType::FLOOD]);
}

FightManager &CoreEngine::getFightManager()
{
    return *static_cast<FightManager*>(m_managers[ManagerType::FIGHT]);
}

FarmManager &CoreEngine::getFarmManager()
{
    return *static_cast<FarmManager*>(m_managers[ManagerType::FARM]);
}

ConnectionManager &CoreEngine::getConnectionManager()
{
    return *static_cast<ConnectionManager*>(m_managers[ManagerType::CONNECTION]);
}

StatsManager &CoreEngine::getStatsManager()
{
    return *static_cast<StatsManager*>(m_managers[ManagerType::STATS]);
}

ExchangeManager &CoreEngine::getExchangeManager()
{
    return *static_cast<ExchangeManager*>(m_managers[ManagerType::EXCHANGE]);
}

GroupManager &CoreEngine::getGroupManager()
{
    return *static_cast<GroupManager*>(m_managers[ManagerType::GROUP]);
}

CraftManager &CoreEngine::getCraftManager()
{
    return *static_cast<CraftManager*>(m_managers[ManagerType::CRAFT]);
}

InteractionManager &CoreEngine::getInteractionManager()
{
    return *static_cast<InteractionManager*>(m_managers[ManagerType::INTERACTION]);
}

SecurityManager &CoreEngine::getSecurityManager()
{
    return *static_cast<SecurityManager*>(m_managers[ManagerType::SECURITY]);
}

const BotData &CoreEngine::getData(SocketIO *sender)
{
    return m_botData[sender];
}
