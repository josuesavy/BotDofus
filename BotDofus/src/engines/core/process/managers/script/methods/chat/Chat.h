#ifndef CHAT_H
#define CHAT_H

#include "src/engines/core/CoreEngine.h"

class Chat: public CoreEngine
{
public:
    void sendPrivateMessage(SocketIO *sender, QString message, QString receiver)
    {
        getFloodManager().sendChatMessage(sender, message, receiver);
    }

    void sendGeneralMessage(SocketIO *sender, QString message)
    {
        getFloodManager().sendChatMessage(sender, message, CHANNELGLOBAL);
    }

    void sendGuildMessage(SocketIO *sender, QString message)
    {
        getFloodManager().sendChatMessage(sender, message, CHANNELGUILD);
    }

    void sendAllianceMessage(SocketIO *sender, QString message)
    {
        getFloodManager().sendChatMessage(sender, message, CHANNELALLIANCE);
    }

    void sendRecruitmentMessage(SocketIO *sender, QString message)
    {
        getFloodManager().sendChatMessage(sender, message, CHANNELSEEK);
    }

    void sendTradeMessage(SocketIO *sender, QString message)
    {
        getFloodManager().sendChatMessage(sender, message, CHANNELSALES);
    }
};

#endif // CHAT_H
