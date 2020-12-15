#include "GameMapChangeOrientationRequestMessage.h"

void GameMapChangeOrientationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameMapChangeOrientationRequestMessage(output);
}

void GameMapChangeOrientationRequestMessage::serializeAs_GameMapChangeOrientationRequestMessage(Writer *output)
{
  output->writeByte(this->direction);
}

void GameMapChangeOrientationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameMapChangeOrientationRequestMessage(input);
}

void GameMapChangeOrientationRequestMessage::deserializeAs_GameMapChangeOrientationRequestMessage(Reader *input)
{
  this->_directionFunc(input);
}

void GameMapChangeOrientationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameMapChangeOrientationRequestMessage(tree);
}

void GameMapChangeOrientationRequestMessage::deserializeAsyncAs_GameMapChangeOrientationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameMapChangeOrientationRequestMessage::_directionFunc, this, std::placeholders::_1));
}

void GameMapChangeOrientationRequestMessage::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - GameMapChangeOrientationRequestMessage -"<<"Forbidden value (" << this->direction << ") on element of GameMapChangeOrientationRequestMessage.direction.";
  }
}

GameMapChangeOrientationRequestMessage::GameMapChangeOrientationRequestMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE;
}

