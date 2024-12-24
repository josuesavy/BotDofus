#ifndef EXTENDEDLOCKEDBREACHBRANCH_H
#define EXTENDEDLOCKEDBREACHBRANCH_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/breach/ExtendedBreachBranch.h"
#include "src/protocol/network/types/data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/utils/io/type/FuncTree.h"

class ExtendedLockedBreachBranch : public ExtendedBreachBranch
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExtendedLockedBreachBranch(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExtendedLockedBreachBranch(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExtendedLockedBreachBranch(FuncTree tree);
  ExtendedLockedBreachBranch();
  bool operator==(const ExtendedLockedBreachBranch &compared);

  uint unlockPrice;

private:
  void _unlockPriceFunc(Reader *input);
};

#endif // EXTENDEDLOCKEDBREACHBRANCH_H