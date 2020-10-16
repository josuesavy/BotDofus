#ifndef TREASUREHUNTSTEPFOLLOWDIRECTION_H
#define TREASUREHUNTSTEPFOLLOWDIRECTION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TreasureHuntStepFollowDirection : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStepFollowDirection(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStepFollowDirection(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStepFollowDirection(FuncTree tree);
  TreasureHuntStepFollowDirection();
  bool operator==(const TreasureHuntStepFollowDirection &compared);

  uint direction;
  uint mapCount;

private:
  void _directionFunc(Reader *input);
  void _mapCountFunc(Reader *input);
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTION_H