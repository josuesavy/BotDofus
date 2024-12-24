#ifndef ACHIEVEMENTSTARTEDOBJECTIVE_H
#define ACHIEVEMENTSTARTEDOBJECTIVE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/achievement/AchievementObjective.h"
#include "src/utils/io/type/FuncTree.h"

class AchievementStartedObjective : public AchievementObjective
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementStartedObjective(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementStartedObjective(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementStartedObjective(FuncTree tree);
  AchievementStartedObjective();
  bool operator==(const AchievementStartedObjective &compared);

  double value;

private:
  void _valueFunc(Reader *input);
};

#endif // ACHIEVEMENTSTARTEDOBJECTIVE_H