#ifndef FRIENDSETSTATUSSHAREMESSAGE_H
#define FRIENDSETSTATUSSHAREMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendSetStatusShareMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSetStatusShareMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSetStatusShareMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSetStatusShareMessage(FuncTree tree);
  FriendSetStatusShareMessage();

  bool share;

private:
  void _shareFunc(Reader *input);
};

#endif // FRIENDSETSTATUSSHAREMESSAGE_H