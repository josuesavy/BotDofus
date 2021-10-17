#ifndef CHARACTERMETHODS_H
#define CHARACTERMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"

class CharacterMethods : public DataHandler
{
public:
    static int breed(lua_State *L, SocketIO *sender)
    {
        int breed = m_botData[sender].playerData.breed;
        lua_pushinteger(L, breed);
        return 1;
    }

    static int name(lua_State *L, SocketIO *sender)
    {
        QString name = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].name;
        lua_pushstring(L, name.toStdString().c_str());
        return 1;
    }

    static int sex(lua_State *L, SocketIO *sender)
    {
        bool sex = m_botData[sender].playerData.sex;
        lua_pushboolean(L, sex);
        return 1;
    }

    static int level(lua_State *L, SocketIO *sender)
    {
        int level = m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].level;
        lua_pushinteger(L, level);
        return 1;
    }

    static int lifePoints(lua_State *L, SocketIO *sender)
    {
        int lifePoints = m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base;
        lua_pushinteger(L, lifePoints);
        return 1;
    }

    static int maxLifePoints(lua_State *L, SocketIO *sender)
    {
        int maxLifePoints = m_botData[sender].playerData.stats[(uint)StatIds::MAX_LIFE].base;
        lua_pushinteger(L, maxLifePoints);
        return 1;
    }

    static int lifePointsP(lua_State *L, SocketIO *sender)
    {
        int lifePointsP = (m_botData[sender].playerData.stats[(uint)StatIds::LIFE_POINTS].base + m_botData[sender].playerData.stats[(uint)StatIds::VITALITY].base - m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base)+ m_botData[sender].playerData.stats[(uint)StatIds::CUR_LIFE].base + m_botData[sender].playerData.stats[(uint)StatIds::CUR_PERMANENT_DAMAGE].base;
        lua_pushinteger(L, lifePointsP);
        return 1;
    }

    static int energyPoints(lua_State *L, SocketIO *sender)
    {
        int energyPoints = m_botData[sender].playerData.stats[(uint)StatIds::ENERGY_POINTS].total;
        lua_pushinteger(L, energyPoints);
        return 1;
    }

    static int maxEnergyPoints(lua_State *L, SocketIO *sender)
    {
        int maxEnergyPoints = m_botData[sender].playerData.stats[(uint)StatIds::MAX_ENERGY_POINTS].total;
        lua_pushinteger(L, maxEnergyPoints);
        return 1;
    }

    static int experience(lua_State *L, SocketIO *sender)
    {
        int experience = m_botData[sender].playerData.experience-m_botData[sender].playerData.experienceLevelFloor;
        lua_pushinteger(L, experience);
        return 1;
    }

    static int freeMode(lua_State *L, SocketIO *sender)
    {
        bool subscription = m_botData[sender].playerData.subscriptionEndDate > 0?true:false;
        lua_pushboolean(L, subscription);
        return 1;
    }

    static int kamas(lua_State *L, SocketIO *sender)
    {
        int kamas = m_botData[sender].playerData.kamas;
        lua_pushinteger(L, kamas);
        return 1;
    }
};

#endif // CHARACTERMETHODS_H
