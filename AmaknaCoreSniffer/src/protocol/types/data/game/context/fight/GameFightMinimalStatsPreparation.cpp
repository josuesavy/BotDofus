#include "GameFightMinimalStatsPreparation.h"

void GameFightMinimalStatsPreparation::serialize(Writer *output)
{
  this->serializeAs_GameFightMinimalStatsPreparation(output);
}

void GameFightMinimalStatsPreparation::serializeAs_GameFightMinimalStatsPreparation(Writer *output)
{
  GameFightMinimalStats::serializeAs_GameFightMinimalStats(output);
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStatsPreparation -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
  }
  output->writeVarInt((int)this->initiative);
}

void GameFightMinimalStatsPreparation::deserialize(Reader *input)
{
  this->deserializeAs_GameFightMinimalStatsPreparation(input);
}

void GameFightMinimalStatsPreparation::deserializeAs_GameFightMinimalStatsPreparation(Reader *input)
{
  GameFightMinimalStats::deserialize(input);
  this->_initiativeFunc(input);
}

void GameFightMinimalStatsPreparation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightMinimalStatsPreparation(tree);
}

void GameFightMinimalStatsPreparation::deserializeAsyncAs_GameFightMinimalStatsPreparation(FuncTree tree)
{
  GameFightMinimalStats::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightMinimalStatsPreparation::_initiativeFunc, this, std::placeholders::_1));
}

void GameFightMinimalStatsPreparation::_initiativeFunc(Reader *input)
{
  this->initiative = input->readVarUhInt();
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - GameFightMinimalStatsPreparation -"<<"Forbidden value (" << this->initiative << ") on element of GameFightMinimalStatsPreparation.initiative.";
  }
}

GameFightMinimalStatsPreparation::GameFightMinimalStatsPreparation()
{
  m_types<<ClassEnum::GAMEFIGHTMINIMALSTATSPREPARATION;
}

bool GameFightMinimalStatsPreparation::operator==(const GameFightMinimalStatsPreparation &compared)
{
  if(initiative == compared.initiative)
  return true;
  
  return false;
}

