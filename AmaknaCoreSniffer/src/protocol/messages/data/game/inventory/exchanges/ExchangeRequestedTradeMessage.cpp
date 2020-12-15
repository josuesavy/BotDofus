#include "ExchangeRequestedTradeMessage.h"

void ExchangeRequestedTradeMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeRequestedTradeMessage(output);
}

void ExchangeRequestedTradeMessage::serializeAs_ExchangeRequestedTradeMessage(Writer *output)
{
  ExchangeRequestedMessage::serializeAs_ExchangeRequestedMessage(output);
  if(this->source < 0 || this->source > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->source << ") on element source.";
  }
  output->writeVarLong((double)this->source);
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->target << ") on element target.";
  }
  output->writeVarLong((double)this->target);
}

void ExchangeRequestedTradeMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeRequestedTradeMessage(input);
}

void ExchangeRequestedTradeMessage::deserializeAs_ExchangeRequestedTradeMessage(Reader *input)
{
  ExchangeRequestedMessage::deserialize(input);
  this->_sourceFunc(input);
  this->_targetFunc(input);
}

void ExchangeRequestedTradeMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeRequestedTradeMessage(tree);
}

void ExchangeRequestedTradeMessage::deserializeAsyncAs_ExchangeRequestedTradeMessage(FuncTree tree)
{
  ExchangeRequestedMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeRequestedTradeMessage::_sourceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeRequestedTradeMessage::_targetFunc, this, std::placeholders::_1));
}

void ExchangeRequestedTradeMessage::_sourceFunc(Reader *input)
{
  this->source = input->readVarUhLong();
  if(this->source < 0 || this->source > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->source << ") on element of ExchangeRequestedTradeMessage.source.";
  }
}

void ExchangeRequestedTradeMessage::_targetFunc(Reader *input)
{
  this->target = input->readVarUhLong();
  if(this->target < 0 || this->target > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeRequestedTradeMessage -"<<"Forbidden value (" << this->target << ") on element of ExchangeRequestedTradeMessage.target.";
  }
}

ExchangeRequestedTradeMessage::ExchangeRequestedTradeMessage()
{
  m_type = MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE;
}

