#include "ExchangeShopStockMovementRemovedMessage.h"

void ExchangeShopStockMovementRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeShopStockMovementRemovedMessage(output);
}

void ExchangeShopStockMovementRemovedMessage::serializeAs_ExchangeShopStockMovementRemovedMessage(Writer *output)
{
  if(this->objectId < 0)
  {
    qDebug()<<"ERREUR - ExchangeShopStockMovementRemovedMessage -"<<"Forbidden value (" << this->objectId << ") on element objectId.";
  }
  output->writeVarInt((int)this->objectId);
}

void ExchangeShopStockMovementRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeShopStockMovementRemovedMessage(input);
}

void ExchangeShopStockMovementRemovedMessage::deserializeAs_ExchangeShopStockMovementRemovedMessage(Reader *input)
{
  this->_objectIdFunc(input);
}

void ExchangeShopStockMovementRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeShopStockMovementRemovedMessage(tree);
}

void ExchangeShopStockMovementRemovedMessage::deserializeAsyncAs_ExchangeShopStockMovementRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeShopStockMovementRemovedMessage::_objectIdFunc, this, std::placeholders::_1));
}

void ExchangeShopStockMovementRemovedMessage::_objectIdFunc(Reader *input)
{
  this->objectId = input->readVarUhInt();
  if(this->objectId < 0)
  {
    qDebug()<<"ERREUR - ExchangeShopStockMovementRemovedMessage -"<<"Forbidden value (" << this->objectId << ") on element of ExchangeShopStockMovementRemovedMessage.objectId.";
  }
}

ExchangeShopStockMovementRemovedMessage::ExchangeShopStockMovementRemovedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE;
}

