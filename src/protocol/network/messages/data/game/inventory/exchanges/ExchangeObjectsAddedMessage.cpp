#include "ExchangeObjectsAddedMessage.h"

void ExchangeObjectsAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectsAddedMessage(output);
}

void ExchangeObjectsAddedMessage::serializeAs_ExchangeObjectsAddedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  output->writeShort((short)this->object.size());
  for(uint _i1 = 0; _i1 < this->object.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->object[_i1])->serializeAs_ObjectItem(output);
  }
}

void ExchangeObjectsAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectsAddedMessage(input);
}

void ExchangeObjectsAddedMessage::deserializeAs_ExchangeObjectsAddedMessage(Reader *input)
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

void ExchangeObjectsAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectsAddedMessage(tree);
}

void ExchangeObjectsAddedMessage::deserializeAsyncAs_ExchangeObjectsAddedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  this->_objecttree = tree.addChild(std::bind(&ExchangeObjectsAddedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ExchangeObjectsAddedMessage::_objecttreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objecttree.addChild(std::bind(&ExchangeObjectsAddedMessage::_objectFunc, this, std::placeholders::_1));
  }
}

void ExchangeObjectsAddedMessage::_objectFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->object.append(_item);
}

ExchangeObjectsAddedMessage::ExchangeObjectsAddedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTSADDEDMESSAGE;
}

