#ifndef LUAFUNCTIONS_H
#define LUAFUNCTIONS_H

#include "src/engines/core/process/managers/script/methods/CharacterMethods.h"
#include "src/engines/core/process/managers/script/methods/ChatMethods.h"
#include "src/engines/core/process/managers/script/methods/CraftMethods.h"
#include "src/engines/core/process/managers/script/methods/GlobalMethods.h"
#include "src/engines/core/process/managers/script/methods/InventoryMethods.h"
#include "src/engines/core/process/managers/script/methods/JobMethods.h"
#include "src/engines/core/process/managers/script/methods/MapMethods.h"
#include "src/engines/core/process/managers/script/methods/NpcMethods.h"

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
}

class LuaFunctions
{
public:
    LuaFunctions(lua_State *L);

    int lua_opencharacterlib(lua_State *L);
    int lua_openchatlib(lua_State *L);
    int lua_opencraftlib(lua_State *L);
    int lua_opengloballib(lua_State *L);
    int lua_openinventorylib(lua_State *L);
    int lua_openjoblib(lua_State *L);
    int lua_openmaplib(lua_State *L);
    int lua_opennpclib(lua_State *L);

    void registerObject(lua_State *L, const char *name);
    void setMethods(lua_State *L, const char *name, int (*mfunc)(lua_State *, T *));

    static const luaL_Reg lualibs[];
    static const luaL_Reg characterLibs[];
    static const luaL_Reg exchangeLibs[];
    static const luaL_Reg globalLibs[];
    static const luaL_Reg inventoryLibs[];
    static const luaL_Reg jobLibs[];
    static const luaL_Reg mapLibs[];
    static const luaL_Reg npcLibs[];
    static const luaL_Reg craftLibs[];
    static const luaL_Reg chatLibs[];
};

#endif // LUAFUNCTIONS_H
