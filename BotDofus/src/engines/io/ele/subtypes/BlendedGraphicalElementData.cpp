#include "BlendedGraphicalElementData.h"

BlendedGraphicalElementData::BlendedGraphicalElementData(int elementId, int elementType):
    NormalGraphicalElementData(elementId, elementType)
{

}

void BlendedGraphicalElementData::fromRaw(Reader *reader, int version)
{
    uint blendModeLength = reader->readInt();
    m_blendMode = reader->readUTFBytes(blendModeLength);
}
