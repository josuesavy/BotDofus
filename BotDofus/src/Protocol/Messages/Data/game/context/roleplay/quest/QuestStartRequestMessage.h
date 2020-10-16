#ifndef QUESTSTARTREQUESTMESSAGE_H
#define QUESTSTARTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class QuestStartRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStartRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStartRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStartRequestMessage(FuncTree tree);
  QuestStartRequestMessage();

  uint questId;

private:
  void _questIdFunc(Reader *input);
};

#endif // QUESTSTARTREQUESTMESSAGE_H