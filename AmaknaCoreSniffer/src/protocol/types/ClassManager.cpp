#include "ClassManager.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberArenaInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/protocol/types/data/game/character/choice/CharacterHardcoreOrEpicInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalGuildInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalAllianceInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookAndGradeInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/protocol/types/data/game/context/FightEntityDispositionInformations.h"
#include "src/protocol/types/data/game/social/AbstractSocialGroupInfos.h"
#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/types/data/game/social/GuildInsiderFactSheetInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInAllianceInformations.h"
#include "src/protocol/types/data/game/social/AlliancedGuildFactSheetInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/AllianceInformations.h"
#include "src/protocol/types/data/game/social/AllianceFactSheetInformations.h"
#include "src/protocol/types/data/game/social/GuildVersatileInformations.h"
#include "src/protocol/types/data/game/social/GuildInAllianceVersatileInformations.h"
#include "src/protocol/types/data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/protocol/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/protocol/types/data/game/prism/PrismInformation.h"
#include "src/protocol/types/data/game/prism/AlliancePrismInformation.h"
#include "src/protocol/types/data/game/prism/AllianceInsiderPrismInformation.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberEntityInformation.h"
#include "src/protocol/types/data/game/context/fight/FightTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/FightAllianceTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMinimalStats.h"
#include "src/protocol/types/data/game/context/fight/GameFightMinimalStatsPreparation.h"
#include "src/protocol/types/data/game/context/fight/FightResultListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultTaxCollectorListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultPlayerListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultMutantListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/protocol/types/data/game/context/fight/FightResultPvpData.h"
#include "src/protocol/types/data/game/context/fight/FightResultExperienceData.h"
#include "src/protocol/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostStateEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporarySpellBoostEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostWeaponDamagesEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporarySpellImmunityEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTriggeredEffect.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectCreature.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectLadder.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectMinMax.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDuration.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectString.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDice.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDate.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectMount.h"
#include "src/protocol/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/protocol/types/data/game/mount/UpdateMountBooleanCharacteristic.h"
#include "src/protocol/types/data/game/mount/UpdateMountIntegerCharacteristic.h"
#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObject.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectPreset.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectIdolsPreset.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectItem.h"
#include "src/protocol/types/data/game/shortcut/ShortcutSpell.h"
#include "src/protocol/types/data/game/shortcut/ShortcutSmiley.h"
#include "src/protocol/types/data/game/shortcut/ShortcutEmote.h"
#include "src/protocol/types/data/game/shortcut/ShortcutEntitiesPreset.h"
#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/protocol/types/data/game/idol/PartyIdol.h"
#include "src/protocol/types/data/game/achievement/AchievementAchieved.h"
#include "src/protocol/types/data/game/achievement/AchievementAchievedRewardable.h"
#include "src/protocol/types/data/game/friend/IgnoredInformations.h"
#include "src/protocol/types/data/game/friend/IgnoredOnlineInformations.h"
#include "src/protocol/types/data/game/friend/FriendInformations.h"
#include "src/protocol/types/data/game/friend/FriendOnlineInformations.h"
#include "src/protocol/types/data/game/friend/AcquaintanceInformation.h"
#include "src/protocol/types/data/game/friend/AcquaintanceOnlineInformation.h"
#include "src/protocol/types/data/game/friend/FriendSpouseInformations.h"
#include "src/protocol/types/data/game/friend/FriendSpouseOnlineInformations.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementSkill.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementNamedSkill.h"
#include "src/protocol/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementWithAgeBonus.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityMemberInformation.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionCollect.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionCraft.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/data/game/house/AccountHouseInformations.h"
#include "src/protocol/types/data/game/house/HouseInformationsInside.h"
#include "src/protocol/types/data/game/house/HouseInformationsForGuild.h"
#include "src/protocol/types/data/game/house/HouseOnMapInformations.h"
#include "src/protocol/types/data/game/house/HouseInstanceInformations.h"
#include "src/protocol/types/data/game/house/HouseGuildedInformations.h"
#include "src/protocol/types/data/game/paddock/PaddockBuyableInformations.h"
#include "src/protocol/types/data/game/paddock/PaddockGuildedInformations.h"
#include "src/protocol/types/data/game/context/GameContextActorPositionInformations.h"
#include "src/protocol/types/data/game/context/GameContextActorInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightAIInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMonsterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMonsterWithAlignmentInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMutantInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightEntityInformation.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayMutantInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayCharacterInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayMountInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayMerchantInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNpcWithQuestInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayGroupMonsterWaveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayTreasureHintInformations.h"
#include "src/protocol/types/data/game/context/GameRolePlayTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayPrismInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayPortalInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionObjectUse.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionAlliance.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionGuild.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionOrnament.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionEmote.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionTitle.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionSkillUse.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionFollowers.h"
#include "src/protocol/types/data/game/context/TaxCollectorStaticInformations.h"
#include "src/protocol/types/data/game/context/TaxCollectorStaticExtendedInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorGuildInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorLootInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorWaitingForHelpInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformationsWithAlternatives.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestObjectiveInformationsWithCompletion.h"
#include "src/protocol/types/data/game/context/fight/SpawnInformation.h"
#include "src/protocol/types/data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnScaledMonsterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnMonsterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnCharacterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnCompanionInformation.h"
#include "src/protocol/types/data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/protocol/types/data/game/context/fight/GameContextSummonsInformation.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterMonsterLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterTaxCollectorLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterEntityLightInformation.h"
#include "src/protocol/types/data/game/context/MapCoordinates.h"
#include "src/protocol/types/data/game/context/MapCoordinatesAndId.h"
#include "src/protocol/types/data/game/context/MapCoordinatesExtended.h"
#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/protocol/types/data/game/presets/PresetsContainerPreset.h"
#include "src/protocol/types/data/game/presets/IconNamedPreset.h"
#include "src/protocol/types/data/game/presets/SpellsPreset.h"
#include "src/protocol/types/data/game/presets/ForgettableSpellsPreset.h"
#include "src/protocol/types/data/game/presets/StatsPreset.h"
#include "src/protocol/types/data/game/presets/IdolsPreset.h"
#include "src/protocol/types/data/game/presets/EntitiesPreset.h"
#include "src/protocol/types/data/game/presets/FullStatsPreset.h"
#include "src/protocol/types/data/game/presets/ItemsPreset.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToPOI.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepDig.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFight.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToHint.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirection.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/protocol/types/data/game/context/roleplay/breach/BreachBranch.h"
#include "src/protocol/types/data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/protocol/types/data/game/context/roleplay/breach/ExtendedLockedBreachBranch.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/character/status/PlayerStatusExtended.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstant.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantString.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantInteger.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantLong.h"
#include "src/protocol/types/data/common/basic/StatisticData.h"
#include "src/protocol/types/data/common/basic/StatisticDataInt.h"
#include "src/protocol/types/data/common/basic/StatisticDataBoolean.h"
#include "src/protocol/types/data/common/basic/StatisticDataShort.h"
#include "src/protocol/types/data/common/basic/StatisticDataString.h"
#include "src/protocol/types/data/common/basic/StatisticDataByte.h"
#include "src/protocol/types/data/game/character/debt/DebtInformation.h"
#include "src/protocol/types/data/game/character/debt/KamaDebtInformation.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 9017:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 9272:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 213:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 6321:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 7121:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 5330:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 3916:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 300:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 9668:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 3023:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 6346:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 8186:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 6801:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 4801:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 5897:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 9794:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 9940:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 274:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 8863:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 1115:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 4955:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 9961:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 1553:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 1344:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 8832:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 325:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 946:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 1525:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 1451:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 3742:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 4681:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 4605:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 9492:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 1174:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 8154:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 4686:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 6438:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 2266:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 7930:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStats());
    
    case 4441:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStatsPreparation());
    
    case 9494:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 1126:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 2949:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 1038:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 3438:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 1833:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 9936:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 5733:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 5728:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 2053:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 3882:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 846:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 6312:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 2653:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 7490:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 6605:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 5843:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 7034:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 1548:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 5036:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 3785:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 7628:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 1846:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 5410:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 6975:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 8476:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 3931:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 8508:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 1043:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 7541:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 2425:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 5835:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 4505:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 571:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 879:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 3412:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 3594:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 2929:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 1051:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 4690:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 5008:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 2408:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 8804:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 1820:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 5289:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 6697:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 2613:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 9044:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 5625:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 7363:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 7588:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 4976:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 4190:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 869:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 6554:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 3206:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 7758:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 7961:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 8200:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 9215:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 8630:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 6405:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 8727:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 4222:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 1681:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 3647:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 3664:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 355:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 4155:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 6228:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 6298:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 2640:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 3277:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 4758:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 8882:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 5594:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 201:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 7640:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 8660:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 3191:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 6486:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 1689:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 1099:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 3034:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 6918:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 9317:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 863:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 3740:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 9292:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 521:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 8498:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 487:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 4866:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 3053:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 6717:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 4884:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 9970:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 4941:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 5005:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 8260:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 5243:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 7090:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 1429:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 7484:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 3115:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 5888:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 5143:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 9776:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 1607:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 2162:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 7974:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 5768:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 7681:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 2413:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 1795:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 2312:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 1770:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 259:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 6339:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 1659:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 5401:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 5264:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 2859:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 2478:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 3995:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 4298:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 873:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 8213:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 5566:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 3866:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 5486:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 3427:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 8214:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 4804:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 9903:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 7815:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 2124:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 7595:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 3738:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 2799:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 527:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 2296:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 2193:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 2376:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 7529:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 5817:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 7770:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 9917:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 3613:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 4544:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 1023:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 6573:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 1746:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 6393:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 865:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 8194:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 6149:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 8729:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 9780:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 8706:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 8962:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 9517:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 760:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 134:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 399:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 7486:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 6089:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

