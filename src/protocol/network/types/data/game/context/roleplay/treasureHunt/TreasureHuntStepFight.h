#ifndef TREASUREHUNTSTEPFIGHT_H
#define TREASUREHUNTSTEPFIGHT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/utils/io/type/FuncTree.h"

class TreasureHuntStepFight : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStepFight(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStepFight(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStepFight(FuncTree tree);
  TreasureHuntStepFight();
  bool operator==(const TreasureHuntStepFight &compared);
};

#endif // TREASUREHUNTSTEPFIGHT_H