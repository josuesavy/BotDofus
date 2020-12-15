#include "ObjectModifiedMessage.h"

void ObjectModifiedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectModifiedMessage(output);
}

void ObjectModifiedMessage::serializeAs_ObjectModifiedMessage(Writer *output)
{
  this->object->serializeAs_ObjectItem(output);
}

void ObjectModifiedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectModifiedMessage(input);
}

void ObjectModifiedMessage::deserializeAs_ObjectModifiedMessage(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void ObjectModifiedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectModifiedMessage(tree);
}

void ObjectModifiedMessage::deserializeAsyncAs_ObjectModifiedMessage(FuncTree tree)
{
  this->_objecttree = tree.addChild(std::bind(&ObjectModifiedMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void ObjectModifiedMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

ObjectModifiedMessage::ObjectModifiedMessage()
{
  m_type = MessageEnum::OBJECTMODIFIEDMESSAGE;
}

