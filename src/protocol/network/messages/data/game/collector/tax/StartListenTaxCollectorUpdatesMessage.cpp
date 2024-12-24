#include "StartListenTaxCollectorUpdatesMessage.h"

void StartListenTaxCollectorUpdatesMessage::serialize(Writer *output)
{
  this->serializeAs_StartListenTaxCollectorUpdatesMessage(output);
}

void StartListenTaxCollectorUpdatesMessage::serializeAs_StartListenTaxCollectorUpdatesMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - StartListenTaxCollectorUpdatesMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
}

void StartListenTaxCollectorUpdatesMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartListenTaxCollectorUpdatesMessage(input);
}

void StartListenTaxCollectorUpdatesMessage::deserializeAs_StartListenTaxCollectorUpdatesMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
}

void StartListenTaxCollectorUpdatesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartListenTaxCollectorUpdatesMessage(tree);
}

void StartListenTaxCollectorUpdatesMessage::deserializeAsyncAs_StartListenTaxCollectorUpdatesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StartListenTaxCollectorUpdatesMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
}

void StartListenTaxCollectorUpdatesMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - StartListenTaxCollectorUpdatesMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of StartListenTaxCollectorUpdatesMessage.taxCollectorId.";
  }
}

StartListenTaxCollectorUpdatesMessage::StartListenTaxCollectorUpdatesMessage()
{
  m_type = MessageEnum::STARTLISTENTAXCOLLECTORUPDATESMESSAGE;
}

