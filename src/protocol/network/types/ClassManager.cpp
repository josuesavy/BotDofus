#include "ClassManager.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/protocol/types/data/common/PlayerSearchCharacterNameInformation.h"
#include "src/protocol/types/data/common/PlayerSearchTagInformation.h"
#include "src/protocol/types/data/common/basic/StatisticData.h"
#include "src/protocol/types/data/common/basic/StatisticDataBoolean.h"
#include "src/protocol/types/data/common/basic/StatisticDataByte.h"
#include "src/protocol/types/data/common/basic/StatisticDataInt.h"
#include "src/protocol/types/data/common/basic/StatisticDataShort.h"
#include "src/protocol/types/data/common/basic/StatisticDataString.h"
#include "src/protocol/types/data/game/achievement/AchievementAchieved.h"
#include "src/protocol/types/data/game/achievement/AchievementAchievedRewardable.h"
#include "src/protocol/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostStateEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostWeaponDamagesEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporarySpellBoostEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporarySpellImmunityEffect.h"
#include "src/protocol/types/data/game/actions/fight/FightTriggeredEffect.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstant.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantInteger.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantLong.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstantString.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristicDetailed.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristicValue.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterUsableCharacteristicDetailed.h"
#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/types/data/game/character/choice/CharacterHardcoreOrEpicInformations.h"
#include "src/protocol/types/data/game/character/debt/DebtInformation.h"
#include "src/protocol/types/data/game/character/debt/KamaDebtInformation.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/character/status/PlayerStatusExtended.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorComplementaryInformations.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorLootInformations.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorWaitingForHelpInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/context/FightEntityDispositionInformations.h"
#include "src/protocol/types/data/game/context/GameContextActorInformations.h"
#include "src/protocol/types/data/game/context/GameContextActorPositionInformations.h"
#include "src/protocol/types/data/game/context/GameRolePlayTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/IdentifiedEntityDispositionInformations.h"
#include "src/protocol/types/data/game/context/MapCoordinates.h"
#include "src/protocol/types/data/game/context/MapCoordinatesAndId.h"
#include "src/protocol/types/data/game/context/MapCoordinatesExtended.h"
#include "src/protocol/types/data/game/context/TaxCollectorStaticInformations.h"
#include "src/protocol/types/data/game/context/fight/BaseSpawnMonsterInformation.h"
#include "src/protocol/types/data/game/context/fight/FightAllianceTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/protocol/types/data/game/context/fight/FightResultExperienceData.h"
#include "src/protocol/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultMutantListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultPlayerListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightResultPvpData.h"
#include "src/protocol/types/data/game/context/fight/FightResultTaxCollectorListEntry.h"
#include "src/protocol/types/data/game/context/fight/FightTeamInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberEntityInformation.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameContextBasicSpawnInformation.h"
#include "src/protocol/types/data/game/context/fight/GameContextSummonsInformation.h"
#include "src/protocol/types/data/game/context/fight/GameFightAIInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightCharacterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightCharacteristics.h"
#include "src/protocol/types/data/game/context/fight/GameFightEntityInformation.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterEntityLightInformation.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterMonsterLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterNamedLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterTaxCollectorLightInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMonsterInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMonsterWithAlignmentInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightMutantInformations.h"
#include "src/protocol/types/data/game/context/fight/GameFightTaxCollectorInformations.h"
#include "src/protocol/types/data/game/context/fight/SpawnCharacterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnCompanionInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnMonsterInformation.h"
#include "src/protocol/types/data/game/context/fight/SpawnScaledMonsterInformation.h"
#include "src/protocol/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayCharacterInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayGroupMonsterWaveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayMountInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayMutantInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayNpcWithQuestInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayPortalInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayPrismInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayTreasureHintInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformationsWithAlternatives.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanInformations.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionAlliance.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionEmote.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionFollowers.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionGuild.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionObjectUse.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionOrnament.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionSkillUse.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionSpeedMultiplier.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOptionTitle.h"
#include "src/protocol/types/data/game/context/roleplay/breach/BreachBranch.h"
#include "src/protocol/types/data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/protocol/types/data/game/context/roleplay/breach/ExtendedLockedBreachBranch.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberArenaInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityMemberInformation.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestObjectiveInformationsWithCompletion.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepDig.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFight.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirection.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToHint.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToPOI.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectCreature.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDate.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDice.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectDuration.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectInteger.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectLadder.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectMinMax.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectMount.h"
#include "src/protocol/types/data/game/data/items/effects/ObjectEffectString.h"
#include "src/protocol/types/data/game/friend/AcquaintanceInformation.h"
#include "src/protocol/types/data/game/friend/AcquaintanceOnlineInformation.h"
#include "src/protocol/types/data/game/friend/FriendInformations.h"
#include "src/protocol/types/data/game/friend/FriendOnlineInformations.h"
#include "src/protocol/types/data/game/friend/FriendSpouseInformations.h"
#include "src/protocol/types/data/game/friend/FriendSpouseOnlineInformations.h"
#include "src/protocol/types/data/game/friend/IgnoredInformations.h"
#include "src/protocol/types/data/game/friend/IgnoredOnlineInformations.h"
#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/protocol/types/data/game/guild/logbook/chest/GuildLogbookChestActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildLevelUpActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPaddockActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPlayerFlowActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildPlayerRankUpdateActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildRankActivity.h"
#include "src/protocol/types/data/game/guild/logbook/global/GuildUnlockNewTabActivity.h"
#include "src/protocol/types/data/game/house/AccountHouseInformations.h"
#include "src/protocol/types/data/game/house/HouseGuildedInformations.h"
#include "src/protocol/types/data/game/house/HouseInformations.h"
#include "src/protocol/types/data/game/house/HouseInformationsForGuild.h"
#include "src/protocol/types/data/game/house/HouseInformationsInside.h"
#include "src/protocol/types/data/game/house/HouseInstanceInformations.h"
#include "src/protocol/types/data/game/house/HouseOnMapInformations.h"
#include "src/protocol/types/data/game/idol/Idol.h"
#include "src/protocol/types/data/game/idol/PartyIdol.h"
#include "src/protocol/types/data/game/interactive/InteractiveElement.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementNamedSkill.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementSkill.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementWithAgeBonus.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionCollect.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionCraft.h"
#include "src/protocol/types/data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "src/protocol/types/data/game/mount/UpdateMountBooleanCharacteristic.h"
#include "src/protocol/types/data/game/mount/UpdateMountCharacteristic.h"
#include "src/protocol/types/data/game/mount/UpdateMountIntegerCharacteristic.h"
#include "src/protocol/types/data/game/paddock/PaddockBuyableInformations.h"
#include "src/protocol/types/data/game/paddock/PaddockGuildedInformations.h"
#include "src/protocol/types/data/game/presets/EntitiesPreset.h"
#include "src/protocol/types/data/game/presets/ForgettableSpellsPreset.h"
#include "src/protocol/types/data/game/presets/FullStatsPreset.h"
#include "src/protocol/types/data/game/presets/IconNamedPreset.h"
#include "src/protocol/types/data/game/presets/IdolsPreset.h"
#include "src/protocol/types/data/game/presets/ItemsPreset.h"
#include "src/protocol/types/data/game/presets/Preset.h"
#include "src/protocol/types/data/game/presets/PresetsContainerPreset.h"
#include "src/protocol/types/data/game/presets/SpellsPreset.h"
#include "src/protocol/types/data/game/presets/StatsPreset.h"
#include "src/protocol/types/data/game/prism/AllianceInsiderPrismInformation.h"
#include "src/protocol/types/data/game/prism/AlliancePrismInformation.h"
#include "src/protocol/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/protocol/types/data/game/prism/PrismInformation.h"
#include "src/protocol/types/data/game/shortcut/Shortcut.h"
#include "src/protocol/types/data/game/shortcut/ShortcutEmote.h"
#include "src/protocol/types/data/game/shortcut/ShortcutEntitiesPreset.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObject.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectIdolsPreset.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectItem.h"
#include "src/protocol/types/data/game/shortcut/ShortcutObjectPreset.h"
#include "src/protocol/types/data/game/shortcut/ShortcutSmiley.h"
#include "src/protocol/types/data/game/shortcut/ShortcutSpell.h"
#include "src/protocol/types/data/game/social/AbstractSocialGroupInfos.h"
#include "src/protocol/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/types/data/game/social/GuildInsiderFactSheetInformations.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 2007:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 2067:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 9215:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 962:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 3199:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 3882:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 8082:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 6330:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 8875:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 5233:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 6388:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 7208:
      return QSharedPointer<AbstractClass>(new AllianceInformation());
    
    case 2341:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformation());
    
    case 1665:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 1185:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 7035:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 1398:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 5265:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 7681:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 5165:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 4112:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 6545:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 1174:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 6224:
      return QSharedPointer<AbstractClass>(new CharacterUsableCharacteristicDetailed());
    
    case 3040:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 9234:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 1973:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 9350:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 6760:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 1583:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 236:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 8480:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 4046:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 6446:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 3460:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 9754:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 4665:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 4904:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 9882:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 366:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 6157:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 663:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 7759:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 5454:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 8908:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 9797:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 8848:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 7238:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 2847:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 4580:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 5182:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 7875:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 8329:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 1424:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 5867:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 4550:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 9254:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 3046:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 9469:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 3174:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 8363:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 4953:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 1969:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 4285:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 6115:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 4184:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 8293:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 8581:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 8731:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 9342:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 2560:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 2308:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 9009:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 1163:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 2287:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 1855:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 1962:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 5091:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 6772:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 8672:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 248:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 8911:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 6627:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 2711:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 4290:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 6125:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 4350:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 2574:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 1101:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 7502:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 8432:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 2954:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 2003:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 867:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 5253:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 8990:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 7264:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 799:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 3322:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 9518:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 6670:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 7576:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 6153:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 3319:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 3110:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 7652:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 5342:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 2152:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 8881:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 6740:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 9015:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 4659:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 597:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 1812:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 6589:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 7110:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 7665:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 1792:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 1610:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 7731:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 1297:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 2939:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 496:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 5217:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 8323:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 6621:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 7276:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 9408:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 2997:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 8021:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 8074:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 4329:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 5139:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 1901:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 2179:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 782:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 3553:
      return QSharedPointer<AbstractClass>(new HumanOptionSpeedMultiplier());
    
    case 7719:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 2283:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 2913:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 1712:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 1423:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 1443:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 1192:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 8094:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 1655:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 9691:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 4083:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 1671:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 8723:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 2475:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 3386:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 9201:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 7232:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 9815:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 2837:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 7053:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 3588:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 124:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 7477:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 6431:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 5658:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 41:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 8150:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 3485:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 1091:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 9112:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 4724:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 4879:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 9888:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 8158:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 2099:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 651:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 6494:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 9368:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 7201:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 9962:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 961:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 1222:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 2955:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 1329:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 1498:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 5941:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 5909:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 25:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 1986:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 4911:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 8196:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 3965:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 9862:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 6773:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 5706:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 344:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 5058:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 8738:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 1419:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 3598:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 8460:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 601:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 7540:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 2428:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 348:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
    case 3876:
      return QSharedPointer<AbstractClass>(new GuildLogbookEntryBasicInformation());
    
    case 7662:
      return QSharedPointer<AbstractClass>(new GuildRankActivity());
    
    case 1236:
      return QSharedPointer<AbstractClass>(new GuildPlayerRankUpdateActivity());
    
    case 6747:
      return QSharedPointer<AbstractClass>(new GuildLogbookChestActivity());
    
    case 7925:
      return QSharedPointer<AbstractClass>(new GuildLevelUpActivity());
    
    case 6202:
      return QSharedPointer<AbstractClass>(new GuildPaddockActivity());
    
    case 9354:
      return QSharedPointer<AbstractClass>(new GuildPlayerFlowActivity());
    
    case 9853:
      return QSharedPointer<AbstractClass>(new GuildUnlockNewTabActivity());
    
  }
}

