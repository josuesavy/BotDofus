#ifndef LUAFUNCTIONS_H
#define LUAFUNCTIONS_H

#include "src/engines/core/process/managers/script/methods/character/CharacterMethods.h"
#include "src/engines/core/process/managers/script/methods/chat/ChatMethods.h"
#include "src/engines/core/process/managers/script/methods/craft/CraftMethods.h"
#include "src/engines/core/process/managers/script/methods/global/GlobalMethods.h"
#include "src/engines/core/process/managers/script/methods/inventory/InventoryMethods.h"
#include "src/engines/core/process/managers/script/methods/job/JobMethods.h"
#include "src/engines/core/process/managers/script/methods/map/MapMethods.h"
#include "src/engines/core/process/managers/script/methods/npc/NpcMethods.h"

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

class LuaFunctions
{
public:
    LuaFunctions();
    LuaFunctions(lua_State *L);

    void init();
    bool isInit();

    void setSender(SocketIO *sender);
    SocketIO *getSender();

    void setLuaState(lua_State *L);
    lua_State *getLuaState();

private:
    lua_State *m_L;
    bool m_Init;
    SocketIO *m_sender;
};

#endif // LUAFUNCTIONS_H
