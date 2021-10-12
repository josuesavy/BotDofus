#ifndef ANIMATEDGRAPHICALELEMENTDATA_H
#define ANIMATEDGRAPHICALELEMENTDATA_H

#include "NormalGraphicalElementData.h"

class AnimatedGraphicalElementData : public NormalGraphicalElementData
{
public:
    AnimatedGraphicalElementData(int elementId, int elementType);
    void fromRaw(Reader *reader, int version);

private:
    uint m_minDelay;
    uint m_maxDelay;
};

#endif // ANIMATEDGRAPHICALELEMENTDATA_H
