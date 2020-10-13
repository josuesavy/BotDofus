#ifndef QUESTSTARTEDMESSAGE_H
#define QUESTSTARTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class QuestStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStartedMessage(FuncTree tree);
  QuestStartedMessage();

  uint questId;

private:
  void _questIdFunc(Reader *input);
};

#endif // QUESTSTARTEDMESSAGE_H