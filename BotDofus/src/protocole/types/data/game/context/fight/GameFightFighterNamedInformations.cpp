#include "GameFightFighterNamedInformations.h"

void GameFightFighterNamedInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterNamedInformations(output);
}

void GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(Writer *output)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(output);
  output->writeUTF(this->name);
  this->status->serializeAs_PlayerStatus(output);
  output->writeVarShort((int)this->leagueId);
  output->writeInt((int)this->ladderPosition);
  output->writeBool(this->hiddenInPrefight);
}

void GameFightFighterNamedInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterNamedInformations(input);
}

void GameFightFighterNamedInformations::deserializeAs_GameFightFighterNamedInformations(Reader *input)
{
  GameFightFighterInformations::deserialize(input);
  this->_nameFunc(input);
  this->status = QSharedPointer<PlayerStatus>(new PlayerStatus() );
  this->status->deserialize(input);
  this->_leagueIdFunc(input);
  this->_ladderPositionFunc(input);
  this->_hiddenInPrefightFunc(input);
}

void GameFightFighterNamedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterNamedInformations(tree);
}

void GameFightFighterNamedInformations::deserializeAsyncAs_GameFightFighterNamedInformations(FuncTree tree)
{
  GameFightFighterInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightFighterNamedInformations::_nameFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&GameFightFighterNamedInformations::_statustreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterNamedInformations::_leagueIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterNamedInformations::_ladderPositionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterNamedInformations::_hiddenInPrefightFunc, this, std::placeholders::_1));
}

void GameFightFighterNamedInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void GameFightFighterNamedInformations::_statustreeFunc(Reader *input)
{
  this->status = QSharedPointer<PlayerStatus>(new PlayerStatus() );
  this->status->deserializeAsync(this->_statustree);
}

void GameFightFighterNamedInformations::_leagueIdFunc(Reader *input)
{
  this->leagueId = input->readVarShort();
}

void GameFightFighterNamedInformations::_ladderPositionFunc(Reader *input)
{
  this->ladderPosition = input->readInt();
}

void GameFightFighterNamedInformations::_hiddenInPrefightFunc(Reader *input)
{
  this->hiddenInPrefight = input->readBool();
}

GameFightFighterNamedInformations::GameFightFighterNamedInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERNAMEDINFORMATIONS;
}

bool GameFightFighterNamedInformations::operator==(const GameFightFighterNamedInformations &compared)
{
  if(name == compared.name)
  if(status == compared.status)
  if(leagueId == compared.leagueId)
  if(ladderPosition == compared.ladderPosition)
  if(hiddenInPrefight == compared.hiddenInPrefight)
  if(_statustree == compared._statustree)
  return true;
  
  return false;
}

