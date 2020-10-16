#include "FriendDeleteRequestMessage.h"

void FriendDeleteRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendDeleteRequestMessage(output);
}

void FriendDeleteRequestMessage::serializeAs_FriendDeleteRequestMessage(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - FriendDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
}

void FriendDeleteRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendDeleteRequestMessage(input);
}

void FriendDeleteRequestMessage::deserializeAs_FriendDeleteRequestMessage(Reader *input)
{
  this->_accountIdFunc(input);
}

void FriendDeleteRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendDeleteRequestMessage(tree);
}

void FriendDeleteRequestMessage::deserializeAsyncAs_FriendDeleteRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendDeleteRequestMessage::_accountIdFunc, this, std::placeholders::_1));
}

void FriendDeleteRequestMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - FriendDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element of FriendDeleteRequestMessage.accountId.";
  }
}

FriendDeleteRequestMessage::FriendDeleteRequestMessage()
{
  m_type = MessageEnum::FRIENDDELETEREQUESTMESSAGE;
}

