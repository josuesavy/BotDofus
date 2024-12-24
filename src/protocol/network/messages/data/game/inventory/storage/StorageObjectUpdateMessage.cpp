#include "StorageObjectUpdateMessage.h"

void StorageObjectUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_StorageObjectUpdateMessage(output);
}

void StorageObjectUpdateMessage::serializeAs_StorageObjectUpdateMessage(Writer *output)
{
  this->object->serializeAs_ObjectItem(output);
}

void StorageObjectUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageObjectUpdateMessage(input);
}

void StorageObjectUpdateMessage::deserializeAs_StorageObjectUpdateMessage(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(input);
}

void StorageObjectUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageObjectUpdateMessage(tree);
}

void StorageObjectUpdateMessage::deserializeAsyncAs_StorageObjectUpdateMessage(FuncTree tree)
{
  this->_objecttree = tree.addChild(std::bind(&StorageObjectUpdateMessage::_objecttreeFunc, this, std::placeholders::_1));
}

void StorageObjectUpdateMessage::_objecttreeFunc(Reader *input)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserializeAsync(this->_objecttree);
}

StorageObjectUpdateMessage::StorageObjectUpdateMessage()
{
  m_type = MessageEnum::STORAGEOBJECTUPDATEMESSAGE;
}

