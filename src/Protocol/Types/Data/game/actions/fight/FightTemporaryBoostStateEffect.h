#ifndef FIGHTTEMPORARYBOOSTSTATEEFFECT_H
#define FIGHTTEMPORARYBOOSTSTATEEFFECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightTemporaryBoostStateEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTemporaryBoostStateEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTemporaryBoostStateEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTemporaryBoostStateEffect(FuncTree tree);
  FightTemporaryBoostStateEffect();
  bool operator==(const FightTemporaryBoostStateEffect &compared);

  int stateId;

private:
  void _stateIdFunc(Reader *input);
};

#endif // FIGHTTEMPORARYBOOSTSTATEEFFECT_H