#ifndef PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H
#define PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyRefuseInvitationNotificationMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyRefuseInvitationNotificationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyRefuseInvitationNotificationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyRefuseInvitationNotificationMessage(FuncTree tree);
  PartyRefuseInvitationNotificationMessage();

  double guestId;

private:
  void _guestIdFunc(Reader *input);
};

#endif // PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H