#include "StopListenTaxCollectorUpdatesMessage.h"

void StopListenTaxCollectorUpdatesMessage::serialize(Writer *output)
{
  this->serializeAs_StopListenTaxCollectorUpdatesMessage(output);
}

void StopListenTaxCollectorUpdatesMessage::serializeAs_StopListenTaxCollectorUpdatesMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - StopListenTaxCollectorUpdatesMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
}

void StopListenTaxCollectorUpdatesMessage::deserialize(Reader *input)
{
  this->deserializeAs_StopListenTaxCollectorUpdatesMessage(input);
}

void StopListenTaxCollectorUpdatesMessage::deserializeAs_StopListenTaxCollectorUpdatesMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
}

void StopListenTaxCollectorUpdatesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StopListenTaxCollectorUpdatesMessage(tree);
}

void StopListenTaxCollectorUpdatesMessage::deserializeAsyncAs_StopListenTaxCollectorUpdatesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StopListenTaxCollectorUpdatesMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
}

void StopListenTaxCollectorUpdatesMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - StopListenTaxCollectorUpdatesMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of StopListenTaxCollectorUpdatesMessage.taxCollectorId.";
  }
}

StopListenTaxCollectorUpdatesMessage::StopListenTaxCollectorUpdatesMessage()
{
  m_type = MessageEnum::STOPLISTENTAXCOLLECTORUPDATESMESSAGE;
}

