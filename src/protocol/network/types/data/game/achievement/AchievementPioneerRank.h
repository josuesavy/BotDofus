#ifndef ACHIEVEMENTPIONEERRANK_H
#define ACHIEVEMENTPIONEERRANK_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class AchievementPioneerRank : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementPioneerRank(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementPioneerRank(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementPioneerRank(FuncTree tree);
  AchievementPioneerRank();
  bool operator==(const AchievementPioneerRank &compared);

  uint achievementId;
  uint pioneerRank;

private:
  void _achievementIdFunc(Reader *input);
  void _pioneerRankFunc(Reader *input);
};

#endif // ACHIEVEMENTPIONEERRANK_H