#include "MessageUtils.h"

QString MessageUtils::getName(const MessageEnum &messageEnum)
{
  if(messageEnum == MessageEnum::ADMINCOMMANDMESSAGE)
      return "AdminCommandMessage";
  
  else if(messageEnum == MessageEnum::ADMINQUIETCOMMANDMESSAGE)
      return "AdminQuietCommandMessage";
  
  else if(messageEnum == MessageEnum::CONSOLECOMMANDSLISTMESSAGE)
      return "ConsoleCommandsListMessage";
  
  else if(messageEnum == MessageEnum::CONSOLEENDMESSAGE)
      return "ConsoleEndMessage";
  
  else if(messageEnum == MessageEnum::CONSOLEMESSAGE)
      return "ConsoleMessage";
  
  else if(messageEnum == MessageEnum::BASICPINGMESSAGE)
      return "BasicPingMessage";
  
  else if(messageEnum == MessageEnum::BASICPONGMESSAGE)
      return "BasicPongMessage";
  
  else if(messageEnum == MessageEnum::BASICSTATMESSAGE)
      return "BasicStatMessage";
  
  else if(messageEnum == MessageEnum::BASICSTATWITHDATAMESSAGE)
      return "BasicStatWithDataMessage";
  
  else if(messageEnum == MessageEnum::NETWORKDATACONTAINERMESSAGE)
      return "NetworkDataContainerMessage";
  
  else if(messageEnum == MessageEnum::CREDENTIALSACKNOWLEDGEMENTMESSAGE)
      return "CredentialsAcknowledgementMessage";
  
  else if(messageEnum == MessageEnum::FORCEACCOUNTERRORMESSAGE)
      return "ForceAccountErrorMessage";
  
  else if(messageEnum == MessageEnum::FORCEACCOUNTMESSAGE)
      return "ForceAccountMessage";
  
  else if(messageEnum == MessageEnum::FORCEACCOUNTSTATUSMESSAGE)
      return "ForceAccountStatusMessage";
  
  else if(messageEnum == MessageEnum::HELLOCONNECTMESSAGE)
      return "HelloConnectMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE)
      return "IdentificationFailedBannedMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE)
      return "IdentificationFailedForBadVersionMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDMESSAGE)
      return "IdentificationFailedMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONMESSAGE)
      return "IdentificationMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONSUCCESSMESSAGE)
      return "IdentificationSuccessMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE)
      return "IdentificationSuccessWithLoginTokenMessage";
  
  else if(messageEnum == MessageEnum::MIGRATEDSERVERLISTMESSAGE)
      return "MigratedServerListMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTLINKREQUIREDMESSAGE)
      return "AccountLinkRequiredMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEACCEPTEDMESSAGE)
      return "NicknameAcceptedMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMECHOICEREQUESTMESSAGE)
      return "NicknameChoiceRequestMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEREFUSEDMESSAGE)
      return "NicknameRefusedMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEREGISTRATIONMESSAGE)
      return "NicknameRegistrationMessage";
  
  else if(messageEnum == MessageEnum::RELEASEACCOUNTMESSAGE)
      return "ReleaseAccountMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESEARCHERRORMESSAGE)
      return "AcquaintanceSearchErrorMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESEARCHMESSAGE)
      return "AcquaintanceSearchMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESERVERLISTMESSAGE)
      return "AcquaintanceServerListMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE)
      return "SelectedServerDataExtendedMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERDATAMESSAGE)
      return "SelectedServerDataMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERREFUSEDMESSAGE)
      return "SelectedServerRefusedMessage";
  
  else if(messageEnum == MessageEnum::SERVERSELECTIONMESSAGE)
      return "ServerSelectionMessage";
  
  else if(messageEnum == MessageEnum::SERVERSLISTMESSAGE)
      return "ServersListMessage";
  
  else if(messageEnum == MessageEnum::SERVERSTATUSUPDATEMESSAGE)
      return "ServerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::DEBUGCLEARHIGHLIGHTCELLSMESSAGE)
      return "DebugClearHighlightCellsMessage";
  
  else if(messageEnum == MessageEnum::DEBUGHIGHLIGHTCELLSMESSAGE)
      return "DebugHighlightCellsMessage";
  
  else if(messageEnum == MessageEnum::DEBUGINCLIENTMESSAGE)
      return "DebugInClientMessage";
  
  else if(messageEnum == MessageEnum::DUMPEDENTITYSTATSMESSAGE)
      return "DumpedEntityStatsMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE)
      return "AchievementAlmostFinishedDetailedListMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTREQUESTMESSAGE)
      return "AchievementAlmostFinishedDetailedListRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILEDLISTMESSAGE)
      return "AchievementDetailedListMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE)
      return "AchievementDetailedListRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILSMESSAGE)
      return "AchievementDetailsMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILSREQUESTMESSAGE)
      return "AchievementDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTFINISHEDINFORMATIONMESSAGE)
      return "AchievementFinishedInformationMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTFINISHEDMESSAGE)
      return "AchievementFinishedMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTLISTMESSAGE)
      return "AchievementListMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDERRORMESSAGE)
      return "AchievementRewardErrorMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDREQUESTMESSAGE)
      return "AchievementRewardRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDSUCCESSMESSAGE)
      return "AchievementRewardSuccessMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTSPIONEERRANKSMESSAGE)
      return "AchievementsPioneerRanksMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTSPIONEERRANKSREQUESTMESSAGE)
      return "AchievementsPioneerRanksRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE)
      return "FriendGuildSetWarnOnAchievementCompleteMessage";
  
  else if(messageEnum == MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE)
      return "FriendGuildWarnOnAchievementCompleteStateMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONMESSAGE)
      return "AbstractGameActionMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONWITHACKMESSAGE)
      return "AbstractGameActionWithAckMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE)
      return "AbstractGameActionFightTargetedAbilityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE)
      return "GameActionFightActivateGlyphTrapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCARRYCHARACTERMESSAGE)
      return "GameActionFightCarryCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE)
      return "GameActionFightCastOnTargetRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCASTREQUESTMESSAGE)
      return "GameActionFightCastRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCHANGELOOKMESSAGE)
      return "GameActionFightChangeLookMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCLOSECOMBATMESSAGE)
      return "GameActionFightCloseCombatMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE)
      return "GameActionFightDeathMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE)
      return "GameActionFightDispellableEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLEFFECTMESSAGE)
      return "GameActionFightDispellEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLMESSAGE)
      return "GameActionFightDispellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLSPELLMESSAGE)
      return "GameActionFightDispellSpellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE)
      return "GameActionFightDodgePointLossMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDROPCHARACTERMESSAGE)
      return "GameActionFightDropCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE)
      return "GameActionFightExchangePositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTINVISIBILITYMESSAGE)
      return "GameActionFightInvisibilityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE)
      return "GameActionFightInvisibleDetectedMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTKILLMESSAGE)
      return "GameActionFightKillMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE)
      return "GameActionFightLifeAndShieldPointsLostMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE)
      return "GameActionFightLifePointsGainMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE)
      return "GameActionFightLifePointsLostMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTMARKCELLSMESSAGE)
      return "GameActionFightMarkCellsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE)
      return "GameActionFightModifyEffectsDurationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTMULTIPLESUMMONMESSAGE)
      return "GameActionFightMultipleSummonMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE)
      return "GameActionFightNoSpellCastMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE)
      return "GameActionFightPointsVariationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE)
      return "GameActionFightReduceDamagesMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE)
      return "GameActionFightReflectDamagesMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREFLECTSPELLMESSAGE)
      return "GameActionFightReflectSpellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE)
      return "GameActionFightSlideMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLCASTMESSAGE)
      return "GameActionFightSpellCastMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE)
      return "GameActionFightSpellCooldownVariationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE)
      return "GameActionFightSpellImmunityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSTEALKAMAMESSAGE)
      return "GameActionFightStealKamaMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE)
      return "GameActionFightSummonMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTACKLEDMESSAGE)
      return "GameActionFightTackledMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE)
      return "GameActionFightTeleportOnSameMapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTHROWCHARACTERMESSAGE)
      return "GameActionFightThrowCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE)
      return "GameActionFightTriggerEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE)
      return "GameActionFightTriggerGlyphTrapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTUNMARKCELLSMESSAGE)
      return "GameActionFightUnmarkCellsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTVANISHMESSAGE)
      return "GameActionFightVanishMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONUPDATEEFFECTTRIGGERCOUNTMESSAGE)
      return "GameActionUpdateEffectTriggerCountMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONACKNOWLEDGEMENTMESSAGE)
      return "GameActionAcknowledgementMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONNOOPMESSAGE)
      return "GameActionNoopMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONSPAMMESSAGE)
      return "GameActionSpamMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCEENDMESSAGE)
      return "SequenceEndMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCESTARTMESSAGE)
      return "SequenceStartMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEALLRANKSUPDATEREQUESTMESSAGE)
      return "AllianceAllRanksUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINMESSAGE)
      return "AllianceBulletinMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINSETERRORMESSAGE)
      return "AllianceBulletinSetErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINSETREQUESTMESSAGE)
      return "AllianceBulletinSetRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECHANGEMEMBERRANKMESSAGE)
      return "AllianceChangeMemberRankMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONRESULTMESSAGE)
      return "AllianceCreationResultMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONSTARTEDMESSAGE)
      return "AllianceCreationStartedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONVALIDMESSAGE)
      return "AllianceCreationValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSERRORMESSAGE)
      return "AllianceFactsErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSMESSAGE)
      return "AllianceFactsMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSREQUESTMESSAGE)
      return "AllianceFactsRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINSIDERINFOMESSAGE)
      return "AllianceInsiderInfoMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINSIDERINFOREQUESTMESSAGE)
      return "AllianceInsiderInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONANSWERMESSAGE)
      return "AllianceInvitationAnswerMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONMESSAGE)
      return "AllianceInvitationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONSTATERECRUTEDMESSAGE)
      return "AllianceInvitationStateRecrutedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONSTATERECRUTERMESSAGE)
      return "AllianceInvitationStateRecruterMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITEDMESSAGE)
      return "AllianceInvitedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEJOINAUTOMATICALLYREQUESTMESSAGE)
      return "AllianceJoinAutomaticallyRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEJOINEDMESSAGE)
      return "AllianceJoinedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEKICKREQUESTMESSAGE)
      return "AllianceKickRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELEFTMESSAGE)
      return "AllianceLeftMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELISTMESSAGE)
      return "AllianceListMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERINFORMATIONUPDATEMESSAGE)
      return "AllianceMemberInformationUpdateMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERLEAVINGMESSAGE)
      return "AllianceMemberLeavingMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERONLINESTATUSMESSAGE)
      return "AllianceMemberOnlineStatusMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERSHIPMESSAGE)
      return "AllianceMembershipMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE)
      return "AllianceMemberStartWarningOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERSTOPWARNINGONCONNECTIONMESSAGE)
      return "AllianceMemberStopWarningOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE)
      return "AllianceModificationEmblemValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE)
      return "AllianceModificationNameAndTagValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONRESULTMESSAGE)
      return "AllianceModificationResultMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONSTARTEDMESSAGE)
      return "AllianceModificationStartedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONVALIDMESSAGE)
      return "AllianceModificationValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDMESSAGE)
      return "AllianceMotdMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDSETERRORMESSAGE)
      return "AllianceMotdSetErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDSETREQUESTMESSAGE)
      return "AllianceMotdSetRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPARTIALLISTMESSAGE)
      return "AlliancePartialListMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERANKCREATEREQUESTMESSAGE)
      return "AllianceRankCreateRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERANKREMOVEREQUESTMESSAGE)
      return "AllianceRankRemoveRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERANKSMESSAGE)
      return "AllianceRanksMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERANKSREQUESTMESSAGE)
      return "AllianceRanksRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERANKUPDATEREQUESTMESSAGE)
      return "AllianceRankUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERIGHTSUPDATEMESSAGE)
      return "AllianceRightsUpdateMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONANSWERMESSAGE)
      return "AllianceApplicationAnswerMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONDELETEDMESSAGE)
      return "AllianceApplicationDeletedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONISANSWEREDMESSAGE)
      return "AllianceApplicationIsAnsweredMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONLISTENMESSAGE)
      return "AllianceApplicationListenMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONPRESENCEMESSAGE)
      return "AllianceApplicationPresenceMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEAPPLICATIONRECEIVEDMESSAGE)
      return "AllianceApplicationReceivedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEDELETEAPPLICATIONREQUESTMESSAGE)
      return "AllianceDeleteApplicationRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEGETPLAYERAPPLICATIONMESSAGE)
      return "AllianceGetPlayerApplicationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEISTHEREANYAPPLICATIONMESSAGE)
      return "AllianceIsThereAnyApplicationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELISTAPPLICATIONANSWERMESSAGE)
      return "AllianceListApplicationAnswerMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELISTAPPLICATIONMODIFIEDMESSAGE)
      return "AllianceListApplicationModifiedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELISTAPPLICATIONREQUESTMESSAGE)
      return "AllianceListApplicationRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPLAYERAPPLICATIONABSTRACTMESSAGE)
      return "AlliancePlayerApplicationAbstractMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPLAYERAPPLICATIONINFORMATIONMESSAGE)
      return "AlliancePlayerApplicationInformationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPLAYERNOAPPLICATIONINFORMATIONMESSAGE)
      return "AlliancePlayerNoApplicationInformationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCESUBMITAPPLICATIONMESSAGE)
      return "AllianceSubmitApplicationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEUPDATEAPPLICATIONMESSAGE)
      return "AllianceUpdateApplicationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTFIGHTERADDEDMESSAGE)
      return "AllianceFightFighterAddedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTFIGHTERREMOVEDMESSAGE)
      return "AllianceFightFighterRemovedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTFINISHEDMESSAGE)
      return "AllianceFightFinishedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTINFOMESSAGE)
      return "AllianceFightInfoMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTPHASEUPDATEMESSAGE)
      return "AllianceFightPhaseUpdateMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFIGHTSTARTEDMESSAGE)
      return "AllianceFightStartedMessage";
  
  else if(messageEnum == MessageEnum::STARTLISTENALLIANCEFIGHTMESSAGE)
      return "StartListenAllianceFightMessage";
  
  else if(messageEnum == MessageEnum::STOPLISTENALLIANCEFIGHTMESSAGE)
      return "StopListenAllianceFightMessage";
  
  else if(messageEnum == MessageEnum::KOHUPDATEMESSAGE)
      return "KohUpdateMessage";
  
  else if(messageEnum == MessageEnum::KOTHENDMESSAGE)
      return "KothEndMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEGETRECRUITMENTINFORMATIONMESSAGE)
      return "AllianceGetRecruitmentInformationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERECRUITMENTINFORMATIONMESSAGE)
      return "AllianceRecruitmentInformationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCERECRUITMENTINVALIDATEMESSAGE)
      return "AllianceRecruitmentInvalidateMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEUPDATERECRUITMENTINFORMATIONMESSAGE)
      return "AllianceUpdateRecruitmentInformationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCESUMMARYMESSAGE)
      return "AllianceSummaryMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCESUMMARYREQUESTMESSAGE)
      return "AllianceSummaryRequestMessage";
  
  else if(messageEnum == MessageEnum::ALMANACHCALENDARDATEMESSAGE)
      return "AlmanachCalendarDateMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTCAPABILITIESMESSAGE)
      return "AccountCapabilitiesMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE)
      return "AccountLoggingKickedMessage";
  
  else if(messageEnum == MessageEnum::ALREADYCONNECTEDMESSAGE)
      return "AlreadyConnectedMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETACCEPTEDMESSAGE)
      return "AuthenticationTicketAcceptedMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETMESSAGE)
      return "AuthenticationTicketMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETREFUSEDMESSAGE)
      return "AuthenticationTicketRefusedMessage";
  
  else if(messageEnum == MessageEnum::HELLOGAMEMESSAGE)
      return "HelloGameMessage";
  
  else if(messageEnum == MessageEnum::RELOGINTOKENREQUESTMESSAGE)
      return "ReloginTokenRequestMessage";
  
  else if(messageEnum == MessageEnum::RELOGINTOKENSTATUSMESSAGE)
      return "ReloginTokenStatusMessage";
  
  else if(messageEnum == MessageEnum::SERVEROPTIONALFEATURESMESSAGE)
      return "ServerOptionalFeaturesMessage";
  
  else if(messageEnum == MessageEnum::SERVERSESSIONCONSTANTSMESSAGE)
      return "ServerSessionConstantsMessage";
  
  else if(messageEnum == MessageEnum::SERVERSETTINGSMESSAGE)
      return "ServerSettingsMessage";
  
  else if(messageEnum == MessageEnum::ATLASPOINTINFORMATIONSMESSAGE)
      return "AtlasPointInformationsMessage";
  
  else if(messageEnum == MessageEnum::COMPASSRESETMESSAGE)
      return "CompassResetMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEMESSAGE)
      return "CompassUpdateMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE)
      return "CompassUpdatePartyMemberMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEPVPSEEKMESSAGE)
      return "CompassUpdatePvpSeekMessage";
  
  else if(messageEnum == MessageEnum::BASICACKMESSAGE)
      return "BasicAckMessage";
  
  else if(messageEnum == MessageEnum::BASICDATEMESSAGE)
      return "BasicDateMessage";
  
  else if(messageEnum == MessageEnum::BASICLATENCYSTATSMESSAGE)
      return "BasicLatencyStatsMessage";
  
  else if(messageEnum == MessageEnum::BASICLATENCYSTATSREQUESTMESSAGE)
      return "BasicLatencyStatsRequestMessage";
  
  else if(messageEnum == MessageEnum::BASICNOOPERATIONMESSAGE)
      return "BasicNoOperationMessage";
  
  else if(messageEnum == MessageEnum::BASICTIMEMESSAGE)
      return "BasicTimeMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOAMIREQUESTMESSAGE)
      return "BasicWhoAmIRequestMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISMESSAGE)
      return "BasicWhoIsMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISNOMATCHMESSAGE)
      return "BasicWhoIsNoMatchMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISREQUESTMESSAGE)
      return "BasicWhoIsRequestMessage";
  
  else if(messageEnum == MessageEnum::CURRENTSERVERSTATUSUPDATEMESSAGE)
      return "CurrentServerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::NUMERICWHOISMESSAGE)
      return "NumericWhoIsMessage";
  
  else if(messageEnum == MessageEnum::NUMERICWHOISREQUESTMESSAGE)
      return "NumericWhoIsRequestMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCENUMBERMESSAGE)
      return "SequenceNumberMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCENUMBERREQUESTMESSAGE)
      return "SequenceNumberRequestMessage";
  
  else if(messageEnum == MessageEnum::TEXTINFORMATIONMESSAGE)
      return "TextInformationMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTWAREFFORTDONATEPREVIEWMESSAGE)
      return "AlignmentWarEffortDonatePreviewMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTWAREFFORTDONATEREQUESTMESSAGE)
      return "AlignmentWarEffortDonateRequestMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTWAREFFORTDONATIONRESULTMESSAGE)
      return "AlignmentWarEffortDonationResultMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERALIGNMENTWAREFFORTPROGRESSIONMESSAGE)
      return "CharacterAlignmentWarEffortProgressionMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE)
      return "CharacterAlignmentWarEffortProgressionRequestMessage";
  
  else if(messageEnum == MessageEnum::ALTERATIONADDEDMESSAGE)
      return "AlterationAddedMessage";
  
  else if(messageEnum == MessageEnum::ALTERATIONREMOVEDMESSAGE)
      return "AlterationRemovedMessage";
  
  else if(messageEnum == MessageEnum::ALTERATIONSMESSAGE)
      return "AlterationsMessage";
  
  else if(messageEnum == MessageEnum::ALTERATIONSUPDATEDMESSAGE)
      return "AlterationsUpdatedMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERFIRSTSELECTIONMESSAGE)
      return "CharacterFirstSelectionMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERREPLAYWITHREMODELREQUESTMESSAGE)
      return "CharacterReplayWithRemodelRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDERRORMESSAGE)
      return "CharacterSelectedErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDFORCEMESSAGE)
      return "CharacterSelectedForceMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDFORCEREADYMESSAGE)
      return "CharacterSelectedForceReadyMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE)
      return "CharacterSelectedSuccessMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTIONMESSAGE)
      return "CharacterSelectionMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTIONWITHREMODELMESSAGE)
      return "CharacterSelectionWithRemodelMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTERRORMESSAGE)
      return "CharactersListErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTMESSAGE)
      return "CharactersListMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTREQUESTMESSAGE)
      return "CharactersListRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTWITHREMODELINGMESSAGE)
      return "CharactersListWithRemodelingMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCANBECREATEDREQUESTMESSAGE)
      return "CharacterCanBeCreatedRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCANBECREATEDRESULTMESSAGE)
      return "CharacterCanBeCreatedResultMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCREATIONREQUESTMESSAGE)
      return "CharacterCreationRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCREATIONRESULTMESSAGE)
      return "CharacterCreationResultMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONFAILUREMESSAGE)
      return "CharacterNameSuggestionFailureMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONREQUESTMESSAGE)
      return "CharacterNameSuggestionRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE)
      return "CharacterNameSuggestionSuccessMessage";
  
  else if(messageEnum == MessageEnum::DEBTSDELETEMESSAGE)
      return "DebtsDeleteMessage";
  
  else if(messageEnum == MessageEnum::DEBTSUPDATEMESSAGE)
      return "DebtsUpdateMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONERRORMESSAGE)
      return "CharacterDeletionErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONPREPAREMESSAGE)
      return "CharacterDeletionPrepareMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONPREPAREREQUESTMESSAGE)
      return "CharacterDeletionPrepareRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONREQUESTMESSAGE)
      return "CharacterDeletionRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERREPLAYREQUESTMESSAGE)
      return "CharacterReplayRequestMessage";
  
  else if(messageEnum == MessageEnum::FORGETTABLESPELLCLIENTACTIONMESSAGE)
      return "ForgettableSpellClientActionMessage";
  
  else if(messageEnum == MessageEnum::FORGETTABLESPELLDELETEMESSAGE)
      return "ForgettableSpellDeleteMessage";
  
  else if(messageEnum == MessageEnum::FORGETTABLESPELLEQUIPMENTSLOTSMESSAGE)
      return "ForgettableSpellEquipmentSlotsMessage";
  
  else if(messageEnum == MessageEnum::FORGETTABLESPELLLISTUPDATEMESSAGE)
      return "ForgettableSpellListUpdateMessage";
  
  else if(messageEnum == MessageEnum::APPLYSPELLMODIFIERMESSAGE)
      return "ApplySpellModifierMessage";
  
  else if(messageEnum == MessageEnum::REMOVESPELLMODIFIERMESSAGE)
      return "RemoveSpellModifierMessage";
  
  else if(messageEnum == MessageEnum::CHARACTEREXPERIENCEGAINMESSAGE)
      return "CharacterExperienceGainMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE)
      return "CharacterLevelUpInformationMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLEVELUPMESSAGE)
      return "CharacterLevelUpMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSTATSLISTMESSAGE)
      return "CharacterStatsListMessage";
  
  else if(messageEnum == MessageEnum::FIGHTERSTATSLISTMESSAGE)
      return "FighterStatsListMessage";
  
  else if(messageEnum == MessageEnum::LIFEPOINTSREGENBEGINMESSAGE)
      return "LifePointsRegenBeginMessage";
  
  else if(messageEnum == MessageEnum::LIFEPOINTSREGENENDMESSAGE)
      return "LifePointsRegenEndMessage";
  
  else if(messageEnum == MessageEnum::RESETCHARACTERSTATSREQUESTMESSAGE)
      return "ResetCharacterStatsRequestMessage";
  
  else if(messageEnum == MessageEnum::UPDATELIFEPOINTSMESSAGE)
      return "UpdateLifePointsMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEERRORMESSAGE)
      return "PlayerStatusUpdateErrorMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEMESSAGE)
      return "PlayerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEREQUESTMESSAGE)
      return "PlayerStatusUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::CHANNELENABLINGCHANGEMESSAGE)
      return "ChannelEnablingChangeMessage";
  
  else if(messageEnum == MessageEnum::CHANNELENABLINGMESSAGE)
      return "ChannelEnablingMessage";
  
  else if(messageEnum == MessageEnum::ENABLEDCHANNELSMESSAGE)
      return "EnabledChannelsMessage";
  
  else if(messageEnum == MessageEnum::CHATABSTRACTCLIENTMESSAGE)
      return "ChatAbstractClientMessage";
  
  else if(messageEnum == MessageEnum::CHATABSTRACTSERVERMESSAGE)
      return "ChatAbstractServerMessage";
  
  else if(messageEnum == MessageEnum::CHATADMINSERVERMESSAGE)
      return "ChatAdminServerMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTMULTIMESSAGE)
      return "ChatClientMultiMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTMULTIWITHOBJECTMESSAGE)
      return "ChatClientMultiWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTPRIVATEMESSAGE)
      return "ChatClientPrivateMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTPRIVATEWITHOBJECTMESSAGE)
      return "ChatClientPrivateWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATERRORMESSAGE)
      return "ChatErrorMessage";
  
  else if(messageEnum == MessageEnum::CHATKOLIZEUMSERVERMESSAGE)
      return "ChatKolizeumServerMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERCOPYMESSAGE)
      return "ChatServerCopyMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERCOPYWITHOBJECTMESSAGE)
      return "ChatServerCopyWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERMESSAGE)
      return "ChatServerMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERWITHOBJECTMESSAGE)
      return "ChatServerWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATCOMMUNITYCHANNELCOMMUNITYMESSAGE)
      return "ChatCommunityChannelCommunityMessage";
  
  else if(messageEnum == MessageEnum::CHATCOMMUNITYCHANNELSETCOMMUNITYREQUESTMESSAGE)
      return "ChatCommunityChannelSetCommunityRequestMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYEXTRAPACKLISTMESSAGE)
      return "ChatSmileyExtraPackListMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYMESSAGE)
      return "ChatSmileyMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYREQUESTMESSAGE)
      return "ChatSmileyRequestMessage";
  
  else if(messageEnum == MessageEnum::LOCALIZEDCHATSMILEYMESSAGE)
      return "LocalizedChatSmileyMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYREQUESTMESSAGE)
      return "MoodSmileyRequestMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYRESULTMESSAGE)
      return "MoodSmileyResultMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYUPDATEMESSAGE)
      return "MoodSmileyUpdateMessage";
  
  else if(messageEnum == MessageEnum::ADDTAXCOLLECTORORDEREDSPELLMESSAGE)
      return "AddTaxCollectorOrderedSpellMessage";
  
  else if(messageEnum == MessageEnum::ADDTAXCOLLECTORPRESETSPELLMESSAGE)
      return "AddTaxCollectorPresetSpellMessage";
  
  else if(messageEnum == MessageEnum::CONFIRMATIONOFLISTENINGTAXCOLLECTORUPDATESMESSAGE)
      return "ConfirmationOfListeningTaxCollectorUpdatesMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE)
      return "GameRolePlayTaxCollectorFightRequestMessage";
  
  else if(messageEnum == MessageEnum::MOVETAXCOLLECTORORDEREDSPELLMESSAGE)
      return "MoveTaxCollectorOrderedSpellMessage";
  
  else if(messageEnum == MessageEnum::MOVETAXCOLLECTORPRESETSPELLMESSAGE)
      return "MoveTaxCollectorPresetSpellMessage";
  
  else if(messageEnum == MessageEnum::REMOVETAXCOLLECTORORDEREDSPELLMESSAGE)
      return "RemoveTaxCollectorOrderedSpellMessage";
  
  else if(messageEnum == MessageEnum::REMOVETAXCOLLECTORPRESETSPELLMESSAGE)
      return "RemoveTaxCollectorPresetSpellMessage";
  
  else if(messageEnum == MessageEnum::STARTLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE)
      return "StartListenTaxCollectorPresetsUpdatesMessage";
  
  else if(messageEnum == MessageEnum::STARTLISTENTAXCOLLECTORUPDATESMESSAGE)
      return "StartListenTaxCollectorUpdatesMessage";
  
  else if(messageEnum == MessageEnum::STOPLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE)
      return "StopListenTaxCollectorPresetsUpdatesMessage";
  
  else if(messageEnum == MessageEnum::STOPLISTENTAXCOLLECTORUPDATESMESSAGE)
      return "StopListenTaxCollectorUpdatesMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORADDEDMESSAGE)
      return "TaxCollectorAddedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORATTACKEDMESSAGE)
      return "TaxCollectorAttackedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORATTACKEDRESULTMESSAGE)
      return "TaxCollectorAttackedResultMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORERRORMESSAGE)
      return "TaxCollectorErrorMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORHARVESTEDMESSAGE)
      return "TaxCollectorHarvestedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE)
      return "TaxCollectorMovementsOfflineMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORORDEREDSPELLUPDATEDMESSAGE)
      return "TaxCollectorOrderedSpellUpdatedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORPRESETSMESSAGE)
      return "TaxCollectorPresetsMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORPRESETSPELLUPDATEDMESSAGE)
      return "TaxCollectorPresetSpellUpdatedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORREMOVEDMESSAGE)
      return "TaxCollectorRemovedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORSTATEUPDATEMESSAGE)
      return "TaxCollectorStateUpdateMessage";
  
  else if(messageEnum == MessageEnum::TOPTAXCOLLECTORLISTMESSAGE)
      return "TopTaxCollectorListMessage";
  
  else if(messageEnum == MessageEnum::DISPLAYNUMERICALVALUEPADDOCKMESSAGE)
      return "DisplayNumericalValuePaddockMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONKEYRINGMESSAGE)
      return "DungeonKeyRingMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONKEYRINGUPDATEMESSAGE)
      return "DungeonKeyRingUpdateMessage";
  
  else if(messageEnum == MessageEnum::ARENAFIGHTERIDLEMESSAGE)
      return "ArenaFighterIdleMessage";
  
  else if(messageEnum == MessageEnum::ARENAFIGHTERLEAVEMESSAGE)
      return "ArenaFighterLeaveMessage";
  
  else if(messageEnum == MessageEnum::BREACHGAMEFIGHTENDMESSAGE)
      return "BreachGameFightEndMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEADDMESSAGE)
      return "ChallengeAddMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEBONUSCHOICEMESSAGE)
      return "ChallengeBonusChoiceMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEBONUSCHOICESELECTEDMESSAGE)
      return "ChallengeBonusChoiceSelectedMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGELISTMESSAGE)
      return "ChallengeListMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEMODSELECTEDMESSAGE)
      return "ChallengeModSelectedMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEMODSELECTMESSAGE)
      return "ChallengeModSelectMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGENUMBERMESSAGE)
      return "ChallengeNumberMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEPROPOSALMESSAGE)
      return "ChallengeProposalMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEREADYMESSAGE)
      return "ChallengeReadyMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGERESULTMESSAGE)
      return "ChallengeResultMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGESELECTEDMESSAGE)
      return "ChallengeSelectedMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGESELECTIONMESSAGE)
      return "ChallengeSelectionMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGETARGETSMESSAGE)
      return "ChallengeTargetsMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGETARGETSREQUESTMESSAGE)
      return "ChallengeTargetsRequestMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEVALIDATEMESSAGE)
      return "ChallengeValidateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREFRESHFIGHTERMESSAGE)
      return "GameFightRefreshFighterMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE)
      return "GameFightShowFighterMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE)
      return "GameFightShowFighterRandomStaticPoseMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTENDMESSAGE)
      return "GameFightEndMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE)
      return "GameFightHumanReadyStateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTJOINMESSAGE)
      return "GameFightJoinMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTJOINREQUESTMESSAGE)
      return "GameFightJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTLEAVEMESSAGE)
      return "GameFightLeaveMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTNEWROUNDMESSAGE)
      return "GameFightNewRoundMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTNEWWAVEMESSAGE)
      return "GameFightNewWaveMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTOPTIONSTATEUPDATEMESSAGE)
      return "GameFightOptionStateUpdateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTOPTIONTOGGLEMESSAGE)
      return "GameFightOptionToggleMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPAUSEMESSAGE)
      return "GameFightPauseMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE)
      return "GameFightPlacementPositionRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE)
      return "GameFightPlacementPossiblePositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE)
      return "GameFightPlacementSwapPositionsAcceptMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE)
      return "GameFightPlacementSwapPositionsCancelledMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE)
      return "GameFightPlacementSwapPositionsCancelMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE)
      return "GameFightPlacementSwapPositionsErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE)
      return "GameFightPlacementSwapPositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE)
      return "GameFightPlacementSwapPositionsOfferMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE)
      return "GameFightPlacementSwapPositionsRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREADYMESSAGE)
      return "GameFightReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREMOVETEAMMEMBERMESSAGE)
      return "GameFightRemoveTeamMemberMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTRESUMEMESSAGE)
      return "GameFightResumeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTRESUMEWITHSLAVESMESSAGE)
      return "GameFightResumeWithSlavesMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATEMESSAGE)
      return "GameFightSpectateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE)
      return "GameFightSpectatePlayerRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATORJOINMESSAGE)
      return "GameFightSpectatorJoinMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSTARTINGMESSAGE)
      return "GameFightStartingMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSTARTMESSAGE)
      return "GameFightStartMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE)
      return "GameFightSynchronizeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNENDMESSAGE)
      return "GameFightTurnEndMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNFINISHMESSAGE)
      return "GameFightTurnFinishMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNLISTMESSAGE)
      return "GameFightTurnListMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNREADYMESSAGE)
      return "GameFightTurnReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNREADYREQUESTMESSAGE)
      return "GameFightTurnReadyRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNRESUMEMESSAGE)
      return "GameFightTurnResumeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNSTARTMESSAGE)
      return "GameFightTurnStartMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNSTARTPLAYINGMESSAGE)
      return "GameFightTurnStartPlayingMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTUPDATETEAMMESSAGE)
      return "GameFightUpdateTeamMessage";
  
  else if(messageEnum == MessageEnum::REFRESHCHARACTERSTATSMESSAGE)
      return "RefreshCharacterStatsMessage";
  
  else if(messageEnum == MessageEnum::SLAVENOLONGERCONTROLEDMESSAGE)
      return "SlaveNoLongerControledMessage";
  
  else if(messageEnum == MessageEnum::SLAVESWITCHCONTEXTMESSAGE)
      return "SlaveSwitchContextMessage";
  
  else if(messageEnum == MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE)
      return "GameCautiousMapMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE)
      return "GameCautiousMapMovementRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEERRORMESSAGE)
      return "GameContextCreateErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEMESSAGE)
      return "GameContextCreateMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEREQUESTMESSAGE)
      return "GameContextCreateRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTDESTROYMESSAGE)
      return "GameContextDestroyMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTKICKMESSAGE)
      return "GameContextKickMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTMOVEELEMENTMESSAGE)
      return "GameContextMoveElementMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE)
      return "GameContextMoveMultipleElementsMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTQUITMESSAGE)
      return "GameContextQuitMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREADYMESSAGE)
      return "GameContextReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE)
      return "GameContextRefreshEntityLookMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE)
      return "GameContextRemoveElementMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE)
      return "GameContextRemoveElementWithEventMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE)
      return "GameContextRemoveMultipleElementsMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE)
      return "GameContextRemoveMultipleElementsWithEventsMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE)
      return "GameEntitiesDispositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITYDISPOSITIONERRORMESSAGE)
      return "GameEntityDispositionErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITYDISPOSITIONMESSAGE)
      return "GameEntityDispositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONMESSAGE)
      return "GameMapChangeOrientationMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE)
      return "GameMapChangeOrientationRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONSMESSAGE)
      return "GameMapChangeOrientationsMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTCANCELMESSAGE)
      return "GameMapMovementCancelMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTCONFIRMMESSAGE)
      return "GameMapMovementConfirmMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTMESSAGE)
      return "GameMapMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTREQUESTMESSAGE)
      return "GameMapMovementRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPNOMOVEMENTMESSAGE)
      return "GameMapNoMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMEREFRESHMONSTERBOOSTSMESSAGE)
      return "GameRefreshMonsterBoostsMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTADDMESSAGE)
      return "GameDataPaddockObjectAddMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTLISTADDMESSAGE)
      return "GameDataPaddockObjectListAddMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTREMOVEMESSAGE)
      return "GameDataPaddockObjectRemoveMessage";
  
  else if(messageEnum == MessageEnum::MOUNTDATAERRORMESSAGE)
      return "MountDataErrorMessage";
  
  else if(messageEnum == MessageEnum::MOUNTDATAMESSAGE)
      return "MountDataMessage";
  
  else if(messageEnum == MessageEnum::MOUNTEMOTEICONUSEDOKMESSAGE)
      return "MountEmoteIconUsedOkMessage";
  
  else if(messageEnum == MessageEnum::MOUNTEQUIPEDERRORMESSAGE)
      return "MountEquipedErrorMessage";
  
  else if(messageEnum == MessageEnum::MOUNTFEEDREQUESTMESSAGE)
      return "MountFeedRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE)
      return "MountHarnessColorsUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTHARNESSDISSOCIATEREQUESTMESSAGE)
      return "MountHarnessDissociateRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE)
      return "MountInformationInPaddockRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTINFORMATIONREQUESTMESSAGE)
      return "MountInformationRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRELEASEDMESSAGE)
      return "MountReleasedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRELEASEREQUESTMESSAGE)
      return "MountReleaseRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRENAMEDMESSAGE)
      return "MountRenamedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRENAMEREQUESTMESSAGE)
      return "MountRenameRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRIDINGMESSAGE)
      return "MountRidingMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSETMESSAGE)
      return "MountSetMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSETXPRATIOREQUESTMESSAGE)
      return "MountSetXpRatioRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSTERILIZEDMESSAGE)
      return "MountSterilizedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSTERILIZEREQUESTMESSAGE)
      return "MountSterilizeRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTTOGGLERIDINGREQUESTMESSAGE)
      return "MountToggleRidingRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTUNSETMESSAGE)
      return "MountUnSetMessage";
  
  else if(messageEnum == MessageEnum::MOUNTXPRATIOMESSAGE)
      return "MountXpRatioMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKBUYREQUESTMESSAGE)
      return "PaddockBuyRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKBUYRESULTMESSAGE)
      return "PaddockBuyResultMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKMOVEITEMREQUESTMESSAGE)
      return "PaddockMoveItemRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKREMOVEITEMREQUESTMESSAGE)
      return "PaddockRemoveItemRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKSELLREQUESTMESSAGE)
      return "PaddockSellRequestMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONBYSERVERMESSAGE)
      return "NotificationByServerMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONLISTMESSAGE)
      return "NotificationListMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONRESETMESSAGE)
      return "NotificationResetMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONUPDATEFLAGMESSAGE)
      return "NotificationUpdateFlagMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTWAREFFORTPROGRESSIONMESSAGE)
      return "AlignmentWarEffortProgressionMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTWAREFFORTPROGRESSIONREQUESTMESSAGE)
      return "AlignmentWarEffortProgressionRequestMessage";
  
  else if(messageEnum == MessageEnum::ANOMALYOPENEDMESSAGE)
      return "AnomalyOpenedMessage";
  
  else if(messageEnum == MessageEnum::ANOMALYSTATEMESSAGE)
      return "AnomalyStateMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE)
      return "MapComplementaryInformationsAnomalyMessage";
  
  else if(messageEnum == MessageEnum::ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE)
      return "AnomalySubareaInformationRequestMessage";
  
  else if(messageEnum == MessageEnum::ANOMALYSUBAREAINFORMATIONRESPONSEMESSAGE)
      return "AnomalySubareaInformationResponseMessage";
  
  else if(messageEnum == MessageEnum::BREACHBRANCHESMESSAGE)
      return "BreachBranchesMessage";
  
  else if(messageEnum == MessageEnum::BREACHBONUSMESSAGE)
      return "BreachBonusMessage";
  
  else if(messageEnum == MessageEnum::BREACHBUDGETMESSAGE)
      return "BreachBudgetMessage";
  
  else if(messageEnum == MessageEnum::BREACHCHARACTERSMESSAGE)
      return "BreachCharactersMessage";
  
  else if(messageEnum == MessageEnum::BREACHENTERMESSAGE)
      return "BreachEnterMessage";
  
  else if(messageEnum == MessageEnum::BREACHEXITREQUESTMESSAGE)
      return "BreachExitRequestMessage";
  
  else if(messageEnum == MessageEnum::BREACHEXITRESPONSEMESSAGE)
      return "BreachExitResponseMessage";
  
  else if(messageEnum == MessageEnum::BREACHROOMLOCKEDMESSAGE)
      return "BreachRoomLockedMessage";
  
  else if(messageEnum == MessageEnum::BREACHROOMUNLOCKREQUESTMESSAGE)
      return "BreachRoomUnlockRequestMessage";
  
  else if(messageEnum == MessageEnum::BREACHROOMUNLOCKRESULTMESSAGE)
      return "BreachRoomUnlockResultMessage";
  
  else if(messageEnum == MessageEnum::BREACHSAVEDMESSAGE)
      return "BreachSavedMessage";
  
  else if(messageEnum == MessageEnum::BREACHSTATEMESSAGE)
      return "BreachStateMessage";
  
  else if(messageEnum == MessageEnum::BREACHTELEPORTREQUESTMESSAGE)
      return "BreachTeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::BREACHTELEPORTRESPONSEMESSAGE)
      return "BreachTeleportResponseMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSBREACHMESSAGE)
      return "MapComplementaryInformationsBreachMessage";
  
  else if(messageEnum == MessageEnum::BREACHINVITATIONANSWERMESSAGE)
      return "BreachInvitationAnswerMessage";
  
  else if(messageEnum == MessageEnum::BREACHINVITATIONCLOSEMESSAGE)
      return "BreachInvitationCloseMessage";
  
  else if(messageEnum == MessageEnum::BREACHINVITATIONOFFERMESSAGE)
      return "BreachInvitationOfferMessage";
  
  else if(messageEnum == MessageEnum::BREACHINVITATIONREQUESTMESSAGE)
      return "BreachInvitationRequestMessage";
  
  else if(messageEnum == MessageEnum::BREACHINVITATIONRESPONSEMESSAGE)
      return "BreachInvitationResponseMessage";
  
  else if(messageEnum == MessageEnum::BREACHKICKREQUESTMESSAGE)
      return "BreachKickRequestMessage";
  
  else if(messageEnum == MessageEnum::BREACHKICKRESPONSEMESSAGE)
      return "BreachKickResponseMessage";
  
  else if(messageEnum == MessageEnum::BREACHREWARDBOUGHTMESSAGE)
      return "BreachRewardBoughtMessage";
  
  else if(messageEnum == MessageEnum::BREACHREWARDBUYMESSAGE)
      return "BreachRewardBuyMessage";
  
  else if(messageEnum == MessageEnum::BREACHREWARDSMESSAGE)
      return "BreachRewardsMessage";
  
  else if(messageEnum == MessageEnum::CHANGEMAPMESSAGE)
      return "ChangeMapMessage";
  
  else if(messageEnum == MessageEnum::CURRENTMAPINSTANCEMESSAGE)
      return "CurrentMapInstanceMessage";
  
  else if(messageEnum == MessageEnum::CURRENTMAPMESSAGE)
      return "CurrentMapMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYFREESOULREQUESTMESSAGE)
      return "GameRolePlayFreeSoulRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYGAMEOVERMESSAGE)
      return "GameRolePlayGameOverMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE)
      return "GameRolePlayPlayerLifeStatusMessage";
  
  else if(messageEnum == MessageEnum::WARNONPERMADEATHMESSAGE)
      return "WarnOnPermaDeathMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE)
      return "GameRolePlayDelayedActionFinishedMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDACTIONMESSAGE)
      return "GameRolePlayDelayedActionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE)
      return "GameRolePlayDelayedObjectUseMessage";
  
  else if(messageEnum == MessageEnum::DICEROLLREQUESTMESSAGE)
      return "DiceRollRequestMessage";
  
  else if(messageEnum == MessageEnum::DOCUMENTREADINGBEGINMESSAGE)
      return "DocumentReadingBeginMessage";
  
  else if(messageEnum == MessageEnum::OPENGUIDEBOOKMESSAGE)
      return "OpenGuideBookMessage";
  
  else if(messageEnum == MessageEnum::EMOTEADDMESSAGE)
      return "EmoteAddMessage";
  
  else if(messageEnum == MessageEnum::EMOTELISTMESSAGE)
      return "EmoteListMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYABSTRACTMESSAGE)
      return "EmotePlayAbstractMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYERRORMESSAGE)
      return "EmotePlayErrorMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYMASSIVEMESSAGE)
      return "EmotePlayMassiveMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYMESSAGE)
      return "EmotePlayMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYREQUESTMESSAGE)
      return "EmotePlayRequestMessage";
  
  else if(messageEnum == MessageEnum::EMOTEREMOVEMESSAGE)
      return "EmoteRemoveMessage";
  
  else if(messageEnum == MessageEnum::ERRORMAPNOTFOUNDMESSAGE)
      return "ErrorMapNotFoundMessage";
  
  else if(messageEnum == MessageEnum::ARENAFIGHTANSWERACKNOWLEDGEMENTMESSAGE)
      return "ArenaFightAnswerAcknowledgementMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTANSWERMESSAGE)
      return "GameRolePlayArenaFightAnswerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE)
      return "GameRolePlayArenaFighterStatusMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE)
      return "GameRolePlayArenaFightPropositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAINVITATIONCANDIDATESANSWERMESSAGE)
      return "GameRolePlayArenaInvitationCandidatesAnswerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENALEAGUEREWARDSMESSAGE)
      return "GameRolePlayArenaLeagueRewardsMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAPLAYERBEHAVIOURSMESSAGE)
      return "GameRolePlayArenaPlayerBehavioursMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAREGISTERMESSAGE)
      return "GameRolePlayArenaRegisterMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE)
      return "GameRolePlayArenaRegistrationStatusMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAREGISTRATIONWARNINGMESSAGE)
      return "GameRolePlayArenaRegistrationWarningMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE)
      return "GameRolePlayArenaSwitchToFightServerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE)
      return "GameRolePlayArenaSwitchToGameServerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAUNREGISTERMESSAGE)
      return "GameRolePlayArenaUnregisterMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE)
      return "GameRolePlayArenaUpdatePlayerInfosMessage";
  
  else if(messageEnum == MessageEnum::SWITCHARENAXPREWARDSMODEMESSAGE)
      return "SwitchArenaXpRewardsModeMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYAGGRESSIONMESSAGE)
      return "GameRolePlayAggressionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE)
      return "GameRolePlayAttackMonsterRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE)
      return "GameRolePlayFightRequestCanceledMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYMONSTERANGRYATPLAYERMESSAGE)
      return "GameRolePlayMonsterAngryAtPlayerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYMONSTERNOTANGRYATPLAYERMESSAGE)
      return "GameRolePlayMonsterNotAngryAtPlayerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE)
      return "GameRolePlayPlayerFightFriendlyAnsweredMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE)
      return "GameRolePlayPlayerFightFriendlyAnswerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE)
      return "GameRolePlayPlayerFightFriendlyRequestedMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE)
      return "GameRolePlayPlayerFightRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYREMOVECHALLENGEMESSAGE)
      return "GameRolePlayRemoveChallengeMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWCHALLENGEMESSAGE)
      return "GameRolePlayShowChallengeMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE)
      return "GameRolePlayShowActorMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE)
      return "GameRolePlayShowActorWithEventMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWMULTIPLEACTORSMESSAGE)
      return "GameRolePlayShowMultipleActorsMessage";
  
  else if(messageEnum == MessageEnum::CHANGEHAVENBAGROOMREQUESTMESSAGE)
      return "ChangeHavenBagRoomRequestMessage";
  
  else if(messageEnum == MessageEnum::CHANGETHEMEREQUESTMESSAGE)
      return "ChangeThemeRequestMessage";
  
  else if(messageEnum == MessageEnum::CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE)
      return "CloseHavenBagFurnitureSequenceRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGCANCELREQUESTMESSAGE)
      return "EditHavenBagCancelRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGFINISHEDMESSAGE)
      return "EditHavenBagFinishedMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGREQUESTMESSAGE)
      return "EditHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGSTARTMESSAGE)
      return "EditHavenBagStartMessage";
  
  else if(messageEnum == MessageEnum::ENTERHAVENBAGREQUESTMESSAGE)
      return "EnterHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::EXITHAVENBAGREQUESTMESSAGE)
      return "ExitHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGDAILYLOTERYMESSAGE)
      return "HavenBagDailyLoteryMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGFURNITURESMESSAGE)
      return "HavenBagFurnituresMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGFURNITURESREQUESTMESSAGE)
      return "HavenBagFurnituresRequestMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGPACKLISTMESSAGE)
      return "HavenBagPackListMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGROOMUPDATEMESSAGE)
      return "HavenBagRoomUpdateMessage";
  
  else if(messageEnum == MessageEnum::KICKHAVENBAGREQUESTMESSAGE)
      return "KickHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGPERMISSIONSUPDATEMESSAGE)
      return "HavenBagPermissionsUpdateMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGPERMISSIONSUPDATEREQUESTMESSAGE)
      return "HavenBagPermissionsUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGCLOSEDMESSAGE)
      return "InviteInHavenBagClosedMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGMESSAGE)
      return "InviteInHavenBagMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGOFFERMESSAGE)
      return "InviteInHavenBagOfferMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTHAVENBAGANSWERMESSAGE)
      return "TeleportHavenBagAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTHAVENBAGREQUESTMESSAGE)
      return "TeleportHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE)
      return "OpenHavenBagFurnitureSequenceRequestMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTHOUSEMESSAGE)
      return "AccountHouseMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDNONEMESSAGE)
      return "HouseGuildNoneMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDRIGHTSMESSAGE)
      return "HouseGuildRightsMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDRIGHTSVIEWMESSAGE)
      return "HouseGuildRightsViewMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDSHAREREQUESTMESSAGE)
      return "HouseGuildShareRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEBUYREQUESTMESSAGE)
      return "HouseBuyRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEBUYRESULTMESSAGE)
      return "HouseBuyResultMessage";
  
  else if(messageEnum == MessageEnum::HOUSEKICKREQUESTMESSAGE)
      return "HouseKickRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSELOCKFROMINSIDEREQUESTMESSAGE)
      return "HouseLockFromInsideRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEPROPERTIESMESSAGE)
      return "HousePropertiesMessage";
  
  else if(messageEnum == MessageEnum::HOUSESELLFROMINSIDEREQUESTMESSAGE)
      return "HouseSellFromInsideRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSESELLINGUPDATEMESSAGE)
      return "HouseSellingUpdateMessage";
  
  else if(messageEnum == MessageEnum::HOUSESELLREQUESTMESSAGE)
      return "HouseSellRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLFILTERMESSAGE)
      return "HouseToSellFilterMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLLISTMESSAGE)
      return "HouseToSellListMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLLISTREQUESTMESSAGE)
      return "HouseToSellListRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBALLOWMULTICRAFTREQUESTMESSAGE)
      return "JobAllowMultiCraftRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBBOOKSUBSCRIPTIONMESSAGE)
      return "JobBookSubscriptionMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYADDMESSAGE)
      return "JobCrafterDirectoryAddMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE)
      return "JobCrafterDirectoryDefineSettingsMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYENTRYMESSAGE)
      return "JobCrafterDirectoryEntryMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE)
      return "JobCrafterDirectoryEntryRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYLISTMESSAGE)
      return "JobCrafterDirectoryListMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE)
      return "JobCrafterDirectoryListRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYREMOVEMESSAGE)
      return "JobCrafterDirectoryRemoveMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYSETTINGSMESSAGE)
      return "JobCrafterDirectorySettingsMessage";
  
  else if(messageEnum == MessageEnum::JOBDESCRIPTIONMESSAGE)
      return "JobDescriptionMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE)
      return "JobExperienceMultiUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE)
      return "JobExperienceOtherPlayerUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEUPDATEMESSAGE)
      return "JobExperienceUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBLEVELUPMESSAGE)
      return "JobLevelUpMessage";
  
  else if(messageEnum == MessageEnum::JOBMULTICRAFTAVAILABLESKILLSMESSAGE)
      return "JobMultiCraftAvailableSkillsMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLECHANGECODEMESSAGE)
      return "LockableChangeCodeMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLECODERESULTMESSAGE)
      return "LockableCodeResultMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESHOWCODEDIALOGMESSAGE)
      return "LockableShowCodeDialogMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATEABSTRACTMESSAGE)
      return "LockableStateUpdateAbstractMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATEHOUSEDOORMESSAGE)
      return "LockableStateUpdateHouseDoorMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATESTORAGEMESSAGE)
      return "LockableStateUpdateStorageMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLEUSECODEMESSAGE)
      return "LockableUseCodeMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE)
      return "MapComplementaryInformationsDataInHavenBagMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE)
      return "MapComplementaryInformationsDataInHouseMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE)
      return "MapComplementaryInformationsDataMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE)
      return "MapComplementaryInformationsWithCoordsMessage";
  
  else if(messageEnum == MessageEnum::MAPFIGHTCOUNTMESSAGE)
      return "MapFightCountMessage";
  
  else if(messageEnum == MessageEnum::MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE)
      return "MapFightStartPositionsUpdateMessage";
  
  else if(messageEnum == MessageEnum::MAPINFORMATIONSREQUESTMESSAGE)
      return "MapInformationsRequestMessage";
  
  else if(messageEnum == MessageEnum::MAPOBSTACLEUPDATEMESSAGE)
      return "MapObstacleUpdateMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE)
      return "MapRunningFightDetailsExtendedMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSMESSAGE)
      return "MapRunningFightDetailsMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE)
      return "MapRunningFightDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE)
      return "MapRunningFightListMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTLISTREQUESTMESSAGE)
      return "MapRunningFightListRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPRISMDIALOGQUESTIONMESSAGE)
      return "AlliancePrismDialogQuestionMessage";
  
  else if(messageEnum == MessageEnum::ENTITYTALKMESSAGE)
      return "EntityTalkMessage";
  
  else if(messageEnum == MessageEnum::LISTMAPNPCSQUESTSTATUSUPDATEMESSAGE)
      return "ListMapNpcsQuestStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGCREATIONMESSAGE)
      return "NpcDialogCreationMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGQUESTIONMESSAGE)
      return "NpcDialogQuestionMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGREPLYMESSAGE)
      return "NpcDialogReplyMessage";
  
  else if(messageEnum == MessageEnum::NPCGENERICACTIONFAILUREMESSAGE)
      return "NpcGenericActionFailureMessage";
  
  else if(messageEnum == MessageEnum::NPCGENERICACTIONREQUESTMESSAGE)
      return "NpcGenericActionRequestMessage";
  
  else if(messageEnum == MessageEnum::PORTALDIALOGCREATIONMESSAGE)
      return "PortalDialogCreationMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE)
      return "TaxCollectorDialogQuestionBasicMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE)
      return "TaxCollectorDialogQuestionExtendedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDADDEDMESSAGE)
      return "ObjectGroundAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE)
      return "ObjectGroundListAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDREMOVEDMESSAGE)
      return "ObjectGroundRemovedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDREMOVEDMULTIPLEMESSAGE)
      return "ObjectGroundRemovedMultipleMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE)
      return "GameDataPlayFarmObjectAnimationMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKPROPERTIESMESSAGE)
      return "PaddockPropertiesMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKSELLBUYDIALOGMESSAGE)
      return "PaddockSellBuyDialogMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLFILTERMESSAGE)
      return "PaddockToSellFilterMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLLISTMESSAGE)
      return "PaddockToSellListMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLLISTREQUESTMESSAGE)
      return "PaddockToSellListRequestMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTPARTYEVENTMESSAGE)
      return "AbstractPartyEventMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTPARTYMEMBERINFIGHTMESSAGE)
      return "AbstractPartyMemberInFightMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTPARTYMESSAGE)
      return "AbstractPartyMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBERINBREACHFIGHTMESSAGE)
      return "PartyMemberInBreachFightMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE)
      return "DungeonPartyFinderAvailableDungeonsMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE)
      return "DungeonPartyFinderAvailableDungeonsRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERLISTENERRORMESSAGE)
      return "DungeonPartyFinderListenErrorMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERLISTENREQUESTMESSAGE)
      return "DungeonPartyFinderListenRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERERRORMESSAGE)
      return "DungeonPartyFinderRegisterErrorMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE)
      return "DungeonPartyFinderRegisterRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE)
      return "DungeonPartyFinderRegisterSuccessMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERROOMCONTENTMESSAGE)
      return "DungeonPartyFinderRoomContentMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE)
      return "DungeonPartyFinderRoomContentUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYENTITYUPDATELIGHTMESSAGE)
      return "PartyEntityUpdateLightMessage";
  
  else if(messageEnum == MessageEnum::PARTYABDICATETHRONEMESSAGE)
      return "PartyAbdicateThroneMessage";
  
  else if(messageEnum == MessageEnum::PARTYACCEPTINVITATIONMESSAGE)
      return "PartyAcceptInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANCELINVITATIONMESSAGE)
      return "PartyCancelInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANCELINVITATIONNOTIFICATIONMESSAGE)
      return "PartyCancelInvitationNotificationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANNOTJOINERRORMESSAGE)
      return "PartyCannotJoinErrorMessage";
  
  else if(messageEnum == MessageEnum::PARTYDELETEDMESSAGE)
      return "PartyDeletedMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWMEMBERREQUESTMESSAGE)
      return "PartyFollowMemberRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE)
      return "PartyFollowStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWTHISMEMBERREQUESTMESSAGE)
      return "PartyFollowThisMemberRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONARENAREQUESTMESSAGE)
      return "PartyInvitationArenaRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONCANCELLEDFORGUESTMESSAGE)
      return "PartyInvitationCancelledForGuestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDETAILSMESSAGE)
      return "PartyInvitationDetailsMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDETAILSREQUESTMESSAGE)
      return "PartyInvitationDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONDETAILSMESSAGE)
      return "PartyInvitationDungeonDetailsMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONMESSAGE)
      return "PartyInvitationDungeonMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONREQUESTMESSAGE)
      return "PartyInvitationDungeonRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONMESSAGE)
      return "PartyInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONREQUESTMESSAGE)
      return "PartyInvitationRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYJOINMESSAGE)
      return "PartyJoinMessage";
  
  else if(messageEnum == MessageEnum::PARTYKICKEDBYMESSAGE)
      return "PartyKickedByMessage";
  
  else if(messageEnum == MessageEnum::PARTYKICKREQUESTMESSAGE)
      return "PartyKickRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEADERUPDATEMESSAGE)
      return "PartyLeaderUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEAVEMESSAGE)
      return "PartyLeaveMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEAVEREQUESTMESSAGE)
      return "PartyLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOCATEMEMBERSMESSAGE)
      return "PartyLocateMembersMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOCATEMEMBERSREQUESTMESSAGE)
      return "PartyLocateMembersRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOYALTYSTATUSMESSAGE)
      return "PartyLoyaltyStatusMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBEREJECTEDMESSAGE)
      return "PartyMemberEjectedMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBERINSTANDARDFIGHTMESSAGE)
      return "PartyMemberInStandardFightMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBERREMOVEMESSAGE)
      return "PartyMemberRemoveMessage";
  
  else if(messageEnum == MessageEnum::PARTYMODIFIABLESTATUSMESSAGE)
      return "PartyModifiableStatusMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMESETERRORMESSAGE)
      return "PartyNameSetErrorMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMESETREQUESTMESSAGE)
      return "PartyNameSetRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMEUPDATEMESSAGE)
      return "PartyNameUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYNEWGUESTMESSAGE)
      return "PartyNewGuestMessage";
  
  else if(messageEnum == MessageEnum::PARTYNEWMEMBERMESSAGE)
      return "PartyNewMemberMessage";
  
  else if(messageEnum == MessageEnum::PARTYPLEDGELOYALTYREQUESTMESSAGE)
      return "PartyPledgeLoyaltyRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYREFUSEINVITATIONMESSAGE)
      return "PartyRefuseInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE)
      return "PartyRefuseInvitationNotificationMessage";
  
  else if(messageEnum == MessageEnum::PARTYRESTRICTEDMESSAGE)
      return "PartyRestrictedMessage";
  
  else if(messageEnum == MessageEnum::PARTYSTOPFOLLOWREQUESTMESSAGE)
      return "PartyStopFollowRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYUPDATELIGHTMESSAGE)
      return "PartyUpdateLightMessage";
  
  else if(messageEnum == MessageEnum::PARTYUPDATEMESSAGE)
      return "PartyUpdateMessage";
  
  else if(messageEnum == MessageEnum::PURCHASABLEDIALOGMESSAGE)
      return "PurchasableDialogMessage";
  
  else if(messageEnum == MessageEnum::FOLLOWEDQUESTSMESSAGE)
      return "FollowedQuestsMessage";
  
  else if(messageEnum == MessageEnum::FOLLOWQUESTOBJECTIVEREQUESTMESSAGE)
      return "FollowQuestObjectiveRequestMessage";
  
  else if(messageEnum == MessageEnum::GUIDEDMODEQUITREQUESTMESSAGE)
      return "GuidedModeQuitRequestMessage";
  
  else if(messageEnum == MessageEnum::GUIDEDMODERETURNREQUESTMESSAGE)
      return "GuidedModeReturnRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTLISTMESSAGE)
      return "QuestListMessage";
  
  else if(messageEnum == MessageEnum::QUESTLISTREQUESTMESSAGE)
      return "QuestListRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTOBJECTIVEVALIDATEDMESSAGE)
      return "QuestObjectiveValidatedMessage";
  
  else if(messageEnum == MessageEnum::QUESTOBJECTIVEVALIDATIONMESSAGE)
      return "QuestObjectiveValidationMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTARTEDMESSAGE)
      return "QuestStartedMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTARTREQUESTMESSAGE)
      return "QuestStartRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPINFOMESSAGE)
      return "QuestStepInfoMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPINFOREQUESTMESSAGE)
      return "QuestStepInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPSTARTEDMESSAGE)
      return "QuestStepStartedMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPVALIDATEDMESSAGE)
      return "QuestStepValidatedMessage";
  
  else if(messageEnum == MessageEnum::QUESTVALIDATEDMESSAGE)
      return "QuestValidatedMessage";
  
  else if(messageEnum == MessageEnum::REFRESHFOLLOWEDQUESTSORDERREQUESTMESSAGE)
      return "RefreshFollowedQuestsOrderRequestMessage";
  
  else if(messageEnum == MessageEnum::UNFOLLOWQUESTOBJECTIVEREQUESTMESSAGE)
      return "UnfollowQuestObjectiveRequestMessage";
  
  else if(messageEnum == MessageEnum::WATCHQUESTLISTMESSAGE)
      return "WatchQuestListMessage";
  
  else if(messageEnum == MessageEnum::WATCHQUESTSTEPINFOMESSAGE)
      return "WatchQuestStepInfoMessage";
  
  else if(messageEnum == MessageEnum::WATCHQUESTSTEPINFOREQUESTMESSAGE)
      return "WatchQuestStepInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::SPELLVARIANTACTIVATIONMESSAGE)
      return "SpellVariantActivationMessage";
  
  else if(messageEnum == MessageEnum::SPELLVARIANTACTIVATIONREQUESTMESSAGE)
      return "SpellVariantActivationRequestMessage";
  
  else if(messageEnum == MessageEnum::STATSUPGRADEREQUESTMESSAGE)
      return "StatsUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::STATSUPGRADERESULTMESSAGE)
      return "StatsUpgradeResultMessage";
  
  else if(messageEnum == MessageEnum::STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE)
      return "StopToListenRunningFightRequestMessage";
  
  else if(messageEnum == MessageEnum::SUBAREAREWARDRATEMESSAGE)
      return "SubareaRewardRateMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTONSAMEMAPMESSAGE)
      return "TeleportOnSameMapMessage";
  
  else if(messageEnum == MessageEnum::PORTALUSEREQUESTMESSAGE)
      return "PortalUseRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE)
      return "TreasureHuntAvailableRetryCountUpdateMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE)
      return "TreasureHuntDigRequestAnswerFailedMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTANSWERMESSAGE)
      return "TreasureHuntDigRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTMESSAGE)
      return "TreasureHuntDigRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFINISHEDMESSAGE)
      return "TreasureHuntFinishedMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREMOVEREQUESTMESSAGE)
      return "TreasureHuntFlagRemoveRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREQUESTANSWERMESSAGE)
      return "TreasureHuntFlagRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREQUESTMESSAGE)
      return "TreasureHuntFlagRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTGIVEUPREQUESTMESSAGE)
      return "TreasureHuntGiveUpRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTLEGENDARYREQUESTMESSAGE)
      return "TreasureHuntLegendaryRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTMESSAGE)
      return "TreasureHuntMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTREQUESTANSWERMESSAGE)
      return "TreasureHuntRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTSHOWLEGENDARYUIMESSAGE)
      return "TreasureHuntShowLegendaryUIMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSPELLANIMMESSAGE)
      return "GameRolePlaySpellAnimMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLMESSAGE)
      return "ShowCellMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLREQUESTMESSAGE)
      return "ShowCellRequestMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLSPECTATORMESSAGE)
      return "ShowCellSpectatorMessage";
  
  else if(messageEnum == MessageEnum::LEAVEDIALOGMESSAGE)
      return "LeaveDialogMessage";
  
  else if(messageEnum == MessageEnum::LEAVEDIALOGREQUESTMESSAGE)
      return "LeaveDialogRequestMessage";
  
  else if(messageEnum == MessageEnum::PAUSEDIALOGMESSAGE)
      return "PauseDialogMessage";
  
  else if(messageEnum == MessageEnum::ENTITIESINFORMATIONMESSAGE)
      return "EntitiesInformationMessage";
  
  else if(messageEnum == MessageEnum::ENTITYINFORMATIONMESSAGE)
      return "EntityInformationMessage";
  
  else if(messageEnum == MessageEnum::OBJECTFEEDMESSAGE)
      return "ObjectFeedMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVELISTMESSAGE)
      return "FinishMoveListMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVELISTREQUESTMESSAGE)
      return "FinishMoveListRequestMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVESETREQUESTMESSAGE)
      return "FinishMoveSetRequestMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCEADDEDMESSAGE)
      return "AcquaintanceAddedMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESGETLISTMESSAGE)
      return "AcquaintancesGetListMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESLISTMESSAGE)
      return "AcquaintancesListMessage";
  
  else if(messageEnum == MessageEnum::CONTACTADDFAILUREMESSAGE)
      return "ContactAddFailureMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDEDMESSAGE)
      return "FriendAddedMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDFAILUREMESSAGE)
      return "FriendAddFailureMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDREQUESTMESSAGE)
      return "FriendAddRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDDELETEREQUESTMESSAGE)
      return "FriendDeleteRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDDELETERESULTMESSAGE)
      return "FriendDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::FRIENDJOINREQUESTMESSAGE)
      return "FriendJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSETSTATUSSHAREMESSAGE)
      return "FriendSetStatusShareMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSETWARNONCONNECTIONMESSAGE)
      return "FriendSetWarnOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSETWARNONLEVELGAINMESSAGE)
      return "FriendSetWarnOnLevelGainMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSGETLISTMESSAGE)
      return "FriendsGetListMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSLISTMESSAGE)
      return "FriendsListMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE)
      return "FriendSpouseFollowWithCompassRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSPOUSEJOINREQUESTMESSAGE)
      return "FriendSpouseJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSTATUSSHARESTATEMESSAGE)
      return "FriendStatusShareStateMessage";
  
  else if(messageEnum == MessageEnum::FRIENDUPDATEMESSAGE)
      return "FriendUpdateMessage";
  
  else if(messageEnum == MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE)
      return "FriendWarnOnConnectionStateMessage";
  
  else if(messageEnum == MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE)
      return "FriendWarnOnLevelGainStateMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDEDMESSAGE)
      return "IgnoredAddedMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDFAILUREMESSAGE)
      return "IgnoredAddFailureMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDREQUESTMESSAGE)
      return "IgnoredAddRequestMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDDELETEREQUESTMESSAGE)
      return "IgnoredDeleteRequestMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDDELETERESULTMESSAGE)
      return "IgnoredDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDGETLISTMESSAGE)
      return "IgnoredGetListMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDLISTMESSAGE)
      return "IgnoredListMessage";
  
  else if(messageEnum == MessageEnum::SPOUSEGETINFORMATIONSMESSAGE)
      return "SpouseGetInformationsMessage";
  
  else if(messageEnum == MessageEnum::SPOUSEINFORMATIONSMESSAGE)
      return "SpouseInformationsMessage";
  
  else if(messageEnum == MessageEnum::SPOUSESTATUSMESSAGE)
      return "SpouseStatusMessage";
  
  else if(messageEnum == MessageEnum::WARNONPERMADEATHSTATEMESSAGE)
      return "WarnOnPermaDeathStateMessage";
  
  else if(messageEnum == MessageEnum::GUESTLIMITATIONMESSAGE)
      return "GuestLimitationMessage";
  
  else if(messageEnum == MessageEnum::GUESTMODEMESSAGE)
      return "GuestModeMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONANSWERMESSAGE)
      return "GuildApplicationAnswerMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONDELETEDMESSAGE)
      return "GuildApplicationDeletedMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONISANSWEREDMESSAGE)
      return "GuildApplicationIsAnsweredMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONLISTENMESSAGE)
      return "GuildApplicationListenMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONPRESENCEMESSAGE)
      return "GuildApplicationPresenceMessage";
  
  else if(messageEnum == MessageEnum::GUILDAPPLICATIONRECEIVEDMESSAGE)
      return "GuildApplicationReceivedMessage";
  
  else if(messageEnum == MessageEnum::GUILDDELETEAPPLICATIONREQUESTMESSAGE)
      return "GuildDeleteApplicationRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDGETPLAYERAPPLICATIONMESSAGE)
      return "GuildGetPlayerApplicationMessage";
  
  else if(messageEnum == MessageEnum::GUILDISTHEREANYAPPLICATIONMESSAGE)
      return "GuildIsThereAnyApplicationMessage";
  
  else if(messageEnum == MessageEnum::GUILDLISTAPPLICATIONANSWERMESSAGE)
      return "GuildListApplicationAnswerMessage";
  
  else if(messageEnum == MessageEnum::GUILDLISTAPPLICATIONMODIFIEDMESSAGE)
      return "GuildListApplicationModifiedMessage";
  
  else if(messageEnum == MessageEnum::GUILDLISTAPPLICATIONREQUESTMESSAGE)
      return "GuildListApplicationRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDPLAYERAPPLICATIONABSTRACTMESSAGE)
      return "GuildPlayerApplicationAbstractMessage";
  
  else if(messageEnum == MessageEnum::GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE)
      return "GuildPlayerApplicationInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDPLAYERNOAPPLICATIONINFORMATIONMESSAGE)
      return "GuildPlayerNoApplicationInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDSUBMITAPPLICATIONMESSAGE)
      return "GuildSubmitApplicationMessage";
  
  else if(messageEnum == MessageEnum::GUILDUPDATEAPPLICATIONMESSAGE)
      return "GuildUpdateApplicationMessage";
  
  else if(messageEnum == MessageEnum::GUILDUPDATENOTEMESSAGE)
      return "GuildUpdateNoteMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEFIGHTJOINREFUSEDMESSAGE)
      return "ChallengeFightJoinRefusedMessage";
  
  else if(messageEnum == MessageEnum::ADDLISTENERONSYNCHRONIZEDSTORAGEMESSAGE)
      return "AddListenerOnSynchronizedStorageMessage";
  
  else if(messageEnum == MessageEnum::LISTENERSOFSYNCHRONIZEDSTORAGEMESSAGE)
      return "ListenersOfSynchronizedStorageMessage";
  
  else if(messageEnum == MessageEnum::REMOVELISTENERONSYNCHRONIZEDSTORAGEMESSAGE)
      return "RemoveListenerOnSynchronizedStorageMessage";
  
  else if(messageEnum == MessageEnum::CREATEGUILDRANKREQUESTMESSAGE)
      return "CreateGuildRankRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINMESSAGE)
      return "GuildBulletinMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINSETERRORMESSAGE)
      return "GuildBulletinSetErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINSETREQUESTMESSAGE)
      return "GuildBulletinSetRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHANGEMEMBERPARAMETERSMESSAGE)
      return "GuildChangeMemberParametersMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHARACSUPGRADEREQUESTMESSAGE)
      return "GuildCharacsUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHESTTABCONTRIBUTIONMESSAGE)
      return "GuildChestTabContributionMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHESTTABCONTRIBUTIONSMESSAGE)
      return "GuildChestTabContributionsMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHESTTABLASTCONTRIBUTIONMESSAGE)
      return "GuildChestTabLastContributionMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONRESULTMESSAGE)
      return "GuildCreationResultMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONSTARTEDMESSAGE)
      return "GuildCreationStartedMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONVALIDMESSAGE)
      return "GuildCreationValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSERRORMESSAGE)
      return "GuildFactsErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSMESSAGE)
      return "GuildFactsMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSREQUESTMESSAGE)
      return "GuildFactsRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDGETCHESTTABCONTRIBUTIONSREQUESTMESSAGE)
      return "GuildGetChestTabContributionsRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDGETINFORMATIONSMESSAGE)
      return "GuildGetInformationsMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSEREMOVEMESSAGE)
      return "GuildHouseRemoveMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSESINFORMATIONMESSAGE)
      return "GuildHousesInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSEUPDATEINFORMATIONMESSAGE)
      return "GuildHouseUpdateInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSGENERALMESSAGE)
      return "GuildInformationsGeneralMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSMEMBERSMESSAGE)
      return "GuildInformationsMembersMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSMEMBERUPDATEMESSAGE)
      return "GuildInformationsMemberUpdateMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSPADDOCKSMESSAGE)
      return "GuildInformationsPaddocksMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONANSWERMESSAGE)
      return "GuildInvitationAnswerMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONMESSAGE)
      return "GuildInvitationMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONSTATERECRUTEDMESSAGE)
      return "GuildInvitationStateRecrutedMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONSTATERECRUTERMESSAGE)
      return "GuildInvitationStateRecruterMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITEDMESSAGE)
      return "GuildInvitedMessage";
  
  else if(messageEnum == MessageEnum::GUILDJOINAUTOMATICALLYREQUESTMESSAGE)
      return "GuildJoinAutomaticallyRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDJOINEDMESSAGE)
      return "GuildJoinedMessage";
  
  else if(messageEnum == MessageEnum::GUILDKICKREQUESTMESSAGE)
      return "GuildKickRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDLEFTMESSAGE)
      return "GuildLeftMessage";
  
  else if(messageEnum == MessageEnum::GUILDLEVELUPMESSAGE)
      return "GuildLevelUpMessage";
  
  else if(messageEnum == MessageEnum::GUILDLISTMESSAGE)
      return "GuildListMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERLEAVINGMESSAGE)
      return "GuildMemberLeavingMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERONLINESTATUSMESSAGE)
      return "GuildMemberOnlineStatusMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERSHIPMESSAGE)
      return "GuildMembershipMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERSTARTWARNONCONNECTIONMESSAGE)
      return "GuildMemberStartWarnOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERSTOPWARNONCONNECTIONMESSAGE)
      return "GuildMemberStopWarnOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONEMBLEMVALIDMESSAGE)
      return "GuildModificationEmblemValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONNAMEVALIDMESSAGE)
      return "GuildModificationNameValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONRESULTMESSAGE)
      return "GuildModificationResultMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONSTARTEDMESSAGE)
      return "GuildModificationStartedMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONVALIDMESSAGE)
      return "GuildModificationValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDMESSAGE)
      return "GuildMotdMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDSETERRORMESSAGE)
      return "GuildMotdSetErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDSETREQUESTMESSAGE)
      return "GuildMotdSetRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKBOUGHTMESSAGE)
      return "GuildPaddockBoughtMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKREMOVEDMESSAGE)
      return "GuildPaddockRemovedMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKTELEPORTREQUESTMESSAGE)
      return "GuildPaddockTeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDRANKSMESSAGE)
      return "GuildRanksMessage";
  
  else if(messageEnum == MessageEnum::GUILDRANKSREQUESTMESSAGE)
      return "GuildRanksRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDSELECTCHESTTABREQUESTMESSAGE)
      return "GuildSelectChestTabRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDSPELLUPGRADEREQUESTMESSAGE)
      return "GuildSpellUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDSUMMARYMESSAGE)
      return "GuildSummaryMessage";
  
  else if(messageEnum == MessageEnum::GUILDSUMMARYREQUESTMESSAGE)
      return "GuildSummaryRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDUPDATECHESTTABREQUESTMESSAGE)
      return "GuildUpdateChestTabRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDLOGBOOKINFORMATIONMESSAGE)
      return "GuildLogbookInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDLOGBOOKINFORMATIONREQUESTMESSAGE)
      return "GuildLogbookInformationRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDRECRUITMENTINVALIDATEMESSAGE)
      return "GuildRecruitmentInvalidateMessage";
  
  else if(messageEnum == MessageEnum::RECRUITMENTINFORMATIONMESSAGE)
      return "RecruitmentInformationMessage";
  
  else if(messageEnum == MessageEnum::UPDATERECRUITMENTINFORMATIONMESSAGE)
      return "UpdateRecruitmentInformationMessage";
  
  else if(messageEnum == MessageEnum::REMOVEGUILDRANKREQUESTMESSAGE)
      return "RemoveGuildRankRequestMessage";
  
  else if(messageEnum == MessageEnum::STARTGUILDCHESTCONTRIBUTIONMESSAGE)
      return "StartGuildChestContributionMessage";
  
  else if(messageEnum == MessageEnum::STARTLISTENGUILDCHESTSTRUCTUREMESSAGE)
      return "StartListenGuildChestStructureMessage";
  
  else if(messageEnum == MessageEnum::STOPGUILDCHESTCONTRIBUTIONMESSAGE)
      return "StopGuildChestContributionMessage";
  
  else if(messageEnum == MessageEnum::STOPLISTENGUILDCHESTSTRUCTUREMESSAGE)
      return "StopListenGuildChestStructureMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTOREQUIPMENTUPDATEMESSAGE)
      return "TaxCollectorEquipmentUpdateMessage";
  
  else if(messageEnum == MessageEnum::UPDATEALLGUILDRANKREQUESTMESSAGE)
      return "UpdateAllGuildRankRequestMessage";
  
  else if(messageEnum == MessageEnum::UPDATEGUILDRANKREQUESTMESSAGE)
      return "UpdateGuildRankRequestMessage";
  
  else if(messageEnum == MessageEnum::UPDATEGUILDRIGHTSMESSAGE)
      return "UpdateGuildRightsMessage";
  
  else if(messageEnum == MessageEnum::HOUSETELEPORTREQUESTMESSAGE)
      return "HouseTeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCAPABILITIESMESSAGE)
      return "CharacterCapabilitiesMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE)
      return "CharacterLoadingCompleteMessage";
  
  else if(messageEnum == MessageEnum::ONCONNECTIONEVENTMESSAGE)
      return "OnConnectionEventMessage";
  
  else if(messageEnum == MessageEnum::SERVEREXPERIENCEMODIFICATORMESSAGE)
      return "ServerExperienceModificatorMessage";
  
  else if(messageEnum == MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE)
      return "SetCharacterRestrictionsMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE)
      return "InteractiveElementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEMAPUPDATEMESSAGE)
      return "InteractiveMapUpdateMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEDMESSAGE)
      return "InteractiveUsedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEENDEDMESSAGE)
      return "InteractiveUseEndedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEERRORMESSAGE)
      return "InteractiveUseErrorMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEREQUESTMESSAGE)
      return "InteractiveUseRequestMessage";
  
  else if(messageEnum == MessageEnum::GROUPTELEPORTPLAYERANSWERMESSAGE)
      return "GroupTeleportPlayerAnswerMessage";
  
  else if(messageEnum == MessageEnum::GROUPTELEPORTPLAYERCLOSEMESSAGE)
      return "GroupTeleportPlayerCloseMessage";
  
  else if(messageEnum == MessageEnum::GROUPTELEPORTPLAYEROFFERMESSAGE)
      return "GroupTeleportPlayerOfferMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESANSWERMESSAGE)
      return "TeleportBuddiesAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESMESSAGE)
      return "TeleportBuddiesMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESREQUESTEDMESSAGE)
      return "TeleportBuddiesRequestedMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTPLAYERANSWERMESSAGE)
      return "TeleportPlayerAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTPLAYERCLOSEMESSAGE)
      return "TeleportPlayerCloseMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTPLAYEROFFERMESSAGE)
      return "TeleportPlayerOfferMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYANSWERMESSAGE)
      return "TeleportToBuddyAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYCLOSEMESSAGE)
      return "TeleportToBuddyCloseMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYOFFERMESSAGE)
      return "TeleportToBuddyOfferMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEWITHPARAMREQUESTMESSAGE)
      return "InteractiveUseWithParamRequestMessage";
  
  else if(messageEnum == MessageEnum::STATEDELEMENTUPDATEDMESSAGE)
      return "StatedElementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::STATEDMAPUPDATEMESSAGE)
      return "StatedMapUpdateMessage";
  
  else if(messageEnum == MessageEnum::KNOWNZAAPLISTMESSAGE)
      return "KnownZaapListMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTDESTINATIONSMESSAGE)
      return "TeleportDestinationsMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTREQUESTMESSAGE)
      return "TeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::ZAAPDESTINATIONSMESSAGE)
      return "ZaapDestinationsMessage";
  
  else if(messageEnum == MessageEnum::ZAAPRESPAWNSAVEREQUESTMESSAGE)
      return "ZaapRespawnSaveRequestMessage";
  
  else if(messageEnum == MessageEnum::ZAAPRESPAWNUPDATEDMESSAGE)
      return "ZaapRespawnUpdatedMessage";
  
  else if(messageEnum == MessageEnum::DECRAFTRESULTMESSAGE)
      return "DecraftResultMessage";
  
  else if(messageEnum == MessageEnum::EVOLUTIVEOBJECTRECYCLERESULTMESSAGE)
      return "EvolutiveObjectRecycleResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEACCEPTMESSAGE)
      return "ExchangeAcceptMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEBUYMESSAGE)
      return "ExchangeBidHouseBuyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEBUYRESULTMESSAGE)
      return "ExchangeBidHouseBuyResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE)
      return "ExchangeBidHouseGenericItemAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE)
      return "ExchangeBidHouseGenericItemRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTADDEDMESSAGE)
      return "ExchangeBidHouseInListAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE)
      return "ExchangeBidHouseInListRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE)
      return "ExchangeBidHouseInListUpdatedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEITEMADDOKMESSAGE)
      return "ExchangeBidHouseItemAddOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE)
      return "ExchangeBidHouseItemRemoveOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSELISTMESSAGE)
      return "ExchangeBidHouseListMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEPRICEMESSAGE)
      return "ExchangeBidHousePriceMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSESEARCHMESSAGE)
      return "ExchangeBidHouseSearchMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSETYPEMESSAGE)
      return "ExchangeBidHouseTypeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE)
      return "ExchangeBidHouseUnsoldItemsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDPRICEFORSELLERMESSAGE)
      return "ExchangeBidPriceForSellerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDPRICEMESSAGE)
      return "ExchangeBidPriceMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDSEARCHOKMESSAGE)
      return "ExchangeBidSearchOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBUYMESSAGE)
      return "ExchangeBuyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBUYOKMESSAGE)
      return "ExchangeBuyOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE)
      return "ExchangeCraftCountModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTCOUNTREQUESTMESSAGE)
      return "ExchangeCraftCountRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTERJOBLEVELUPMESSAGE)
      return "ExchangeCrafterJobLevelupMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE)
      return "ExchangeCraftPaymentModificationRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE)
      return "ExchangeCraftPaymentModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE)
      return "ExchangeCraftResultMagicWithObjectDescMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTMESSAGE)
      return "ExchangeCraftResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE)
      return "ExchangeCraftResultWithObjectDescMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE)
      return "ExchangeCraftResultWithObjectIdMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEERRORMESSAGE)
      return "ExchangeErrorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEHANDLEMOUNTSMESSAGE)
      return "ExchangeHandleMountsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEISREADYMESSAGE)
      return "ExchangeIsReadyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE)
      return "ExchangeItemAutoCraftStopedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGELEAVEMESSAGE)
      return "ExchangeLeaveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMONEYMOVEMENTINFORMATIONMESSAGE)
      return "ExchangeMoneyMovementInformationMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE)
      return "ExchangeMountFreeFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSPADDOCKADDMESSAGE)
      return "ExchangeMountsPaddockAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE)
      return "ExchangeMountsPaddockRemoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEADDMESSAGE)
      return "ExchangeMountsStableAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEBORNADDMESSAGE)
      return "ExchangeMountsStableBornAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEREMOVEMESSAGE)
      return "ExchangeMountsStableRemoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTABLEERRORMESSAGE)
      return "ExchangeMountStableErrorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE)
      return "ExchangeMountsTakenFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE)
      return "ExchangeMountSterilizeFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTADDEDMESSAGE)
      return "ExchangeObjectAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMESSAGE)
      return "ExchangeObjectMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFYPRICEDMESSAGE)
      return "ExchangeObjectModifyPricedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEKAMAMESSAGE)
      return "ExchangeObjectMoveKamaMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEMESSAGE)
      return "ExchangeObjectMoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEPRICEDMESSAGE)
      return "ExchangeObjectMovePricedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVETOTABMESSAGE)
      return "ExchangeObjectMoveToTabMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSADDEDMESSAGE)
      return "ExchangeObjectsAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE)
      return "ExchangeObjectTransfertAllFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE)
      return "ExchangeObjectTransfertAllToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE)
      return "ExchangeObjectTransfertExistingFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE)
      return "ExchangeObjectTransfertExistingToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE)
      return "ExchangeObjectTransfertListFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE)
      return "ExchangeObjectTransfertListToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE)
      return "ExchangeObjectTransfertListWithQuantityToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTUSEINWORKSHOPMESSAGE)
      return "ExchangeObjectUseInWorkshopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOFFLINESOLDITEMSMESSAGE)
      return "ExchangeOfflineSoldItemsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOKMULTICRAFTMESSAGE)
      return "ExchangeOkMultiCraftMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE)
      return "ExchangePlayerMultiCraftRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPLAYERREQUESTMESSAGE)
      return "ExchangePlayerRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREADYMESSAGE)
      return "ExchangeReadyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREPLAYSTOPMESSAGE)
      return "ExchangeReplayStopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTEDMESSAGE)
      return "ExchangeRequestedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE)
      return "ExchangeRequestedTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTMESSAGE)
      return "ExchangeRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTONMOUNTSTOCKMESSAGE)
      return "ExchangeRequestOnMountStockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTONTAXCOLLECTORMESSAGE)
      return "ExchangeRequestOnTaxCollectorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESELLMESSAGE)
      return "ExchangeSellMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESELLOKMESSAGE)
      return "ExchangeSellOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESETCRAFTRECIPEMESSAGE)
      return "ExchangeSetCraftRecipeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDBIDBUYERMESSAGE)
      return "ExchangeStartedBidBuyerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE)
      return "ExchangeStartedBidSellerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDMESSAGE)
      return "ExchangeStartedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDMOUNTSTOCKMESSAGE)
      return "ExchangeStartedMountStockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDTAXCOLLECTOREQUIPMENTMESSAGE)
      return "ExchangeStartedTaxCollectorEquipmentMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE)
      return "ExchangeStartedTaxCollectorShopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDWITHMULTITABSTORAGEMESSAGE)
      return "ExchangeStartedWithMultiTabStorageMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE)
      return "ExchangeStartedWithPodsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE)
      return "ExchangeStartedWithStorageMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKCRAFTMESSAGE)
      return "ExchangeStartOkCraftMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE)
      return "ExchangeStartOkCraftWithInformationMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKEVOLUTIVEOBJECTRECYCLETRADEMESSAGE)
      return "ExchangeStartOkEvolutiveObjectRecycleTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKJOBINDEXMESSAGE)
      return "ExchangeStartOkJobIndexMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMOUNTMESSAGE)
      return "ExchangeStartOkMountMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE)
      return "ExchangeStartOkMountWithOutPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE)
      return "ExchangeStartOkMulticraftCrafterMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE)
      return "ExchangeStartOkMulticraftCustomerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE)
      return "ExchangeStartOkNpcShopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKNPCTRADEMESSAGE)
      return "ExchangeStartOkNpcTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE)
      return "ExchangeStartOkRecycleTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKRUNESTRADEMESSAGE)
      return "ExchangeStartOkRunesTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTOPPEDMESSAGE)
      return "ExchangeStoppedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGETAXCOLLECTORGETMESSAGE)
      return "ExchangeTaxCollectorGetMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE)
      return "ExchangeTypesExchangerDescriptionForUserMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE)
      return "ExchangeTypesItemsExchangerDescriptionForUserMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEWAITINGRESULTMESSAGE)
      return "ExchangeWaitingResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEWEIGHTMESSAGE)
      return "ExchangeWeightMessage";
  
  else if(messageEnum == MessageEnum::FOCUSEDEXCHANGEREADYMESSAGE)
      return "FocusedExchangeReadyMessage";
  
  else if(messageEnum == MessageEnum::ITEMNOMOREAVAILABLEMESSAGE)
      return "ItemNoMoreAvailableMessage";
  
  else if(messageEnum == MessageEnum::JOBBOOKSUBSCRIBEREQUESTMESSAGE)
      return "JobBookSubscribeRequestMessage";
  
  else if(messageEnum == MessageEnum::RECYCLERESULTMESSAGE)
      return "RecycleResultMessage";
  
  else if(messageEnum == MessageEnum::STARTEXCHANGETAXCOLLECTOREQUIPMENTMESSAGE)
      return "StartExchangeTaxCollectorEquipmentMessage";
  
  else if(messageEnum == MessageEnum::UPDATEMOUNTCHARACTERISTICSMESSAGE)
      return "UpdateMountCharacteristicsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE)
      return "ExchangeKamaModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE)
      return "ExchangeMultiCraftCrafterCanUseHisRessourcesMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE)
      return "ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFIEDINBAGMESSAGE)
      return "ExchangeObjectModifiedInBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE)
      return "ExchangeObjectModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTPUTINBAGMESSAGE)
      return "ExchangeObjectPutInBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE)
      return "ExchangeObjectRemovedFromBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE)
      return "ExchangeObjectRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE)
      return "ExchangeObjectsModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE)
      return "ExchangeObjectsRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPODSMODIFIEDMESSAGE)
      return "ExchangePodsModifiedMessage";
  
  else if(messageEnum == MessageEnum::GOLDADDEDMESSAGE)
      return "GoldAddedMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYCONTENTMESSAGE)
      return "InventoryContentMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYWEIGHTMESSAGE)
      return "InventoryWeightMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTCHANGESKINREQUESTMESSAGE)
      return "LivingObjectChangeSkinRequestMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTDISSOCIATEMESSAGE)
      return "LivingObjectDissociateMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTMESSAGEMESSAGE)
      return "LivingObjectMessageMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTMESSAGEREQUESTMESSAGE)
      return "LivingObjectMessageRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTASSOCIATEDMESSAGE)
      return "MimicryObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTERASEREQUESTMESSAGE)
      return "MimicryObjectEraseRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTERRORMESSAGE)
      return "MimicryObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE)
      return "MimicryObjectFeedAndAssociateRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTPREVIEWMESSAGE)
      return "MimicryObjectPreviewMessage";
  
  else if(messageEnum == MessageEnum::OBJECTADDEDMESSAGE)
      return "ObjectAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDELETEDMESSAGE)
      return "ObjectDeletedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDELETEMESSAGE)
      return "ObjectDeleteMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDROPMESSAGE)
      return "ObjectDropMessage";
  
  else if(messageEnum == MessageEnum::OBJECTERRORMESSAGE)
      return "ObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::OBJECTJOBADDEDMESSAGE)
      return "ObjectJobAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTMODIFIEDMESSAGE)
      return "ObjectModifiedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTMOVEMENTMESSAGE)
      return "ObjectMovementMessage";
  
  else if(messageEnum == MessageEnum::OBJECTQUANTITYMESSAGE)
      return "ObjectQuantityMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSADDEDMESSAGE)
      return "ObjectsAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSDELETEDMESSAGE)
      return "ObjectsDeletedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSETPOSITIONMESSAGE)
      return "ObjectSetPositionMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSQUANTITYMESSAGE)
      return "ObjectsQuantityMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEMESSAGE)
      return "ObjectUseMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEMULTIPLEMESSAGE)
      return "ObjectUseMultipleMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEONCELLMESSAGE)
      return "ObjectUseOnCellMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEONCHARACTERMESSAGE)
      return "ObjectUseOnCharacterMessage";
  
  else if(messageEnum == MessageEnum::OBTAINEDITEMMESSAGE)
      return "ObtainedItemMessage";
  
  else if(messageEnum == MessageEnum::OBTAINEDITEMWITHBONUSMESSAGE)
      return "ObtainedItemWithBonusMessage";
  
  else if(messageEnum == MessageEnum::SETUPDATEMESSAGE)
      return "SetUpdateMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTASSOCIATEDMESSAGE)
      return "SymbioticObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE)
      return "SymbioticObjectAssociateRequestMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTERRORMESSAGE)
      return "SymbioticObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::WATCHINVENTORYCONTENTMESSAGE)
      return "WatchInventoryContentMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTASSOCIATEDMESSAGE)
      return "WrapperObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE)
      return "WrapperObjectDissociateRequestMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTERRORMESSAGE)
      return "WrapperObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::KAMASUPDATEMESSAGE)
      return "KamasUpdateMessage";
  
  else if(messageEnum == MessageEnum::MULTITABSTORAGEMESSAGE)
      return "MultiTabStorageMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESERRORMESSAGE)
      return "ObjectAveragePricesErrorMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESGETMESSAGE)
      return "ObjectAveragePricesGetMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESMESSAGE)
      return "ObjectAveragePricesMessage";
  
  else if(messageEnum == MessageEnum::SPELLLISTMESSAGE)
      return "SpellListMessage";
  
  else if(messageEnum == MessageEnum::STORAGEINVENTORYCONTENTMESSAGE)
      return "StorageInventoryContentMessage";
  
  else if(messageEnum == MessageEnum::STORAGEKAMASUPDATEMESSAGE)
      return "StorageKamasUpdateMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTREMOVEMESSAGE)
      return "StorageObjectRemoveMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTSREMOVEMESSAGE)
      return "StorageObjectsRemoveMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTSUPDATEMESSAGE)
      return "StorageObjectsUpdateMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTUPDATEMESSAGE)
      return "StorageObjectUpdateMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWERRORMESSAGE)
      return "AccessoryPreviewErrorMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWMESSAGE)
      return "AccessoryPreviewMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWREQUESTMESSAGE)
      return "AccessoryPreviewRequestMessage";
  
  else if(messageEnum == MessageEnum::POPUPWARNINGCLOSEDMESSAGE)
      return "PopupWarningClosedMessage";
  
  else if(messageEnum == MessageEnum::POPUPWARNINGCLOSEREQUESTMESSAGE)
      return "PopupWarningCloseRequestMessage";
  
  else if(messageEnum == MessageEnum::POPUPWARNINGMESSAGE)
      return "PopupWarningMessage";
  
  else if(messageEnum == MessageEnum::AREAFIGHTMODIFICATORUPDATEMESSAGE)
      return "AreaFightModificatorUpdateMessage";
  
  else if(messageEnum == MessageEnum::NUGGETSDISTRIBUTIONMESSAGE)
      return "NuggetsDistributionMessage";
  
  else if(messageEnum == MessageEnum::NUGGETSINFORMATIONMESSAGE)
      return "NuggetsInformationMessage";
  
  else if(messageEnum == MessageEnum::STARTLISTENNUGGETSMESSAGE)
      return "StartListenNuggetsMessage";
  
  else if(messageEnum == MessageEnum::STOPLISTENNUGGETSMESSAGE)
      return "StopListenNuggetsMessage";
  
  else if(messageEnum == MessageEnum::PAGINATIONANSWERABSTRACTMESSAGE)
      return "PaginationAnswerAbstractMessage";
  
  else if(messageEnum == MessageEnum::PAGINATIONREQUESTABSTRACTMESSAGE)
      return "PaginationRequestAbstractMessage";
  
  else if(messageEnum == MessageEnum::ICONNAMEDPRESETSAVEREQUESTMESSAGE)
      return "IconNamedPresetSaveRequestMessage";
  
  else if(messageEnum == MessageEnum::ICONPRESETSAVEREQUESTMESSAGE)
      return "IconPresetSaveRequestMessage";
  
  else if(messageEnum == MessageEnum::INVALIDPRESETSMESSAGE)
      return "InvalidPresetsMessage";
  
  else if(messageEnum == MessageEnum::ITEMFORPRESETUPDATEMESSAGE)
      return "ItemForPresetUpdateMessage";
  
  else if(messageEnum == MessageEnum::PRESETDELETEREQUESTMESSAGE)
      return "PresetDeleteRequestMessage";
  
  else if(messageEnum == MessageEnum::PRESETDELETERESULTMESSAGE)
      return "PresetDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::PRESETSAVEDMESSAGE)
      return "PresetSavedMessage";
  
  else if(messageEnum == MessageEnum::PRESETSAVEERRORMESSAGE)
      return "PresetSaveErrorMessage";
  
  else if(messageEnum == MessageEnum::PRESETSMESSAGE)
      return "PresetsMessage";
  
  else if(messageEnum == MessageEnum::PRESETUSEREQUESTMESSAGE)
      return "PresetUseRequestMessage";
  
  else if(messageEnum == MessageEnum::PRESETUSERESULTMESSAGE)
      return "PresetUseResultMessage";
  
  else if(messageEnum == MessageEnum::PRESETUSERESULTWITHMISSINGIDSMESSAGE)
      return "PresetUseResultWithMissingIdsMessage";
  
  else if(messageEnum == MessageEnum::PRISMADDORUPDATEMESSAGE)
      return "PrismAddOrUpdateMessage";
  
  else if(messageEnum == MessageEnum::PRISMATTACKEDMESSAGE)
      return "PrismAttackedMessage";
  
  else if(messageEnum == MessageEnum::PRISMATTACKREQUESTMESSAGE)
      return "PrismAttackRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMATTACKRESULTMESSAGE)
      return "PrismAttackResultMessage";
  
  else if(messageEnum == MessageEnum::PRISMEXCHANGEREQUESTMESSAGE)
      return "PrismExchangeRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMRECYCLETRADEREQUESTMESSAGE)
      return "PrismRecycleTradeRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMREMOVEMESSAGE)
      return "PrismRemoveMessage";
  
  else if(messageEnum == MessageEnum::PRISMSLISTMESSAGE)
      return "PrismsListMessage";
  
  else if(messageEnum == MessageEnum::PRISMTELEPORTATIONREQUESTMESSAGE)
      return "PrismTeleportationRequestMessage";
  
  else if(messageEnum == MessageEnum::ACTIVITYHIDEREQUESTMESSAGE)
      return "ActivityHideRequestMessage";
  
  else if(messageEnum == MessageEnum::ACTIVITYLOCKREQUESTMESSAGE)
      return "ActivityLockRequestMessage";
  
  else if(messageEnum == MessageEnum::ACTIVITYSUGGESTIONSMESSAGE)
      return "ActivitySuggestionsMessage";
  
  else if(messageEnum == MessageEnum::ACTIVITYSUGGESTIONSREQUESTMESSAGE)
      return "ActivitySuggestionsRequestMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTRANKUPDATEMESSAGE)
      return "AlignmentRankUpdateMessage";
  
  else if(messageEnum == MessageEnum::SETENABLEAVAREQUESTMESSAGE)
      return "SetEnableAVARequestMessage";
  
  else if(messageEnum == MessageEnum::SETENABLEPVPREQUESTMESSAGE)
      return "SetEnablePVPRequestMessage";
  
  else if(messageEnum == MessageEnum::UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE)
      return "UpdateMapPlayersAgressableStatusMessage";
  
  else if(messageEnum == MessageEnum::UPDATESELFAGRESSABLESTATUSMESSAGE)
      return "UpdateSelfAgressableStatusMessage";
  
  else if(messageEnum == MessageEnum::CINEMATICMESSAGE)
      return "CinematicMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARADDERRORMESSAGE)
      return "ShortcutBarAddErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARADDREQUESTMESSAGE)
      return "ShortcutBarAddRequestMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARCONTENTMESSAGE)
      return "ShortcutBarContentMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREFRESHMESSAGE)
      return "ShortcutBarRefreshMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEDMESSAGE)
      return "ShortcutBarRemovedMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEERRORMESSAGE)
      return "ShortcutBarRemoveErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEREQUESTMESSAGE)
      return "ShortcutBarRemoveRequestMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREPLACEDMESSAGE)
      return "ShortcutBarReplacedMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARSWAPERRORMESSAGE)
      return "ShortcutBarSwapErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARSWAPREQUESTMESSAGE)
      return "ShortcutBarSwapRequestMessage";
  
  else if(messageEnum == MessageEnum::BULLETINMESSAGE)
      return "BulletinMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKERRORMESSAGE)
      return "ContactLookErrorMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKMESSAGE)
      return "ContactLookMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTBYIDMESSAGE)
      return "ContactLookRequestByIdMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTBYNAMEMESSAGE)
      return "ContactLookRequestByNameMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTMESSAGE)
      return "ContactLookRequestMessage";
  
  else if(messageEnum == MessageEnum::SOCIALFIGHTJOINREQUESTMESSAGE)
      return "SocialFightJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::SOCIALFIGHTLEAVEREQUESTMESSAGE)
      return "SocialFightLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::SOCIALFIGHTTAKEPLACEREQUESTMESSAGE)
      return "SocialFightTakePlaceRequestMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICEMESSAGE)
      return "SocialNoticeMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICESETERRORMESSAGE)
      return "SocialNoticeSetErrorMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICESETREQUESTMESSAGE)
      return "SocialNoticeSetRequestMessage";
  
  else if(messageEnum == MessageEnum::CONSUMEALLGAMEACTIONITEMMESSAGE)
      return "ConsumeAllGameActionItemMessage";
  
  else if(messageEnum == MessageEnum::CONSUMEGAMEACTIONITEMMESSAGE)
      return "ConsumeGameActionItemMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONITEMADDMESSAGE)
      return "GameActionItemAddMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONITEMCONSUMEDMESSAGE)
      return "GameActionItemConsumedMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONITEMLISTMESSAGE)
      return "GameActionItemListMessage";
  
  else if(messageEnum == MessageEnum::SUBSCRIPTIONLIMITATIONMESSAGE)
      return "SubscriptionLimitationMessage";
  
  else if(messageEnum == MessageEnum::SUBSCRIPTIONZONEMESSAGE)
      return "SubscriptionZoneMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERINFOREQUESTMESSAGE)
      return "SurrenderInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERINFORESPONSEMESSAGE)
      return "SurrenderInfoResponseMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERSTATEMESSAGE)
      return "SurrenderStateMessage";
  
  else if(messageEnum == MessageEnum::OPPONENTSURRENDERMESSAGE)
      return "OpponentSurrenderMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERVOTECASTMESSAGE)
      return "SurrenderVoteCastMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERVOTEENDMESSAGE)
      return "SurrenderVoteEndMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERVOTESTARTMESSAGE)
      return "SurrenderVoteStartMessage";
  
  else if(messageEnum == MessageEnum::SURRENDERVOTEUPDATEMESSAGE)
      return "SurrenderVoteUpdateMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTGAINEDMESSAGE)
      return "OrnamentGainedMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTLOSTMESSAGE)
      return "OrnamentLostMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTEDMESSAGE)
      return "OrnamentSelectedMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTERRORMESSAGE)
      return "OrnamentSelectErrorMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTREQUESTMESSAGE)
      return "OrnamentSelectRequestMessage";
  
  else if(messageEnum == MessageEnum::TITLEGAINEDMESSAGE)
      return "TitleGainedMessage";
  
  else if(messageEnum == MessageEnum::TITLELOSTMESSAGE)
      return "TitleLostMessage";
  
  else if(messageEnum == MessageEnum::TITLESANDORNAMENTSLISTMESSAGE)
      return "TitlesAndOrnamentsListMessage";
  
  else if(messageEnum == MessageEnum::TITLESANDORNAMENTSLISTREQUESTMESSAGE)
      return "TitlesAndOrnamentsListRequestMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTEDMESSAGE)
      return "TitleSelectedMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTERRORMESSAGE)
      return "TitleSelectErrorMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTREQUESTMESSAGE)
      return "TitleSelectRequestMessage";
  
  else if(messageEnum == MessageEnum::CLIENTUIOPENEDBYOBJECTMESSAGE)
      return "ClientUIOpenedByObjectMessage";
  
  else if(messageEnum == MessageEnum::CLIENTUIOPENEDMESSAGE)
      return "ClientUIOpenedMessage";
  
  else if(messageEnum == MessageEnum::PROTOCOLREQUIRED)
      return "ProtocolRequired";
  
  else if(messageEnum == MessageEnum::LOGINQUEUESTATUSMESSAGE)
      return "LoginQueueStatusMessage";
  
  else if(messageEnum == MessageEnum::QUEUESTATUSMESSAGE)
      return "QueueStatusMessage";
  
  else if(messageEnum == MessageEnum::REPORTREQUESTMESSAGE)
      return "ReportRequestMessage";
  
  else if(messageEnum == MessageEnum::REPORTRESPONSEMESSAGE)
      return "ReportResponseMessage";
  
  else if(messageEnum == MessageEnum::TRUSTSTATUSMESSAGE)
      return "TrustStatusMessage";
  
  else if(messageEnum == MessageEnum::CHECKFILEMESSAGE)
      return "CheckFileMessage";
  
  else if(messageEnum == MessageEnum::CHECKFILEREQUESTMESSAGE)
      return "CheckFileRequestMessage";
  
  else if(messageEnum == MessageEnum::CHECKINTEGRITYMESSAGE)
      return "CheckIntegrityMessage";
  
  else if(messageEnum == MessageEnum::CLIENTKEYMESSAGE)
      return "ClientKeyMessage";
  
  else if(messageEnum == MessageEnum::RAWDATAMESSAGE)
      return "RawDataMessage";
  
  else if(messageEnum == MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE)
      return "SystemMessageDisplayMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTINFORMATIONSUPDATEMESSAGE)
      return "AccountInformationsUpdateMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTSUBSCRIPTIONELAPSEDDURATIONMESSAGE)
      return "AccountSubscriptionElapsedDurationMessage";
  
  else if(messageEnum == MessageEnum::HAAPIAPIKEYMESSAGE)
      return "HaapiApiKeyMessage";
  
  else if(messageEnum == MessageEnum::HAAPIAPIKEYREQUESTMESSAGE)
      return "HaapiApiKeyRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPIAUTHERRORMESSAGE)
      return "HaapiAuthErrorMessage";
  
  else if(messageEnum == MessageEnum::HAAPIBUFFERLISTMESSAGE)
      return "HaapiBufferListMessage";
  
  else if(messageEnum == MessageEnum::HAAPIBUFFERLISTREQUESTMESSAGE)
      return "HaapiBufferListRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPIBUYVALIDATIONMESSAGE)
      return "HaapiBuyValidationMessage";
  
  else if(messageEnum == MessageEnum::HAAPICANCELBIDREQUESTMESSAGE)
      return "HaapiCancelBidRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPICONFIRMATIONMESSAGE)
      return "HaapiConfirmationMessage";
  
  else if(messageEnum == MessageEnum::HAAPICONFIRMATIONREQUESTMESSAGE)
      return "HaapiConfirmationRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPICONSUMEBUFFERREQUESTMESSAGE)
      return "HaapiConsumeBufferRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPISESSIONMESSAGE)
      return "HaapiSessionMessage";
  
  else if(messageEnum == MessageEnum::HAAPISHOPAPIKEYMESSAGE)
      return "HaapiShopApiKeyMessage";
  
  else if(messageEnum == MessageEnum::HAAPISHOPAPIKEYREQUESTMESSAGE)
      return "HaapiShopApiKeyRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPITOKENMESSAGE)
      return "HaapiTokenMessage";
  
  else if(messageEnum == MessageEnum::HAAPITOKENREQUESTMESSAGE)
      return "HaapiTokenRequestMessage";
  
  else if(messageEnum == MessageEnum::HAAPIVALIDATIONMESSAGE)
      return "HaapiValidationMessage";
  
  else if(messageEnum == MessageEnum::HAAPIVALIDATIONREQUESTMESSAGE)
      return "HaapiValidationRequestMessage";
  
  else if(messageEnum == MessageEnum::CLIENTYOUAREDRUNKMESSAGE)
      return "ClientYouAreDrunkMessage";
  
  else
  {
    qDebug()<<"ERREUR - MessageUtils - Ne connait pas l'enum :"<<(int)messageEnum;
    return "";
  }
}

