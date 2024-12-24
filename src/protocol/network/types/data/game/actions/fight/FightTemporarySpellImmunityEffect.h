#ifndef FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H
#define FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/utils/io/type/FuncTree.h"

class FightTemporarySpellImmunityEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTemporarySpellImmunityEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTemporarySpellImmunityEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTemporarySpellImmunityEffect(FuncTree tree);
  FightTemporarySpellImmunityEffect();
  bool operator==(const FightTemporarySpellImmunityEffect &compared);

  int immuneSpellId;

private:
  void _immuneSpellIdFunc(Reader *input);
};

#endif // FIGHTTEMPORARYSPELLIMMUNITYEFFECT_H