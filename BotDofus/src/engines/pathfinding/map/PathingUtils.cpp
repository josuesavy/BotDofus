#include "PathingUtils.h"

QList<QPoint> PathingUtils::m_cellsPositions = QList<QPoint>();
const int PathingUtils::m_mapHeight = 20;
const int PathingUtils::m_mapWidth = 14;
const int PathingUtils::m_mapCellsCount = 560;
const int PathingUtils::m_walking = 300;
const int PathingUtils::m_walkingDiagonalVertical = 300;
const int PathingUtils::m_walkingDiagonalHorizontal = 300;
const int PathingUtils::m_running = 175;
const int PathingUtils::m_runningDiagonalVertical = 155;
const int PathingUtils::m_runningDiagonalHorizontal = 260;
const int PathingUtils::m_mountWalking = 485;
const int PathingUtils::m_mountWalkingDiagonalVertical = 430;
const int PathingUtils::m_mountWalkingDiagonalHorizontal = 515;
const int PathingUtils::m_mountRunning = 140;
const int PathingUtils::m_mountRunningDiagonalVertical = 125;
const int PathingUtils::m_mountRunningDiagonalHorizontal = 205;

PathingUtils::PathingUtils()
{
    int _loc_1 = 0;
    int _loc_2 = 0;
    int _loc_3 = 0;
    int _loc_4 = 0;
    int _loc_5 = 0;

    while (_loc_5 < m_mapHeight)
    {
        _loc_4 = 0;
        while (_loc_4 < m_mapWidth)
        {
            m_cellsPositions[_loc_3] = QPoint(_loc_1 + _loc_4, _loc_2 + _loc_4);
            _loc_3++;
            _loc_4++;
        }
        _loc_1++;
        _loc_4 = 0;
        while (_loc_4 < m_mapWidth)
        {
            m_cellsPositions[_loc_3] = QPoint(_loc_1 + _loc_4, _loc_2 + _loc_4);
            _loc_3++;
            _loc_4++;
        }
        _loc_2 = _loc_2 - 1;
        _loc_5++;
    }
}

int PathingUtils::coordToCellId(int cellX, int cellY)
{
    return ((cellX - cellY) * m_mapWidth + cellY + (cellX - cellY) / 2);
}

int PathingUtils::coordToCellId(QPoint cellPosition)
{
    return coordToCellId(cellPosition.x(), cellPosition.y());
}

QPoint PathingUtils::cellIdToCoord(int cellId)
{
    if (cellId < 0 || cellId >= m_cellsPositions.size())
    {
        qDebug() << "Invalid cell id";
        return QPoint();
    }
    return m_cellsPositions[cellId];
}

QList<uint> PathingUtils::getCompressedPath(QList<QSharedPointer<NodeWithOrientation>> path)
{
    QList<uint> compressedPath;
    if (path.size() < 2)
    {
        foreach (QSharedPointer<NodeWithOrientation> node, path)
        {
            node->setCompressedValue();
            compressedPath.append(node->getCompressedValue());
        }
    }
    else
    {
        for (int i = 0; i < path.size()-1; i++)
        {
            path[i]->setOrientation(path[i+1]);
        }

        path.last()->setOrientation(path[path.size()-2]->getOrientation());
        foreach (QSharedPointer<NodeWithOrientation> node, path)
        {
            node->setCompressedValue();
        }
        compressedPath.append(path.first()->getCompressedValue());
        for (int i = 1; i < path.size()-1; i++)
        {
            if (path[i]->getOrientation() != path[i - 1]->getOrientation())
            {
                compressedPath.append(path[i]->getCompressedValue());
            }
        }

        compressedPath.append(path.last()->getCompressedValue());
    }

    return compressedPath;
}

int PathingUtils::distanceToPoint(QPoint point1, QPoint point2)
{
    return qSqrt((point1.x() - point2.x()) * (point1.x() - point2.x()) + (point1.y() - point2.y()) * (point1.y() - point2.y()));
}

int PathingUtils::distanceToCell(int param1, int param2)
{
    int _loc3_ = qFloor(param1 / 14);
    int _loc4_ = qFloor((_loc3_ + 1) / 2);
    auto _loc5_ = param1 - _loc3_ * 14;
    auto _loc6_ = _loc4_ + _loc5_;
    int _loc7_ = qFloor(param1 / 14);
    int _loc8_ = qFloor((_loc7_ + 1) / 2);
    auto _loc9_ = _loc7_ - _loc8_;
    auto _loc10_ = param1 - _loc7_ * 14;
    auto _loc11_ = _loc10_ - _loc9_;
    int _loc12_ = qFloor(param2 / 14);
    int _loc13_ = qFloor((_loc12_ + 1) / 2);
    auto _loc14_ = param2 - _loc12_ * 14;
    auto _loc15_ = _loc13_ + _loc14_;
    int _loc16_ = qFloor(param2 / 14);
    int _loc17_ = qFloor((_loc16_ + 1) / 2);
    auto _loc18_ = _loc16_ - _loc17_;
    auto _loc19_ = param2 - _loc16_ * 14;
    auto _loc20_ = _loc19_ - _loc18_;

    return qFloor((qAbs(_loc15_ - _loc6_)) + (qAbs(_loc20_ - _loc11_)));
}

int PathingUtils::processTime(QList<QSharedPointer<NodeWithOrientation>> path, bool mount)
{
    int timer = 0;
    if (path.size() <= 2)
    {
        if (mount)
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i]->getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=m_mountWalkingDiagonalHorizontal;
                else if (orientation == 2 || orientation == 5)
                    timer+=m_mountWalkingDiagonalVertical;
                else
                    timer+=m_mountWalking;
            }
        }
        else
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i]->getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=m_walkingDiagonalHorizontal;
                else if (orientation == 2 || orientation == 5)
                    timer+=m_walkingDiagonalVertical;
                else
                    timer+=m_walking;
            }
        }
    }
    else
    {
        if (mount)
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i]->getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=m_mountRunningDiagonalHorizontal;
                else if (orientation == 2 || orientation == 5)
                    timer+=m_mountRunningDiagonalVertical;
                else
                    timer+=m_mountRunning;
            }
        }
        else
        {
            for (int i = 0; i < path.size(); i++)
            {
                int orientation = path[i]->getOrientation();
                if (orientation == 0 || orientation == 7)
                    timer+=m_runningDiagonalHorizontal;
                else if (orientation == 2 || orientation == 5)
                    timer+=m_runningDiagonalVertical;
                else
                    timer+=m_running;
            }
        }
    }

    return timer;
}
