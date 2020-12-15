#include "AchievementDetailsMessage.h"

void AchievementDetailsMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementDetailsMessage(output);
}

void AchievementDetailsMessage::serializeAs_AchievementDetailsMessage(Writer *output)
{
  this->achievement.serializeAs_Achievement(output);
}

void AchievementDetailsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementDetailsMessage(input);
}

void AchievementDetailsMessage::deserializeAs_AchievementDetailsMessage(Reader *input)
{
  this->achievement = Achievement();
  this->achievement.deserialize(input);
}

void AchievementDetailsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementDetailsMessage(tree);
}

void AchievementDetailsMessage::deserializeAsyncAs_AchievementDetailsMessage(FuncTree tree)
{
  this->_achievementtree = tree.addChild(std::bind(&AchievementDetailsMessage::_achievementtreeFunc, this, std::placeholders::_1));
}

void AchievementDetailsMessage::_achievementtreeFunc(Reader *input)
{
  this->achievement = Achievement();
  this->achievement.deserializeAsync(this->_achievementtree);
}

AchievementDetailsMessage::AchievementDetailsMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILSMESSAGE;
}

