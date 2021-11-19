#include "DebtInformation.h"

void DebtInformation::serialize(Writer *output)
{
  this->serializeAs_DebtInformation(output);
}

void DebtInformation::serializeAs_DebtInformation(Writer *output)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DebtInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DebtInformation -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  output->writeDouble(this->timestamp);
}

void DebtInformation::deserialize(Reader *input)
{
  this->deserializeAs_DebtInformation(input);
}

void DebtInformation::deserializeAs_DebtInformation(Reader *input)
{
  this->_idFunc(input);
  this->_timestampFunc(input);
}

void DebtInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DebtInformation(tree);
}

void DebtInformation::deserializeAsyncAs_DebtInformation(FuncTree tree)
{
  tree.addChild(std::bind(&DebtInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DebtInformation::_timestampFunc, this, std::placeholders::_1));
}

void DebtInformation::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DebtInformation -"<<"Forbidden value (" << this->id << ") on element of DebtInformation.id.";
  }
}

void DebtInformation::_timestampFunc(Reader *input)
{
  this->timestamp = input->readDouble();
  if(this->timestamp < 0 || this->timestamp > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DebtInformation -"<<"Forbidden value (" << this->timestamp << ") on element of DebtInformation.timestamp.";
  }
}

DebtInformation::DebtInformation()
{
  m_types<<ClassEnum::DEBTINFORMATION;
}

bool DebtInformation::operator==(const DebtInformation &compared)
{
  if(id == compared.id)
  if(timestamp == compared.timestamp)
  return true;
  
  return false;
}

