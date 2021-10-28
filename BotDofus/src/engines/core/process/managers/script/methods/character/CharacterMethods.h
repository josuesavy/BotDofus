#ifndef CHARACTERMETHODS_H
#define CHARACTERMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/character/Character.h"
namespace {
class CharacterMethods
{
    static const char className[];
    static const luaL_Reg methods[12];

    //static SocketIO *m_sender;

    static Character *checkcharacter(lua_State *L, int narg)
    {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Character**)ud;  // unbox pointer
    }

    static int breed(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int breed = c->breed(new SocketIO());
        lua_pushinteger(L, breed);
        return 1;
    }

    static int name(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        QString name = c->name(new SocketIO());
        lua_pushstring(L, name.toStdString().c_str());
        return 1;
    }

    static int sex(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        bool sex = c->sex(new SocketIO());
        lua_pushboolean(L, sex);
        return 1;
    }

    static int level(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int level = c->level(new SocketIO());
        lua_pushinteger(L, level);
        return 1;
    }

    static int lifePoints(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int lifePoints = c->lifePoints(new SocketIO());
        lua_pushinteger(L, lifePoints);
        return 1;
    }

    static int maxLifePoints(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int maxLifePoints = c->maxLifePoints(new SocketIO());
        lua_pushinteger(L, maxLifePoints);
        return 1;
    }

    static int lifePointsP(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int lifePointsP = c->lifePointsP(new SocketIO());
        lua_pushinteger(L, lifePointsP);
        return 1;
    }

    static int energyPoints(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int energyPoints = c->energyPoints(new SocketIO());
        lua_pushinteger(L, energyPoints);
        return 1;
    }

    static int maxEnergyPoints(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int maxEnergyPoints = c->maxEnergyPoints(new SocketIO());
        lua_pushinteger(L, maxEnergyPoints);
        return 1;
    }

    static int experience(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int experience = c->experience(new SocketIO());
        lua_pushinteger(L, experience);
        return 1;
    }

    static int freeMode(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int freeMode = c->freeMode(new SocketIO());
        lua_pushboolean(L, freeMode);
        return 1;
    }

    static int kamas(lua_State *L)
    {
        Character *c = checkcharacter(L, 1);
        int kamas = c->kamas(new SocketIO());
        lua_pushinteger(L, kamas);
        return 1;
    }

public:
    static void Register(lua_State* L, SocketIO *sender)
    {
        //m_sender = sender;

        lua_newtable(L);
        int methodtable = lua_gettop(L);
        luaL_newmetatable(L, className);
        int metatable   = lua_gettop(L);

        lua_pushliteral(L, "__metatable");
        lua_pushvalue(L, methodtable);
        lua_settable(L, metatable);  // hide metatable from Lua getmetatable()

        lua_pushliteral(L, "__index");
        lua_pushvalue(L, methodtable);
        lua_settable(L, metatable);

        //          lua_pushliteral(L, "__gc");
        //          lua_pushcfunction(L, gc_account);
        //          lua_settable(L, metatable);

        lua_pop(L, 1);  // drop metatable

        luaL_newlib(L, methods);  // fill methodtable
        lua_pop(L, 1);  // drop methodtable

        //          lua_register(L, className, create_account);
    }
};

const char CharacterMethods::className[] = "character";

const luaL_Reg CharacterMethods::methods[12] = {
    { "breed", breed },
    { "name", name },
    { "sex", sex },
    { "level", level },
    { "lifePoints", lifePoints },
    { "maxLifePoints", maxLifePoints },
    { "energyPoints", energyPoints },
    { "maxEnergyPoints", maxEnergyPoints },
    { "experience", experience },
    { "freeMode", freeMode },
    { "kamas", kamas },
    { NULL, NULL }
};
}

#endif // CHARACTERMETHODS_H
