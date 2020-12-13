#ifndef ACHIEVEMENTLISTMESSAGE_H
#define ACHIEVEMENTLISTMESSAGE_H

#include "src/protocol/types/data/game/achievement/AchievementAchieved.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

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