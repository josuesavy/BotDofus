#include "GameContextBasicSpawnInformation.h"

void GameContextBasicSpawnInformation::serialize(Writer *output)
{
  this->serializeAs_GameContextBasicSpawnInformation(output);
}

void GameContextBasicSpawnInformation::serializeAs_GameContextBasicSpawnInformation(Writer *output)
{
  output->writeByte(this->teamId);
  output->writeBool(this->alive);
  output->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(output);
}

void GameContextBasicSpawnInformation::deserialize(Reader *input)
{
  this->deserializeAs_GameContextBasicSpawnInformation(input);
}

void GameContextBasicSpawnInformation::deserializeAs_GameContextBasicSpawnInformation(Reader *input)
{
  this->_teamIdFunc(input);
  this->_aliveFunc(input);
  uint _id3 = input->readUShort();
  this->informations = qSharedPointerCast<GameContextActorPositionInformations>(ClassManagerSingleton::get()->getClass(_id3));
  this->informations->deserialize(input);
}

void GameContextBasicSpawnInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextBasicSpawnInformation(tree);
}

void GameContextBasicSpawnInformation::deserializeAsyncAs_GameContextBasicSpawnInformation(FuncTree tree)
{
  tree.addChild(std::bind(&GameContextBasicSpawnInformation::_teamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameContextBasicSpawnInformation::_aliveFunc, this, std::placeholders::_1));
  this->_informationstree = tree.addChild(std::bind(&GameContextBasicSpawnInformation::_informationstreeFunc, this, std::placeholders::_1));
}

void GameContextBasicSpawnInformation::_teamIdFunc(Reader *input)
{
  this->teamId = input->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - GameContextBasicSpawnInformation -"<<"Forbidden value (" << this->teamId << ") on element of GameContextBasicSpawnInformation.teamId.";
  }
}

void GameContextBasicSpawnInformation::_aliveFunc(Reader *input)
{
  this->alive = input->readBool();
}

void GameContextBasicSpawnInformation::_informationstreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->informations = qSharedPointerCast<GameContextActorPositionInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->informations->deserializeAsync(this->_informationstree);
}

GameContextBasicSpawnInformation::GameContextBasicSpawnInformation()
{
  m_types<<ClassEnum::GAMECONTEXTBASICSPAWNINFORMATION;
}

bool GameContextBasicSpawnInformation::operator==(const GameContextBasicSpawnInformation &compared)
{
  if(teamId == compared.teamId)
  if(alive == compared.alive)
  if(informations == compared.informations)
  if(_informationstree == compared._informationstree)
  return true;
  
  return false;
}

