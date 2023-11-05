#include "StartExchangeTaxCollectorEquipmentMessage.h"

void StartExchangeTaxCollectorEquipmentMessage::serialize(Writer *output)
{
  this->serializeAs_StartExchangeTaxCollectorEquipmentMessage(output);
}

void StartExchangeTaxCollectorEquipmentMessage::serializeAs_StartExchangeTaxCollectorEquipmentMessage(Writer *output)
{
  if(this->uid < 0 || this->uid > 9007199254740992)
  {
    qDebug()<<"ERREUR - StartExchangeTaxCollectorEquipmentMessage -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeDouble(this->uid);
}

void StartExchangeTaxCollectorEquipmentMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartExchangeTaxCollectorEquipmentMessage(input);
}

void StartExchangeTaxCollectorEquipmentMessage::deserializeAs_StartExchangeTaxCollectorEquipmentMessage(Reader *input)
{
  this->_uidFunc(input);
}

void StartExchangeTaxCollectorEquipmentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartExchangeTaxCollectorEquipmentMessage(tree);
}

void StartExchangeTaxCollectorEquipmentMessage::deserializeAsyncAs_StartExchangeTaxCollectorEquipmentMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StartExchangeTaxCollectorEquipmentMessage::_uidFunc, this, std::placeholders::_1));
}

void StartExchangeTaxCollectorEquipmentMessage::_uidFunc(Reader *input)
{
  this->uid = input->readDouble();
  if(this->uid < 0 || this->uid > 9007199254740992)
  {
    qDebug()<<"ERREUR - StartExchangeTaxCollectorEquipmentMessage -"<<"Forbidden value (" << this->uid << ") on element of StartExchangeTaxCollectorEquipmentMessage.uid.";
  }
}

StartExchangeTaxCollectorEquipmentMessage::StartExchangeTaxCollectorEquipmentMessage()
{
  m_type = MessageEnum::STARTEXCHANGETAXCOLLECTOREQUIPMENTMESSAGE;
}

