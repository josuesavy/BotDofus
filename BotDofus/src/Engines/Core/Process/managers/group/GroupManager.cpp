#include "GroupManager.h"

GroupManager::GroupManager(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager):
    AbstractManager(ManagerType::MAP, connectionsData),
    m_mapManager(mapManager)
{
    connect(m_mapManager, SIGNAL(mapContentUpdated(SocketIO*)), this, SLOT(followUpUpdate(SocketIO*)));
    connect(m_mapManager, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(followUpFailure(SocketIO*)));
}

void GroupManager::reset(SocketIO *sender)
{
    m_botData[sender].groupData.isInGroup = false;
    m_botData[sender].groupData.masterId = INVALID;
    m_botData[sender].groupData.partyId = INVALID;
    m_botData[sender].groupData.isFollowing = false;
    m_botData[sender].groupData.hasRequestedFollowUp = false;
    m_botData[sender].groupData.masterPosition.x = INVALID;
    m_botData[sender].groupData.masterPosition.y = INVALID;
    m_botData[sender].groupData.members.clear();
}

void GroupManager::setFollowUpEnabled(SocketIO *sender, bool followUp)
{
    m_botData[sender].groupData.followUp = followUp;

    if(!m_botData[sender].groupData.hasRequestedFollowUp && followUp && m_botData[sender].groupData.isInGroup)
    {
        PartyFollowMemberRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        answer.playerId = m_botData[sender].groupData.masterId;
        sender->send(answer);
    }

    if (!followUp && m_botData[sender].groupData.isFollowing)
    {
        m_mapManager->stopMoving(sender);
        m_botData[sender].groupData.isFollowing = false;
    }

    if(followUp && m_botData[sender].groupData.isInGroup && m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.hasRequestedFollowUp)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x,  m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapManager->stopMoving(sender);
        m_mapManager->changeMap(sender, mapId);
        m_botData[sender].groupData.isFollowing = true;
    }
}

void GroupManager::setMaster(SocketIO *sender, const QString &master)
{
    m_botData[sender].groupData.master = master;

    if(!master.isEmpty() && m_botData[sender].groupData.isInGroup)
    {
        PartyLeaveRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        sender->send(answer);
    }

    updateTeams();
}

SocketIO* GroupManager::getMaster(SocketIO *sender)
{
    QMapIterator<SocketIO*, BotData>i(m_botData);

    while(i.hasNext())
    {
        i.next();
        if(m_botData[sender].connectionData.connectionInfos.character != i.value().connectionData.connectionInfos.character &&
                m_botData[sender].connectionData.connectionInfos.serverId == i.value().connectionData.connectionInfos.serverId &&
                m_botData[sender].groupData.master == i.value().connectionData.connectionInfos.character &&
                m_botData[sender].connectionData.connectionInfos.masterGroup == i.value().connectionData.connectionInfos.character)
            return i.key();
    }

    return NULL;
}

QList<SocketIO*> GroupManager::getSlaves(SocketIO *sender)
{
    QList<SocketIO*> slaves;

    foreach(SocketIO *slave, m_botData.keys())
    {
        if(m_botData[slave].connectionData.connectionState == ConnectionState::CONNECTED &&
                m_botData[sender].connectionData.connectionInfos.serverId == m_botData[slave].connectionData.connectionInfos.serverId &&
                m_botData[slave].groupData.master == m_botData[sender].connectionData.connectionInfos.character &&
                m_botData[slave].groupData.master != m_botData[slave].connectionData.connectionInfos.character &&
                !m_botData[slave].connectionData.connectionInfos.masterGroup.isEmpty())
            slaves<<slave;
    }

    return slaves;
}

bool GroupManager::isGroupOnMapAndInactive(SocketIO *master)
{
    QList<SocketIO*> slaves = getSlaves(master);


    if(m_botData[master].generalData.botState == INACTIVE_STATE)
    {
        foreach(SocketIO *slave, slaves)
        {
            if(m_botData[master].mapData.map.getMapId() != m_botData[slave].mapData.map.getMapId() || m_botData[slave].generalData.botState != INACTIVE_STATE)
                return false;
        }
    }

    return true;
}

void GroupManager::updateTeams()
{
    QMapIterator<SocketIO*, BotData>i(m_botData);

    while(i.hasNext())
    {
        i.next();

        QList<SocketIO*> slaves = getSlaves(i.key());

        foreach(SocketIO *slave, slaves)
        {
            if(i.value().connectionData.connectionState == ConnectionState::CONNECTED && !i.value().groupData.members.values().contains(m_botData[slave].connectionData.connectionInfos.character) && i.key() == getMaster(slave))
            {
                action(i.key()) << "Invitation de" << m_botData[slave].connectionData.connectionInfos.character << "à rejoindre le groupe...";

                m_botData[i.key()].groupData.playerNameInvited = m_botData[slave].connectionData.connectionInfos.character;

                QSharedPointer<PlayerSearchCharacterNameInformation> playerSearchCharacterNameInformation;
                playerSearchCharacterNameInformation->name = m_botData[slave].connectionData.connectionInfos.character;

                PartyInvitationRequestMessage answer;
                answer.target = playerSearchCharacterNameInformation;
                i.key()->send(answer);
            }
        }
    }
    StartupActionsListMessage a;
}

void GroupManager::teleportSlavesToMaster(SocketIO *sender, const QString master)
{
    if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        action(sender) << "Demande de rejoindre le chef";

        QSharedPointer<PlayerSearchCharacterNameInformation> playerSearchCharacterNameInformation;
        playerSearchCharacterNameInformation->name = master;

        FriendJoinRequestMessage answer;
        answer.target = playerSearchCharacterNameInformation;
        sender->send(answer);
    }
}

void GroupManager::followUpUpdate(SocketIO *sender)
{
    if((m_botData[sender].mapData.map.getPosition().getX() == m_botData[sender].groupData.masterPosition.x && m_botData[sender].mapData.map.getPosition().getY() == m_botData[sender].groupData.masterPosition.y) || !m_botData[sender].groupData.isInGroup)
        m_botData[sender].groupData.isFollowing = false;


    else if(m_botData[sender].groupData.isInGroup && (m_botData[sender].groupData.masterPosition.x != m_botData[sender].mapData.map.getPosition().getX() || m_botData[sender].groupData.masterPosition.y != m_botData[sender].mapData.map.getPosition().getY()) &&  m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.followUp && !m_botData[sender].groupData.isFollowing && m_botData[sender].groupData.hasRequestedFollowUp && m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x, m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapManager->stopMoving(sender);
        m_mapManager->changeMap(sender, mapId);
        m_botData[sender].groupData.isFollowing = true;
    }

    else if(m_botData[sender].groupData.isInGroup && m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.followUp && !m_botData[sender].groupData.isFollowing && !m_botData[sender].groupData.hasRequestedFollowUp && m_botData[sender].mapData.map.isInit() && m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        PartyFollowMemberRequestMessage answer;
        answer.partyId = m_botData[sender].groupData.partyId;
        answer.playerId = m_botData[sender].groupData.masterId;
        sender->send(answer);
    }
}

void GroupManager::followUpFailure(SocketIO *sender)
{
    m_botData[sender].groupData.isFollowing = false;
}
