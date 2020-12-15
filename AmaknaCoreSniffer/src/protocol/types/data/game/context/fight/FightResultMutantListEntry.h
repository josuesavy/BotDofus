#ifndef FIGHTRESULTMUTANTLISTENTRY_H
#define FIGHTRESULTMUTANTLISTENTRY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightResultMutantListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultMutantListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultMutantListEntry(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultMutantListEntry(FuncTree tree);
  FightResultMutantListEntry();
  bool operator==(const FightResultMutantListEntry &compared);

  uint level;

private:
  void _levelFunc(Reader *input);
};

#endif // FIGHTRESULTMUTANTLISTENTRY_H