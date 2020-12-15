#ifndef PARTYACCEPTINVITATIONMESSAGE_H
#define PARTYACCEPTINVITATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyAcceptInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyAcceptInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyAcceptInvitationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyAcceptInvitationMessage(FuncTree tree);
  PartyAcceptInvitationMessage();
};

#endif // PARTYACCEPTINVITATIONMESSAGE_H