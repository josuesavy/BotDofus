#ifndef ACHIEVEMENTREWARDERRORMESSAGE_H
#define ACHIEVEMENTREWARDERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementRewardErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementRewardErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementRewardErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementRewardErrorMessage(FuncTree tree);
  AchievementRewardErrorMessage();

  int achievementId;

private:
  void _achievementIdFunc(Reader *input);
};

#endif // ACHIEVEMENTREWARDERRORMESSAGE_H