#ifndef GAMEDATADECLARATOR_H
#define GAMEDATADECLARATOR_H

#include "src/protocol/datacenter/data/abuse/AbuseReasonsData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentGiftData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentOrderData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentRankData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentRankJntGiftData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentSideData.h"
#include "src/protocol/datacenter/data/alignments/AlignmentTitleData.h"
#include "src/protocol/datacenter/data/alliance/AllianceRankData.h"
#include "src/protocol/datacenter/data/alliance/AllianceRankNameSuggestionData.h"
#include "src/protocol/datacenter/data/alliance/AllianceRightData.h"
#include "src/protocol/datacenter/data/alliance/AllianceRightGroupData.h"
#include "src/protocol/datacenter/data/alliance/AllianceTagData.h"
#include "src/protocol/datacenter/data/alliance/AllianceTagsTypeData.h"
#include "src/protocol/datacenter/data/alliance/KothRoleData.h"
#include "src/protocol/datacenter/data/almanax/AlmanaxCalendarData.h"
#include "src/protocol/datacenter/data/alterations/AlterationData.h"
#include "src/protocol/datacenter/data/alterations/AlterationCategoryData.h"
#include "src/protocol/datacenter/data/ambientSounds/PlaylistSoundData.h"
#include "src/protocol/datacenter/data/appearance/AppearanceData.h"
#include "src/protocol/datacenter/data/appearance/CreatureBoneOverrideData.h"
#include "src/protocol/datacenter/data/appearance/CreatureBoneTypeData.h"
#include "src/protocol/datacenter/data/appearance/OrnamentData.h"
#include "src/protocol/datacenter/data/appearance/SkinMappingData.h"
#include "src/protocol/datacenter/data/appearance/SkinPositionData.h"
#include "src/protocol/datacenter/data/appearance/TitleData.h"
#include "src/protocol/datacenter/data/appearance/TitleCategoryData.h"
#include "src/protocol/datacenter/data/arena/ArenaLeagueData.h"
#include "src/protocol/datacenter/data/arena/ArenaLeagueRewardData.h"
#include "src/protocol/datacenter/data/bonus/BonusData.h"
#include "src/protocol/datacenter/data/bonus/criterion/BonusCriterionData.h"
#include "src/protocol/datacenter/data/breach/BreachDungeonModificatorData.h"
#include "src/protocol/datacenter/data/breach/BreachInfinityLevelData.h"
#include "src/protocol/datacenter/data/breach/BreachWorldMapCoordinateData.h"
#include "src/protocol/datacenter/data/breach/BreachWorldMapSectorData.h"
#include "src/protocol/datacenter/data/breeds/BreedData.h"
#include "src/protocol/datacenter/data/breeds/BreedRoleData.h"
#include "src/protocol/datacenter/data/breeds/BreedRoleByBreedData.h"
#include "src/protocol/datacenter/data/breeds/HeadData.h"
#include "src/protocol/datacenter/data/challenges/ChallengeData.h"
#include "src/protocol/datacenter/data/characteristics/CharacteristicData.h"
#include "src/protocol/datacenter/data/characteristics/CharacteristicCategoryData.h"
#include "src/protocol/datacenter/data/collection/CollectableData.h"
#include "src/protocol/datacenter/data/collection/CollectionData.h"
#include "src/protocol/datacenter/data/communication/CensoredWordData.h"
#include "src/protocol/datacenter/data/communication/ChatChannelData.h"
#include "src/protocol/datacenter/data/communication/EmoticonData.h"
#include "src/protocol/datacenter/data/communication/InfoMessageData.h"
#include "src/protocol/datacenter/data/communication/NamingRuleData.h"
#include "src/protocol/datacenter/data/communication/SmileyData.h"
#include "src/protocol/datacenter/data/communication/SmileyCategoryData.h"
#include "src/protocol/datacenter/data/communication/SmileyPackData.h"
#include "src/protocol/datacenter/data/documents/DocumentData.h"
#include "src/protocol/datacenter/data/effects/EffectData.h"
#include "src/protocol/datacenter/data/effects/EffectInstanceData.h"
#include "src/protocol/datacenter/data/effects/EvolutiveEffectData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceCreatureData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceDateData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceDiceData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceDurationData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceIntegerData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceLadderData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceMinMaxData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceMountData.h"
#include "src/protocol/datacenter/data/effects/instances/EffectInstanceStringData.h"
#include "src/protocol/datacenter/data/externalnotifications/ExternalNotificationData.h"
#include "src/protocol/datacenter/data/feature/OptionalFeatureData.h"
#include "src/protocol/datacenter/data/guild/GuildRankData.h"
#include "src/protocol/datacenter/data/guild/GuildRankNameSuggestionData.h"
#include "src/protocol/datacenter/data/guild/GuildRightData.h"
#include "src/protocol/datacenter/data/guild/GuildRightGroupData.h"
#include "src/protocol/datacenter/data/guild/GuildTagData.h"
#include "src/protocol/datacenter/data/guild/GuildTagsTypeData.h"
#include "src/protocol/datacenter/data/houses/HavenbagFurnitureData.h"
#include "src/protocol/datacenter/data/houses/HavenbagThemeData.h"
#include "src/protocol/datacenter/data/houses/HouseData.h"
#include "src/protocol/datacenter/data/interactives/InteractiveData.h"
#include "src/protocol/datacenter/data/interactives/SignData.h"
#include "src/protocol/datacenter/data/interactives/SkillNameData.h"
#include "src/protocol/datacenter/data/interactives/StealthBonesData.h"
#include "src/protocol/datacenter/data/items/criterion/AccountRightsItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AchievementAccountItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AchievementItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AchievementObjectiveValidatedData.h"
#include "src/protocol/datacenter/data/items/criterion/AchievementPioneerItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AchievementPointsItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AlignmentItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AlignmentLevelItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AllianceAvAItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AllianceItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AllianceMasterItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AllianceRightsItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AlterationCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/AreaItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/Arena1V1LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/Arena2V2LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/Arena3V3LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ArenaMax1V1LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ArenaMax2V2LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ArenaMax3V3LeagueCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/BonesItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/BonusSetItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/BreedItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/CommunityItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/CriterionUtilsData.h"
#include "src/protocol/datacenter/data/items/criterion/DayItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/EmoteItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/FriendlistItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GiftItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GroupItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GuildItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GuildLevelItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GuildMasterItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/GuildRightsItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionFactoryData.h"
#include "src/protocol/datacenter/data/items/criterion/ItemCriterionOperatorData.h"
#include "src/protocol/datacenter/data/items/criterion/JobItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/KamaItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/LevelItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MapCharactersItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MapItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MariedItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MonsterGroupChallengeCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MonthItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/MountFamilyItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/NameItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/NewHavenbagItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/NumberOfItemMadeCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/NumberOfMountBirthedCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ObjectItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/OnlySetCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/OptionalFeatureEnabledCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/PremiumAccountItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/PrestigeLevelItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/PrismOnMapStateItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/PVPRankItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/QuestItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/QuestObjectiveItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/RideItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/RuneByBreakingItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SeasonCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ServerItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/ServerTypeItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SexItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SkillItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SmileyPackItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SoulStoneItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SpecializationItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SpellItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/StateCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/StaticCriterionItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SubareaItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SubareaLevelItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SubscribeItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/SubscriptionDurationItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/UnusableItemCriterionData.h"
#include "src/protocol/datacenter/data/items/criterion/WeightItemCriterionData.h"
#include "src/protocol/datacenter/data/items/EvolutiveItemTypeData.h"
#include "src/protocol/datacenter/data/items/IncarnationData.h"
#include "src/protocol/datacenter/data/items/IncarnationLevelData.h"
#include "src/protocol/datacenter/data/items/ItemData.h"
#include "src/protocol/datacenter/data/items/ItemSetData.h"
#include "src/protocol/datacenter/data/items/ItemSuperTypeData.h"
#include "src/protocol/datacenter/data/items/ItemTypeData.h"
#include "src/protocol/datacenter/data/items/LegendaryPowerCategoryData.h"
#include "src/protocol/datacenter/data/items/PresetIconData.h"
#include "src/protocol/datacenter/data/items/RandomDropGroupData.h"
#include "src/protocol/datacenter/data/items/RandomDropItemData.h"
#include "src/protocol/datacenter/data/items/VeteranRewardData.h"
#include "src/protocol/datacenter/data/items/WeaponData.h"
#include "src/protocol/datacenter/data/jobs/JobData.h"
#include "src/protocol/datacenter/data/jobs/RecipeData.h"
#include "src/protocol/datacenter/data/jobs/SkillData.h"
#include "src/protocol/datacenter/data/livingObjects/LivingObjectSkinJntMoodData.h"
#include "src/protocol/datacenter/data/livingObjects/SpeakingItemsTriggerData.h"
#include "src/protocol/datacenter/data/livingObjects/SpeakingItemTextData.h"
#include "src/protocol/datacenter/data/misc/BreachBossData.h"
#include "src/protocol/datacenter/data/misc/BreachPrizeData.h"
#include "src/protocol/datacenter/data/misc/CensoredContentData.h"
#include "src/protocol/datacenter/data/misc/CharacterXPMappingData.h"
#include "src/protocol/datacenter/data/misc/LuaFormulaData.h"
#include "src/protocol/datacenter/data/misc/MonthData.h"
#include "src/protocol/datacenter/data/misc/PackData.h"
#include "src/protocol/datacenter/data/misc/SubhintData.h"
#include "src/protocol/datacenter/data/misc/TipsData.h"
#include "src/protocol/datacenter/data/monsters/CompanionData.h"
#include "src/protocol/datacenter/data/monsters/CompanionCharacteristicData.h"
#include "src/protocol/datacenter/data/monsters/CompanionSpellData.h"
#include "src/protocol/datacenter/data/monsters/MonsterData.h"
#include "src/protocol/datacenter/data/monsters/MonsterBonusCharacteristicsData.h"
#include "src/protocol/datacenter/data/monsters/MonsterDropData.h"
#include "src/protocol/datacenter/data/monsters/MonsterDropCoefficientData.h"
#include "src/protocol/datacenter/data/monsters/MonsterGradeData.h"
#include "src/protocol/datacenter/data/monsters/MonsterMiniBossData.h"
#include "src/protocol/datacenter/data/monsters/MonsterRaceData.h"
#include "src/protocol/datacenter/data/monsters/MonsterSuperRaceData.h"
#include "src/protocol/datacenter/data/mounts/MountData.h"
#include "src/protocol/datacenter/data/mounts/MountBehaviorData.h"
#include "src/protocol/datacenter/data/mounts/MountBoneData.h"
#include "src/protocol/datacenter/data/mounts/MountFamilyData.h"
#include "src/protocol/datacenter/data/mounts/RideFoodData.h"
#include "src/protocol/datacenter/data/notifications/NotificationData.h"
#include "src/protocol/datacenter/data/npcs/NpcData.h"
#include "src/protocol/datacenter/data/npcs/NpcActionData.h"
#include "src/protocol/datacenter/data/npcs/NpcMessageData.h"
#include "src/protocol/datacenter/data/npcs/TaxCollectorFirstnameData.h"
#include "src/protocol/datacenter/data/npcs/TaxCollectorNameData.h"
#include "src/protocol/datacenter/data/optionalFeatures/CustomModeBreedSpellData.h"
#include "src/protocol/datacenter/data/optionalFeatures/ForgettableSpellData.h"
#include "src/protocol/datacenter/data/optionalFeatures/ModsterData.h"
#include "src/protocol/datacenter/data/playlists/PlaylistData.h"
#include "src/protocol/datacenter/data/popup/PopupButtonData.h"
#include "src/protocol/datacenter/data/popup/PopupInformationData.h"
#include "src/protocol/datacenter/data/progression/ActivitySuggestionData.h"
#include "src/protocol/datacenter/data/progression/ActivitySuggestionsCategoryData.h"
#include "src/protocol/datacenter/data/progression/FeatureDescriptionData.h"
#include "src/protocol/datacenter/data/quest/AchievementData.h"
#include "src/protocol/datacenter/data/quest/AchievementCategoryData.h"
#include "src/protocol/datacenter/data/quest/AchievementObjectiveData.h"
#include "src/protocol/datacenter/data/quest/AchievementRewardData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveBringItemToNpcData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveBringSoulToNpcData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveCraftItemData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveDiscoverMapData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveDiscoverSubAreaData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveDuelSpecificPlayerData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveFightMonsterData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveFightMonstersOnMapData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveFreeFormData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveGoToNpcData.h"
#include "src/protocol/datacenter/data/quest/objectives/QuestObjectiveMultiFightMonsterData.h"
#include "src/protocol/datacenter/data/quest/QuestData.h"
#include "src/protocol/datacenter/data/quest/QuestCategoryData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveData.h"
#include "src/protocol/datacenter/data/quest/QuestObjectiveTypeData.h"
#include "src/protocol/datacenter/data/quest/QuestStepData.h"
#include "src/protocol/datacenter/data/quest/QuestStepRewardsData.h"
#include "src/protocol/datacenter/data/quest/treasureHunt/LegendaryTreasureHuntData.h"
#include "src/protocol/datacenter/data/quest/treasureHunt/PointOfInterestData.h"
#include "src/protocol/datacenter/data/quest/treasureHunt/PointOfInterestCategoryData.h"
#include "src/protocol/datacenter/data/seasons/ArenaLeagueSeasonData.h"
#include "src/protocol/datacenter/data/seasons/ExpeditionSeasonData.h"
#include "src/protocol/datacenter/data/seasons/ServerSeasonData.h"
#include "src/protocol/datacenter/data/servers/ServerData.h"
#include "src/protocol/datacenter/data/servers/ServerCommunityData.h"
#include "src/protocol/datacenter/data/servers/ServerGameTypeData.h"
#include "src/protocol/datacenter/data/servers/ServerLangData.h"
#include "src/protocol/datacenter/data/servers/ServerPopulationData.h"
#include "src/protocol/datacenter/data/social/EmblemBackgroundData.h"
#include "src/protocol/datacenter/data/social/EmblemSymbolData.h"
#include "src/protocol/datacenter/data/social/EmblemSymbolCategoryData.h"
#include "src/protocol/datacenter/data/social/SocialRightData.h"
#include "src/protocol/datacenter/data/social/SocialRightGroupData.h"
#include "src/protocol/datacenter/data/social/SocialTagData.h"
#include "src/protocol/datacenter/data/social/SocialTagsTypeData.h"
#include "src/protocol/datacenter/data/sounds/SoundAnimationData.h"
#include "src/protocol/datacenter/data/sounds/SoundBonesData.h"
#include "src/protocol/datacenter/data/sounds/SoundUiData.h"
#include "src/protocol/datacenter/data/sounds/SoundUiElementData.h"
#include "src/protocol/datacenter/data/sounds/SoundUiHookData.h"
#include "src/protocol/datacenter/data/spells/BoundScriptUsageDataData.h"
#include "src/protocol/datacenter/data/spells/EffectZoneData.h"
#include "src/protocol/datacenter/data/spells/FinishMoveData.h"
#include "src/protocol/datacenter/data/spells/SpellData.h"
#include "src/protocol/datacenter/data/spells/SpellBombData.h"
#include "src/protocol/datacenter/data/spells/SpellConversionData.h"
#include "src/protocol/datacenter/data/spells/SpellLevelData.h"
#include "src/protocol/datacenter/data/spells/SpellPairData.h"
#include "src/protocol/datacenter/data/spells/SpellScriptData.h"
#include "src/protocol/datacenter/data/spells/SpellStateData.h"
#include "src/protocol/datacenter/data/spells/SpellTypeData.h"
#include "src/protocol/datacenter/data/spells/SpellVariantData.h"
#include "src/protocol/datacenter/data/temporis/AchievementProgressData.h"
#include "src/protocol/datacenter/data/temporis/AchievementProgressStepData.h"
#include "src/protocol/datacenter/data/world/AreaData.h"
#include "src/protocol/datacenter/data/world/DungeonData.h"
#include "src/protocol/datacenter/data/world/HintData.h"
#include "src/protocol/datacenter/data/world/HintCategoryData.h"
#include "src/protocol/datacenter/data/world/MapCoordinatesData.h"
#include "src/protocol/datacenter/data/world/MapPositionData.h"
#include "src/protocol/datacenter/data/world/MapReferenceData.h"
#include "src/protocol/datacenter/data/world/MapScrollActionData.h"
#include "src/protocol/datacenter/data/world/SubAreaData.h"
#include "src/protocol/datacenter/data/world/SuperAreaData.h"
#include "src/protocol/datacenter/data/world/WaypointData.h"
#include "src/protocol/datacenter/data/world/WorldMapData.h"

enum class GameDataEnum
{
    ABUSEREASONSDATA,
    ALIGNMENTGIFTDATA,
    ALIGNMENTORDERDATA,
    ALIGNMENTRANKDATA,
    ALIGNMENTRANKJNTGIFTDATA,
    ALIGNMENTSIDEDATA,
    ALIGNMENTTITLEDATA,
    ALLIANCERANKDATA,
    ALLIANCERANKNAMESUGGESTIONDATA,
    ALLIANCERIGHTDATA,
    ALLIANCERIGHTGROUPDATA,
    ALLIANCETAGDATA,
    ALLIANCETAGSTYPEDATA,
    KOTHROLEDATA,
    ALMANAXCALENDARDATA,
    ALTERATIONDATA,
    ALTERATIONCATEGORYDATA,
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
    COLLECTABLEDATA,
    COLLECTIONDATA,
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
    GUILDRANKDATA,
    GUILDRANKNAMESUGGESTIONDATA,
    GUILDRIGHTDATA,
    GUILDRIGHTGROUPDATA,
    GUILDTAGDATA,
    GUILDTAGSTYPEDATA,
    HAVENBAGFURNITUREDATA,
    HAVENBAGTHEMEDATA,
    HOUSEDATA,
    INTERACTIVEDATA,
    SIGNDATA,
    SKILLNAMEDATA,
    STEALTHBONESDATA,
    ACCOUNTRIGHTSITEMCRITERIONDATA,
    ACHIEVEMENTACCOUNTITEMCRITERIONDATA,
    ACHIEVEMENTITEMCRITERIONDATA,
    ACHIEVEMENTOBJECTIVEVALIDATEDDATA,
    ACHIEVEMENTPIONEERITEMCRITERIONDATA,
    ACHIEVEMENTPOINTSITEMCRITERIONDATA,
    ALIGNMENTITEMCRITERIONDATA,
    ALIGNMENTLEVELITEMCRITERIONDATA,
    ALLIANCEAVAITEMCRITERIONDATA,
    ALLIANCEITEMCRITERIONDATA,
    ALLIANCEMASTERITEMCRITERIONDATA,
    ALLIANCERIGHTSITEMCRITERIONDATA,
    ALTERATIONCRITERIONDATA,
    AREAITEMCRITERIONDATA,
    ARENA1V1LEAGUECRITERIONDATA,
    ARENA2V2LEAGUECRITERIONDATA,
    ARENA3V3LEAGUECRITERIONDATA,
    ARENAMAX1V1LEAGUECRITERIONDATA,
    ARENAMAX2V2LEAGUECRITERIONDATA,
    ARENAMAX3V3LEAGUECRITERIONDATA,
    BONESITEMCRITERIONDATA,
    BONUSSETITEMCRITERIONDATA,
    BREEDITEMCRITERIONDATA,
    COMMUNITYITEMCRITERIONDATA,
    CRITERIONUTILSDATA,
    DAYITEMCRITERIONDATA,
    EMOTEITEMCRITERIONDATA,
    FRIENDLISTITEMCRITERIONDATA,
    GIFTITEMCRITERIONDATA,
    GROUPITEMCRITERIONDATA,
    GUILDITEMCRITERIONDATA,
    GUILDLEVELITEMCRITERIONDATA,
    GUILDMASTERITEMCRITERIONDATA,
    GUILDRIGHTSITEMCRITERIONDATA,
    ITEMCRITERIONDATA,
    ITEMCRITERIONFACTORYDATA,
    ITEMCRITERIONOPERATORDATA,
    JOBITEMCRITERIONDATA,
    KAMAITEMCRITERIONDATA,
    LEVELITEMCRITERIONDATA,
    MAPCHARACTERSITEMCRITERIONDATA,
    MAPITEMCRITERIONDATA,
    MARIEDITEMCRITERIONDATA,
    MONSTERGROUPCHALLENGECRITERIONDATA,
    MONTHITEMCRITERIONDATA,
    MOUNTFAMILYITEMCRITERIONDATA,
    NAMEITEMCRITERIONDATA,
    NEWHAVENBAGITEMCRITERIONDATA,
    NUMBEROFITEMMADECRITERIONDATA,
    NUMBEROFMOUNTBIRTHEDCRITERIONDATA,
    OBJECTITEMCRITERIONDATA,
    ONLYSETCRITERIONDATA,
    OPTIONALFEATUREENABLEDCRITERIONDATA,
    PREMIUMACCOUNTITEMCRITERIONDATA,
    PRESTIGELEVELITEMCRITERIONDATA,
    PRISMONMAPSTATEITEMCRITERIONDATA,
    PVPRANKITEMCRITERIONDATA,
    QUESTITEMCRITERIONDATA,
    QUESTOBJECTIVEITEMCRITERIONDATA,
    RIDEITEMCRITERIONDATA,
    RUNEBYBREAKINGITEMCRITERIONDATA,
    SEASONCRITERIONDATA,
    SERVERITEMCRITERIONDATA,
    SERVERTYPEITEMCRITERIONDATA,
    SEXITEMCRITERIONDATA,
    SKILLITEMCRITERIONDATA,
    SMILEYPACKITEMCRITERIONDATA,
    SOULSTONEITEMCRITERIONDATA,
    SPECIALIZATIONITEMCRITERIONDATA,
    SPELLITEMCRITERIONDATA,
    STATECRITERIONDATA,
    STATICCRITERIONITEMCRITERIONDATA,
    SUBAREAITEMCRITERIONDATA,
    SUBAREALEVELITEMCRITERIONDATA,
    SUBSCRIBEITEMCRITERIONDATA,
    SUBSCRIPTIONDURATIONITEMCRITERIONDATA,
    UNUSABLEITEMCRITERIONDATA,
    WEIGHTITEMCRITERIONDATA,
    EVOLUTIVEITEMTYPEDATA,
    INCARNATIONDATA,
    INCARNATIONLEVELDATA,
    ITEMDATA,
    ITEMSETDATA,
    ITEMSUPERTYPEDATA,
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
    CUSTOMMODEBREEDSPELLDATA,
    FORGETTABLESPELLDATA,
    MODSTERDATA,
    PLAYLISTDATA,
    POPUPBUTTONDATA,
    POPUPINFORMATIONDATA,
    ACTIVITYSUGGESTIONDATA,
    ACTIVITYSUGGESTIONSCATEGORYDATA,
    FEATUREDESCRIPTIONDATA,
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
    ARENALEAGUESEASONDATA,
    EXPEDITIONSEASONDATA,
    SERVERSEASONDATA,
    SERVERDATA,
    SERVERCOMMUNITYDATA,
    SERVERGAMETYPEDATA,
    SERVERLANGDATA,
    SERVERPOPULATIONDATA,
    EMBLEMBACKGROUNDDATA,
    EMBLEMSYMBOLDATA,
    EMBLEMSYMBOLCATEGORYDATA,
    SOCIALRIGHTDATA,
    SOCIALRIGHTGROUPDATA,
    SOCIALTAGDATA,
    SOCIALTAGSTYPEDATA,
    SOUNDANIMATIONDATA,
    SOUNDBONESDATA,
    SOUNDUIDATA,
    SOUNDUIELEMENTDATA,
    SOUNDUIHOOKDATA,
    BOUNDSCRIPTUSAGEDATADATA,
    EFFECTZONEDATA,
    FINISHMOVEDATA,
    SPELLDATA,
    SPELLBOMBDATA,
    SPELLCONVERSIONDATA,
    SPELLLEVELDATA,
    SPELLPAIRDATA,
    SPELLSCRIPTDATA,
    SPELLSTATEDATA,
    SPELLTYPEDATA,
    SPELLVARIANTDATA,
    ACHIEVEMENTPROGRESSDATA,
    ACHIEVEMENTPROGRESSSTEPDATA,
    AREADATA,
    DUNGEONDATA,
    HINTDATA,
    HINTCATEGORYDATA,
    MAPCOORDINATESDATA,
    MAPPOSITIONDATA,
    MAPREFERENCEDATA,
    MAPSCROLLACTIONDATA,
    SUBAREADATA,
    SUPERAREADATA,
    WAYPOINTDATA,
    WORLDMAPDATA
};

#endif // GAMEDATADECLARATOR_H