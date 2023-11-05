#include "GameActionItemAddMessage.h"

void GameActionItemAddMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionItemAddMessage(output);
}

void GameActionItemAddMessage::serializeAs_GameActionItemAddMessage(Writer *output)
{
  this->newAction->serializeAs_GameActionItem(output);
}

void GameActionItemAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionItemAddMessage(input);
}

void GameActionItemAddMessage::deserializeAs_GameActionItemAddMessage(Reader *input)
{
  this->newAction = QSharedPointer<GameActionItem>(new GameActionItem() );
  this->newAction->deserialize(input);
}

void GameActionItemAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionItemAddMessage(tree);
}

void GameActionItemAddMessage::deserializeAsyncAs_GameActionItemAddMessage(FuncTree tree)
{
  this->_newActiontree = tree.addChild(std::bind(&GameActionItemAddMessage::_newActiontreeFunc, this, std::placeholders::_1));
}

void GameActionItemAddMessage::_newActiontreeFunc(Reader *input)
{
  this->newAction = QSharedPointer<GameActionItem>(new GameActionItem() );
  this->newAction->deserializeAsync(this->_newActiontree);
}

GameActionItemAddMessage::GameActionItemAddMessage()
{
  m_type = MessageEnum::GAMEACTIONITEMADDMESSAGE;
}

