#ifndef QUESTVALIDATEDMESSAGE_H
#define QUESTVALIDATEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class QuestValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestValidatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestValidatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestValidatedMessage(FuncTree tree);
  QuestValidatedMessage();

  uint questId;

private:
  void _questIdFunc(Reader *input);
};

#endif // QUESTVALIDATEDMESSAGE_H