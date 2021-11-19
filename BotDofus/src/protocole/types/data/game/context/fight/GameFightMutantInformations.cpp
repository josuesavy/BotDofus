#include "GameFightMutantInformations.h"

void GameFightMutantInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightMutantInformations(output);
}

void GameFightMutantInformations::serializeAs_GameFightMutantInformations(Writer *output)
{
  GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(output);
  if(this->powerLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMutantInformations -"<<"Forbidden value (" << this->powerLevel << ") on element powerLevel.";
  }
  output->writeByte(this->powerLevel);
}

void GameFightMutantInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightMutantInformations(input);
}

void GameFightMutantInformations::deserializeAs_GameFightMutantInformations(Reader *input)
{
  GameFightFighterNamedInformations::deserialize(input);
  this->_powerLevelFunc(input);
}

void GameFightMutantInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightMutantInformations(tree);
}

void GameFightMutantInformations::deserializeAsyncAs_GameFightMutantInformations(FuncTree tree)
{
  GameFightFighterNamedInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightMutantInformations::_powerLevelFunc, this, std::placeholders::_1));
}

void GameFightMutantInformations::_powerLevelFunc(Reader *input)
{
  this->powerLevel = input->readByte();
  if(this->powerLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMutantInformations -"<<"Forbidden value (" << this->powerLevel << ") on element of GameFightMutantInformations.powerLevel.";
  }
}

GameFightMutantInformations::GameFightMutantInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMUTANTINFORMATIONS;
}

bool GameFightMutantInformations::operator==(const GameFightMutantInformations &compared)
{
  if(powerLevel == compared.powerLevel)
  return true;
  
  return false;
}

