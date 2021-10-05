#include "FriendGuildSetWarnOnAchievementCompleteMessage.h"

void FriendGuildSetWarnOnAchievementCompleteMessage::serialize(Writer *output)
{
  this->serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(output);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::serializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Writer *output)
{
  output->writeBool(this->enable);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserialize(Reader *input)
{
  this->deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(input);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserializeAs_FriendGuildSetWarnOnAchievementCompleteMessage(Reader *input)
{
  this->_enableFunc(input);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FriendGuildSetWarnOnAchievementCompleteMessage(tree);
}

void FriendGuildSetWarnOnAchievementCompleteMessage::deserializeAsyncAs_FriendGuildSetWarnOnAchievementCompleteMessage(FuncTree tree)
{
  tree.addChild(std::bind(&FriendGuildSetWarnOnAchievementCompleteMessage::_enableFunc, this, std::placeholders::_1));
}

void FriendGuildSetWarnOnAchievementCompleteMessage::_enableFunc(Reader *input)
{
  this->enable = input->readBool();
}

FriendGuildSetWarnOnAchievementCompleteMessage::FriendGuildSetWarnOnAchievementCompleteMessage()
{
  m_type = MessageEnum::FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE;
}

