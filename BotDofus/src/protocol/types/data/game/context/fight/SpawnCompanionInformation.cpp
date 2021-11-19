#include "SpawnCompanionInformation.h"

void SpawnCompanionInformation::serialize(Writer *output)
{
  this->serializeAs_SpawnCompanionInformation(output);
}

void SpawnCompanionInformation::serializeAs_SpawnCompanionInformation(Writer *output)
{
  SpawnInformation::serializeAs_SpawnInformation(output);
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  output->writeByte(this->modelId);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  if(this->summonerId < -9.007199254740992E15 || this->summonerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->summonerId << ") on element summonerId.";
  }
  output->writeDouble(this->summonerId);
  if(this->ownerId < -9.007199254740992E15 || this->ownerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->ownerId << ") on element ownerId.";
  }
  output->writeDouble(this->ownerId);
}

void SpawnCompanionInformation::deserialize(Reader *input)
{
  this->deserializeAs_SpawnCompanionInformation(input);
}

void SpawnCompanionInformation::deserializeAs_SpawnCompanionInformation(Reader *input)
{
  SpawnInformation::deserialize(input);
  this->_modelIdFunc(input);
  this->_levelFunc(input);
  this->_summonerIdFunc(input);
  this->_ownerIdFunc(input);
}

void SpawnCompanionInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpawnCompanionInformation(tree);
}

void SpawnCompanionInformation::deserializeAsyncAs_SpawnCompanionInformation(FuncTree tree)
{
  SpawnInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&SpawnCompanionInformation::_modelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpawnCompanionInformation::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpawnCompanionInformation::_summonerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpawnCompanionInformation::_ownerIdFunc, this, std::placeholders::_1));
}

void SpawnCompanionInformation::_modelIdFunc(Reader *input)
{
  this->modelId = input->readByte();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->modelId << ") on element of SpawnCompanionInformation.modelId.";
  }
}

void SpawnCompanionInformation::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->level << ") on element of SpawnCompanionInformation.level.";
  }
}

void SpawnCompanionInformation::_summonerIdFunc(Reader *input)
{
  this->summonerId = input->readDouble();
  if(this->summonerId < -9.007199254740992E15 || this->summonerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->summonerId << ") on element of SpawnCompanionInformation.summonerId.";
  }
}

void SpawnCompanionInformation::_ownerIdFunc(Reader *input)
{
  this->ownerId = input->readDouble();
  if(this->ownerId < -9.007199254740992E15 || this->ownerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SpawnCompanionInformation -"<<"Forbidden value (" << this->ownerId << ") on element of SpawnCompanionInformation.ownerId.";
  }
}

SpawnCompanionInformation::SpawnCompanionInformation()
{
  m_types<<ClassEnum::SPAWNCOMPANIONINFORMATION;
}

bool SpawnCompanionInformation::operator==(const SpawnCompanionInformation &compared)
{
  if(modelId == compared.modelId)
  if(level == compared.level)
  if(summonerId == compared.summonerId)
  if(ownerId == compared.ownerId)
  return true;
  
  return false;
}

