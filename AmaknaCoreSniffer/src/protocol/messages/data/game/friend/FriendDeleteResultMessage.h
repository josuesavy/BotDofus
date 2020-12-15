#ifndef FRIENDDELETERESULTMESSAGE_H
#define FRIENDDELETERESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  QString name;

private:
  void _successFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // FRIENDDELETERESULTMESSAGE_H