#pragma once

#include "src/engines/io/network/Reader.h"
#include "elements/BasicElement.h"

class MapCell
{
public:
    MapCell(Reader *reader, Map *map);
};
