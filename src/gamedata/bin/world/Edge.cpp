#include "Edge.h"

Edge::Edge()
{

}

Edge::Edge(QSharedPointer<Vertex> from, QSharedPointer<Vertex> to)
{
    m_from = from;
    m_to = to;
    m_transitions = QList<QSharedPointer<Transition>>();
}

QSharedPointer<Vertex> Edge::getFrom()
{
    return m_from;
}

QSharedPointer<Vertex> Edge::getTo()
{
    return m_to;
}

void Edge::addTransition(int dir, int type, int skill, QString criterion, double transitionMapId, int cell, int id)
{
    m_transitions.append(QSharedPointer<Transition>(new Transition(type, dir, skill, criterion, transitionMapId, cell, id)));
}
