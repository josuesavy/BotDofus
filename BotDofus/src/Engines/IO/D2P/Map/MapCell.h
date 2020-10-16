#pragma once

#include "src/Engines/IO/Network/Reader.h"
#include "Elements/BasicElement.h"

class MapCell
{
public:
    MapCell(Reader *reader, Map *map);
};
