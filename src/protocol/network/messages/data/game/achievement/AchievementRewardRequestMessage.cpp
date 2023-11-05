#include "AchievementRewardRequestMessage.h"

void AchievementRewardRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementRewardRequestMessage(output);
}

void AchievementRewardRequestMessage::serializeAs_AchievementRewardRequestMessage(Writer *output)
{
  output->writeShort((short)this->achievementId);
}

void AchievementRewardRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementRewardRequestMessage(input);
}

void AchievementRewardRequestMessage::deserializeAs_AchievementRewardRequestMessage(Reader *input)
{
  this->_achievementIdFunc(input);
}

void AchievementRewardRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementRewardRequestMessage(tree);
}

void AchievementRewardRequestMessage::deserializeAsyncAs_AchievementRewardRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementRewardRequestMessage::_achievementIdFunc, this, std::placeholders::_1));
}

void AchievementRewardRequestMessage::_achievementIdFunc(Reader *input)
{
  this->achievementId = input->readShort();
}

AchievementRewardRequestMessage::AchievementRewardRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTREWARDREQUESTMESSAGE;
}

