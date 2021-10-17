#ifndef JOBMETHODS_H
#define JOBMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"

class JobMethods : public DataHandler
{
public:
    static int level(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int id = lua_tointeger(L, 1);

        // process
        int level = INVALID;
        foreach(const JobExperience &e, m_botData[sender].craftData.jobs)
        {
            if(e.jobLevel != 1 && (qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor)))) != 0 && e.jobId == id)
            {
                level = e.jobLevel;
                break;
            }
        }

        // return the result
        lua_pushinteger(L, level);

        return 1;
    }

    static int name(lua_State *L, SocketIO *sender)
    {
        // get parameters
        int id = lua_tointeger(L, 1);

        // process
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

        // return the result
        lua_pushinteger(L, name);

        return 1;
    }
};

#endif // JOBMETHODS_H
