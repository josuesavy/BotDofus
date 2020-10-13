#ifndef FINISHMOVEINFORMATIONS_H
#define FINISHMOVEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FinishMoveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FinishMoveInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FinishMoveInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FinishMoveInformations(FuncTree tree);
  FinishMoveInformations();
  bool operator==(const FinishMoveInformations &compared);

  uint finishMoveId;
  bool finishMoveState;

private:
  void _finishMoveIdFunc(Reader *input);
  void _finishMoveStateFunc(Reader *input);
};

#endif // FINISHMOVEINFORMATIONS_H