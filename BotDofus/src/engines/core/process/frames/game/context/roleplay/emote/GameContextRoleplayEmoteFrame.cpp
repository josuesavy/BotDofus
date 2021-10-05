#include "GameContextRoleplayEmoteFrame.h"

GameContextRoleplayEmoteFrame::GameContextRoleplayEmoteFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameContextRoleplayEmoteFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::EMOTEPLAYERRORMESSAGE:
    {
        EmotePlayErrorMessage message;
        message.deserialize(&reader);

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.common.cantUseEmote");
    }
        break;
    }

    return messageFound;
}
