#include "CellData.h"
#include "src/Engines/IO/D2P/Map/Map.h"

CellData::CellData(int id, Reader *reader, Map *map)
{
    m_id = id;
    m_allowWalk = 0;
    m_floor = reader->readByte() * 10;

    if (m_floor != -1280)
    {
        if(map->getMapVersion() >= 9)
        {
            short tmpBytes = reader->readShort();
            m_walkable = (tmpBytes & 1) == 0;
            m_nonWalkableDuringFight = (tmpBytes& 2) != 0;
            m_nonWalkableDuringRP = (tmpBytes & 4) != 0;
            m_los = (tmpBytes & 8) == 0;
            m_blue = (tmpBytes & 16) != 0;
            m_red = (tmpBytes & 32) != 0;
            m_visible = (tmpBytes & 64) != 0;
            m_farmCell = (tmpBytes & 128) != 0;


            if(map->getMapVersion() >= 10)
            {
                m_havenbagCell = (tmpBytes & 256) != 0;

                if((tmpBytes & 512) != 0)
                    map->addTopArrowCell(id);

                if((tmpBytes & 1024) != 0)
                    map->addBottomArrowCell(id);

                if((tmpBytes & 2048) != 0)
                    map->addRightArrowCell(id);

                if((tmpBytes & 4096) != 0)
                    map->addLeftArrowCell(id);
            }

            else
            {
                if((tmpBytes & 256) != 0)
                    map->addTopArrowCell(id);

                if((tmpBytes & 512) != 0)
                    map->addBottomArrowCell(id);

                if((tmpBytes & 1024) != 0)
                    map->addRightArrowCell(id);

                if((tmpBytes & 2048) != 0)
                    map->addLeftArrowCell(id);
            }
        }

        else
        {
            uchar losmov = reader->readUByte();
            m_los = (losmov & 2) >> 1 == 1;
            m_walkable = (losmov & 1) == 1;
            m_visible = (losmov & 64) >> 6 == 1;
            m_farmCell = (losmov & 32) >> 5 == 1;
            m_blue = (losmov & 16) >> 4 == 1;
            m_red = (losmov & 8) >> 3 == 1;
            m_nonWalkableDuringRP = (losmov & 128) >> 7 == 1;
            m_nonWalkableDuringFight = (losmov & 4) >> 2 == 1;
        }

        m_speed = reader->readByte();
        m_mapChangeData = reader->readUByte();

        if(map->getMapVersion() > 5)
            m_moveZone = reader->readUByte();

        if(map->getMapVersion() > 10 && ((m_walkable && !m_farmCell) || (m_walkable && !m_nonWalkableDuringFight && !m_farmCell && !m_havenbagCell)))
            m_linkedZone = reader->readUByte();

        if(map->getMapVersion() > 7 && map->getMapVersion() < 9)
        {
            int tmpBits = reader->readByte();
            m_arrow = 15 & tmpBits;

            if(!((m_arrow & 1) == 0))
                map->addTopArrowCell(id);

            if(!((m_arrow & 2) == 0))
                map->addBottomArrowCell(id);

            if(!((m_arrow & 4) == 0))
                map->addRightArrowCell(id);

            if(!((m_arrow & 8) == 0))
                map->addLeftArrowCell(id);
        }
    }
}

CellData::CellData()
{

}

int CellData::getId() const
{
    return m_id;
}

bool CellData::isLos() const
{
    return m_los;
}

bool CellData::isWalkable() const
{
    if (m_allowWalk == 1)
        return true;
    else if (m_allowWalk == 2)
        return false;
    else
        return m_walkable;
}

bool CellData::isNonWalkableDuringFight() const
{
    return m_nonWalkableDuringFight;
}

bool CellData::isNonWalkableDuringRP() const
{
    return m_nonWalkableDuringRP;
}

bool CellData::isFarmCell() const
{
    return m_farmCell;
}

bool CellData::isVisible() const
{
    return m_visible;
}

bool CellData::isHavenbagCell() const
{
    return m_havenbagCell;
}

uint CellData::getMapChangeData() const
{
    return m_mapChangeData;
}

int CellData::getSpeed() const
{
    return m_speed;
}

int CellData::getFloor() const
{
    return m_floor;
}

uint CellData::getMoveZone() const
{
    return m_moveZone;
}

void CellData::setAllowWalk(int w)
{
    m_allowWalk = w;
}
