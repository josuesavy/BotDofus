#ifndef GLOBALMETHODS_H
#define GLOBALMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"

class GlobalMethods : public DataHandler
{
public:
    int printMessage(lua_State *L, SocketIO *sender)
    {
        QString message = lua_tostring(L, 2);
        action(sender) << message;
        return 1;
    }

    int printSuccess(lua_State *L, SocketIO *sender)
    {
        QString message = lua_tostring(L, 2);
        info(sender) << message;
        return 1;
    }

    int printError(lua_State *L, SocketIO *sender)
    {
        QString message = lua_tostring(L, 2);
        error(sender) << message;
        return 1;
    }
};

#endif // GLOBALMETHODS_H
