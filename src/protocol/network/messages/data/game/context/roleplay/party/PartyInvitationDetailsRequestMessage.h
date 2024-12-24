#ifndef PARTYINVITATIONDETAILSREQUESTMESSAGE_H
#define PARTYINVITATIONDETAILSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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