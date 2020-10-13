#include "FriendInformations.h"

void FriendInformations::serialize(Writer *output)
{
  this->serializeAs_FriendInformations(output);
}

void FriendInformations::serializeAs_FriendInformations(Writer *output)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(output);
  output->writeByte(this->playerState);
  if(this->lastConnection < 0)
  {
    qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->lastConnection << ") on element lastConnection.";
  }
  output->writeVarShort((int)this->lastConnection);
  output->writeInt((int)this->achievementPoints);
  output->writeVarShort((int)this->leagueId);
  output->writeInt((int)this->ladderPosition);
}

void FriendInformations::deserialize(Reader *input)
{
  this->deserializeAs_FriendInformations(input);
}

void FriendInformations::deserializeAs_FriendInformations(Reader *input)
{
  AbstractContactInformations::deserialize(input);
  this->_playerStateFunc(input);
  this->_lastConnectionFunc(input);
  this->_achievementPointsFunc(input);
  this->_leagueIdFunc(input);
  this->_ladderPositionFunc(input);
}

void FriendInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendInformations(tree);
}

void FriendInformations::deserializeAsyncAs_FriendInformations(FuncTree tree)
{
  AbstractContactInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FriendInformations::_playerStateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendInformations::_lastConnectionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendInformations::_achievementPointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendInformations::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FriendInformations::_ladderPositionFunc, this, std::placeholders::_1));
}

void FriendInformations::_playerStateFunc(Reader *input)
{
  this->playerState = input->readByte();
  if(this->playerState < 0)
  {
    qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->playerState << ") on element of FriendInformations.playerState.";
  }
}

void FriendInformations::_lastConnectionFunc(Reader *input)
{
  this->lastConnection = input->readVarUhShort();
  if(this->lastConnection < 0)
  {
    qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->lastConnection << ") on element of FriendInformations.lastConnection.";
  }
}

void FriendInformations::_achievementPointsFunc(Reader *input)
{
  this->achievementPoints = input->readInt();
}

void FriendInformations::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarShort();
}

void FriendInformations::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

FriendInformations::FriendInformations()
{
  m_types<<ClassEnum::FRIENDINFORMATIONS;
}

bool FriendInformations::operator==(const FriendInformations &compared)
{
  if(playerState == compared.playerState)
  if(lastConnection == compared.lastConnection)
  if(achievementPoints == compared.achievementPoints)
  if(leagueId == compared.leagueId)
  if(ladderPosition == compared.ladderPosition)
  return true;
  
  return false;
}

