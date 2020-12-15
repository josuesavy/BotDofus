#include "ExchangeStartedMountStockMessage.h"

void ExchangeStartedMountStockMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedMountStockMessage(output);
}

void ExchangeStartedMountStockMessage::serializeAs_ExchangeStartedMountStockMessage(Writer *output)
{
  output->writeShort((short)this->objectsInfos.size());
  for(uint _i1 = 0; _i1 < this->objectsInfos.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objectsInfos[_i1])->serializeAs_ObjectItem(output);
  }
}

void ExchangeStartedMountStockMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedMountStockMessage(input);
}

void ExchangeStartedMountStockMessage::deserializeAs_ExchangeStartedMountStockMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  uint _objectsInfosLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectsInfosLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objectsInfos.append(_item1);
  }
}

void ExchangeStartedMountStockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedMountStockMessage(tree);
}

void ExchangeStartedMountStockMessage::deserializeAsyncAs_ExchangeStartedMountStockMessage(FuncTree tree)
{
  this->_objectsInfostree = tree.addChild(std::bind(&ExchangeStartedMountStockMessage::_objectsInfostreeFunc, this, std::placeholders::_1));
}

void ExchangeStartedMountStockMessage::_objectsInfostreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectsInfostree.addChild(std::bind(&ExchangeStartedMountStockMessage::_objectsInfosFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartedMountStockMessage::_objectsInfosFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objectsInfos.append(_item);
}

ExchangeStartedMountStockMessage::ExchangeStartedMountStockMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDMOUNTSTOCKMESSAGE;
}

