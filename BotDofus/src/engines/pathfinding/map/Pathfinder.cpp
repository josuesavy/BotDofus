#include "Pathfinder.h"

Pathfinder::Pathfinder()
{

}

int Pathfinder::getLoadedMapId()
{
    if (m_currentMap.isInit())
        return m_currentMap.getMapId();
    return 0;
}

void Pathfinder::setMap(Map map, QList<uint> entities, bool useDiagonal)
{
    m_currentMap = map;
    m_useDiagonals = useDiagonal;
    m_matrix.clear();
    m_openList.clear();
    m_find = false;
    CellData cell;
    int id = 0;
    int loc1 = 0;
    int loc2 = 0;
    int loc3 = 0;

    for (int line = 0; line < 20; line++)
    {
        for (int column = 0; column < 14; column++)
        {
            cell = m_currentMap.getCellData()[id];
//            if (entities.contains((uint)id))
//            {
//                cell.setAllowWalk(false);
//            }
            m_matrix.insert(id, QSharedPointer<Node>(new Node(cell.getMapChangeData() != 0, cell.isWalkable(), true, column, loc3, id, QPoint(loc1 + column, loc2 + column))));
            id++;
        }
        loc1++;
        loc3++;
        for (int column = 0; column < 14; column++)
        {
            cell = m_currentMap.getCellData()[id];
//            if (entities.contains((uint)id))
//            {
//                cell.setAllowWalk(false);
//            }
            m_matrix.insert(id, QSharedPointer<Node>(new Node(cell.getMapChangeData() != 0, cell.isWalkable(), true, column, loc3, id, QPoint(loc1 + column, loc2 + column))));
            id++;
        }
        loc3++;
        loc2--;
    }

    qDebug() << "Map end!";
}

QList<uint> Pathfinder::getCompressPath(int startCellId, int destinationCellId)
{
    return PathingUtils::getCompressedPath(find(startCellId, destinationCellId));
}

QList<QSharedPointer<NodeWithOrientation> > Pathfinder::getPath(int startCellId, int destinationCellId)
{
    return find(startCellId, destinationCellId);
}

QList<QSharedPointer<NodeWithOrientation>> Pathfinder::find(int startCellId, int destinationCellId)
{
    m_startCell = m_matrix[startCellId];
    m_destinationCell = m_matrix[destinationCellId];

    m_matrix[startCellId]->setStart(true);
    m_matrix[startCellId]->setInClosedList(true);

    m_matrix[destinationCellId]->setEnd(true);
    m_destinationCell = m_matrix[destinationCellId];
    foreach (QSharedPointer<Node> cell, m_matrix.values())
    {
        cell->setH(m_matrix[destinationCellId]);
    }

    QSharedPointer<Node> currentCell = m_matrix[startCellId];

    int k = 0;
    while (!m_find)
    {
        findAvailableCell(currentCell);

        if (!m_find)
        {
            if (m_openList.size() == 0)
                return QList<QSharedPointer<NodeWithOrientation>>();

            currentCell = m_openList.first();
            currentCell->setInClosedList(true);
            currentCell->setInOpenList(false);
            m_openList.removeFirst();
        }
        k++;
    }


    QList<QSharedPointer<NodeWithOrientation>> cells;
    currentCell = m_matrix[destinationCellId];

    while (currentCell->getParent() != nullptr)
    {
        cells.prepend(QSharedPointer<NodeWithOrientation>(new NodeWithOrientation(currentCell->getId(), currentCell->getLocation().x(), currentCell->getLocation().y())));
        currentCell = currentCell->getParent();
    }
    cells.prepend(QSharedPointer<NodeWithOrientation>(new NodeWithOrientation(startCellId, m_matrix[startCellId]->getLocation().x(), m_matrix[startCellId]->getLocation().y())));
    return cells;
}

void Pathfinder::findAvailableCell(QSharedPointer<Node> cell)
{
    QSharedPointer<Node> availableCell = nullptr;

    // Top-Right
    if (cell->getPosition()[0] == 0 && cell->getPosition()[6] == 0)
    {
        availableCell = cell->getPair() ? m_matrix[cell->getId() - 14] : m_matrix[cell->getId() - 13];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }

        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Bottom-Right
    if (cell->getPosition()[2] == 0 && cell->getPosition()[6] == 0)
    {
        availableCell = cell->getPair() ? m_matrix[cell->getId() + 14] : m_matrix[cell->getId() + 15];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }

        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Top-Left
    if (cell->getPosition()[0] == 0 && cell->getPosition()[4] == 0)
    {
        availableCell = cell->getPair() ? m_matrix[cell->getId() - 15] : m_matrix[cell->getId() - 14];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Bottom-Left
    if (cell->getPosition()[2] == 0 && cell->getPosition()[4] == 0)
    {
        availableCell = cell->getPair() ? m_matrix[cell->getId() + 13] : m_matrix[cell->getId() + 14];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Right
    if (cell->getPosition()[6] == 0 && cell->getPosition()[7] == 0 && m_useDiagonals)
    {
        availableCell = m_matrix[cell->getId() + 1];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Left
    if (cell->getPosition()[4] == 0 && cell->getPosition()[5] == 0 && m_useDiagonals)
    {
        availableCell = m_matrix[cell->getId() - 1];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Top
    if (cell->getPosition()[0] == 0 && cell->getPosition()[1] == 0 && m_useDiagonals)
    {
        availableCell = m_matrix[cell->getId() - 28];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    // Bottom
    if (cell->getPosition()[2] == 0 && cell->getPosition()[3] == 0 && m_useDiagonals)
    {
        availableCell = m_matrix[cell->getId() + 28];
        if (availableCell->getEnd())
        {
            availableCell->setParent(cell);
            m_find = true;
            return;
        }
        if (availableCell->getWalkable())
        {
            if (!availableCell->getInOpenList() && !availableCell->getInClosedList())
            {
                availableCell->setParent(cell);
                availableCell->setInOpenList(true);
                m_openList.append(availableCell);
                fixeCell(availableCell, cell);
            }
        }
    }

    sortOpenList();
}

void Pathfinder::sortOpenList()
{
    bool ok = false;
    while (!ok)
    {
        ok = true;
        QSharedPointer<Node> temp;
        for (int i = 0; i < m_openList.size() - 1; i++)
        {
            if (m_openList[i]->getF() > m_openList[i + 1]->getF() && PathingUtils::distanceToPoint(m_openList[i]->getLocation(), m_destinationCell->getLocation()) < PathingUtils::distanceToPoint(m_openList[i + 1]->getLocation(), m_destinationCell->getLocation()))
            {
                temp = m_openList[i];
                m_openList[i] = m_openList[i + 1];
                m_openList[i + 1] = temp;
                ok = false;
            }
        }
    }
}

void Pathfinder::fixeCell(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell)
{
    double movementCost = getFixedMovementCost(cellInspected, currentCell);
    cellInspected->setG(movementCost);
    cellInspected->setH(getFixedHeuristic(cellInspected, currentCell));
    cellInspected->setF(cellInspected->getG() + cellInspected->getH());
}

double Pathfinder::getFixedMovementCost(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell)
{
    double weight = pointWeight(cellInspected->getLocation());
    return cellInspected->getG() + (cellInspected->getLocation().y() == currentCell->getLocation().y() || cellInspected->getLocation().x() == currentCell->getLocation().x() ? 10.0 : 15.0) * weight;
}

double Pathfinder::getFixedHeuristic(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell)
{
    bool _loc8_ = cellInspected->getLocation().x() + cellInspected->getLocation().y() == m_destinationCell->getLocation().x() + m_destinationCell->getLocation().y();
    bool _loc9_ = cellInspected->getLocation().x() + cellInspected->getLocation().y() == m_startCell->getLocation().x() + m_startCell->getLocation().y();
    bool _loc10_ = cellInspected->getLocation().x() - cellInspected->getLocation().y() == m_destinationCell->getLocation().x() - m_destinationCell->getLocation().y();
    bool _loc11_ = cellInspected->getLocation().x() - cellInspected->getLocation().y() == m_startCell->getLocation().x() - m_startCell->getLocation().y();

    double heuristic = 10 * qSqrt((m_destinationCell->getLocation().x() - cellInspected->getLocation().x()) * (m_destinationCell->getLocation().y() - cellInspected->getLocation().y()) + (m_destinationCell->getLocation().x() - cellInspected->getLocation().x()) * (m_destinationCell->getLocation().x() - cellInspected->getLocation().x()));

    if (cellInspected->getLocation().x() == m_destinationCell->getLocation().x() || cellInspected->getLocation().y() == m_destinationCell->getLocation().y())
    {
        heuristic = heuristic - 3;
    }
    if ((_loc8_) || (_loc10_) || cellInspected->getLocation().x() + cellInspected->getLocation().y() == currentCell->getLocation().x() + currentCell->getLocation().y() || cellInspected->getLocation().x() - cellInspected->getLocation().y() == currentCell->getLocation().x() - currentCell->getLocation().y())
    {
        heuristic = heuristic - 2;
    }
    if (cellInspected->getLocation().x() == m_startCell->getLocation().x() || cellInspected->getLocation().y() == m_startCell->getLocation().y())
    {
        heuristic = heuristic - 3;
    }
    if ((_loc9_) || (_loc11_))
    {
        heuristic = heuristic - 2;
    }

    if (heuristic < 0 || heuristic != heuristic)
    {
        heuristic = 0;
    }

    return heuristic;
}

double Pathfinder::pointWeight(QPoint point)
{
    double result = 1;
    int cellId = PathingUtils::coordToCellId(point.x(), point.y());
    int speed = m_currentMap.getCellData()[cellId].getSpeed();
    if (speed >= 0)
    {
        result = result + (5 - speed);
    }
    else
    {
        result = result + (11 + qAbs(speed));
    }
    return result;
}
