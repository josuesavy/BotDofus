#include "GameFightMonsterInformations.h"

void GameFightMonsterInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightMonsterInformations(output);
}

void GameFightMonsterInformations::serializeAs_GameFightMonsterInformations(Writer *output)
{
  GameFightAIInformations::serializeAs_GameFightAIInformations(output);
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element creatureGenericId.";
  }
  output->writeVarShort((int)this->creatureGenericId);
  if(this->creatureGrade < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGrade << ") on element creatureGrade.";
  }
  output->writeByte(this->creatureGrade);
  if(this->creatureLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureLevel << ") on element creatureLevel.";
  }
  output->writeShort((short)this->creatureLevel);
}

void GameFightMonsterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightMonsterInformations(input);
}

void GameFightMonsterInformations::deserializeAs_GameFightMonsterInformations(Reader *input)
{
  GameFightAIInformations::deserialize(input);
  this->_creatureGenericIdFunc(input);
  this->_creatureGradeFunc(input);
  this->_creatureLevelFunc(input);
}

void GameFightMonsterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightMonsterInformations(tree);
}

void GameFightMonsterInformations::deserializeAsyncAs_GameFightMonsterInformations(FuncTree tree)
{
  GameFightAIInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightMonsterInformations::_creatureGenericIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMonsterInformations::_creatureGradeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightMonsterInformations::_creatureLevelFunc, this, std::placeholders::_1));
}

void GameFightMonsterInformations::_creatureGenericIdFunc(Reader *input)
{
  this->creatureGenericId = input->readVarUhShort();
  if(this->creatureGenericId < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGenericId << ") on element of GameFightMonsterInformations.creatureGenericId.";
  }
}

void GameFightMonsterInformations::_creatureGradeFunc(Reader *input)
{
  this->creatureGrade = input->readByte();
  if(this->creatureGrade < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureGrade << ") on element of GameFightMonsterInformations.creatureGrade.";
  }
}

void GameFightMonsterInformations::_creatureLevelFunc(Reader *input)
{
  this->creatureLevel = input->readShort();
  if(this->creatureLevel < 0)
  {
    qDebug()<<"ERREUR - GameFightMonsterInformations -"<<"Forbidden value (" << this->creatureLevel << ") on element of GameFightMonsterInformations.creatureLevel.";
  }
}

GameFightMonsterInformations::GameFightMonsterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMONSTERINFORMATIONS;
}

bool GameFightMonsterInformations::operator==(const GameFightMonsterInformations &compared)
{
  if(creatureGenericId == compared.creatureGenericId)
  if(creatureGrade == compared.creatureGrade)
  if(creatureLevel == compared.creatureLevel)
  return true;
  
  return false;
}

