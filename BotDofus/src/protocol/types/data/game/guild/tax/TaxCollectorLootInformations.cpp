#include "TaxCollectorLootInformations.h"

void TaxCollectorLootInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorLootInformations(output);
}

void TaxCollectorLootInformations::serializeAs_TaxCollectorLootInformations(Writer *output)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(output);
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  output->writeVarLong((double)this->experience);
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->pods << ") on element pods.";
  }
  output->writeVarInt((int)this->pods);
  if(this->itemsValue < 0 || this->itemsValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->itemsValue << ") on element itemsValue.";
  }
  output->writeVarLong((double)this->itemsValue);
}

void TaxCollectorLootInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorLootInformations(input);
}

void TaxCollectorLootInformations::deserializeAs_TaxCollectorLootInformations(Reader *input)
{
  TaxCollectorComplementaryInformations::deserialize(input);
  this->_kamasFunc(input);
  this->_experienceFunc(input);
  this->_podsFunc(input);
  this->_itemsValueFunc(input);
}

void TaxCollectorLootInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorLootInformations(tree);
}

void TaxCollectorLootInformations::deserializeAsyncAs_TaxCollectorLootInformations(FuncTree tree)
{
  TaxCollectorComplementaryInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&TaxCollectorLootInformations::_kamasFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorLootInformations::_experienceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorLootInformations::_podsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorLootInformations::_itemsValueFunc, this, std::placeholders::_1));
}

void TaxCollectorLootInformations::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->kamas << ") on element of TaxCollectorLootInformations.kamas.";
  }
}

void TaxCollectorLootInformations::_experienceFunc(Reader *input)
{
  this->experience = input->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->experience << ") on element of TaxCollectorLootInformations.experience.";
  }
}

void TaxCollectorLootInformations::_podsFunc(Reader *input)
{
  this->pods = input->readVarUhInt();
  if(this->pods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->pods << ") on element of TaxCollectorLootInformations.pods.";
  }
}

void TaxCollectorLootInformations::_itemsValueFunc(Reader *input)
{
  this->itemsValue = input->readVarUhLong();
  if(this->itemsValue < 0 || this->itemsValue > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->itemsValue << ") on element of TaxCollectorLootInformations.itemsValue.";
  }
}

TaxCollectorLootInformations::TaxCollectorLootInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORLOOTINFORMATIONS;
}

bool TaxCollectorLootInformations::operator==(const TaxCollectorLootInformations &compared)
{
  if(kamas == compared.kamas)
  if(experience == compared.experience)
  if(pods == compared.pods)
  if(itemsValue == compared.itemsValue)
  return true;
  
  return false;
}

