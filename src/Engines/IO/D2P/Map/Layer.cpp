#include "Layer.h"

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
            MapCell cell(reader, map);
    }
}

