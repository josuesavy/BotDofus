#include "D2PFile.h"

D2PFile::D2PFile(const QString &path):
    m_path(path)
{
    if (!path.contains(".d2p"))
        qDebug()<<"ERROR - D2PFile - Incorrect extension"<<path;

    getFileContent();
}

D2PFile::~D2PFile()
{
    foreach(CompressedMap *map, m_contentMap.values())
        delete map;
}

const QMap<uint, CompressedMap*> &D2PFile::getContentMap() const
{
    return m_contentMap;
}

const QMap<QString, CompressedMap *> &D2PFile::getContentImage() const
{
    return m_contentImage;
}

const QString &D2PFile::getPath() const
{
    return m_path;
}

void D2PFile::getFileContent()
{
    Reader reader(m_path);
    uchar param1 = reader.readByte();
    uchar param2 = reader.readByte();

    if ((param1 != 2) || (param2 != 1))
        qDebug()<<"ERROR - D2PFile - Unable to read file"<<m_path;

    reader.setPosition(reader.getSize()-16);
    uint position = reader.readUInt();
    int contentcount = reader.readUInt();
    reader.setPosition(position);

    for (int i = 0; i <= contentcount; i++)
    {
        CompressedMap *compressedMap = new CompressedMap(&reader, m_path);
        if (compressedMap->isInvalidMap())
        {
            delete compressedMap;
            continue;
        }

        else if(compressedMap->isImage())
            m_contentImage[compressedMap->getImageId()] = compressedMap;

        else if(compressedMap->isMap())
            m_contentMap[compressedMap->getMapId()] = compressedMap;
    }
}
