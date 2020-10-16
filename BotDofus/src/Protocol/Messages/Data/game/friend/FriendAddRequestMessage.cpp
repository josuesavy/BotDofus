#include "FriendAddRequestMessage.h"

void FriendAddRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendAddRequestMessage(output);
}

void FriendAddRequestMessage::serializeAs_FriendAddRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
}

void FriendAddRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendAddRequestMessage(input);
}

void FriendAddRequestMessage::deserializeAs_FriendAddRequestMessage(Reader *input)
{
  this->_nameFunc(input);
}

void FriendAddRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendAddRequestMessage(tree);
}

void FriendAddRequestMessage::deserializeAsyncAs_FriendAddRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendAddRequestMessage::_nameFunc, this, std::placeholders::_1));
}

void FriendAddRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

FriendAddRequestMessage::FriendAddRequestMessage()
{
  m_type = MessageEnum::FRIENDADDREQUESTMESSAGE;
  m_needsHash = true;
}

