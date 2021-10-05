#include "Reader.h"

int Reader::INT_SIZE = 32;
int Reader::SHORT_SIZE = 16;
int Reader::SHORT_MIN_VALUE = -32768;
int Reader::SHORT_MAX_VALUE = 32767;
int Reader::UNSIGNED_SHORT_MAX_VALUE = 65536;
int Reader::CHUNCK_BIT_SIZE = 7;
int Reader::MAX_ENCODING_LENGTH = qCeil(Reader::INT_SIZE / Reader::CHUNCK_BIT_SIZE);
int Reader::MASK_10000000 = 128;
int Reader::MASK_01111111 = 127;

Reader::Reader():
    m_isUsingFile(false)
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

Reader::Reader(const char *buffer, int size):
    m_isUsingFile(false),
    m_buffer(QByteArray(buffer, size))
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}


Reader::Reader(const QByteArray &buffer):
    m_isUsingFile(false),
    m_buffer(buffer)
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

Reader::Reader(const QString &path):
    m_isUsingFile(true)
{
    QFile *file = new QFile(path);

    if (!file->open(QIODevice::ReadOnly))
        qDebug()<<"ERROR - Reader - Can't open the path :"<<path;

    m_input = new QDataStream(file);
}

Reader::~Reader()
{
    if(m_isUsingFile)
        delete m_input->device();
    delete m_input;
}

void Reader::setBuffer(const char *buffer, int size)
{
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = false;
    delete m_input;
    setBuffer(QByteArray(buffer, size));
}

void Reader::setBuffer(const QByteArray &buffer)
{
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = false;
    delete m_input;
    m_buffer = buffer;
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

void Reader::setBuffer(const QString &path)
{
    m_buffer.clear();
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = true;

    QFile *file = new QFile(path);

    if (!file->open(QIODevice::ReadOnly))
        qDebug()<<"ERROR - Reader - Couldn't open"<<path;

    m_input->setDevice(file);
}

void Reader::setPosition(uint pos)
{
    m_input->device()->seek(pos);
}

uint Reader::getPosition() const
{
    return m_input->device()->pos();
}

int Reader::getSize() const
{
    return m_input->device()->size();
}

int Reader::getAvailableBytes() const
{
    return m_input->device()->bytesAvailable();
}

short Reader::readShort()
{
    qint16 shortData;
    *m_input >> shortData;
    return shortData;
}

ushort Reader::readUShort()
{
    quint16 uShortData;
    *m_input >> uShortData;
    return uShortData;
}

char Reader::readByte()
{
    qint8 byteData;
    *m_input >> byteData;
    return byteData;
}

QByteArray Reader::readBytes(int length, int offset)
{
    QByteArray s;

    if(length == 0)
        length = m_input->device()->bytesAvailable();

    for (int i = offset; i < length; i++)
        s.append(readByte());

    return s;
}

uchar Reader::readUByte()
{
    quint8 uByteData;
    *m_input >> uByteData;
    return uByteData;
}


int Reader::readInt()
{
    qint32 intData;
    *m_input >> intData;
    return intData;
}

uint Reader::readUInt()
{
    quint32 UIntData;
    *m_input >> UIntData;
    return UIntData;
}

QString Reader::readUTF()
{
    ushort length = readUShort();
    QByteArray unicodeArray;
    for(quint16 index(0); index < length; index++)
        unicodeArray.append(readByte());
    return QString::fromUtf8(unicodeArray);
}

QString Reader::readUTFBytes(int size)
{
    QByteArray unicodeArray;

    if (!size)
    {
        do
            unicodeArray.append(readByte());
        while (unicodeArray[unicodeArray.size()-1] != '\0');
    }

    else
    {
        for (int i = 0; i < size; i++)
            unicodeArray.append(readByte());
    }

    return QString::fromUtf8(unicodeArray);
}

bool Reader::readBool()
{
    return readByte() == 1 ? true : false;
}


double Reader::readDouble()
{
    double doubleData;
    *m_input >> doubleData;
    return doubleData;
}

float Reader::readFloat()
{
    float floatData;
    *m_input >> floatData;
    return floatData;
}

int Reader::readVarInt()
{
    char b = 0;
    int value = 0;
    int offset = 0;
    bool hasNext = false;

    while(offset < INT_SIZE)
    {
        b = readByte();

        hasNext = (b & MASK_10000000) == MASK_10000000;

        if(offset > 0)
            value += ((b & MASK_01111111) << offset);

        else
            value += (b & MASK_01111111);

        offset += CHUNCK_BIT_SIZE;

        if(!hasNext)
            return value;
    }

    qDebug()<<"ERROR - Reader - readVarInt - Too much data";
}

uint Reader::readVarUhInt()
{
    return readVarInt();
}

short Reader::readVarShort()
{
    int b = 0;
    int value = 0;
    int offset = 0;
    bool hasNext = false;

    while(offset < SHORT_SIZE)
    {
        b = readByte();
        hasNext = (b & MASK_10000000) == MASK_10000000;

        if(offset > 0)
            value += ((b & MASK_01111111) << offset);

        else
            value += (b & MASK_01111111);

        offset += CHUNCK_BIT_SIZE;

        if(!hasNext)
        {
            if(value > SHORT_MAX_VALUE)
                value -= UNSIGNED_SHORT_MAX_VALUE;

            return value;
        }
    }

    qDebug()<<"ERROR - Reader - readVarShort - Too much data";
}

ushort Reader::readVarUhShort()
{
    return readVarShort();
}

double Reader::readVarLong()
{
    uint b= 0;
    SpecialInt result;
    uint i = 0;

    while(true)
    {
        b = readUByte();

        if(i == 28)
            break;

        if(b >= 128)
        {
            result.low = result.low | (b & 127) << i;
            i = i + 7;
            continue;
        }

        result.low = result.low | b << i;
        return result.high * 4.294967296E9 + result.low;
    }

    if(b >= 128)
    {
        b = b & 127;
        result.low = result.low | b << i;
        result.high = b >> 4;
        i = 3;

        while(true)
        {
            b = readUByte();

            if(i < 32)
            {
                if(b >= 128)
                    result.high = result.high | (b & 127) << i;

                else
                    break;
            }

            i += 7;
        }

        result.high = result.high | b << i;

        return result.high * 4.294967296E9 + result.low;
    }

    result.low = result.low | b << i;
    result.high = b >> 4;
    return result.high * 4.294967296E9 + result.low;
}

double Reader::readVarUhLong()
{
    uint b = 0;
    SpecialInt result;
    uint i = 0;
    while(true)
    {
        b = readUByte();
        if(i == 28)
            break;

        if(b >= 128)
        {
            result.low = result.low | (b & 127) << i;
            i = i + 7;
            continue;
        }
        result.low = result.low | b << i;
        return result.high * 4.294967296E9 + result.low;
    }

    if(b >= 128)
    {
        b = b & 127;
        result.low = result.low | b << i;
        result.high = b >> 4;
        i = 3;

        while(true)
        {
            b = readUByte();

            if(i < 32)
            {
                if(b >= 128)
                    result.high = result.high | (b & 127) << i;

                else
                    break;
            }

            i += 7;
        }

        result.high = result.high | b << i;
        return result.high * 4.294967296E9 + result.low;
    }

    result.low = result.low | b << i;
    result.high = b >> 4;
    return result.high * 4.294967296E9 + result.low;
}
