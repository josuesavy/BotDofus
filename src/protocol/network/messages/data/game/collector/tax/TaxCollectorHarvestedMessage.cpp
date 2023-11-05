#include "TaxCollectorHarvestedMessage.h"

void TaxCollectorHarvestedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorHarvestedMessage(output);
}

void TaxCollectorHarvestedMessage::serializeAs_TaxCollectorHarvestedMessage(Writer *output)
{
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorHarvestedMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element taxCollectorId.";
  }
  output->writeDouble(this->taxCollectorId);
  if(this->harvesterId < 0 || this->harvesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorHarvestedMessage -"<<"Forbidden value (" << this->harvesterId << ") on element harvesterId.";
  }
  output->writeVarLong((double)this->harvesterId);
  output->writeUTF(this->harvesterName);
}

void TaxCollectorHarvestedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorHarvestedMessage(input);
}

void TaxCollectorHarvestedMessage::deserializeAs_TaxCollectorHarvestedMessage(Reader *input)
{
  this->_taxCollectorIdFunc(input);
  this->_harvesterIdFunc(input);
  this->_harvesterNameFunc(input);
}

void TaxCollectorHarvestedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorHarvestedMessage(tree);
}

void TaxCollectorHarvestedMessage::deserializeAsyncAs_TaxCollectorHarvestedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorHarvestedMessage::_taxCollectorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorHarvestedMessage::_harvesterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorHarvestedMessage::_harvesterNameFunc, this, std::placeholders::_1));
}

void TaxCollectorHarvestedMessage::_taxCollectorIdFunc(Reader *input)
{
  this->taxCollectorId = input->readDouble();
  if(this->taxCollectorId < 0 || this->taxCollectorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorHarvestedMessage -"<<"Forbidden value (" << this->taxCollectorId << ") on element of TaxCollectorHarvestedMessage.taxCollectorId.";
  }
}

void TaxCollectorHarvestedMessage::_harvesterIdFunc(Reader *input)
{
  this->harvesterId = input->readVarUhLong();
  if(this->harvesterId < 0 || this->harvesterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorHarvestedMessage -"<<"Forbidden value (" << this->harvesterId << ") on element of TaxCollectorHarvestedMessage.harvesterId.";
  }
}

void TaxCollectorHarvestedMessage::_harvesterNameFunc(Reader *input)
{
  this->harvesterName = input->readUTF();
}

TaxCollectorHarvestedMessage::TaxCollectorHarvestedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORHARVESTEDMESSAGE;
}

