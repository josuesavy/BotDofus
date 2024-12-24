#ifndef QUESTOBJECTIVEINFORMATIONS_H
#define QUESTOBJECTIVEINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class QuestObjectiveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestObjectiveInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestObjectiveInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestObjectiveInformations(FuncTree tree);
  QuestObjectiveInformations();
  bool operator==(const QuestObjectiveInformations &compared);

  uint objectiveId;
  bool objectiveStatus;
  QList<QString> dialogParams;

private:
  void _objectiveIdFunc(Reader *input);
  void _objectiveStatusFunc(Reader *input);
  void _dialogParamstreeFunc(Reader *input);
  void _dialogParamsFunc(Reader *input);

  FuncTree _dialogParamstree;
};

#endif // QUESTOBJECTIVEINFORMATIONS_H