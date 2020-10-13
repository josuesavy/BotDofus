#include "ExchangeBuyMessage.h"

void ExchangeBuyMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBuyMessage(output);
}

void ExchangeBuyMessage::serializeAs_ExchangeBuyMessage(Writer *output)
{
  if(this->objectToBuyId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->objectToBuyId << ") on element objectToBuyId.";
  }
  output->writeVarInt((int)this->objectToBuyId);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ExchangeBuyMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBuyMessage(input);
}

void ExchangeBuyMessage::deserializeAs_ExchangeBuyMessage(Reader *input)
{
  this->_objectToBuyIdFunc(input);
  this->_quantityFunc(input);
}

void ExchangeBuyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBuyMessage(tree);
}

void ExchangeBuyMessage::deserializeAsyncAs_ExchangeBuyMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeBuyMessage::_objectToBuyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeBuyMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeBuyMessage::_objectToBuyIdFunc(Reader *input)
{
  this->objectToBuyId = input->readVarUhInt();
  if(this->objectToBuyId < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->objectToBuyId << ") on element of ExchangeBuyMessage.objectToBuyId.";
  }
}

void ExchangeBuyMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ExchangeBuyMessage -"<<"Forbidden value (" << this->quantity << ") on element of ExchangeBuyMessage.quantity.";
  }
}

ExchangeBuyMessage::ExchangeBuyMessage()
{
  m_type = MessageEnum::EXCHANGEBUYMESSAGE;
}

