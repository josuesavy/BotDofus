#include "FightTemporaryBoostEffect.h"

void FightTemporaryBoostEffect::serialize(Writer *output)
{
  this->serializeAs_FightTemporaryBoostEffect(output);
}

void FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(Writer *output)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(output);
  output->writeInt((int)this->delta);
}

void FightTemporaryBoostEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTemporaryBoostEffect(input);
}

void FightTemporaryBoostEffect::deserializeAs_FightTemporaryBoostEffect(Reader *input)
{
  AbstractFightDispellableEffect::deserialize(input);
  this->_deltaFunc(input);
}

void FightTemporaryBoostEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTemporaryBoostEffect(tree);
}

void FightTemporaryBoostEffect::deserializeAsyncAs_FightTemporaryBoostEffect(FuncTree tree)
{
  AbstractFightDispellableEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTemporaryBoostEffect::_deltaFunc, this, std::placeholders::_1));
}

void FightTemporaryBoostEffect::_deltaFunc(Reader *input)
{
  this->delta = input->readInt();
}

FightTemporaryBoostEffect::FightTemporaryBoostEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTEFFECT;
}

bool FightTemporaryBoostEffect::operator==(const FightTemporaryBoostEffect &compared)
{
  if(delta == compared.delta)
  return true;
  
  return false;
}

