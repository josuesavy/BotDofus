#ifndef FIGHTTEMPORARYSPELLBOOSTEFFECT_H
#define FIGHTTEMPORARYSPELLBOOSTEFFECT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightTemporarySpellBoostEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTemporarySpellBoostEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTemporarySpellBoostEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTemporarySpellBoostEffect(FuncTree tree);
  FightTemporarySpellBoostEffect();
  bool operator==(const FightTemporarySpellBoostEffect &compared);

  uint boostedSpellId;

private:
  void _boostedSpellIdFunc(Reader *input);
};

#endif // FIGHTTEMPORARYSPELLBOOSTEFFECT_H