#ifndef QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H
#define QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class QuestObjectiveInformationsWithCompletion : public QuestObjectiveInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestObjectiveInformationsWithCompletion(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestObjectiveInformationsWithCompletion(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestObjectiveInformationsWithCompletion(FuncTree tree);
  QuestObjectiveInformationsWithCompletion();
  bool operator==(const QuestObjectiveInformationsWithCompletion &compared);

  uint curCompletion;
  uint maxCompletion;

private:
  void _curCompletionFunc(Reader *input);
  void _maxCompletionFunc(Reader *input);
};

#endif // QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H