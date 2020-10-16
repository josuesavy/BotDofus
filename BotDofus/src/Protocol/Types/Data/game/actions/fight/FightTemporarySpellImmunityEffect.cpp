#include "FightTemporarySpellImmunityEffect.h"

void FightTemporarySpellImmunityEffect::serialize(Writer *output)
{
  this->serializeAs_FightTemporarySpellImmunityEffect(output);
}

void FightTemporarySpellImmunityEffect::serializeAs_FightTemporarySpellImmunityEffect(Writer *output)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(output);
  output->writeInt((int)this->immuneSpellId);
}

void FightTemporarySpellImmunityEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTemporarySpellImmunityEffect(input);
}

void FightTemporarySpellImmunityEffect::deserializeAs_FightTemporarySpellImmunityEffect(Reader *input)
{
  AbstractFightDispellableEffect::deserialize(input);
  this->_immuneSpellIdFunc(input);
}

void FightTemporarySpellImmunityEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTemporarySpellImmunityEffect(tree);
}

void FightTemporarySpellImmunityEffect::deserializeAsyncAs_FightTemporarySpellImmunityEffect(FuncTree tree)
{
  AbstractFightDispellableEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTemporarySpellImmunityEffect::_immuneSpellIdFunc, this, std::placeholders::_1));
}

void FightTemporarySpellImmunityEffect::_immuneSpellIdFunc(Reader *input)
{
  this->immuneSpellId = input->readInt();
}

FightTemporarySpellImmunityEffect::FightTemporarySpellImmunityEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYSPELLIMMUNITYEFFECT;
}

bool FightTemporarySpellImmunityEffect::operator==(const FightTemporarySpellImmunityEffect &compared)
{
  if(immuneSpellId == compared.immuneSpellId)
  return true;
  
  return false;
}

