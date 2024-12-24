#include "GameFightAIInformations.h"

void GameFightAIInformations::serialize(Writer *output)
{
  this->serializeAs_GameFightAIInformations(output);
}

void GameFightAIInformations::serializeAs_GameFightAIInformations(Writer *output)
{
  GameFightFighterInformations::serializeAs_GameFightFighterInformations(output);
}

void GameFightAIInformations::deserialize(Reader *input)
{
  this->deserializeAs_GameFightAIInformations(input);
}

void GameFightAIInformations::deserializeAs_GameFightAIInformations(Reader *input)
{
  GameFightFighterInformations::deserialize(input);
}

void GameFightAIInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightAIInformations(tree);
}

void GameFightAIInformations::deserializeAsyncAs_GameFightAIInformations(FuncTree tree)
{
  GameFightFighterInformations::deserializeAsync(tree);
}

GameFightAIInformations::GameFightAIInformations()
{
  m_types<<ClassEnum::GAMEFIGHTAIINFORMATIONS;
}

bool GameFightAIInformations::operator==(const GameFightAIInformations &compared)
{
  return true;
}

