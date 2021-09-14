#include "GameMapSpeedMovementMessage.h"

void GameMapSpeedMovementMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapSpeedMovementMessage(output);
}

void GameMapSpeedMovementMessage::serializeAs_GameMapSpeedMovementMessage(Writer *output)
{
  output->writeInt((int)this->speedMultiplier);
}

void GameMapSpeedMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapSpeedMovementMessage(input);
}

void GameMapSpeedMovementMessage::deserializeAs_GameMapSpeedMovementMessage(Reader *input)
{
  this->_speedMultiplierFunc(input);
}

void GameMapSpeedMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapSpeedMovementMessage(tree);
}

void GameMapSpeedMovementMessage::deserializeAsyncAs_GameMapSpeedMovementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameMapSpeedMovementMessage::_speedMultiplierFunc, this, std::placeholders::_1));
}

void GameMapSpeedMovementMessage::_speedMultiplierFunc(Reader *input)
{
  this->speedMultiplier = input->readInt();
}

GameMapSpeedMovementMessage::GameMapSpeedMovementMessage()
{
  m_type = MessageEnum::GAMEMAPSPEEDMOVEMENTMESSAGE;
}

