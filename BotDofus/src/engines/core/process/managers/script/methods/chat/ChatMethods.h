#ifndef CHATMETHODS_H
#define CHATMETHODS_H

extern "C"
{
#include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lauxlib.h"
#include "include/lua-5.4.2_Win32_dll16_lib/include/lualib.h"
}

#include "src/engines/core/process/managers/script/methods/chat/Chat.h"

class ChatMethods
{
    static const char className[];
    static const luaL_Reg methods[7];

    static Chat *checkchat(lua_State *L, int narg) {
        luaL_checktype(L, narg, LUA_TUSERDATA);
        void *ud = luaL_checkudata(L, narg, className);
        if(!ud) luaL_typeerror(L, narg, className);
        return *(Chat**)ud;  // unbox pointer
    }

    static int sendPrivateMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        QString receiver = luaL_checkstring(L, 3);
        c->sendPrivateMessage(new SocketIO(), message, receiver);
        return 0;
    }

    static int sendGeneralMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        c->sendGeneralMessage(new SocketIO(), message);
        return 0;
    }

    static int sendGuildMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        c->sendGuildMessage(new SocketIO(), message);
        return 0;
    }

    static int sendAllianceMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        c->sendAllianceMessage(new SocketIO(), message);
        return 0;
    }

    static int sendRecruitmentMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        c->sendRecruitmentMessage(new SocketIO(), message);
        return 0;
    }

    static int sendTradeMessage(lua_State *L)
    {
        Chat *c = checkchat(L, 1);
        QString message = luaL_checkstring(L, 2);
        c->sendTradeMessage(new SocketIO(), message);
        return 0;
    }

public:
    static void Register(lua_State* L) {
        lua_newtable(L);                 int methodtable = lua_gettop(L);
        luaL_newmetatable(L, className); int metatable   = lua_gettop(L);

        lua_pushliteral(L, "__metatable");
        lua_pushvalue(L, methodtable);
        lua_settable(L, metatable);  // hide metatable from Lua getmetatable()

        lua_pushliteral(L, "__index");
        lua_pushvalue(L, methodtable);
        lua_settable(L, metatable);

        //        lua_pushliteral(L, "__gc");
        //        lua_pushcfunction(L, gc_account);
        //        lua_settable(L, metatable);

        lua_pop(L, 1);  // drop metatable

        luaL_newlib(L, methods);  // fill methodtable
        lua_pop(L, 1);  // drop methodtable

        //lua_register(L, className, create_account);
    }
};

const char ChatMethods::className[] = "chat";

const luaL_Reg ChatMethods::methods[] = {
    { "sendPrivateMessage", sendPrivateMessage },
    { "sendGeneralMessage", sendGeneralMessage },
    { "sendGuildMessage", sendGuildMessage },
    { "sendAllianceMessage", sendAllianceMessage },
    { "sendRecruitmentMessage", sendRecruitmentMessage },
    { "sendTradeMessage", sendTradeMessage },
    { NULL, NULL }
};

#endif // CHATMETHODS_H
