#include "AbstractContactInformations.h"

void AbstractContactInformations::serialize(Writer *output)
{
  this->serializeAs_AbstractContactInformations(output);
}

void AbstractContactInformations::serializeAs_AbstractContactInformations(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AbstractContactInformations -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeUTF(this->accountName);
}

void AbstractContactInformations::deserialize(Reader *input)
{
  this->deserializeAs_AbstractContactInformations(input);
}

void AbstractContactInformations::deserializeAs_AbstractContactInformations(Reader *input)
{
  this->_accountIdFunc(input);
  this->_accountNameFunc(input);
}

void AbstractContactInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractContactInformations(tree);
}

void AbstractContactInformations::deserializeAsyncAs_AbstractContactInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractContactInformations::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AbstractContactInformations::_accountNameFunc, this, std::placeholders::_1));
}

void AbstractContactInformations::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AbstractContactInformations -"<<"Forbidden value (" << this->accountId << ") on element of AbstractContactInformations.accountId.";
  }
}

void AbstractContactInformations::_accountNameFunc(Reader *input)
{
  this->accountName = input->readUTF();
}

AbstractContactInformations::AbstractContactInformations()
{
  m_types<<ClassEnum::ABSTRACTCONTACTINFORMATIONS;
}

bool AbstractContactInformations::operator==(const AbstractContactInformations &compared)
{
  if(accountId == compared.accountId)
  if(accountName == compared.accountName)
  return true;
  
  return false;
}

