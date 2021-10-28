#ifndef CRAFTMETHODS_H
#define CRAFTMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/craft/Craft.h"

namespace {
class CraftMethods
{
    static const char className[];
    static const luaL_Reg methods[7];

    static Craft *checkcraft(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Craft**)ud;  // unbox pointer
    }

    static int putItem(lua_State *L)
    {
        Craft *c = checkcraft(L, 1);
        int id = luaL_checkinteger(L, 2);
        int quantity = luaL_checkinteger(L, 3);
        c->putItem(new SocketIO(), id, quantity);
        return 0;
    }

    static int changeQuantityToCraft(lua_State *L)
    {
        Craft *c = checkcraft(L, 1);
        int id = luaL_checkinteger(L, 2);
        int quantity = luaL_checkinteger(L, 3);
        c->changeQuantityToCraft(new SocketIO(), id, quantity);
        return 0;
    }

    static int ready(lua_State *L)
    {
        Craft *c = checkcraft(L, 1);
        c->ready(new SocketIO());
        return 0;
    }

    static int leaveDialog(lua_State *L)
    {
        Craft *c = checkcraft(L, 1);
        c->leaveDialog(new SocketIO());
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

const char CraftMethods::className[] = "craft";

const luaL_Reg CraftMethods::methods[] = {
    { "putItem", putItem },
    { "changeQuantityToCraft", changeQuantityToCraft },
    { "ready", ready },
    { "leaveDialog", leaveDialog },
    { NULL, NULL }
};
}

#endif // CRAFTMETHODS_H
