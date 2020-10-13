#include "GroupModule.h"

GroupModule::GroupModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule):
    AbstractModule(ModuleType::GROUP, connectionsData),
    m_mapModule(mapModule)
{
    connect(m_mapModule, SIGNAL(mapContentUpdated(SocketIO*)), this, SLOT(followUpUpdate(SocketIO*)));
    connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(followUpFailure(SocketIO*)));
}

void GroupModule::reset(SocketIO *sender)
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

bool GroupModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::CHARACTERSELECTEDFORCEMESSAGE:
    case MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE:
        if(!m_botData[sender].connectionData.connectionInfos.masterGroup.isEmpty())
            updateTeams();
        break;

    case MessageEnum::PARTYINVITATIONMESSAGE:
    {
        PartyInvitationMessage message;
        message.deserialize(&reader);

        if((PartyTypeEnum)message.partyType == PartyTypeEnum::PARTY_TYPE_CLASSICAL)
        {
            info(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.playerInvitation").replace("%1", message.fromName);

            m_botData[sender].groupData.currentInvitations[message.partyId] = message.fromName;

            if(message.fromName == m_botData[sender].groupData.master)
            {
                action(sender) << "Acceptation de l'invitation...";

                m_botData[sender].groupData.currentInvitations.remove(message.partyId);
                m_botData[sender].groupData.masterId = message.fromId;
                m_botData[sender].groupData.partyId = message.partyId;
                m_botData[sender].groupData.isInGroup = true;

                PartyAcceptInvitationMessage answer;
                answer.partyId = message.partyId;
                sender->send(answer);
            }

            else
            {
                action(sender) << "Refus de l'invitation...";

                m_botData[sender].groupData.currentInvitations.remove(message.partyId);

                PartyRefuseInvitationMessage answer;
                answer.partyId = message.partyId;
                sender->send(answer);
            }
        }
    }
        break;

    case MessageEnum::PARTYINVITATIONCANCELLEDFORGUESTMESSAGE:
    {
        PartyInvitationCancelledForGuestMessage message;
        message.deserialize(&reader);

        if(!m_botData[sender].groupData.currentInvitations.value(message.partyId).isEmpty())
        {
            action(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.invitationCancelledForGuest").replace("%1", m_botData[sender].groupData.currentInvitations.value(message.partyId));

            m_botData[sender].groupData.currentInvitations.remove(message.partyId);
        }
    }
        break;

    case MessageEnum::PARTYJOINMESSAGE:
    {
        PartyJoinMessage message;
        message.deserialize(&reader);

        if((PartyTypeEnum)message.partyType == PartyTypeEnum::PARTY_TYPE_CLASSICAL)
        {
            QString masterName;

            foreach(QSharedPointer<PartyMemberInformations> member, message.members)
            {
                if(member->entities.size() > 0)
                {
                    foreach(QSharedPointer<PartyEntityBaseInformation> companion, member->entities)
                    {
                        QSharedPointer<CompanionData> companionData = qSharedPointerCast<CompanionData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::COMPANIONS, companion->entityModelId));
                        m_botData[sender].groupData.members[companion->entityModelId] = companionData->getName();
                    }
                }

                if(member->id == message.partyLeaderId)
                    masterName = member->name;

                m_botData[sender].groupData.members[member->id] = member->name;
            }

            if(!m_botData[sender].groupData.members.contains(m_botData[sender].mapData.botId))
                info(sender)<<"Vous avez rejoint le groupe de "<<masterName<<".";

            m_botData[sender].groupData.masterId = message.partyLeaderId;
            m_botData[sender].groupData.partyId = message.partyId;
            m_botData[sender].groupData.isInGroup = true;

            if(!m_botData[sender].groupData.master.isEmpty() && masterName != m_botData[sender].groupData.master)
            {
                PartyLeaveRequestMessage answer;
                answer.partyId = message.partyId;
                sender->send(answer);
            }

            else if(m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY && m_botData[sender].mapData.map.isInit() && m_botData[sender].mapData.botId != m_botData[sender].groupData.masterId)
            {
                action(sender) << "Demande de suivre le chef...";

                PartyFollowMemberRequestMessage answer;
                answer.partyId = message.partyId;
                answer.playerId = message.partyLeaderId;
                sender->send(answer);
            }
        }
    }
        break;

    case MessageEnum::PARTYUPDATEMESSAGE:
    {
        PartyUpdateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId && m_botData[sender].groupData.masterId == message.memberInformations->id)
        {
            if(message.memberInformations->mapId)
            {
                Map map = D2PManagerSingleton::get()->getMap(message.memberInformations->mapId);

                m_botData[sender].groupData.masterPosition.x = map.getPosition().getX();
                m_botData[sender].groupData.masterPosition.y = map.getPosition().getY();
            }

            else
            {
                m_botData[sender].groupData.masterPosition.x = m_botData[sender].mapData.map.getPosition().getX();
                m_botData[sender].groupData.masterPosition.y = m_botData[sender].mapData.map.getPosition().getY();

                if(m_botData[sender].groupData.hasRequestedFollowUp)
                {
                    PartyStopFollowRequestMessage answer;
                    answer.partyId = m_botData[sender].groupData.partyId;
                    sender->send(answer);
                }
            }
        }
    }
        break;

    case MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE:
    {
        PartyFollowStatusUpdateMessage message;
        message.deserialize(&reader);

        if(message.partyId == m_botData[sender].groupData.partyId && message.followedId == 0 && m_botData[sender].groupData.hasRequestedFollowUp)
        {
            m_botData[sender].groupData.hasRequestedFollowUp = false;
            PartyFollowMemberRequestMessage answer;
            answer.partyId = message.partyId;
            answer.playerId = m_botData[sender].groupData.masterId;
            sender->send(answer);
        }

        else if(message.partyId == m_botData[sender].groupData.partyId && message.followedId == m_botData[sender].groupData.masterId)
            m_botData[sender].groupData.hasRequestedFollowUp = true;

        else if(message.partyId == m_botData[sender].groupData.partyId && message.followedId != 0)
        {
            m_botData[sender].groupData.masterPosition.x = m_botData[sender].mapData.map.getPosition().getX();
            m_botData[sender].groupData.masterPosition.y = m_botData[sender].mapData.map.getPosition().getY();

            PartyStopFollowRequestMessage answer;
            answer.partyId = m_botData[sender].groupData.partyId;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::PARTYNEWMEMBERMESSAGE:
    {
        PartyNewMemberMessage message;
        message.deserialize(&reader);

        info(sender) << message.memberInformations->name << "a rejoint votre groupe.";

        m_botData[sender].groupData.isInGroup = true;

        if(m_botData[sender].groupData.partyId == message.partyId)
            m_botData[sender].groupData.members[message.memberInformations->id] = message.memberInformations->name;
    }
        break;

    case MessageEnum::PARTYMEMBEREJECTEDMESSAGE:
    case MessageEnum::PARTYMEMBERREMOVEMESSAGE:
    {
        PartyMemberRemoveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.members.contains(message.leavingPlayerId))
            m_botData[sender].groupData.members.remove(message.leavingPlayerId);

        if(message.leavingPlayerId == m_botData[sender].groupData.masterId && message.partyId == m_botData[sender].groupData.partyId)
        {
            PartyLeaveRequestMessage answer;
            answer.partyId = m_botData[sender].groupData.partyId;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::PARTYDELETEDMESSAGE:
    {
        PartyDeletedMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            warn(sender)<<"Votre groupe a été détruit";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = 0;
            m_botData[sender].groupData.masterId = 0;
            m_botData[sender].groupData.isInGroup = false;

            if(m_botData[sender].groupData.isFollowing && (m_botData[sender].generalData.botState == MOVING_STATE || m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }
        break;

    case MessageEnum::PARTYKICKEDBYMESSAGE:
    {
        PartyKickedByMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            warn(sender)<<"Vous avez été exclu du groupe";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = 0;
            m_botData[sender].groupData.masterId = 0;
            m_botData[sender].groupData.isInGroup = false;


            if(m_botData[sender].groupData.isFollowing && (m_botData[sender].generalData.botState == MOVING_STATE || m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }
        break;

    case MessageEnum::PARTYLEAVEMESSAGE:
    {
        PartyLeaveMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].groupData.partyId == message.partyId)
        {
            warn(sender)<<"Vous avez quitté le groupe car le chef configuré n'est plus/pas présent";

            m_botData[sender].groupData.members.clear();
            m_botData[sender].groupData.partyId = INVALID;
            m_botData[sender].groupData.masterId = INVALID;
            m_botData[sender].groupData.isInGroup = false;
            m_botData[sender].groupData.masterPosition.x = INVALID;
            m_botData[sender].groupData.masterPosition.y = INVALID;

            if(m_botData[sender].groupData.isFollowing && (m_botData[sender].generalData.botState == MOVING_STATE || m_botData[sender].generalData.botState == CALCULATING_STATE))
                m_mapModule->stopMoving(sender);
        }
    }
        break;

    case MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE:
    {
        CompassUpdatePartyMemberMessage message;
        message.deserialize(&reader);

        if(message.memberId == m_botData[sender].groupData.masterId)
        {
            m_botData[sender].groupData.masterPosition.x = message.coords->worldX;
            m_botData[sender].groupData.masterPosition.y = message.coords->worldY;

            if(m_botData[sender].groupData.followUp)
            {
                QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
                QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

                int mapId = PathfindingMap::coordsToMapId(message.coords->worldX, message.coords->worldY, area->getSuperAreaId());

                m_mapModule->stopMoving(sender);
                m_mapModule->changeMap(sender, mapId);
                m_botData[sender].groupData.isFollowing = true;
            }
        }
    }
        break;

    case MessageEnum::PARTYUPDATELIGHTMESSAGE:
        break;

    case MessageEnum::PARTYCANNOTJOINERRORMESSAGE:
    {
        PartyCannotJoinErrorMessage message;
        message.deserialize(&reader);

        switch((PartyJoinErrorEnum)message.reason)
        {
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PARTY_FULL:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.partyFull");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PARTY_NOT_FOUND:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.cantFindParty");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PLAYER_BUSY:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.cantInvitPlayerBusy");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PLAYER_NOT_FOUND:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.common.playerNotFound").replace("%1", m_botData[sender].groupData.playerNameInvited);
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_UNMET_CRITERION:
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PLAYER_LOYAL:
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PLAYER_TOO_SOLLICITED:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.playerTooSollicited");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_UNMODIFIABLE:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.partyUnmodifiable");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_PLAYER_ALREADY_INVITED:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.playerAlreayBeingInvited");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_NOT_ENOUGH_ROOM:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.notEnoughRoom");
            break;
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_COMPOSITION_CHANGED:
        case PartyJoinErrorEnum::PARTY_JOIN_ERROR_UNKNOWN:
        default:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.cantInvit");
            break;
        }
    }
        break;

    case MessageEnum::PARTYNAMESETERRORMESSAGE:
    {
        PartyNameSetErrorMessage message;
        message.deserialize(&reader);

        switch((PartyNameErrorEnum)message.result)
        {
        case PartyNameErrorEnum::PARTY_NAME_UNDEFINED_ERROR:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.nameError");
            break;
        case PartyNameErrorEnum::PARTY_NAME_INVALID:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.nameInvalid");
            break;
        case PartyNameErrorEnum::PARTY_NAME_ALREADY_USED:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.nameAlreadyUsed");
            break;
        case PartyNameErrorEnum::PARTY_NAME_UNALLOWED_RIGHTS:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.nameUnallowedRights");
            break;
        case PartyNameErrorEnum::PARTY_NAME_UNALLOWED_NOW:
            error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.party.nameUnallowedNow");
            break;
        }
    }
        break;
    }

    return messageFound;
}

void GroupModule::setFollowUpEnabled(SocketIO *sender, bool followUp)
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
        m_mapModule->stopMoving(sender);
        m_botData[sender].groupData.isFollowing = false;
    }

    if(followUp && m_botData[sender].groupData.isInGroup && m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.hasRequestedFollowUp)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x,  m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapModule->stopMoving(sender);
        m_mapModule->changeMap(sender, mapId);
        m_botData[sender].groupData.isFollowing = true;
    }
}

void GroupModule::setMaster(SocketIO *sender, const QString &master)
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

SocketIO* GroupModule::getMaster(SocketIO *sender)
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

QList<SocketIO*> GroupModule::getSlaves(SocketIO *sender)
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

bool GroupModule::isGroupOnMapAndInactive(SocketIO *master)
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

void GroupModule::updateTeams()
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

                PartyInvitationRequestMessage answer;
                answer.name = m_botData[slave].connectionData.connectionInfos.character;
                i.key()->send(answer);
            }
        }
    }
    StartupActionsListMessage a;
}

void GroupModule::teleportSlavesToMaster(SocketIO *sender, const QString master)
{
    if(m_botData[sender].connectionData.connectionState == ConnectionState::CONNECTED)
    {
        action(sender) << "Demande de rejoindre le chef";

        FriendJoinRequestMessage answer;
        answer.name = master;
        sender->send(answer);
    }
}

void GroupModule::followUpUpdate(SocketIO *sender)
{
    if((m_botData[sender].mapData.map.getPosition().getX() == m_botData[sender].groupData.masterPosition.x && m_botData[sender].mapData.map.getPosition().getY() == m_botData[sender].groupData.masterPosition.y) || !m_botData[sender].groupData.isInGroup)
        m_botData[sender].groupData.isFollowing = false;


    else if(m_botData[sender].groupData.isInGroup && (m_botData[sender].groupData.masterPosition.x != m_botData[sender].mapData.map.getPosition().getX() || m_botData[sender].groupData.masterPosition.y != m_botData[sender].mapData.map.getPosition().getY()) &&  m_botData[sender].generalData.botState == INACTIVE_STATE && m_botData[sender].groupData.followUp && !m_botData[sender].groupData.isFollowing && m_botData[sender].groupData.hasRequestedFollowUp && m_botData[sender].mapData.gameContext == GameContextEnum::ROLE_PLAY)
    {
        QSharedPointer<SubAreaData> subArea = qSharedPointerCast<SubAreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SUBAREAS, m_botData[sender].mapData.map.getSubAreaId()));
        QSharedPointer<AreaData> area = qSharedPointerCast<AreaData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::AREAS, subArea->getAreaId()));

        int mapId = PathfindingMap::coordsToMapId(m_botData[sender].groupData.masterPosition.x, m_botData[sender].groupData.masterPosition.y, area->getSuperAreaId());

        m_mapModule->stopMoving(sender);
        m_mapModule->changeMap(sender, mapId);
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

void GroupModule::followUpFailure(SocketIO *sender)
{
    m_botData[sender].groupData.isFollowing = false;
}
