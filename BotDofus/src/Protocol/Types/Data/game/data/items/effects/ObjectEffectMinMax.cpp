#include "ObjectEffectMinMax.h"

void ObjectEffectMinMax::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectMinMax(output);
}

void ObjectEffectMinMax::serializeAs_ObjectEffectMinMax(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->min << ") on element min.";
  }
  output->writeVarInt((int)this->min);
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->max << ") on element max.";
  }
  output->writeVarInt((int)this->max);
}

void ObjectEffectMinMax::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectMinMax(input);
}

void ObjectEffectMinMax::deserializeAs_ObjectEffectMinMax(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_minFunc(input);
  this->_maxFunc(input);
}

void ObjectEffectMinMax::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectMinMax(tree);
}

void ObjectEffectMinMax::deserializeAsyncAs_ObjectEffectMinMax(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectMinMax::_minFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectEffectMinMax::_maxFunc, this, std::placeholders::_1));
}

void ObjectEffectMinMax::_minFunc(Reader *input)
{
  this->min = input->readVarUhInt();
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->min << ") on element of ObjectEffectMinMax.min.";
  }
}

void ObjectEffectMinMax::_maxFunc(Reader *input)
{
  this->max = input->readVarUhInt();
  if(this->max < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->max << ") on element of ObjectEffectMinMax.max.";
  }
}

ObjectEffectMinMax::ObjectEffectMinMax()
{
  m_types<<ClassEnum::OBJECTEFFECTMINMAX;
}

bool ObjectEffectMinMax::operator==(const ObjectEffectMinMax &compared)
{
  if(min == compared.min)
  if(max == compared.max)
  return true;
  
  return false;
}

