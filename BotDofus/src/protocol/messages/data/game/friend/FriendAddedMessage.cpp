#include "FriendAddedMessage.h"

void FriendAddedMessage::serialize(Writer *output)
{
  this->serializeAs_FriendAddedMessage(output);
}

void FriendAddedMessage::serializeAs_FriendAddedMessage(Writer *output)
{
  output->writeShort((short)this->friendAdded->getTypes().last());
  this->friendAdded->serialize(output);
}

void FriendAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendAddedMessage(input);
}

void FriendAddedMessage::deserializeAs_FriendAddedMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->friendAdded = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->friendAdded->deserialize(input);
}

void FriendAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendAddedMessage(tree);
}

void FriendAddedMessage::deserializeAsyncAs_FriendAddedMessage(FuncTree tree)
{
  this->_friendAddedtree = tree.addChild(std::bind(&FriendAddedMessage::_friendAddedtreeFunc, this, std::placeholders::_1));
}

void FriendAddedMessage::_friendAddedtreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->friendAdded = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->friendAdded->deserializeAsync(this->_friendAddedtree);
}

FriendAddedMessage::FriendAddedMessage()
{
  m_type = MessageEnum::FRIENDADDEDMESSAGE;
}

