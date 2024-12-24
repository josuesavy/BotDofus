#ifndef STOPGUILDCHESTCONTRIBUTIONMESSAGE_H
#define STOPGUILDCHESTCONTRIBUTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopGuildChestContributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopGuildChestContributionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopGuildChestContributionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopGuildChestContributionMessage(FuncTree tree);
  StopGuildChestContributionMessage();
};

#endif // STOPGUILDCHESTCONTRIBUTIONMESSAGE_H