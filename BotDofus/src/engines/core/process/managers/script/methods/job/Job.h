#ifndef JOB_H
#define JOB_H

#include "src/engines/core/CoreEngine.h"

class Job: public CoreEngine
{
public:
    int level(SocketIO *sender, int id)
    {
        int level = INVALID;
        foreach(const JobExperience &e, m_botData[sender].craftData.jobs)
        {
            if(e.jobLevel != 1 && (qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor)))) != 0 && e.jobId == id)
            {
                level = e.jobLevel;
                break;
            }
        }
        return level;
    }

    QString name(SocketIO *sender, int id)
    {
        QString name;
        foreach(const JobExperience &e, m_botData[sender].craftData.jobs)
        {
            if(e.jobLevel != 1 && (qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor)))) != 0 && e.jobId == id)
            {
                QSharedPointer<JobData> jobData = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, e.jobId));
                name = jobData->getName();
                break;
            }
        }
        return name;
    }
};

#endif // JOB_H
