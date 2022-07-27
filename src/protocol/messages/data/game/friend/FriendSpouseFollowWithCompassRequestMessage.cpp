#include "FriendSpouseFollowWithCompassRequestMessage.h"

void FriendSpouseFollowWithCompassRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendSpouseFollowWithCompassRequestMessage(output);
}

void FriendSpouseFollowWithCompassRequestMessage::serializeAs_FriendSpouseFollowWithCompassRequestMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendSpouseFollowWithCompassRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendSpouseFollowWithCompassRequestMessage(input);
}

void FriendSpouseFollowWithCompassRequestMessage::deserializeAs_FriendSpouseFollowWithCompassRequestMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendSpouseFollowWithCompassRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSpouseFollowWithCompassRequestMessage(tree);
}

void FriendSpouseFollowWithCompassRequestMessage::deserializeAsyncAs_FriendSpouseFollowWithCompassRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendSpouseFollowWithCompassRequestMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendSpouseFollowWithCompassRequestMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendSpouseFollowWithCompassRequestMessage::FriendSpouseFollowWithCompassRequestMessage()
{
  m_type = MessageEnum::FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE;
}

