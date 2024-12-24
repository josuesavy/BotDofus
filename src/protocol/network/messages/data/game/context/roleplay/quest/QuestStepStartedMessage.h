#ifndef QUESTSTEPSTARTEDMESSAGE_H
#define QUESTSTEPSTARTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class QuestStepStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestStepStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestStepStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestStepStartedMessage(FuncTree tree);
  QuestStepStartedMessage();

  uint questId;
  uint stepId;

private:
  void _questIdFunc(Reader *input);
  void _stepIdFunc(Reader *input);
};

#endif // QUESTSTEPSTARTEDMESSAGE_H