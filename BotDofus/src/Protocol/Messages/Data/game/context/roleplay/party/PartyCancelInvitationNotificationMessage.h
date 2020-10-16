#ifndef PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H
#define PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyCancelInvitationNotificationMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyCancelInvitationNotificationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyCancelInvitationNotificationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyCancelInvitationNotificationMessage(FuncTree tree);
  PartyCancelInvitationNotificationMessage();

  double cancelerId;
  double guestId;

private:
  void _cancelerIdFunc(Reader *input);
  void _guestIdFunc(Reader *input);
};

#endif // PARTYCANCELINVITATIONNOTIFICATIONMESSAGE_H