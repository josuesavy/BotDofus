#ifndef TREASUREHUNTSTEP_H
#define TREASUREHUNTSTEP_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TreasureHuntStep : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStep(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStep(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStep(FuncTree tree);
  TreasureHuntStep();
  bool operator==(const TreasureHuntStep &compared);
};

#endif // TREASUREHUNTSTEP_H