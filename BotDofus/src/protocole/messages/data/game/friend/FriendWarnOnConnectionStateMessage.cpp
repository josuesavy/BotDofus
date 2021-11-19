#include "FriendWarnOnConnectionStateMessage.h"

void FriendWarnOnConnectionStateMessage::serialize(Writer *output)
{
  this->serializeAs_FriendWarnOnConnectionStateMessage(output);
}

void FriendWarnOnConnectionStateMessage::serializeAs_FriendWarnOnConnectionStateMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendWarnOnConnectionStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendWarnOnConnectionStateMessage(input);
}

void FriendWarnOnConnectionStateMessage::deserializeAs_FriendWarnOnConnectionStateMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendWarnOnConnectionStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendWarnOnConnectionStateMessage(tree);
}

void FriendWarnOnConnectionStateMessage::deserializeAsyncAs_FriendWarnOnConnectionStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendWarnOnConnectionStateMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendWarnOnConnectionStateMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendWarnOnConnectionStateMessage::FriendWarnOnConnectionStateMessage()
{
  m_type = MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE;
}

