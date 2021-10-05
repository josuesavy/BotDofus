#include "ExchangeObjectUseInWorkshopMessage.h"

void ExchangeObjectUseInWorkshopMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeObjectUseInWorkshopMessage(output);
}

void ExchangeObjectUseInWorkshopMessage::serializeAs_ExchangeObjectUseInWorkshopMessage(Writer *output)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectUseInWorkshopMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  output->writeVarInt((int)this->objectUID);
  output->writeVarInt((int)this->quantity);
}

void ExchangeObjectUseInWorkshopMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeObjectUseInWorkshopMessage(input);
}

void ExchangeObjectUseInWorkshopMessage::deserializeAs_ExchangeObjectUseInWorkshopMessage(Reader *input)
{
  this->_objectUIDFunc(input);
  this->_quantityFunc(input);
}

void ExchangeObjectUseInWorkshopMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeObjectUseInWorkshopMessage(tree);
}

void ExchangeObjectUseInWorkshopMessage::deserializeAsyncAs_ExchangeObjectUseInWorkshopMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeObjectUseInWorkshopMessage::_objectUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ExchangeObjectUseInWorkshopMessage::_quantityFunc, this, std::placeholders::_1));
}

void ExchangeObjectUseInWorkshopMessage::_objectUIDFunc(Reader *input)
{
  this->objectUID = input->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ExchangeObjectUseInWorkshopMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ExchangeObjectUseInWorkshopMessage.objectUID.";
  }
}

void ExchangeObjectUseInWorkshopMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarInt();
}

ExchangeObjectUseInWorkshopMessage::ExchangeObjectUseInWorkshopMessage()
{
  m_type = MessageEnum::EXCHANGEOBJECTUSEINWORKSHOPMESSAGE;
}

