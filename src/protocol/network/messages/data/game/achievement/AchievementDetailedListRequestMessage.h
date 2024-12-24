#ifndef ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H
#define ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AchievementDetailedListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementDetailedListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementDetailedListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementDetailedListRequestMessage(FuncTree tree);
  AchievementDetailedListRequestMessage();

  uint categoryId;

private:
  void _categoryIdFunc(Reader *input);
};

#endif // ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE_H