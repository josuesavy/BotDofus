#ifndef PARTYREFUSEINVITATIONMESSAGE_H
#define PARTYREFUSEINVITATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyRefuseInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyRefuseInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyRefuseInvitationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyRefuseInvitationMessage(FuncTree tree);
  PartyRefuseInvitationMessage();
};

#endif // PARTYREFUSEINVITATIONMESSAGE_H