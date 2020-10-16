#ifndef ACHIEVEMENTACHIEVED_H
#define ACHIEVEMENTACHIEVED_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AchievementAchieved : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementAchieved(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementAchieved(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementAchieved(FuncTree tree);
  AchievementAchieved();
  bool operator==(const AchievementAchieved &compared);

  uint id;
  double achievedBy;

private:
  void _idFunc(Reader *input);
  void _achievedByFunc(Reader *input);
};

#endif // ACHIEVEMENTACHIEVED_H