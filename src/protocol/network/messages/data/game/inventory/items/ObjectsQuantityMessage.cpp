#include "ObjectsQuantityMessage.h"

void ObjectsQuantityMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectsQuantityMessage(output);
}

void ObjectsQuantityMessage::serializeAs_ObjectsQuantityMessage(Writer *output)
{
  output->writeShort((short)this->objectsUIDAndQty.size());
  for(uint _i1 = 0; _i1 < this->objectsUIDAndQty.size(); _i1++)
  {
    (this->objectsUIDAndQty[_i1]).serializeAs_ObjectItemQuantity(output);
  }
}

void ObjectsQuantityMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectsQuantityMessage(input);
}

void ObjectsQuantityMessage::deserializeAs_ObjectsQuantityMessage(Reader *input)
{
  ObjectItemQuantity _item1 ;
  uint _objectsUIDAndQtyLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _objectsUIDAndQtyLen; _i1++)
  {
    _item1 = ObjectItemQuantity();
    _item1.deserialize(input);
    this->objectsUIDAndQty.append(_item1);
  }
}

void ObjectsQuantityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectsQuantityMessage(tree);
}

void ObjectsQuantityMessage::deserializeAsyncAs_ObjectsQuantityMessage(FuncTree tree)
{
  this->_objectsUIDAndQtytree = tree.addChild(std::bind(&ObjectsQuantityMessage::_objectsUIDAndQtytreeFunc, this, std::placeholders::_1));
}

void ObjectsQuantityMessage::_objectsUIDAndQtytreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_objectsUIDAndQtytree.addChild(std::bind(&ObjectsQuantityMessage::_objectsUIDAndQtyFunc, this, std::placeholders::_1));
  }
}

void ObjectsQuantityMessage::_objectsUIDAndQtyFunc(Reader *input)
{
  ObjectItemQuantity _item = ObjectItemQuantity();
  _item.deserialize(input);
  this->objectsUIDAndQty.append(_item);
}

ObjectsQuantityMessage::ObjectsQuantityMessage()
{
  m_type = MessageEnum::OBJECTSQUANTITYMESSAGE;
}

