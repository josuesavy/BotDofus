#include "ObjectEffectLadder.h"

void ObjectEffectLadder::serialize(Writer *output)
{
  this->serializeAs_ObjectEffectLadder(output);
}

void ObjectEffectLadder::serializeAs_ObjectEffectLadder(Writer *output)
{
  ObjectEffectCreature::serializeAs_ObjectEffectCreature(output);
  if(this->monsterCount < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectLadder -"<<"Forbidden value (" << this->monsterCount << ") on element monsterCount.";
  }
  output->writeVarInt((int)this->monsterCount);
}

void ObjectEffectLadder::deserialize(Reader *input)
{
  this->deserializeAs_ObjectEffectLadder(input);
}

void ObjectEffectLadder::deserializeAs_ObjectEffectLadder(Reader *input)
{
  ObjectEffectCreature::deserialize(input);
  this->_monsterCountFunc(input);
}

void ObjectEffectLadder::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectEffectLadder(tree);
}

void ObjectEffectLadder::deserializeAsyncAs_ObjectEffectLadder(FuncTree tree)
{
  ObjectEffectCreature::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectEffectLadder::_monsterCountFunc, this, std::placeholders::_1));
}

void ObjectEffectLadder::_monsterCountFunc(Reader *input)
{
  this->monsterCount = input->readVarUhInt();
  if(this->monsterCount < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectLadder -"<<"Forbidden value (" << this->monsterCount << ") on element of ObjectEffectLadder.monsterCount.";
  }
}

ObjectEffectLadder::ObjectEffectLadder()
{
  m_types<<ClassEnum::OBJECTEFFECTLADDER;
}

bool ObjectEffectLadder::operator==(const ObjectEffectLadder &compared)
{
  if(monsterCount == compared.monsterCount)
  return true;
  
  return false;
}

