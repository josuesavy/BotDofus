#include "GameRolePlayCharacterInformations.h"

void GameRolePlayCharacterInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayCharacterInformations(output);
}

void GameRolePlayCharacterInformations::serializeAs_GameRolePlayCharacterInformations(Writer *output)
{
  GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(output);
  this->alignmentInfos.serializeAs_ActorAlignmentInformations(output);
}

void GameRolePlayCharacterInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayCharacterInformations(input);
}

void GameRolePlayCharacterInformations::deserializeAs_GameRolePlayCharacterInformations(Reader *input)
{
  GameRolePlayHumanoidInformations::deserialize(input);
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserialize(input);
}

void GameRolePlayCharacterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayCharacterInformations(tree);
}

void GameRolePlayCharacterInformations::deserializeAsyncAs_GameRolePlayCharacterInformations(FuncTree tree)
{
  GameRolePlayHumanoidInformations::deserializeAsync(tree);
  this->_alignmentInfostree = tree.addChild(std::bind(&GameRolePlayCharacterInformations::_alignmentInfostreeFunc, this, std::placeholders::_1));
}

void GameRolePlayCharacterInformations::_alignmentInfostreeFunc(Reader *input)
{
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserializeAsync(this->_alignmentInfostree);
}

GameRolePlayCharacterInformations::GameRolePlayCharacterInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYCHARACTERINFORMATIONS;
}

bool GameRolePlayCharacterInformations::operator==(const GameRolePlayCharacterInformations &compared)
{
  if(alignmentInfos == compared.alignmentInfos)
  if(_alignmentInfostree == compared._alignmentInfostree)
  return true;
  
  return false;
}

