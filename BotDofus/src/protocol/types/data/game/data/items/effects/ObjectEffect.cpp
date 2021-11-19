#include "ObjectEffect.h"

void ObjectEffect::serialize(Writer *output)
{
  this->serializeAs_ObjectEffect(output);
}

void ObjectEffect::serializeAs_ObjectEffect(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffect -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeVarShort((int)this->actionId);
}

void ObjectEffect::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffect(input);
}

void ObjectEffect::deserializeAs_ObjectEffect(Reader *input)
{
  this->_actionIdFunc(input);
}

void ObjectEffect::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffect(tree);
}

void ObjectEffect::deserializeAsyncAs_ObjectEffect(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectEffect::_actionIdFunc, this, std::placeholders::_1));
}

void ObjectEffect::_actionIdFunc(Reader *input)
{
  this->actionId = input->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffect -"<<"Forbidden value (" << this->actionId << ") on element of ObjectEffect.actionId.";
  }
}

ObjectEffect::ObjectEffect()
{
  m_types<<ClassEnum::OBJECTEFFECT;
}

bool ObjectEffect::operator==(const ObjectEffect &compared)
{
  if(actionId == compared.actionId)
  return true;
  
  return false;
}

