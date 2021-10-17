#ifndef NPCMETHODS_H
#define NPCMETHODS_H

extern "C"
{
    #include "include/lua-5.4.2_Win32_dll16_lib/include/lua.h"
}

#include "src/engines/DataHandler.h"
#include "src/engines/core/process/managers/interaction/InteractionManager.h"

class NpcMethods : public DataHandler
{
public:
    static int leaveDialog(lua_State *L, SocketIO *sender, InteractionManager *interactionManager)
    {
        // get parameters

        // process
        interactionManager->leaveNpcDialog(sender);

        // return the result

        return 1;
    }

    static int npc(lua_State *L, SocketIO *sender, InteractionManager *interactionManager)
    {
        // get parameters

        // process
        //interactionManager->

        // return the result

        return 1;
    }

    static int npcBank(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }

    static int reply(lua_State *L, SocketIO *sender)
    {
        // get parameters

        // process

        // return the result

        return 1;
    }
};

#endif // NPCMETHODS_H
