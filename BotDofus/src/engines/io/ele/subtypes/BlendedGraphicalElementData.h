#ifndef BLENDEDGRAPHICALELEMENTDATA_H
#define BLENDEDGRAPHICALELEMENTDATA_H

#include "NormalGraphicalElementData.h"

class BlendedGraphicalElementData : public NormalGraphicalElementData
{
public:
    BlendedGraphicalElementData(int elementId, int elementType);

    void fromRaw(Reader *reader, int version);

private:
    QString m_blendMode;
};

#endif // BLENDEDGRAPHICALELEMENTDATA_H
