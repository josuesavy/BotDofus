#ifndef ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTREQUESTMESSAGE_H
#define ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AchievementAlmostFinishedDetailedListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementAlmostFinishedDetailedListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementAlmostFinishedDetailedListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementAlmostFinishedDetailedListRequestMessage(FuncTree tree);
  AchievementAlmostFinishedDetailedListRequestMessage();
};

#endif // ACHIEVEMENTALMOSTFINISHEDDETAILEDLISTREQUESTMESSAGE_H