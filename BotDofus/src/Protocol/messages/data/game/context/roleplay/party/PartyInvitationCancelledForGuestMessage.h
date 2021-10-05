#ifndef PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H
#define PARTYINVITATIONCANCELLEDFORGUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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