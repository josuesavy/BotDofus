#ifndef QUESTSTEPINFOREQUESTMESSAGE_H
#define QUESTSTEPINFOREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class QuestStepInfoRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStepInfoRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStepInfoRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStepInfoRequestMessage(FuncTree tree);
  QuestStepInfoRequestMessage();

  uint questId;

private:
  void _questIdFunc(Reader *input);
};

#endif // QUESTSTEPINFOREQUESTMESSAGE_H