#include "EntityGraphicalElementData.h"

EntityGraphicalElementData::EntityGraphicalElementData(int elementId, int elementType):
    GraphicalElementData(elementId, elementType)
{

}

void EntityGraphicalElementData::fromRaw(Reader *reader, int version)
{
    uint entityLookLength = reader->readInt();
    m_entityLook = reader->readUTFBytes(entityLookLength);

    m_horizontalSymmetry = reader->readBool();

    if(version >= 7)
    {
        m_playAnimation = reader->readBool();
    }

    if(version >= 6)
    {
        m_playAnimStatic = reader->readBool();
    }

    if(version >= 5)
    {
        m_minDelay = reader->readInt();
        m_maxDelay = reader->readInt();
    }
}


