#include "Layer.h"
#include "MapCell.h"
#include "Map.h"

Layer::Layer(Reader *reader, Map *map)
{
    int layerId;

    if(map->getMapVersion() >= 9)
        layerId = reader->readByte();
    else
        layerId = reader->readInt();

    short cellcount = reader->readShort();

    if(cellcount > 0)
    {
        for (int i = 0; i < cellcount; i++)
            m_mapCells << MapCell(reader, map);
    }
}

QList<MapCell> Layer::getMapCells()
{
    return m_mapCells;
}

