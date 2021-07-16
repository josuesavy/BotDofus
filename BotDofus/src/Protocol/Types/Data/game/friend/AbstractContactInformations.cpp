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
  this->accountTag.serializeAs_AccountTagInformation(output);
}

void AbstractContactInformations::deserialize(Reader *input)
{
  this->deserializeAs_AbstractContactInformations(input);
}

void AbstractContactInformations::deserializeAs_AbstractContactInformations(Reader *input)
{
  this->_accountIdFunc(input);
  this->accountTag = AccountTagInformation();
  this->accountTag.deserialize(input);
}

void AbstractContactInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AbstractContactInformations(tree);
}

void AbstractContactInformations::deserializeAsyncAs_AbstractContactInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AbstractContactInformations::_accountIdFunc, this, std::placeholders::_1));
  this->_accountTagtree = tree.addChild(std::bind(&AbstractContactInformations::_accountTagtreeFunc, this, std::placeholders::_1));
}

void AbstractContactInformations::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AbstractContactInformations -"<<"Forbidden value (" << this->accountId << ") on element of AbstractContactInformations.accountId.";
  }
}

void AbstractContactInformations::_accountTagtreeFunc(Reader *input)
{
  this->accountTag = AccountTagInformation();
  this->accountTag.deserializeAsync(this->_accountTagtree);
}

AbstractContactInformations::AbstractContactInformations()
{
  m_types<<ClassEnum::ABSTRACTCONTACTINFORMATIONS;
}

bool AbstractContactInformations::operator==(const AbstractContactInformations &compared)
{
  if(accountId == compared.accountId)
  if(accountTag == compared.accountTag)
  if(_accountTagtree == compared._accountTagtree)
  return true;
  
  return false;
}

