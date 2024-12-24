#include "AchievementRewardErrorMessage.h"

void AchievementRewardErrorMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementRewardErrorMessage(output);
}

void AchievementRewardErrorMessage::serializeAs_AchievementRewardErrorMessage(Writer *output)
{
  output->writeShort((short)this->achievementId);
}

void AchievementRewardErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementRewardErrorMessage(input);
}

void AchievementRewardErrorMessage::deserializeAs_AchievementRewardErrorMessage(Reader *input)
{
  this->_achievementIdFunc(input);
}

void AchievementRewardErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementRewardErrorMessage(tree);
}

void AchievementRewardErrorMessage::deserializeAsyncAs_AchievementRewardErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementRewardErrorMessage::_achievementIdFunc, this, std::placeholders::_1));
}

void AchievementRewardErrorMessage::_achievementIdFunc(Reader *input)
{
  this->achievementId = input->readShort();
}

AchievementRewardErrorMessage::AchievementRewardErrorMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDERRORMESSAGE;
}

