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
    
    case 9322:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 6229:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 4314:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 5578:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 6986:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 9691:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 1792:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 9569:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 3910:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 8166:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 1096:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 7599:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 5340:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 4363:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 6150:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 8090:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 2779:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 401:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 5800:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 2803:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 9525:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 2023:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 8187:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 1698:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 5103:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 6234:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 4507:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 6808:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 522:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 9015:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 6698:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristic());
    
    case 9104:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicDetailed());
    
    case 9091:
      return QSharedPointer<AbstractClass>(new CharacterCharacteristicValue());
    
    case 5517:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 9504:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 1314:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 8837:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 2540:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 8132:
      return QSharedPointer<AbstractClass>(new FightTeamMemberEntityInformation());
    
    case 4423:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 9664:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 1704:
      return QSharedPointer<AbstractClass>(new GameFightCharacteristics());
    
    case 3845:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 2332:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 3769:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 7758:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 3811:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 7416:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 6964:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 9842:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 907:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 6364:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 9662:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 6082:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 9993:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 8628:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 8247:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 1334:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 5613:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 7591:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 2941:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 8105:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 6159:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 9360:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 4205:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 289:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 8425:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 7345:
      return QSharedPointer<AbstractClass>(new UpdateMountCharacteristic());
    
    case 2582:
      return QSharedPointer<AbstractClass>(new UpdateMountBooleanCharacteristic());
    
    case 6030:
      return QSharedPointer<AbstractClass>(new UpdateMountIntegerCharacteristic());
    
    case 4360:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 5069:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 7469:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 2328:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 3668:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 3525:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 4681:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 3311:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 1062:
      return QSharedPointer<AbstractClass>(new ShortcutEntitiesPreset());
    
    case 5710:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 4814:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 9380:
      return QSharedPointer<AbstractClass>(new AchievementAchieved());
    
    case 1727:
      return QSharedPointer<AbstractClass>(new AchievementAchievedRewardable());
    
    case 6956:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 6373:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 628:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 1930:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 8151:
      return QSharedPointer<AbstractClass>(new AcquaintanceInformation());
    
    case 9830:
      return QSharedPointer<AbstractClass>(new AcquaintanceOnlineInformation());
    
    case 5129:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 8848:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 4962:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 5896:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 5267:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 4436:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 5477:
      return QSharedPointer<AbstractClass>(new PartyEntityBaseInformation());
    
    case 7194:
      return QSharedPointer<AbstractClass>(new PartyEntityMemberInformation());
    
    case 8167:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 9391:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 1705:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 4595:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 7352:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 2516:
      return QSharedPointer<AbstractClass>(new AccountHouseInformations());
    
    case 5028:
      return QSharedPointer<AbstractClass>(new HouseInformationsInside());
    
    case 678:
      return QSharedPointer<AbstractClass>(new HouseInformationsForGuild());
    
    case 7004:
      return QSharedPointer<AbstractClass>(new HouseOnMapInformations());
    
    case 9016:
      return QSharedPointer<AbstractClass>(new HouseInstanceInformations());
    
    case 8750:
      return QSharedPointer<AbstractClass>(new HouseGuildedInformations());
    
    case 2537:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 9781:
      return QSharedPointer<AbstractClass>(new PaddockGuildedInformations());
    
    case 8664:
      return QSharedPointer<AbstractClass>(new GameContextActorPositionInformations());
    
    case 2114:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 2017:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 636:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 7065:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 9646:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 2742:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 5602:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 2563:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 1119:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 7484:
      return QSharedPointer<AbstractClass>(new GameFightEntityInformation());
    
    case 1344:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 6934:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 4340:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 1455:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 4999:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 3017:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 3789:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 4264:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 4621:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 7549:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 6519:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 7828:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 3006:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 2415:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 379:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 3871:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 8193:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 3734:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 3803:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 3623:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 5202:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 941:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 2136:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 5637:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 1104:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 5127:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 6787:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 7983:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 2290:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 3928:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 5342:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 5297:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 2137:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 6503:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 6313:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 4009:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 5819:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 5311:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 5018:
      return QSharedPointer<AbstractClass>(new SpawnInformation());
    
    case 763:
      return QSharedPointer<AbstractClass>(new BaseSpawnMonsterInformation());
    
    case 8080:
      return QSharedPointer<AbstractClass>(new SpawnScaledMonsterInformation());
    
    case 3436:
      return QSharedPointer<AbstractClass>(new SpawnMonsterInformation());
    
    case 5312:
      return QSharedPointer<AbstractClass>(new SpawnCharacterInformation());
    
    case 1934:
      return QSharedPointer<AbstractClass>(new SpawnCompanionInformation());
    
    case 3832:
      return QSharedPointer<AbstractClass>(new GameContextBasicSpawnInformation());
    
    case 9552:
      return QSharedPointer<AbstractClass>(new GameContextSummonsInformation());
    
    case 9171:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 995:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 1267:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 2897:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 6112:
      return QSharedPointer<AbstractClass>(new GameFightFighterEntityLightInformation());
    
    case 8278:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 7757:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 127:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 6226:
      return QSharedPointer<AbstractClass>(new Preset());
    
    case 4633:
      return QSharedPointer<AbstractClass>(new PresetsContainerPreset());
    
    case 1404:
      return QSharedPointer<AbstractClass>(new IconNamedPreset());
    
    case 7800:
      return QSharedPointer<AbstractClass>(new SpellsPreset());
    
    case 3222:
      return QSharedPointer<AbstractClass>(new ForgettableSpellsPreset());
    
    case 1057:
      return QSharedPointer<AbstractClass>(new StatsPreset());
    
    case 794:
      return QSharedPointer<AbstractClass>(new IdolsPreset());
    
    case 4990:
      return QSharedPointer<AbstractClass>(new EntitiesPreset());
    
    case 7899:
      return QSharedPointer<AbstractClass>(new FullStatsPreset());
    
    case 9346:
      return QSharedPointer<AbstractClass>(new ItemsPreset());
    
    case 679:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 6028:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 9914:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 9684:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 219:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 3754:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 9457:
      return QSharedPointer<AbstractClass>(new AbstractPlayerSearchInformation());
    
    case 1239:
      return QSharedPointer<AbstractClass>(new PlayerSearchTagInformation());
    
    case 3294:
      return QSharedPointer<AbstractClass>(new PlayerSearchCharacterNameInformation());
    
    case 1947:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 9563:
      return QSharedPointer<AbstractClass>(new BreachBranch());
    
    case 8201:
      return QSharedPointer<AbstractClass>(new ExtendedBreachBranch());
    
    case 130:
      return QSharedPointer<AbstractClass>(new ExtendedLockedBreachBranch());
    
    case 8621:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 181:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 821:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 6720:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 6038:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 5080:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 9231:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 8542:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 2197:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
    case 5717:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 423:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 4975:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 1100:
      return QSharedPointer<AbstractClass>(new DebtInformation());
    
    case 6337:
      return QSharedPointer<AbstractClass>(new KamaDebtInformation());
    
  }
}

