#include "FriendAddFailureMessage.h"

void FriendAddFailureMessage::serialize(Writer *output)
{
  this->serializeAs_FriendAddFailureMessage(output);
}

void FriendAddFailureMessage::serializeAs_FriendAddFailureMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void FriendAddFailureMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendAddFailureMessage(input);
}

void FriendAddFailureMessage::deserializeAs_FriendAddFailureMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void FriendAddFailureMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendAddFailureMessage(tree);
}

void FriendAddFailureMessage::deserializeAsyncAs_FriendAddFailureMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendAddFailureMessage::_reasonFunc, this, std::placeholders::_1));
}

void FriendAddFailureMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - FriendAddFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of FriendAddFailureMessage.reason.";
  }
}

FriendAddFailureMessage::FriendAddFailureMessage()
{
  m_type = MessageEnum::FRIENDADDFAILUREMESSAGE;
}

