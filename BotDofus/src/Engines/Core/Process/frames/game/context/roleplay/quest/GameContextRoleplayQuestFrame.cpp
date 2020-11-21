#include "GameContextRoleplayQuestFrame.h"

GameContextRoleplayQuestFrame::GameContextRoleplayQuestFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(ModuleType::CONNECTION, connectionsData)
{

}

void GameContextRoleplayQuestFrame::reset(SocketIO *sender)
{

}

bool GameContextRoleplayQuestFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::QUESTSTARTEDMESSAGE:
    {
        QuestStartedMessage message;
        message.deserialize(&reader);

        m_botData[sender].statisticsData.countTotalNewQuest += 1;
        info(sender) << "Nouvelle quête : [" << qSharedPointerCast<QuestData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::QUESTS, message.questId))->getName() << "]";
    }
        break;
    case MessageEnum::QUESTVALIDATEDMESSAGE:
    {
        QuestStepValidatedMessage message;
        message.deserialize(&reader);

        m_botData[sender].statisticsData.countTotalValidatedQuest += 1;
        info(sender) << "Quête terminée : [" << qSharedPointerCast<QuestData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::QUESTS, message.questId))->getName() << "]";
    }
        break;
    }

    return messageFound;
}
