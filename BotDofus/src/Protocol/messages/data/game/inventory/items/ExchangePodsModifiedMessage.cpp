#include "ExchangePodsModifiedMessage.h"

void ExchangePodsModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangePodsModifiedMessage(output);
}

void ExchangePodsModifiedMessage::serializeAs_ExchangePodsModifiedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->currentWeight << ") on element currentWeight.";
  }
  output->writeVarInt((int)this->currentWeight);
  if(this->maxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->maxWeight << ") on element maxWeight.";
  }
  output->writeVarInt((int)this->maxWeight);
}

void ExchangePodsModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangePodsModifiedMessage(input);
}

void ExchangePodsModifiedMessage::deserializeAs_ExchangePodsModifiedMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->_currentWeightFunc(input);
  this->_maxWeightFunc(input);
}

void ExchangePodsModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangePodsModifiedMessage(tree);
}

void ExchangePodsModifiedMessage::deserializeAsyncAs_ExchangePodsModifiedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangePodsModifiedMessage::_currentWeightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangePodsModifiedMessage::_maxWeightFunc, this, std::placeholders::_1));
}

void ExchangePodsModifiedMessage::_currentWeightFunc(Reader *input)
{
  this->currentWeight = input->readVarUhInt();
  if(this->currentWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->currentWeight << ") on element of ExchangePodsModifiedMessage.currentWeight.";
  }
}

void ExchangePodsModifiedMessage::_maxWeightFunc(Reader *input)
{
  this->maxWeight = input->readVarUhInt();
  if(this->maxWeight < 0)
  {
    qDebug()<<"ERREUR - ExchangePodsModifiedMessage -"<<"Forbidden value (" << this->maxWeight << ") on element of ExchangePodsModifiedMessage.maxWeight.";
  }
}

ExchangePodsModifiedMessage::ExchangePodsModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEPODSMODIFIEDMESSAGE;
}

