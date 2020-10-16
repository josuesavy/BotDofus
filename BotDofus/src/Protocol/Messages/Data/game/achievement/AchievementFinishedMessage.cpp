#include "AchievementFinishedMessage.h"

void AchievementFinishedMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementFinishedMessage(output);
}

void AchievementFinishedMessage::serializeAs_AchievementFinishedMessage(Writer *output)
{
  this->achievement->serializeAs_AchievementAchievedRewardable(output);
}

void AchievementFinishedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementFinishedMessage(input);
}

void AchievementFinishedMessage::deserializeAs_AchievementFinishedMessage(Reader *input)
{
  this->achievement = QSharedPointer<AchievementAchievedRewardable>(new AchievementAchievedRewardable() );
  this->achievement->deserialize(input);
}

void AchievementFinishedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementFinishedMessage(tree);
}

void AchievementFinishedMessage::deserializeAsyncAs_AchievementFinishedMessage(FuncTree tree)
{
  this->_achievementtree = tree.addChild(std::bind(&AchievementFinishedMessage::_achievementtreeFunc, this, std::placeholders::_1));
}

void AchievementFinishedMessage::_achievementtreeFunc(Reader *input)
{
  this->achievement = QSharedPointer<AchievementAchievedRewardable>(new AchievementAchievedRewardable() );
  this->achievement->deserializeAsync(this->_achievementtree);
}

AchievementFinishedMessage::AchievementFinishedMessage()
{
  m_type = MessageEnum::ACHIEVEMENTFINISHEDMESSAGE;
}

