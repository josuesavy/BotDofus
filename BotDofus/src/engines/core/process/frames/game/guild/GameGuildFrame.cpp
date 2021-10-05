#include "GameGuildFrame.h"

GameGuildFrame::GameGuildFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameGuildFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GUILDMOTDMESSAGE:
    {
        GuildMotdMessage message;
        message.deserialize(&reader);

        log(sender, CHANNELGUILD) << "Annonce de guilde :" << message.content;
    }
        break;
    }

    return messageFound;
}
