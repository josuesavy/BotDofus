#ifndef ENUMDECLARATOR_H
#define ENUMDECLARATOR_H

#include "src/Protocol/Enums/Data/AccessoryPreviewErrorEnum.h"
#include "src/Protocol/Enums/Data/AggressableStatusEnum.h"
#include "src/Protocol/Enums/Data/AlignmentSideEnum.h"
#include "src/Protocol/Enums/Data/AlignmentWarEffortDonationResultEnum.h"
#include "src/Protocol/Enums/Data/AlliancePrismModuleTypeEnum.h"
#include "src/Protocol/Enums/Data/AllianceRightsBitEnum.h"
#include "src/Protocol/Enums/Data/BidActionEnum.h"
#include "src/Protocol/Enums/Data/BidCancellationEnum.h"
#include "src/Protocol/Enums/Data/BidValidationEnum.h"
#include "src/Protocol/Enums/Data/BoostableCharacteristicEnum.h"
#include "src/Protocol/Enums/Data/BreachRewardLockEnum.h"
#include "src/Protocol/Enums/Data/BreachRoomUnlockEnum.h"
#include "src/Protocol/Enums/Data/BreedEnum.h"
#include "src/Protocol/Enums/Data/BuildTypeEnum.h"
#include "src/Protocol/Enums/Data/CharacterCreationResultEnum.h"
#include "src/Protocol/Enums/Data/CharacterDeletionErrorEnum.h"
#include "src/Protocol/Enums/Data/CharacterInventoryPositionEnum.h"
#include "src/Protocol/Enums/Data/CharacterRemodelingEnum.h"
#include "src/Protocol/Enums/Data/CharacterSpellModificationTypeEnum.h"
#include "src/Protocol/Enums/Data/ChatActivableChannelsEnum.h"
#include "src/Protocol/Enums/Data/ChatChannelsMultiEnum.h"
#include "src/Protocol/Enums/Data/ChatErrorEnum.h"
#include "src/Protocol/Enums/Data/ClientUITypeEnum.h"
#include "src/Protocol/Enums/Data/CompassTypeEnum.h"
#include "src/Protocol/Enums/Data/ConsoleMessageTypeEnum.h"
#include "src/Protocol/Enums/Data/CraftResultEnum.h"
#include "src/Protocol/Enums/Data/DebugLevelEnum.h"
#include "src/Protocol/Enums/Data/DelayedActionTypeEnum.h"
#include "src/Protocol/Enums/Data/DialogTypeEnum.h"
#include "src/Protocol/Enums/Data/ExchangeErrorEnum.h"
#include "src/Protocol/Enums/Data/ExchangeHandleMountStableTypeEnum.h"
#include "src/Protocol/Enums/Data/ExchangeReplayStopReasonEnum.h"
#include "src/Protocol/Enums/Data/ExchangeTypeEnum.h"
#include "src/Protocol/Enums/Data/FightDispellableEnum.h"
#include "src/Protocol/Enums/Data/FighterRefusedReasonEnum.h"
#include "src/Protocol/Enums/Data/FightOptionsEnum.h"
#include "src/Protocol/Enums/Data/FightOutcomeEnum.h"
#include "src/Protocol/Enums/Data/FightSpellCastCriticalEnum.h"
#include "src/Protocol/Enums/Data/FightTypeEnum.h"
#include "src/Protocol/Enums/Data/ForgettableSpellClientActionEnum.h"
#include "src/Protocol/Enums/Data/ForgettableSpellListActionEnum.h"
#include "src/Protocol/Enums/Data/GameActionFightInvisibilityStateEnum.h"
#include "src/Protocol/Enums/Data/GameActionMarkCellsTypeEnum.h"
#include "src/Protocol/Enums/Data/GameContextEnum.h"
#include "src/Protocol/Enums/Data/GameHierarchyEnum.h"
#include "src/Protocol/Enums/Data/GameServerTypeEnum.h"
#include "src/Protocol/Enums/Data/GuildInformationsTypeEnum.h"
#include "src/Protocol/Enums/Data/GuildRightsBitEnum.h"
#include "src/Protocol/Enums/Data/HaapiAuthTypeEnum.h"
#include "src/Protocol/Enums/Data/HaapiSessionTypeEnum.h"
#include "src/Protocol/Enums/Data/HavenBagDailyLoteryErrorEnum.h"
#include "src/Protocol/Enums/Data/HavenBagRoomActionEnum.h"
#include "src/Protocol/Enums/Data/HavenBagShareBitEnum.h"
#include "src/Protocol/Enums/Data/IdentificationFailureReasonEnum.h"
#include "src/Protocol/Enums/Data/ListAddFailureEnum.h"
#include "src/Protocol/Enums/Data/LockableResultEnum.h"
#include "src/Protocol/Enums/Data/MapObstacleStateEnum.h"
#include "src/Protocol/Enums/Data/MountCharacteristicEnum.h"
#include "src/Protocol/Enums/Data/MountEquipedErrorEnum.h"
#include "src/Protocol/Enums/Data/NicknameErrorEnum.h"
#include "src/Protocol/Enums/Data/ObjectErrorEnum.h"
#include "src/Protocol/Enums/Data/PartyJoinErrorEnum.h"
#include "src/Protocol/Enums/Data/PartyNameErrorEnum.h"
#include "src/Protocol/Enums/Data/PartyTypeEnum.h"
#include "src/Protocol/Enums/Data/PlayableBreedEnum.h"
#include "src/Protocol/Enums/Data/PlayerLifeStatusEnum.h"
#include "src/Protocol/Enums/Data/PlayerStateEnum.h"
#include "src/Protocol/Enums/Data/PlayerStatusEnum.h"
#include "src/Protocol/Enums/Data/PresetDeleteResultEnum.h"
#include "src/Protocol/Enums/Data/PresetSaveResultEnum.h"
#include "src/Protocol/Enums/Data/PresetUseResultEnum.h"
#include "src/Protocol/Enums/Data/PrismListenEnum.h"
#include "src/Protocol/Enums/Data/PrismSetSabotagedRefusedReasonEnum.h"
#include "src/Protocol/Enums/Data/PrismStateEnum.h"
#include "src/Protocol/Enums/Data/PvpArenaStepEnum.h"
#include "src/Protocol/Enums/Data/PvpArenaTypeEnum.h"
#include "src/Protocol/Enums/Data/SavablePresetTypeEnum.h"
#include "src/Protocol/Enums/Data/ServerCompletionEnum.h"
#include "src/Protocol/Enums/Data/ServerConnectionErrorEnum.h"
#include "src/Protocol/Enums/Data/ServerStatusEnum.h"
#include "src/Protocol/Enums/Data/ShortcutBarEnum.h"
#include "src/Protocol/Enums/Data/SocialContactCategoryEnum.h"
#include "src/Protocol/Enums/Data/SocialGroupCreationResultEnum.h"
#include "src/Protocol/Enums/Data/SocialGroupInvitationStateEnum.h"
#include "src/Protocol/Enums/Data/SocialNoticeErrorEnum.h"
#include "src/Protocol/Enums/Data/StatsUpgradeResultEnum.h"
#include "src/Protocol/Enums/Data/SubEntityBindingPointCategoryEnum.h"
#include "src/Protocol/Enums/Data/SubscriptionRequiredEnum.h"
#include "src/Protocol/Enums/Data/TaxCollectorErrorReasonEnum.h"
#include "src/Protocol/Enums/Data/TaxCollectorMovementTypeEnum.h"
#include "src/Protocol/Enums/Data/TaxCollectorStateEnum.h"
#include "src/Protocol/Enums/Data/TeamEnum.h"
#include "src/Protocol/Enums/Data/TeamTypeEnum.h"
#include "src/Protocol/Enums/Data/TeleporterTypeEnum.h"
#include "src/Protocol/Enums/Data/TextInformationTypeEnum.h"
#include "src/Protocol/Enums/Data/TreasureHuntDigRequestEnum.h"
#include "src/Protocol/Enums/Data/TreasureHuntFlagRequestEnum.h"
#include "src/Protocol/Enums/Data/TreasureHuntFlagStateEnum.h"
#include "src/Protocol/Enums/Data/TreasureHuntRequestEnum.h"
#include "src/Protocol/Enums/Data/TreasureHuntTypeEnum.h"

#endif // ENUMDECLARATOR_H