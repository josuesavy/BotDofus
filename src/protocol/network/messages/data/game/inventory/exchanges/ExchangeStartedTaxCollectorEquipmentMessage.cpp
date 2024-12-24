#include "ExchangeStartedTaxCollectorEquipmentMessage.h"

void ExchangeStartedTaxCollectorEquipmentMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartedTaxCollectorEquipmentMessage(output);
}

void ExchangeStartedTaxCollectorEquipmentMessage::serializeAs_ExchangeStartedTaxCollectorEquipmentMessage(Writer *output)
{
  this->information->serializeAs_TaxCollectorInformations(output);
}

void ExchangeStartedTaxCollectorEquipmentMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartedTaxCollectorEquipmentMessage(input);
}

void ExchangeStartedTaxCollectorEquipmentMessage::deserializeAs_ExchangeStartedTaxCollectorEquipmentMessage(Reader *input)
{
  this->information = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
  this->information->deserialize(input);
}

void ExchangeStartedTaxCollectorEquipmentMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartedTaxCollectorEquipmentMessage(tree);
}

void ExchangeStartedTaxCollectorEquipmentMessage::deserializeAsyncAs_ExchangeStartedTaxCollectorEquipmentMessage(FuncTree tree)
{
  this->_informationtree = tree.addChild(std::bind(&ExchangeStartedTaxCollectorEquipmentMessage::_informationtreeFunc, this, std::placeholders::_1));
}

void ExchangeStartedTaxCollectorEquipmentMessage::_informationtreeFunc(Reader *input)
{
  this->information = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
  this->information->deserializeAsync(this->_informationtree);
}

ExchangeStartedTaxCollectorEquipmentMessage::ExchangeStartedTaxCollectorEquipmentMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDTAXCOLLECTOREQUIPMENTMESSAGE;
}

