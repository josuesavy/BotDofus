#ifndef FRIENDDELETEREQUESTMESSAGE_H
#define FRIENDDELETEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendDeleteRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendDeleteRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendDeleteRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendDeleteRequestMessage(FuncTree tree);
  FriendDeleteRequestMessage();

  uint accountId;

private:
  void _accountIdFunc(Reader *input);
};

#endif // FRIENDDELETEREQUESTMESSAGE_H