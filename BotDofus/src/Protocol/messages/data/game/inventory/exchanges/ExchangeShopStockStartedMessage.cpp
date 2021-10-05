#include "ExchangeShopStockStartedMessage.h"

void ExchangeShopStockStartedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeShopStockStartedMessage(output);
}

void ExchangeShopStockStartedMessage::serializeAs_ExchangeShopStockStartedMessage(Writer *output)
{
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i1 = 0; _i1 < this->objectsInfos.size(); _i1++)
  {
    qSharedPointerCast<ObjectItemToSell>(this->objectsInfos[_i1])->serializeAs_ObjectItemToSell(output);
  }
}

void ExchangeShopStockStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeShopStockStartedMessage(input);
}

void ExchangeShopStockStartedMessage::deserializeAs_ExchangeShopStockStartedMessage(Reader *input)
{
  QSharedPointer<ObjectItemToSell> _item1 ;
  uint _objectsInfosLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsInfosLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
    _item1->deserialize(input);
    this->objectsInfos.append(_item1);
  }
}

void ExchangeShopStockStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeShopStockStartedMessage(tree);
}

void ExchangeShopStockStartedMessage::deserializeAsyncAs_ExchangeShopStockStartedMessage(FuncTree tree)
{
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeShopStockStartedMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeShopStockStartedMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeShopStockStartedMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeShopStockStartedMessage::_objectsInfosFunc(Reader *input)
{
  QSharedPointer<ObjectItemToSell> _item = QSharedPointer<ObjectItemToSell>(new ObjectItemToSell() );
  _item->deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeShopStockStartedMessage::ExchangeShopStockStartedMessage()
{
  m_type = MessageEnum::EXCHANGESHOPSTOCKSTARTEDMESSAGE;
}

