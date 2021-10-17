#include "LuaFunctions.h"

LuaFunctions::LuaFunctions(lua_State *L)
{
    characterLibs = {
        { "breed", &CharacterMethods::breed },
        { "name", &CharacterMethods::name },
        { "sex", &CharacterMethods::sex },
        { "level", &CharacterMethods::level },
        { "lifePoints", &CharacterMethods::lifePoints },
        { "maxLifePoints", &CharacterMethods::maxLifePoints },
        { "lifePointsP", &CharacterMethods::lifePointsP },
        { "energyPoints", &CharacterMethods::energyPoints },
        { "maxEnergyPoints", &CharacterMethods::maxEnergyPoints },
        { "experience", &CharacterMethods::experience },
        { "freeMode", &CharacterMethods::freeMode },
        { "kamas", &CharacterMethods::kamas },
        { NULL, NULL }
    };

    globalLibs = {
        { "printMessage", &GlobalMethods::printMessage },
        { "printSuccess", &GlobalMethods::printSuccess },
        { "printError", &GlobalMethods::printError },
        { NULL, NULL }
    };

    inventoryLibs = {
        { "deleteItem", &InventoryMethods::deleteItem },
        { "equipItem", &InventoryMethods::equipItem },
        { "itemCount", &InventoryMethods::itemCount },
        { "itemNameId", &InventoryMethods::itemNameId },
        { "itemTypeId", &InventoryMethods::itemTypeId },
        { "itemWeight", &InventoryMethods::itemWeight },
        { "pods", &InventoryMethods::pods },
        { "podsMax", &InventoryMethods::podsMax },
        { "podsP", &InventoryMethods::podsP },
        { "useItem", &InventoryMethods::useItem },
        { "inventoryContent", &InventoryMethods::inventoryContent },
        { NULL, NULL }
    };

    jobLibs = {
        { "level", &JobMethods::level },
        { "name", &JobMethods::name },
        { NULL, NULL }
    };

    mapLibs = {
        { "changeMap", &MapMethods::changeMap },
        { "countPlayers", &MapMethods::countPlayers },
        { "currentArea", &MapMethods::currentArea },
        { "currentSubArea", &MapMethods::currentSubArea },
        { "currentCell", &MapMethods::currentCell },
        { "currentMap", &MapMethods::currentMap },
        { "currentMapId", &MapMethods::currentMapId },
        { "door", &MapMethods::door },
        { "fight", &MapMethods::fight },
        { "moveToCell", &MapMethods::moveToCell },
        { "onCell", &MapMethods::onCell },
        { "onMap", &MapMethods::onMap },
        { "saveZaap", &MapMethods::saveZaap },
        { "useById", &MapMethods::useById },
        { "lockedHouse", &MapMethods::lockedHouse },
        { "lockedStorage", &MapMethods::lockedStorage },
        { NULL, NULL }
    };

    npcLibs = {
        { "leaveDialog", &NpcMethods::leaveDialog },
        { "npc", &NpcMethods::npc },
        { "npcBank", &NpcMethods::npcBank },
        { "reply", &NpcMethods::reply },
        { NULL, NULL }
    };

    craftLibs = {
        { "putItem", &CraftMethods::putItem },
        { "changeQuantityToCraft", &CraftMethods::changeQuantityToCraft },
        { "ready", &CraftMethods::ready },
        { "leaveDialog", &CraftMethods::leaveDialog },
        { NULL, NULL }
    };

    chatLibs = {
        { "sendPrivateMessage", &ChatMethods::sendPrivateMessage },
        { "sendGeneralMessage", &ChatMethods::sendGeneralMessage },
        { "sendGuildMessage", &ChatMethods::sendGuildMessage },
        { "sendAllianceMessage", &ChatMethods::sendAllianceMessage },
        { "sendRecruitmentMessage", &ChatMethods::sendRecruitmentMessage },
        { "sendTradeMessage", &ChatMethods::sendTradeMessage },
        { NULL, NULL }
    };

    lualibs = {
        { "character", lua_opencharacterlib },
        { "chat", lua_openchatlib },
        { "craft", lua_opencraftlib },
        { "global", lua_opengloballib },
        { "inventory", lua_openinventorylib },
        { "job", lua_openjoblib },
        { "map", lua_openmaplib },
        { "npc", lua_opennpclib },
        { NULL, NULL }
    };

    const luaL_Reg *lib = lualibs;
    for(; lib->func != NULL; lib++)
    {
        luaL_requiref(L, lib->name, lib->func, 1);
        lua_pop(L, 1);
    }
}

int LuaFunctions::lua_opencharacterlib(lua_State *L)
{
    luaL_newlib(L, characterLibs);
    return 1;
}

int LuaFunctions::lua_openchatlib(lua_State *L)
{
    luaL_newlib(L, chatLibs);
    return 1;
}

int LuaFunctions::lua_opencraftlib(lua_State *L)
{
    luaL_newlib(L, craftLibs);
    return 1;
}

int LuaFunctions::lua_opengloballib(lua_State *L)
{
    luaL_newlib(L, globalLibs);
    return 1;
}

int LuaFunctions::lua_openinventorylib(lua_State *L)
{
    luaL_newlib(L, inventoryLibs);
    return 1;
}

int LuaFunctions::lua_openjoblib(lua_State *L)
{
    luaL_newlib(L, jobLibs);
    return 1;
}

int LuaFunctions::lua_openmaplib(lua_State *L)
{
    luaL_newlib(L, mapLibs);
    return 1;
}

int LuaFunctions::lua_opennpclib(lua_State *L)
{
    luaL_newlib(L, npcLibs);
    return 1;
}

void LuaFunctions::registerObject(lua_State *L, const char* name)
{
    lua_getglobal(L, name);
    if (lua_isnoneornil(L, -1))
        return;

    lua_pop(L, 1);

    luaL_newmetatable(L, name);
    int metatable  = lua_gettop(L);

    lua_pushvalue(L, metatable);
    lua_setglobal(L, name);

    lua_pop(L, 1);
}

void LuaFunctions::setMethods(lua_State *L, const char *name, int(*mfunc)(lua_State*, T*))
{
    lua_pushstring(L, name);
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L, -1))
        return;

    lua_pushstring(L, name);
    lua_pushlightuserdata(L, (void*)methodTable);
    lua_pushcclosure(L, CallMethod, 1);
    lua_rawset(L, -3);

    lua_pop(L, 1);
}
