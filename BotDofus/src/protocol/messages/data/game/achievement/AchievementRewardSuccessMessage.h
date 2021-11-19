#ifndef ACHIEVEMENTREWARDSUCCESSMESSAGE_H
#define ACHIEVEMENTREWARDSUCCESSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementRewardSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementRewardSuccessMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementRewardSuccessMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementRewardSuccessMessage(FuncTree tree);
  AchievementRewardSuccessMessage();

  int achievementId;

private:
  void _achievementIdFunc(Reader *input);
};

#endif // ACHIEVEMENTREWARDSUCCESSMESSAGE_H