#ifndef FIGHTDETAILEDTEMPORARYBOOSTEFFECT_H
#define FIGHTDETAILEDTEMPORARYBOOSTEFFECT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/utils/io/type/FuncTree.h"

class FightDetailedTemporaryBoostEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightDetailedTemporaryBoostEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightDetailedTemporaryBoostEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightDetailedTemporaryBoostEffect(FuncTree tree);
  FightDetailedTemporaryBoostEffect();
  bool operator==(const FightDetailedTemporaryBoostEffect &compared);

  int param1;
  int param2;
  int param3;

private:
  void _param1Func(Reader *input);
  void _param2Func(Reader *input);
  void _param3Func(Reader *input);
};

#endif // FIGHTDETAILEDTEMPORARYBOOSTEFFECT_H