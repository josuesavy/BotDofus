#include "Elements.h"

Elements::Elements()
{

}

Elements::Elements(Reader *reader)
{
    int header = reader->readByte();
    if (header != 69)
        qDebug() << "Unknown file format";

    m_reader = reader;

    m_fileVersion = reader->readByte();
    m_elementsCount = reader->readUInt();

    uint skypLen = 0;
    int edId = 0;
    for (int i= 0; i < m_elementsCount; i++)
    {
        if (m_fileVersion >= 9)
        {
            skypLen = reader->readUShort();
        }

        edId = reader->readInt();

        if (m_fileVersion <= 8)
        {
            m_elementsIndex[edId] = reader->getPosition();
            readElement(edId);
        }
        else
        {
            m_elementsIndex[edId] = reader->getPosition();
            reader->setPosition(skypLen - 4);
        }
    }

    if (m_fileVersion >= 8)
    {
        int gfxCount = reader->readInt();
        for (int i = 0; i < gfxCount; i++)
        {
            m_jpegMap[reader->readInt()] = true;
        }
    }
}

void Elements::readElement(uint edId)
{
    m_reader->setPosition(m_elementsIndex[edId]);

    int edType = m_reader->readByte();

    QSharedPointer<GraphicalElementData> ed = GraphicalElementFactory::getGraphicalElementData(edId, edType);
    if (!ed)
        return NULL;

    ed.
}
