#include "ExchangeObjectsModifiedMessage.h"

void ExchangeObjectsModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectsModifiedMessage(output);
}

void ExchangeObjectsModifiedMessage::serializeAs_ExchangeObjectsModifiedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  output->writeShort((short)this->object.size());
  for(uint _i1 = 0; _i1 < this->object.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->object[_i1])->serializeAs_ObjectItem(output);
  }
}

void ExchangeObjectsModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectsModifiedMessage(input);
}

void ExchangeObjectsModifiedMessage::deserializeAs_ExchangeObjectsModifiedMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  ExchangeObjectMessage::deserialize(input);
  uint _objectLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->object.append(_item1);
  }
}

void ExchangeObjectsModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectsModifiedMessage(tree);
}

void ExchangeObjectsModifiedMessage::deserializeAsyncAs_ExchangeObjectsModifiedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectsModifiedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectsModifiedMessage::_objecttreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objecttree.addChild(std::bind(&ExchangeObjectsModifiedMessage::_objectFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectsModifiedMessage::_objectFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->object.append(_item);
}

ExchangeObjectsModifiedMessage::ExchangeObjectsModifiedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE;
}

