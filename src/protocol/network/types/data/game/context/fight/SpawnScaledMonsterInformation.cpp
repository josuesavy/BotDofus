#include "SpawnScaledMonsterInformation.h"

void SpawnScaledMonsterInformation::serialize(Writer *output)
{
  this->serializeAs_SpawnScaledMonsterInformation(output);
}

void SpawnScaledMonsterInformation::serializeAs_SpawnScaledMonsterInformation(Writer *output)
{
  BaseSpawnMonsterInformation::serializeAs_BaseSpawnMonsterInformation(output);
  if(this->creatureLevel < 0)
  {
    qDebug()<<"ERREUR - SpawnScaledMonsterInformation -"<<"Forbidden value (" << this->creatureLevel << ") on element creatureLevel.";
  }
  output->writeShort((short)this->creatureLevel);
}

void SpawnScaledMonsterInformation::deserialize(Reader *input)
{
  this->deserializeAs_SpawnScaledMonsterInformation(input);
}

void SpawnScaledMonsterInformation::deserializeAs_SpawnScaledMonsterInformation(Reader *input)
{
  BaseSpawnMonsterInformation::deserialize(input);
  this->_creatureLevelFunc(input);
}

void SpawnScaledMonsterInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpawnScaledMonsterInformation(tree);
}

void SpawnScaledMonsterInformation::deserializeAsyncAs_SpawnScaledMonsterInformation(FuncTree tree)
{
  BaseSpawnMonsterInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&SpawnScaledMonsterInformation::_creatureLevelFunc, this, std::placeholders::_1));
}

void SpawnScaledMonsterInformation::_creatureLevelFunc(Reader *input)
{
  this->creatureLevel = input->readShort();
  if(this->creatureLevel < 0)
  {
    qDebug()<<"ERREUR - SpawnScaledMonsterInformation -"<<"Forbidden value (" << this->creatureLevel << ") on element of SpawnScaledMonsterInformation.creatureLevel.";
  }
}

SpawnScaledMonsterInformation::SpawnScaledMonsterInformation()
{
  m_types<<ClassEnum::SPAWNSCALEDMONSTERINFORMATION;
}

bool SpawnScaledMonsterInformation::operator==(const SpawnScaledMonsterInformation &compared)
{
  if(creatureLevel == compared.creatureLevel)
  return true;
  
  return false;
}

