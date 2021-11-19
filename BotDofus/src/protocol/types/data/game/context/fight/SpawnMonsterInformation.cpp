#include "SpawnMonsterInformation.h"

void SpawnMonsterInformation::serialize(Writer *output)
{
  this->serializeAs_SpawnMonsterInformation(output);
}

void SpawnMonsterInformation::serializeAs_SpawnMonsterInformation(Writer *output)
{
  BaseSpawnMonsterInformation::serializeAs_BaseSpawnMonsterInformation(output);
  if(this->creatureGrade < 0)
  {
    qDebug()<<"ERREUR - SpawnMonsterInformation -"<<"Forbidden value (" << this->creatureGrade << ") on element creatureGrade.";
  }
  output->writeByte(this->creatureGrade);
}

void SpawnMonsterInformation::deserialize(Reader *input)
{
  this->deserializeAs_SpawnMonsterInformation(input);
}

void SpawnMonsterInformation::deserializeAs_SpawnMonsterInformation(Reader *input)
{
  BaseSpawnMonsterInformation::deserialize(input);
  this->_creatureGradeFunc(input);
}

void SpawnMonsterInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpawnMonsterInformation(tree);
}

void SpawnMonsterInformation::deserializeAsyncAs_SpawnMonsterInformation(FuncTree tree)
{
  BaseSpawnMonsterInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&SpawnMonsterInformation::_creatureGradeFunc, this, std::placeholders::_1));
}

void SpawnMonsterInformation::_creatureGradeFunc(Reader *input)
{
  this->creatureGrade = input->readByte();
  if(this->creatureGrade < 0)
  {
    qDebug()<<"ERREUR - SpawnMonsterInformation -"<<"Forbidden value (" << this->creatureGrade << ") on element of SpawnMonsterInformation.creatureGrade.";
  }
}

SpawnMonsterInformation::SpawnMonsterInformation()
{
  m_types<<ClassEnum::SPAWNMONSTERINFORMATION;
}

bool SpawnMonsterInformation::operator==(const SpawnMonsterInformation &compared)
{
  if(creatureGrade == compared.creatureGrade)
  return true;
  
  return false;
}

