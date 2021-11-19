#include "ExchangeShopStockMultiMovementUpdatedMessage.h"

void ExchangeShopStockMultiMovementUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(output);
}

void ExchangeShopStockMultiMovementUpdatedMessage::serializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Writer *output)
{
  output->writeShort((short)this->objectInfoList.size());
  for(uint _i1 = 0; _i1 < this->objectInfoList.size(); _i1++)
  {
    qSharedPointerCast<ObjectItemToSell>(this->objectInfoList[_i1])->serializeAs_ObjectItemToSell(output);
  }
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(input);
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserializeAs_ExchangeShopStockMultiMovementUpdatedMessage(Reader *input)
{
  QSharedPointer<ObjectItemToSell> _item1 ;
  uint _objectInfoListLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectInfoListLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
    _item1->deserialize(input);
    this->objectInfoList.append(_item1);
  }
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeShopStockMultiMovementUpdatedMessage(tree);
}

void ExchangeShopStockMultiMovementUpdatedMessage::deserializeAsyncAs_ExchangeShopStockMultiMovementUpdatedMessage(FuncTree tree)
{
  this->_objectInfoListtree = tree.addChild(std::bind(&ExchangeShopStockMultiMovementUpdatedMessage::_objectInfoListtreeFunc, this, std::placeholders::_1));
}

void ExchangeShopStockMultiMovementUpdatedMessage::_objectInfoListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectInfoListtree.addChild(std::bind(&ExchangeShopStockMultiMovementUpdatedMessage::_objectInfoListFunc, this, std::placeholders::_1));
  }
}

void ExchangeShopStockMultiMovementUpdatedMessage::_objectInfoListFunc(Reader *input)
{
  QSharedPointer<ObjectItemToSell> _item = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
  _item->deserialize(input);
  this->objectInfoList.append(_item);
}

ExchangeShopStockMultiMovementUpdatedMessage::ExchangeShopStockMultiMovementUpdatedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE;
}

