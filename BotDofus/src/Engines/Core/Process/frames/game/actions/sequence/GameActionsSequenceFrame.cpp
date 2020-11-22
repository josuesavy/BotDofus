#include "GameActionsSequenceFrame.h"

GameActionsSequenceFrame::GameActionsSequenceFrame(QMap<SocketIO *, BotData> *connectionsData, FightManager *fightManager):
    AbstractFrame(ModuleType::CONNECTION, connectionsData),
    m_fightManager(fightManager)
{

}

void GameActionsSequenceFrame::reset(SocketIO *sender)
{
    m_botData[sender].connectionData.connectionState = ConnectionState::DISCONNECTED;
}

bool GameActionsSequenceFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::SEQUENCEENDMESSAGE:
    {
        SequenceEndMessage message;
        message.deserialize(&reader);

        if(message.authorId == m_botData[sender].fightData.botFightData.botId)
        {
            GameActionAcknowledgementMessage answer;
            answer.valid = true;
            answer.actionId = message.actionId;
            sender->send(answer);

            m_fightManager->processTurn(sender);
        }
    }
        break;

    case MessageEnum::SEQUENCESTARTMESSAGE:
        break;
    }

    return messageFound;
}
