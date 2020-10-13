#include "GameFightEntityInformation.h"

void GameFightEntityInformation::serialize(Writer *output)
{
  this->serializeAs_GameFightEntityInformation(output);
}

void GameFightEntityInformation::serializeAs_GameFightEntityInformation(Writer *output)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(output);
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->entityModelId << ") on element entityModelId.";
  }
  output->writeByte(this->entityModelId);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  output->writeDouble(this->masterId);
}

void GameFightEntityInformation::deserialize(Reader *input)
{
  this->deserializeAs_GameFightEntityInformation(input);
}

void GameFightEntityInformation::deserializeAs_GameFightEntityInformation(Reader *input)
{
  GameFightFighterInformations::deserialize(input);
  this->_entityModelIdFunc(input);
  this->_levelFunc(input);
  this->_masterIdFunc(input);
}

void GameFightEntityInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightEntityInformation(tree);
}

void GameFightEntityInformation::deserializeAsyncAs_GameFightEntityInformation(FuncTree tree)
{
  GameFightFighterInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightEntityInformation::_entityModelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEntityInformation::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEntityInformation::_masterIdFunc, this, std::placeholders::_1));
}

void GameFightEntityInformation::_entityModelIdFunc(Reader *input)
{
  this->entityModelId = input->readByte();
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->entityModelId << ") on element of GameFightEntityInformation.entityModelId.";
  }
}

void GameFightEntityInformation::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->level << ") on element of GameFightEntityInformation.level.";
  }
}

void GameFightEntityInformation::_masterIdFunc(Reader *input)
{
  this->masterId = input->readDouble();
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightEntityInformation -"<<"Forbidden value (" << this->masterId << ") on element of GameFightEntityInformation.masterId.";
  }
}

GameFightEntityInformation::GameFightEntityInformation()
{
  m_types<<ClassEnum::GAMEFIGHTENTITYINFORMATION;
}

bool GameFightEntityInformation::operator==(const GameFightEntityInformation &compared)
{
  if(entityModelId == compared.entityModelId)
  if(level == compared.level)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

