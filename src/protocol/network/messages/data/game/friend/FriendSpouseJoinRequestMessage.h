#ifndef FRIENDSPOUSEJOINREQUESTMESSAGE_H
#define FRIENDSPOUSEJOINREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendSpouseJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSpouseJoinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSpouseJoinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSpouseJoinRequestMessage(FuncTree tree);
  FriendSpouseJoinRequestMessage();
};

#endif // FRIENDSPOUSEJOINREQUESTMESSAGE_H