#include "StorageObjectRemoveMessage.h"

void StorageObjectRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_StorageObjectRemoveMessage(output);
}

void StorageObjectRemoveMessage::serializeAs_StorageObjectRemoveMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - StorageObjectRemoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
}

void StorageObjectRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_StorageObjectRemoveMessage(input);
}

void StorageObjectRemoveMessage::deserializeAs_StorageObjectRemoveMessage(Reader *input)
{
  this->_objectUIDFunc(input);
}

void StorageObjectRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageObjectRemoveMessage(tree);
}

void StorageObjectRemoveMessage::deserializeAsyncAs_StorageObjectRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StorageObjectRemoveMessage::_objectUIDFunc, this, std::placeholders::_1));
}

void StorageObjectRemoveMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - StorageObjectRemoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element of StorageObjectRemoveMessage.objectUID.";
  }
}

StorageObjectRemoveMessage::StorageObjectRemoveMessage()
{
  m_type = MessageEnum::STORAGEOBJECTREMOVEMESSAGE;
}

