#ifndef FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H
#define FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FriendGuildWarnOnAchievementCompleteStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FriendGuildWarnOnAchievementCompleteStateMessage(FuncTree tree);
  FriendGuildWarnOnAchievementCompleteStateMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H