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
    
    case 8092:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 8093:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 3195:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 4142:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 7674:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 1115:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 2221:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 1299:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 4537:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 3712:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 7809:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 3367:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 3038:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 5618:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 7164:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 7323:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 2172:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 8509:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 2727:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 4657:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 5445:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 8797:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 6140:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 7152:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 5007:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 5770:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 2505:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 6703:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 6150:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 2110:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 9655:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 6407:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 4386:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 3192:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 3797:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 7673:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 3394:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 1273:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 7465:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 2789:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 7345:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 3838:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 6186:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 7228:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 9468:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 7696:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 5254:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 6539:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 7057:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 490:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 7210:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 6281:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 9021:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 4312:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 3328:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 5135:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 5581:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 4697:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 6830:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 6774:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 5759:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 3021:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 5835:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 6577:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 8884:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 6158:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 573:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 7629:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 2721:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 4802:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 8009:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 2990:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 5755:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 4574:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 2367:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 8507:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 7250:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 7304:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 1472:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 6332:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 3318:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 2348:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 7342:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 2243:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 5875:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 8415:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 9255:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 1757:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 4019:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 7579:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 626:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 7626:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 2089:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 9234:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 6304:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 7115:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 4932:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 9312:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 9183:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 1878:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 831:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 1842:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 6208:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 3747:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 8358:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 7811:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 9198:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 1430:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 1793:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 3631:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 7715:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 820:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 6480:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 7170:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 3465:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 4474:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 4727:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 2219:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 9147:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 5774:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 2228:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 3475:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 728:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 7636:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 8375:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 1511:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 8751:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 6260:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 3764:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 1578:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 9233:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 3578:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 5850:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 5944:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 85:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 3633:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 2054:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 6069:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 948:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 6880:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 5415:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 8991:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 6727:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 6777:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 9357:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 7384:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 4624:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 6156:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 1777:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 2532:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 7058:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 4587:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 5571:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 3208:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 1237:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 7439:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 5107:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 6861:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 6659:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 3915:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 1879:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 1601:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 5272:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 4213:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 5162:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 4971:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 6866:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 4382:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 4270:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 1283:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 4714:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 2079:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 7107:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 7566:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 8055:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 9090:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 8908:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 6693:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 3692:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 9060:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 393:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 2536:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 2953:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 1236:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 8681:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 6139:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 1853:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 7010:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 9688:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 6447:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 4403:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 6854:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 4153:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 9987:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 4262:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 5388:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 2944:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 6682:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 4228:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 8594:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 1570:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 4319:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 1851:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 4260:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 3867:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 9476:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 9177:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 8195:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 7140:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 1140:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 6526:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 4534:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

