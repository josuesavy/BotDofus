#ifndef ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H
#define ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H

#include "src/Protocol/Types/Data/game/achievement/AchievementAchievedRewardable.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/achievement/AchievementFinishedMessage.h"

class AchievementFinishedInformationMessage : public AchievementFinishedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementFinishedInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementFinishedInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementFinishedInformationMessage(FuncTree tree);
  AchievementFinishedInformationMessage();

  QString name;
  double playerId;

private:
  void _nameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H