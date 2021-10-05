#ifndef FRIENDSTATUSSHARESTATEMESSAGE_H
#define FRIENDSTATUSSHARESTATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendStatusShareStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendStatusShareStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendStatusShareStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendStatusShareStateMessage(FuncTree tree);
  FriendStatusShareStateMessage();

  bool share;

private:
  void _shareFunc(Reader *input);
};

#endif // FRIENDSTATUSSHARESTATEMESSAGE_H