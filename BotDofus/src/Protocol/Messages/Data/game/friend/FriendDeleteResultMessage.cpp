#include "FriendDeleteResultMessage.h"

void FriendDeleteResultMessage::serialize(Writer *output)
{
  this->serializeAs_FriendDeleteResultMessage(output);
}

void FriendDeleteResultMessage::serializeAs_FriendDeleteResultMessage(Writer *output)
{
  output->writeBool(this->success);
  this->tag.serializeAs_AccountTagInformation(output);
}

void FriendDeleteResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendDeleteResultMessage(input);
}

void FriendDeleteResultMessage::deserializeAs_FriendDeleteResultMessage(Reader *input)
{
  this->_successFunc(input);
  this->tag = AccountTagInformation();
  this->tag.deserialize(input);
}

void FriendDeleteResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendDeleteResultMessage(tree);
}

void FriendDeleteResultMessage::deserializeAsyncAs_FriendDeleteResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendDeleteResultMessage::_successFunc, this, std::placeholders::_1));
  this->_tagtree = tree.addChild(std::bind(&FriendDeleteResultMessage::_tagtreeFunc, this, std::placeholders::_1));
}

void FriendDeleteResultMessage::_successFunc(Reader *input)
{
  this->success = input->readBool();
}

void FriendDeleteResultMessage::_tagtreeFunc(Reader *input)
{
  this->tag = AccountTagInformation();
  this->tag.deserializeAsync(this->_tagtree);
}

FriendDeleteResultMessage::FriendDeleteResultMessage()
{
  m_type = MessageEnum::FRIENDDELETERESULTMESSAGE;
}

