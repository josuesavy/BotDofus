#ifndef EXTENDEDBREACHBRANCH_H
#define EXTENDEDBREACHBRANCH_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/breach/BreachReward.h"
#include "src/Protocol/Types/Data/game/context/roleplay/breach/BreachBranch.h"
#include "src/Protocol/Types/Data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ExtendedBreachBranch : public BreachBranch
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExtendedBreachBranch(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExtendedBreachBranch(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExtendedBreachBranch(FuncTree tree);
  ExtendedBreachBranch();
  bool operator==(const ExtendedBreachBranch &compared);

  QList<BreachReward> rewards;
  int modifier;
  uint prize;

private:
  void _rewardstreeFunc(Reader *input);
  void _rewardsFunc(Reader *input);
  void _modifierFunc(Reader *input);
  void _prizeFunc(Reader *input);

  FuncTree _rewardstree;
};

#endif // EXTENDEDBREACHBRANCH_H