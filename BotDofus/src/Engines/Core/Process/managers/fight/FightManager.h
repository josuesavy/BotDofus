#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include "src/engines/core/process/managers/AbstractManager.h"
#include "src/engines/core/process/managers/map/MapManager.h"
#include "src/engines/core/process/managers/group/GroupManager.h"

#include <QTime>
#include <QMap>

#define INVALID -1
#define MAP_WIDTH 14
#define MAP_HEIGHT 20
//#define TOLERANCE_ELEVATION 11

enum class SpellInabilityReason
{
    /// <summary>Les points d'action sont insuffisants</summary>
    ACTION_POINTS = -1,
    /// <summary>Le temps de recharge du sort est actif</summary>
    COOL_DOWN = -2,
    /// <summary>L'état n'est pas autorisé</summary>
    FORBIDDEN_STATE = -3,
    /// <summary>La ligne de vue n'est pas dégagée</summary>
    LINE_OF_SIGHT = -4,
    /// <summary>La distance maximum du sort a été dépassée</summary>
    MAX_RANGE = -5,
    /// <summary>La distance minimum du sort a été dépassée</summary>
    MIN_RANGE = -6,
    /// <summary>La cellule doit être vide</summary>
    NEED_FREE_CELL = -7,
    /// <summary>La cellule doit être prise</summary>
    NEED_TAKEN_CELL = -8,
    /// <summary>Le sort peut être lancé</summary>
    OK = 1,
    /// <summary>Le sort n'est pas lancé en ligne alors qu'il le devrait</summary>
    NOT_IN_LINE= -9,
    /// <summary>L'état requis est manquant</summary>
    REQUIRED_STATE = -10,
    /// <summary>Le nombre d'invoquation est dépassé</summary>
    TOO_MANY_INVOCATIONS = -11,
    /// <summary>Le sort a été lancé trop de fois ce tour</summary>
    TOO_MANY_LAUNCH= -12,
    /// <summary>Le sort a été lancé trop de fois sur cette cellule</summary>
    TOO_MANY_LAUNCH_ON_CELL = -13,
    /// <summary>Le sort ne peut pas être lancé pour une raison inconnue</summary>
    UNKNOWN = -16,
    /// <summary>Le personnage ne possède pas le sort indiqué</summary>
    UNKNOWN_SPELL = -14,
    /// <summary>Le sort n'est pas lancé en diagonale alors qu'il le devrait</summary>
    NOT_IN_DIAGONAL = -15
};

enum class SpellType
{
    SUMMON,
    HEAL,
    ATTACK,
    UNKOWN,
    BOOST
};

class FightManager : public AbstractManager
{
    Q_OBJECT

public:
    FightManager(QMap<SocketIO*, BotData> *connectionsData, MapManager *mapManager, GroupManager *groupManager);

    /*!
     * \brief Reset the module
     * \param sender Bot's particular connection
     */
    virtual void reset(SocketIO *sender);

    /*!
     * \brief Set the conditions's list of monster to fight
     * \param sender Bot's particular connection
     * \param requestedMonster The monster's conditions
     */
    void setRequestedMonsters(SocketIO *sender, RequestedMonsters requestedMonster);


    /*!
     * \brief Set the character's intelligence artificial
     * \param sender Bot's particular connection
     * \param fightIA The intelligence artificial
     */
    void setFightIA(SocketIO *sender, FightIA fightIA);


    /*!
     * \brief Set the character's placement position when start fight
     * \param sender Bot's particular connection
     * \param fightPlacementPosition The character's placement position
     */
    void setFightPlacementPosition(SocketIO *sender, FightPlacementPosition fightPlacementPosition);


    /*!
     * \brief Enable the restricted member team
     * \param sender Bot's particular connection
     * \param isPartyOnly Only member team enter or not
     */
    void setPartyOnly(SocketIO *sender, bool isPartyOnly);


    /*!
     * \brief Enable the spectator coming to watch the fight
     * \param sender Bot's particular connection
     * \param isSecret Watch or not
     */
    void setSecret(SocketIO *sender, int value);


    /*!
     * \brief Enable the fight opening
     * \param sender Bot's particular connection
     * \param isClosed Opening or not
     */
    void setClosed(SocketIO *sender, int value);


    /*!
     * \brief Request the help to fight
     * \param sender Bot's particular connection
     * \param isAskForHelp Help or not
     */
    void setAskForHelp(SocketIO *sender, bool isAskForHelp);


    /*!
     * \brief Enable and set the character's approach about the distance
     * \param distance
     */
    void setComeAboutDistance(SocketIO *sender, int distance);


    /*!
     * \brief Give up a fight
     * \param sender Bot's particular connection
     */
    void giveUpFight(SocketIO *sender);


    /*!
     * \brief Set the spells to use in the fights
     * \param sender Bot's particular connection
     * \param requestedSpells The spells to use
     */
    void setRequestedSpells(SocketIO *sender, QList<RequestedSpell> requestedSpells);


    /*!
     * \brief Recover the spells to use in the fights
     * \param sender Bot's particular connection
     * \return QList<RequestedSpell> The spells's list used in the fights
     */
    QList<RequestedSpell> getRequestedSpells(SocketIO *sender) const;


    /*!
     * \brief Recover a cell's position by his identify
     * \param cellID The cell's identify
     * \return Point2D The position (x,y)
     */
    Point2D getCoordsbyCellID(int cellID);


    /*!
     * \brief Recover the cell's identify by his position
     * \param coords The position (x,y)
     * \return int The cell's identify
     */
    int getCellIDFromCoords(Point2D coords);


    /*!
     * \brief Recover the distance between two cells's positions
     * \param source The first position
     * \param destination The second position
     * \return int The distance
     */
    int getDistance(Point2D source, Point2D destination);


    /*!
     * \brief Recover the distance between two cells's identify
     * \param sourceCellID The first identify
     * \param destinationCellID The second identify
     * \return int The distance
     */
    int getDistance(int sourceCellID, int destinationCellID);


    /*!
     * \brief Calcul and recover the damage that a monster will undergo with a specific spell
     * \param sender Bot's particular connection
     * \param spellID The specific spell
     * \param cellID The cell's identify where is the monster
     * \return QMap<int, int> The normal damage and critical damage
     */
    QMap<int, int> getSuddenDamage(SocketIO *sender, int spellID, int cellID);


    /*!
     * \brief Recover the spell type
     * \param sender Bot's particular connection
     * \param spellID The specific spell
     * \return SpellType (Heal, Summon, etc...)
     */
    SpellType getSpellType(SocketIO *sender, int spellID);


    /*!
     * \brief Recover the monsters to fight
     * \param sender Bot's particular connection
     * \return QList<MonsterGroup> Monster's group list
     */
    QList<MonsterGroup> getMonstersToFight(SocketIO *sender);


    /*!
     * \brief Check if there are the monsters to fight
     * \param sender Bot's particular connection
     * \return Monsters to fight or not
     */
    bool isMonstersToFight(SocketIO *sender);

    /*!
     * \brief Check if the monster is a summon
     * \param sender Bot's particular connection
     * \param ennemie The ennemie's cible
     * \return Monsters is a summon or not
     */
    bool isSummon(SocketIO *sender, double ennemie);



public slots:

    /*!
     * \brief Go to fight against a monster group
     * \param sender Bot's particular connection
     * \return bool Going to fight against a monster group in progress or not
     */
    bool processMonsters(SocketIO *sender);



private slots:

    /*!
     * \brief Event when the fight against a monster group is finished
     * \param sender Bot's particular connection
     */
    void processEndFight(SocketIO *sender);


    /*!
     * \brief Event when the moving towards to the monster group is succesful
     * \param sender Bot's particular connection
     */
    void moveSuccess(SocketIO *sender);


    /*!
     * \brief Event when the moving towards to the monster group is failed
     * \param sender Bot's particular connection
     */
    void moveFailure(SocketIO *sender);

public:
    /*!
     * \brief Dispose the character's placement when start fight
     * \param sender Bot's particular connection
     */
    void updateFightDisposition(SocketIO *sender);


    /*!
     * \brief Recover all fighters in the fight
     * \param sender Bot's particular connection
     * \return QList<uint> The fighters's list
     */
    QList<uint> getFighters(SocketIO *sender);


    /*!
     * \brief Recover all allies in the fight
     * \param sender Bot's particular connection
     * \return QList<uint> The allies's list
     */
    QList<uint> getAllies(SocketIO *sender);


    /*!
     * \brief Recover all enemies in the fight
     * \param sender Bot's particular connection
     * \return QList<uint> The enemies's list
     */
    QList<uint> getEnemies(SocketIO *sender);


    /*!
     * \brief Recover the strongest enemy in the fight
     * \param sender Bot's particular connection
     * \return int The strongest enemy's identify
     */
    int getStrongestEnemy(SocketIO *sender);


    /*!
     * \brief Recover the weakest enemy in the fight
     * \param sender Bot's particular connection
     * \return int The weakest enemy's identify
     */
    int getWeakestEnemy(SocketIO *sender);


    /*!
     * \brief Fight the enemies in the fight
     * \param sender Bot's particular connection
     */
    void processTurn(SocketIO *sender);


    /*!
     * \brief Update the character's properties and effects at the end his turn
     * \param sender Bot's particular connection
     */
    void processEndTurn(SocketIO *sender);


    /*!
     * \brief Recover the cell's list farther compared to a cell's identify and cibles's list
     * \param cellID The cell's identify
     * \param cibles The cibles's list
     * \return QList<uint> The cell's list farther
     */
    QList<uint> getFartherCells(uint cellID, QList<uint> cibles);


    /*!
     * \brief Recover the cell farther compared to a cell's identify and cibles's list
     * \param cellID The cell's identify
     * \param cibles The cibles's list
     * \return uint The cell's idendity farther
     */
    uint getFartherCell(uint cellID, QList<uint> cibles);


    /*!
     * \brief Recover the cell's list closest compared to a cell's identify and cibles's list
     * \param cellID The cell's identify
     * \param cibles The cibles's list
     * \return QList<uint> The cell's list closest
     */
    QList<uint> getClosestCells(uint cellID, QList<uint> cibles);


    /*!
     * \brief Recover the cell closest compared to a cell's identify and cibles's list
     * \param cellID The cell's identify
     * \param cibles The cibles's list
     * \return uint The cell's idendity closest
     */
    uint getClosestCell(uint cellID, QList<uint> cibles);


    /*!
     * \brief Recover the cell middle in the cible's list
     * \param cibles The cible's list
     * \return uint The cell's identify of the middle
     */
    uint getMiddleCell(QList<uint> cibles);


    /*!
     * \brief Recover cells's list around a cell within a predefined radius
     * \param cellID The cell's identify
     * \param minRadius The radius's minimum
     * \param radius The radius's size
     * \return QList<uint> The cells's list around of a cible
     */
    QList<uint> getSurroundingCells(int cellID, int minRadius, int radius);


    /*!
     * \brief Recover the inability reason if we will can cast a spell to next turn
     * \param sender Bot's particular connection
     * \param spellID The spell's identify
     * \return SpellInabilityReason The spell's inability reason
     */
    SpellInabilityReason canCastSpellNextTurn(SocketIO *sender, int spellID);


    /*!
     * \brief Recover if it's possible to cast a spell
     * \param sender Bot's particular connection
     * \param spellID The spell's identify
     * \return SpellInabilityReason The spell's inability reason
     */
    SpellInabilityReason canCastSpell(SocketIO *sender, int spellID);


    /*!
     * \brief Recover if it's possible to cast a spell on a cell's identify
     * \param sender Bot's particular connection
     * \param spellID The spell's identify
     * \param cellID The cell's identify
     * \return SpellInabilityReason The spell's inability reason
     */
    SpellInabilityReason canCastSpellOnCell(SocketIO *sender, int spellID, int cellID);


    /*!
     * \brief Check if a cell is free
     * \param sender Bot's particular connection
     * \param cellID The cell's identify
     * \return bool Cell is empty or not
     */
    bool isFreeCell(SocketIO *sender, int cellID);


    /*!
     * \brief Recover the cells's list in line between two cells's identify
     * \param x1 The postion x of the first cell
     * \param y1 The position y of the first cell
     * \param x2 The position x of the second cell
     * \param y2 The position y of the second cell
     * \return QList<Point2D> The positions's list of the line
     */
    QList<Point2D> getLine(int x1, int y1, int x2, int y2);


    /*!
     * \brief Cast a spell on a cell
     * \param sender Bot's particular connection
     * \param spellID The spell's identify to cast
     * \param cellID The cell's identify
     */
    void castSpell(SocketIO *sender, int spellID, int cellID);


    /*!
     * \brief Move the character on the cell
     * \param sender Bot's particular connection
     * \param path The cells's list for the path
     */
    void moveToCell(SocketIO *sender, QList<uint> path);


    /*!
     * \brief Add fighter in the data handler
     * \param sender Bot's particular connection
     * \param fighter The fighter present in the fight
     */
    void addFighter(SocketIO *sender, const QSharedPointer<GameFightFighterInformations> &fighter);


    /*!
     * \brief Check if it's possible to cast a spell close to a cell
     * \param sender Bot's particular connection
     * \param spellID The spell's identify to cast
     * \param cibleID The cible's identify
     * \return bool Can cast near or not
     */
    bool castNear(SocketIO *sender, int spellID, int cibleID);


    /*!
     * \brief Check if it's possible to cast a spell far to a cell
     * \param sender Bot's particular connection
     * \param spellID The spell's identify to cast
     * \param cibleID The cible's identify
     * \return bool Can cast far or not
     */
    bool castAway(SocketIO *sender, int spellID, int cibleID);


    /*!
     * \brief Move on a close cell if it's possible
     * \param sender Bot's particular connection
     * \param cibleID The cible's identify
     * \param distanceWanted The distance wanted
     * \param moveOnlyIfDistancePossible Move or not
     * \return bool Move possible or not
     */
    bool moveNear(SocketIO *sender, int cibleID, int distanceWanted = -1, bool moveOnlyIfDistancePossible = false);


    /*!
     * \brief Move on a far cell if it's possible
     * \param sender Bot's particular connection
     * \param cibleID The cible's identify
     * \param distanceWanted The distance wanted
     * \param moveOnlyIfDistancePossible Move or not
     * \return bool Move possible or not
     */
    bool moveAway(SocketIO *sender, int cibleID, int distanceWanted = -1, bool moveOnlyIfDistancePossible = false);


    /*!
     * \brief Move if it's not possible to reach a cell with a spell
     * \param sender Bot's particular connection
     * \param spellID The cible's identify
     * \param cellID The cell's identify to reach
     * \param moveOnlyIfDistancePossible Move or not
     * \return bool Need to move are not
     */
    bool moveToRange(SocketIO *sender, int spellID, int cellID, bool moveOnlyIfDistancePossible = true);

    MapManager *m_mapManager;
    GroupManager *m_groupManager;
    static QMap<int, Point2D> m_cellsPos;
    static QMap<Point2D, int> m_cellsId;
    QTime fightTimer;
};

#endif // FIGHTMANAGER_H
