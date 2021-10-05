#include "ObjectMovementMessage.h"

void ObjectMovementMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectMovementMessage(output);
}

void ObjectMovementMessage::serializeAs_ObjectMovementMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeShort((short)this->position);
}

void ObjectMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectMovementMessage(input);
}

void ObjectMovementMessage::deserializeAs_ObjectMovementMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_positionFunc(input);
}

void ObjectMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectMovementMessage(tree);
}

void ObjectMovementMessage::deserializeAsyncAs_ObjectMovementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectMovementMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ObjectMovementMessage::_positionFunc, this, std::placeholders::_1));
}

void ObjectMovementMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectMovementMessage.objectUID.";
  }
}

void ObjectMovementMessage::_positionFunc(Reader *input)
{
  this->position = input->readShort();
  if(this->position < 0)
  {
    qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->position << ") on element of ObjectMovementMessage.position.";
  }
}

ObjectMovementMessage::ObjectMovementMessage()
{
  m_type = MessageEnum::OBJECTMOVEMENTMESSAGE;
}

