#include "ForceAccountMessage.h"

void ForceAccountMessage::serialize(Writer *output)
{
  this->serializeAs_ForceAccountMessage(output);
}

void ForceAccountMessage::serializeAs_ForceAccountMessage(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ForceAccountMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void ForceAccountMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForceAccountMessage(input);
}

void ForceAccountMessage::deserializeAs_ForceAccountMessage(Reader *input)
{
  this->_accountIdFunc(input);
}

void ForceAccountMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForceAccountMessage(tree);
}

void ForceAccountMessage::deserializeAsyncAs_ForceAccountMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForceAccountMessage::_accountIdFunc, this, std::placeholders::_1));
}

void ForceAccountMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - ForceAccountMessage -"<<"Forbidden value (" << this->accountId << ") on element of ForceAccountMessage.accountId.";
  }
}

ForceAccountMessage::ForceAccountMessage()
{
  m_type = MessageEnum::FORCEACCOUNTMESSAGE;
}

