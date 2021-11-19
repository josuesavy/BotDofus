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
    
    case 3373:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 1613:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 5064:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 5607:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 2626:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 6244:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 4565:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 5168:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 1505:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 7046:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 6389:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 2016:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 3145:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 7036:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 4559:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 3077:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 574:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 9877:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 7856:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 9702:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 5140:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 1304:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 4994:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 2194:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 9677:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 7224:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 4405:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 137:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 2680:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 4664:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 5165:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 1770:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 7097:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 3495:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 5675:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 7922:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 8987:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 1261:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 5522:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 9261:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 1097:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 599:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 6695:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 4571:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 4349:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 5896:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 5956:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 4384:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 6176:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 9855:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 7062:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 155:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 8972:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 4660:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 1305:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 648:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 9523:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 5030:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 500:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 5470:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 9305:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 917:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 5647:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 6296:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 8099:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 6506:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 6967:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 8349:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 5159:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 730:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 3964:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 2610:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 3094:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 1602:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 8253:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 1096:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 333:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 1608:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 6790:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 9662:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 1230:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 695:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 9933:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 376:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 2838:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 8739:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 4065:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 3205:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 9258:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 5347:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 3147:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 8407:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 1269:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 103:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 8893:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 1005:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 899:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 9833:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 7695:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 262:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 2216:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 5059:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 1876:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 7239:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 6358:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 3543:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 8292:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 1452:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 2405:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 2740:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 5534:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 2804:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 2498:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 2832:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 5909:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 3192:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 5174:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 5464:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 2731:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 6266:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 6382:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 6706:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 7309:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 5990:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 8538:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 3492:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 8300:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 1458:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 3076:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 3953:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 4532:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 7750:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 9835:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 8644:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 6468:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 4378:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 5041:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 8448:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 9672:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 4011:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 9773:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 2557:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 2273:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 2796:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 971:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 874:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 290:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 4758:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 2254:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 8904:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 6833:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 1870:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 8179:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 2225:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 1413:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 3909:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 2606:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 974:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 5367:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 4474:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 7503:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 8807:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 7791:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 5937:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 5066:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 1496:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 3522:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 3008:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 5626:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 6952:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 3245:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 9273:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 3938:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 6896:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 6793:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 9375:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 8408:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 5260:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 4718:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 7708:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 8119:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 6206:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 8726:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 7704:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 581:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 2177:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 6943:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 5680:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 6950:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 3658:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 9506:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 5189:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 6691:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 2997:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 2839:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 1472:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 364:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 6873:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 5987:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 7115:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 7511:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 7381:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 4813:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 2691:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 7366:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 9952:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 7584:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 2326:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 3251:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 9916:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 1596:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 1134:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 3699:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

