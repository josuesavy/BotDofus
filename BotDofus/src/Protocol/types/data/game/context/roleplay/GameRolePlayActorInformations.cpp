#include "GameRolePlayActorInformations.h"

void GameRolePlayActorInformations::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayActorInformations(output);
}

void GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(Writer *output)
{
  GameContextActorInformations::serializeAs_GameContextActorInformations(output);
}

void GameRolePlayActorInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayActorInformations(input);
}

void GameRolePlayActorInformations::deserializeAs_GameRolePlayActorInformations(Reader *input)
{
  GameContextActorInformations::deserialize(input);
}

void GameRolePlayActorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayActorInformations(tree);
}

void GameRolePlayActorInformations::deserializeAsyncAs_GameRolePlayActorInformations(FuncTree tree)
{
  GameContextActorInformations::deserializeAsync(tree);
}

GameRolePlayActorInformations::GameRolePlayActorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYACTORINFORMATIONS;
}

bool GameRolePlayActorInformations::operator==(const GameRolePlayActorInformations &compared)
{
  return true;
}

