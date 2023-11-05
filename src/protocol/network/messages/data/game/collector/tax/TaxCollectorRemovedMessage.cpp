#include "TaxCollectorRemovedMessage.h"

void TaxCollectorRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorRemovedMessage(output);
}

void TaxCollectorRemovedMessage::serializeAs_TaxCollectorRemovedMessage(Writer *output)
{
  if(this->collectorId < 0 || this->collectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorRemovedMessage -"<<"Forbidden value (" << this->collectorId << ") on element collectorId.";
  }
  output->writeDouble(this->collectorId);
}

void TaxCollectorRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorRemovedMessage(input);
}

void TaxCollectorRemovedMessage::deserializeAs_TaxCollectorRemovedMessage(Reader *input)
{
  this->_collectorIdFunc(input);
}

void TaxCollectorRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorRemovedMessage(tree);
}

void TaxCollectorRemovedMessage::deserializeAsyncAs_TaxCollectorRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorRemovedMessage::_collectorIdFunc, this, std::placeholders::_1));
}

void TaxCollectorRemovedMessage::_collectorIdFunc(Reader *input)
{
  this->collectorId = input->readDouble();
  if(this->collectorId < 0 || this->collectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorRemovedMessage -"<<"Forbidden value (" << this->collectorId << ") on element of TaxCollectorRemovedMessage.collectorId.";
  }
}

TaxCollectorRemovedMessage::TaxCollectorRemovedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORREMOVEDMESSAGE;
}

