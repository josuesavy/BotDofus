#include "FightTemporaryBoostWeaponDamagesEffect.h"

void FightTemporaryBoostWeaponDamagesEffect::serialize(Writer *output)
{
  this->serializeAs_FightTemporaryBoostWeaponDamagesEffect(output);
}

void FightTemporaryBoostWeaponDamagesEffect::serializeAs_FightTemporaryBoostWeaponDamagesEffect(Writer *output)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(output);
  output->writeShort((short)this->weaponTypeId);
}

void FightTemporaryBoostWeaponDamagesEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTemporaryBoostWeaponDamagesEffect(input);
}

void FightTemporaryBoostWeaponDamagesEffect::deserializeAs_FightTemporaryBoostWeaponDamagesEffect(Reader *input)
{
  FightTemporaryBoostEffect::deserialize(input);
  this->_weaponTypeIdFunc(input);
}

void FightTemporaryBoostWeaponDamagesEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTemporaryBoostWeaponDamagesEffect(tree);
}

void FightTemporaryBoostWeaponDamagesEffect::deserializeAsyncAs_FightTemporaryBoostWeaponDamagesEffect(FuncTree tree)
{
  FightTemporaryBoostEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTemporaryBoostWeaponDamagesEffect::_weaponTypeIdFunc, this, std::placeholders::_1));
}

void FightTemporaryBoostWeaponDamagesEffect::_weaponTypeIdFunc(Reader *input)
{
  this->weaponTypeId = input->readShort();
}

FightTemporaryBoostWeaponDamagesEffect::FightTemporaryBoostWeaponDamagesEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTWEAPONDAMAGESEFFECT;
}

bool FightTemporaryBoostWeaponDamagesEffect::operator==(const FightTemporaryBoostWeaponDamagesEffect &compared)
{
  if(weaponTypeId == compared.weaponTypeId)
  return true;
  
  return false;
}

