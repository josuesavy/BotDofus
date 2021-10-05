#ifndef TREASUREHUNTSTEPDIG_H
#define TREASUREHUNTSTEPDIG_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TreasureHuntStepDig : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStepDig(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStepDig(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStepDig(FuncTree tree);
  TreasureHuntStepDig();
  bool operator==(const TreasureHuntStepDig &compared);
};

#endif // TREASUREHUNTSTEPDIG_H