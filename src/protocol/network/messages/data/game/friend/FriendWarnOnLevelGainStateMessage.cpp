#include "FriendWarnOnLevelGainStateMessage.h"

void FriendWarnOnLevelGainStateMessage::serialize(Writer *output)
{
  this->serializeAs_FriendWarnOnLevelGainStateMessage(output);
}

void FriendWarnOnLevelGainStateMessage::serializeAs_FriendWarnOnLevelGainStateMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendWarnOnLevelGainStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendWarnOnLevelGainStateMessage(input);
}

void FriendWarnOnLevelGainStateMessage::deserializeAs_FriendWarnOnLevelGainStateMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendWarnOnLevelGainStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendWarnOnLevelGainStateMessage(tree);
}

void FriendWarnOnLevelGainStateMessage::deserializeAsyncAs_FriendWarnOnLevelGainStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendWarnOnLevelGainStateMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendWarnOnLevelGainStateMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendWarnOnLevelGainStateMessage::FriendWarnOnLevelGainStateMessage()
{
  m_type = MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE;
}

