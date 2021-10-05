#include "KamaDebtInformation.h"

void KamaDebtInformation::serialize(Writer *output)
{
  this->serializeAs_KamaDebtInformation(output);
}

void KamaDebtInformation::serializeAs_KamaDebtInformation(Writer *output)
{
  DebtInformation::serializeAs_DebtInformation(output);
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KamaDebtInformation -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  output->writeVarLong((double)this->kamas);
}

void KamaDebtInformation::deserialize(Reader *input)
{
  this->deserializeAs_KamaDebtInformation(input);
}

void KamaDebtInformation::deserializeAs_KamaDebtInformation(Reader *input)
{
  DebtInformation::deserialize(input);
  this->_kamasFunc(input);
}

void KamaDebtInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KamaDebtInformation(tree);
}

void KamaDebtInformation::deserializeAsyncAs_KamaDebtInformation(FuncTree tree)
{
  DebtInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&KamaDebtInformation::_kamasFunc, this, std::placeholders::_1));
}

void KamaDebtInformation::_kamasFunc(Reader *input)
{
  this->kamas = input->readVarUhLong();
  if(this->kamas < 0 || this->kamas > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KamaDebtInformation -"<<"Forbidden value (" << this->kamas << ") on element of KamaDebtInformation.kamas.";
  }
}

KamaDebtInformation::KamaDebtInformation()
{
  m_types<<ClassEnum::KAMADEBTINFORMATION;
}

bool KamaDebtInformation::operator==(const KamaDebtInformation &compared)
{
  if(kamas == compared.kamas)
  return true;
  
  return false;
}

