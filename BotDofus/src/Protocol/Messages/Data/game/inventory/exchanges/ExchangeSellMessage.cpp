#include "ExchangeSellMessage.h"

void ExchangeSellMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeSellMessage(output);
}

void ExchangeSellMessage::serializeAs_ExchangeSellMessage(Writer *output)
{
  if(this->objectToSellId < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->objectToSellId << ") on element objectToSellId.";
  }
  output->writeVarInt((int)this->objectToSellId);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ExchangeSellMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeSellMessage(input);
}

void ExchangeSellMessage::deserializeAs_ExchangeSellMessage(Reader *input)
{
  this->_objectToSellIdFunc(input);
  this->_quantityFunc(input);
}

void ExchangeSellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeSellMessage(tree);
}

void ExchangeSellMessage::deserializeAsyncAs_ExchangeSellMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeSellMessage::_objectToSellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeSellMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeSellMessage::_objectToSellIdFunc(Reader *input)
{
  this->objectToSellId = input->readVarUhInt();
  if(this->objectToSellId < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->objectToSellId << ") on element of ExchangeSellMessage.objectToSellId.";
  }
}

void ExchangeSellMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeSellMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeSellMessage.quantity.";
  }
}

ExchangeSellMessage::ExchangeSellMessage()
{
  m_type = MessageEnum::EXCHANGESELLMESSAGE;
}

