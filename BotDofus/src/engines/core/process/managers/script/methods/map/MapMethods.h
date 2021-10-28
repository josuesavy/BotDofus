#ifndef MAPMETHODS_H
#define MAPMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/map/MapLua.h"
#include <QRandomGenerator>

namespace {
class MapMethods
{
    static const char className[];
    static const luaL_Reg methods[17];

    static MapLua *checkmaplua(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(MapLua**)ud;  // unbox pointer
    }

    static int changeMap(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        QString direction = luaL_checkstring(L, 2);
        ml->changeMap(new SocketIO(), direction);
        return 0;
    }

    static int countPlayers(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        int countPlayers = ml->countPlayers(new SocketIO());
        lua_pushinteger(L, countPlayers);
        return 1;
    }

    static int currentArea(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        QString currentArea = ml->currentArea(new SocketIO());
        lua_pushstring(L, currentArea.toStdString().c_str());
        return 1;
    }

    static int currentSubArea(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        QString currentSubArea = ml->currentSubArea(new SocketIO());
        lua_pushstring(L, currentSubArea.toStdString().c_str());
        return 1;
    }

    static int currentCell(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        int currentCell = ml->currentCell(new SocketIO());
        lua_pushinteger(L, currentCell);
        return 1;
    }

    static int currentMap(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        QString currentMap = ml->currentMap(new SocketIO());
        lua_pushstring(L, currentMap.toStdString().c_str());
        return 1;
    }

    static int currentMapId(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        int currentMapId = ml->currentMapId(new SocketIO());
        lua_pushinteger(L, currentMapId);
        return 1;
    }

    static int door(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        ml->door(new SocketIO());
        return 0;
    }

    static int fight(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        ml->fight(new SocketIO());
        return 0;
    }

    static int moveToCell(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        int cellId = luaL_checkinteger(L, 2);
        ml->moveToCell(new SocketIO(), cellId);
        return 0;
    }

    static int onCell(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);
        int cellId = luaL_checkinteger(L, 2);
        bool onCell = ml->onCell(new SocketIO(), cellId);
        lua_pushboolean(L, onCell);
        return 1;
    }

    static int onMap(lua_State *L)
    {
        MapLua *ml = checkmaplua(L, 1);

        bool onCell = false;

        QString mapPosition;
        if (lua_isstring(L, -2))
        {
            mapPosition = luaL_checkinteger(L, 2);
            onCell = ml->onMap(new SocketIO(), mapPosition);
        }

        int mapId = INVALID;
        if(lua_isinteger(L, -2))
        {
            mapId = luaL_checkinteger(L, 2);
            onCell = ml->onMap(new SocketIO(), mapId);
        }

        lua_pushboolean(L, onCell);
        return 1;
    }

    static int saveZaap(lua_State *L)
    {
        return 1;
    }

    static int useById(lua_State *L)
    {
        return 1;
    }

    static int lockedHouse(lua_State *L)
    {
        return 1;
    }

    static int lockedStorage(lua_State *L)
    {
        return 1;
    }

public:
    static void Register(lua_State* L) {
        lua_newtable(L);                 int methodtable = lua_gettop(L);
        luaL_newmetatable(L, className); int metatable   = lua_gettop(L);

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

const char MapMethods::className[] = "map";

const luaL_Reg MapMethods::methods[] = {
    { "changeMap", changeMap },
    { "countPlayers", countPlayers },
    { "currentArea", currentArea },
    { "currentSubArea", currentSubArea },
    { "currentCell", currentCell },
    { "currentMap", currentMap },
    { "currentMapId", currentMapId },
    { "door", door },
    { "fight", fight },
    { "moveToCell", moveToCell },
    { "onCell", onCell },
    { "onMap", onMap },
    { "saveZaap", saveZaap },
    { "useById", useById },
    { "lockedHouse", lockedHouse },
    { "lockedStorage", lockedStorage },
    { NULL, NULL }
};
}

#endif // MAPMETHODS_H
