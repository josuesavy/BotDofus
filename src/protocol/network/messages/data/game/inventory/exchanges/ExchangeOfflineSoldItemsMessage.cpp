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
}

void ExchangeOfflineSoldItemsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeOfflineSoldItemsMessage(input);
}

void ExchangeOfflineSoldItemsMessage::deserializeAs_ExchangeOfflineSoldItemsMessage(Reader *input)
{
  QSharedPointer<ObjectItemQuantityPriceDateEffects> _item1 ;
  uint _bidHouseItemsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _bidHouseItemsLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItemQuantityPriceDateEffects>(new ObjectItemQuantityPriceDateEffects() );
    _item1->deserialize(input);
    this->bidHouseItems.append(_item1);
  }
}

void ExchangeOfflineSoldItemsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeOfflineSoldItemsMessage(tree);
}

void ExchangeOfflineSoldItemsMessage::deserializeAsyncAs_ExchangeOfflineSoldItemsMessage(FuncTree tree)
{
  this->_bidHouseItemstree = tree.addChild(std::bind(&ExchangeOfflineSoldItemsMessage::_bidHouseItemstreeFunc, this, std::placeholders::_1));
}

void ExchangeOfflineSoldItemsMessage::_bidHouseItemstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
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

ExchangeOfflineSoldItemsMessage::ExchangeOfflineSoldItemsMessage()
{
  m_type = MessageEnum::EXCHANGEOFFLINESOLDITEMSMESSAGE;
}

