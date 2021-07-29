#pragma once

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/d2p/map/Map.h"
#include "src/engines/io/d2p/map/elements/BasicElement.h"

#define FIXEDMAPCHANGER_GRAPHICAL_ID 34708

class GraphicalElement : public BasicElement
{
public:
    GraphicalElement(Reader *reader, Map *map, int cellId);

    uint getIdentifier();

private:
    uint m_identifier;
};

