#ifndef ENTITYGRAPHICALELEMENTDATA_H
#define ENTITYGRAPHICALELEMENTDATA_H

#include <QString>

#include "src/engines/io/ele/GraphicalElementData.h"
#include "src/engines/io/network/Reader.h"

class EntityGraphicalElementData : public GraphicalElementData
{
public:
    EntityGraphicalElementData(int elementId, int elementType);

    void fromRaw(Reader *reader, int version);

private:
    QString m_entityLook;
    bool m_horizontalSymmetry;
    bool m_playAnimation;
    bool m_playAnimStatic;
    uint m_minDelay;
    uint m_maxDelay;
};

#endif // ENTITYGRAPHICALELEMENTDATA_H
