#include "AdditionalTaxCollectorInformation.h"

void AdditionalTaxCollectorInformation::serialize(Writer *output)
{
  this->serializeAs_AdditionalTaxCollectorInformation(output);
}

void AdditionalTaxCollectorInformation::serializeAs_AdditionalTaxCollectorInformation(Writer *output)
{
  if(this->collectorCallerId < 0 || this->collectorCallerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformation -"<<"Forbidden value (" << this->collectorCallerId << ") on element collectorCallerId.";
  }
  output->writeVarLong((double)this->collectorCallerId);
  output->writeUTF(this->collectorCallerName);
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformation -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  output->writeInt((int)this->date);
}

void AdditionalTaxCollectorInformation::deserialize(Reader *input)
{
  this->deserializeAs_AdditionalTaxCollectorInformation(input);
}

void AdditionalTaxCollectorInformation::deserializeAs_AdditionalTaxCollectorInformation(Reader *input)
{
  this->_collectorCallerIdFunc(input);
  this->_collectorCallerNameFunc(input);
  this->_dateFunc(input);
}

void AdditionalTaxCollectorInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AdditionalTaxCollectorInformation(tree);
}

void AdditionalTaxCollectorInformation::deserializeAsyncAs_AdditionalTaxCollectorInformation(FuncTree tree)
{
  tree.addChild(std::bind(&AdditionalTaxCollectorInformation::_collectorCallerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AdditionalTaxCollectorInformation::_collectorCallerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AdditionalTaxCollectorInformation::_dateFunc, this, std::placeholders::_1));
}

void AdditionalTaxCollectorInformation::_collectorCallerIdFunc(Reader *input)
{
  this->collectorCallerId = input->readVarUhLong();
  if(this->collectorCallerId < 0 || this->collectorCallerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformation -"<<"Forbidden value (" << this->collectorCallerId << ") on element of AdditionalTaxCollectorInformation.collectorCallerId.";
  }
}

void AdditionalTaxCollectorInformation::_collectorCallerNameFunc(Reader *input)
{
  this->collectorCallerName = input->readUTF();
}

void AdditionalTaxCollectorInformation::_dateFunc(Reader *input)
{
  this->date = input->readInt();
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformation -"<<"Forbidden value (" << this->date << ") on element of AdditionalTaxCollectorInformation.date.";
  }
}

AdditionalTaxCollectorInformation::AdditionalTaxCollectorInformation()
{
  m_types<<ClassEnum::ADDITIONALTAXCOLLECTORINFORMATION;
}

bool AdditionalTaxCollectorInformation::operator==(const AdditionalTaxCollectorInformation &compared)
{
  if(collectorCallerId == compared.collectorCallerId)
  if(collectorCallerName == compared.collectorCallerName)
  if(date == compared.date)
  return true;
  
  return false;
}

