#ifndef NPC_H
#define NPC_H

#include "src/engines/core/CoreEngine.h"

class Npc: public CoreEngine
{
public:
    void leaveDialog(SocketIO *sender)
    {
        getInteractionManager().leaveNpcDialog(sender);
    }

    void npc(SocketIO *sender)
    {

    }

    void npcBank(SocketIO *sender)
    {

    }

    void reply(SocketIO *sender)
    {

    }
};

#endif // NPC_H
