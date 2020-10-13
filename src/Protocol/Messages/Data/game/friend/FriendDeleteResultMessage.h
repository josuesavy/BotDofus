#ifndef FRIENDDELETERESULTMESSAGE_H
#define FRIENDDELETERESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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