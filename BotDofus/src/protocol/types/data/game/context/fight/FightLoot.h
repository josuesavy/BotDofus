#ifndef FIGHTLOOT_H
#define FIGHTLOOT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightLootObject.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightLoot : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightLoot(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightLoot(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightLoot(FuncTree tree);
  FightLoot();
  bool operator==(const FightLoot &compared);

  QList<FightLootObject> objects;
  double kamas;

private:
  void _objectstreeFunc(Reader *input);
  void _objectsFunc(Reader *input);
  void _kamasFunc(Reader *input);

  FuncTree _objectstree;
};

#endif // FIGHTLOOT_H