#ifndef BOUNDINGBOXGRAPHICALELEMENTDATA_H
#define BOUNDINGBOXGRAPHICALELEMENTDATA_H

#include "NormalGraphicalElementData.h"

class BoundingBoxGraphicalElementData : public NormalGraphicalElementData
{
public:
    BoundingBoxGraphicalElementData(int elementId, int elementType);

    void fromRaw(Reader *reader, int version);
};

#endif // BOUNDINGBOXGRAPHICALELEMENTDATA_H
