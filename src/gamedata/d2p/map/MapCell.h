#pragma once

#include "src/utils/io/Reader.h"
#include "elements/BasicElement.h"

class Map;
class BasicElement;

class MapCell
{
public:
    MapCell(Reader *reader, Map *map);

    QList<BasicElement> getBasicElements();
    short getCellId();

private:
    QList<BasicElement> m_basicElements;
    short m_cellId;
};
