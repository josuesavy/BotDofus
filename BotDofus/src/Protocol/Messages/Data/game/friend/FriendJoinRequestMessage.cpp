#include "FriendJoinRequestMessage.h"

void FriendJoinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendJoinRequestMessage(output);
}

void FriendJoinRequestMessage::serializeAs_FriendJoinRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
}

void FriendJoinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendJoinRequestMessage(input);
}

void FriendJoinRequestMessage::deserializeAs_FriendJoinRequestMessage(Reader *input)
{
  this->_nameFunc(input);
}

void FriendJoinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendJoinRequestMessage(tree);
}

void FriendJoinRequestMessage::deserializeAsyncAs_FriendJoinRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendJoinRequestMessage::_nameFunc, this, std::placeholders::_1));
}

void FriendJoinRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

FriendJoinRequestMessage::FriendJoinRequestMessage()
{
  m_type = MessageEnum::FRIENDJOINREQUESTMESSAGE;
}

