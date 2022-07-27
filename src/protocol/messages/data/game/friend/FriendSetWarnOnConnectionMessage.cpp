#include "FriendSetWarnOnConnectionMessage.h"

void FriendSetWarnOnConnectionMessage::serialize(Writer *output)
{
  this->serializeAs_FriendSetWarnOnConnectionMessage(output);
}

void FriendSetWarnOnConnectionMessage::serializeAs_FriendSetWarnOnConnectionMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendSetWarnOnConnectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendSetWarnOnConnectionMessage(input);
}

void FriendSetWarnOnConnectionMessage::deserializeAs_FriendSetWarnOnConnectionMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendSetWarnOnConnectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSetWarnOnConnectionMessage(tree);
}

void FriendSetWarnOnConnectionMessage::deserializeAsyncAs_FriendSetWarnOnConnectionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendSetWarnOnConnectionMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendSetWarnOnConnectionMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendSetWarnOnConnectionMessage::FriendSetWarnOnConnectionMessage()
{
  m_type = MessageEnum::FRIENDSETWARNONCONNECTIONMESSAGE;
}

