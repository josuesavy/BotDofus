#pragma once

#include "src/utils/io/Reader.h"
#include "Vertex.h"
#include "Edge.h"

class WorldGraph
{
public:
    WorldGraph();
    WorldGraph(const QString &WGFile);

    void init(const QString &WGFile);
    QSharedPointer<Vertex> addVertex(double mapId, int zone);
    QSharedPointer<Vertex> getVertex(double mapId, int mapRpZone);
    QSharedPointer<Edge> addEdge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> dest);
    QSharedPointer<Edge> getEdge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> dest);
    QList<QSharedPointer<Edge>> getEdges();

    bool isInit();

private:
    QString m_wgFile;
    bool m_isInit;

    QList<QSharedPointer<Vertex>> m_vertices;
    QList<QSharedPointer<Edge>> m_edges;
    QMap<int,QSharedPointer<Edge>> m_outgoingEdges;
    double m_vertexUid;
};
