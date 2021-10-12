#include "AnimatedGraphicalElementData.h"

AnimatedGraphicalElementData::AnimatedGraphicalElementData(int elementId, int elementType):
    NormalGraphicalElementData(elementId, elementType)
{

}

void AnimatedGraphicalElementData::fromRaw(Reader *reader, int version)
{
    if(version == 4)
    {
        m_minDelay = reader->readInt();
        m_maxDelay = reader->readInt();
    }
}
