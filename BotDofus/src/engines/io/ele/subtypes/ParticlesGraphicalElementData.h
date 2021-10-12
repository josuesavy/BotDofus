#ifndef PARTICLESGRAPHICALELEMENTDATA_H
#define PARTICLESGRAPHICALELEMENTDATA_H

#include "src/engines/io/ele/GraphicalElementData.h"
#include "src/engines/io/network/Reader.h"

class ParticlesGraphicalElementData : public GraphicalElementData
{
public:
    ParticlesGraphicalElementData(int elementId, int elementType);

    void fromRaw(Reader *reader, int version);

private:
    int m_scriptId;
};

#endif // PARTICLESGRAPHICALELEMENTDATA_H
