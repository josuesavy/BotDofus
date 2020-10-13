#ifndef ACHIEVEMENTACHIEVEDREWARDABLE_H
#define ACHIEVEMENTACHIEVEDREWARDABLE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/achievement/AchievementAchieved.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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

  uint finishedlevel;

private:
  void _finishedlevelFunc(Reader *input);
};

#endif // ACHIEVEMENTACHIEVEDREWARDABLE_H