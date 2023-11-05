#include "FightTriggeredEffect.h"

void FightTriggeredEffect::serialize(Writer *output)
{
  this->serializeAs_FightTriggeredEffect(output);
}

void FightTriggeredEffect::serializeAs_FightTriggeredEffect(Writer *output)
{
  AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(output);
  output->writeInt((int)this->param1);
  output->writeInt((int)this->param2);
  output->writeInt((int)this->param3);
  output->writeShort((short)this->delay);
}

void FightTriggeredEffect::deserialize(Reader *input)
{
  this->deserializeAs_FightTriggeredEffect(input);
}

void FightTriggeredEffect::deserializeAs_FightTriggeredEffect(Reader *input)
{
  AbstractFightDispellableEffect::deserialize(input);
  this->_param1Func(input);
  this->_param2Func(input);
  this->_param3Func(input);
  this->_delayFunc(input);
}

void FightTriggeredEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTriggeredEffect(tree);
}

void FightTriggeredEffect::deserializeAsyncAs_FightTriggeredEffect(FuncTree tree)
{
  AbstractFightDispellableEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTriggeredEffect::_param1Func, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTriggeredEffect::_param2Func, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTriggeredEffect::_param3Func, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTriggeredEffect::_delayFunc, this, std::placeholders::_1));
}

void FightTriggeredEffect::_param1Func(Reader *input)
{
  this->param1 = input->readInt();
}

void FightTriggeredEffect::_param2Func(Reader *input)
{
  this->param2 = input->readInt();
}

void FightTriggeredEffect::_param3Func(Reader *input)
{
  this->param3 = input->readInt();
}

void FightTriggeredEffect::_delayFunc(Reader *input)
{
  this->delay = input->readShort();
}

FightTriggeredEffect::FightTriggeredEffect()
{
  m_types<<ClassEnum::FIGHTTRIGGEREDEFFECT;
}

bool FightTriggeredEffect::operator==(const FightTriggeredEffect &compared)
{
  if(param1 == compared.param1)
  if(param2 == compared.param2)
  if(param3 == compared.param3)
  if(delay == compared.delay)
  return true;
  
  return false;
}

