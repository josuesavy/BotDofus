#include "EntityMovementInformations.h"

void EntityMovementInformations::serialize(Writer *output)
{
  this->serializeAs_EntityMovementInformations(output);
}

void EntityMovementInformations::serializeAs_EntityMovementInformations(Writer *output)
{
  output->writeInt((int)this->id);
  output->writeShort((short)this->steps.size());
  for(uint _i2 = 0; _i2 < this->steps.size(); _i2++)
  {
    output->writeByte(this->steps[_i2]);
  }
}

void EntityMovementInformations::deserialize(Reader *input)
{
  this->deserializeAs_EntityMovementInformations(input);
}

void EntityMovementInformations::deserializeAs_EntityMovementInformations(Reader *input)
{
  auto _val2 = 0;
  this->_idFunc(input);
  uint _stepsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _stepsLen; _i2++)
  {
    _val2 = input->readByte();
    this->steps.append(_val2);
  }
}

void EntityMovementInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityMovementInformations(tree);
}

void EntityMovementInformations::deserializeAsyncAs_EntityMovementInformations(FuncTree tree)
{
  tree.addChild(std::bind(&EntityMovementInformations::_idFunc, this, std::placeholders::_1));
  this->_stepstree = tree.addChild(std::bind(&EntityMovementInformations::_stepstreeFunc, this, std::placeholders::_1));
}

void EntityMovementInformations::_idFunc(Reader *input)
{
  this->id = input->readInt();
}

void EntityMovementInformations::_stepstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_stepstree.addChild(std::bind(&EntityMovementInformations::_stepsFunc, this, std::placeholders::_1));
  }
}

void EntityMovementInformations::_stepsFunc(Reader *input)
{
  int _val = input->readByte();
  this->steps.append(_val);
}

EntityMovementInformations::EntityMovementInformations()
{
  m_types<<ClassEnum::ENTITYMOVEMENTINFORMATIONS;
}

bool EntityMovementInformations::operator==(const EntityMovementInformations &compared)
{
  if(id == compared.id)
  if(steps == compared.steps)
  if(_stepstree == compared._stepstree)
  return true;
  
  return false;
}

