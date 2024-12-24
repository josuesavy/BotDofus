#ifndef FRIENDDELETERESULTMESSAGE_H
#define FRIENDDELETERESULTMESSAGE_H

#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendDeleteResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendDeleteResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendDeleteResultMessage(FuncTree tree);
  FriendDeleteResultMessage();

  bool success;
  AccountTagInformation tag;

private:
  void _successFunc(Reader *input);
  void _tagtreeFunc(Reader *input);

  FuncTree _tagtree;
};

#endif // FRIENDDELETERESULTMESSAGE_H