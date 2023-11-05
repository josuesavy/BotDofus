#include "FriendStatusShareStateMessage.h"

void FriendStatusShareStateMessage::serialize(Writer *output)
{
  this->serializeAs_FriendStatusShareStateMessage(output);
}

void FriendStatusShareStateMessage::serializeAs_FriendStatusShareStateMessage(Writer *output)
{
  output->writeBool(this->share);
}

void FriendStatusShareStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendStatusShareStateMessage(input);
}

void FriendStatusShareStateMessage::deserializeAs_FriendStatusShareStateMessage(Reader *input)
{
  this->_shareFunc(input);
}

void FriendStatusShareStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendStatusShareStateMessage(tree);
}

void FriendStatusShareStateMessage::deserializeAsyncAs_FriendStatusShareStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendStatusShareStateMessage::_shareFunc, this, std::placeholders::_1));
}

void FriendStatusShareStateMessage::_shareFunc(Reader *input)
{
  this->share = input->readBool();
}

FriendStatusShareStateMessage::FriendStatusShareStateMessage()
{
  m_type = MessageEnum::FRIENDSTATUSSHARESTATEMESSAGE;
}

