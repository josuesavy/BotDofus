#ifndef ACHIEVEMENTSTARTEDOBJECTIVE_H
#define ACHIEVEMENTSTARTEDOBJECTIVE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/achievement/AchievementObjective.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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