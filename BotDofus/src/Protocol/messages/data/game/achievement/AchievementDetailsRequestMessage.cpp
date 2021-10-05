#include "AchievementDetailsRequestMessage.h"

void AchievementDetailsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AchievementDetailsRequestMessage(output);
}

void AchievementDetailsRequestMessage::serializeAs_AchievementDetailsRequestMessage(Writer *output)
{
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailsRequestMessage -"<<"Forbidden value (" << this->achievementId << ") on element achievementId.";
  }
  output->writeVarShort((int)this->achievementId);
}

void AchievementDetailsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AchievementDetailsRequestMessage(input);
}

void AchievementDetailsRequestMessage::deserializeAs_AchievementDetailsRequestMessage(Reader *input)
{
  this->_achievementIdFunc(input);
}

void AchievementDetailsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementDetailsRequestMessage(tree);
}

void AchievementDetailsRequestMessage::deserializeAsyncAs_AchievementDetailsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementDetailsRequestMessage::_achievementIdFunc, this, std::placeholders::_1));
}

void AchievementDetailsRequestMessage::_achievementIdFunc(Reader *input)
{
  this->achievementId = input->readVarUhShort();
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailsRequestMessage -"<<"Forbidden value (" << this->achievementId << ") on element of AchievementDetailsRequestMessage.achievementId.";
  }
}

AchievementDetailsRequestMessage::AchievementDetailsRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILSREQUESTMESSAGE;
}

