#include "NuggetsBeneficiary.h"

void NuggetsBeneficiary::serialize(Writer *output)
{
  this->serializeAs_NuggetsBeneficiary(output);
}

void NuggetsBeneficiary::serializeAs_NuggetsBeneficiary(Writer *output)
{
  if(this->beneficiaryPlayerId < 0 || this->beneficiaryPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NuggetsBeneficiary -"<<"Forbidden value (" << this->beneficiaryPlayerId << ") on element beneficiaryPlayerId.";
  }
  output->writeVarLong((double)this->beneficiaryPlayerId);
  output->writeInt((int)this->nuggetsQuantity);
}

void NuggetsBeneficiary::deserialize(Reader *input)
{
  this->deserializeAs_NuggetsBeneficiary(input);
}

void NuggetsBeneficiary::deserializeAs_NuggetsBeneficiary(Reader *input)
{
  this->_beneficiaryPlayerIdFunc(input);
  this->_nuggetsQuantityFunc(input);
}

void NuggetsBeneficiary::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NuggetsBeneficiary(tree);
}

void NuggetsBeneficiary::deserializeAsyncAs_NuggetsBeneficiary(FuncTree tree)
{
  tree.addChild(std::bind(&NuggetsBeneficiary::_beneficiaryPlayerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&NuggetsBeneficiary::_nuggetsQuantityFunc, this, std::placeholders::_1));
}

void NuggetsBeneficiary::_beneficiaryPlayerIdFunc(Reader *input)
{
  this->beneficiaryPlayerId = input->readVarUhLong();
  if(this->beneficiaryPlayerId < 0 || this->beneficiaryPlayerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - NuggetsBeneficiary -"<<"Forbidden value (" << this->beneficiaryPlayerId << ") on element of NuggetsBeneficiary.beneficiaryPlayerId.";
  }
}

void NuggetsBeneficiary::_nuggetsQuantityFunc(Reader *input)
{
  this->nuggetsQuantity = input->readInt();
}

NuggetsBeneficiary::NuggetsBeneficiary()
{
  m_types<<ClassEnum::NUGGETSBENEFICIARY;
}

bool NuggetsBeneficiary::operator==(const NuggetsBeneficiary &compared)
{
  if(beneficiaryPlayerId == compared.beneficiaryPlayerId)
  if(nuggetsQuantity == compared.nuggetsQuantity)
  return true;
  
  return false;
}

