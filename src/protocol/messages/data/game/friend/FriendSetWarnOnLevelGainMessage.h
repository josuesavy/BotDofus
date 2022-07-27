#ifndef FRIENDSETWARNONLEVELGAINMESSAGE_H
#define FRIENDSETWARNONLEVELGAINMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendSetWarnOnLevelGainMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendSetWarnOnLevelGainMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendSetWarnOnLevelGainMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendSetWarnOnLevelGainMessage(FuncTree tree);
  FriendSetWarnOnLevelGainMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDSETWARNONLEVELGAINMESSAGE_H