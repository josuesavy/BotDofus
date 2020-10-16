#pragma once

#include "src/Engines/IO/Network/Reader.h"
#include "src/Engines/IO/D2P/Map/Map.h"

#define FIXEDMAPCHANGER_GRAPHICAL_ID 34708

class GraphicalElement
{
public:
    GraphicalElement(Reader *reader, Map *map, int cellId);
};

