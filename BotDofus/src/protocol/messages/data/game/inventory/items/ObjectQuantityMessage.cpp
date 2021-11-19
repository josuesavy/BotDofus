#include "ObjectQuantityMessage.h"

void ObjectQuantityMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectQuantityMessage(output);
}

void ObjectQuantityMessage::serializeAs_ObjectQuantityMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
  output->writeByte(this->origin);
}

void ObjectQuantityMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectQuantityMessage(input);
}

void ObjectQuantityMessage::deserializeAs_ObjectQuantityMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
  this->_originFunc(input);
}

void ObjectQuantityMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectQuantityMessage(tree);
}

void ObjectQuantityMessage::deserializeAsyncAs_ObjectQuantityMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectQuantityMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectQuantityMessage::_quantityFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectQuantityMessage::_originFunc, this, std::placeholders::_1));
}

void ObjectQuantityMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectQuantityMessage.objectUID.";
  }
}

void ObjectQuantityMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectQuantityMessage.quantity.";
  }
}

void ObjectQuantityMessage::_originFunc(Reader *input)
{
  this->origin = input->readByte();
  if(this->origin < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->origin << ") on element of ObjectQuantityMessage.origin.";
  }
}

ObjectQuantityMessage::ObjectQuantityMessage()
{
  m_type = MessageEnum::OBJECTQUANTITYMESSAGE;
}

