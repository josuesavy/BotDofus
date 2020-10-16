#ifndef GAMEDATADECLARATOR_H
#define GAMEDATADECLARATOR_H

#include "src/Engines/IO/D2O/Data/abuse/AbuseReasonsData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentBalanceData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentEffectData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentGiftData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentOrderData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentRankData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentRankJntGiftData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentSideData.h"
#include "src/Engines/IO/D2O/Data/alignments/AlignmentTitleData.h"
#include "src/Engines/IO/D2O/Data/almanax/AlmanaxCalendarData.h"
#include "src/Engines/IO/D2O/Data/ambientSounds/PlaylistSoundData.h"
#include "src/Engines/IO/D2O/Data/appearance/AppearanceData.h"
#include "src/Engines/IO/D2O/Data/appearance/CreatureBoneOverrideData.h"
#include "src/Engines/IO/D2O/Data/appearance/CreatureBoneTypeData.h"
#include "src/Engines/IO/D2O/Data/appearance/OrnamentData.h"
#include "src/Engines/IO/D2O/Data/appearance/SkinMappingData.h"
#include "src/Engines/IO/D2O/Data/appearance/SkinPositionData.h"
#include "src/Engines/IO/D2O/Data/appearance/TitleData.h"
#include "src/Engines/IO/D2O/Data/appearance/TitleCategoryData.h"
#include "src/Engines/IO/D2O/Data/arena/ArenaLeagueData.h"
#include "src/Engines/IO/D2O/Data/arena/ArenaLeagueRewardData.h"
#include "src/Engines/IO/D2O/Data/arena/ArenaLeagueSeasonData.h"
#include "src/Engines/IO/D2O/Data/bonus/BonusData.h"
#include "src/Engines/IO/D2O/Data/bonus/criterion/BonusCriterionData.h"
#include "src/Engines/IO/D2O/Data/breach/BreachDungeonModificatorData.h"
#include "src/Engines/IO/D2O/Data/breach/BreachInfinityLevelData.h"
#include "src/Engines/IO/D2O/Data/breach/BreachWorldMapCoordinateData.h"
#include "src/Engines/IO/D2O/Data/breach/BreachWorldMapSectorData.h"
#include "src/Engines/IO/D2O/Data/breeds/BreedData.h"
#include "src/Engines/IO/D2O/Data/breeds/BreedRoleData.h"
#include "src/Engines/IO/D2O/Data/breeds/BreedRoleByBreedData.h"
#include "src/Engines/IO/D2O/Data/breeds/HeadData.h"
#include "src/Engines/IO/D2O/Data/challenges/ChallengeData.h"
#include "src/Engines/IO/D2O/Data/characteristics/CharacteristicData.h"
#include "src/Engines/IO/D2O/Data/characteristics/CharacteristicCategoryData.h"
#include "src/Engines/IO/D2O/Data/communication/CensoredWordData.h"
#include "src/Engines/IO/D2O/Data/communication/ChatChannelData.h"
#include "src/Engines/IO/D2O/Data/communication/EmoticonData.h"
#include "src/Engines/IO/D2O/Data/communication/InfoMessageData.h"
#include "src/Engines/IO/D2O/Data/communication/NamingRuleData.h"
#include "src/Engines/IO/D2O/Data/communication/SmileyData.h"
#include "src/Engines/IO/D2O/Data/communication/SmileyCategoryData.h"
#include "src/Engines/IO/D2O/Data/communication/SmileyPackData.h"
#include "src/Engines/IO/D2O/Data/documents/DocumentData.h"
#include "src/Engines/IO/D2O/Data/effects/EffectData.h"
#include "src/Engines/IO/D2O/Data/effects/EffectInstanceData.h"
#include "src/Engines/IO/D2O/Data/effects/EvolutiveEffectData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceCreatureData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceDateData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceDiceData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceDurationData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceIntegerData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceLadderData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceMinMaxData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceMountData.h"
#include "src/Engines/IO/D2O/Data/effects/instances/EffectInstanceStringData.h"
#include "src/Engines/IO/D2O/Data/externalnotifications/ExternalNotificationData.h"
#include "src/Engines/IO/D2O/Data/feature/OptionalFeatureData.h"
#include "src/Engines/IO/D2O/Data/guild/EmblemBackgroundData.h"
#include "src/Engines/IO/D2O/Data/guild/EmblemSymbolData.h"
#include "src/Engines/IO/D2O/Data/guild/EmblemSymbolCategoryData.h"
#include "src/Engines/IO/D2O/Data/guild/RankNameData.h"
#include "src/Engines/IO/D2O/Data/houses/HavenbagFurnitureData.h"
#include "src/Engines/IO/D2O/Data/houses/HavenbagThemeData.h"
#include "src/Engines/IO/D2O/Data/houses/HouseData.h"
#include "src/Engines/IO/D2O/Data/idols/IdolData.h"
#include "src/Engines/IO/D2O/Data/interactives/InteractiveData.h"
#include "src/Engines/IO/D2O/Data/interactives/SignData.h"
#include "src/Engines/IO/D2O/Data/interactives/SkillNameData.h"
#include "src/Engines/IO/D2O/Data/interactives/StealthBonesData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AccountRightsItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AchievementAccountItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AchievementItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AchievementObjectiveValidatedData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AchievementPointsItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AlignmentItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AlignmentLevelItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AllianceAvAItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AllianceItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AllianceRightsItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/AreaItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaDuelRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaMaxDuelRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaMaxSoloRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaMaxTeamRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaSoloRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ArenaTeamRankCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/BonesItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/BonusSetItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/BreedItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/CommunityItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/DayItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/EmoteItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/FriendlistItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/GiftItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/GroupItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/GuildItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/GuildLevelItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/GuildRightsItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionFactoryData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ItemCriterionOperatorData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/JobItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/KamaItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/LevelItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/MapCharactersItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/MariedItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/MonsterGroupChallengeCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/MonthItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/MountFamilyItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/NameItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/NewHavenbagItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/NumberOfItemMadeCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/NumberOfMountBirthedCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ObjectItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/PremiumAccountItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/PrestigeLevelItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/PVPRankItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/QuestItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/QuestObjectiveItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/RideItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/RuneByBreakingItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ServerItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ServerSeasonTemporisCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/ServerTypeItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SexItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SkillItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SmileyPackItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SoulStoneItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SpecializationItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SpellItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/StaticCriterionItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SubareaItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SubscribeItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/SubscriptionDurationItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/UnusableItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/criterion/WeightItemCriterionData.h"
#include "src/Engines/IO/D2O/Data/items/EvolutiveItemTypeData.h"
#include "src/Engines/IO/D2O/Data/items/IncarnationData.h"
#include "src/Engines/IO/D2O/Data/items/IncarnationLevelData.h"
#include "src/Engines/IO/D2O/Data/items/ItemData.h"
#include "src/Engines/IO/D2O/Data/items/ItemSetData.h"
#include "src/Engines/IO/D2O/Data/items/ItemTypeData.h"
#include "src/Engines/IO/D2O/Data/items/LegendaryPowerCategoryData.h"
#include "src/Engines/IO/D2O/Data/items/PresetIconData.h"
#include "src/Engines/IO/D2O/Data/items/RandomDropGroupData.h"
#include "src/Engines/IO/D2O/Data/items/RandomDropItemData.h"
#include "src/Engines/IO/D2O/Data/items/VeteranRewardData.h"
#include "src/Engines/IO/D2O/Data/items/WeaponData.h"
#include "src/Engines/IO/D2O/Data/jobs/JobData.h"
#include "src/Engines/IO/D2O/Data/jobs/RecipeData.h"
#include "src/Engines/IO/D2O/Data/jobs/SkillData.h"
#include "src/Engines/IO/D2O/Data/livingObjects/LivingObjectSkinJntMoodData.h"
#include "src/Engines/IO/D2O/Data/livingObjects/SpeakingItemsTriggerData.h"
#include "src/Engines/IO/D2O/Data/livingObjects/SpeakingItemTextData.h"
#include "src/Engines/IO/D2O/Data/misc/BreachBossData.h"
#include "src/Engines/IO/D2O/Data/misc/BreachPrizeData.h"
#include "src/Engines/IO/D2O/Data/misc/CensoredContentData.h"
#include "src/Engines/IO/D2O/Data/misc/CharacterXPMappingData.h"
#include "src/Engines/IO/D2O/Data/misc/LuaFormulaData.h"
#include "src/Engines/IO/D2O/Data/misc/MonthData.h"
#include "src/Engines/IO/D2O/Data/misc/PackData.h"
#include "src/Engines/IO/D2O/Data/misc/SubhintData.h"
#include "src/Engines/IO/D2O/Data/misc/TipsData.h"
#include "src/Engines/IO/D2O/Data/misc/UrlData.h"
#include "src/Engines/IO/D2O/Data/monsters/CompanionData.h"
#include "src/Engines/IO/D2O/Data/monsters/CompanionCharacteristicData.h"
#include "src/Engines/IO/D2O/Data/monsters/CompanionSpellData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterBonusCharacteristicsData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterDropData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterDropCoefficientData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterGradeData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterMiniBossData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterRaceData.h"
#include "src/Engines/IO/D2O/Data/monsters/MonsterSuperRaceData.h"
#include "src/Engines/IO/D2O/Data/mounts/MountData.h"
#include "src/Engines/IO/D2O/Data/mounts/MountBehaviorData.h"
#include "src/Engines/IO/D2O/Data/mounts/MountBoneData.h"
#include "src/Engines/IO/D2O/Data/mounts/MountFamilyData.h"
#include "src/Engines/IO/D2O/Data/mounts/RideFoodData.h"
#include "src/Engines/IO/D2O/Data/notifications/NotificationData.h"
#include "src/Engines/IO/D2O/Data/npcs/NpcData.h"
#include "src/Engines/IO/D2O/Data/npcs/NpcActionData.h"
#include "src/Engines/IO/D2O/Data/npcs/NpcMessageData.h"
#include "src/Engines/IO/D2O/Data/npcs/TaxCollectorFirstnameData.h"
#include "src/Engines/IO/D2O/Data/npcs/TaxCollectorNameData.h"
#include "src/Engines/IO/D2O/Data/playlists/PlaylistData.h"
#include "src/Engines/IO/D2O/Data/quest/AchievementData.h"
#include "src/Engines/IO/D2O/Data/quest/AchievementCategoryData.h"
#include "src/Engines/IO/D2O/Data/quest/AchievementObjectiveData.h"
#include "src/Engines/IO/D2O/Data/quest/AchievementRewardData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveBringItemToNpcData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveBringSoulToNpcData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveCraftItemData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveDiscoverMapData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveDiscoverSubAreaData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveDuelSpecificPlayerData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveFightMonsterData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveFightMonstersOnMapData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveFreeFormData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveGoToNpcData.h"
#include "src/Engines/IO/D2O/Data/quest/objectives/QuestObjectiveMultiFightMonsterData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestCategoryData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestObjectiveData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestObjectiveTypeData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestStepData.h"
#include "src/Engines/IO/D2O/Data/quest/QuestStepRewardsData.h"
#include "src/Engines/IO/D2O/Data/quest/treasureHunt/LegendaryTreasureHuntData.h"
#include "src/Engines/IO/D2O/Data/quest/treasureHunt/PointOfInterestData.h"
#include "src/Engines/IO/D2O/Data/quest/treasureHunt/PointOfInterestCategoryData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerCommunityData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerGameTypeData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerLangData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerPopulationData.h"
#include "src/Engines/IO/D2O/Data/servers/ServerTemporisSeasonData.h"
#include "src/Engines/IO/D2O/Data/sounds/SoundAnimationData.h"
#include "src/Engines/IO/D2O/Data/sounds/SoundBonesData.h"
#include "src/Engines/IO/D2O/Data/sounds/SoundUiData.h"
#include "src/Engines/IO/D2O/Data/sounds/SoundUiElementData.h"
#include "src/Engines/IO/D2O/Data/sounds/SoundUiHookData.h"
#include "src/Engines/IO/D2O/Data/spells/FinishMoveData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellBombData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellConversionData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellLevelData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellPairData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellStateData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellTypeData.h"
#include "src/Engines/IO/D2O/Data/spells/SpellVariantData.h"
#include "src/Engines/IO/D2O/Data/temporis/AchievementProgressData.h"
#include "src/Engines/IO/D2O/Data/temporis/AchievementProgressStepData.h"
#include "src/Engines/IO/D2O/Data/temporis/CustomModeBreedSpellData.h"
#include "src/Engines/IO/D2O/Data/temporis/ForgettableSpellData.h"
#include "src/Engines/IO/D2O/Data/world/AreaData.h"
#include "src/Engines/IO/D2O/Data/world/DungeonData.h"
#include "src/Engines/IO/D2O/Data/world/HintData.h"
#include "src/Engines/IO/D2O/Data/world/HintCategoryData.h"
#include "src/Engines/IO/D2O/Data/world/MapCoordinatesData.h"
#include "src/Engines/IO/D2O/Data/world/MapPositionData.h"
#include "src/Engines/IO/D2O/Data/world/MapReferenceData.h"
#include "src/Engines/IO/D2O/Data/world/MapScrollActionData.h"
#include "src/Engines/IO/D2O/Data/world/PhoenixData.h"
#include "src/Engines/IO/D2O/Data/world/SubAreaData.h"
#include "src/Engines/IO/D2O/Data/world/SuperAreaData.h"
#include "src/Engines/IO/D2O/Data/world/WaypointData.h"
#include "src/Engines/IO/D2O/Data/world/WorldMapData.h"

enum class GameDataEnum
{
    ABUSEREASONSDATA,
    ALIGNMENTBALANCEDATA,
    ALIGNMENTEFFECTDATA,
    ALIGNMENTGIFTDATA,
    ALIGNMENTORDERDATA,
    ALIGNMENTRANKDATA,
    ALIGNMENTRANKJNTGIFTDATA,
    ALIGNMENTSIDEDATA,
    ALIGNMENTTITLEDATA,
    ALMANAXCALENDARDATA,
    PLAYLISTSOUNDDATA,
    APPEARANCEDATA,
    CREATUREBONEOVERRIDEDATA,
    CREATUREBONETYPEDATA,
    ORNAMENTDATA,
    SKINMAPPINGDATA,
    SKINPOSITIONDATA,
    TITLEDATA,
    TITLECATEGORYDATA,
    ARENALEAGUEDATA,
    ARENALEAGUEREWARDDATA,
    ARENALEAGUESEASONDATA,
    BONUSDATA,
    BONUSCRITERIONDATA,
    BREACHDUNGEONMODIFICATORDATA,
    BREACHINFINITYLEVELDATA,
    BREACHWORLDMAPCOORDINATEDATA,
    BREACHWORLDMAPSECTORDATA,
    BREEDDATA,
    BREEDROLEDATA,
    BREEDROLEBYBREEDDATA,
    HEADDATA,
    CHALLENGEDATA,
    CHARACTERISTICDATA,
    CHARACTERISTICCATEGORYDATA,
    CENSOREDWORDDATA,
    CHATCHANNELDATA,
    EMOTICONDATA,
    INFOMESSAGEDATA,
    NAMINGRULEDATA,
    SMILEYDATA,
    SMILEYCATEGORYDATA,
    SMILEYPACKDATA,
    DOCUMENTDATA,
    EFFECTDATA,
    EFFECTINSTANCEDATA,
    EVOLUTIVEEFFECTDATA,
    EFFECTINSTANCECREATUREDATA,
    EFFECTINSTANCEDATEDATA,
    EFFECTINSTANCEDICEDATA,
    EFFECTINSTANCEDURATIONDATA,
    EFFECTINSTANCEINTEGERDATA,
    EFFECTINSTANCELADDERDATA,
    EFFECTINSTANCEMINMAXDATA,
    EFFECTINSTANCEMOUNTDATA,
    EFFECTINSTANCESTRINGDATA,
    EXTERNALNOTIFICATIONDATA,
    OPTIONALFEATUREDATA,
    EMBLEMBACKGROUNDDATA,
    EMBLEMSYMBOLDATA,
    EMBLEMSYMBOLCATEGORYDATA,
    RANKNAMEDATA,
    HAVENBAGFURNITUREDATA,
    HAVENBAGTHEMEDATA,
    HOUSEDATA,
    IDOLDATA,
    INTERACTIVEDATA,
    SIGNDATA,
    SKILLNAMEDATA,
    STEALTHBONESDATA,
    ACCOUNTRIGHTSITEMCRITERIONDATA,
    ACHIEVEMENTACCOUNTITEMCRITERIONDATA,
    ACHIEVEMENTITEMCRITERIONDATA,
    ACHIEVEMENTOBJECTIVEVALIDATEDDATA,
    ACHIEVEMENTPOINTSITEMCRITERIONDATA,
    ALIGNMENTITEMCRITERIONDATA,
    ALIGNMENTLEVELITEMCRITERIONDATA,
    ALLIANCEAVAITEMCRITERIONDATA,
    ALLIANCEITEMCRITERIONDATA,
    ALLIANCERIGHTSITEMCRITERIONDATA,
    AREAITEMCRITERIONDATA,
    ARENADUELRANKCRITERIONDATA,
    ARENAMAXDUELRANKCRITERIONDATA,
    ARENAMAXSOLORANKCRITERIONDATA,
    ARENAMAXTEAMRANKCRITERIONDATA,
    ARENASOLORANKCRITERIONDATA,
    ARENATEAMRANKCRITERIONDATA,
    BONESITEMCRITERIONDATA,
    BONUSSETITEMCRITERIONDATA,
    BREEDITEMCRITERIONDATA,
    COMMUNITYITEMCRITERIONDATA,
    DAYITEMCRITERIONDATA,
    EMOTEITEMCRITERIONDATA,
    FRIENDLISTITEMCRITERIONDATA,
    GIFTITEMCRITERIONDATA,
    GROUPITEMCRITERIONDATA,
    GUILDITEMCRITERIONDATA,
    GUILDLEVELITEMCRITERIONDATA,
    GUILDRIGHTSITEMCRITERIONDATA,
    ITEMCRITERIONDATA,
    ITEMCRITERIONFACTORYDATA,
    ITEMCRITERIONOPERATORDATA,
    JOBITEMCRITERIONDATA,
    KAMAITEMCRITERIONDATA,
    LEVELITEMCRITERIONDATA,
    MAPCHARACTERSITEMCRITERIONDATA,
    MARIEDITEMCRITERIONDATA,
    MONSTERGROUPCHALLENGECRITERIONDATA,
    MONTHITEMCRITERIONDATA,
    MOUNTFAMILYITEMCRITERIONDATA,
    NAMEITEMCRITERIONDATA,
    NEWHAVENBAGITEMCRITERIONDATA,
    NUMBEROFITEMMADECRITERIONDATA,
    NUMBEROFMOUNTBIRTHEDCRITERIONDATA,
    OBJECTITEMCRITERIONDATA,
    PREMIUMACCOUNTITEMCRITERIONDATA,
    PRESTIGELEVELITEMCRITERIONDATA,
    PVPRANKITEMCRITERIONDATA,
    QUESTITEMCRITERIONDATA,
    QUESTOBJECTIVEITEMCRITERIONDATA,
    RIDEITEMCRITERIONDATA,
    RUNEBYBREAKINGITEMCRITERIONDATA,
    SERVERITEMCRITERIONDATA,
    SERVERSEASONTEMPORISCRITERIONDATA,
    SERVERTYPEITEMCRITERIONDATA,
    SEXITEMCRITERIONDATA,
    SKILLITEMCRITERIONDATA,
    SMILEYPACKITEMCRITERIONDATA,
    SOULSTONEITEMCRITERIONDATA,
    SPECIALIZATIONITEMCRITERIONDATA,
    SPELLITEMCRITERIONDATA,
    STATICCRITERIONITEMCRITERIONDATA,
    SUBAREAITEMCRITERIONDATA,
    SUBSCRIBEITEMCRITERIONDATA,
    SUBSCRIPTIONDURATIONITEMCRITERIONDATA,
    UNUSABLEITEMCRITERIONDATA,
    WEIGHTITEMCRITERIONDATA,
    EVOLUTIVEITEMTYPEDATA,
    INCARNATIONDATA,
    INCARNATIONLEVELDATA,
    ITEMDATA,
    ITEMSETDATA,
    ITEMTYPEDATA,
    LEGENDARYPOWERCATEGORYDATA,
    PRESETICONDATA,
    RANDOMDROPGROUPDATA,
    RANDOMDROPITEMDATA,
    VETERANREWARDDATA,
    WEAPONDATA,
    JOBDATA,
    RECIPEDATA,
    SKILLDATA,
    LIVINGOBJECTSKINJNTMOODDATA,
    SPEAKINGITEMSTRIGGERDATA,
    SPEAKINGITEMTEXTDATA,
    BREACHBOSSDATA,
    BREACHPRIZEDATA,
    CENSOREDCONTENTDATA,
    CHARACTERXPMAPPINGDATA,
    LUAFORMULADATA,
    MONTHDATA,
    PACKDATA,
    SUBHINTDATA,
    TIPSDATA,
    URLDATA,
    COMPANIONDATA,
    COMPANIONCHARACTERISTICDATA,
    COMPANIONSPELLDATA,
    MONSTERDATA,
    MONSTERBONUSCHARACTERISTICSDATA,
    MONSTERDROPDATA,
    MONSTERDROPCOEFFICIENTDATA,
    MONSTERGRADEDATA,
    MONSTERMINIBOSSDATA,
    MONSTERRACEDATA,
    MONSTERSUPERRACEDATA,
    MOUNTDATA,
    MOUNTBEHAVIORDATA,
    MOUNTBONEDATA,
    MOUNTFAMILYDATA,
    RIDEFOODDATA,
    NOTIFICATIONDATA,
    NPCDATA,
    NPCACTIONDATA,
    NPCMESSAGEDATA,
    TAXCOLLECTORFIRSTNAMEDATA,
    TAXCOLLECTORNAMEDATA,
    PLAYLISTDATA,
    ACHIEVEMENTDATA,
    ACHIEVEMENTCATEGORYDATA,
    ACHIEVEMENTOBJECTIVEDATA,
    ACHIEVEMENTREWARDDATA,
    QUESTOBJECTIVEBRINGITEMTONPCDATA,
    QUESTOBJECTIVEBRINGSOULTONPCDATA,
    QUESTOBJECTIVECRAFTITEMDATA,
    QUESTOBJECTIVEDISCOVERMAPDATA,
    QUESTOBJECTIVEDISCOVERSUBAREADATA,
    QUESTOBJECTIVEDUELSPECIFICPLAYERDATA,
    QUESTOBJECTIVEFIGHTMONSTERDATA,
    QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA,
    QUESTOBJECTIVEFREEFORMDATA,
    QUESTOBJECTIVEGOTONPCDATA,
    QUESTOBJECTIVEMULTIFIGHTMONSTERDATA,
    QUESTDATA,
    QUESTCATEGORYDATA,
    QUESTOBJECTIVEDATA,
    QUESTOBJECTIVETYPEDATA,
    QUESTSTEPDATA,
    QUESTSTEPREWARDSDATA,
    LEGENDARYTREASUREHUNTDATA,
    POINTOFINTERESTDATA,
    POINTOFINTERESTCATEGORYDATA,
    SERVERDATA,
    SERVERCOMMUNITYDATA,
    SERVERGAMETYPEDATA,
    SERVERLANGDATA,
    SERVERPOPULATIONDATA,
    SERVERTEMPORISSEASONDATA,
    SOUNDANIMATIONDATA,
    SOUNDBONESDATA,
    SOUNDUIDATA,
    SOUNDUIELEMENTDATA,
    SOUNDUIHOOKDATA,
    FINISHMOVEDATA,
    SPELLDATA,
    SPELLBOMBDATA,
    SPELLCONVERSIONDATA,
    SPELLLEVELDATA,
    SPELLPAIRDATA,
    SPELLSTATEDATA,
    SPELLTYPEDATA,
    SPELLVARIANTDATA,
    ACHIEVEMENTPROGRESSDATA,
    ACHIEVEMENTPROGRESSSTEPDATA,
    CUSTOMMODEBREEDSPELLDATA,
    FORGETTABLESPELLDATA,
    AREADATA,
    DUNGEONDATA,
    HINTDATA,
    HINTCATEGORYDATA,
    MAPCOORDINATESDATA,
    MAPPOSITIONDATA,
    MAPREFERENCEDATA,
    MAPSCROLLACTIONDATA,
    PHOENIXDATA,
    SUBAREADATA,
    SUPERAREADATA,
    WAYPOINTDATA,
    WORLDMAPDATA
};

#endif // GAMEDATADECLARATOR_H