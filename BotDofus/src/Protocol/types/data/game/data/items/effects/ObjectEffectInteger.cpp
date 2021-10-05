#include "ObjectEffectInteger.h"

void ObjectEffectInteger::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectInteger(output);
}

void ObjectEffectInteger::serializeAs_ObjectEffectInteger(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectInteger -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  output->writeVarInt((int)this->value);
}

void ObjectEffectInteger::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectInteger(input);
}

void ObjectEffectInteger::deserializeAs_ObjectEffectInteger(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_valueFunc(input);
}

void ObjectEffectInteger::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectInteger(tree);
}

void ObjectEffectInteger::deserializeAsyncAs_ObjectEffectInteger(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectInteger::_valueFunc, this, std::placeholders::_1));
}

void ObjectEffectInteger::_valueFunc(Reader *input)
{
  this->value = input->readVarUhInt();
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectInteger -"<<"Forbidden value (" << this->value << ") on element of ObjectEffectInteger.value.";
  }
}

ObjectEffectInteger::ObjectEffectInteger()
{
  m_types<<ClassEnum::OBJECTEFFECTINTEGER;
}

bool ObjectEffectInteger::operator==(const ObjectEffectInteger &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

