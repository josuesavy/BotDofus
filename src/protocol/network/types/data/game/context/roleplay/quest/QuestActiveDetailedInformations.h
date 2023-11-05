#ifndef QUESTACTIVEDETAILEDINFORMATIONS_H
#define QUESTACTIVEDETAILEDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
  QList<> objectives;

private:
  void _stepIdFunc(Reader *input);
  void _objectivestreeFunc(Reader *input);
  void _objectivesFunc(Reader *input);

  FuncTree _objectivestree;
};

#endif // QUESTACTIVEDETAILEDINFORMATIONS_H