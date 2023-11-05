#pragma once

#include "src/utils/io/Reader.h"
#include "enums/ElementTypesEnum.h"
#include "src/gamedata/d2p/map/Map.h"
//#include "GraphicalElement.h"
//#include "SoundElement.h"

class SoundElement;
class GraphicalElement;

class BasicElement
{
public:
    BasicElement()=default;
    BasicElement(Reader *reader, Map *map, int cellId);

    QSharedPointer<BasicElement> getElement();

private:
    QSharedPointer<BasicElement> m_element;
};
