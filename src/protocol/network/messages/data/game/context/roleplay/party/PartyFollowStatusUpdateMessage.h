#ifndef PARTYFOLLOWSTATUSUPDATEMESSAGE_H
#define PARTYFOLLOWSTATUSUPDATEMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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