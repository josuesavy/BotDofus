#ifndef FIGHTRESULTLISTENTRY_H
#define FIGHTRESULTLISTENTRY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightLoot.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightResultListEntry : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultListEntry(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultListEntry(FuncTree tree);
  FightResultListEntry();
  bool operator==(const FightResultListEntry &compared);

  uint outcome;
  uint wave;
  FightLoot rewards;

private:
  void _outcomeFunc(Reader *input);
  void _waveFunc(Reader *input);
  void _rewardstreeFunc(Reader *input);

  FuncTree _rewardstree;
};

#endif // FIGHTRESULTLISTENTRY_H