#ifndef TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H
#define TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TreasureHuntStepFollowDirectionToHint : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntStepFollowDirectionToHint(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntStepFollowDirectionToHint(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntStepFollowDirectionToHint(FuncTree tree);
  TreasureHuntStepFollowDirectionToHint();
  bool operator==(const TreasureHuntStepFollowDirectionToHint &compared);

  uint direction;
  uint npcId;

private:
  void _directionFunc(Reader *input);
  void _npcIdFunc(Reader *input);
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H