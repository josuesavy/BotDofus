#ifndef FRIENDADDFAILUREMESSAGE_H
#define FRIENDADDFAILUREMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendAddFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendAddFailureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendAddFailureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendAddFailureMessage(FuncTree tree);
  FriendAddFailureMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // FRIENDADDFAILUREMESSAGE_H