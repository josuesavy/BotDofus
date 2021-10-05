#include "FightTemporaryBoostStateEffect.h"

void FightTemporaryBoostStateEffect::serialize(Writer *output)
{
  this->serializeAs_FightTemporaryBoostStateEffect(output);
}

void FightTemporaryBoostStateEffect::serializeAs_FightTemporaryBoostStateEffect(Writer *output)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(output);
  output->writeShort((short)this->stateId);
}

void FightTemporaryBoostStateEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTemporaryBoostStateEffect(input);
}

void FightTemporaryBoostStateEffect::deserializeAs_FightTemporaryBoostStateEffect(Reader *input)
{
  FightTemporaryBoostEffect::deserialize(input);
  this->_stateIdFunc(input);
}

void FightTemporaryBoostStateEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTemporaryBoostStateEffect(tree);
}

void FightTemporaryBoostStateEffect::deserializeAsyncAs_FightTemporaryBoostStateEffect(FuncTree tree)
{
  FightTemporaryBoostEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTemporaryBoostStateEffect::_stateIdFunc, this, std::placeholders::_1));
}

void FightTemporaryBoostStateEffect::_stateIdFunc(Reader *input)
{
  this->stateId = input->readShort();
}

FightTemporaryBoostStateEffect::FightTemporaryBoostStateEffect()
{
  m_types<<ClassEnum::FIGHTTEMPORARYBOOSTSTATEEFFECT;
}

bool FightTemporaryBoostStateEffect::operator==(const FightTemporaryBoostStateEffect &compared)
{
  if(stateId == compared.stateId)
  return true;
  
  return false;
}

