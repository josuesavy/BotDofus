#include "GameCautiousMapMovementMessage.h"

void GameCautiousMapMovementMessage::serialize(Writer *output)
{
  this->serializeAs_GameCautiousMapMovementMessage(output);
}

void GameCautiousMapMovementMessage::serializeAs_GameCautiousMapMovementMessage(Writer *output)
{
  GameMapMovementMessage::serializeAs_GameMapMovementMessage(output);
}

void GameCautiousMapMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameCautiousMapMovementMessage(input);
}

void GameCautiousMapMovementMessage::deserializeAs_GameCautiousMapMovementMessage(Reader *input)
{
  GameMapMovementMessage::deserialize(input);
}

void GameCautiousMapMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameCautiousMapMovementMessage(tree);
}

void GameCautiousMapMovementMessage::deserializeAsyncAs_GameCautiousMapMovementMessage(FuncTree tree)
{
  GameMapMovementMessage::deserializeAsync(tree);
}

GameCautiousMapMovementMessage::GameCautiousMapMovementMessage()
{
  m_type = MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE;
}

