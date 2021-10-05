#include "ExchangeWeightMessage.h"

void ExchangeWeightMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeWeightMessage(output);
}

void ExchangeWeightMessage::serializeAs_ExchangeWeightMessage(Writer *output)
{
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->currentWeight << ") on element currentWeight.";
  }
  output->writeVarInt((int)this->currentWeight);
  if(this->maxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->maxWeight << ") on element maxWeight.";
  }
  output->writeVarInt((int)this->maxWeight);
}

void ExchangeWeightMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeWeightMessage(input);
}

void ExchangeWeightMessage::deserializeAs_ExchangeWeightMessage(Reader *input)
{
  this->_currentWeightFunc(input);
  this->_maxWeightFunc(input);
}

void ExchangeWeightMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeWeightMessage(tree);
}

void ExchangeWeightMessage::deserializeAsyncAs_ExchangeWeightMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeWeightMessage::_currentWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeWeightMessage::_maxWeightFunc, this, std::placeholders::_1));
}

void ExchangeWeightMessage::_currentWeightFunc(Reader *input)
{
  this->currentWeight = input->readVarUhInt();
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->currentWeight << ") on element of ExchangeWeightMessage.currentWeight.";
  }
}

void ExchangeWeightMessage::_maxWeightFunc(Reader *input)
{
  this->maxWeight = input->readVarUhInt();
  if(this->maxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangeWeightMessage -"<<"Forbidden value (" << this->maxWeight << ") on element of ExchangeWeightMessage.maxWeight.";
  }
}

ExchangeWeightMessage::ExchangeWeightMessage()
{
  m_type = MessageEnum::EXCHANGEWEIGHTMESSAGE;
}

