#include "GameCharacterStatusFrame.h"

GameCharacterStatusFrame::GameCharacterStatusFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameCharacterStatusFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::PLAYERSTATUSUPDATEMESSAGE:
    {
        PlayerStatusUpdateMessage psumsg;
        psumsg.deserialize(&reader);

        if(psumsg.accountId == m_botData[sender].playerData.accountId)
        {
            QString status;

            switch((PlayerStatusEnum)psumsg.status->statusId)
            {
            case PlayerStatusEnum::PLAYER_STATUS_AVAILABLE:
                status = D2OManagerSingleton::get()->getI18N()->getText("ui.chat.status.availiable");
                break;

            case PlayerStatusEnum::PLAYER_STATUS_AFK:
                status = D2OManagerSingleton::get()->getI18N()->getText("ui.chat.status.away");
                break;

            case PlayerStatusEnum::PLAYER_STATUS_PRIVATE:
                status = D2OManagerSingleton::get()->getI18N()->getText("ui.chat.status.private");
                break;

            case PlayerStatusEnum::PLAYER_STATUS_SOLO:
                status = D2OManagerSingleton::get()->getI18N()->getText("ui.chat.status.solo");
                break;
            }

            info(sender) << D2OManagerSingleton::get()->getI18N()->getText("ui.chat.status.statuschange").arg(status);
        }
    }
        break;
    }

    return messageFound;
}
