#ifndef FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H
#define FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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