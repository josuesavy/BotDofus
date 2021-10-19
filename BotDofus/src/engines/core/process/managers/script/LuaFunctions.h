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

    static int lua_opencharacterlib(lua_State *L);
    static int lua_openchatlib(lua_State *L);
    static int lua_opencraftlib(lua_State *L);
    static int lua_opengloballib(lua_State *L);
    static int lua_openinventorylib(lua_State *L);
    static int lua_openjoblib(lua_State *L);
    static int lua_openmaplib(lua_State *L);
    static int lua_opennpclib(lua_State *L);

    void registerObject(lua_State *L, const char *name);
    void setMethods(lua_State *L, const char *name, int (*mfunc)(lua_State *, T *));

    static luaL_Reg lualibs[9];
    static luaL_Reg characterLibs[13];
    static luaL_Reg exchangeLibs[];
    static luaL_Reg globalLibs[4];
    static luaL_Reg inventoryLibs[12];
    static luaL_Reg jobLibs[3];
    static luaL_Reg mapLibs[17];
    static luaL_Reg npcLibs[5];
    static luaL_Reg craftLibs[5];
    static luaL_Reg chatLibs[8];
};

#endif // LUAFUNCTIONS_H
