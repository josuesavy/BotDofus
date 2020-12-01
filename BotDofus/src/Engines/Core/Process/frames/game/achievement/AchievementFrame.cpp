#include "AchievementFrame.h"

AchievementFrame::AchievementFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool AchievementFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::ACHIEVEMENTFINISHEDMESSAGE:
    {
        AchievementFinishedMessage message;
        message.deserialize(&reader);

        info(sender) << "Succès déverrouillé :<b>[" << qSharedPointerCast<AchievementData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ACHIEVEMENTS, message.achievement->id))->getName() << "]</b>";

        m_botData[sender].statisticsData.countTotalNotValidatedAchievement += 1;

        if(m_botData[sender].playerData.automaticallyAcceptAchievement)
        {
            AchievementRewardRequestMessage answer;
            answer.achievementId = -1;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::ACHIEVEMENTLISTMESSAGE:
    {
        AchievementListMessage message;
        message.deserialize(&reader);

        for(int i = 0; i < message.finishedAchievements.size(); i++)
        {
            if(message.finishedAchievements.at(i)->getTypes().contains(ClassEnum::ACHIEVEMENTACHIEVEDREWARDABLE))
            {
                m_botData[sender].statisticsData.countTotalNotValidatedAchievement += 1;
            }
        }

        if(m_botData[sender].playerData.automaticallyAcceptAchievement)
        {
            AchievementRewardRequestMessage answer;
            answer.achievementId = -1;
            sender->send(answer);
        }
    }
        break;

    case MessageEnum::ACHIEVEMENTREWARDERRORMESSAGE:
        break;

    case MessageEnum::ACHIEVEMENTREWARDSUCCESSMESSAGE:
    {
        AchievementRewardSuccessMessage message;
        message.deserialize(&reader);

        m_botData[sender].statisticsData.countTotalNotValidatedAchievement -= 1;
        m_botData[sender].statisticsData.countTotalValidatedAchievement += 1;

        info(sender) << "Succès :<b>[" << qSharedPointerCast<AchievementData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ACHIEVEMENTS, message.achievementId))->getName() << "]</b> accepté.";
    }
        break;
    }

    return messageFound;
}
