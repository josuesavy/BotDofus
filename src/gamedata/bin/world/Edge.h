#ifndef EDGE_H
#define EDGE_H

#include "src/engines/io/bin/world/Vertex.h"
#include "src/engines/io/bin/world/Transition.h"
#include <QSharedPointer>

class Edge
{
public:
    Edge();
    Edge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> to);

    QSharedPointer<Vertex> getFrom();
    QSharedPointer<Vertex> getTo();

    void addTransition(int dir, int type, int skill, QString criterion, double transitionMapId, int cell, int id);

private:
    QSharedPointer<Vertex> m_from;
    QSharedPointer<Vertex> m_to;
    QList<QSharedPointer<Transition>> m_transitions;
};

#endif // EDGE_H
