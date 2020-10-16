#ifndef PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H
#define PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

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