#include "ObjectsAddedMessage.h"

void ObjectsAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectsAddedMessage(output);
}

void ObjectsAddedMessage::serializeAs_ObjectsAddedMessage(Writer *output)
{
  output->writeShort((short)this->object.size());
  for(uint _i1 = 0; _i1 < this->object.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->object[_i1])->serializeAs_ObjectItem(output);
  }
}

void ObjectsAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectsAddedMessage(input);
}

void ObjectsAddedMessage::deserializeAs_ObjectsAddedMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  uint _objectLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->object.append(_item1);
  }
}

void ObjectsAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectsAddedMessage(tree);
}

void ObjectsAddedMessage::deserializeAsyncAs_ObjectsAddedMessage(FuncTree tree)
{
  this->_objecttree = tree.addChild(std::bind(&ObjectsAddedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ObjectsAddedMessage::_objecttreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objecttree.addChild(std::bind(&ObjectsAddedMessage::_objectFunc, this, std::placeholders::_1));
  }
}

void ObjectsAddedMessage::_objectFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->object.append(_item);
}

ObjectsAddedMessage::ObjectsAddedMessage()
{
  m_type = MessageEnum::OBJECTSADDEDMESSAGE;
}

