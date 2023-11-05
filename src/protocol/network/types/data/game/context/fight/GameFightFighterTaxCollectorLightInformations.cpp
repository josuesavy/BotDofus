#include "GameFightFighterTaxCollectorLightInformations.h"

void GameFightFighterTaxCollectorLightInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightFighterTaxCollectorLightInformations(output);
}

void GameFightFighterTaxCollectorLightInformations::serializeAs_GameFightFighterTaxCollectorLightInformations(Writer *output)
{
  GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(output);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
}

void GameFightFighterTaxCollectorLightInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightFighterTaxCollectorLightInformations(input);
}

void GameFightFighterTaxCollectorLightInformations::deserializeAs_GameFightFighterTaxCollectorLightInformations(Reader *input)
{
  GameFightFighterLightInformations::deserialize(input);
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
}

void GameFightFighterTaxCollectorLightInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightFighterTaxCollectorLightInformations(tree);
}

void GameFightFighterTaxCollectorLightInformations::deserializeAsyncAs_GameFightFighterTaxCollectorLightInformations(FuncTree tree)
{
  GameFightFighterLightInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightFighterTaxCollectorLightInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightFighterTaxCollectorLightInformations::_lastNameIdFunc, this, std::placeholders::_1));
}

void GameFightFighterTaxCollectorLightInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of GameFightFighterTaxCollectorLightInformations.firstNameId.";
  }
}

void GameFightFighterTaxCollectorLightInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterTaxCollectorLightInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of GameFightFighterTaxCollectorLightInformations.lastNameId.";
  }
}

GameFightFighterTaxCollectorLightInformations::GameFightFighterTaxCollectorLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERTAXCOLLECTORLIGHTINFORMATIONS;
}

bool GameFightFighterTaxCollectorLightInformations::operator==(const GameFightFighterTaxCollectorLightInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  return true;
  
  return false;
}

