#ifndef LUAFUNCTIONS_H
#define LUAFUNCTIONS_H

#include "src/engines/core/process/managers/script/methods/CharacterMethods.h"
#include "src/engines/core/process/managers/script/methods/ChatMethods.h"
#include "src/engines/core/process/managers/script/methods/CraftMethods.h"
#include "src/engines/core/process/managers/script/methods/GlobalMethods.h"
#include "src/engines/core/process/managers/script/methods/InventoryMethods.h"
#include "src/engines/core/process/managers/script/methods/JobMethods.h"
#include "src/engines/core/process/managers/script/methods/MapMethods.h"
#include "src/engines/core/process/managers/script/methods/NpcMethods.h"h"

struct BotDofusRegister
{
    const char* name;
    int(*mfunc)(lua_State*, T*);
};

class LuaFunctions
{
public:
    LuaFunctions();

    void registerObject(lua_State *L, const char *name);
    void setMethods(lua_State *L, const char *name);
};

#endif // LUAFUNCTIONS_H
