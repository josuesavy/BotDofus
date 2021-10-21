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
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

class LuaFunctions
{
public:
    LuaFunctions(lua_State *L);

    static int lua_opencharacterlib(lua_State *L);
    static int lua_openchatlib(lua_State *L);
    static int lua_opencraftlib(lua_State *L);
    static int lua_openexchangelib(lua_State *L);
    static int lua_opengloballib(lua_State *L);
    static int lua_openinventorylib(lua_State *L);
    static int lua_openjoblib(lua_State *L);
    static int lua_openmaplib(lua_State *L);
    static int lua_opennpclib(lua_State *L);

private:
    lua_State *m_L;
};

#endif // LUAFUNCTIONS_H
