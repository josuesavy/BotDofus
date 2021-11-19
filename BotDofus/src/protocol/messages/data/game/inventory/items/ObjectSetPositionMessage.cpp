#include "ObjectSetPositionMessage.h"

void ObjectSetPositionMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectSetPositionMessage(output);
}

void ObjectSetPositionMessage::serializeAs_ObjectSetPositionMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeShort((short)this->position);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectSetPositionMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectSetPositionMessage(input);
}

void ObjectSetPositionMessage::deserializeAs_ObjectSetPositionMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_positionFunc(input);
  this->_quantityFunc(input);
}

void ObjectSetPositionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectSetPositionMessage(tree);
}

void ObjectSetPositionMessage::deserializeAsyncAs_ObjectSetPositionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectSetPositionMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectSetPositionMessage::_positionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectSetPositionMessage::_quantityFunc, this, std::placeholders::_1));
}

void ObjectSetPositionMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectSetPositionMessage.objectUID.";
  }
}

void ObjectSetPositionMessage::_positionFunc(Reader *input)
{
  this->position = input->readShort();
  if(this->position < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->position << ") on element of ObjectSetPositionMessage.position.";
  }
}

void ObjectSetPositionMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectSetPositionMessage.quantity.";
  }
}

ObjectSetPositionMessage::ObjectSetPositionMessage()
{
  m_type = MessageEnum::OBJECTSETPOSITIONMESSAGE;
}

