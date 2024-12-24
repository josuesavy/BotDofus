#include "ObjectDropMessage.h"

void ObjectDropMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectDropMessage(output);
}

void ObjectDropMessage::serializeAs_ObjectDropMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectDropMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectDropMessage(input);
}

void ObjectDropMessage::deserializeAs_ObjectDropMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ObjectDropMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectDropMessage(tree);
}

void ObjectDropMessage::deserializeAsyncAs_ObjectDropMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectDropMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectDropMessage::_quantityFunc, this, std::placeholders::_1));
}

void ObjectDropMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDropMessage.objectUID.";
  }
}

void ObjectDropMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectDropMessage.quantity.";
  }
}

ObjectDropMessage::ObjectDropMessage()
{
  m_type = MessageEnum::OBJECTDROPMESSAGE;
}

