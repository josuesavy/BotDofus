#ifndef TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H
#define TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TreasureHuntStepFollowDirectionToPOI : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStepFollowDirectionToPOI(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStepFollowDirectionToPOI(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStepFollowDirectionToPOI(FuncTree tree);
  TreasureHuntStepFollowDirectionToPOI();
  bool operator==(const TreasureHuntStepFollowDirectionToPOI &compared);

  uint direction;
  uint poiLabelId;

private:
  void _directionFunc(Reader *input);
  void _poiLabelIdFunc(Reader *input);
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H