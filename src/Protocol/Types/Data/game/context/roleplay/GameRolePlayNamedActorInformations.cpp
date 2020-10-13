#include "GameRolePlayNamedActorInformations.h"

void GameRolePlayNamedActorInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayNamedActorInformations(output);
}

void GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(Writer *output)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(output);
  output->writeUTF(this->name);
}

void GameRolePlayNamedActorInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayNamedActorInformations(input);
}

void GameRolePlayNamedActorInformations::deserializeAs_GameRolePlayNamedActorInformations(Reader *input)
{
  GameRolePlayActorInformations::deserialize(input);
  this->_nameFunc(input);
}

void GameRolePlayNamedActorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayNamedActorInformations(tree);
}

void GameRolePlayNamedActorInformations::deserializeAsyncAs_GameRolePlayNamedActorInformations(FuncTree tree)
{
  GameRolePlayActorInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GameRolePlayNamedActorInformations::_nameFunc, this, std::placeholders::_1));
}

void GameRolePlayNamedActorInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

GameRolePlayNamedActorInformations::GameRolePlayNamedActorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYNAMEDACTORINFORMATIONS;
}

bool GameRolePlayNamedActorInformations::operator==(const GameRolePlayNamedActorInformations &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

