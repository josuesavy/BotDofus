#include "ObjectDeleteMessage.h"

void ObjectDeleteMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectDeleteMessage(output);
}

void ObjectDeleteMessage::serializeAs_ObjectDeleteMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectDeleteMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectDeleteMessage(input);
}

void ObjectDeleteMessage::deserializeAs_ObjectDeleteMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectDeleteMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectDeleteMessage(tree);
}

void ObjectDeleteMessage::deserializeAsyncAs_ObjectDeleteMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectDeleteMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectDeleteMessage::_quantityFunc, this, std::placeholders::_1));
}

void ObjectDeleteMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDeleteMessage.objectUID.";
  }
}

void ObjectDeleteMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectDeleteMessage.quantity.";
  }
}

ObjectDeleteMessage::ObjectDeleteMessage()
{
  m_type = MessageEnum::OBJECTDELETEMESSAGE;
}

