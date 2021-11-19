#include "ExchangeOfflineSoldItemsMessage.h"

void ExchangeOfflineSoldItemsMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeOfflineSoldItemsMessage(output);
}

void ExchangeOfflineSoldItemsMessage::serializeAs_ExchangeOfflineSoldItemsMessage(Writer *output)
{
  output->writeShort((short)this->bidHouseItems.size());
  for(uint _i1 = 0; _i1 < this->bidHouseItems.size(); _i1++)
  {
    qSharedPointerCast<ObjectItemQuantityPriceDateEffects>(this->bidHouseItems[_i1])->serializeAs_ObjectItemQuantityPriceDateEffects(output);
  }
  output->writeShort((short)this->merchantItems.size());
  for(uint _i2 = 0; _i2 < this->merchantItems.size(); _i2++)
  {
    qSharedPointerCast<ObjectItemQuantityPriceDateEffects>(this->merchantItems[_i2])->serializeAs_ObjectItemQuantityPriceDateEffects(output);
  }
}

void ExchangeOfflineSoldItemsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeOfflineSoldItemsMessage(input);
}

void ExchangeOfflineSoldItemsMessage::deserializeAs_ExchangeOfflineSoldItemsMessage(Reader *input)
{
  QSharedPointer<ObjectItemQuantityPriceDateEffects> _item1 ;
  QSharedPointer<ObjectItemQuantityPriceDateEffects> _item2 ;
  uint _bidHouseItemsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _bidHouseItemsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItemQuantityPriceDateEffects>(new ObjectItemQuantityPriceDateEffects() );
    _item1->deserialize(input);
    this->bidHouseItems.append(_item1);
  }
  uint _merchantItemsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _merchantItemsLen; _i2++)
  {
    _item2 = QSharedPointer<ObjectItemQuantityPriceDateEffects>(new ObjectItemQuantityPriceDateEffects() );
    _item2->deserialize(input);
    this->merchantItems.append(_item2);
  }
}

void ExchangeOfflineSoldItemsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeOfflineSoldItemsMessage(tree);
}

void ExchangeOfflineSoldItemsMessage::deserializeAsyncAs_ExchangeOfflineSoldItemsMessage(FuncTree tree)
{
  this->_bidHouseItemstree = tree.addChild(std::bind(&ExchangeOfflineSoldItemsMessage::_bidHouseItemstreeFunc, this, std::placeholders::_1));
  this->_merchantItemstree = tree.addChild(std::bind(&ExchangeOfflineSoldItemsMessage::_merchantItemstreeFunc, this, std::placeholders::_1));
}

void ExchangeOfflineSoldItemsMessage::_bidHouseItemstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_bidHouseItemstree.addChild(std::bind(&ExchangeOfflineSoldItemsMessage::_bidHouseItemsFunc, this, std::placeholders::_1));
  }
}

void ExchangeOfflineSoldItemsMessage::_bidHouseItemsFunc(Reader *input)
{
  QSharedPointer<ObjectItemQuantityPriceDateEffects> _item = QSharedPointer<ObjectItemQuantityPriceDateEffects>(new ObjectItemQuantityPriceDateEffects() );
  _item->deserialize(input);
  this->bidHouseItems.append(_item);
}

void ExchangeOfflineSoldItemsMessage::_merchantItemstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_merchantItemstree.addChild(std::bind(&ExchangeOfflineSoldItemsMessage::_merchantItemsFunc, this, std::placeholders::_1));
  }
}

void ExchangeOfflineSoldItemsMessage::_merchantItemsFunc(Reader *input)
{
  QSharedPointer<ObjectItemQuantityPriceDateEffects> _item = QSharedPointer<ObjectItemQuantityPriceDateEffects>(new ObjectItemQuantityPriceDateEffects() );
  _item->deserialize(input);
  this->merchantItems.append(_item);
}

ExchangeOfflineSoldItemsMessage::ExchangeOfflineSoldItemsMessage()
{
  m_type = MessageEnum::EXCHANGEOFFLINESOLDITEMSMESSAGE;
}

