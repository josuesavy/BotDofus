#ifndef PARTYINVITATIONARENAREQUESTMESSAGE_H
#define PARTYINVITATIONARENAREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyInvitationRequestMessage.h"

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