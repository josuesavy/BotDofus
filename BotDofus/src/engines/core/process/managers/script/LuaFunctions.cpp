#include "LuaFunctions.h"

static const luaL_Reg characterLibs[13] = {
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

static const luaL_Reg exchangeLibs[1] = {
    { NULL, NULL }
};

static const luaL_Reg globalLibs[4] = {
    { "printMessage", &GlobalMethods::printMessage },
    { "printSuccess", &GlobalMethods::printSuccess },
    { "printError", &GlobalMethods::printError },
    { NULL, NULL }
};

static const luaL_Reg inventoryLibs[12] = {
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

static const luaL_Reg jobLibs[3] = {
    { "level", &JobMethods::level },
    { "name", &JobMethods::name },
    { NULL, NULL }
};

static const luaL_Reg mapLibs[17] = {
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

static const luaL_Reg npcLibs[5] = {
    { "leaveDialog", &NpcMethods::leaveDialog },
    { "npc", &NpcMethods::npc },
    { "npcBank", &NpcMethods::npcBank },
    { "reply", &NpcMethods::reply },
    { NULL, NULL }
};

static const luaL_Reg craftLibs[5] = {
    { "putItem", &CraftMethods::putItem },
    { "changeQuantityToCraft", &CraftMethods::changeQuantityToCraft },
    { "ready", &CraftMethods::ready },
    { "leaveDialog", &CraftMethods::leaveDialog },
    { NULL, NULL }
};

static const luaL_Reg chatLibs[7] = {
    { "sendPrivateMessage", &ChatMethods::sendPrivateMessage },
    { "sendGeneralMessage", &ChatMethods::sendGeneralMessage },
    { "sendGuildMessage", &ChatMethods::sendGuildMessage },
    { "sendAllianceMessage", &ChatMethods::sendAllianceMessage },
    { "sendRecruitmentMessage", &ChatMethods::sendRecruitmentMessage },
    { "sendTradeMessage", &ChatMethods::sendTradeMessage },
    { NULL, NULL }
};

LuaFunctions::LuaFunctions(lua_State *L)
{
    m_L = L;

    static const luaL_Reg lualibs[] = {
        { "character", lua_opencharacterlib },
        { "chat", lua_openchatlib },
        { "craft", lua_opencraftlib },
        { "exchange", lua_openexchangelib },
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
        luaL_requiref(m_L, lib->name, lib->func, 1);
        lua_pop(m_L,1);
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

int LuaFunctions::lua_openexchangelib(lua_State *L)
{
    luaL_newlib(L, exchangeLibs);
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

int lua_opennpclib(lua_State *L)
{
    luaL_newlib(L, npcLibs);
    return 1;
}
