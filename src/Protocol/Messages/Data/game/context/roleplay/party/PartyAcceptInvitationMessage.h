#ifndef PARTYACCEPTINVITATIONMESSAGE_H
#define PARTYACCEPTINVITATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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