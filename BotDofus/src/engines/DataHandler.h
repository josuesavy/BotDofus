#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#define INVALID -1

#include <QString>
#include <QVariantList>
#include <QSharedPointer>
#include <QTime>

#include "src/engines/utils/logger/LogOutput.h"
#include "src/protocol/enums/EnumDeclarator.h"
#include "src/engines/io/d2p/D2PManager.h"
#include "src/engines/io/d2o/D2OManager.h"
#include "src/protocol/types/ClassDeclarator.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/MessageDeclarator.h"
#include "src/engines/pathfinding/map/Pathfinding.h"
#include "src/engines/pathfinding/world/PathfindingMap.h"

struct Point2D
{
    double x = INVALID;
    double y = INVALID;
};

struct Point3D : Point2D
{
    float z = INVALID;
};

struct DofusVersion
{
    int major = 0;
    int minor = 0;
    int code = 0;
    int build = 0;
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

enum class StatIds
{
    UNKNOWN = -1,
    LIFE_POINTS = 0,
    ACTION_POINTS,
    STATS_POINTS = 3,
    SPELL_POINTS,
    LEVEL,
    STRENGTH = 10,
    VITALITY,
    WISDOM,
    CHANCE,
    AGILITY,
    INTELLIGENCE,
    ALL_DAMAGES_BONUS,
    DAMAGES_FACTOR,
    CRITICAL_HIT,
    RANGE,
    DAMAGES_PHYSICAL_REDUCTION = 21,
    EXPERIENCE_BOOST,
    MOVEMENT_POINTS,
    INVISIBILITY,
    DAMAGES_PERCENT,
    MAX_SUMMONED_CREATURES_BOOST,
    DODGE_PA_LOST_PROBABILITY,
    DODGE_PM_LOST_PROBABILITY,
    ENERGY_POINTS,
    ALIGNMENT_VALUE,
    WEAPON_DAMAGES_PERCENT,
    PHYSICAL_DAMAGES_BONUS,
    EARTH_ELEMENT_RESIST_PERCENT,
    FIRE_ELEMENT_RESIST_PERCENT,
    WATER_ELEMENT_RESIST_PERCENT,
    AIR_ELEMENT_RESIST_PERCENT,
    NEUTRAL_ELEMENT_RESIST_PERCENT,
    DIFFERENT_LOOK,
    CRITICAL_MISS,
    WEIGHT,
    RESTRICTION_ON_MYSELF,
    RESTRICTION_ON_OTHER,
    ALIGNMENT_SIDE,
    INITIATIVE,
    SHOP_REDUCTION_PERCENTAGE,
    ALIGNMENT_RANK,
    MAX_ENERGY_POINTS,
    MAGIC_FIND,
    HEAL_BONUS,
    REFLECT_DAMAGE,
    ENERGY_LOOSE,
    HONOUR_POINTS,
    DISHOUNOUR_POINTS,
    EARTH_ELEMENT_REDUCTION,
    FIRE_ELEMENT_REDUCTION,
    WATER_ELEMENT_REDUCTION,
    AIR_ELEMENT_REDUCTION,
    NEUTRAL_ELEMENT_REDUCTION,
    PVP_EARTH_ELEMENT_RESIST_PERCENT,
    PVP_FIRE_ELEMENT_RESIST_PERCENT,
    PVP_WATER_ELEMENT_RESIST_PERCENT,
    PVP_AIR_ELEMENT_RESIST_PERCENT,
    PVP_NEUTRAL_ELEMENT_RESIST_PERCENT,
    PVP_EARTH_ELEMENT_REDUCTION,
    PVP_FIRE_ELEMENT_REDUCTION,
    PVP_WATER_ELEMENT_REDUCTION,
    PVP_AIR_ELEMENT_REDUCTION,
    PVP_NEUTRAL_ELEMENT_REDUCTION,
    TRAP_DAMAGE_BONUS_PERCENT,
    TRAP_DAMAGE_BONUS,
    FAKE_SKILL_FOR_STATES,
    SOUL_CAPTURE_BONUS,
    RIDE_XP_BONUS,
    CONFUSION,
    PERMANENT_DAMAGE_PERCENT,
    UNLUCKY,
    MAXIMIZE_ROLL,
    TACKLE_EVADE,
    TACKLE_BLOCK,
    ALLIANCE_AUTO_AGGRESS_RANGE,
    ALLIANCE_AUTO_AGGRESS_RESISTANCE,
    AP_ATTACK,
    MP_ATTACK,
    PUSH_DAMAGE_BONUS,
    PUSH_DAMAGE_REDUCTION,
    CRITICAL_DAMAGE_BONUS,
    CRITICAL_DAMAGE_REDUCTION,
    EARTH_DAMAGE_BONUS,
    FIRE_DAMAGE_BONUS,
    WATER_DAMAGE_BONUS,
    AIR_DAMAGE_BONUS,
    NEUTRAL_DAMAGE_BONUS,
    MAX_BOMB_SUMMON,
    BOMB_COMBO_BONUS,
    MAX_LIFE,
    SHIELD,
    CUR_LIFE,
    DAMAGES_PERCENT_SPELL,
    EXTRA_SCALE_FLAT,
    PASS_TURN,
    RESIST_PERCENT,
    CUR_PERMANENT_DAMAGE,
    WEAPON_POWER,
    INCOMING_DAMAGE_PERCENT_MULTIPLICATOR,
    INCOMING_DAMAGE_HEAL_PERCENT_MULTIPLICATOR,
    GLYPH_POWER,
    DEALT_DAMAGE_MULTIPLIER,
    STOP_XP,
    HUNTER,
    RUNE_POWER,
    DEALT_DAMAGE_MULTIPLIER_MELEE = 112,
    DEALT_DAMAGE_MULTIPLIER_DISTANCE,
    DEALT_DAMAGE_MULTIPLIER_WEAPON,
    RECEIVED_DAMAGE_MULTIPLIER_MELEE,
    DEALT_DAMAGE_MULTIPLIER_SPELLS,
    RECEIVED_DAMAGE_MULTIPLIER_DISTANCE,
    RECEIVED_DAMAGE_MULTIPLIER_WEAPON,
    RECEIVED_DAMAGE_MULTIPLIER_SPELLS,
    AGILITY_INITIAL_PERCENT = 126,
    STRENGTH_INITIAL_PERCENT,
    CHANCE_INITIAL_PERCENT,
    INTELLIGENCE_INITIAL_PERCENT,
    VITALITY_INITIAL_PERCENT,
    WISDOM_INITIAL_PERCENT,
    TACKLE_BLOCK_INITIAL_PERCENT,
    TACKLE_EVADE_INITIAL_PERCENT,
    ACTION_POINTS_INITIAL_PERCENT,
    MOVEMENT_POINTS_INITIAL_PERCENT,
    AP_ATTACK_INITIAL_PERCENT,
    MP_ATTACK_INITIAL_PERCENT,
    DODGE_PA_LOST_PROBABILITY_INITIAL_PERCENT,
    DODGE_PM_LOST_PROBABILITY_INITIAL_PERCENT,
    EXTRA_SCALE_PERCENT,
    CHARAC_COUNT,
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
    int total;
};

struct DetailedStats : Stats
{
    int base;
    int additional;
    int objectsAndMountBonus;
    int alignGiftBonus;
    int contextModif;
};

struct UsableStats : DetailedStats
{
    int used;
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
    bool isLoaded = false;
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
    int direction = INVALID;
    QList<QSharedPointer<HumanOption>> options;
    QSharedPointer<EntityLook> look;
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
    QMap<uint,Stats> stats;
    double summoner;
    bool summoned;
    uint invisibilityState;
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
    int elementTypeId;
    QList<InteractiveSkillInfos> enabledSkills;
    QList<InteractiveSkillInfos> disabledSkills;
};

struct StatedElementsInfos
{
    uint elementId;
    uint elementState;
    uint elementCellId;
};

struct InteractiveElementDoorInfos
{
    uint cellId;
    InteractiveElementInfos interactiveElementInfos;
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

enum class ManagerType
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

struct ShieldCertificate
{
    uint id;
    uint version;
    QString content;
    bool useBasicNetworkInfo;
    bool useAdvancedNetworkInfo;
    bool useBasicInfo;
    bool useUserInfo;
    bool filterVirtualNetwork;
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
    // Fight options
    FightTeamsOptions options;
    bool requestLockPartyOnly = false;
    int requestLockSecret = 0;
    int requestLockClosed = 0;
    bool requestLockAskForHelp = false;

    int comeAboutDistance = INVALID;
    RequestedMonsters requestedMonsters;
    int followingMonsterGroup = INVALID;
    bool hasWon = true;
    uint roundDouble = 0;
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
    QList<StatedElementsInfos> statedElementsOnMap;
    QList<InteractiveElementDoorInfos> doorsOnMap;
    RequestedPathInfos requestedPath;
    MovingConfirmationRequest confirmationRequest;
    QMap<uint, uint> objectGroundListAdded;
};

struct PlayerData
{
    QMap<uint,Stats> stats;
    QList<QSharedPointer<CharacterSpellModification>> spellModifications;
    Pods pods;
    uint kamas = 0;
    uint dofus = 0;
    bool ring = false;
    uint regenRate = 0;
    uint accountId = 0;
    int healPercentage;
    bool isRiding = false;
    QTimer *basicRegen;
    int minRegenRatio = 50;
    int maxRegenRatio = 90;
    QMap<int, Spell> spells;
    PlayerMountData mountData;
    bool regenUseObjects = false;
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

    int experience = INVALID;
    int experienceLevelFloor = INVALID;
    int experienceNextLevelFloor = INVALID;
    int statsRequiredIntelligence = INVALID;
    int statsRequiredAgility = INVALID;
    int statsRequiredChance = INVALID;
    int statsRequiredWisdom = INVALID;
    int statsRequiredVitality = INVALID;
    int statsRequiredStrength = INVALID;
};

struct ConnectionData
{
    bool hasRequestedReconnection = false;
    QSharedPointer<QTimer> autoReconnectionTimer;
    QString ticket;
    QElapsedTimer timeElapsed;
    QByteArray aesKey;
    uint latestSent = 0;
    int sequenceNumber = 0;
    bool reconnectionAuto = false;
    ConnectionInfos connectionInfos;
    ConnectionState connectionState;
    int rawDataRequestIndex = INVALID;
    int greetingMessageIsInitialized = 0;
    bool hasRequestedDisconnection = false;
    bool shieldActive = false;
    QString haapiSessionKey;
    QString haapiApiKey;
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
    ManagerType activeModule = ManagerType::UNKNOWN;
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
    QList<NpcDisplayInfos> npcs;
    CurrentInteraction interactionType = CurrentInteraction::NONE;
};

struct GeneralData
{
    uint logMessageCount = 0;
    QList<LogMessage> logMessages;
    BotState botState = INVALID_STATE;
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
    StatisticsData statisticsData;
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
