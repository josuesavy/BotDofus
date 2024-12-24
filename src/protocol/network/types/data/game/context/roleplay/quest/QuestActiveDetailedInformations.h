#ifndef QUESTACTIVEDETAILEDINFORMATIONS_H
#define QUESTACTIVEDETAILEDINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class QuestActiveDetailedInformations : public QuestActiveInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestActiveDetailedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestActiveDetailedInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestActiveDetailedInformations(FuncTree tree);
  QuestActiveDetailedInformations();
  bool operator==(const QuestActiveDetailedInformations &compared);

  uint stepId;
  QList<QSharedPointer<QuestObjectiveInformations>> objectives;

private:
  void _stepIdFunc(Reader *input);
  void _objectivestreeFunc(Reader *input);
  void _objectivesFunc(Reader *input);

  FuncTree _objectivestree;
};

#endif // QUESTACTIVEDETAILEDINFORMATIONS_H