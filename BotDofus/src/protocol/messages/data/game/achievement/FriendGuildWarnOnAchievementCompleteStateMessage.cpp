#include "FriendGuildWarnOnAchievementCompleteStateMessage.h"

void FriendGuildWarnOnAchievementCompleteStateMessage::serialize(Writer *output)
{
  this->serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(output);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::serializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(input);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserializeAs_FriendGuildWarnOnAchievementCompleteStateMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendGuildWarnOnAchievementCompleteStateMessage(tree);
}

void FriendGuildWarnOnAchievementCompleteStateMessage::deserializeAsyncAs_FriendGuildWarnOnAchievementCompleteStateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendGuildWarnOnAchievementCompleteStateMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendGuildWarnOnAchievementCompleteStateMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendGuildWarnOnAchievementCompleteStateMessage::FriendGuildWarnOnAchievementCompleteStateMessage()
{
  m_type = MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE;
}

