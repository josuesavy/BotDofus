#ifndef JOBMETHODS_H
#define JOBMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/job/Job.h"

namespace {
class JobMethods
{
    static const char className[];
    static const luaL_Reg methods[3];

    static Job *checkjob(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Job**)ud;  // unbox pointer
    }

    static int level(lua_State *L)
    {
        Job *j = checkjob(L, 1);
        int id = luaL_checkinteger(L, 2);
        int level = j->level(new SocketIO(), id);
        lua_pushinteger(L, level);
        return 1;
    }

    static int name(lua_State *L)
    {
        // get parameters
        Job *j = checkjob(L, 1);
        int id = luaL_checkinteger(L, 2);
        QString name = j->name(new SocketIO(), id);
        lua_pushstring(L, name.toStdString().c_str());
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

const char JobMethods::className[] = "job";

const luaL_Reg JobMethods::methods[] = {
    { "level", level },
    { "name", name },
    { NULL, NULL }
};
}

#endif // JOBMETHODS_H
