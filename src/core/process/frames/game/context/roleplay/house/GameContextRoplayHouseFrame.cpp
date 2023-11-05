#include "GameContextRoplayHouseFrame.h"

GameContextRoplayHouseFrame::GameContextRoplayHouseFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameContextRoplayHouseFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::HOUSEPROPERTIESMESSAGE:
    {
        HousePropertiesMessage message;
        message.deserialize(&reader);

        HouseInfos houseInfos;
        houseInfos.houseId = message.houseId;
        houseInfos.doorsOnMap = message.doorsOnMap;
        houseInfos.properties = message.properties;

        m_botData[sender].mapData.housesOnMap[message.houseId] = houseInfos;
    }
        break;
    }

    return messageFound;
}
