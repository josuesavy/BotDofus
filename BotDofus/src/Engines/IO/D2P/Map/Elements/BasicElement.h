#pragma once

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/d2p/map/elements/enums/ElementTypesEnum.h"
#include "GraphicalElement.h"
#include "SoundElement.h"

class BasicElement
{
public:
    BasicElement(Reader *reader, Map *map, int cellId);
};
