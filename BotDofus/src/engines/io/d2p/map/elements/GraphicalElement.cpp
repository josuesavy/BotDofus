﻿#include "GraphicalElement.h"

GraphicalElement::GraphicalElement(Reader *reader, Map *map, int cellId)
{
    uint elementId = reader->readUInt();
    uchar hue1 = reader->readByte();
    uchar hue2 = reader->readByte();
    uchar hue3 = reader->readByte();
    uchar shadow1 = reader->readByte();
    uchar shadow2 = reader->readByte();
    uchar shadow3 = reader->readByte();

    if (map->getMapVersion() <= 4)
    {
        uchar offsetX = reader->readByte();
        uchar offsetY = reader->readByte();
    }

    else
    {
        short offsetX = reader->readShort();
        short offsetY = reader->readShort();
    }
    uchar altitude = reader->readByte();
    m_identifier = reader->readUInt();

    if(m_identifier != 0)
        map->m_interactiveElements[m_identifier] = cellId;

    if(elementId == FIXEDMAPCHANGER_GRAPHICAL_ID)
        map->m_fixedMapChangers<<cellId;
}

uint GraphicalElement::getIdentifier()
{
    return m_identifier;
}
