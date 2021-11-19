#include "GameMapNoMovementMessage.h"

void GameMapNoMovementMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapNoMovementMessage(output);
}

void GameMapNoMovementMessage::serializeAs_GameMapNoMovementMessage(Writer *output)
{
  output->writeShort((short)this->cellX);
  output->writeShort((short)this->cellY);
}

void GameMapNoMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapNoMovementMessage(input);
}

void GameMapNoMovementMessage::deserializeAs_GameMapNoMovementMessage(Reader *input)
{
  this->_cellXFunc(input);
  this->_cellYFunc(input);
}

void GameMapNoMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapNoMovementMessage(tree);
}

void GameMapNoMovementMessage::deserializeAsyncAs_GameMapNoMovementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameMapNoMovementMessage::_cellXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameMapNoMovementMessage::_cellYFunc, this, std::placeholders::_1));
}

void GameMapNoMovementMessage::_cellXFunc(Reader *input)
{
  this->cellX = input->readShort();
}

void GameMapNoMovementMessage::_cellYFunc(Reader *input)
{
  this->cellY = input->readShort();
}

GameMapNoMovementMessage::GameMapNoMovementMessage()
{
  m_type = MessageEnum::GAMEMAPNOMOVEMENTMESSAGE;
}

