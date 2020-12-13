#pragma once

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/d2p/map/Map.h"

#define FIXEDMAPCHANGER_GRAPHICAL_ID 34708

class GraphicalElement
{
public:
    GraphicalElement(Reader *reader, Map *map, int cellId);
};

