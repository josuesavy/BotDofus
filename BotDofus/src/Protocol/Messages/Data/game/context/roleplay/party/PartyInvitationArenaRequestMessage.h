#ifndef PARTYINVITATIONARENAREQUESTMESSAGE_H
#define PARTYINVITATIONARENAREQUESTMESSAGE_H

#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/PartyInvitationRequestMessage.h"

class PartyInvitationArenaRequestMessage : public PartyInvitationRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationArenaRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationArenaRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationArenaRequestMessage(FuncTree tree);
  PartyInvitationArenaRequestMessage();
};

#endif // PARTYINVITATIONARENAREQUESTMESSAGE_H