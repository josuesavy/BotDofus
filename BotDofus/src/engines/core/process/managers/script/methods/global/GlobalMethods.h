#ifndef GLOBALMETHODS_H
#define GLOBALMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/global/Global.h"

namespace {
class GlobalMethods
{
    static const char className[];
    static const luaL_Reg methods[5];

    static Global *checkglobal(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Global**)ud;  // unbox pointer
    }

    static int printMessage(lua_State *L)
    {
        Global *g = checkglobal(L, 1);
        QString message = luaL_checkstring(L, 2);
        g->printMessage(message, new SocketIO());
        return 0;
    }

    static int printSuccess(lua_State *L)
    {
        Global *g = checkglobal(L, 1);
        QString message = luaL_checkstring(L, 2);
        g->printSuccess(message, new SocketIO());
        return 0;
    }

    static int printWarning(lua_State *L)
    {
        Global *g = checkglobal(L, 1);
        QString message = luaL_checkstring(L, 2);
        g->printWarning(message, new SocketIO());
        return 0;
    }

    static int printError(lua_State *L)
    {
        Global *g = checkglobal(L, 1);
        QString message = luaL_checkstring(L, 2);
        g->printError(message, new SocketIO());
        return 0;
    }

public:
    static void Register(lua_State* L) {
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

//        lua_pushliteral(L, "__gc");
//        lua_pushcfunction(L, gc_account);
//        lua_settable(L, metatable);

        lua_pop(L, 1);  // drop metatable

        luaL_newlib(L, methods);  // fill methodtable
        lua_pop(L, 1);  // drop methodtable

        //lua_register(L, className, create_account);
    }
};

const char GlobalMethods::className[] = "global";

const luaL_Reg GlobalMethods::methods[] = {
    { "printMessage", printMessage },
    { "printSuccess", printSuccess },
    { "printSuccess", printWarning },
    { "printError", printError },
    { NULL, NULL }
};
}

#endif // GLOBALMETHODS_H
