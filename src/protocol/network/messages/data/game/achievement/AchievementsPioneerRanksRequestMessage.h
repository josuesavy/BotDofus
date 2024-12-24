#ifndef ACHIEVEMENTSPIONEERRANKSREQUESTMESSAGE_H
#define ACHIEVEMENTSPIONEERRANKSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementsPioneerRanksRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementsPioneerRanksRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementsPioneerRanksRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementsPioneerRanksRequestMessage(FuncTree tree);
  AchievementsPioneerRanksRequestMessage();
};

#endif // ACHIEVEMENTSPIONEERRANKSREQUESTMESSAGE_H