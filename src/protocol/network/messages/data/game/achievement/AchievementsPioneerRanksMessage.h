#ifndef ACHIEVEMENTSPIONEERRANKSMESSAGE_H
#define ACHIEVEMENTSPIONEERRANKSMESSAGE_H

#include "src/protocol/network/types/data/game/achievement/AchievementPioneerRank.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementsPioneerRanksMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementsPioneerRanksMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementsPioneerRanksMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementsPioneerRanksMessage(FuncTree tree);
  AchievementsPioneerRanksMessage();

  QList<AchievementPioneerRank> achievementsPioneerRanks;

private:
  void _achievementsPioneerRankstreeFunc(Reader *input);
  void _achievementsPioneerRanksFunc(Reader *input);

  FuncTree _achievementsPioneerRankstree;
};

#endif // ACHIEVEMENTSPIONEERRANKSMESSAGE_H