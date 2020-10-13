#ifndef FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H
#define FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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