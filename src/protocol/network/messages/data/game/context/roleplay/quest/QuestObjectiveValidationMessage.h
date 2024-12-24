#ifndef QUESTOBJECTIVEVALIDATIONMESSAGE_H
#define QUESTOBJECTIVEVALIDATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class QuestObjectiveValidationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestObjectiveValidationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestObjectiveValidationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestObjectiveValidationMessage(FuncTree tree);
  QuestObjectiveValidationMessage();

  uint questId;
  uint objectiveId;

private:
  void _questIdFunc(Reader *input);
  void _objectiveIdFunc(Reader *input);
};

#endif // QUESTOBJECTIVEVALIDATIONMESSAGE_H