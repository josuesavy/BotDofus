#include "LuaFunctions.h"

LuaFunctions::LuaFunctions()
{

}

void LuaFunctions::registerObject(lua_State *L, const char* name)
{
    lua_getglobal(E->L, name);
    if (lua_isnoneornil(L, -1))
        return;

    lua_pop(E->L, 1);

    luaL_newmetatable(L, name);
    int metatable  = lua_gettop(L);

    lua_pushvalue(E->L, metatable);
    lua_setglobal(E->L, name);

    lua_pop(E->L, 1);
}

void LuaFunctions::setMethods(lua_State *L, const char *name)
{
    lua_pushstring(L, name);
    lua_rawget(L, LUA_REGISTRYINDEX);

    lua_pushstring(L, methodTable->name);
    lua_pushlightuserdata(L, (void*)methodTable);
    lua_pushcclosure(L, CallMethod, 1);
    lua_rawset(L, -3);

    lua_pop(L, 1);
}
