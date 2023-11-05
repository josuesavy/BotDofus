#include "FriendJoinRequestMessage.h"

void FriendJoinRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendJoinRequestMessage(output);
}

void FriendJoinRequestMessage::serializeAs_FriendJoinRequestMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void FriendJoinRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendJoinRequestMessage(input);
}

void FriendJoinRequestMessage::deserializeAs_FriendJoinRequestMessage(Reader *input)
{
  uint _id1 = uint(input->readUShort());
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
}

void FriendJoinRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendJoinRequestMessage(tree);
}

void FriendJoinRequestMessage::deserializeAsyncAs_FriendJoinRequestMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&FriendJoinRequestMessage::_targettreeFunc, this, std::placeholders::_1));
}

void FriendJoinRequestMessage::_targettreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

FriendJoinRequestMessage::FriendJoinRequestMessage()
{
  m_type = MessageEnum::FRIENDJOINREQUESTMESSAGE;
}

