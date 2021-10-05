#ifndef ENTITYDISPOSITIONINFORMATIONS_H
#define ENTITYDISPOSITIONINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class EntityDispositionInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityDispositionInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityDispositionInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityDispositionInformations(FuncTree tree);
  EntityDispositionInformations();
  bool operator==(const EntityDispositionInformations &compared);

  int cellId;
  uint direction;

private:
  void _cellIdFunc(Reader *input);
  void _directionFunc(Reader *input);
};

#endif // ENTITYDISPOSITIONINFORMATIONS_H