#include "ExchangeShopStockMovementUpdatedMessage.h"

void ExchangeShopStockMovementUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeShopStockMovementUpdatedMessage(output);
}

void ExchangeShopStockMovementUpdatedMessage::serializeAs_ExchangeShopStockMovementUpdatedMessage(Writer *output)
{
  this->objectInfo->serializeAs_ObjectItemToSell(output);
}

void ExchangeShopStockMovementUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeShopStockMovementUpdatedMessage(input);
}

void ExchangeShopStockMovementUpdatedMessage::deserializeAs_ExchangeShopStockMovementUpdatedMessage(Reader *input)
{
  this->objectInfo = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
  this->objectInfo->deserialize(input);
}

void ExchangeShopStockMovementUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeShopStockMovementUpdatedMessage(tree);
}

void ExchangeShopStockMovementUpdatedMessage::deserializeAsyncAs_ExchangeShopStockMovementUpdatedMessage(FuncTree tree)
{
  this->_objectInfotree = tree.addChild(std::bind(&ExchangeShopStockMovementUpdatedMessage::_objectInfotreeFunc, this, std::placeholders::_1));
}

void ExchangeShopStockMovementUpdatedMessage::_objectInfotreeFunc(Reader *input)
{
  this->objectInfo = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
  this->objectInfo->deserializeAsync(this->_objectInfotree);
}

ExchangeShopStockMovementUpdatedMessage::ExchangeShopStockMovementUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE;
}

