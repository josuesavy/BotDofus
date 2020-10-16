#include "ObjectUseMessage.h"

void ObjectUseMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectUseMessage(output);
}

void ObjectUseMessage::serializeAs_ObjectUseMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
}

void ObjectUseMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectUseMessage(input);
}

void ObjectUseMessage::deserializeAs_ObjectUseMessage(Reader *input)
{
  this->_objectUIDFunc(input);
}

void ObjectUseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectUseMessage(tree);
}

void ObjectUseMessage::deserializeAsyncAs_ObjectUseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectUseMessage::_objectUIDFunc, this, std::placeholders::_1));
}

void ObjectUseMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectUseMessage.objectUID.";
  }
}

ObjectUseMessage::ObjectUseMessage()
{
  m_type = MessageEnum::OBJECTUSEMESSAGE;
}

