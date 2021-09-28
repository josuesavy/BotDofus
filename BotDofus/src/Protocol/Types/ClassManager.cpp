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
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristicDetailed.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristicValue.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberEntityInformation.h"
#include "src/protocol/types/data/game/context/fight/FightTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/FightAllianceTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightCharacteristics.h"
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
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/protocol/types/data/common/PlayerSearchTagInformation.h"
#include "src/protocol/types/data/common/PlayerSearchCharacterNameInformation.h"
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
    
    case 7976:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 478:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 946:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 4121:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 9998:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 5611:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 5035:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 9253:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 355:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 8739:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 885:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 7383:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 3734:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 4940:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 8072:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 9608:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 4241:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 205:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 6687:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 9453:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 3964:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 8533:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 3470:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 6093:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 4980:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 8228:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 3839:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 5173:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 543:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 9544:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 2749:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 2228:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 4916:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 2271:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 9197:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 3664:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 4225:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 8576:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 1381:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 8703:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 356:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 491:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 1742:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 8179:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 3904:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 6261:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 6408:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 2505:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 1539:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 1140:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 9926:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 4000:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 9792:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 644:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 2026:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 4511:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 469:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 7625:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 9806:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 3223:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 2029:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 561:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 7822:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 4988:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 9193:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 2018:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 9057:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 3449:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 744:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 6597:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 9070:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 2944:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 5911:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 8997:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 9238:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 8543:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 7966:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 4326:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 6440:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 5238:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 3152:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 5446:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 6764:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 8428:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 5386:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 5460:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 552:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 3387:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 3017:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 4954:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 8961:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 7588:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 2153:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 5307:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 643:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 1037:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 7231:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 5696:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 7672:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 4261:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 5272:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 8270:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 9875:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 1887:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 2945:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 2384:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 4022:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 6817:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 9190:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 7173:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 6738:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 1881:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 2757:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 7367:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 5076:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 1699:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 337:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 3601:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 2081:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 8913:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 3833:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 7553:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 9573:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 734:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 9750:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 3029:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 8822:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 6214:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 2980:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 9569:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 4060:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 441:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 8136:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 949:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 5756:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 858:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 1292:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 7996:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 1557:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 5744:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 6493:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 7160:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 5041:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 1322:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 8109:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 662:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 9533:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 8002:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 2830:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 9876:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 465:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 6744:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 1411:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 7432:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 8218:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 5280:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 6559:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 5643:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 7433:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 1150:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 3077:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 5422:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 2654:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 8052:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 7338:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 585:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 5103:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 2915:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 9473:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 3024:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 8740:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 7264:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 1920:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 83:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 6611:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 3312:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 4952:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 5627:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 9950:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 5104:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 207:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 4763:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 9255:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 1436:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 1838:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 1339:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 2242:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 4775:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 1671:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 1533:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 6007:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 8497:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 3502:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 5718:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 5689:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 591:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 9529:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 5176:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 4631:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 4565:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 6320:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 8885:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 803:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 2383:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 8764:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 4956:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 3499:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 3692:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 1901:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 424:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 3245:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 7285:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

