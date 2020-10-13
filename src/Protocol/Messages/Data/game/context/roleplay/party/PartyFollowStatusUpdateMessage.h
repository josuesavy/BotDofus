#ifndef PARTYFOLLOWSTATUSUPDATEMESSAGE_H
#define PARTYFOLLOWSTATUSUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyFollowStatusUpdateMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyFollowStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyFollowStatusUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyFollowStatusUpdateMessage(FuncTree tree);
  PartyFollowStatusUpdateMessage();

  bool success;
  bool isFollowed;
  double followedId;

private:
  void deserializeByteBoxes(Reader *input);
  void _followedIdFunc(Reader *input);
};

#endif // PARTYFOLLOWSTATUSUPDATEMESSAGE_H