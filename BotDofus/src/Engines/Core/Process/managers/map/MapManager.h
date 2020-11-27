#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "src/Engines/Core/Process/Managers/AbstractManager.h"

/*!
 * \enum Directions
 * \brief The Directions enum
 *
 * Directions is an enum that has all the different directions associated to an id.
 */
enum Directions
{
    UNKOWN = -1,                /*!< Unknown direction */
    DIRECTION_SOUTH_EAST = 1,   /*!< South East direction */
    DIRECTION_SOUTH = 2,        /*!< South direction */
    DIRECTION_SOUTH_WEST = 3,   /*!< South West direction */
    DIRECTION_WEST = 4,         /*!< West direction */
    DIRECTION_NORTH_WEST = 5,   /*!< South North West direction */
    DIRECTION_NORTH = 6,        /*!< South North direction */
    DIRECTION_NORTH_EAST = 7    /*!< South North East direction */
};

class MapManager : public AbstractManager
{
    Q_OBJECT

public:
    MapManager(QMap<SocketIO*, BotData> *connectionsData);
    ~MapManager();

    /*!
     * \brief stopMoving
     * \param sender Pointer to the bot instance
     *
     * Aborts the bot mouvement and stops it at the current cell.
     */
    void stopMoving(SocketIO *sender);

    /*!
     * \brief changeCell
     * \param sender Pointer to the bot instance
     * \param cellId Cell ID of arrival
     * \return bool Returns true if the bot could move to the cell, false if not
     *
     * Moves the bot to the specified cell ID of the map and confirms the mouvement automatically when the timer is elapsed.
     */
    bool changeCell(SocketIO *sender, uint cellId);

    /*!
     * \brief changeToNearestCell
     * \param sender Pointer to the bot instance
     * \param cellId Cell ID of arrival
     * \return bool Returns true if the bot could move next to the cell, false if not
     *
     * Moves the bot to the nearest cell ID specified making it on purpose that the arrival cell id is NOT the specified cell
     * ID. This is useful for gathering resources such as wheat because the bot needs to be next to the cell without beeing
     * on it. Confirms the mouvement automatically when the timer is elapsed.
     */
    bool changeToNearestCell(SocketIO *sender, uint cellId);

    /*!
     * \brief changeMap
     * \param sender Pointer to the bot instance
     * \param mapSide Side through which the bot should change map
     * \param cellId Overloaded variable. If specified the bot changes map using the specified cell ID. If default value the bot will randomly decide a cell to change map
     * \return bool True if the bot could change map, false if not
     *
     * Changes map through the specified side and using the specified value of cellId (overloaded). If the cell ID is the
     * default value, the bot will randomly choose an avaliable cell that it will use to change map.
     */
    bool changeMap(SocketIO *sender, MapSide mapSide, int cellId = -1);

    /*!
     * \brief changeMap
     * \param sender Pointer to the bot instance
     * \param x X coordonates of the map of arrival
     * \param y Y coordonates of the map of arrival
     * \return bool Returns true if the bot could change map, false if not
     *
     * The bot will attempt to change map using the X and Y coordonates specified.
     */
    bool changeMap(SocketIO *sender, int x, int y);

    /*!
     * \brief changeMap
     * \param sender Pointer to the bot instance
     * \param mapId Map ID of arrival
     * \return bool Returns true if the bot could change map, false if not
     *
     * The bot will attempt to change map using the map ID specified.
     */
    bool changeMap(SocketIO *sender, uint mapId);

    /*!
     * \brief processDirection
     * \param character Played Id of the character on the map
     * \param element Element Id towards which the player should turn
     * \return Directions Orientation of the element according to the character's point of view
     *
     * Returns the orientation of the element according to the character's point of view.
     */
    Directions processDirection(int character, int element);

    /*!
     * \brief changeDirection
     * \param sender Pointer to the bot instance
     * \param dir Orientation which the bot has to turn to
     *
     * Moves the bot to the specified direction.
     */
    void changeDirection(SocketIO *sender, Directions dir);

    void rejoinCharacter(SocketIO *sender, QString character);

private slots:
    void processConfirmation();
    void processMapPath(QList<ChangeMapRequest> requestedMaps, SocketIO *sender);

signals:
    void findMapPath(uint, uint, int, SocketIO*);
    void mapContentUpdated(SocketIO *sender);
    void hasFinishedMoving(SocketIO *sender);
    void couldNotMove(SocketIO *sender);

private:
    QMap<SocketIO*, PathfindingMap*> m_pathfindingThreads;
};

#endif // MAPMANAGER_H
