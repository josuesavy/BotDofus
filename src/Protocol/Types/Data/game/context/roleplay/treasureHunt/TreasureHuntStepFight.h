#ifndef TREASUREHUNTSTEPFIGHT_H
#define TREASUREHUNTSTEPFIGHT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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