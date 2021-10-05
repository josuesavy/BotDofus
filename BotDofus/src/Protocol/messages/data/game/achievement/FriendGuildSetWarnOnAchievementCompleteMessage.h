#ifndef FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H
#define FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class FriendGuildSetWarnOnAchievementCompleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendGuildSetWarnOnAchievementCompleteMessage(FuncTree tree);
  FriendGuildSetWarnOnAchievementCompleteMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H