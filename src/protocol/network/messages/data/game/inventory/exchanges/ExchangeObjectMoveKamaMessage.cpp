#include "ExchangeObjectMoveKamaMessage.h"

void ExchangeObjectMoveKamaMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectMoveKamaMessage(output);
}

void ExchangeObjectMoveKamaMessage::serializeAs_ExchangeObjectMoveKamaMessage(Writer *output)
{
  if(this->quantity < -9007199254740992 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveKamaMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarLong((double)this->quantity);
}

void ExchangeObjectMoveKamaMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectMoveKamaMessage(input);
}

void ExchangeObjectMoveKamaMessage::deserializeAs_ExchangeObjectMoveKamaMessage(Reader *input)
{
  this->_quantityFunc(input);
}

void ExchangeObjectMoveKamaMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectMoveKamaMessage(tree);
}

void ExchangeObjectMoveKamaMessage::deserializeAsyncAs_ExchangeObjectMoveKamaMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeObjectMoveKamaMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeObjectMoveKamaMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarLong();
  if(this->quantity < -9007199254740992 || this->quantity > 9007199254740992)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveKamaMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeObjectMoveKamaMessage.quantity.";
  }
}

ExchangeObjectMoveKamaMessage::ExchangeObjectMoveKamaMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEKAMAMESSAGE;
}

