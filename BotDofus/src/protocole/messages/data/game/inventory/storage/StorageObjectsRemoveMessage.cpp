#include "StorageObjectsRemoveMessage.h"

void StorageObjectsRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_StorageObjectsRemoveMessage(output);
}

void StorageObjectsRemoveMessage::serializeAs_StorageObjectsRemoveMessage(Writer *output)
{
  output->writeShort((short)this->objectUIDList.size());
  for(uint _i1 = 0; _i1 < this->objectUIDList.size(); _i1++)
  {
    if(this->objectUIDList[_i1] < 0)
    {
      qDebug()<<"ERREUR - StorageObjectsRemoveMessage -"<<"Forbidden value (" << this->objectUIDList[_i1] << ") on element 1 (starting at 1) of objectUIDList.";
    }
    output->writeVarInt((int)this->objectUIDList[_i1]);
  }
}

void StorageObjectsRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageObjectsRemoveMessage(input);
}

void StorageObjectsRemoveMessage::deserializeAs_StorageObjectsRemoveMessage(Reader *input)
{
  uint _val1 = 0;
  uint _objectUIDListLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _objectUIDListLen; _i1++)
  {
    _val1 = input->readVarUhInt();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - StorageObjectsRemoveMessage -"<<"Forbidden value (" << _val1 << ") on elements of objectUIDList.";
    }
    this->objectUIDList.append(_val1);
  }
}

void StorageObjectsRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageObjectsRemoveMessage(tree);
}

void StorageObjectsRemoveMessage::deserializeAsyncAs_StorageObjectsRemoveMessage(FuncTree tree)
{
  this->_objectUIDListtree = tree.addChild(std::bind(&StorageObjectsRemoveMessage::_objectUIDListtreeFunc, this, std::placeholders::_1));
}

void StorageObjectsRemoveMessage::_objectUIDListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_objectUIDListtree.addChild(std::bind(&StorageObjectsRemoveMessage::_objectUIDListFunc, this, std::placeholders::_1));
  }
}

void StorageObjectsRemoveMessage::_objectUIDListFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - StorageObjectsRemoveMessage -"<<"Forbidden value (" << _val << ") on elements of objectUIDList.";
  }
  this->objectUIDList.append(_val);
}

StorageObjectsRemoveMessage::StorageObjectsRemoveMessage()
{
  m_type = MessageEnum::STORAGEOBJECTSREMOVEMESSAGE;
}

