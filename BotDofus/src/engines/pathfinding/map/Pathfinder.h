#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <cmath>
#include <QMap>

#include "src/engines/pathfinding/map/PathingUtils.h"
#include "src/engines/pathfinding/map/Node.h"
#include "src/engines/pathfinding/map/NodeWithOrientation.h"
#include "src/engines/io/d2p/D2PManager.h"

struct PathInfos
{
    QList<uint> path;
    int time = -1;
};

struct NearestPathInfos
{
    QList<uint> path;
    int time = -1;
    int dist = 0;
};


class Pathfinder
{
public:
    Pathfinder();

    int getLoadedMapId();
    void setMap(Map map, QList<uint> entities, bool useDiagonal);
    QList<uint> getCompressPath(int startCellId, int destinationCellId);
    QList<QSharedPointer<NodeWithOrientation>> getPath(int startCellId, int destinationCellId);

private:
    QList<QSharedPointer<NodeWithOrientation>> find(int startCellId, int destinationCellId);
    void findAvailableCell(QSharedPointer<Node> cell);
    void sortOpenList();
    void fixeCell(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell);
    double getFixedMovementCost(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell);
    double getFixedHeuristic(QSharedPointer<Node> cellInspected, QSharedPointer<Node> currentCell);
    double pointWeight(QPoint point);

    bool m_useDiagonals;
    bool m_find;

    QSharedPointer<Node> m_destinationCell, m_startCell;
    Map m_currentMap;

    QMap<int, QSharedPointer<Node>> m_matrix;
    QList<QSharedPointer<Node>> m_openList;

    const uint m_mapWidth = 20;
    const uint m_mapHeight = 14;
};

#endif // PATHFINDER_H
