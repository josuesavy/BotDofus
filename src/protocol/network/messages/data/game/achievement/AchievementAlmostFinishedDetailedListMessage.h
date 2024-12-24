#ifndef ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE_H
#define ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTMESSAGE_H

#include "src/protocol/network/types/data/game/achievement/Achievement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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