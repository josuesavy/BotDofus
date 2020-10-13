#pragma once

#include "src/Engines/IO/Network/Reader.h"
#include "src/Engines/IO/D2P/Enums/EnumDeclarator.h"
#include "GraphicalElement.h"
#include "SoundElement.h"

class BasicElement
{
public:
    BasicElement(Reader *reader, Map *map, int cellId);
};
