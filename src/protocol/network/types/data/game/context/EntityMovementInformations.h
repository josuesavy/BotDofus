#ifndef ENTITYMOVEMENTINFORMATIONS_H
#define ENTITYMOVEMENTINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class EntityMovementInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityMovementInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityMovementInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityMovementInformations(FuncTree tree);
  EntityMovementInformations();
  bool operator==(const EntityMovementInformations &compared);

  int id;
  QList<int> steps;

private:
  void _idFunc(Reader *input);
  void _stepstreeFunc(Reader *input);
  void _stepsFunc(Reader *input);

  FuncTree _stepstree;
};

#endif // ENTITYMOVEMENTINFORMATIONS_H