#ifndef FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H
#define FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/utils/io/type/FuncTree.h"

class FightTemporaryBoostWeaponDamagesEffect : public FightTemporaryBoostEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTemporaryBoostWeaponDamagesEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTemporaryBoostWeaponDamagesEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTemporaryBoostWeaponDamagesEffect(FuncTree tree);
  FightTemporaryBoostWeaponDamagesEffect();
  bool operator==(const FightTemporaryBoostWeaponDamagesEffect &compared);

  int weaponTypeId;

private:
  void _weaponTypeIdFunc(Reader *input);
};

#endif // FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H