#include "GameAtlasCompassFrame.h"

GameAtlasCompassFrame::GameAtlasCompassFrame(QMap<SocketIO *, BotData> *connectionsData, MapManager *mapManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_mapManager(mapManager)
{

}

void GameAtlasCompassFrame::reset(SocketIO *sender)
{

}

bool GameAtlasCompassFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::COMPASSRESETMESSAGE:
        break;

    case MessageEnum::COMPASSUPDATEMESSAGE:
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

                m_mapManager->stopMoving(sender);
                m_mapManager->changeMap(sender, mapId);
                m_botData[sender].groupData.isFollowing = true;
            }
        }
    }
        break;

    case MessageEnum::COMPASSUPDATEPVPSEEKMESSAGE:
        break;
    }

    return messageFound;
}
