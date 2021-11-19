#ifndef ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE_H
#define ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE_H

#include "src/protocol/types/data/game/achievement/Achievement.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementAlmostFinishedDetailedListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementAlmostFinishedDetailedListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementAlmostFinishedDetailedListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementAlmostFinishedDetailedListMessage(FuncTree tree);
  AchievementAlmostFinishedDetailedListMessage();

  QList<Achievement> almostFinishedAchievements;

private:
  void _almostFinishedAchievementstreeFunc(Reader *input);
  void _almostFinishedAchievementsFunc(Reader *input);

  FuncTree _almostFinishedAchievementstree;
};

#endif // ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE_H