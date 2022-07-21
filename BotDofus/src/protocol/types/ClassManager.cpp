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
#include "src/protocol/types/data/game/context/roleplay/HumanOptionSpeedMultiplier.h"
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
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildRankActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPlayerRankUpdateActivity.h"
#include "src/protocol/types/data/game/guild/logbook/chest/GuildLogbookChestActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildLevelUpActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPaddockActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPlayerFlowActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildUnlockNewTabActivity.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 8212:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 9836:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 6068:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 2014:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 1262:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 1196:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 2061:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 9911:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 8774:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 1013:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 9329:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 2021:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 2981:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 1743:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 1378:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 3899:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 3248:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 1460:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 1200:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 1267:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 4103:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 2818:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 4963:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 9751:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 3790:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 6181:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 1753:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 9724:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 5203:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 4051:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 4854:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 7776:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 8623:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 4098:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 4909:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 7627:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 6546:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 30:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 3808:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 9982:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 4521:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 2478:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 2826:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 8846:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 5278:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 6742:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 5252:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 6203:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 2300:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 7334:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 7996:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 1719:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 9241:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 4223:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 4512:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 1415:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 7192:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 4714:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 7896:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 2318:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 5256:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 3303:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 9370:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 8604:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 8860:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 8832:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 8271:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 6026:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 9752:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 960:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 1105:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 511:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 7291:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 1315:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 8402:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 8353:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 549:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 9867:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 1915:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 4371:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 5798:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 8132:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 2177:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 6683:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 2436:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 6708:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 5852:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 7194:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 2932:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 1864:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 6176:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 9569:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 7215:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 1604:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 9337:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 5109:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 3556:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 8792:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 8489:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 9835:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 2829:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 608:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 4132:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 6261:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 2065:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 8800:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 4674:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 2842:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 5515:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 7782:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 9430:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 7625:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 7693:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 9960:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 8337:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 6859:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 9184:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 6212:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 6325:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 3718:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 147:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 1078:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 1981:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 6231:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 4147:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 1173:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 6485:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 1466:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 2812:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 6424:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 9106:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 7717:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 2770:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 9575:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 7488:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 3779:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 6336:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 8501:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 2909:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 2763:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 2424:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 6904:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 3411:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 691:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 9965:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 7191:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 1571:
      return QSharedPointer<AbstractClass>(new HumanOptionSpeedMultiplier());
    
    case 6730:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 4793:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 8499:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 1044:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 373:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 4847:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 6864:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 74:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 8164:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 197:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 1923:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 6646:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 3404:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 62:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 8609:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 9755:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 2501:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 5802:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 2591:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 7394:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 5587:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 9389:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 4256:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 522:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 7583:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 6877:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 493:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 6560:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 8395:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 4499:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 2869:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 9143:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 9801:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 4113:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 4457:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 7409:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 3921:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 6578:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 3344:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 8342:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 8385:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 4322:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 2480:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 3328:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 527:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 4957:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 4733:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 7865:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 865:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 5483:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 1771:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 2621:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 9433:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 4703:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 5048:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 9527:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 2673:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 6624:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 5548:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 8415:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 6131:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 45:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 9582:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 3277:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 132:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 9455:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 2773:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
    case 8461:
      return QSharedPointer<AbstractClass>(new GuildLogbookEntryBasicInformation());
    
    case 3065:
      return QSharedPointer<AbstractClass>(new GuildRankActivity());
    
    case 222:
      return QSharedPointer<AbstractClass>(new GuildPlayerRankUpdateActivity());
    
    case 4492:
      return QSharedPointer<AbstractClass>(new GuildLogbookChestActivity());
    
    case 5284:
      return QSharedPointer<AbstractClass>(new GuildLevelUpActivity());
    
    case 3056:
      return QSharedPointer<AbstractClass>(new GuildPaddockActivity());
    
    case 507:
      return QSharedPointer<AbstractClass>(new GuildPlayerFlowActivity());
    
    case 1232:
      return QSharedPointer<AbstractClass>(new GuildUnlockNewTabActivity());
    
  }
}

