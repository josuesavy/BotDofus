#ifndef FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H
#define FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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