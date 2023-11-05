#include "CompressedMap.h"

CompressedMap::CompressedMap(Reader *reader, const QString &path) :
    m_path(path),
    m_isInvalidMap(false),
    m_isImage(false),
    m_isMap(false)
{
    m_indexName = reader->readUTF();
    if (m_indexName == "link" || m_indexName == "")
    {
        m_isInvalidMap = true;
        return;
    }

    else if(m_indexName.contains("png"))
        m_isImage = true;

    else if(m_indexName.contains(".dlm"))
        m_isMap = true;


    m_offset = reader->readUInt() + 2;
    m_byteCount = reader->readUInt();

    if(m_isImage)
    {
        int pos = (int)reader->getPosition();
        reader->setPosition((int)m_offset);
        data = reader->readBytes((int)m_byteCount);
        reader->setPosition(pos);
    }
}

QString CompressedMap::getPath() const
{
    return m_path;
}

QString CompressedMap::getIndexName() const
{
    return m_indexName;
}

bool CompressedMap::isInvalidMap() const
{
    return m_isInvalidMap;
}

bool CompressedMap::isImage() const
{
    return m_isImage;
}

bool CompressedMap::isMap() const
{
    return m_isMap;
}

uint CompressedMap::getOffset() const
{
    return m_offset;
}

uint CompressedMap::getByteCount() const
{
    return m_byteCount;
}

uint CompressedMap::getMapId() const
{
    int i = 0;
    for (i = 0; i < m_indexName.size(); i++)
        if (m_indexName[i] == '/')
            break;

    return toUInt(m_indexName.mid(i+1, m_indexName.size()-i+1+4));
}

QString CompressedMap::getImageId() const
{
    int i = 0;
    for (i = 0; i < m_indexName.size(); i++)
        if (m_indexName[i] == '/')
            break;

    return m_indexName.split(".").at(0);
}

QByteArray CompressedMap::getData() const
{
    return data;
}
