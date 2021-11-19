#include "GameFightTaxCollectorInformations.h"

void GameFightTaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightTaxCollectorInformations(output);
}

void GameFightTaxCollectorInformations::serializeAs_GameFightTaxCollectorInformations(Writer *output)
{
  GameFightAIInformations::serializeAs_GameFightAIInformations(output);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
}

void GameFightTaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTaxCollectorInformations(input);
}

void GameFightTaxCollectorInformations::deserializeAs_GameFightTaxCollectorInformations(Reader *input)
{
  GameFightAIInformations::deserialize(input);
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->_levelFunc(input);
}

void GameFightTaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTaxCollectorInformations(tree);
}

void GameFightTaxCollectorInformations::deserializeAsyncAs_GameFightTaxCollectorInformations(FuncTree tree)
{
  GameFightAIInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightTaxCollectorInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightTaxCollectorInformations::_lastNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightTaxCollectorInformations::_levelFunc, this, std::placeholders::_1));
}

void GameFightTaxCollectorInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of GameFightTaxCollectorInformations.firstNameId.";
  }
}

void GameFightTaxCollectorInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of GameFightTaxCollectorInformations.lastNameId.";
  }
}

void GameFightTaxCollectorInformations::_levelFunc(Reader *input)
{
  this->level = input->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameFightTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightTaxCollectorInformations.level.";
  }
}

GameFightTaxCollectorInformations::GameFightTaxCollectorInformations()
{
  m_types<<ClassEnum::GAMEFIGHTTAXCOLLECTORINFORMATIONS;
}

bool GameFightTaxCollectorInformations::operator==(const GameFightTaxCollectorInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(level == compared.level)
  return true;
  
  return false;
}

