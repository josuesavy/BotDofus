#include "NormalGraphicalElementData.h"

NormalGraphicalElementData::NormalGraphicalElementData(int elementId, int elementType):
    GraphicalElementData(elementId, elementType)
{

}

void NormalGraphicalElementData::fromRaw(Reader *reader, int version)
{
    m_gfxId = reader->readInt();
    m_height = reader->readByte();
    m_horizontalSymmetry = reader->readBool();
    m_origin = QPoint(reader->readShort(), reader->readShort());
    m_size = QPoint(reader->readShort(), reader->readShort());
}
