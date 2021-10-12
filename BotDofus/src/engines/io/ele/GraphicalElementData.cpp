#include "GraphicalElementData.h"

GraphicalElementData::GraphicalElementData(int elementId, int elementType)
{
    m_id = elementId;
    m_type = elementType;
}

GraphicalElementData::~GraphicalElementData()
{

}

void GraphicalElementData::fromRaw(Reader *reader, int version)
{

}
