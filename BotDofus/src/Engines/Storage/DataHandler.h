#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#define INVALID -1

#include <QString>
#include <QVariantList>
#include <QSharedPointer>
#include <QTime>

#include "src/Engines/Misc/Logging/LogOutput.h"
#include "src/Protocol/Enums/EnumDeclarator.h"
#include "src/Engines/IO/D2P/D2PManager.h"
#include "src/Engines/IO/D2O/D2OManager.h"
#include "src/Protocol/Types/ClassDeclarator.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/MessageDeclarator.h"
#include "src/Engines/Pathfinding/Map/Pathfinding.h"
#include "src/Engines/Pathfinding/World/PathfindingMap.h"

struct Point2D
{
    double x = INVALID;
    double y = INVALID;
};

struct Point3D : Point2D
{
    float z = INVALID;
};

enum class SuperTypeId
{
    RING = 3,
    BELT = 4,
    HAT = 10,
    CAPE = 11,
    BOOTS = 5,
    AMULET = 1,
    WEAPON = 2,
    SHIELD = 7,
    DOFUS = 13,
    COMPANION = 23,
    PETS_OR_MOUNT = 12,
};

enum class CurrentInteraction
{
    NPC,
    BANK,
    NONE,
    ITEM,
    ZAAP,
    ZAAPI,
};

enum class EntityRendererType
{
    FULL,
    FACE,
};

enum class EntityRendererOrientation
{
    FRONT = 2,
    PROFILE = 0,
    DIAGONAL_LEFT = 3,
    DIAGONAL_RIGHT = 1,
};

enum class Jobs
{
    MINER = 24,
    PESANT = 28,
    ALCHEMIST = 26,
    FISHERMAN = 36,
    LUMBERJACK = 2,
    UNKNOWN = INVALID
};

enum class PlayerD2OFields
{
    WISDOM = 12,
    CHANCE = 13,
    AGILITY = 14,
    STRENGTH = 10,
    VITALITY = 11,
    INTELLIGENCE = 15
};

enum class InventoryCategorie
{
    EQUIPEMENT_CATEGORY,
    CONSUMABLES_CATEGORY,
    RESSOURCES_CATEGORY,
    QUEST_CATEGORY,
    OTHER_CATEGORY
};

enum class ScriptType
{
    MAP, HEADER, FUNCTION, OPEN_TAG, CLOSE_TAG, CONDITION,
};

enum class ScriptTag
{
    BANK, LOST, MOVE, GHOST, CRAFT, FIGHT, COLLECT, NO_AGGRO, UNDEFINED,
};

enum class ScriptFunctionEnum
{
    USE, MOVE, CELL, ZAAP, CRAFT, ZAAPI, TRADE, FIGHT,WEAPON, COLLECT, AUTOPATH, USE_ITEM, NPC_QUIT, UNDEFINED, NPC_DIALOG, NPC_INTERACT,
};

struct ScriptFunction
{
    ScriptFunctionEnum type;
    QVariantList params;
};

struct ScriptPathMapData
{
    int id = INVALID;
    ScriptTag tag;
    QString condition;
    QList<MapSide> sides;
    bool defaultCondition;
    QList<ScriptFunction> functions;
};

struct UsableItem
{
    uint id;
    bool usable;
};

struct Pods
{
    uint max = 0;
    uint current = 0;
};

struct RecipeInfos
{
    uint jobId;
    uint skillId;
    QString name;
    int quantity;
    uint joblevel;
    uint recipeId;
    QMap<uint, uint> ingredients;
};

struct InventoryObject
{
    uint GID;
    uint UID;
    int quantity;
    int regenLife = 0;
    bool isEquipped = false;
    CharacterInventoryPositionEnum position;
};

struct Stats
{
    Pods pods;
    short criticalHitWeapon = INVALID;
    int agressable = INVALID;
    int experience = INVALID;
    int experienceLevelFloor = INVALID;
    int experienceNextLevelFloor = INVALID;
    int statsPoints = INVALID;
    int spellsPoints = INVALID;
    int lifePoints = INVALID;
    int maxLifePoints = INVALID;
    int energyPoints = INVALID;
    int maxEnergyPoints = INVALID;
    int actionPointsCurrent = INVALID;
    int movementPointsCurrent = INVALID;
    int statsRequiredIntelligence = INVALID;
    int statsRequiredAgility = INVALID;
    int statsRequiredChance = INVALID;
    int statsRequiredWisdom = INVALID;
    int statsRequiredVitality = INVALID;
    int statsRequiredStrength = INVALID;
    CharacterBaseCharacteristic initiative;
    CharacterBaseCharacteristic prospecting;
    CharacterBaseCharacteristic actionPoints;
    CharacterBaseCharacteristic movementPoints;
    CharacterBaseCharacteristic strength;
    CharacterBaseCharacteristic vitality; 
    CharacterBaseCharacteristic wisdom;
    CharacterBaseCharacteristic chance;
    CharacterBaseCharacteristic agility;
    CharacterBaseCharacteristic intelligence;
    CharacterBaseCharacteristic range;
    CharacterBaseCharacteristic summonableCreaturesBoost;
    CharacterBaseCharacteristic reflect;
    CharacterBaseCharacteristic criticalHit; 
    CharacterBaseCharacteristic criticalMiss;
    CharacterBaseCharacteristic healBonus;
    CharacterBaseCharacteristic allDamagesBonus;
    CharacterBaseCharacteristic weaponDamagesBonusPercent;
    CharacterBaseCharacteristic damagesBonusPercent;
    CharacterBaseCharacteristic trapBonus;
    CharacterBaseCharacteristic glyphBonusPercent;
    CharacterBaseCharacteristic trapBonusPercent;
    CharacterBaseCharacteristic permanentDamagePercent;
    CharacterBaseCharacteristic tackleBlock;
    CharacterBaseCharacteristic tackleEvade;
    CharacterBaseCharacteristic PAAttack;
    CharacterBaseCharacteristic PMAttack;
    CharacterBaseCharacteristic pushDamageBonus;
    CharacterBaseCharacteristic criticalDamageBonus;
    CharacterBaseCharacteristic neutralDamageBonus;
    CharacterBaseCharacteristic earthDamageBonus;
    CharacterBaseCharacteristic waterDamageBonus;
    CharacterBaseCharacteristic airDamageBonus;
    CharacterBaseCharacteristic fireDamageBonus;
    CharacterBaseCharacteristic dodgePALostProbability;
    CharacterBaseCharacteristic dodgePMLostProbability;
    CharacterBaseCharacteristic neutralElementResistPercent;
    CharacterBaseCharacteristic earthElementResistPercent;
    CharacterBaseCharacteristic waterElementResistPercent;
    CharacterBaseCharacteristic airElementResistPercent;
    CharacterBaseCharacteristic fireElementResistPercent;
    CharacterBaseCharacteristic neutralElementReduction;
    CharacterBaseCharacteristic earthElementReduction;
    CharacterBaseCharacteristic waterElementReduction;
    CharacterBaseCharacteristic airElementReduction;
    CharacterBaseCharacteristic fireElementReduction;
    CharacterBaseCharacteristic pushDamageReduction;
    CharacterBaseCharacteristic criticalDamageReduction;
    CharacterBaseCharacteristic pvpNeutralElementResistPercent;
    CharacterBaseCharacteristic pvpEarthElementResistPercent;
    CharacterBaseCharacteristic pvpWaterElementResistPercent;
    CharacterBaseCharacteristic pvpAirElementResistPercent;
    CharacterBaseCharacteristic pvpFireElementResistPercent;
    CharacterBaseCharacteristic pvpNeutralElementReduction;
    CharacterBaseCharacteristic pvpEarthElementReduction;
    CharacterBaseCharacteristic pvpWaterElementReduction;
    CharacterBaseCharacteristic pvpAirElementReduction;
    CharacterBaseCharacteristic pvpFireElementReduction;
};


enum class ConnectionState
{
    CONNECTED = 1,
    TRANSITION = -1,
    DISCONNECTED = 0
};

enum class ConnectionTo
{
    SERVER = 0,
    CHARACTER = 1,
    GAME = 2
};

struct CharactersCreationInfos
{
    QString name;
    uint server;
    int breed = INVALID;
    int sex = INVALID;
    int head = INVALID;
    QList<int> colors;
    bool skipDidactiel;
};

struct ConnectionInfos
{
    QString login;
    QString server;
    QString password;
    QString character;
    QString alias;
    QString masterGroup;
    int nbrMembers = INVALID;
    int serverId = INVALID;
    bool isBanned = false;
    bool needToCreateCharacter = false;
    bool characterCreated = false;
    bool autoConnect = false;
    ConnectionTo connectionTo = ConnectionTo::SERVER;
    long long int lastConnection = INVALID;
    CharactersCreationInfos creation;
    bool isCharged = false;
};

struct RequestTradeObject
{
    int quantity = INVALID;
    uint GID = INVALID;
    uint UID = INVALID;
    uint price = INVALID;
};

struct RequestedPathInfos
{
   QTime timer;
   PathInfos path;
};

enum BotState
{
    MOVING_STATE,
    MAP_TRANSITION_STATE,
    FARMING_STATE,
    BANKING_STATE,
    INVALID_STATE,
    CRAFTING_STATE,
    FIGHTING_STATE,
    INACTIVE_STATE,
    EXCHANGING_STATE,
    CALCULATING_STATE,
    REGENERATING_STATE
};

struct GroupData
{
    QString master;
    uint partyId = INVALID;
    double masterId = INVALID;
    bool isInGroup = false;
    bool isFollowing = false;
    bool hasRequestedFollowUp = false;
    bool followUp = false;
    Point2D masterPosition;
    QMap<uint, QString> members;
    QMap<uint, QString> currentInvitations;
    QString playerNameInvited;
};

struct HouseInfos
{
    uint houseId = 0;
    QList<uint> doorsOnMap;
    uint modelId = 0;
    QString ownerName;
    bool isOnSale = false;
    bool isSaleLocked = false;
};

struct NpcInfos
{
    int npcId = INVALID;
    int cellId = INVALID;
    int contextualId = INVALID;
};

struct NpcQuestInfos
{
    int npcId = INVALID;
    int cellId = INVALID;
    int contextualId = INVALID;
};

struct MerchantInfos
{
    QString name;
    double merchantId = INVALID;
    uint sellType = INVALID;
    int cellId = INVALID;
    QList<QSharedPointer<HumanOption>> options;
};

struct NpcDisplayInfos
{
    QString name;
    int id = INVALID;
    int cellId = INVALID;
};

struct MonsterDisplayInfos
{
    int nbrMembers = INVALID;
    int level = INVALID;
    int nbStars = INVALID;
    QList<MonsterData> monsters;
};

struct InteractiveDisplayInfos
{
    QString name;
    int id = INVALID;
    int cellId = INVALID;
};

struct EntityInfos
{
    int level = INVALID;
    int cellId = INVALID;
    double entityId = INVALID;
    int direction = INVALID;
    QString name = "NO_NAME";
    QSharedPointer<EntityLook> look;
    QList<uint> keyMovements;
};

struct FightEntityInfos : EntityInfos
{
    bool isAlive = true;
    GameFightMinimalStats stats;
    TeamEnum teamId = TeamEnum::TEAM_SPECTATOR;
};

struct InteractiveSkillInfos
{
    int ID = INVALID;
    int UID = INVALID;
};

struct InteractiveElementInfos
{
    uint elementId;
    uint elementTypeId;
    QList<InteractiveSkillInfos> enabledSkills;
    QList<InteractiveSkillInfos> disabledSkills;
};

struct InteractiveElementAction
{
    uint position;
    int skillInstanceUid;
    InteractiveElementInfos ie;
};

struct ArenaRanksInfos
{
    int rank = 0;
    int maxRank = 0;
    int todayFightCount = 0;
    int todayVictoryCount = 0;
    int leagueId = INVALID;
    QString leagueName;
    bool inLastLeague = false;
    int leagueProgression = INVALID;
    int ladderPosition = INVALID;
    int totalLeaguePoint = INVALID;
    int numFightNeededForLadder = 0;
    QString leagueIconId = "icon_kolizeum01.png";
};

struct ArenaLeague
{
    int id;
    uint nameId;
    uint ornamentId;
    QString icon;
    QString illus;
    bool isLastLeague;
    QString name;
    QString iconWithExtension;
};

struct FightTeamsOptions
{
    bool isSecret = false;
    bool isClosed = false;
    bool isAskingForHelp = false;
    bool isRestrictedToOnly = false;
    bool isExpel = false;
};

enum class SpellCible
{
    SELF = 3,
    ALLY = 1,
    ENEMY = 0,
    DIRECTION = 2,
};

struct RequestedSpell
{
    int castNb = INVALID;
    int spellID = INVALID;
    SpellCible spellCible = SpellCible::ENEMY;
};

struct Spell
{
    int spellID = INVALID;
    int spellLevel = INVALID;
};

struct Monster
{
    int level = INVALID;
    int id = INVALID;
};

struct MonsterGroup
{
    QList<Monster> monsters;
    int cellID = INVALID;
    int contextualID = INVALID;
    int level = INVALID;
    QList<uint> keyMovements;
};

enum class FightIA
{
    FOLLOWER,
    FEARFUL,
    AGGRESSIVE
};

enum class FightPlacementPosition
{
    NONE,
    NEARFUL,
    FARTHER
};

enum class MonsterInclusion
{
    /// Mandatory
    NONE_EXCEPT,
    /// Forbbiden
    ALL_EXCEPT
};

struct BotFightData
{
    QMap<int, int> lastTurnCastBySpell;
    QMap<int ,int> totalCastBySpell;
    QMap<int, int> durationByEffect;
    QMap<int, QMap<int, int> > totalCastByCellBySpell;
    QList<RequestedSpell> processingSpells;
    double botId = INVALID;
    FightIA processingIA = FightIA::FOLLOWER;
    FightPlacementPosition processingPlacementPosition;
    bool isReady = false;
    bool spellsWaiting = false;
    bool movementsWaiting = false;
    bool lastActionWaiting = false;
    bool firstActionWaiting = false;
};

struct MonsterCondition
{
    int id = INVALID;
    int levelMin = INVALID;
    int levelMax = INVALID;
    MonsterInclusion monsterInclusion = MonsterInclusion::ALL_EXCEPT;
};

struct RequestedMonsters
{
    QList<MonsterCondition> monsterConditions;
    int mnNbMonsters = INVALID;
    int mxNbMonsters = INVALID;
    int groupLevelMin = INVALID;
    int groupLevelMax = INVALID;
};

struct BankItem
{
    uint pods;
    uint itemId;
};

struct MovingConfirmationRequest
{
    QSharedPointer<QTimer> timer;      /*!< Timer to callback function */
    QTime elapsedTime;  /*!< Elapsed time of timer */
    int estimatedTime;  /*!< Estimated time to wait before sending mouvement confirm message */
};

enum class ModuleType
{
    UNKNOWN,
    FLOOD,
    FIGHT,
    CONNECTION,
    STATS,
    EXCHANGE,
    GROUP,
    MAP,
    FARM,
    CRAFT,
    SCRIPT,
    INTERACTION,
    ARENA,
    SHOP,
    SECURITY
};

struct PlayerMountData
{
    QString name;
    QString breed;
    int level = INVALID;
    QStringList effects;
    int energy = INVALID;
    int xpRatio = INVALID;
    int energyMax = INVALID;
    float levelRatio = INVALID;
};

struct PetFeedInfos
{
    int GID;
    int UID;
    QString name;
    int waitingTime = 1;
    int foodId = INVALID;
    QSharedPointer<QTimer> timer;
    bool toRemove = false;
};

struct PlayerPetData
{
    bool toggleFeed = false;
    QList<PetFeedInfos> petInfos;
};

enum class BankInclusion
{
    ALL_EXCEPT,
    NONE_EXCEPT
};

struct FloodMessage
{
    QString message;
    Channel channel;
    QTime timer;
    int changeTimer = -1;
    int levelMin = 1;
    int levelMax = 200;
};

// Datas

struct BankData
{
    QList<BankItem> take;
    QList<BankItem> deposit;
    QMap<int, int> toTakeQuantity;
    QMap<int, int> toDepositQuantity;
    BankInclusion takeCondition = BankInclusion::NONE_EXCEPT;
    BankInclusion depositCondition = BankInclusion::NONE_EXCEPT;
};

struct FightData
{
    BotFightData botFightData;
    bool isBotTurn = false;
    FightIA fightIA = FightIA::FOLLOWER;
    FightPlacementPosition fightPlacementPosition = FightPlacementPosition::NONE;
    QList<RequestedSpell> requestedSpells;
    QMap<double, FightEntityInfos> fighters;
    QList<uint> startingPositions;
    QList<uint> startingPositionsOpponent;
    int fightId = INVALID;
    FightTypeEnum fightType;
    FightTeamsOptions options;
    bool lockPartyOnly = false;
    bool lockSecret = false;
    bool lockClosed = false;
    bool lockAskForHelp = false;
    bool lockExpel = false;
    int comeAboutDistance = INVALID;
    RequestedMonsters requestedMonsters;
    int followingMonsterGroup = INVALID;
    bool hasWon = true;
};

struct JobsData
{
    QList<uint> miner;
    QList<uint> peasant;
    QList<uint> fisherman;
    QList<uint> alchemist;
    QList<uint> lumberjack;
};

struct MapData
{
    GameContextEnum gameContext = GameContextEnum::ROLE_PLAY;
    Map map;
    double botId = INVALID;
    QMap<uint, MerchantInfos> merchantsOnMap;
    QMap<uint, NpcInfos> npcsOnMap;
    QMap<uint, NpcQuestInfos> npcsQuestOnMap;
    QMap<uint, EntityInfos> playersOnMap;
    QList<ChangeMapRequest> requestedMaps;
    QMap<uint, MonsterGroup> monsterGroupsOnMap;
    QList<InteractiveElementInfos> interactivesOnMap;
    RequestedPathInfos requestedPath;
    MovingConfirmationRequest confirmationRequest;
    QMap<uint, uint> objectGroundListAdded;
};

struct PlayerData
{
    Stats stats;
    uint kamas = 0;
    uint dofus = 0;
    bool ring = false;
    uint regenRate = 0;
    uint accountId = 0;
    int healPercentage;
    bool isRiding = false;
    int minRegenRatio = 50;
    int maxRegenRatio = 90;
    QMap<int, Spell> spells;
    PlayerMountData mountData;
    bool regenUseObjects = true;
    uint increaseStatId = INVALID;
    QMap<uint, uint> resourceMonitor;
    bool isRequestingFreeSoul = false;
    bool hasSentRequestFreeSoul = false;
    double subscriptionEndDate = INVALID;
    double subscriptionElapsedDuration = INVALID;
    bool automaticallyAcceptAchievement = false;
    QList<InventoryObject> healInventory;
    int breed = 0;
    QList<InventoryObject> inventoryContent;
    PlayerLifeStatusEnum lifeStatus = PlayerLifeStatusEnum::STATUS_ALIVE_AND_KICKING;
    QPixmap headPixmap;
    QPixmap fullPixmap;
};

struct ConnectionData
{
    bool hasRequestedReconnection = false;
    QSharedPointer<QTimer> autoReconnectionTimer;
    QString ticket;
    QTime timeElapsed;
    QByteArray aesKey;
    uint latestSent = 0;
    int sequenceNumber = 0;
    bool reconnectionAuto = false;
    ConnectionInfos connectionInfos;
    ConnectionState connectionState;
    int rawDataRequestIndex = INVALID;
    int greetingMessageIsInitialized = 0;
    bool hasRequestedDisconnection = false;
};

struct FloodData
{
    QList<FloodMessage> flood;
    QTime timer;
    int levelMin = 1;
    int levelMax = 200;
    int changeTimer = -1;
    QString floodMessage;
    int messageIndex = -1;
    QByteArray fileContent;
    QStringList messageFile;
    bool isUsingFile = false;
    QList<Channel> channelList;
};

struct ExchangeData
{
    QList<RequestTradeObject> requestList;
    int sourceId = INVALID;
    bool isLackingKamas = false;
    QList<InventoryObject> objects;
    uint step = 0;
    uint currentKamas = 0;
    bool isActive = false;
    bool isExchangingWithMaster = false;
};

struct FarmData
{
    bool moved = false;
    bool farming = false;
    QList<Jobs> jobs;
    QList<int> elementsId;
    QList<int> resourcesToDelete;
    InteractiveElementAction currentElement;
    QList<InteractiveElementAction> interactiveElementsList;
    QSharedPointer<QTimer> farmTimer;
};

struct CraftData
{
    int step = INVALID;
    RecipeInfos toCraft;
    bool countSet = false;
    bool isCrafting = false;
    QList<RecipeInfos> craftList;
    QMap<uint, uint> recipeStack;
    QList<QString> craftableRecipes;
    QMap<uint, JobExperience> jobs;
    QMap<uint, int> recipeQuantities;
    InteractiveElementInfos craftingBench;
    InteractiveSkillInfos craftingBenchSkill;
};

struct ScriptData
{
    int lastActionMapId = INVALID;
    bool isIndependent = false;
    ushort podsLimitRatio = 95;
    int headers;
    ScriptTag tag;
    QString condition;
    QString fileContent;
    bool isActive = false;
    bool defaultCondition;
    QList<ScriptPathMapData> data;
    QList<ScriptPathMapData> lost;
    QList<ScriptPathMapData> bank;
    QList<ScriptPathMapData> ghost;
    ScriptFunction lastInstruction;
    QList<ScriptFunction> toExecute;
    ModuleType activeModule = ModuleType::UNKNOWN;
    int sequence = -10;
    QTime scriptTimer;
    int scriptMaxTime = INVALID;
};

struct InteractionData
{
    BankData bankData;
    PlayerPetData petData;
    QList<uint> npcDialogs;
    int actionID = INVALID;
    bool finishedAction = true;
    int interactionId = INVALID;
    QList<InteractiveDisplayInfos> interactives;
    CurrentInteraction interactionType = CurrentInteraction::NONE;
};

struct GeneralData
{
    uint logMessageCount = 0;
    QList<LogMessage> logMessages;
    BotState botState = INVALID_STATE;
};

struct ArenaData
{
    PvpArenaStepEnum arenaCurrentStatus = PvpArenaStepEnum::ARENA_STEP_UNREGISTER;
    uint arenaTypeFight = INVALID;
    bool isArenaRegistered = false;
    QList<double> arenaAlliesIds;
    QList<double> arenaReadyPartyMemberIds;
    ArenaRanksInfos arenaRankSoloInfos;
    ArenaRanksInfos arenaRankDuelInfos;
    ArenaRanksInfos arenaRankGroupInfos;
    ArenaLeague arenaLeague;
};

struct StatisticsData
{
    // Characteristics
    int countTotalExperience = 0;
    QMap<int,int> countTotalExperienceJobs;
    int countTotalExperienceMount = 0;
    int countTotalExperienceGuild = 0;
    int countTotalExperienceIncarnation = 0;
    int countTotalGetNewLevel = 0;
    QMap<int,int> countTotalGetNewLevelJobs;
    int countTotalPointVitality = 0;
    int countTotalPointWisdom = 0;
    int countTotalPointStrength = 0;
    int countTotalPointIntelligence = 0;
    int countTotalPointChance = 0;
    int countTotalPointAgility = 0;

    // Inventory
    int countTotalResourcesFight = 0;
    int countTotalResourcesGather = 0;
    int countTotalObjectWonFight = 0;
    int countTotalObjectWonGather = 0;
    int countTotalKamas = 0;

    // Fight
    int countFightSetWon = 0;
    int countFightSetLost = 0;
    int countFightGetWon = 0;
    int countFightGetLost = 0;
    int speedFight = 0;

    // Gather
    int countTotalGatherWon = 0;
    int countTotalGatherLost = 0;

    // Flood
    int countTotalMessageSent = 0;
    int countTotalMessageFailed = 0;

    // Miscellaneous
    int countTotalReconnection = 0;
    int countTotalNotValidatedAchievement = 0;
    int countTotalValidatedAchievement = 0;
    QList<QString> countTotalMetPlayers;
    int countTotalSpeedNetwork = 0;
    int countTotalBackToBank = 0;
    int countTotalBackToPhoenix = 0;
    int countTotalRestartScript = 0;
    int countTotalValidatedQuest = 0;
    int countTotalNewQuest = 0;
};

struct ShopData
{
    QList<RequestTradeObject> requestTradeObjectsInExchangeShop;
    QList<RequestTradeObject> requestTradeObjectsInMerchand;
    QList<RequestTradeObject> tradeObjectsInMerchand;
    bool isReadyToMerchand = false;
    QList<uint> typesItemsCanSell;
    uint maxItemLevel = INVALID;
    uint maxItemPerAccount = INVALID;
    QList<uint> itemInSell;
    QList<uint> objectsTypeSelected;
};

struct MerchandData
{
    QList<QSharedPointer<ObjectItemToSell>> objectsItemToSell;
};

struct BotData
{
    MapData mapData;
    FarmData farmData;
    CraftData craftData;
    FightData fightData;
    FloodData floodData;
    GroupData groupData;
    PlayerData playerData;
    ScriptData scriptData;
    GeneralData generalData;
    ExchangeData exchangeData;
    ConnectionData connectionData;
    InteractionData interactionData;
    ArenaData arenaData;
    StatisticsData statisticsData;
    ShopData shopData;
    MerchandData merchandData;
};

bool operator==(const RequestTradeObject &left, const RequestTradeObject &right);
bool operator==(const InventoryObject &left, const InventoryObject &right);
bool operator<(const InventoryObject &left, const InventoryObject &right);
bool operator==(const ConnectionInfos &left, const ConnectionInfos &right);
bool operator==(const ConnectionInfos &left, const ConnectionInfos &right);
bool operator==(const PetFeedInfos &left, const PetFeedInfos &right);
bool operator<(const PetFeedInfos &left, const PetFeedInfos &right);
bool operator==(const RecipeInfos &left, const RecipeInfos &right);
bool operator==(const RecipeInfos &left, const RecipeInfos &right);
bool operator==(const BankItem &left, const BankItem &right);


class DataHandler
{
public:
    DataHandler();
    DataHandler(QMap<SocketIO*, BotData> *connectionsData);
    ~DataHandler();

    LogOutput &debug(SocketIO *sender);
    LogOutput &info(SocketIO *sender);
    LogOutput &warn(SocketIO *sender);
    LogOutput &error(SocketIO *sender);
    LogOutput &action(SocketIO *sender);

    LogOutput &log(SocketIO *sender, Channel channel);

protected:
    QMap<SocketIO*, BotData> &m_botData;

private:
    bool m_selfInit;
    LogOutput m_logOutput;
    QMap<SocketIO*, BotData> *m_dataPointer;
};

#endif // DATAHANDLER_H
