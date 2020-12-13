#ifndef PARTYINVITATIONMESSAGE_H
#define PARTYINVITATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationMessage(FuncTree tree);
  PartyInvitationMessage();

  uint partyType;
  QString partyName;
  uint maxParticipants;
  double fromId;
  QString fromName;
  double toId;

private:
  void _partyTypeFunc(Reader *input);
  void _partyNameFunc(Reader *input);
  void _maxParticipantsFunc(Reader *input);
  void _fromIdFunc(Reader *input);
  void _fromNameFunc(Reader *input);
  void _toIdFunc(Reader *input);
};

#endif // PARTYINVITATIONMESSAGE_H