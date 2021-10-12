#ifndef GRAPHICALELEMENTDATA_H
#define GRAPHICALELEMENTDATA_H

#include "src/engines/io/network/Reader.h"

class GraphicalElementData
{
public:
    GraphicalElementData(int elementId, int elementType);
    virtual ~GraphicalElementData();

    virtual void fromRaw(Reader *reader, int version);

protected:
    int m_id;
    int m_type;
};

#endif // GRAPHICALELEMENTDATA_H
