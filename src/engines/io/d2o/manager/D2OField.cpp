#include "D2OField.h"

D2OField::D2OField(const QString &name, Reader *reader):
    m_name(name)
{
    int readType = reader->readInt();
    m_readMethod = getMethod(readType, reader);
    m_type = getType(readType);
}

const QByteArray &D2OField::getValue() const
{
    return m_value;
}

MemoryType D2OField::getType() const
{
    return m_type;
}

const QString D2OField::getName() const
{
    return m_name;
}

D2OClassDefinition &D2OField::getD2OClassDefinition(int classId)
{
    return *m_classes[classId];
}

void D2OField::setClasses(QMap<int, D2OClassDefinition*> &classes, I18nFile *I18n)
{
    m_classes = classes;
    m_I18n = I18n;
}

MemoryType D2OField::getType(const int &typeId)
{
    switch (typeId)
    {
    case -1:
        return _INT;

    case -2:
        return _BOOL;

    case -3:
        return _STRING;

    case -4:
        return _DOUBLE;

    case -5:
        return _INT;

    case -6:
        return _UINT;

    case -99:
        switch (m_typeId[0])
        {
        case -1:
            return LIST_INT;
        case -2:
            return LIST_BOOL;
        case -3:
            return LIST_STRING;
        case -4:
            return LIST_DOUBLE;
        case -5:
            return LIST_INT;
        case -6:
            return LIST_UINT;
        case -99:
            switch (m_typeId[1])
            {
            case -1:
                return LISTLIST_INT;
            case -2:
                return LISTLIST_BOOL;
            case -3:
                return LISTLIST_STRING;
            case -4:
                return LISTLIST_DOUBLE;
            case -5:
                return LISTLIST_INT;
            case -6:
                return LISTLIST_UINT;
            case -99:
                return LIST_OBJECT;
            default:
                return LISTLIST_OBJECT;
            }
        default:
            return LIST_OBJECT;
        }

    default :
        return _OBJECT;
    }
}

std::function<QByteArray (Reader*, const uint&)> D2OField::getMethod(const int &methodType, Reader *reader)
{
    switch (methodType)
    {
    case -1:
        return readInt;

    case -2:
        return readBoolean;

    case -3:
        return readUTF;

    case -4:
        return readDouble;

    case -5:
        return readI18nIndex;

    case -6:
        return readUInt;

    case -99:
    {
        m_listClasses.push_back(reader->readUTF());
        m_typeId.push_back(reader->readInt());
        m_listMethod.insert(0,getMethod(m_typeId.last(), reader));
        return std::function<QByteArray (Reader*, const uint&)>  (std::bind(readVector, std::placeholders::_1, std::placeholders::_2, this));
    }

    default:
    {
        if (methodType > 0)
            return std::function<QByteArray (Reader*, const uint&)>  (std::bind(readObject, std::placeholders::_1, std::placeholders::_2, this));
        qDebug()<<"Unknown type :"<<methodType;
    }
    }
}

void D2OField::read(Reader *reader)
{
    m_value = m_readMethod(reader, 0);
}

QByteArray D2OField::readObject(Reader *reader, const uint &dimention, D2OField *D2OField)
{
    int startIndex = reader->getPosition();
    int classId = reader->readInt();
    D2OField->getD2OClassDefinition(classId).read(reader, D2OField->m_I18n);
    int endIndex = reader->getPosition();

    reader->setPosition(startIndex);

    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readBytes(endIndex-startIndex);
    return buffer.data();
}

QByteArray D2OField::readVector(Reader *reader, const uint &dimention, D2OField *D2OField)
{
    int listCount = reader->readInt();
    QList<QByteArray> list;
    for (int i = 0; i < listCount; i++)
        list.append(D2OField->m_listMethod[(int)dimention](reader, dimention + 1));

    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<list;
    return buffer.data();
}

QByteArray D2OField::readInt(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readInt();
    return buffer.data();
}

QByteArray D2OField::readBoolean(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readBool();
    return buffer.data();
}

QByteArray D2OField::readUTF(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUTF();
    return buffer.data();
}

QByteArray D2OField::readDouble(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readDouble();
    return buffer.data();
}

QByteArray D2OField::readI18nIndex(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readInt();
    return buffer.data();
}

QByteArray D2OField::readUInt(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUInt();
    return buffer.data();
}


QString D2OField::toString() const
{
    return getName();
    //return QString::Format("{0} AS {1}", getName(), getType()->Name);
}
