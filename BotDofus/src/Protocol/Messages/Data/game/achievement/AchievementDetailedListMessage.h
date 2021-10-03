#ifndef ACHIEVEMENTDETAILEDLISTMESSAGE_H
#define ACHIEVEMENTDETAILEDLISTMESSAGE_H

#include "src/protocol/types/data/game/achievement/Achievement.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementDetailedListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementDetailedListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementDetailedListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementDetailedListMessage(FuncTree tree);
  AchievementDetailedListMessage();

  QList<Achievement> startedAchievements;
  QList<Achievement> finishedAchievements;

private:
  void _startedAchievementstreeFunc(Reader *input);
  void _startedAchievementsFunc(Reader *input);
  void _finishedAchievementstreeFunc(Reader *input);
  void _finishedAchievementsFunc(Reader *input);

  FuncTree _startedAchievementstree;
  FuncTree _finishedAchievementstree;
};

#endif // ACHIEVEMENTDETAILEDLISTMESSAGE_H