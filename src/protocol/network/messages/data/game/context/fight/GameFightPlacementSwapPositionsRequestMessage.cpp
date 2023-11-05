#include "GameFightPlacementSwapPositionsRequestMessage.h"

void GameFightPlacementSwapPositionsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsRequestMessage(output);
}

void GameFightPlacementSwapPositionsRequestMessage::serializeAs_GameFightPlacementSwapPositionsRequestMessage(Writer *output)
{
  GameFightPlacementPositionRequestMessage::serializeAs_GameFightPlacementPositionRequestMessage(output);
  if(this->requestedId < -9007199254740992 || this->requestedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsRequestMessage -"<<"Forbidden value (" << this->requestedId << ") on element requestedId.";
  }
  output->writeDouble(this->requestedId);
}

void GameFightPlacementSwapPositionsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsRequestMessage(input);
}

void GameFightPlacementSwapPositionsRequestMessage::deserializeAs_GameFightPlacementSwapPositionsRequestMessage(Reader *input)
{
  GameFightPlacementPositionRequestMessage::deserialize(input);
  this->_requestedIdFunc(input);
}

void GameFightPlacementSwapPositionsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsRequestMessage(tree);
}

void GameFightPlacementSwapPositionsRequestMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsRequestMessage(FuncTree tree)
{
  GameFightPlacementPositionRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsRequestMessage::_requestedIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsRequestMessage::_requestedIdFunc(Reader *input)
{
  this->requestedId = input->readDouble();
  if(this->requestedId < -9007199254740992 || this->requestedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsRequestMessage -"<<"Forbidden value (" << this->requestedId << ") on element of GameFightPlacementSwapPositionsRequestMessage.requestedId.";
  }
}

GameFightPlacementSwapPositionsRequestMessage::GameFightPlacementSwapPositionsRequestMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE;
}

