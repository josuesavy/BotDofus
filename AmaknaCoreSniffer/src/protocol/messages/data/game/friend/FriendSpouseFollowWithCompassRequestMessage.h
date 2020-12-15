#ifndef FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H
#define FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendSpouseFollowWithCompassRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSpouseFollowWithCompassRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSpouseFollowWithCompassRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSpouseFollowWithCompassRequestMessage(FuncTree tree);
  FriendSpouseFollowWithCompassRequestMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE_H