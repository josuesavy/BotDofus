#ifndef PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H
#define PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationCancelledForGuestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationCancelledForGuestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationCancelledForGuestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationCancelledForGuestMessage(FuncTree tree);
  PartyInvitationCancelledForGuestMessage();

  double cancelerId;

private:
  void _cancelerIdFunc(Reader *input);
};

#endif // PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H