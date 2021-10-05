#include "GameMapChangeOrientationMessage.h"

void GameMapChangeOrientationMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapChangeOrientationMessage(output);
}

void GameMapChangeOrientationMessage::serializeAs_GameMapChangeOrientationMessage(Writer *output)
{
  this->orientation.serializeAs_ActorOrientation(output);
}

void GameMapChangeOrientationMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapChangeOrientationMessage(input);
}

void GameMapChangeOrientationMessage::deserializeAs_GameMapChangeOrientationMessage(Reader *input)
{
  this->orientation = ActorOrientation();
  this->orientation.deserialize(input);
}

void GameMapChangeOrientationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapChangeOrientationMessage(tree);
}

void GameMapChangeOrientationMessage::deserializeAsyncAs_GameMapChangeOrientationMessage(FuncTree tree)
{
  this->_orientationtree = tree.addChild(std::bind(&GameMapChangeOrientationMessage::_orientationtreeFunc, this, std::placeholders::_1));
}

void GameMapChangeOrientationMessage::_orientationtreeFunc(Reader *input)
{
  this->orientation = ActorOrientation();
  this->orientation.deserializeAsync(this->_orientationtree);
}

GameMapChangeOrientationMessage::GameMapChangeOrientationMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONMESSAGE;
}

