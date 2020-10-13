#ifndef ACHIEVEMENTFINISHEDMESSAGE_H
#define ACHIEVEMENTFINISHEDMESSAGE_H

#include "src/Protocol/Types/Data/game/achievement/AchievementAchievedRewardable.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AchievementFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementFinishedMessage(FuncTree tree);
  AchievementFinishedMessage();

  QSharedPointer<AchievementAchievedRewardable> achievement;

private:
  void _achievementtreeFunc(Reader *input);

  FuncTree _achievementtree;
};

#endif // ACHIEVEMENTFINISHEDMESSAGE_H