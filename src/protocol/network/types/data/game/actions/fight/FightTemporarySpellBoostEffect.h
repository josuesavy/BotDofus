#ifndef FIGHTTEMPORARYSPELLBOOSTEFFECT_H
#define FIGHTTEMPORARYSPELLBOOSTEFFECT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/utils/io/type/FuncTree.h"

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