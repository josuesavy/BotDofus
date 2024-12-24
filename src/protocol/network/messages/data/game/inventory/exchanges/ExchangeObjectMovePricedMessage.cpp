#include "ExchangeObjectMovePricedMessage.h"

void ExchangeObjectMovePricedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectMovePricedMessage(output);
}

void ExchangeObjectMovePricedMessage::serializeAs_ExchangeObjectMovePricedMessage(Writer *output)
{
  ExchangeObjectMoveMessage::serializeAs_ExchangeObjectMoveMessage(output);
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeObjectMovePricedMessage -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void ExchangeObjectMovePricedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectMovePricedMessage(input);
}

void ExchangeObjectMovePricedMessage::deserializeAs_ExchangeObjectMovePricedMessage(Reader *input)
{
  ExchangeObjectMoveMessage::deserialize(input);
  this->_priceFunc(input);
}

void ExchangeObjectMovePricedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectMovePricedMessage(tree);
}

void ExchangeObjectMovePricedMessage::deserializeAsyncAs_ExchangeObjectMovePricedMessage(FuncTree tree)
{
  ExchangeObjectMoveMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeObjectMovePricedMessage::_priceFunc, this, std::placeholders::_1));
}

void ExchangeObjectMovePricedMessage::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeObjectMovePricedMessage -"<<"Forbidden value (" << this->price << ") on element of ExchangeObjectMovePricedMessage.price.";
  }
}

ExchangeObjectMovePricedMessage::ExchangeObjectMovePricedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEPRICEDMESSAGE;
  m_needsHash = true;
}

