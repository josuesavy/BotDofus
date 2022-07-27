#include "MapCell.h"
#include "elements/BasicElement.h"
#include "Map.h"

MapCell::MapCell(Reader *reader, Map *map)
{
    m_cellId = reader->readShort();
    short elementcount = reader->readShort();

    for (int i = 0; i < elementcount; i++)
        m_basicElements<< BasicElement(reader, map, m_cellId);
}

QList<BasicElement> MapCell::getBasicElements()
{
    return m_basicElements;
}

short MapCell::getCellId()
{
    return m_cellId;
}
