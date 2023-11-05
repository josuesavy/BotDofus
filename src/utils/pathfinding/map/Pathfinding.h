#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "src/utils/Public.h"
#include "Node.h"
#include <QPoint>
#include <QMap>
#include "src/gamedata/d2p/D2PManager.h"

enum SpeedBehavior
{
    WALKING = 300,
    WALKING_DIAGONAL_HORIZONTAL = 300,
    WALKING_DIAGONAL_VERTICAL = 300,

    RUNNING = 175,
    RUNNING_DIAGONAL_HORIZONTAL = 260,
    RUNNING_DIAGONAL_VERTICAL = 155,

    MOUNT_WALKING = 485,
    MOUNT_WALKING_DIAGONAL_HORIZONTAL = 515,
    MOUNT_WALKING_DIAGONAL_VERTICAL = 430,

    MOUNT_RUNNING = 140,
    MOUNT_RUNNING_DIAGONAL_HORIZONTAL = 205,
    MOUNT_RUNNING_DIAGONAL_VERTICAL = 125
};

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

class Pathfinding
{
public:
    Pathfinding();
    static QPair<uint, uint> getCoordinates(uint cellId); // Constructeur du PathingUtils et de sa methode CellIdToCoord de RaidBot

    /*!
     * \brief findPath
     * \param startId starting cell's id
     * \param endId ending cell's id
     * \param mapId current map's id
     * \param mount on a mount
     * \param diag use diagonal
     * \param entities all entities on the map
     * \return PathInfos
     *
     * Function using the algorithm to find the more short path
     */
    PathInfos findPath(uint startId, uint endId, uint mapId, bool mount = false, bool diag = true, QList<uint> entities = QList<uint>());

    /*!
     * \brief findNearestPath
     * \param startCell starting cell's id
     * \param interactiveElementCell ending cell's id
     * \param mapId current map's id
     * \param mount on a mount
     * \param diag use diagonal
     * \param entities all entities on the map
     * \return  NearestPathInfos
     *
     * Function using the algorithm to find the more short path
     */
    NearestPathInfos findNearestPath(uint startCell, uint interactiveElementCell, uint mapId, bool mount = false, bool diag = true, QList<uint> entities = QList<uint>());

protected:
    void initializeCurrentMap(int mapId);
    void findNeighboringCell(Node c_node, /*Node e_node,*/ bool diag, QList<uint> entities = QList<uint>());
    void addCell(Node cell, Node c_node);
    void sortOpenList();
    void removeNeightboring(QList<Node> &addCells, Node cell);
    int getCellIdFromPoint(int x, int y);
    int processTime(QList<Node> path, bool mount);
    QList<uint> compressPath(QList<Node> path);
    QList<Node> retraceOrientation(QList<Node> path);

    bool m_finishSearch;
    QMap<uint, Node> m_cellPos;
    QList<Node> m_openList;
    QList<CellData> m_currentMap;
    QMap<uint, uint> m_cellHeight;
    static QMap< uint, QPair<uint, uint> > coordinates;
};

#endif // PATHFINDING_H
