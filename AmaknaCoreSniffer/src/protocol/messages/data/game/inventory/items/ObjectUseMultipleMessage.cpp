#include "ObjectUseMultipleMessage.h"

void ObjectUseMultipleMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectUseMultipleMessage(output);
}

void ObjectUseMultipleMessage::serializeAs_ObjectUseMultipleMessage(Writer *output)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(output);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMultipleMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  output->writeVarInt((int)this->quantity);
}

void ObjectUseMultipleMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectUseMultipleMessage(input);
}

void ObjectUseMultipleMessage::deserializeAs_ObjectUseMultipleMessage(Reader *input)
{
  ObjectUseMessage::deserialize(input);
  this->_quantityFunc(input);
}

void ObjectUseMultipleMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectUseMultipleMessage(tree);
}

void ObjectUseMultipleMessage::deserializeAsyncAs_ObjectUseMultipleMessage(FuncTree tree)
{
  ObjectUseMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ObjectUseMultipleMessage::_quantityFunc, this, std::placeholders::_1));
}

void ObjectUseMultipleMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMultipleMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectUseMultipleMessage.quantity.";
  }
}

ObjectUseMultipleMessage::ObjectUseMultipleMessage()
{
  m_type = MessageEnum::OBJECTUSEMULTIPLEMESSAGE;
}

