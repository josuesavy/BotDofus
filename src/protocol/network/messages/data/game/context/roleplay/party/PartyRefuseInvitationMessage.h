#ifndef PARTYREFUSEINVITATIONMESSAGE_H
#define PARTYREFUSEINVITATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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