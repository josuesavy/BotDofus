#include "StorageObjectsUpdateMessage.h"

void StorageObjectsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_StorageObjectsUpdateMessage(output);
}

void StorageObjectsUpdateMessage::serializeAs_StorageObjectsUpdateMessage(Writer *output)
{
  output->writeShort((short)this->objectList.size());
  for(uint _i1 = 0; _i1 < this->objectList.size(); _i1++)
  {
    qSharedPointerCast<ObjectItem>(this->objectList[_i1])->serializeAs_ObjectItem(output);
  }
}

void StorageObjectsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageObjectsUpdateMessage(input);
}

void StorageObjectsUpdateMessage::deserializeAs_StorageObjectsUpdateMessage(Reader *input)
{
  QSharedPointer<ObjectItem> _item1 ;
  uint _objectListLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectListLen; _i1++)
  {
    _item1 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item1->deserialize(input);
    this->objectList.append(_item1);
  }
}

void StorageObjectsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageObjectsUpdateMessage(tree);
}

void StorageObjectsUpdateMessage::deserializeAsyncAs_StorageObjectsUpdateMessage(FuncTree tree)
{
  this->_objectListtree = tree.addChild(std::bind(&StorageObjectsUpdateMessage::_objectListtreeFunc, this, std::placeholders::_1));
}

void StorageObjectsUpdateMessage::_objectListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectListtree.addChild(std::bind(&StorageObjectsUpdateMessage::_objectListFunc, this, std::placeholders::_1));
  }
}

void StorageObjectsUpdateMessage::_objectListFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->objectList.append(_item);
}

StorageObjectsUpdateMessage::StorageObjectsUpdateMessage()
{
  m_type = MessageEnum::STORAGEOBJECTSUPDATEMESSAGE;
}

