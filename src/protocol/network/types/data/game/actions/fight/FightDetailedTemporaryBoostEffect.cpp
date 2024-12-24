#include "FightDetailedTemporaryBoostEffect.h"

void FightDetailedTemporaryBoostEffect::serialize(Writer *output)
{
  this->serializeAs_FightDetailedTemporaryBoostEffect(output);
}

void FightDetailedTemporaryBoostEffect::serializeAs_FightDetailedTemporaryBoostEffect(Writer *output)
{
  FightTemporaryBoostEffect::serializeAs_FightTemporaryBoostEffect(output);
  output->writeInt((int)this->param1);
  output->writeInt((int)this->param2);
  output->writeInt((int)this->param3);
}

void FightDetailedTemporaryBoostEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightDetailedTemporaryBoostEffect(input);
}

void FightDetailedTemporaryBoostEffect::deserializeAs_FightDetailedTemporaryBoostEffect(Reader *input)
{
  FightTemporaryBoostEffect::deserialize(input);
  this->_param1Func(input);
  this->_param2Func(input);
  this->_param3Func(input);
}

void FightDetailedTemporaryBoostEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightDetailedTemporaryBoostEffect(tree);
}

void FightDetailedTemporaryBoostEffect::deserializeAsyncAs_FightDetailedTemporaryBoostEffect(FuncTree tree)
{
  FightTemporaryBoostEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightDetailedTemporaryBoostEffect::_param1Func, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightDetailedTemporaryBoostEffect::_param2Func, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightDetailedTemporaryBoostEffect::_param3Func, this, std::placeholders::_1));
}

void FightDetailedTemporaryBoostEffect::_param1Func(Reader *input)
{
  this->param1 = input->readInt();
}

void FightDetailedTemporaryBoostEffect::_param2Func(Reader *input)
{
  this->param2 = input->readInt();
}

void FightDetailedTemporaryBoostEffect::_param3Func(Reader *input)
{
  this->param3 = input->readInt();
}

FightDetailedTemporaryBoostEffect::FightDetailedTemporaryBoostEffect()
{
  m_types<<ClassEnum::FIGHTDETAILEDTEMPORARYBOOSTEFFECT;
}

bool FightDetailedTemporaryBoostEffect::operator==(const FightDetailedTemporaryBoostEffect &compared)
{
  if(param1 == compared.param1)
  if(param2 == compared.param2)
  if(param3 == compared.param3)
  return true;
  
  return false;
}

