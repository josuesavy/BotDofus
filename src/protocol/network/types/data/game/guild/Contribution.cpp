#include "Contribution.h"

void Contribution::serialize(Writer *output)
{
  this->serializeAs_Contribution(output);
}

void Contribution::serializeAs_Contribution(Writer *output)
{
  if(this->contributorId < 0 || this->contributorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - Contribution -"<<"Forbidden value (" << this->contributorId << ") on element contributorId.";
  }
  output->writeVarLong((double)this->contributorId);
  output->writeUTF(this->contributorName);
  if(this->amount < 0 || this->amount > 9007199254740992)
  {
    qDebug()<<"ERREUR - Contribution -"<<"Forbidden value (" << this->amount << ") on element amount.";
  }
  output->writeVarLong((double)this->amount);
}

void Contribution::deserialize(Reader *input)
{
  this->deserializeAs_Contribution(input);
}

void Contribution::deserializeAs_Contribution(Reader *input)
{
  this->_contributorIdFunc(input);
  this->_contributorNameFunc(input);
  this->_amountFunc(input);
}

void Contribution::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_Contribution(tree);
}

void Contribution::deserializeAsyncAs_Contribution(FuncTree tree)
{
  tree.addChild(std::bind(&Contribution::_contributorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Contribution::_contributorNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&Contribution::_amountFunc, this, std::placeholders::_1));
}

void Contribution::_contributorIdFunc(Reader *input)
{
  this->contributorId = input->readVarUhLong();
  if(this->contributorId < 0 || this->contributorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - Contribution -"<<"Forbidden value (" << this->contributorId << ") on element of Contribution.contributorId.";
  }
}

void Contribution::_contributorNameFunc(Reader *input)
{
  this->contributorName = input->readUTF();
}

void Contribution::_amountFunc(Reader *input)
{
  this->amount = input->readVarUhLong();
  if(this->amount < 0 || this->amount > 9007199254740992)
  {
    qDebug()<<"ERREUR - Contribution -"<<"Forbidden value (" << this->amount << ") on element of Contribution.amount.";
  }
}

Contribution::Contribution()
{
  m_types<<ClassEnum::CONTRIBUTION;
}

bool Contribution::operator==(const Contribution &compared)
{
  if(contributorId == compared.contributorId)
  if(contributorName == compared.contributorName)
  if(amount == compared.amount)
  return true;
  
  return false;
}

