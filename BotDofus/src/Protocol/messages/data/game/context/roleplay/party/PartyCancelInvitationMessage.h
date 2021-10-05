#ifndef PARTYCANCELINVITATIONMESSAGE_H
#define PARTYCANCELINVITATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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