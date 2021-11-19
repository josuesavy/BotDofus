#include "GameContextMoveElementMessage.h"

void GameContextMoveElementMessage::serialize(Writer *output)
{
  this->serializeAs_GameContextMoveElementMessage(output);
}

void GameContextMoveElementMessage::serializeAs_GameContextMoveElementMessage(Writer *output)
{
  this->movement.serializeAs_EntityMovementInformations(output);
}

void GameContextMoveElementMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameContextMoveElementMessage(input);
}

void GameContextMoveElementMessage::deserializeAs_GameContextMoveElementMessage(Reader *input)
{
  this->movement = EntityMovementInformations();
  this->movement.deserialize(input);
}

void GameContextMoveElementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameContextMoveElementMessage(tree);
}

void GameContextMoveElementMessage::deserializeAsyncAs_GameContextMoveElementMessage(FuncTree tree)
{
  this->_movementtree = tree.addChild(std::bind(&GameContextMoveElementMessage::_movementtreeFunc, this, std::placeholders::_1));
}

void GameContextMoveElementMessage::_movementtreeFunc(Reader *input)
{
  this->movement = EntityMovementInformations();
  this->movement.deserializeAsync(this->_movementtree);
}

GameContextMoveElementMessage::GameContextMoveElementMessage()
{
  m_type = MessageEnum::GAMECONTEXTMOVEELEMENTMESSAGE;
}

