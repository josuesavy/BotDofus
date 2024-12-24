#include "ClassManager.h"
#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/protocol/network/types/data/common/PlayerSearchCharacterNameInformation.h"
#include "src/protocol/network/types/data/common/PlayerSearchTagInformation.h"
#include "src/protocol/network/types/data/common/basic/StatisticData.h"
#include "src/protocol/network/types/data/common/basic/StatisticDataBoolean.h"
#include "src/protocol/network/types/data/common/basic/StatisticDataByte.h"
#include "src/protocol/network/types/data/common/basic/StatisticDataInt.h"
#include "src/protocol/network/types/data/common/basic/StatisticDataShort.h"
#include "src/protocol/network/types/data/common/basic/StatisticDataString.h"
#include "src/protocol/network/types/data/game/achievement/AchievementAchieved.h"
#include "src/protocol/network/types/data/game/achievement/AchievementAchievedRewardable.h"
#include "src/protocol/network/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightDetailedTemporaryBoostEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostStateEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostWeaponDamagesEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporarySpellBoostEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporarySpellImmunityEffect.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTriggeredEffect.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstant.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstantInteger.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstantLong.h"
#include "src/protocol/network/types/data/game/approach/ServerSessionConstantString.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicDetailed.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicValue.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterUsableCharacteristicDetailed.h"
#include "src/protocol/network/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/network/types/data/game/character/choice/CharacterHardcoreOrEpicInformations.h"
#include "src/protocol/network/types/data/game/character/debt/DebtInformation.h"
#include "src/protocol/network/types/data/game/character/debt/KamaDebtInformation.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatusExtended.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorComplementaryInformations.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorLootInformations.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorWaitingForHelpInformations.h"
#include "src/protocol/network/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/context/FightEntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/context/GameContextActorInformations.h"
#include "src/protocol/network/types/data/game/context/GameContextActorPositionInformations.h"
#include "src/protocol/network/types/data/game/context/GameRolePlayTaxCollectorInformations.h"
#include "src/protocol/network/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/protocol/network/types/data/game/context/MapCoordinates.h"
#include "src/protocol/network/types/data/game/context/MapCoordinatesAndId.h"
#include "src/protocol/network/types/data/game/context/MapCoordinatesExtended.h"
#include "src/protocol/network/types/data/game/context/TaxCollectorStaticInformations.h"
#include "src/protocol/network/types/data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/protocol/network/types/data/game/context/fight/FightAllianceTeamInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultExperienceData.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultListEntry.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultMutantListEntry.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultPlayerListEntry.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultPvpData.h"
#include "src/protocol/network/types/data/game/context/fight/FightResultTaxCollectorListEntry.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberEntityInformation.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "src/protocol/network/types/data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/protocol/network/types/data/game/context/fight/GameContextSummonsInformation.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightAIInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightCharacterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightCharacteristics.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightEntityInformation.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterEntityLightInformation.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterMonsterLightInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterNamedLightInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterTaxCollectorLightInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightMonsterInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightMonsterWithAlignmentInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightMutantInformations.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightTaxCollectorInformations.h"
#include "src/protocol/network/types/data/game/context/fight/SpawnCharacterInformation.h"
#include "src/protocol/network/types/data/game/context/fight/SpawnCompanionInformation.h"
#include "src/protocol/network/types/data/game/context/fight/SpawnInformation.h"
#include "src/protocol/network/types/data/game/context/fight/SpawnMonsterInformation.h"
#include "src/protocol/network/types/data/game/context/fight/SpawnScaledMonsterInformation.h"
#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeTargetInformation.h"
#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeTargetWithAttackerInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayCharacterInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayGroupMonsterWaveInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayMountInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayMutantInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayNpcWithQuestInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayPortalInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayPrismInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GameRolePlayTreasureHintInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/GroupMonsterStaticInformationsWithAlternatives.h"
#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOption.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionAlliance.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionEmote.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionFollowers.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionGuild.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionObjectUse.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionOrnament.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionSkillUse.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionSpeedMultiplier.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOptionTitle.h"
#include "src/protocol/network/types/data/game/context/roleplay/breach/BreachBranch.h"
#include "src/protocol/network/types/data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/protocol/network/types/data/game/context/roleplay/breach/ExtendedLockedBreachBranch.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/PartyMemberArenaInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/entity/PartyEntityMemberInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestObjectiveInformationsWithCompletion.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepDig.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFight.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirection.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToHint.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToPOI.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectCreature.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectDate.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectDice.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectDuration.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectLadder.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectMinMax.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectMount.h"
#include "src/protocol/network/types/data/game/data/items/effects/ObjectEffectString.h"
#include "src/protocol/network/types/data/game/friend/AcquaintanceInformation.h"
#include "src/protocol/network/types/data/game/friend/AcquaintanceOnlineInformation.h"
#include "src/protocol/network/types/data/game/friend/FriendInformations.h"
#include "src/protocol/network/types/data/game/friend/FriendOnlineInformations.h"
#include "src/protocol/network/types/data/game/friend/FriendSpouseInformations.h"
#include "src/protocol/network/types/data/game/friend/FriendSpouseOnlineInformations.h"
#include "src/protocol/network/types/data/game/friend/IgnoredInformations.h"
#include "src/protocol/network/types/data/game/friend/IgnoredOnlineInformations.h"
#include "src/protocol/network/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/protocol/network/types/data/game/guild/logbook/chest/GuildLogbookChestActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildLevelUpActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildPaddockActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildPlayerFlowActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildPlayerRankUpdateActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildRankActivity.h"
#include "src/protocol/network/types/data/game/guild/logbook/global/GuildUnlockNewTabActivity.h"
#include "src/protocol/network/types/data/game/house/AccountHouseInformations.h"
#include "src/protocol/network/types/data/game/house/HouseGuildedInformations.h"
#include "src/protocol/network/types/data/game/house/HouseInformations.h"
#include "src/protocol/network/types/data/game/house/HouseInformationsForGuild.h"
#include "src/protocol/network/types/data/game/house/HouseInformationsInside.h"
#include "src/protocol/network/types/data/game/house/HouseInstanceInformations.h"
#include "src/protocol/network/types/data/game/house/HouseOnMapInformations.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElementNamedSkill.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElementSkill.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElementWithAgeBonus.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescriptionCollect.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescriptionCraft.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "src/protocol/network/types/data/game/mount/UpdateMountBooleanCharacteristic.h"
#include "src/protocol/network/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/protocol/network/types/data/game/mount/UpdateMountIntegerCharacteristic.h"
#include "src/protocol/network/types/data/game/paddock/PaddockBuyableInformations.h"
#include "src/protocol/network/types/data/game/paddock/PaddockGuildedInformations.h"
#include "src/protocol/network/types/data/game/presets/EntitiesPreset.h"
#include "src/protocol/network/types/data/game/presets/ForgettableSpellsPreset.h"
#include "src/protocol/network/types/data/game/presets/FullStatsPreset.h"
#include "src/protocol/network/types/data/game/presets/IconNamedPreset.h"
#include "src/protocol/network/types/data/game/presets/ItemsPreset.h"
#include "src/protocol/network/types/data/game/presets/Preset.h"
#include "src/protocol/network/types/data/game/presets/PresetsContainerPreset.h"
#include "src/protocol/network/types/data/game/presets/SpellsPreset.h"
#include "src/protocol/network/types/data/game/presets/StatsPreset.h"
#include "src/protocol/network/types/data/game/prism/AllianceInsiderPrismInformation.h"
#include "src/protocol/network/types/data/game/prism/AlliancePrismInformation.h"
#include "src/protocol/network/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/protocol/network/types/data/game/prism/PrismInformation.h"
#include "src/protocol/network/types/data/game/shortcut/Shortcut.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutEmote.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutEntitiesPreset.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutObject.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutObjectItem.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutObjectPreset.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutSmiley.h"
#include "src/protocol/network/types/data/game/shortcut/ShortcutSpell.h"
#include "src/protocol/network/types/data/game/social/AbstractSocialGroupInfos.h"
#include "src/protocol/network/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/protocol/network/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/network/types/data/game/social/GuildInsiderFactSheetInformations.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderAccepted.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderRefused.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderRefusedBeforeTurn.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderRefusedBeforeVote.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderResponse.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteAccepted.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefused.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefusedAlreadyAsked.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefusedBeforeTurn.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteRefusedWaitBetweenVotes.h"
#include "src/protocol/network/types/data/game/surrender/vote/SurrenderVoteResponse.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 4367:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 9391:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 2056:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 3577:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 3983:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 4052:
      return QSharedPointer<AbstractClass>(new ChallengeTargetInformation());
    
    case 540:
      return QSharedPointer<AbstractClass>(new ChallengeTargetWithAttackerInformation());
    
    case 2447:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 619:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 3736:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 6837:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 2995:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 5416:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 1197:
      return QSharedPointer<AbstractClass>(new AllianceInformation());
    
    case 6340:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformation());
    
    case 4606:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 7929:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 643:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 9836:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 9281:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 65:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 4594:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 7229:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 6701:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 901:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 1943:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 3951:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 9810:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 4535:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 793:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 4832:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 7397:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 5854:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 3291:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 8585:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 714:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 3594:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 613:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 6507:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 6813:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 2795:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 8078:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 7233:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 5571:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 4079:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 2521:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 4574:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 7119:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 2061:
      return QSharedPointer<AbstractClass>(new FightDetailedTemporaryBoostEffect());
    
    case 9695:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 3450:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 5487:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 7605:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 3930:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 3987:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 5489:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 843:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 7031:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 3424:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 670:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 3435:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 3353:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 470:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 2137:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 5600:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 5117:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 8861:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 1697:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 2079:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 576:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 4118:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 1189:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 3288:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 6607:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 9874:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 2099:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 941:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 861:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 9348:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 1584:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 251:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 8260:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 8676:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 2087:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 7880:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 6065:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 2952:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 5790:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 118:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 3573:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 1078:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 5684:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 5905:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 2374:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 8406:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 2801:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 409:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 5255:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 3219:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 4071:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 5612:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 4294:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 3056:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 9060:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 5601:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 8061:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 1792:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 7656:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 7175:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 4176:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 3578:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 419:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 4556:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 8764:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 2808:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 9318:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 2574:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 9304:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 9212:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 8347:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 7588:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 7360:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 6822:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 9279:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 4101:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 7369:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 9999:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 495:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 7701:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 446:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 7953:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 1132:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 5782:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 7646:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 2189:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 2036:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 4364:
      return QSharedPointer<AbstractClass>(new HumanOptionSpeedMultiplier());
    
    case 8287:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 1672:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 4158:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 1982:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 4183:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 5931:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 5953:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 4829:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 7048:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 7451:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 7248:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 8731:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 339:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 5062:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 8568:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 571:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 3409:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 4847:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 1891:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 5419:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 4794:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 3925:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 5195:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 3310:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 3181:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 315:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 7010:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 1599:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 3628:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 5695:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 2553:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 7774:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 6253:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 1993:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 6250:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 4653:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 4783:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 8185:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 9275:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 5858:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 9719:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 8809:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 9008:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 1300:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 3389:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 3022:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 2396:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 7507:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 8307:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 4080:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 2273:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 8257:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 9977:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 7359:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 2867:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 4175:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 1815:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 7834:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 7901:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 1762:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 4102:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 4573:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 8943:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 2104:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
    case 8590:
      return QSharedPointer<AbstractClass>(new GuildLogbookEntryBasicInformation());
    
    case 3270:
      return QSharedPointer<AbstractClass>(new GuildRankActivity());
    
    case 8680:
      return QSharedPointer<AbstractClass>(new GuildPlayerRankUpdateActivity());
    
    case 9067:
      return QSharedPointer<AbstractClass>(new GuildLogbookChestActivity());
    
    case 3398:
      return QSharedPointer<AbstractClass>(new GuildLevelUpActivity());
    
    case 3935:
      return QSharedPointer<AbstractClass>(new GuildPaddockActivity());
    
    case 2970:
      return QSharedPointer<AbstractClass>(new GuildPlayerFlowActivity());
    
    case 7681:
      return QSharedPointer<AbstractClass>(new GuildUnlockNewTabActivity());
    
    case 8655:
      return QSharedPointer<AbstractClass>(new SurrenderResponse());
    
    case 8906:
      return QSharedPointer<AbstractClass>(new SurrenderRefused());
    
    case 9548:
      return QSharedPointer<AbstractClass>(new SurrenderRefusedBeforeTurn());
    
    case 2726:
      return QSharedPointer<AbstractClass>(new SurrenderRefusedBeforeVote());
    
    case 8859:
      return QSharedPointer<AbstractClass>(new SurrenderAccepted());
    
    case 3674:
      return QSharedPointer<AbstractClass>(new SurrenderVoteResponse());
    
    case 1140:
      return QSharedPointer<AbstractClass>(new SurrenderVoteRefused());
    
    case 5188:
      return QSharedPointer<AbstractClass>(new SurrenderVoteRefusedWaitBetweenVotes());
    
    case 9709:
      return QSharedPointer<AbstractClass>(new SurrenderVoteRefusedBeforeTurn());
    
    case 8978:
      return QSharedPointer<AbstractClass>(new SurrenderVoteRefusedAlreadyAsked());
    
    case 8687:
      return QSharedPointer<AbstractClass>(new SurrenderVoteAccepted());
    
  }
}

