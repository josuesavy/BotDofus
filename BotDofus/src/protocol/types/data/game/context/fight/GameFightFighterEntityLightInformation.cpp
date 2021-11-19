#include "GameFightFighterEntityLightInformation.h"

void GameFightFighterEntityLightInformation::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterEntityLightInformation(output);
}

void GameFightFighterEntityLightInformation::serializeAs_GameFightFighterEntityLightInformation(Writer *output)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(output);
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterEntityLightInformation -"<<"Forbidden value (" << this->entityModelId << ") on element entityModelId.";
  }
  output->writeByte(this->entityModelId);
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterEntityLightInformation -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  output->writeDouble(this->masterId);
}

void GameFightFighterEntityLightInformation::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterEntityLightInformation(input);
}

void GameFightFighterEntityLightInformation::deserializeAs_GameFightFighterEntityLightInformation(Reader *input)
{
  GameFightFighterLightInformations::deserialize(input);
  this->_entityModelIdFunc(input);
  this->_masterIdFunc(input);
}

void GameFightFighterEntityLightInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterEntityLightInformation(tree);
}

void GameFightFighterEntityLightInformation::deserializeAsyncAs_GameFightFighterEntityLightInformation(FuncTree tree)
{
  GameFightFighterLightInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightFighterEntityLightInformation::_entityModelIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterEntityLightInformation::_masterIdFunc, this, std::placeholders::_1));
}

void GameFightFighterEntityLightInformation::_entityModelIdFunc(Reader *input)
{
  this->entityModelId = input->readByte();
  if(this->entityModelId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterEntityLightInformation -"<<"Forbidden value (" << this->entityModelId << ") on element of GameFightFighterEntityLightInformation.entityModelId.";
  }
}

void GameFightFighterEntityLightInformation::_masterIdFunc(Reader *input)
{
  this->masterId = input->readDouble();
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterEntityLightInformation -"<<"Forbidden value (" << this->masterId << ") on element of GameFightFighterEntityLightInformation.masterId.";
  }
}

GameFightFighterEntityLightInformation::GameFightFighterEntityLightInformation()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERENTITYLIGHTINFORMATION;
}

bool GameFightFighterEntityLightInformation::operator==(const GameFightFighterEntityLightInformation &compared)
{
  if(entityModelId == compared.entityModelId)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

