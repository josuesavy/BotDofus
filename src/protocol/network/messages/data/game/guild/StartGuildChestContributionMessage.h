#ifndef STARTGUILDCHESTCONTRIBUTIONMESSAGE_H
#define STARTGUILDCHESTCONTRIBUTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StartGuildChestContributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartGuildChestContributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartGuildChestContributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartGuildChestContributionMessage(FuncTree tree);
  StartGuildChestContributionMessage();
};

#endif // STARTGUILDCHESTCONTRIBUTIONMESSAGE_H