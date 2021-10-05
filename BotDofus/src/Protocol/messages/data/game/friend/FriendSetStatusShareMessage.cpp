#include "FriendSetStatusShareMessage.h"

void FriendSetStatusShareMessage::serialize(Writer *output)
{
  this->serializeAs_FriendSetStatusShareMessage(output);
}

void FriendSetStatusShareMessage::serializeAs_FriendSetStatusShareMessage(Writer *output)
{
  output->writeBool(this->share);
}

void FriendSetStatusShareMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendSetStatusShareMessage(input);
}

void FriendSetStatusShareMessage::deserializeAs_FriendSetStatusShareMessage(Reader *input)
{
  this->_shareFunc(input);
}

void FriendSetStatusShareMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSetStatusShareMessage(tree);
}

void FriendSetStatusShareMessage::deserializeAsyncAs_FriendSetStatusShareMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendSetStatusShareMessage::_shareFunc, this, std::placeholders::_1));
}

void FriendSetStatusShareMessage::_shareFunc(Reader *input)
{
  this->share = input->readBool();
}

FriendSetStatusShareMessage::FriendSetStatusShareMessage()
{
  m_type = MessageEnum::FRIENDSETSTATUSSHAREMESSAGE;
}

