#include "GameRolePlayTreasureHintInformations.h"

void GameRolePlayTreasureHintInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayTreasureHintInformations(output);
}

void GameRolePlayTreasureHintInformations::serializeAs_GameRolePlayTreasureHintInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayTreasureHintInformations -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  output->writeVarShort((int)this->npcId);
}

void GameRolePlayTreasureHintInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayTreasureHintInformations(input);
}

void GameRolePlayTreasureHintInformations::deserializeAs_GameRolePlayTreasureHintInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  this->_npcIdFunc(input);
}

void GameRolePlayTreasureHintInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayTreasureHintInformations(tree);
}

void GameRolePlayTreasureHintInformations::deserializeAsyncAs_GameRolePlayTreasureHintInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayTreasureHintInformations::_npcIdFunc, this, std::placeholders::_1));
}

void GameRolePlayTreasureHintInformations::_npcIdFunc(Reader *input)
{
  this->npcId = input->readVarUhShort();
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayTreasureHintInformations -"<<"Forbidden value (" << this->npcId << ") on element of GameRolePlayTreasureHintInformations.npcId.";
  }
}

GameRolePlayTreasureHintInformations::GameRolePlayTreasureHintInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYTREASUREHINTINFORMATIONS;
}

bool GameRolePlayTreasureHintInformations::operator==(const GameRolePlayTreasureHintInformations &compared)
{
  if(npcId == compared.npcId)
  return true;
  
  return false;
}

