#ifndef FRIENDWARNONLEVELGAINSTATEMESSAGE_H
#define FRIENDWARNONLEVELGAINSTATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendWarnOnLevelGainStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendWarnOnLevelGainStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendWarnOnLevelGainStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendWarnOnLevelGainStateMessage(FuncTree tree);
  FriendWarnOnLevelGainStateMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDWARNONLEVELGAINSTATEMESSAGE_H