#ifndef ACHIEVEMENTDETAILSMESSAGE_H
#define ACHIEVEMENTDETAILSMESSAGE_H

#include "src/protocol/network/types/data/game/achievement/Achievement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementDetailsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementDetailsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementDetailsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementDetailsMessage(FuncTree tree);
  AchievementDetailsMessage();

  Achievement achievement;

private:
  void _achievementtreeFunc(Reader *input);

  FuncTree _achievementtree;
};

#endif // ACHIEVEMENTDETAILSMESSAGE_H