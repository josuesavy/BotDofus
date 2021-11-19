#include "GameRolePlayMutantInformations.h"

void GameRolePlayMutantInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayMutantInformations(output);
}

void GameRolePlayMutantInformations::serializeAs_GameRolePlayMutantInformations(Writer *output)
{
  GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(output);
  if(this->monsterId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMutantInformations -"<<"Forbidden value (" << this->monsterId << ") on element monsterId.";
  }
  output->writeVarShort((int)this->monsterId);
  output->writeByte(this->powerLevel);
}

void GameRolePlayMutantInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayMutantInformations(input);
}

void GameRolePlayMutantInformations::deserializeAs_GameRolePlayMutantInformations(Reader *input)
{
  GameRolePlayHumanoidInformations::deserialize(input);
  this->_monsterIdFunc(input);
  this->_powerLevelFunc(input);
}

void GameRolePlayMutantInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayMutantInformations(tree);
}

void GameRolePlayMutantInformations::deserializeAsyncAs_GameRolePlayMutantInformations(FuncTree tree)
{
  GameRolePlayHumanoidInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayMutantInformations::_monsterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayMutantInformations::_powerLevelFunc, this, std::placeholders::_1));
}

void GameRolePlayMutantInformations::_monsterIdFunc(Reader *input)
{
  this->monsterId = input->readVarUhShort();
  if(this->monsterId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMutantInformations -"<<"Forbidden value (" << this->monsterId << ") on element of GameRolePlayMutantInformations.monsterId.";
  }
}

void GameRolePlayMutantInformations::_powerLevelFunc(Reader *input)
{
  this->powerLevel = input->readByte();
}

GameRolePlayMutantInformations::GameRolePlayMutantInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMUTANTINFORMATIONS;
}

bool GameRolePlayMutantInformations::operator==(const GameRolePlayMutantInformations &compared)
{
  if(monsterId == compared.monsterId)
  if(powerLevel == compared.powerLevel)
  return true;
  
  return false;
}

