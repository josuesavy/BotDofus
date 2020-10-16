#include "GameFightPlacementSwapPositionsCancelledMessage.h"

void GameFightPlacementSwapPositionsCancelledMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsCancelledMessage(output);
}

void GameFightPlacementSwapPositionsCancelledMessage::serializeAs_GameFightPlacementSwapPositionsCancelledMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeInt((int)this->requestId);
  if(this->cancellerId < -9.007199254740992E15 || this->cancellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->cancellerId << ") on element cancellerId.";
  }
  output->writeDouble(this->cancellerId);
}

void GameFightPlacementSwapPositionsCancelledMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(input);
}

void GameFightPlacementSwapPositionsCancelledMessage::deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(Reader *input)
{
  this->_requestIdFunc(input);
  this->_cancellerIdFunc(input);
}

void GameFightPlacementSwapPositionsCancelledMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsCancelledMessage(tree);
}

void GameFightPlacementSwapPositionsCancelledMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsCancelledMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsCancelledMessage::_requestIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsCancelledMessage::_cancellerIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsCancelledMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsCancelledMessage.requestId.";
  }
}

void GameFightPlacementSwapPositionsCancelledMessage::_cancellerIdFunc(Reader *input)
{
  this->cancellerId = input->readDouble();
  if(this->cancellerId < -9.007199254740992E15 || this->cancellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelledMessage -"<<"Forbidden value (" << this->cancellerId << ") on element of GameFightPlacementSwapPositionsCancelledMessage.cancellerId.";
  }
}

GameFightPlacementSwapPositionsCancelledMessage::GameFightPlacementSwapPositionsCancelledMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE;
}

