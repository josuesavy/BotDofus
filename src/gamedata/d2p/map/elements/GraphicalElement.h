#pragma once

#include "src/utils/io/Reader.h"
#include "src/gamedata/d2p/map/Map.h"
#include "BasicElement.h"

#define FIXEDMAPCHANGER_GRAPHICAL_ID 34708

class GraphicalElement : public BasicElement
{
public:
    GraphicalElement(Reader *reader, Map *map, int cellId);

    uint getIdentifier();

private:
    uint m_identifier;
};

