#include "TaxCollectorMovementRemoveMessage.h"

void TaxCollectorMovementRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorMovementRemoveMessage(output);
}

void TaxCollectorMovementRemoveMessage::serializeAs_TaxCollectorMovementRemoveMessage(Writer *output)
{
  if(this->collectorId < 0 || this->collectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementRemoveMessage -"<<"Forbidden value (" << this->collectorId << ") on element collectorId.";
  }
  output->writeDouble(this->collectorId);
}

void TaxCollectorMovementRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorMovementRemoveMessage(input);
}

void TaxCollectorMovementRemoveMessage::deserializeAs_TaxCollectorMovementRemoveMessage(Reader *input)
{
  this->_collectorIdFunc(input);
}

void TaxCollectorMovementRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorMovementRemoveMessage(tree);
}

void TaxCollectorMovementRemoveMessage::deserializeAsyncAs_TaxCollectorMovementRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorMovementRemoveMessage::_collectorIdFunc, this, std::placeholders::_1));
}

void TaxCollectorMovementRemoveMessage::_collectorIdFunc(Reader *input)
{
  this->collectorId = input->readDouble();
  if(this->collectorId < 0 || this->collectorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementRemoveMessage -"<<"Forbidden value (" << this->collectorId << ") on element of TaxCollectorMovementRemoveMessage.collectorId.";
  }
}

TaxCollectorMovementRemoveMessage::TaxCollectorMovementRemoveMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTREMOVEMESSAGE;
}

