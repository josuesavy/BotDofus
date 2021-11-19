#include "IgnoredDeleteRequestMessage.h"

void IgnoredDeleteRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IgnoredDeleteRequestMessage(output);
}

void IgnoredDeleteRequestMessage::serializeAs_IgnoredDeleteRequestMessage(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IgnoredDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  output->writeBool(this->session);
}

void IgnoredDeleteRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IgnoredDeleteRequestMessage(input);
}

void IgnoredDeleteRequestMessage::deserializeAs_IgnoredDeleteRequestMessage(Reader *input)
{
  this->_accountIdFunc(input);
  this->_sessionFunc(input);
}

void IgnoredDeleteRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IgnoredDeleteRequestMessage(tree);
}

void IgnoredDeleteRequestMessage::deserializeAsyncAs_IgnoredDeleteRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IgnoredDeleteRequestMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IgnoredDeleteRequestMessage::_sessionFunc, this, std::placeholders::_1));
}

void IgnoredDeleteRequestMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IgnoredDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element of IgnoredDeleteRequestMessage.accountId.";
  }
}

void IgnoredDeleteRequestMessage::_sessionFunc(Reader *input)
{
  this->session = input->readBool();
}

IgnoredDeleteRequestMessage::IgnoredDeleteRequestMessage()
{
  m_type = MessageEnum::IGNOREDDELETEREQUESTMESSAGE;
}

