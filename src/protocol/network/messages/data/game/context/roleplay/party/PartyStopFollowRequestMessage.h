#ifndef PARTYSTOPFOLLOWREQUESTMESSAGE_H
#define PARTYSTOPFOLLOWREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyStopFollowRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyStopFollowRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyStopFollowRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyStopFollowRequestMessage(FuncTree tree);
  PartyStopFollowRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // PARTYSTOPFOLLOWREQUESTMESSAGE_H