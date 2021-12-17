#include "Node.h"

Node::Node(bool changeMap, bool walkable, bool los, int column, int line, int id, QPoint location)
{
    m_changeMap = changeMap;
    m_walkable = walkable;
    m_los = los;
    m_id = id;
    m_pair = line % 2 == 0;
    m_location = location;
    m_inOpenList = false;
    m_inClosedList = false;
    m_start = false;
    m_end = false;
    m_f = 0;
    m_g = 0;
    m_h = 0;
    m_orientation = 0;
    m_parent = nullptr;

    getBorder(column, line);
}

Node::~Node()
{

}

bool Node::getPair()
{
    return m_pair;
}

bool Node::getChangeMap()
{
    return m_changeMap;
}

bool Node::getWalkable()
{
    return m_walkable;
}

bool Node::getLos()
{
    return m_los;
}

bool Node::getInOpenList()
{
    return m_inOpenList;
}

bool Node::getInClosedList()
{
    return m_inClosedList;
}

bool Node::getStart()
{
    return m_start;
}

bool Node::getEnd()
{
    return m_end;
}

QVector<unsigned char> Node::getPosition()
{
    return m_position;
}

QPoint Node::getLocation()
{
    return m_location;
}

int Node::getId()
{
    return m_id;
}

QSharedPointer<Node> Node::getParent() const
{
    return m_parent;
}

int Node::getF()
{
    return m_f;
}

int Node::getG()
{
    return m_g;
}

int Node::getH()
{
    return m_h;
}

int Node::getOrientation()
{
    return m_orientation;
}

void Node::setInOpenList(bool inOpenList)
{
    m_inOpenList = inOpenList;
}

void Node::setInClosedList(bool inClosedList)
{
    m_inClosedList = inClosedList;
}

void Node::setStart(bool start)
{
    m_start = start;
}

void Node::setEnd(bool end)
{
    m_end = end;
}

void Node::setParent(QSharedPointer<Node> parent)
{
    m_parent = parent;
}

void Node::setG(int g)
{
    m_g = g;
}

void Node::setH(int h)
{
    m_h = h;
}

void Node::setH(QSharedPointer<Node> endNode)
{
    m_h = (uint)(10 * (qAbs(endNode->getLocation().x() - m_location.x()) + qAbs(endNode->getLocation().x() - m_location.y())));
}

void Node::setF(int f)
{
    m_f = f;
}

void Node::getBorder(int column, int line)
{
    m_position = QVector<unsigned char>(8);

    if (line == 0)
        m_position[0] = 1;
    if (line == 1)
        m_position[1] = 1;
    if (line == 39)
        m_position[2] = 1;
    if (line == 38)
        m_position[3] = 1;
    if (column == 0 && m_pair)
        m_position[4] = 1;
    if (column == 0 && !m_pair)
        m_position[5] = 1;
    if (column == 13 && !m_pair)
        m_position[6] = 1;
    if (column == 13 && m_pair)
        m_position[7] = 1;
}
