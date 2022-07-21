#ifndef GAMEDATADECLARATOR_H
#define GAMEDATADECLARATOR_H

#include "src/engines/io/d2o/game/data/abuse/AbuseReasonsData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentGiftData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentOrderData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentRankData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentRankJntGiftData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentSideData.h"
#include "src/engines/io/d2o/game/data/alignments/AlignmentTitleData.h"
#include "src/engines/io/d2o/game/data/almanax/AlmanaxCalendarData.h"
#include "src/engines/io/d2o/game/data/alterations/AlterationData.h"
#include "src/engines/io/d2o/game/data/alterations/AlterationCategoryData.h"
#include "src/engines/io/d2o/game/data/ambientSounds/PlaylistSoundData.h"
#include "src/engines/io/d2o/game/data/appearance/AppearanceData.h"
#include "src/engines/io/d2o/game/data/appearance/CreatureBoneOverrideData.h"
#include "src/engines/io/d2o/game/data/appearance/CreatureBoneTypeData.h"
#include "src/engines/io/d2o/game/data/appearance/OrnamentData.h"
#include "src/engines/io/d2o/game/data/appearance/SkinMappingData.h"
#include "src/engines/io/d2o/game/data/appearance/SkinPositionData.h"
#include "src/engines/io/d2o/game/data/appearance/TitleData.h"
#include "src/engines/io/d2o/game/data/appearance/TitleCategoryData.h"
#include "src/engines/io/d2o/game/data/arena/ArenaLeagueData.h"
#include "src/engines/io/d2o/game/data/arena/ArenaLeagueRewardData.h"
#include "src/engines/io/d2o/game/data/arena/ArenaLeagueSeasonData.h"
#include "src/engines/io/d2o/game/data/bonus/BonusData.h"
#include "src/engines/io/d2o/game/data/bonus/criterion/BonusCriterionData.h"
#include "src/engines/io/d2o/game/data/breach/BreachDungeonModificatorData.h"
#include "src/engines/io/d2o/game/data/breach/BreachInfinityLevelData.h"
#include "src/engines/io/d2o/game/data/breach/BreachWorldMapCoordinateData.h"
#include "src/engines/io/d2o/game/data/breach/BreachWorldMapSectorData.h"
#include "src/engines/io/d2o/game/data/breeds/BreedData.h"
#include "src/engines/io/d2o/game/data/breeds/BreedRoleData.h"
#include "src/engines/io/d2o/game/data/breeds/BreedRoleByBreedData.h"
#include "src/engines/io/d2o/game/data/breeds/HeadData.h"
#include "src/engines/io/d2o/game/data/challenges/ChallengeData.h"
#include "src/engines/io/d2o/game/data/characteristics/CharacteristicData.h"
#include "src/engines/io/d2o/game/data/characteristics/CharacteristicCategoryData.h"
#include "src/engines/io/d2o/game/data/collection/CollectableData.h"
#include "src/engines/io/d2o/game/data/collection/CollectionData.h"
#include "src/engines/io/d2o/game/data/communication/CensoredWordData.h"
#include "src/engines/io/d2o/game/data/communication/ChatChannelData.h"
#include "src/engines/io/d2o/game/data/communication/EmoticonData.h"
#include "src/engines/io/d2o/game/data/communication/InfoMessageData.h"
#include "src/engines/io/d2o/game/data/communication/NamingRuleData.h"
#include "src/engines/io/d2o/game/data/communication/SmileyData.h"
#include "src/engines/io/d2o/game/data/communication/SmileyCategoryData.h"
#include "src/engines/io/d2o/game/data/communication/SmileyPackData.h"
#include "src/engines/io/d2o/game/data/documents/DocumentData.h"
#include "src/engines/io/d2o/game/data/effects/EffectData.h"
#include "src/engines/io/d2o/game/data/effects/EffectInstanceData.h"
#include "src/engines/io/d2o/game/data/effects/EvolutiveEffectData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceCreatureData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceDateData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceDiceData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceDurationData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceIntegerData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceLadderData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceMinMaxData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceMountData.h"
#include "src/engines/io/d2o/game/data/effects/instances/EffectInstanceStringData.h"
#include "src/engines/io/d2o/game/data/externalnotifications/ExternalNotificationData.h"
#include "src/engines/io/d2o/game/data/feature/OptionalFeatureData.h"
#include "src/engines/io/d2o/game/data/guild/EmblemBackgroundData.h"
#include "src/engines/io/d2o/game/data/guild/EmblemSymbolData.h"
#include "src/engines/io/d2o/game/data/guild/EmblemSymbolCategoryData.h"
#include "src/engines/io/d2o/game/data/guild/GuildRankData.h"
#include "src/engines/io/d2o/game/data/guild/GuildRankNameSuggestionData.h"
#include "src/engines/io/d2o/game/data/guild/GuildRightData.h"
#include "src/engines/io/d2o/game/data/guild/GuildRightGroupData.h"
#include "src/engines/io/d2o/game/data/guild/GuildTagData.h"
#include "src/engines/io/d2o/game/data/guild/GuildTagsTypeData.h"
#include "src/engines/io/d2o/game/data/houses/HavenbagFurnitureData.h"
#include "src/engines/io/d2o/game/data/houses/HavenbagThemeData.h"
#include "src/engines/io/d2o/game/data/houses/HouseData.h"
#include "src/engines/io/d2o/game/data/idols/IdolData.h"
#include "src/engines/io/d2o/game/data/interactives/InteractiveData.h"
#include "src/engines/io/d2o/game/data/interactives/SignData.h"
#include "src/engines/io/d2o/game/data/interactives/SkillNameData.h"
#include "src/engines/io/d2o/game/data/interactives/StealthBonesData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AccountRightsItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AchievementAccountItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AchievementItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AchievementObjectiveValidatedData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AchievementPointsItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AlignmentItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AlignmentLevelItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AllianceAvAItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AllianceItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AllianceRightsItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AlterationCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/AreaItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaDuelRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaMaxDuelRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaMaxSoloRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaMaxTeamRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaSoloRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ArenaTeamRankCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/BonesItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/BonusSetItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/BreedItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/CommunityItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/CriterionUtilsData.h"
#include "src/engines/io/d2o/game/data/items/criterion/DayItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/EmoteItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/FriendlistItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GiftItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GroupItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GuildItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GuildLevelItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GuildMasterItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/GuildRightsItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionFactoryData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ItemCriterionOperatorData.h"
#include "src/engines/io/d2o/game/data/items/criterion/JobItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/KamaItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/LevelItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MapCharactersItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MapItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MariedItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MonsterGroupChallengeCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MonthItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/MountFamilyItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/NameItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/NewHavenbagItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/NumberOfItemMadeCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/NumberOfMountBirthedCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ObjectItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/OnlySetCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/PremiumAccountItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/PrestigeLevelItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/PVPRankItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/QuestItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/QuestObjectiveItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/RideItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/RuneByBreakingItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ServerItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ServerSeasonTemporisCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/ServerTypeItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SexItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SkillItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SmileyPackItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SoulStoneItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SpecializationItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SpellItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/StateCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/StaticCriterionItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SubareaItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SubscribeItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/SubscriptionDurationItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/UnusableItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/criterion/WeightItemCriterionData.h"
#include "src/engines/io/d2o/game/data/items/EvolutiveItemTypeData.h"
#include "src/engines/io/d2o/game/data/items/IncarnationData.h"
#include "src/engines/io/d2o/game/data/items/IncarnationLevelData.h"
#include "src/engines/io/d2o/game/data/items/ItemData.h"
#include "src/engines/io/d2o/game/data/items/ItemSetData.h"
#include "src/engines/io/d2o/game/data/items/ItemTypeData.h"
#include "src/engines/io/d2o/game/data/items/LegendaryPowerCategoryData.h"
#include "src/engines/io/d2o/game/data/items/PresetIconData.h"
#include "src/engines/io/d2o/game/data/items/RandomDropGroupData.h"
#include "src/engines/io/d2o/game/data/items/RandomDropItemData.h"
#include "src/engines/io/d2o/game/data/items/VeteranRewardData.h"
#include "src/engines/io/d2o/game/data/items/WeaponData.h"
#include "src/engines/io/d2o/game/data/jobs/JobData.h"
#include "src/engines/io/d2o/game/data/jobs/RecipeData.h"
#include "src/engines/io/d2o/game/data/jobs/SkillData.h"
#include "src/engines/io/d2o/game/data/livingObjects/LivingObjectSkinJntMoodData.h"
#include "src/engines/io/d2o/game/data/livingObjects/SpeakingItemsTriggerData.h"
#include "src/engines/io/d2o/game/data/livingObjects/SpeakingItemTextData.h"
#include "src/engines/io/d2o/game/data/misc/BreachBossData.h"
#include "src/engines/io/d2o/game/data/misc/BreachPrizeData.h"
#include "src/engines/io/d2o/game/data/misc/CensoredContentData.h"
#include "src/engines/io/d2o/game/data/misc/CharacterXPMappingData.h"
#include "src/engines/io/d2o/game/data/misc/LuaFormulaData.h"
#include "src/engines/io/d2o/game/data/misc/MonthData.h"
#include "src/engines/io/d2o/game/data/misc/PackData.h"
#include "src/engines/io/d2o/game/data/misc/SubhintData.h"
#include "src/engines/io/d2o/game/data/misc/TipsData.h"
#include "src/engines/io/d2o/game/data/monsters/CompanionData.h"
#include "src/engines/io/d2o/game/data/monsters/CompanionCharacteristicData.h"
#include "src/engines/io/d2o/game/data/monsters/CompanionSpellData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterBonusCharacteristicsData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterDropData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterDropCoefficientData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterGradeData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterMiniBossData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterRaceData.h"
#include "src/engines/io/d2o/game/data/monsters/MonsterSuperRaceData.h"
#include "src/engines/io/d2o/game/data/mounts/MountData.h"
#include "src/engines/io/d2o/game/data/mounts/MountBehaviorData.h"
#include "src/engines/io/d2o/game/data/mounts/MountBoneData.h"
#include "src/engines/io/d2o/game/data/mounts/MountFamilyData.h"
#include "src/engines/io/d2o/game/data/mounts/RideFoodData.h"
#include "src/engines/io/d2o/game/data/notifications/NotificationData.h"
#include "src/engines/io/d2o/game/data/npcs/NpcData.h"
#include "src/engines/io/d2o/game/data/npcs/NpcActionData.h"
#include "src/engines/io/d2o/game/data/npcs/NpcMessageData.h"
#include "src/engines/io/d2o/game/data/npcs/TaxCollectorFirstnameData.h"
#include "src/engines/io/d2o/game/data/npcs/TaxCollectorNameData.h"
#include "src/engines/io/d2o/game/data/optionalFeatures/CustomModeBreedSpellData.h"
#include "src/engines/io/d2o/game/data/optionalFeatures/ForgettableSpellData.h"
#include "src/engines/io/d2o/game/data/optionalFeatures/ModsterData.h"
#include "src/engines/io/d2o/game/data/playlists/PlaylistData.h"
#include "src/engines/io/d2o/game/data/popup/PopupButtonData.h"
#include "src/engines/io/d2o/game/data/popup/PopupInformationData.h"
#include "src/engines/io/d2o/game/data/progression/ActivitySuggestionData.h"
#include "src/engines/io/d2o/game/data/progression/ActivitySuggestionsCategoryData.h"
#include "src/engines/io/d2o/game/data/progression/FeatureDescriptionData.h"
#include "src/engines/io/d2o/game/data/quest/AchievementData.h"
#include "src/engines/io/d2o/game/data/quest/AchievementCategoryData.h"
#include "src/engines/io/d2o/game/data/quest/AchievementObjectiveData.h"
#include "src/engines/io/d2o/game/data/quest/AchievementRewardData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveBringItemToNpcData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveBringSoulToNpcData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveCraftItemData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveDiscoverMapData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveDiscoverSubAreaData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveDuelSpecificPlayerData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveFightMonsterData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveFightMonstersOnMapData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveFreeFormData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveGoToNpcData.h"
#include "src/engines/io/d2o/game/data/quest/objectives/QuestObjectiveMultiFightMonsterData.h"
#include "src/engines/io/d2o/game/data/quest/QuestData.h"
#include "src/engines/io/d2o/game/data/quest/QuestCategoryData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveData.h"
#include "src/engines/io/d2o/game/data/quest/QuestObjectiveTypeData.h"
#include "src/engines/io/d2o/game/data/quest/QuestStepData.h"
#include "src/engines/io/d2o/game/data/quest/QuestStepRewardsData.h"
#include "src/engines/io/d2o/game/data/quest/treasureHunt/LegendaryTreasureHuntData.h"
#include "src/engines/io/d2o/game/data/quest/treasureHunt/PointOfInterestData.h"
#include "src/engines/io/d2o/game/data/quest/treasureHunt/PointOfInterestCategoryData.h"
#include "src/engines/io/d2o/game/data/servers/ServerData.h"
#include "src/engines/io/d2o/game/data/servers/ServerCommunityData.h"
#include "src/engines/io/d2o/game/data/servers/ServerGameTypeData.h"
#include "src/engines/io/d2o/game/data/servers/ServerLangData.h"
#include "src/engines/io/d2o/game/data/servers/ServerPopulationData.h"
#include "src/engines/io/d2o/game/data/servers/ServerTemporisSeasonData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundAnimationData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundBonesData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundUiData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundUiElementData.h"
#include "src/engines/io/d2o/game/data/sounds/SoundUiHookData.h"
#include "src/engines/io/d2o/game/data/spells/FinishMoveData.h"
#include "src/engines/io/d2o/game/data/spells/SpellData.h"
#include "src/engines/io/d2o/game/data/spells/SpellBombData.h"
#include "src/engines/io/d2o/game/data/spells/SpellConversionData.h"
#include "src/engines/io/d2o/game/data/spells/SpellLevelData.h"
#include "src/engines/io/d2o/game/data/spells/SpellPairData.h"
#include "src/engines/io/d2o/game/data/spells/SpellStateData.h"
#include "src/engines/io/d2o/game/data/spells/SpellTypeData.h"
#include "src/engines/io/d2o/game/data/spells/SpellVariantData.h"
#include "src/engines/io/d2o/game/data/temporis/AchievementProgressData.h"
#include "src/engines/io/d2o/game/data/temporis/AchievementProgressStepData.h"
#include "src/engines/io/d2o/game/data/world/AreaData.h"
#include "src/engines/io/d2o/game/data/world/DungeonData.h"
#include "src/engines/io/d2o/game/data/world/HintData.h"
#include "src/engines/io/d2o/game/data/world/HintCategoryData.h"
#include "src/engines/io/d2o/game/data/world/MapCoordinatesData.h"
#include "src/engines/io/d2o/game/data/world/MapPositionData.h"
#include "src/engines/io/d2o/game/data/world/MapReferenceData.h"
#include "src/engines/io/d2o/game/data/world/MapScrollActionData.h"
#include "src/engines/io/d2o/game/data/world/PhoenixData.h"
#include "src/engines/io/d2o/game/data/world/SubAreaData.h"
#include "src/engines/io/d2o/game/data/world/SuperAreaData.h"
#include "src/engines/io/d2o/game/data/world/WaypointData.h"
#include "src/engines/io/d2o/game/data/world/WorldMapData.h"

enum class GameDataEnum
{
    ABUSEREASONSDATA,
    ALIGNMENTGIFTDATA,
    ALIGNMENTORDERDATA,
    ALIGNMENTRANKDATA,
    ALIGNMENTRANKJNTGIFTDATA,
    ALIGNMENTSIDEDATA,
    ALIGNMENTTITLEDATA,
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
    EMBLEMBACKGROUNDDATA,
    EMBLEMSYMBOLDATA,
    EMBLEMSYMBOLCATEGORYDATA,
    GUILDRANKDATA,
    GUILDRANKNAMESUGGESTIONDATA,
    GUILDRIGHTDATA,
    GUILDRIGHTGROUPDATA,
    GUILDTAGDATA,
    GUILDTAGSTYPEDATA,
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
    ALTERATIONCRITERIONDATA,
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
    STATECRITERIONDATA,
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