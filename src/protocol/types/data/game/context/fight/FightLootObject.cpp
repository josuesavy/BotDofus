#include "FightLootObject.h"

void FightLootObject::serialize(Writer *output)
{
  this->serializeAs_FightLootObject(output);
}

void FightLootObject::serializeAs_FightLootObject(Writer *output)
{
  output->writeInt((int)this->objectId);
  output->writeInt((int)this->quantity);
  output->writeInt((int)this->priorityHint);
}

void FightLootObject::deserialize(Reader *input)
{
  this->deserializeAs_FightLootObject(input);
}

void FightLootObject::deserializeAs_FightLootObject(Reader *input)
{
  this->_objectIdFunc(input);
  this->_quantityFunc(input);
  this->_priorityHintFunc(input);
}

void FightLootObject::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightLootObject(tree);
}

void FightLootObject::deserializeAsyncAs_FightLootObject(FuncTree tree)
{
  tree.addChild(std::bind(&FightLootObject::_objectIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightLootObject::_quantityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightLootObject::_priorityHintFunc, this, std::placeholders::_1));
}

void FightLootObject::_objectIdFunc(Reader *input)
{
  this->objectId = input->readInt();
}

void FightLootObject::_quantityFunc(Reader *input)
{
  this->quantity = input->readInt();
}

void FightLootObject::_priorityHintFunc(Reader *input)
{
  this->priorityHint = input->readInt();
}

FightLootObject::FightLootObject()
{
  m_types<<ClassEnum::FIGHTLOOTOBJECT;
}

bool FightLootObject::operator==(const FightLootObject &compared)
{
  if(objectId == compared.objectId)
  if(quantity == compared.quantity)
  if(priorityHint == compared.priorityHint)
  return true;
  
  return false;
}

