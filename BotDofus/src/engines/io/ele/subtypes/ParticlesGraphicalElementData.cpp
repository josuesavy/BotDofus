#include "ParticlesGraphicalElementData.h"

ParticlesGraphicalElementData::ParticlesGraphicalElementData(int elementId, int elementType):
    GraphicalElementData(elementId, elementType)
{

}

void ParticlesGraphicalElementData::fromRaw(Reader *reader, int version)
{
    m_scriptId = reader->readShort();
}
