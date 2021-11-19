#include "ExchangeObjectRemovedFromBagMessage.h"

void ExchangeObjectRemovedFromBagMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectRemovedFromBagMessage(output);
}

void ExchangeObjectRemovedFromBagMessage::serializeAs_ExchangeObjectRemovedFromBagMessage(Writer *output)
{
  ExchangeObjectMessage::serializeAs_ExchangeObjectMessage(output);
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedFromBagMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
}

void ExchangeObjectRemovedFromBagMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectRemovedFromBagMessage(input);
}

void ExchangeObjectRemovedFromBagMessage::deserializeAs_ExchangeObjectRemovedFromBagMessage(Reader *input)
{
  ExchangeObjectMessage::deserialize(input);
  this->_objectUIDFunc(input);
}

void ExchangeObjectRemovedFromBagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectRemovedFromBagMessage(tree);
}

void ExchangeObjectRemovedFromBagMessage::deserializeAsyncAs_ExchangeObjectRemovedFromBagMessage(FuncTree tree)
{
  ExchangeObjectMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeObjectRemovedFromBagMessage::_objectUIDFunc, this, std::placeholders::_1));
}

void ExchangeObjectRemovedFromBagMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectRemovedFromBagMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectRemovedFromBagMessage.objectUID.";
  }
}

ExchangeObjectRemovedFromBagMessage::ExchangeObjectRemovedFromBagMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE;
}

