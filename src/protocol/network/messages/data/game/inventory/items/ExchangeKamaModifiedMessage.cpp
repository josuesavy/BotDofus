#include "ExchangeKamaModifiedMessage.h"

void ExchangeKamaModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeKamaModifiedMessage(output);
}

void ExchangeKamaModifiedMessage::serializeAs_ExchangeKamaModifiedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  if(this->quantity < 0 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeKamaModifiedMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarLong((double)this->quantity);
}

void ExchangeKamaModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeKamaModifiedMessage(input);
}

void ExchangeKamaModifiedMessage::deserializeAs_ExchangeKamaModifiedMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->_quantityFunc(input);
}

void ExchangeKamaModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeKamaModifiedMessage(tree);
}

void ExchangeKamaModifiedMessage::deserializeAsyncAs_ExchangeKamaModifiedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeKamaModifiedMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeKamaModifiedMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhLong();
  if(this->quantity < 0 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeKamaModifiedMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeKamaModifiedMessage.quantity.";
  }
}

ExchangeKamaModifiedMessage::ExchangeKamaModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE;
}

