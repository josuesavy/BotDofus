#include "NodeWithOrientation.h"

NodeWithOrientation::NodeWithOrientation(int id, int x, int y)
{
    m_id = id;
    m_x = x;
    m_y = y;
}

int NodeWithOrientation::getId()
{
    return m_id;
}

int NodeWithOrientation::getOrientation()
{
    return m_orientation;
}

int NodeWithOrientation::getX()
{
    return m_x;
}

int NodeWithOrientation::getY()
{
    return m_y;
}

int NodeWithOrientation::getCompressedValue() const
{
    return m_compressedValue;
}

void NodeWithOrientation::setCompressedValue()
{
    m_compressedValue = (m_orientation & 7) << 12 | (m_id & 4095);
}

void NodeWithOrientation::setOrientation(int orientation)
{
    m_orientation = orientation;
}

void NodeWithOrientation::setOrientation(QSharedPointer<NodeWithOrientation> nextNode)
{
    if (nextNode->getX() == m_x)
    {
        if (nextNode->getY() == m_y + 1)
            m_orientation = 7;
        else if (nextNode->getY() == m_y - 1)
            m_orientation = 3;
    }
    else if (nextNode->getY() == m_y)
    {
        if (nextNode->getX() == m_x + 1)
            m_orientation = 1;
        else if (nextNode->getX() == m_x - 1)
            m_orientation = 5;
    }
    else
    {
        if (nextNode->getX() == m_x + 1 && nextNode->getY() == m_y + 1)
            m_orientation = 0;
        else if (nextNode->getX() == m_x + 1 && nextNode->getY() == m_y - 1)
            m_orientation = 2;
        else if (nextNode->getX() == m_x - 1 && nextNode->getY() == m_y - 1)
            m_orientation = 4;
        else if (nextNode->getX() == m_x - 1 && nextNode->getY() == m_y + 1)
            m_orientation = 6;
    }
}
