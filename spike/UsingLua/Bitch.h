#ifndef BITCH_H
#define BITCH_H

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

#include <QDebug>

enum class Function
{
    MOVE,
    BANK,
    PHOENIX
};

class Bitch
{
public:
    Bitch();

private:
    bool checkLua(lua_State *lua, int r);

    void getSettings(lua_State *lua);
    void getGlobalFunction(lua_State *lua, Function function);
    void getActions(lua_State *lua);

    void registerFunction(lua_State *lua);
};

#endif // BITCH_H
