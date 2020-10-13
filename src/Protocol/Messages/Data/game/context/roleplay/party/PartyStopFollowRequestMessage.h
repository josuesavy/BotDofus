#ifndef PARTYSTOPFOLLOWREQUESTMESSAGE_H
#define PARTYSTOPFOLLOWREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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