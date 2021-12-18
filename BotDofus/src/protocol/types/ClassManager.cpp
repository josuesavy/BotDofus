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
    
    case 9551:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 8097:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 8492:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 2694:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 436:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 7850:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 4548:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 4354:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 7522:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 7424:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 8490:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 7794:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 6359:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 4374:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 1201:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 7387:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 8132:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 8343:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 1714:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 183:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 949:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 5338:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 9654:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 4170:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 9740:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 6884:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 2406:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 6060:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 1469:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 8201:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 4565:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 9089:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 9575:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 1995:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 5640:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 6593:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 2689:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 9850:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 6386:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 5487:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 4654:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 2398:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 7425:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 6627:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 4819:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 1517:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 9771:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 815:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 6654:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 9919:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 9530:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 1657:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 7366:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 8281:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 540:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 15:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 4141:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 1349:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 5685:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 2163:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 8829:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 7384:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 5720:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 5502:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 576:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 1048:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 5415:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 4916:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 826:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 1756:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 305:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 5511:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 8583:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 5044:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 83:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 6510:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 445:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 4590:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 3292:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 3590:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 960:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 563:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 1836:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 4851:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 1909:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 7223:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 8035:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 3896:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 6223:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 4750:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 9956:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 1910:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 6784:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 3340:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 4768:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 2510:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 8087:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 2136:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 2262:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 9286:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 5191:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 6151:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 3346:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 3170:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 2517:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 3219:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 8890:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 3243:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 856:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 3536:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 6908:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 1244:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 801:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 5068:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 858:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 1922:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 108:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 5235:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 7293:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 2405:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 2861:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 5544:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 102:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 6660:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 345:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 4120:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 9532:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 9304:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 3425:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 7419:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 3824:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 3148:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 5382:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 8741:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 5071:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 6265:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 8125:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 7547:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 693:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 1192:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 3939:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 1437:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 5510:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 3456:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 1813:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 2427:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 77:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 4022:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 6505:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 3820:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 9875:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 2529:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 8142:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 3199:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 9226:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 1240:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 1975:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 2409:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 4677:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 5115:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 5149:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 736:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 6368:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 3120:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 457:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 8892:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 2015:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 253:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 6482:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 4254:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 2754:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 6139:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 4268:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 3568:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 1741:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 3550:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 6024:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 4853:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 876:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 1337:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 8231:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 6559:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 6343:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 1197:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 9471:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 5400:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 7141:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 2093:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 199:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 4747:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 4752:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 5753:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 1294:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 3556:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 6431:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 2145:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 5320:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 9376:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 169:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 3077:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 1176:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 7504:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 8535:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 6620:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 4492:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 9162:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 4720:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 8397:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 5872:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 6983:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 6844:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 9735:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 2979:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

