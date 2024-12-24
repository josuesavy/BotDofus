#include "BaseSpawnMonsterInformation.h"

void BaseSpawnMonsterInformation::serialize(Writer *output)
{
  this->serializeAs_BaseSpawnMonsterInformation(output);
}

void BaseSpawnMonsterInformation::serializeAs_BaseSpawnMonsterInformation(Writer *output)
{
  SpawnInformation::serializeAs_SpawnInformation(output);
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - BaseSpawnMonsterInformation -"<<"Forbidden value (" << this->creatureGenericId << ") on element creatureGenericId.";
  }
  output->writeVarShort((int)this->creatureGenericId);
}

void BaseSpawnMonsterInformation::deserialize(Reader *input)
{
  this->deserializeAs_BaseSpawnMonsterInformation(input);
}

void BaseSpawnMonsterInformation::deserializeAs_BaseSpawnMonsterInformation(Reader *input)
{
  SpawnInformation::deserialize(input);
  this->_creatureGenericIdFunc(input);
}

void BaseSpawnMonsterInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BaseSpawnMonsterInformation(tree);
}

void BaseSpawnMonsterInformation::deserializeAsyncAs_BaseSpawnMonsterInformation(FuncTree tree)
{
  SpawnInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&BaseSpawnMonsterInformation::_creatureGenericIdFunc, this, std::placeholders::_1));
}

void BaseSpawnMonsterInformation::_creatureGenericIdFunc(Reader *input)
{
  this->creatureGenericId = input->readVarUhShort();
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - BaseSpawnMonsterInformation -"<<"Forbidden value (" << this->creatureGenericId << ") on element of BaseSpawnMonsterInformation.creatureGenericId.";
  }
}

BaseSpawnMonsterInformation::BaseSpawnMonsterInformation()
{
  m_types<<ClassEnum::BASESPAWNMONSTERINFORMATION;
}

bool BaseSpawnMonsterInformation::operator==(const BaseSpawnMonsterInformation &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  return true;
  
  return false;
}

