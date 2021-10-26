#ifndef NPCMETHODS_H
#define NPCMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/npc/Npc.h"

class NpcMethods
{
    static const char className[];
    static const luaL_Reg methods[5];

    static Npc *checknpc(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Npc**)ud;  // unbox pointer
    }

    static int leaveDialog(lua_State *L)
    {
        Npc *n = checknpc(L, 1);
        n->leaveDialog(new SocketIO());
        return 0;
    }

    static int npc(lua_State *L)
    {
        return 0;
    }

    static int npcBank(lua_State *L)
    {
        return 0;
    }

    static int reply(lua_State *L)
    {
        return 0;
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

const char NpcMethods::className[] = "npc";

const luaL_Reg NpcMethods::methods[] = {
    { "leaveDialog", leaveDialog },
    { "npc", npc },
    { "npcBank", npcBank },
    { "reply", reply },
    { NULL, NULL }
};

#endif // NPCMETHODS_H
