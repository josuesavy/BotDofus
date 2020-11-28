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
            switch((PlayerStatusEnum)psumsg.status->statusId)
            {
            case PlayerStatusEnum::PLAYER_STATUS_AVAILABLE:
                info(sender) << "Statut disponible activé.";
                break;

            case PlayerStatusEnum::PLAYER_STATUS_AFK:
                info(sender) << "Statut absent activé.";
                break;

            case PlayerStatusEnum::PLAYER_STATUS_PRIVATE:
                info(sender) << "Statut privé activé.";
                break;

            case PlayerStatusEnum::PLAYER_STATUS_SOLO:
                info(sender) << "Statut solo activé.";
                break;
            }
        }
    }
        break;
    }

    return messageFound;
}
