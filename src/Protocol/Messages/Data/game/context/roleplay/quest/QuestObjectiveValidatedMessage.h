#ifndef QUESTOBJECTIVEVALIDATEDMESSAGE_H
#define QUESTOBJECTIVEVALIDATEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class QuestObjectiveValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestObjectiveValidatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestObjectiveValidatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestObjectiveValidatedMessage(FuncTree tree);
  QuestObjectiveValidatedMessage();

  uint questId;
  uint objectiveId;

private:
  void _questIdFunc(Reader *input);
  void _objectiveIdFunc(Reader *input);
};

#endif // QUESTOBJECTIVEVALIDATEDMESSAGE_H