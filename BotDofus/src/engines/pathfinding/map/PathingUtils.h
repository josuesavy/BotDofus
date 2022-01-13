#ifndef PATHINGUTILS_H
#define PATHINGUTILS_H

#include <QPoint>
#include <QList>
#include <QtMath>
#include <QSharedPointer>
#include <QDebug>

#include "NodeWithOrientation.h"

class PathingUtils
{
public:
    PathingUtils();

    static int coordToCellId(int cellX, int cellY);
    static int coordToCellId(QPoint cellPosition);
    static QPoint cellIdToCoord(int cellId);
    static QList<uint> getCompressedPath(QList<QSharedPointer<NodeWithOrientation>> path);
    static int distanceToPoint(QPoint point1, QPoint point2);
    static int processTime(QList<QSharedPointer<NodeWithOrientation>> path, bool mount);

    static QList<QPoint> m_cellsPositions;

private:
    static const int m_mapHeight;
    static const int m_mapWidth;
    static const int m_mapCellsCount;
    static const int m_walking;
    static const int m_walkingDiagonalVertical;
    static const int m_walkingDiagonalHorizontal;
    static const int m_running;
    static const int m_runningDiagonalVertical;
    static const int m_runningDiagonalHorizontal;
    static const int m_mountWalking;
    static const int m_mountWalkingDiagonalVertical;
    static const int m_mountWalkingDiagonalHorizontal;
    static const int m_mountRunning;
    static const int m_mountRunningDiagonalVertical;
    static const int m_mountRunningDiagonalHorizontal;
};

#endif // PATHINGUTILS_H
