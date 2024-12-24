#ifndef ACHIEVEMENTACHIEVEDREWARDABLE_H
#define ACHIEVEMENTACHIEVEDREWARDABLE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/achievement/AchievementAchieved.h"
#include "src/utils/io/type/FuncTree.h"

class AchievementAchievedRewardable : public AchievementAchieved
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementAchievedRewardable(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementAchievedRewardable(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementAchievedRewardable(FuncTree tree);
  AchievementAchievedRewardable();
  bool operator==(const AchievementAchievedRewardable &compared);

  uint finishedLevel;

private:
  void _finishedLevelFunc(Reader *input);
};

#endif // ACHIEVEMENTACHIEVEDREWARDABLE_H