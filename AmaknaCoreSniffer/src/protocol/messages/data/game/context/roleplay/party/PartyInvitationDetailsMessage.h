#ifndef PARTYINVITATIONDETAILSMESSAGE_H
#define PARTYINVITATIONDETAILSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationDetailsMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationDetailsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationDetailsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationDetailsMessage(FuncTree tree);
  PartyInvitationDetailsMessage();

  uint partyType;
  QString partyName;
  double fromId;
  QString fromName;
  double leaderId;
  QList<QSharedPointer<PartyInvitationMemberInformations>> members;
  QList<QSharedPointer<PartyGuestInformations>> guests;

private:
  void _partyTypeFunc(Reader *input);
  void _partyNameFunc(Reader *input);
  void _fromIdFunc(Reader *input);
  void _fromNameFunc(Reader *input);
  void _leaderIdFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);
  void _gueststreeFunc(Reader *input);
  void _guestsFunc(Reader *input);

  FuncTree _memberstree;
  FuncTree _gueststree;
};

#endif // PARTYINVITATIONDETAILSMESSAGE_H