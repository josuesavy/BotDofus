#pragma once

#include "src/utils/io/Reader.h"
#include "MapCell.h"

class MapCell;
class Map;

class Layer
{
public:
    Layer(Reader *reader, Map *map);

    QList<MapCell> getMapCells();

private:
    QList<MapCell> m_mapCells;
};
