#ifndef CHATMETHODS_H
#define CHATMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/managers/flood/FloodManager.h"h"

class ChatMethods : public DataHandler
{
public:
    static int sendPrivateMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);
        QString receiver = lua_tostring(L, 2);

        // process
        floodManager->sendChatMessage(sender, message, receiver);

        // return the result

        return 1;
    }

    static int sendGeneralMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);

        // process
        floodManager->sendChatMessage(sender, message, CHANNELGLOBAL);

        // return the result

        return 1;
    }

    static int sendGuildMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);

        // process
        floodManager->sendChatMessage(sender, message, CHANNELGUILD);

        // return the result

        return 1;
    }

    static int sendAllianceMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);

        // process
        floodManager->sendChatMessage(sender, message, CHANNELALLIANCE);

        // return the result

        return 1;
    }

    static int sendRecruitmentMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);

        // process
        floodManager->sendChatMessage(sender, message, CHANNELSEEK);

        // return the result

        return 1;
    }

    static int sendTradeMessage(lua_State *L, SocketIO *sender, FloodManager *floodManager)
    {
        // get parameters
        QString message = lua_tostring(L, 1);

        // process
        floodManager->sendChatMessage(sender, message, CHANNELSALES);

        // return the result

        return 1;
    }
};

#endif // CHATMETHODS_H
