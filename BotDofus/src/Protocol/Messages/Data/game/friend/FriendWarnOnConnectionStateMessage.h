#ifndef FRIENDWARNONCONNECTIONSTATEMESSAGE_H
#define FRIENDWARNONCONNECTIONSTATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class FriendWarnOnConnectionStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendWarnOnConnectionStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendWarnOnConnectionStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendWarnOnConnectionStateMessage(FuncTree tree);
  FriendWarnOnConnectionStateMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDWARNONCONNECTIONSTATEMESSAGE_H