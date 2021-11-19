#include "ObjectDeletedMessage.h"

void ObjectDeletedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectDeletedMessage(output);
}

void ObjectDeletedMessage::serializeAs_ObjectDeletedMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeletedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
}

void ObjectDeletedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectDeletedMessage(input);
}

void ObjectDeletedMessage::deserializeAs_ObjectDeletedMessage(Reader *input)
{
  this->_objectUIDFunc(input);
}

void ObjectDeletedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectDeletedMessage(tree);
}

void ObjectDeletedMessage::deserializeAsyncAs_ObjectDeletedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectDeletedMessage::_objectUIDFunc, this, std::placeholders::_1));
}

void ObjectDeletedMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeletedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDeletedMessage.objectUID.";
  }
}

ObjectDeletedMessage::ObjectDeletedMessage()
{
  m_type = MessageEnum::OBJECTDELETEDMESSAGE;
}

