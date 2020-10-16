#ifndef ACHIEVEMENTDETAILSREQUESTMESSAGE_H
#define ACHIEVEMENTDETAILSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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