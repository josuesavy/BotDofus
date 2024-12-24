#include "ConfirmationOfListeningTaxCollectorUpdatesMessage.h"

void ConfirmationOfListeningTaxCollectorUpdatesMessage::serialize(Writer *output)
{
  this->serializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(output);
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::serializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(Writer *output)
{
  this->information->serializeAs_TaxCollectorInformations(output);
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(input);
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::deserializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(Reader *input)
{
  this->information = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
  this->information->deserialize(input);
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(tree);
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::deserializeAsyncAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(FuncTree tree)
{
  this->_informationtree = tree.addChild(std::bind(&ConfirmationOfListeningTaxCollectorUpdatesMessage::_informationtreeFunc, this, std::placeholders::_1));
}

void ConfirmationOfListeningTaxCollectorUpdatesMessage::_informationtreeFunc(Reader *input)
{
  this->information = QSharedPointer<TaxCollectorInformations>(new TaxCollectorInformations() );
  this->information->deserializeAsync(this->_informationtree);
}

ConfirmationOfListeningTaxCollectorUpdatesMessage::ConfirmationOfListeningTaxCollectorUpdatesMessage()
{
  m_type = MessageEnum::CONFIRMATIONOFLISTENINGTAXCOLLECTORUPDATESMESSAGE;
}

