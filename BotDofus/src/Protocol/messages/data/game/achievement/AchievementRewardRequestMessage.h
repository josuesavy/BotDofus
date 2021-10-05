#ifndef ACHIEVEMENTREWARDREQUESTMESSAGE_H
#define ACHIEVEMENTREWARDREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementRewardRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementRewardRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementRewardRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementRewardRequestMessage(FuncTree tree);
  AchievementRewardRequestMessage();

  int achievementId;

private:
  void _achievementIdFunc(Reader *input);
};

#endif // ACHIEVEMENTREWARDREQUESTMESSAGE_H