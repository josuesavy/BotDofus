#ifndef PARTYINVITATIONDETAILSREQUESTMESSAGE_H
#define PARTYINVITATIONDETAILSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationDetailsRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationDetailsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationDetailsRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationDetailsRequestMessage(FuncTree tree);
  PartyInvitationDetailsRequestMessage();
};

#endif // PARTYINVITATIONDETAILSREQUESTMESSAGE_H