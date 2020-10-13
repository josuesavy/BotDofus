#ifndef FIGHTRESULTFIGHTERLISTENTRY_H
#define FIGHTRESULTFIGHTERLISTENTRY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultListEntry.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightResultFighterListEntry : public FightResultListEntry
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultFighterListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultFighterListEntry(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultFighterListEntry(FuncTree tree);
  FightResultFighterListEntry();
  bool operator==(const FightResultFighterListEntry &compared);

  double id;
  bool alive;

private:
  void _idFunc(Reader *input);
  void _aliveFunc(Reader *input);
};

#endif // FIGHTRESULTFIGHTERLISTENTRY_H