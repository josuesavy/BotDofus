#include "Writer.h"

int Writer::INT_SIZE = 32;
int Writer::SHORT_SIZE = 16;
int Writer::SHORT_MIN_VALUE = -32768;
int Writer::SHORT_MAX_VALUE = 32767;
int Writer::UNSIGNED_SHORT_MAX_VALUE = 65536;
int Writer::CHUNCK_BIT_SIZE = 7;
int Writer::MAX_ENCODING_LENGTH = qCeil(Writer::INT_SIZE / Writer::CHUNCK_BIT_SIZE);
int Writer::MASK_10000000 = 128;
int Writer::MASK_01111111 = 127;

Writer::Writer()
{
    m_output = new QDataStream(&m_buffer, QIODevice::WriteOnly);
}

Writer::~Writer()
{
    delete m_output;
}

void Writer::reset()
{
    delete m_output;
    m_buffer.clear();
    m_output = new QDataStream(&m_buffer, QIODevice::WriteOnly);
}

int Writer::getPosition() const
{
    return m_output->device()->pos();
}

const QByteArray &Writer::getBuffer()
{
    return m_buffer;
}

int Writer::getSize()
{
    return m_buffer.size();
}

void Writer::writeByte(qint8 b)
{
    *m_output << b;
}

void Writer::writeBytes(const QByteArray &buffer)
{
    for (int i = 0; i < buffer.size(); i++)
        writeByte(buffer[i]);
}

void Writer::writeShort(qint16 s)
{
    *m_output << s;
}

void Writer::writeUShort(quint16 s)
{
    *m_output << s;
}

void Writer::writeInt(qint32 i)
{
    *m_output << i;
}

void Writer::writeUInt(quint32 i)
{
    *m_output << i;
}

void Writer::writeDouble(double d)
{
    *m_output << d;
}

void Writer::writeFloat(float f)
{
    *m_output << f;
}

void Writer::writeUTF(const QString unicodeData)
{
    writeUShort(unicodeData.toUtf8().size());
    writeUTFBytes(unicodeData);
}

void Writer::writeUTFBytes(const QString unicodeData)
{
    QByteArray utf8ByteArray = unicodeData.toUtf8();
    quint32 sizeToWrite = utf8ByteArray.size();
    m_output->writeRawData(utf8ByteArray.constData(), sizeToWrite);
}

void Writer::writeBool(bool b)
{
    *m_output << b;
}

void Writer::writeVarInt(int value)
{
    int b = 0;
    QByteArray ba;

    if(value >= 0 && value <= MASK_01111111)
    {
        ba[ba.size()] = value;
        writeBytes(ba);
        return;
    }

    int c = value;
    QByteArray buffer;

    while(c != 0)
    {
        buffer[buffer.size()] =  c & MASK_01111111;
        b = buffer[buffer.size() - 1];
        c = (uint)c >> CHUNCK_BIT_SIZE;

        if(c > 0)
            b = b | MASK_10000000;

        ba[ba.size()] = b;
    }

    writeBytes(ba);
}

void Writer::writeVarShort(quint16 value)
{
    int b = 0;
    if(value > SHORT_MAX_VALUE || value < SHORT_MIN_VALUE)
        qDebug()<<"ERROR - Writer - Forbidden value"<<value;

    else
    {
        QByteArray ba;

        if(value >= 0 && value <= MASK_01111111)
        {
            ba[ba.size()] = value;
            writeBytes(ba);
            return;
        }

        int c = value & 65535;
        QByteArray buffer;

        while(c != 0)
        {
            buffer[buffer.size()] = c & MASK_01111111;
            b = buffer[buffer.size()-1];
            c = (uint)c >> CHUNCK_BIT_SIZE;

            if(c > 0)
                b = b | MASK_10000000;

            ba[ba.size()] = b;
        }

        writeBytes(ba);
        return;
    }
}

void Writer::writeVarLong(double value)
{
    uint i = 0;
    SpecialInt val;
    val.low = value;
    val.high = qFloor(value/4.294967296E9);

    if(val.high == 0)
    {
        uint value2 = val.low;

        while(value2 >= 128)
        {
            writeByte(value2 & 127 | 128);
            value2 = value2 >> 7;
        }

        writeByte(value2);
    }

    else
    {
        i = 0;

        while(i < 4)
        {
            writeByte(val.low & 127 | 128);
            val.low = val.low >> 7;
            i++;
        }

        if((val.high & 268435455 << 3) == 0)
           writeByte(val.high << 4 | val.low);

        else
        {
            writeByte((val.high << 4 | val.low) & 127 | 128);
            uint value2 = val.high >> 3;

            while(value2 >= 128)
            {
                writeByte(value2 & 127 | 128);
                value2 = value2 >> 7;
            }

            writeByte(value2);
        }
    }
}

void Writer::setPosition(int i)
{
    m_output->device()->seek(i);
}
