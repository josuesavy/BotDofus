#pragma once

#include "src/engines/io/network/Reader.h"
#include "src/engines/io/d2p/map/elements/enums/ElementTypesEnum.h"
#include "src/engines/io/d2p/map/Map.h"
//#include "GraphicalElement.h"
//#include "SoundElement.h"

class SoundElement;
class GraphicalElement;

class BasicElement
{
public:
    BasicElement()=default;
    BasicElement(Reader *reader, Map *map, int cellId);

    BasicElement *getElement();

private:
    BasicElement *m_element;
};
