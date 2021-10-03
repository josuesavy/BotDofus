#ifndef ACHIEVEMENTSTARTEDOBJECTIVE_H
#define ACHIEVEMENTSTARTEDOBJECTIVE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/achievement/AchievementObjective.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

  uint value;

private:
  void _valueFunc(Reader *input);
};

#endif // ACHIEVEMENTSTARTEDOBJECTIVE_H