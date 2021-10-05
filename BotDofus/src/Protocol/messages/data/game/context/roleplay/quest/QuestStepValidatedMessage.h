#ifndef QUESTSTEPVALIDATEDMESSAGE_H
#define QUESTSTEPVALIDATEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class QuestStepValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStepValidatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStepValidatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStepValidatedMessage(FuncTree tree);
  QuestStepValidatedMessage();

  uint questId;
  uint stepId;

private:
  void _questIdFunc(Reader *input);
  void _stepIdFunc(Reader *input);
};

#endif // QUESTSTEPVALIDATEDMESSAGE_H