#include "ExchangeObjectRemovedMessage.h"

void ExchangeObjectRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectRemovedMessage(output);
}

void ExchangeObjectRemovedMessage::serializeAs_ExchangeObjectRemovedMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
}

void ExchangeObjectRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectRemovedMessage(input);
}

void ExchangeObjectRemovedMessage::deserializeAs_ExchangeObjectRemovedMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->_objectUIDFunc(input);
}

void ExchangeObjectRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectRemovedMessage(tree);
}

void ExchangeObjectRemovedMessage::deserializeAsyncAs_ExchangeObjectRemovedMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeObjectRemovedMessage::_objectUIDFunc, this, std::placeholders::_1));
}

void ExchangeObjectRemovedMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectRemovedMessage.objectUID.";
  }
}

ExchangeObjectRemovedMessage::ExchangeObjectRemovedMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE;
}

