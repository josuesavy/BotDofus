#include "GameAllianceFrame.h"

GameAllianceFrame::GameAllianceFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameAllianceFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool GameAllianceFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ALLIANCEMOTDMESSAGE:
    {
        AllianceMotdMessage message;
        message.deserialize(&reader);

        log(sender, CHANNELALLIANCE) << "Annonce d'Alliance :" << message.content;
    }
        break;
    }

    return messageFound;
}
