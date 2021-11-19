#include "ObjectEffectString.h"

void ObjectEffectString::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectString(output);
}

void ObjectEffectString::serializeAs_ObjectEffectString(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  output->writeUTF(this->value);
}

void ObjectEffectString::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectString(input);
}

void ObjectEffectString::deserializeAs_ObjectEffectString(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_valueFunc(input);
}

void ObjectEffectString::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectString(tree);
}

void ObjectEffectString::deserializeAsyncAs_ObjectEffectString(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectString::_valueFunc, this, std::placeholders::_1));
}

void ObjectEffectString::_valueFunc(Reader *input)
{
  this->value = input->readUTF();
}

ObjectEffectString::ObjectEffectString()
{
  m_types<<ClassEnum::OBJECTEFFECTSTRING;
}

bool ObjectEffectString::operator==(const ObjectEffectString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

