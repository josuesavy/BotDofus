#ifndef ACHIEVEMENTDETAILSREQUESTMESSAGE_H
#define ACHIEVEMENTDETAILSREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementDetailsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementDetailsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementDetailsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementDetailsRequestMessage(FuncTree tree);
  AchievementDetailsRequestMessage();

  uint achievementId;

private:
  void _achievementIdFunc(Reader *input);
};

#endif // ACHIEVEMENTDETAILSREQUESTMESSAGE_H