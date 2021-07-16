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
    
    case 1956:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 7196:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 3956:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 358:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 6670:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 9632:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 2440:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 5854:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 889:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 2799:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 9489:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 2973:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 6558:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 5973:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 6465:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 8504:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 473:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 3579:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 1184:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 3126:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 56:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 1398:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 7735:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 9761:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 2686:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 4789:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 3408:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 1753:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 4043:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 9390:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 2983:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 651:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 4252:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 7292:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 3311:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 3733:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 9221:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 8655:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 4737:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 4316:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 2474:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 6094:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 4588:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 2947:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 7131:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 7134:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 2372:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 2515:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 4466:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 9775:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 1188:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 320:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 3474:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 8477:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 7744:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 2214:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 977:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 2671:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 624:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 222:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 2694:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 6930:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 1342:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 3066:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 7506:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 6498:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 5871:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 5898:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 1327:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 4747:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 3614:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 2748:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 3086:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 8219:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 3792:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 8389:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 6309:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 2084:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 5484:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 5210:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 1785:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 8790:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 676:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 4223:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 2860:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 9750:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 6842:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 1:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 6947:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 9186:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 6899:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 4345:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 8215:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 8429:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 7651:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 8446:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 3958:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 9402:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 4668:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 9547:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 4065:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 3662:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 5019:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 261:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 9540:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 2155:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 4670:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 7631:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 4586:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 5746:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 8832:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 3338:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 8684:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 3226:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 975:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 9829:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 8023:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 3910:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 5141:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 3991:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 3550:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 5720:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 4623:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 1484:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 5654:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 8148:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 2326:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 2992:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 5203:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 7842:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 475:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 5020:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 3649:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 1656:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 7793:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 4028:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 4572:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 3247:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 8293:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 1332:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 7748:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 6314:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 5644:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 5299:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 1691:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 2314:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 1042:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 6146:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 6718:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 1676:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 8602:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 9341:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 9165:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 954:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 822:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 3840:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 109:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 1560:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 9237:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 9403:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 5895:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 9707:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 3997:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 5438:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 1867:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 3043:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 9597:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 1156:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 7050:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 4418:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 4311:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 5084:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 4951:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 992:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 1133:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 6748:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 4064:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 7031:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 3330:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 8969:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 4860:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 5155:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 8645:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 3276:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 5347:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 9693:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 6674:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 1976:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 7124:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 9304:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 3436:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 8949:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 7105:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 1326:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 2566:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 9905:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 5225:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 1195:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 223:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 4104:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 2772:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 9726:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 1273:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 1271:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 2111:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 9200:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 9792:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 8387:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 5723:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 7726:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 7005:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 6700:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

