#include "GameRolePlayNpcWithQuestInformations.h"

void GameRolePlayNpcWithQuestInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayNpcWithQuestInformations(output);
}

void GameRolePlayNpcWithQuestInformations::serializeAs_GameRolePlayNpcWithQuestInformations(Writer *output)
{
  GameRolePlayNpcInformations::serializeAs_GameRolePlayNpcInformations(output);
  this->questFlag.serializeAs_GameRolePlayNpcQuestFlag(output);
}

void GameRolePlayNpcWithQuestInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayNpcWithQuestInformations(input);
}

void GameRolePlayNpcWithQuestInformations::deserializeAs_GameRolePlayNpcWithQuestInformations(Reader *input)
{
  GameRolePlayNpcInformations::deserialize(input);
  this->questFlag = GameRolePlayNpcQuestFlag();
  this->questFlag.deserialize(input);
}

void GameRolePlayNpcWithQuestInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayNpcWithQuestInformations(tree);
}

void GameRolePlayNpcWithQuestInformations::deserializeAsyncAs_GameRolePlayNpcWithQuestInformations(FuncTree tree)
{
  GameRolePlayNpcInformations::deserializeAsync(tree);
  this->_questFlagtree = tree.addChild(std::bind(&GameRolePlayNpcWithQuestInformations::_questFlagtreeFunc, this, std::placeholders::_1));
}

void GameRolePlayNpcWithQuestInformations::_questFlagtreeFunc(Reader *input)
{
  this->questFlag = GameRolePlayNpcQuestFlag();
  this->questFlag.deserializeAsync(this->_questFlagtree);
}

GameRolePlayNpcWithQuestInformations::GameRolePlayNpcWithQuestInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNPCWITHQUESTINFORMATIONS;
}

bool GameRolePlayNpcWithQuestInformations::operator==(const GameRolePlayNpcWithQuestInformations &compared)
{
  if(questFlag == compared.questFlag)
  if(_questFlagtree == compared._questFlagtree)
  return true;
  
  return false;
}

