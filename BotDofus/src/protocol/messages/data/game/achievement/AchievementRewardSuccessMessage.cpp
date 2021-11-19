#include "AchievementRewardSuccessMessage.h"

void AchievementRewardSuccessMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementRewardSuccessMessage(output);
}

void AchievementRewardSuccessMessage::serializeAs_AchievementRewardSuccessMessage(Writer *output)
{
  output->writeShort((short)this->achievementId);
}

void AchievementRewardSuccessMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementRewardSuccessMessage(input);
}

void AchievementRewardSuccessMessage::deserializeAs_AchievementRewardSuccessMessage(Reader *input)
{
  this->_achievementIdFunc(input);
}

void AchievementRewardSuccessMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementRewardSuccessMessage(tree);
}

void AchievementRewardSuccessMessage::deserializeAsyncAs_AchievementRewardSuccessMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementRewardSuccessMessage::_achievementIdFunc, this, std::placeholders::_1));
}

void AchievementRewardSuccessMessage::_achievementIdFunc(Reader *input)
{
  this->achievementId = input->readShort();
}

AchievementRewardSuccessMessage::AchievementRewardSuccessMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDSUCCESSMESSAGE;
}

