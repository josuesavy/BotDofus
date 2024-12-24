#ifndef ACHIEVEMENTACHIEVED_H
#define ACHIEVEMENTACHIEVED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

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
  uint achievedPioneerRank;

private:
  void _idFunc(Reader *input);
  void _achievedByFunc(Reader *input);
  void _achievedPioneerRankFunc(Reader *input);
};

#endif // ACHIEVEMENTACHIEVED_H