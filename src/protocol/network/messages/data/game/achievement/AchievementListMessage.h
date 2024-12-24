#ifndef ACHIEVEMENTLISTMESSAGE_H
#define ACHIEVEMENTLISTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/achievement/AchievementAchieved.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementListMessage(FuncTree tree);
  AchievementListMessage();

  QList<QSharedPointer<AchievementAchieved>> finishedAchievements;

private:
  void _finishedAchievementstreeFunc(Reader *input);
  void _finishedAchievementsFunc(Reader *input);

  FuncTree _finishedAchievementstree;
};

#endif // ACHIEVEMENTLISTMESSAGE_H