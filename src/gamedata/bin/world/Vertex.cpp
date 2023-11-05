#include "Vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(double mapId, int zoneId, double vertexUid)
{
    m_mapId = mapId;
    m_zoneId = zoneId;
    m_vertexUid = vertexUid;
}

double Vertex::getMapId() const
{
    return m_mapId;
}

int Vertex::getZoneId() const
{
    return m_zoneId;
}

double Vertex::getUid() const
{
    return m_vertexUid;
}
