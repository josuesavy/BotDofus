#include "GameContextRoleplayFightFrame.h"

GameContextRoleplayFightFrame::GameContextRoleplayFightFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayFightFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayFightFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE:
    {
        GameRolePlayPlayerFightFriendlyAnsweredMessage message;
        message.deserialize(&reader);

        if(message.accept)
            info(sender) << "Défi de" << m_botData[sender].mapData.playersOnMap[message.sourceId].name << "accepté.";

        else
            info(sender) << "Défi de" << m_botData[sender].mapData.playersOnMap[message.sourceId].name << "refusé.";
    }
        break;

    case MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE:
    {
        GameRolePlayPlayerFightFriendlyRequestedMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].mapData.playersOnMap[message.sourceId].name == m_botData[sender].groupData.master)
        {
            warn(sender)<<m_botData[sender].groupData.master<<"(chef) vous défi !";
            action(sender) << "Acceptation du défi..";

            GameRolePlayPlayerFightFriendlyAnswerMessage answer;
            answer.accept = true;
            answer.fightId = message.fightId;
            sender->send(answer);
        }

        else
        {
            warn(sender)<<m_botData[sender].mapData.playersOnMap[message.sourceId].name << "vous défi !";
            action(sender) << "Refus du défi..";

            GameRolePlayPlayerFightFriendlyAnswerMessage answer;
            answer.accept = false;
            answer.fightId = message.fightId;
            sender->send(answer);
        }
    }
        break;
    }

    return messageFound;
}
