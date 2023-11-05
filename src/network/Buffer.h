#ifndef BUFFER_H
#define BUFFER_H

#include <QByteArray>
#include <QDebug>

#include "src/protocol/network/messages/MessageDeclarator.h"
#include "src/protocol/network/messages/MessageUtils.h"
#include "src/utils/io/Reader.h"
#include "src/utils/io/Writer.h"
#include "src/utils/security/AesManager.h"

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
