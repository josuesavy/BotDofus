#include "FriendsListMessage.h"

void FriendsListMessage::serialize(Writer *output)
{
  this->serializeAs_FriendsListMessage(output);
}

void FriendsListMessage::serializeAs_FriendsListMessage(Writer *output)
{
  output->writeShort((short)this->friendsList.size());
  for(uint _i1 = 0; _i1 < this->friendsList.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<FriendInformations>(this->friendsList[_i1])->getTypes().last());
    qSharedPointerCast<FriendInformations>(this->friendsList[_i1])->serialize(output);
  }
}

void FriendsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendsListMessage(input);
}

void FriendsListMessage::deserializeAs_FriendsListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<FriendInformations> _item1 ;
  uint _friendsListLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _friendsListLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->friendsList.append(_item1);
  }
}

void FriendsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendsListMessage(tree);
}

void FriendsListMessage::deserializeAsyncAs_FriendsListMessage(FuncTree tree)
{
  this->_friendsListtree = tree.addChild(std::bind(&FriendsListMessage::_friendsListtreeFunc, this, std::placeholders::_1));
}

void FriendsListMessage::_friendsListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_friendsListtree.addChild(std::bind(&FriendsListMessage::_friendsListFunc, this, std::placeholders::_1));
  }
}

void FriendsListMessage::_friendsListFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<FriendInformations> _item = qSharedPointerCast<FriendInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->friendsList.append(_item);
}

FriendsListMessage::FriendsListMessage()
{
  m_type = MessageEnum::FRIENDSLISTMESSAGE;
}

