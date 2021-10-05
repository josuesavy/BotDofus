#include "ObjectEffectCreature.h"

void ObjectEffectCreature::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectCreature(output);
}

void ObjectEffectCreature::serializeAs_ObjectEffectCreature(Writer *output)
{
  ObjectEffect::serializeAs_ObjectEffect(output);
  if(this->monsterFamilyId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectCreature -"<<"Forbidden value (" << this->monsterFamilyId << ") on element monsterFamilyId.";
  }
  output->writeVarShort((int)this->monsterFamilyId);
}

void ObjectEffectCreature::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectCreature(input);
}

void ObjectEffectCreature::deserializeAs_ObjectEffectCreature(Reader *input)
{
  ObjectEffect::deserialize(input);
  this->_monsterFamilyIdFunc(input);
}

void ObjectEffectCreature::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectCreature(tree);
}

void ObjectEffectCreature::deserializeAsyncAs_ObjectEffectCreature(FuncTree tree)
{
  ObjectEffect::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectCreature::_monsterFamilyIdFunc, this, std::placeholders::_1));
}

void ObjectEffectCreature::_monsterFamilyIdFunc(Reader *input)
{
  this->monsterFamilyId = input->readVarUhShort();
  if(this->monsterFamilyId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectCreature -"<<"Forbidden value (" << this->monsterFamilyId << ") on element of ObjectEffectCreature.monsterFamilyId.";
  }
}

ObjectEffectCreature::ObjectEffectCreature()
{
  m_types<<ClassEnum::OBJECTEFFECTCREATURE;
}

bool ObjectEffectCreature::operator==(const ObjectEffectCreature &compared)
{
  if(monsterFamilyId == compared.monsterFamilyId)
  return true;
  
  return false;
}

