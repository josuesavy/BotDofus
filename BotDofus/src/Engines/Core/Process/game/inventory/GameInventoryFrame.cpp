#include "GameInventoryFrame.h"

GameInventoryFrame::GameInventoryFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameInventoryFrame::reset(SocketIO *sender)
{

}

bool GameInventoryFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::KAMASUPDATEMESSAGE:
    {
        KamasUpdateMessage message;
        message.deserialize(&reader);
        m_botData[sender].playerData.kamas = message.kamasTotal;

        m_botData[sender].statisticsData.countTotalKamas += message.kamasTotal;

        info(sender) << "Vous avez gagné" << message.kamasTotal << "kamas.";
    }
        break;
    }

    return messageFound;
}
