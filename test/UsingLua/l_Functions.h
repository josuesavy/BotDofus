#ifndef L_FUNCTIONS_H
#define L_FUNCTIONS_H

extern "C"
{
#include "Lua514/include/lua.h"
#include "Lua514/include/lauxlib.h"
#include "Lua514/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua514/lua5.1.lib")
#endif

#include "Functions.h"

int l_Global_constructor(lua_State * l)
{
    Global ** udata = (Global **)lua_newuserdata(l, sizeof(Global *));
    *udata = new Global();

    luaL_getmetatable(l, "luaL_Global");

    lua_setmetatable(l, -2);

    return 1;
}

Global * l_CheckGlobal(lua_State * l, int n)
{
    return *(Global **)luaL_checkudata(l, n, "luaL_Foo");
}

int l_Global_printMessage(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    QString message = global->printMessage(luaL_checkstring(L, 1));

    qDebug() << "[Script]" << message;
    return 1;
}

int l_Global_printSuccess(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    QString message = global->printSuccess(luaL_checkstring(L, 1));

    qDebug() << "(Success) [Script]" << message;
    return 1;
}

int l_Global_printWarning(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    QString message = global->printWarning(luaL_checkstring(L, 1));

    qDebug() << "(Warning) [Script]" << message;
    return 1;
}

int l_Global_printError(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    QString message = global->printError(luaL_checkstring(L, 1));

    qDebug() << "(Error) [Script]" << message;
    return 1;
}


int l_Global_getCountFight(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    int nbr = global->getCountFight();

    lua_pushnumber(L, nbr);
    return 1;
}

int l_Global_getCountGather(lua_State *L)
{
    Global * global = l_CheckGlobal(L, 1);

    int nbr = global->getCountGather();

    lua_pushnumber(L, nbr);
    return 1;
}

int l_Global_destructor(lua_State * l)
{
    Global * foo = l_CheckGlobal(l, 1);
    delete foo;

    return 0;
}

#endif // L_FUNCTIONS_H
