#include "ExchangeObjectMoveToTabMessage.h"

void ExchangeObjectMoveToTabMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectMoveToTabMessage(output);
}

void ExchangeObjectMoveToTabMessage::serializeAs_ExchangeObjectMoveToTabMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveToTabMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeVarInt((int)this->quantity);
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveToTabMessage -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
}

void ExchangeObjectMoveToTabMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectMoveToTabMessage(input);
}

void ExchangeObjectMoveToTabMessage::deserializeAs_ExchangeObjectMoveToTabMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
  this->_tabNumberFunc(input);
}

void ExchangeObjectMoveToTabMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectMoveToTabMessage(tree);
}

void ExchangeObjectMoveToTabMessage::deserializeAsyncAs_ExchangeObjectMoveToTabMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeObjectMoveToTabMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeObjectMoveToTabMessage::_quantityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeObjectMoveToTabMessage::_tabNumberFunc, this, std::placeholders::_1));
}

void ExchangeObjectMoveToTabMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveToTabMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectMoveToTabMessage.objectUID.";
  }
}

void ExchangeObjectMoveToTabMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarInt();
}

void ExchangeObjectMoveToTabMessage::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectMoveToTabMessage -"<<"Forbidden value (" << this->tabNumber << ") on element of ExchangeObjectMoveToTabMessage.tabNumber.";
  }
}

ExchangeObjectMoveToTabMessage::ExchangeObjectMoveToTabMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTMOVETOTABMESSAGE;
}

