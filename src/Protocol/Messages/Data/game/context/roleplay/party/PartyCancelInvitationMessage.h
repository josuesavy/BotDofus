#ifndef PARTYCANCELINVITATIONMESSAGE_H
#define PARTYCANCELINVITATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyCancelInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyCancelInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyCancelInvitationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyCancelInvitationMessage(FuncTree tree);
  PartyCancelInvitationMessage();

  double guestId;

private:
  void _guestIdFunc(Reader *input);
};

#endif // PARTYCANCELINVITATIONMESSAGE_H