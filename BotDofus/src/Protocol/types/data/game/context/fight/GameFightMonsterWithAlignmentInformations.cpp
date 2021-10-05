#include "GameFightMonsterWithAlignmentInformations.h"

void GameFightMonsterWithAlignmentInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightMonsterWithAlignmentInformations(output);
}

void GameFightMonsterWithAlignmentInformations::serializeAs_GameFightMonsterWithAlignmentInformations(Writer *output)
{
  GameFightMonsterInformations::serializeAs_GameFightMonsterInformations(output);
  this->alignmentInfos.serializeAs_ActorAlignmentInformations(output);
}

void GameFightMonsterWithAlignmentInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightMonsterWithAlignmentInformations(input);
}

void GameFightMonsterWithAlignmentInformations::deserializeAs_GameFightMonsterWithAlignmentInformations(Reader *input)
{
  GameFightMonsterInformations::deserialize(input);
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserialize(input);
}

void GameFightMonsterWithAlignmentInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightMonsterWithAlignmentInformations(tree);
}

void GameFightMonsterWithAlignmentInformations::deserializeAsyncAs_GameFightMonsterWithAlignmentInformations(FuncTree tree)
{
  GameFightMonsterInformations::deserializeAsync(tree);
  this->_alignmentInfostree = tree.addChild(std::bind(&GameFightMonsterWithAlignmentInformations::_alignmentInfostreeFunc, this, std::placeholders::_1));
}

void GameFightMonsterWithAlignmentInformations::_alignmentInfostreeFunc(Reader *input)
{
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserializeAsync(this->_alignmentInfostree);
}

GameFightMonsterWithAlignmentInformations::GameFightMonsterWithAlignmentInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS;
}

bool GameFightMonsterWithAlignmentInformations::operator==(const GameFightMonsterWithAlignmentInformations &compared)
{
  if(alignmentInfos == compared.alignmentInfos)
  if(_alignmentInfostree == compared._alignmentInfostree)
  return true;
  
  return false;
}

