#include "Buffer.h"

Buffer::Buffer():
    m_remainingBytes(0),
    m_part(0),
    _instance_id(0)
{

}

void Buffer::reset()
{
    m_key.clear();
    m_message.messageData.clear();
    m_remainingBytes = 0;
}

Writer Buffer::writePacket(AbstractMessage &message)
{
    Writer temp;
    message.serialize(&temp);

    if(message.needHash() && !m_key.isEmpty())
        temp.writeBytes(m_hashManager.hashFunction(temp.getBuffer(), m_key));

    MessageInfos messageInfos;
    messageInfos.messageData = temp.getBuffer();
    messageInfos.messageType = message.getType();

    return writePacket(messageInfos);
}

Writer Buffer::writePacket(MessageInfos &message)
{
    qDebug()<<"\n----------------------PACKET SEND----------------------";

    ushort messageType = (ushort)message.messageType;

    int lengthType = 0; // On recupere le lengthType en fonction de la taille.

    if (message.messageData.size() > 65535)
        lengthType = 3;

    else if (message.messageData.size() > 255)
        lengthType = 2;

    else if (message.messageData.size() > 0)
        lengthType = 1;


    ushort header = (ushort)(messageType << 2 | lengthType); // On cree le header

    Writer writer;
    writer.writeUShort(header); // On l'ecrit
    _instance_id++;
    writer.writeUInt(_instance_id);

    // On ecrit la longueur du message en fonction du lengthType

    if (lengthType == 1)
        writer.writeByte((char)(message.messageData.size()));

    else if (lengthType == 2)
        writer.writeShort((short)(message.messageData.size()));

    else if (lengthType == 3)
    {
        writer.writeByte((char)(message.messageData.size() >> 16 & 255));
        writer.writeShort((short)(message.messageData.size() & 65535));
    }

    writer.writeBytes(message.messageData); // Et on ecrit le bytes de notre writer temporaire.

    qDebug()<<"Packet -"<<MessageUtils::getName(message.messageType)<< "- ID :"<<messageType<< "- Size :"<<message.messageData.size()<< "- Type :" <<lengthType;

    return writer;
}

QList<MessageInfos> Buffer::readPacket(QByteArray packetData)
{
    QList<MessageInfos> messages;
    int messageTotalLength = 0;

    if (m_remainingBytes > 0)
    {
        m_part++;

        if (packetData.size() - m_remainingBytes >= 0)
        {
            m_message.messageData += packetData.mid(0,m_remainingBytes);
            messageTotalLength = m_remainingBytes;
            m_remainingBytes = 0;
            messages<<m_message;
        }

        else
        {
            m_message.messageData+= packetData.mid(0, packetData.size());
            messageTotalLength = packetData.size();
            m_remainingBytes -= packetData.size();
        }

        qDebug()<<"Packet -"<<MessageUtils::getName(m_message.messageType)<< "- ID :"<<(int)m_message.messageType<< "- Partie :"<<m_part;

        if (m_remainingBytes == 0)
        {
            qDebug()<<"\n----------------------PACKET RECONSTITUTED----------------------";
            qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName(m_message.messageType)<< "- ID :"<<(int)m_message.messageType<< "- Taille :"<<m_message.messageData.size();
        }
    }

    if (m_remainingBytes == 0 && messageTotalLength != packetData.size())
    {
        qDebug()<<"\n----------------------PACKET(S) RECEIVED ("<<packetData.size() - messageTotalLength<<")----------------------";

        while (messageTotalLength < packetData.size())
        {
            if(!m_incompleteHeader.isEmpty())
            {
                packetData.insert(0, m_incompleteHeader);
                m_incompleteHeader.clear();
            }

            QByteArray header = packetData.mid(messageTotalLength,2+3);
            int messageLength = 0;
            ushort hiheader = Reader(header, 2).readUShort();
            ushort packetID = hiheader >> 2;
            ushort lengthType = hiheader & 3;

            if(header.size() == 1 || (header.size() >=2 && header.size()-2 < lengthType))
            {
                qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName((MessageEnum)packetID)<< "-  ID :"<<packetID<<" - Incomplete header  - Part 0";

                m_incompleteHeader = header;
                break;
            }

            else
            {
                Reader reader(packetData.mid(2+messageTotalLength,lengthType).data(),lengthType);

                if (lengthType == 1)
                    messageLength =  reader.readUByte();

                else if (lengthType == 2)
                    messageLength =  reader.readUShort();

                else if (lengthType == 3)
                    messageLength = (uint)(((reader.readUByte() & 255) << 16) + ((reader.readUByte() & 255) << 8) + (reader.readUByte() & 255));

                m_message.messageType = (MessageEnum)packetID;

                if (0 > packetData.size() - (messageTotalLength+messageLength+2+lengthType))
                {
                    m_part = 1;
                    m_remainingBytes = messageLength - (packetData.size() - (messageTotalLength+2+lengthType));
                    m_message.messageData = packetData.mid(2+lengthType+messageTotalLength, packetData.size()-(messageTotalLength+2+lengthType));
                    messageTotalLength = packetData.size();

                    qDebug()<<"Packet "<<messages.size()+1<<"-"<<MessageUtils::getName((MessageEnum)packetID)<<
                              "- ID :"<<packetID<<
                              "- Total Size :"<<messageLength<<
                              "- Type :" <<lengthType<<
                              "- Part :"<<m_part<<
                              "- Size :"<<packetData.size();
                }

                else
                {
                    m_message.messageData = packetData.mid(2+lengthType+messageTotalLength, messageLength);
                    messages<<m_message;
                    messageTotalLength+=messageLength+2+lengthType;

                    qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName((MessageEnum)packetID)<<
                              "-  ID :"<<packetID<<
                              "- Size :"<<messageLength<<
                              "- Type :" <<lengthType;
                }
            }
        }
    }

    return messages;
}
