#include "FriendAddRequestMessage.h"

void FriendAddRequestMessage::serialize(Writer *output)
{
  this->serializeAs_FriendAddRequestMessage(output);
}

void FriendAddRequestMessage::serializeAs_FriendAddRequestMessage(Writer *output)
{
  output->writeShort((short)this->target->getTypes().last());
  this->target->serialize(output);
}

void FriendAddRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendAddRequestMessage(input);
}

void FriendAddRequestMessage::deserializeAs_FriendAddRequestMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id1));
  this->target->deserialize(input);
}

void FriendAddRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendAddRequestMessage(tree);
}

void FriendAddRequestMessage::deserializeAsyncAs_FriendAddRequestMessage(FuncTree tree)
{
  this->_targettree = tree.addChild(std::bind(&FriendAddRequestMessage::_targettreeFunc, this, std::placeholders::_1));
}

void FriendAddRequestMessage::_targettreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->target = qSharedPointerCast<AbstractPlayerSearchInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->target->deserializeAsync(this->_targettree);
}

FriendAddRequestMessage::FriendAddRequestMessage()
{
  m_type = MessageEnum::FRIENDADDREQUESTMESSAGE;
  m_needsHash = true;
}

