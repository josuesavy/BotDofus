#include "ExchangeObjectMoveMessage.h"

void ExchangeObjectMoveMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectMoveMessage(output);
}

void ExchangeObjectMoveMessage::serializeAs_ExchangeObjectMoveMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeVarInt((int)this->quantity);
}

void ExchangeObjectMoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectMoveMessage(input);
}

void ExchangeObjectMoveMessage::deserializeAs_ExchangeObjectMoveMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ExchangeObjectMoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectMoveMessage(tree);
}

void ExchangeObjectMoveMessage::deserializeAsyncAs_ExchangeObjectMoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeObjectMoveMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeObjectMoveMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeObjectMoveMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectMoveMessage.objectUID.";
  }
}

void ExchangeObjectMoveMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarInt();
}

ExchangeObjectMoveMessage::ExchangeObjectMoveMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVEMESSAGE;
  m_needsHash = true;
}

