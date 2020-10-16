#include "FriendSetWarnOnLevelGainMessage.h"

void FriendSetWarnOnLevelGainMessage::serialize(Writer *output)
{
  this->serializeAs_FriendSetWarnOnLevelGainMessage(output);
}

void FriendSetWarnOnLevelGainMessage::serializeAs_FriendSetWarnOnLevelGainMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendSetWarnOnLevelGainMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendSetWarnOnLevelGainMessage(input);
}

void FriendSetWarnOnLevelGainMessage::deserializeAs_FriendSetWarnOnLevelGainMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendSetWarnOnLevelGainMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendSetWarnOnLevelGainMessage(tree);
}

void FriendSetWarnOnLevelGainMessage::deserializeAsyncAs_FriendSetWarnOnLevelGainMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendSetWarnOnLevelGainMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendSetWarnOnLevelGainMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendSetWarnOnLevelGainMessage::FriendSetWarnOnLevelGainMessage()
{
  m_type = MessageEnum::FRIENDSETWARNONLEVELGAINMESSAGE;
}

