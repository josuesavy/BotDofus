#include "ExchangeBidHouseUnsoldItemsMessage.h"

void ExchangeBidHouseUnsoldItemsMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeBidHouseUnsoldItemsMessage(output);
}

void ExchangeBidHouseUnsoldItemsMessage::serializeAs_ExchangeBidHouseUnsoldItemsMessage(Writer *output)
{
  output->writeShort((short)this->items.size());
  for(uint _i1 = 0; _i1 < this->items.size(); _i1++)
  {
    (this->items[_i1]).serializeAs_ObjectItemGenericQuantity(output);
  }
}

void ExchangeBidHouseUnsoldItemsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeBidHouseUnsoldItemsMessage(input);
}

void ExchangeBidHouseUnsoldItemsMessage::deserializeAs_ExchangeBidHouseUnsoldItemsMessage(Reader *input)
{
  ObjectItemGenericQuantity _item1 ;
  uint _itemsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _itemsLen; _i1++)
  {
    _item1 = ObjectItemGenericQuantity();
    _item1.deserialize(input);
    this->items.append(_item1);
  }
}

void ExchangeBidHouseUnsoldItemsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeBidHouseUnsoldItemsMessage(tree);
}

void ExchangeBidHouseUnsoldItemsMessage::deserializeAsyncAs_ExchangeBidHouseUnsoldItemsMessage(FuncTree tree)
{
  this->_itemstree = tree.addChild(std::bind(&ExchangeBidHouseUnsoldItemsMessage::_itemstreeFunc, this, std::placeholders::_1));
}

void ExchangeBidHouseUnsoldItemsMessage::_itemstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_itemstree.addChild(std::bind(&ExchangeBidHouseUnsoldItemsMessage::_itemsFunc, this, std::placeholders::_1));
  }
}

void ExchangeBidHouseUnsoldItemsMessage::_itemsFunc(Reader *input)
{
  ObjectItemGenericQuantity _item = ObjectItemGenericQuantity();
  _item.deserialize(input);
  this->items.append(_item);
}

ExchangeBidHouseUnsoldItemsMessage::ExchangeBidHouseUnsoldItemsMessage()
{
  m_type = MessageEnum::EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE;
}

