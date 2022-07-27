#include "GameCautiousMapMovementRequestMessage.h"

void GameCautiousMapMovementRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameCautiousMapMovementRequestMessage(output);
}

void GameCautiousMapMovementRequestMessage::serializeAs_GameCautiousMapMovementRequestMessage(Writer *output)
{
  GameMapMovementRequestMessage::serializeAs_GameMapMovementRequestMessage(output);
}

void GameCautiousMapMovementRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameCautiousMapMovementRequestMessage(input);
}

void GameCautiousMapMovementRequestMessage::deserializeAs_GameCautiousMapMovementRequestMessage(Reader *input)
{
  GameMapMovementRequestMessage::deserialize(input);
}

void GameCautiousMapMovementRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameCautiousMapMovementRequestMessage(tree);
}

void GameCautiousMapMovementRequestMessage::deserializeAsyncAs_GameCautiousMapMovementRequestMessage(FuncTree tree)
{
  GameMapMovementRequestMessage::deserializeAsync(tree);
}

GameCautiousMapMovementRequestMessage::GameCautiousMapMovementRequestMessage()
{
  m_type = MessageEnum::GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE;
  m_needsHash = true;
}

