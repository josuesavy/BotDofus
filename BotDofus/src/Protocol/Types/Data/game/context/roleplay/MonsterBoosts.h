#ifndef MONSTERBOOSTS_H
#define MONSTERBOOSTS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class MonsterBoosts : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MonsterBoosts(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MonsterBoosts(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MonsterBoosts(FuncTree tree);
  MonsterBoosts();
  bool operator==(const MonsterBoosts &compared);

  uint id;
  uint xpBoost;
  uint dropBoost;

private:
  void _idFunc(Reader *input);
  void _xpBoostFunc(Reader *input);
  void _dropBoostFunc(Reader *input);
};

#endif // MONSTERBOOSTS_H