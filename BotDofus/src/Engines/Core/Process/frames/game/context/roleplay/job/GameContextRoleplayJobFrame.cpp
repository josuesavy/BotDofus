#include "GameContextRoleplayJobFrame.h"

GameContextRoleplayJobFrame::GameContextRoleplayJobFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameContextRoleplayJobFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE:
    {
        JobExperienceMultiUpdateMessage message;
        message.deserialize(&reader);

        foreach(const JobExperience &e, message.experiencesUpdate)
            m_botData[sender].craftData.jobs[e.jobId] = e;
    }
        break;

    case MessageEnum::JOBEXPERIENCEUPDATEMESSAGE:
    {
        JobExperienceUpdateMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].statisticsData.countTotalExperienceJobs.contains(message.experiencesUpdate.jobId))
            m_botData[sender].statisticsData.countTotalExperienceJobs[message.experiencesUpdate.jobId] += message.experiencesUpdate.jobXP;
        else
            m_botData[sender].statisticsData.countTotalExperienceJobs.insert(message.experiencesUpdate.jobId, message.experiencesUpdate.jobXP);

        m_botData[sender].craftData.jobs[message.experiencesUpdate.jobId] = message.experiencesUpdate;
    }
        break;

    case MessageEnum::JOBLEVELUPMESSAGE:
    {
        JobLevelUpMessage message;
        message.deserialize(&reader);

        if(m_botData[sender].statisticsData.countTotalGetNewLevelJobs.contains(message.jobsDescription->jobId))
            m_botData[sender].statisticsData.countTotalGetNewLevelJobs[message.jobsDescription->jobId] += 1;
        else
            m_botData[sender].statisticsData.countTotalGetNewLevelJobs.insert(message.jobsDescription->jobId, 1);

        action(sender) << "Votre métier" << qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, message.jobsDescription->jobId))->getName() << "passe niveau" << message.newLevel;
        m_botData[sender].craftData.jobs[message.jobsDescription->jobId].jobLevel = message.newLevel;
    }
        break;
    }

    return messageFound;
}
