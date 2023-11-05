#include "FriendUpdateMessage.h"

void FriendUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_FriendUpdateMessage(output);
}

void FriendUpdateMessage::serializeAs_FriendUpdateMessage(Writer *output)
{
  output->writeShort((short)this->friendUpdated->getTypes().last());
  this->friendUpdated->serialize(output);
}

void FriendUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendUpdateMessage(input);
}

void FriendUpdateMessage::deserializeAs_FriendUpdateMessage(Reader *input)
{
  uint _id1 = uint(input->readUShort());
  this->friendUpdated = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->friendUpdated->deserialize(input);
}

void FriendUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendUpdateMessage(tree);
}

void FriendUpdateMessage::deserializeAsyncAs_FriendUpdateMessage(FuncTree tree)
{
  this->_friendUpdatedtree = tree.addChild(std::bind(&FriendUpdateMessage::_friendUpdatedtreeFunc, this, std::placeholders::_1));
}

void FriendUpdateMessage::_friendUpdatedtreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->friendUpdated = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->friendUpdated->deserializeAsync(this->_friendUpdatedtree);
}

FriendUpdateMessage::FriendUpdateMessage()
{
  m_type = MessageEnum::FRIENDUPDATEMESSAGE;
}

