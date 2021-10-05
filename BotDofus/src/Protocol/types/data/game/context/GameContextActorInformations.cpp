#include "GameContextActorInformations.h"

void GameContextActorInformations::serialize(Writer *output)
{
  this->serializeAs_GameContextActorInformations(output);
}

void GameContextActorInformations::serializeAs_GameContextActorInformations(Writer *output)
{
  GameContextActorPositionInformations::serializeAs_GameContextActorPositionInformations(output);
  this->look->serializeAs_EntityLook(output);
}

void GameContextActorInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameContextActorInformations(input);
}

void GameContextActorInformations::deserializeAs_GameContextActorInformations(Reader *input)
{
  GameContextActorPositionInformations::deserialize(input);
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(input);
}

void GameContextActorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextActorInformations(tree);
}

void GameContextActorInformations::deserializeAsyncAs_GameContextActorInformations(FuncTree tree)
{
  GameContextActorPositionInformations::deserializeAsync(tree);
  this->_looktree = tree.addChild(std::bind(&GameContextActorInformations::_looktreeFunc, this, std::placeholders::_1));
}

void GameContextActorInformations::_looktreeFunc(Reader *input)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserializeAsync(this->_looktree);
}

GameContextActorInformations::GameContextActorInformations()
{
  m_types<<ClassEnum::GAMECONTEXTACTORINFORMATIONS;
}

bool GameContextActorInformations::operator==(const GameContextActorInformations &compared)
{
  if(look == compared.look)
  if(_looktree == compared._looktree)
  return true;
  
  return false;
}

