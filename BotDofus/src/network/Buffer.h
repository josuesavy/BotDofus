#ifndef BUFFER_H
#define BUFFER_H

#include <QByteArray>
#include <QDebug>

#include "src/protocol/messages/MessageDeclarator.h"
#include "src/protocol/messages/MessageUtils.h"
#include "src/engines/io/network/Reader.h"
#include "src/engines/io/network/Writer.h"
#include "src/engines/security/AesManager.h"

struct MessageInfos
{
    MessageEnum messageType;
    QByteArray messageData;
};

class Buffer
{
public:
    Buffer();

    void reset();

    Writer writePacket(MessageInfos &message);
    Writer writePacket(AbstractMessage &message);
    QList<MessageInfos> readPacket(QByteArray packetData);

private:
    AesManager m_hashManager;
    QByteArray m_key;
    int m_remainingBytes;
    QByteArray m_incompleteHeader;
    int m_part;
    MessageInfos m_message;
    uint _instance_id;
};

#endif // BUFFER_H
