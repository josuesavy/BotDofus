#include "GameActionFightExchangePositionsMessage.h"

void GameActionFightExchangePositionsMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightExchangePositionsMessage(output);
}

void GameActionFightExchangePositionsMessage::serializeAs_GameActionFightExchangePositionsMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->casterCellId < -1 || this->casterCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->casterCellId << ") on element casterCellId.";
  }
  output->writeShort((short)this->casterCellId);
  if(this->targetCellId < -1 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
  }
  output->writeShort((short)this->targetCellId);
}

void GameActionFightExchangePositionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightExchangePositionsMessage(input);
}

void GameActionFightExchangePositionsMessage::deserializeAs_GameActionFightExchangePositionsMessage(Reader *input)
{
  AbstractGameActionMessage::deserialize(input);
  this->_targetIdFunc(input);
  this->_casterCellIdFunc(input);
  this->_targetCellIdFunc(input);
}

void GameActionFightExchangePositionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightExchangePositionsMessage(tree);
}

void GameActionFightExchangePositionsMessage::deserializeAsyncAs_GameActionFightExchangePositionsMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightExchangePositionsMessage::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightExchangePositionsMessage::_casterCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionFightExchangePositionsMessage::_targetCellIdFunc, this, std::placeholders::_1));
}

void GameActionFightExchangePositionsMessage::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightExchangePositionsMessage.targetId.";
  }
}

void GameActionFightExchangePositionsMessage::_casterCellIdFunc(Reader *input)
{
  this->casterCellId = input->readShort();
  if(this->casterCellId < -1 || this->casterCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->casterCellId << ") on element of GameActionFightExchangePositionsMessage.casterCellId.";
  }
}

void GameActionFightExchangePositionsMessage::_targetCellIdFunc(Reader *input)
{
  this->targetCellId = input->readShort();
  if(this->targetCellId < -1 || this->targetCellId > 559)
  {
    qDebug()<<"ERREUR - GameActionFightExchangePositionsMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameActionFightExchangePositionsMessage.targetCellId.";
  }
}

GameActionFightExchangePositionsMessage::GameActionFightExchangePositionsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE;
}

