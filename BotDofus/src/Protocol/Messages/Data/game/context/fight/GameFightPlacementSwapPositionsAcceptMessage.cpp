#include "GameFightPlacementSwapPositionsAcceptMessage.h"

void GameFightPlacementSwapPositionsAcceptMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsAcceptMessage(output);
}

void GameFightPlacementSwapPositionsAcceptMessage::serializeAs_GameFightPlacementSwapPositionsAcceptMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsAcceptMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeInt((int)this->requestId);
}

void GameFightPlacementSwapPositionsAcceptMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(input);
}

void GameFightPlacementSwapPositionsAcceptMessage::deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(Reader *input)
{
  this->_requestIdFunc(input);
}

void GameFightPlacementSwapPositionsAcceptMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsAcceptMessage(tree);
}

void GameFightPlacementSwapPositionsAcceptMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsAcceptMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsAcceptMessage::_requestIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsAcceptMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsAcceptMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsAcceptMessage.requestId.";
  }
}

GameFightPlacementSwapPositionsAcceptMessage::GameFightPlacementSwapPositionsAcceptMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE;
}

