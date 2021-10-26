#ifndef ABSTRACTLUAMETHODS_H
#define ABSTRACTLUAMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/CoreEngine.h"

class AbstractLuaMethods : public CoreEngine
{
protected:
    static const char className[];
    static const luaL_Reg methods[20];

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

#endif // ABSTRACTLUAMETHODS_H
