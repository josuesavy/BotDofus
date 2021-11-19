#include "GameFightPlacementSwapPositionsCancelMessage.h"

void GameFightPlacementSwapPositionsCancelMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsCancelMessage(output);
}

void GameFightPlacementSwapPositionsCancelMessage::serializeAs_GameFightPlacementSwapPositionsCancelMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeInt((int)this->requestId);
}

void GameFightPlacementSwapPositionsCancelMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsCancelMessage(input);
}

void GameFightPlacementSwapPositionsCancelMessage::deserializeAs_GameFightPlacementSwapPositionsCancelMessage(Reader *input)
{
  this->_requestIdFunc(input);
}

void GameFightPlacementSwapPositionsCancelMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsCancelMessage(tree);
}

void GameFightPlacementSwapPositionsCancelMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsCancelMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsCancelMessage::_requestIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsCancelMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsCancelMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsCancelMessage.requestId.";
  }
}

GameFightPlacementSwapPositionsCancelMessage::GameFightPlacementSwapPositionsCancelMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE;
}

