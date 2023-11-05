#include "GameFightFighterMonsterLightInformations.h"

void GameFightFighterMonsterLightInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterMonsterLightInformations(output);
}

void GameFightFighterMonsterLightInformations::serializeAs_GameFightFighterMonsterLightInformations(Writer *output)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(output);
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterMonsterLightInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element creatureGenericId.";
  }
  output->writeVarShort((int)this->creatureGenericId);
}

void GameFightFighterMonsterLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterMonsterLightInformations(input);
}

void GameFightFighterMonsterLightInformations::deserializeAs_GameFightFighterMonsterLightInformations(Reader *input)
{
  GameFightFighterLightInformations::deserialize(input);
  this->_creatureGenericIdFunc(input);
}

void GameFightFighterMonsterLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterMonsterLightInformations(tree);
}

void GameFightFighterMonsterLightInformations::deserializeAsyncAs_GameFightFighterMonsterLightInformations(FuncTree tree)
{
  GameFightFighterLightInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightFighterMonsterLightInformations::_creatureGenericIdFunc, this, std::placeholders::_1));
}

void GameFightFighterMonsterLightInformations::_creatureGenericIdFunc(Reader *input)
{
  this->creatureGenericId = input->readVarUhShort();
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterMonsterLightInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element of GameFightFighterMonsterLightInformations.creatureGenericId.";
  }
}

GameFightFighterMonsterLightInformations::GameFightFighterMonsterLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERMONSTERLIGHTINFORMATIONS;
}

bool GameFightFighterMonsterLightInformations::operator==(const GameFightFighterMonsterLightInformations &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  return true;
  
  return false;
}

