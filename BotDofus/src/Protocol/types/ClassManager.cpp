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
#include "src/protocol/types/data/game/character/characteristic/CharacterUsableCharacteristicDetailed.h"
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
    
    case 8502:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 7716:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 4365:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 2040:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 1210:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 3259:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 6019:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 6683:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 2193:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 1636:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 2881:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 7965:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 6369:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 3077:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 4809:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 1129:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 6349:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 8691:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 1873:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 8701:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 5829:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 2370:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 710:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 3812:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 4605:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 2799:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 8095:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 3353:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 2845:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 8455:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 2951:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 4869:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 2839:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 3392:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 9737:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 4188:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 9579:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 7074:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 184:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 4423:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 4944:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 2617:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 156:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 1131:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 4759:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 5436:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 6439:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 780:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 1199:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 9849:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 3400:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 5163:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 2399:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 2050:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 6087:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 22:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 893:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 5229:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 383:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 7767:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 4098:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 2619:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 4995:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 8087:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 1995:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 7029:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 7625:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 677:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 6778:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 6273:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 1447:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 4584:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 713:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 3698:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 105:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 1441:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 844:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 9559:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 9177:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 8874:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 9244:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 5294:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 5630:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 8724:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 8757:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 77:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 7985:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 8381:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 9270:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 8561:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 1681:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 8257:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 9614:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 6443:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 1909:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 7924:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 6250:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 6291:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 7363:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 3865:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 1019:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 726:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 7130:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 1719:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 6064:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 5064:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 9305:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 482:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 4102:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 3203:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 6617:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 9535:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 8540:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 4318:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 3984:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 371:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 6902:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 599:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 7974:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 4926:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 4694:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 2406:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 3704:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 5753:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 6746:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 4072:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 7990:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 6990:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 8597:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 4823:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 246:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 7275:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 3235:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 1568:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 8285:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 7095:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 1845:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 8384:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 2696:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 4284:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 752:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 2783:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 6947:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 4815:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 9666:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 3819:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 4666:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 5470:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 5078:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 2392:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 2589:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 6295:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 5840:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 2303:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 7969:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 3492:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 1125:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 2743:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 6157:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 8545:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 2311:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 2632:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 1666:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 7535:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 6489:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 951:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 6819:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 1598:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 9160:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 9304:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 5848:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 1780:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 4351:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 433:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 1003:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 4546:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 7595:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 9883:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 4824:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 6037:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 2821:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 3605:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 8762:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 4971:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 2631:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 6029:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 3169:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 8913:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 1472:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 5052:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 45:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 2034:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 6358:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 3914:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 6521:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 1468:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 6499:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 2530:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 6885:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 4685:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 6974:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 4254:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 3099:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 3982:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 9234:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 8705:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 7564:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 3771:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 6033:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 2427:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 8011:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 9175:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 6835:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

