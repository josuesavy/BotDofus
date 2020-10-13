#include "ClassManager.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberArenaInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/Protocol/Types/Data/game/character/choice/CharacterHardcoreOrEpicInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalGuildInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalAllianceInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookAndGradeInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/context/FightEntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/social/AbstractSocialGroupInfos.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/social/GuildFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/social/GuildInsiderFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInAllianceInformations.h"
#include "src/Protocol/Types/Data/game/social/AlliancedGuildFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Protocol/Types/Data/game/social/AllianceFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/social/GuildVersatileInformations.h"
#include "src/Protocol/Types/Data/game/social/GuildInAllianceVersatileInformations.h"
#include "src/Protocol/Types/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/Protocol/Types/Data/game/prism/PrismGeolocalizedInformation.h"
#include "src/Protocol/Types/Data/game/prism/PrismInformation.h"
#include "src/Protocol/Types/Data/game/prism/AlliancePrismInformation.h"
#include "src/Protocol/Types/Data/game/prism/AllianceInsiderPrismInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamMemberEntityInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/FightTeamInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightAllianceTeamInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMinimalStats.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMinimalStatsPreparation.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultListEntry.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultFighterListEntry.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultTaxCollectorListEntry.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultPlayerListEntry.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultMutantListEntry.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultAdditionalData.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultPvpData.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultExperienceData.h"
#include "src/Protocol/Types/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporaryBoostStateEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporarySpellBoostEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporaryBoostWeaponDamagesEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporarySpellImmunityEffect.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTriggeredEffect.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectCreature.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectLadder.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectMinMax.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectDuration.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectString.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectDice.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectDate.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffectMount.h"
#include "src/Protocol/Types/Data/game/mount/UpdateMountCharacteristic.h"
#include "src/Protocol/Types/Data/game/mount/UpdateMountBooleanCharacteristic.h"
#include "src/Protocol/Types/Data/game/mount/UpdateMountIntegerCharacteristic.h"
#include "src/Protocol/Types/Data/game/shortcut/Shortcut.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObject.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObjectPreset.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObjectIdolsPreset.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutObjectItem.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutSpell.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutSmiley.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutEmote.h"
#include "src/Protocol/Types/Data/game/shortcut/ShortcutEntitiesPreset.h"
#include "src/Protocol/Types/Data/game/idol/Idol.h"
#include "src/Protocol/Types/Data/game/idol/PartyIdol.h"
#include "src/Protocol/Types/Data/game/achievement/AchievementAchieved.h"
#include "src/Protocol/Types/Data/game/achievement/AchievementAchievedRewardable.h"
#include "src/Protocol/Types/Data/game/friend/IgnoredInformations.h"
#include "src/Protocol/Types/Data/game/friend/IgnoredOnlineInformations.h"
#include "src/Protocol/Types/Data/game/friend/FriendInformations.h"
#include "src/Protocol/Types/Data/game/friend/FriendOnlineInformations.h"
#include "src/Protocol/Types/Data/game/friend/AcquaintanceInformation.h"
#include "src/Protocol/Types/Data/game/friend/AcquaintanceOnlineInformation.h"
#include "src/Protocol/Types/Data/game/friend/FriendSpouseInformations.h"
#include "src/Protocol/Types/Data/game/friend/FriendSpouseOnlineInformations.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElementSkill.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElementNamedSkill.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElementWithAgeBonus.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/entity/PartyEntityMemberInformation.h"
#include "src/Protocol/Types/Data/game/interactive/skill/SkillActionDescription.h"
#include "src/Protocol/Types/Data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "src/Protocol/Types/Data/game/interactive/skill/SkillActionDescriptionCollect.h"
#include "src/Protocol/Types/Data/game/interactive/skill/SkillActionDescriptionCraft.h"
#include "src/Protocol/Types/Data/game/house/HouseInformations.h"
#include "src/Protocol/Types/Data/game/house/AccountHouseInformations.h"
#include "src/Protocol/Types/Data/game/house/HouseInformationsInside.h"
#include "src/Protocol/Types/Data/game/house/HouseInformationsForGuild.h"
#include "src/Protocol/Types/Data/game/house/HouseOnMapInformations.h"
#include "src/Protocol/Types/Data/game/house/HouseInstanceInformations.h"
#include "src/Protocol/Types/Data/game/house/HouseGuildedInformations.h"
#include "src/Protocol/Types/Data/game/paddock/PaddockBuyableInformations.h"
#include "src/Protocol/Types/Data/game/paddock/PaddockGuildedInformations.h"
#include "src/Protocol/Types/Data/game/context/GameContextActorPositionInformations.h"
#include "src/Protocol/Types/Data/game/context/GameContextActorInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightAIInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMonsterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMonsterWithAlignmentInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightTaxCollectorInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightCharacterInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightMutantInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightEntityInformation.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayMutantInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayCharacterInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayMountInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayMerchantInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayNpcWithQuestInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayGroupMonsterWaveInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayTreasureHintInformations.h"
#include "src/Protocol/Types/Data/game/context/GameRolePlayTaxCollectorInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayPrismInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayPortalInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionObjectUse.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionAlliance.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionGuild.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionOrnament.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionEmote.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionTitle.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionSkillUse.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOptionFollowers.h"
#include "src/Protocol/Types/Data/game/context/TaxCollectorStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/TaxCollectorStaticExtendedInformations.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorInformations.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorGuildInformations.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorLootInformations.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorWaitingForHelpInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GroupMonsterStaticInformationsWithAlternatives.h"
#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestObjectiveInformationsWithCompletion.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnScaledMonsterInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnMonsterInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnCharacterInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/SpawnCompanionInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/GameContextSummonsInformation.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterMonsterLightInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterNamedLightInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterTaxCollectorLightInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterEntityLightInformation.h"
#include "src/Protocol/Types/Data/game/context/MapCoordinates.h"
#include "src/Protocol/Types/Data/game/context/MapCoordinatesAndId.h"
#include "src/Protocol/Types/Data/game/context/MapCoordinatesExtended.h"
#include "src/Protocol/Types/Data/game/presets/Preset.h"
#include "src/Protocol/Types/Data/game/presets/PresetsContainerPreset.h"
#include "src/Protocol/Types/Data/game/presets/IconNamedPreset.h"
#include "src/Protocol/Types/Data/game/presets/SpellsPreset.h"
#include "src/Protocol/Types/Data/game/presets/ForgettableSpellsPreset.h"
#include "src/Protocol/Types/Data/game/presets/StatsPreset.h"
#include "src/Protocol/Types/Data/game/presets/IdolsPreset.h"
#include "src/Protocol/Types/Data/game/presets/EntitiesPreset.h"
#include "src/Protocol/Types/Data/game/presets/FullStatsPreset.h"
#include "src/Protocol/Types/Data/game/presets/ItemsPreset.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToPOI.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStepDig.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFight.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToHint.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirection.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/Protocol/Types/Data/game/context/roleplay/breach/BreachBranch.h"
#include "src/Protocol/Types/Data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/Protocol/Types/Data/game/context/roleplay/breach/ExtendedLockedBreachBranch.h"
#include "src/Protocol/Types/Data/game/character/status/PlayerStatus.h"
#include "src/Protocol/Types/Data/game/character/status/PlayerStatusExtended.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstant.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstantString.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstantInteger.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstantLong.h"
#include "src/Protocol/Types/Data/common/basic/StatisticData.h"
#include "src/Protocol/Types/Data/common/basic/StatisticDataInt.h"
#include "src/Protocol/Types/Data/common/basic/StatisticDataBoolean.h"
#include "src/Protocol/Types/Data/common/basic/StatisticDataShort.h"
#include "src/Protocol/Types/Data/common/basic/StatisticDataString.h"
#include "src/Protocol/Types/Data/common/basic/StatisticDataByte.h"
#include "src/Protocol/Types/Data/game/character/debt/DebtInformation.h"
#include "src/Protocol/Types/Data/game/character/debt/KamaDebtInformation.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 2181:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 6291:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 918:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 460:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 5851:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 2827:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 5177:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 4067:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 4536:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 4880:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 7938:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 2127:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 5025:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 1274:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 486:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 3641:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 5929:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 989:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 7721:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 8260:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 3494:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 8760:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 4179:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 7410:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 7784:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 58:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 6199:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 7029:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 2626:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 9949:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 9464:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 314:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 790:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 7125:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 8164:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 8911:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 6495:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 3334:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 8766:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStats());
    
    case 5419:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStatsPreparation());
    
    case 2461:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 7464:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 1061:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 2386:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 3182:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 6509:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 3055:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 676:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 7567:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 4561:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 4218:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 1017:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 3021:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 8950:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 7166:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 5208:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 6720:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 6596:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 4007:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 6806:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 5574:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 2778:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 3270:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 6666:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 4686:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 8844:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 9905:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 5446:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 445:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 5864:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 5199:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 6872:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 4550:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 7155:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 5172:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 7079:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 3114:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 2559:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 5532:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 7081:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 7853:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 4692:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 8684:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 1048:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 782:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 3132:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 2664:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 5129:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 5595:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 1662:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 1530:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 9391:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 5847:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 8629:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 9826:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 6637:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 2763:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 4751:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 6486:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 346:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 4600:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 3148:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 3959:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 7732:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 8114:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 4170:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 6006:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 5633:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 2762:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 1950:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 4629:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 1404:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 2891:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 2259:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 8569:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 442:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 5123:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 6092:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 7442:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 4806:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 2876:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 5783:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 860:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 5568:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 25:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 1806:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 6845:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 784:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 9493:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 4412:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 9257:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 1546:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 1573:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 1150:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 6985:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 2965:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 2302:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 8006:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 6774:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 5752:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 4201:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 8205:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 371:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 773:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 8427:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 7629:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 6557:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 9114:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 904:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 5810:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 2779:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 1522:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 5848:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 3193:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 6:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 7333:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 1250:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 8258:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 2645:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 8592:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 8512:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 9236:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 4898:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 8683:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 8757:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 365:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 1104:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 6640:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 469:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 3105:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 3667:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 8784:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 7924:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 3252:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 9890:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 7810:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 9527:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 8993:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 1953:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 2670:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 9807:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 908:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 7276:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 7623:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 6922:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 8590:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 5856:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 3743:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 2737:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 477:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 2941:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 2810:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 7557:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 2234:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 9783:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 2481:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 4930:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 3622:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 2359:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 3901:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 6412:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 5613:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 3853:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 3215:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 5484:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 4642:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 859:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

