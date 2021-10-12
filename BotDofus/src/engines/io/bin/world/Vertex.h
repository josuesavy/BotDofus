#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
public:
    Vertex();
    Vertex(double mapId, int zoneId, double vertexUid);

    double getMapId() const;
    int getZoneId() const;
    double getUid() const;

private:
    double m_mapId;
    int m_zoneId;
    double m_vertexUid;
};

#endif // VERTEX_H
