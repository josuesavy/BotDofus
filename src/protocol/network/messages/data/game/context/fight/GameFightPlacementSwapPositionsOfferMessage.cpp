#include "GameFightPlacementSwapPositionsOfferMessage.h"

void GameFightPlacementSwapPositionsOfferMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightPlacementSwapPositionsOfferMessage(output);
}

void GameFightPlacementSwapPositionsOfferMessage::serializeAs_GameFightPlacementSwapPositionsOfferMessage(Writer *output)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  output->writeInt((int)this->requestId);
  if(this->requesterId < -9007199254740992 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element requesterId.";
  }
  output->writeDouble(this->requesterId);
  if(this->requesterCellId < 0 || this->requesterCellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterCellId << ") on element requesterCellId.";
  }
  output->writeVarShort((int)this->requesterCellId);
  if(this->requestedId < -9007199254740992 || this->requestedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedId << ") on element requestedId.";
  }
  output->writeDouble(this->requestedId);
  if(this->requestedCellId < 0 || this->requestedCellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedCellId << ") on element requestedCellId.";
  }
  output->writeVarShort((int)this->requestedCellId);
}

void GameFightPlacementSwapPositionsOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightPlacementSwapPositionsOfferMessage(input);
}

void GameFightPlacementSwapPositionsOfferMessage::deserializeAs_GameFightPlacementSwapPositionsOfferMessage(Reader *input)
{
  this->_requestIdFunc(input);
  this->_requesterIdFunc(input);
  this->_requesterCellIdFunc(input);
  this->_requestedIdFunc(input);
  this->_requestedCellIdFunc(input);
}

void GameFightPlacementSwapPositionsOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightPlacementSwapPositionsOfferMessage(tree);
}

void GameFightPlacementSwapPositionsOfferMessage::deserializeAsyncAs_GameFightPlacementSwapPositionsOfferMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsOfferMessage::_requestIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsOfferMessage::_requesterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsOfferMessage::_requesterCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsOfferMessage::_requestedIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightPlacementSwapPositionsOfferMessage::_requestedCellIdFunc, this, std::placeholders::_1));
}

void GameFightPlacementSwapPositionsOfferMessage::_requestIdFunc(Reader *input)
{
  this->requestId = input->readInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestId.";
  }
}

void GameFightPlacementSwapPositionsOfferMessage::_requesterIdFunc(Reader *input)
{
  this->requesterId = input->readDouble();
  if(this->requesterId < -9007199254740992 || this->requesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requesterId.";
  }
}

void GameFightPlacementSwapPositionsOfferMessage::_requesterCellIdFunc(Reader *input)
{
  this->requesterCellId = input->readVarUhShort();
  if(this->requesterCellId < 0 || this->requesterCellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requesterCellId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requesterCellId.";
  }
}

void GameFightPlacementSwapPositionsOfferMessage::_requestedIdFunc(Reader *input)
{
  this->requestedId = input->readDouble();
  if(this->requestedId < -9007199254740992 || this->requestedId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestedId.";
  }
}

void GameFightPlacementSwapPositionsOfferMessage::_requestedCellIdFunc(Reader *input)
{
  this->requestedCellId = input->readVarUhShort();
  if(this->requestedCellId < 0 || this->requestedCellId > 559)
  {
    qDebug()<<"ERREUR - GameFightPlacementSwapPositionsOfferMessage -"<<"Forbidden value (" << this->requestedCellId << ") on element of GameFightPlacementSwapPositionsOfferMessage.requestedCellId.";
  }
}

GameFightPlacementSwapPositionsOfferMessage::GameFightPlacementSwapPositionsOfferMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE;
}

