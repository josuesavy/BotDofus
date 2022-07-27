#include "Bitch.h"

Bitch::Bitch()
{
    lua_State *lua;

    lua = luaL_newstate();
    luaL_openlibs(lua);
    registerFunction(lua);

    if(checkLua(lua, luaL_dofile(lua, "C:\\Users\\SAVY\\Documents\\Qt Creator projects\\BotDofus\\spike\\UsingLua\\test.lua")))
    {
        // Get vars
        getSettings(lua);

        // Get functions
        getGlobalFunction(lua, Function::MOVE);
        getGlobalFunction(lua, Function::BANK);
        getGlobalFunction(lua, Function::PHOENIX);
    }

    lua_close(lua);
}

bool Bitch::checkLua(lua_State *lua, int r)
{
    if(r != 0)
    {
        qDebug() << lua_tostring(lua, -1);
        return false;
    }

    return true;
}

void Bitch::getSettings(lua_State *lua)
{
    lua_getglobal(lua, "AUTO_DELETE");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                (int)lua_tonumber(lua,-1); // value

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "GATHER");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                (int)lua_tonumber(lua,-1); // value

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "MIN_MONSTERS");
    if(lua_isnumber(lua, -1))
        (int)lua_tonumber(lua,-1); // value

    lua_getglobal(lua, "MAX_MONSTERS");
    if(lua_isnumber(lua, -1))
        (int)lua_tonumber(lua,-1); // value

    lua_getglobal(lua, "OPEN_BAGS");
    if(lua_isboolean(lua, -1))
        (bool)lua_toboolean(lua,-1); // value

    lua_getglobal(lua, "FORBIDDEN_MONSTERS");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                (int)lua_tonumber(lua,-1); // value

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_getglobal(lua, "FORCE_MONSTERS");
    if(lua_istable(lua, -1))
    {
        lua_pushnil(lua);
        while(lua_next(lua, -2))
        {
            if(lua_isnumber(lua, -1))
                (int)lua_tonumber(lua,-1); // value

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }
}

void Bitch::getGlobalFunction(lua_State *lua, Function function)
{
    switch (function)
    {
    case Function::MOVE:
        lua_getglobal(lua, "move");
        break;

    case Function::BANK:
        lua_getglobal(lua, "bank");
        break;

    case Function::PHOENIX:
        lua_getglobal(lua, "phoenix");
        break;
    }

    if(lua_isfunction(lua, -1))
    {
        if(!lua_pcall(lua, 0, LUA_MULTRET, 0))
        {
            if(lua_istable(lua, -1))
            {
                lua_pushnil(lua);
                while(lua_next(lua,-2) != 0)
                {
                    if(lua_istable(lua, -3))
                        getActions(lua);

                    lua_pop(lua,1);
                }
            }
        }
    }
}

void Bitch::getActions(lua_State *lua)
{
    lua_pushstring(lua, "map");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "custom");
    lua_gettable(lua, -2);
    if(lua_topointer(lua, -1) != NULL)
    {
        if(lua_isfunction(lua, -1))
        {
            if(lua_pcall(lua, 0,1,0))
            {

                qDebug() << lua_tostring(lua, -1); // value
            }
        }
    }

    lua_pop(lua,1);

    lua_pushstring(lua, "npcBank");
    lua_gettable(lua, -2);
    (bool)lua_toboolean(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "path");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "door");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "gather");
    lua_gettable(lua, -2);
    (bool)lua_toboolean(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "fight");
    lua_gettable(lua, -2);
    (bool)lua_toboolean(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "lockedHouse");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);

    lua_pushstring(lua, "lockedStorage");
    lua_gettable(lua, -2);
    lua_tostring(lua, -1); // value
    lua_pop(lua,1);
}

void Bitch::registerFunction(lua_State *lua)
{
    luaL_Reg sFooRegs[] =
    {
        { "printMessage", global::printMessage },
        { NULL, NULL }
    };


    lua_register(lua, "global", global::printMessage);
}
