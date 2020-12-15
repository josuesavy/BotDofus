#include "AdditionalTaxCollectorInformations.h"

void AdditionalTaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_AdditionalTaxCollectorInformations(output);
}

void AdditionalTaxCollectorInformations::serializeAs_AdditionalTaxCollectorInformations(Writer *output)
{
  output->writeUTF(this->collectorCallerName);
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformations -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  output->writeInt((int)this->date);
}

void AdditionalTaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_AdditionalTaxCollectorInformations(input);
}

void AdditionalTaxCollectorInformations::deserializeAs_AdditionalTaxCollectorInformations(Reader *input)
{
  this->_collectorCallerNameFunc(input);
  this->_dateFunc(input);
}

void AdditionalTaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AdditionalTaxCollectorInformations(tree);
}

void AdditionalTaxCollectorInformations::deserializeAsyncAs_AdditionalTaxCollectorInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AdditionalTaxCollectorInformations::_collectorCallerNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AdditionalTaxCollectorInformations::_dateFunc, this, std::placeholders::_1));
}

void AdditionalTaxCollectorInformations::_collectorCallerNameFunc(Reader *input)
{
  this->collectorCallerName = input->readUTF();
}

void AdditionalTaxCollectorInformations::_dateFunc(Reader *input)
{
  this->date = input->readInt();
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformations -"<<"Forbidden value (" << this->date << ") on element of AdditionalTaxCollectorInformations.date.";
  }
}

AdditionalTaxCollectorInformations::AdditionalTaxCollectorInformations()
{
  m_types<<ClassEnum::ADDITIONALTAXCOLLECTORINFORMATIONS;
}

bool AdditionalTaxCollectorInformations::operator==(const AdditionalTaxCollectorInformations &compared)
{
  if(collectorCallerName == compared.collectorCallerName)
  if(date == compared.date)
  return true;
  
  return false;
}

