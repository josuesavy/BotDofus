#include "WorldGraph.h"

WorldGraph::WorldGraph():
    m_wgFile(QString()),
    m_isInit(false)
{

}

WorldGraph::WorldGraph(const QString &WGFile)
{
    init(WGFile);
}

void WorldGraph::init(const QString &WGFile)
{
    m_wgFile = WGFile;
    QSharedPointer<Vertex> from;
    QSharedPointer<Vertex> dest;
    QSharedPointer<Edge> edge;

    Reader reader(m_wgFile);
    int edgeCount = reader.readInt();
    for (int i = 0; i < edgeCount; i++)
    {
        from = addVertex(reader.readDouble(), reader.readInt());
        dest = addVertex(reader.readDouble(), reader.readInt());
        edge = addEdge(from, dest);

        int transitionCount = reader.readInt();
        for (int j = 0; j < transitionCount; j++)
        {
            edge->addTransition(reader.readByte(),reader.readByte(),reader.readInt(),reader.readUTFBytes(reader.readInt()),reader.readDouble(),reader.readInt(),reader.readDouble());
        }
    }
}

QSharedPointer<Vertex> WorldGraph::addVertex(double mapId, int zone)
{
    QSharedPointer<Vertex> vertex = QSharedPointer<Vertex>(new Vertex(mapId, zone, m_vertexUid+1));

    if (!m_vertices.contains(vertex))
        m_vertices.append(vertex);

    return vertex;
}

QSharedPointer<Vertex> WorldGraph::getVertex(double mapId, int mapRpZone)
{
    foreach (QSharedPointer<Vertex> vertex, m_vertices)
    {
        if (vertex->getMapId() == mapId && vertex->getZoneId() == mapRpZone)
            return vertex;
    }

    return NULL;
}

QSharedPointer<Edge> WorldGraph::addEdge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> dest)
{
    QSharedPointer<Edge> edge = getEdge(from, dest);
    if (edge)
        return edge;

    if (!from || !dest)
        return NULL;

    m_edges.append(edge);

    if (!m_outgoingEdges.contains(from->getUid()))
        m_outgoingEdges.insert(from->getUid(), edge);

    return edge;
}

QSharedPointer<Edge> WorldGraph::getEdge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> dest)
{
    foreach (QSharedPointer<Edge> edge, m_edges)
    {
        if (edge->getFrom() == from && edge->getTo() == dest)
            return edge;
    }

    return NULL;
}

QList<QSharedPointer<Edge> > WorldGraph::getEdges()
{
    return m_edges;
}
