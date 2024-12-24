#include "AchievementAchievedRewardable.h"

void AchievementAchievedRewardable::serialize(Writer *output)
{
  this->serializeAs_AchievementAchievedRewardable(output);
}

void AchievementAchievedRewardable::serializeAs_AchievementAchievedRewardable(Writer *output)
{
  AchievementAchieved::serializeAs_AchievementAchieved(output);
  if(this->finishedLevel < 0 || this->finishedLevel > 200)
  {
    qDebug()<<"ERREUR - AchievementAchievedRewardable -"<<"Forbidden value (" << this->finishedLevel << ") on element finishedLevel.";
  }
  output->writeVarShort((int)this->finishedLevel);
}

void AchievementAchievedRewardable::deserialize(Reader *input)
{
  this->deserializeAs_AchievementAchievedRewardable(input);
}

void AchievementAchievedRewardable::deserializeAs_AchievementAchievedRewardable(Reader *input)
{
  AchievementAchieved::deserialize(input);
  this->_finishedLevelFunc(input);
}

void AchievementAchievedRewardable::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementAchievedRewardable(tree);
}

void AchievementAchievedRewardable::deserializeAsyncAs_AchievementAchievedRewardable(FuncTree tree)
{
  AchievementAchieved::deserializeAsync(tree);
  tree.addChild(std::bind(&AchievementAchievedRewardable::_finishedLevelFunc, this, std::placeholders::_1));
}

void AchievementAchievedRewardable::_finishedLevelFunc(Reader *input)
{
  this->finishedLevel = input->readVarUhShort();
  if(this->finishedLevel < 0 || this->finishedLevel > 200)
  {
    qDebug()<<"ERREUR - AchievementAchievedRewardable -"<<"Forbidden value (" << this->finishedLevel << ") on element of AchievementAchievedRewardable.finishedLevel.";
  }
}

AchievementAchievedRewardable::AchievementAchievedRewardable()
{
  m_types<<ClassEnum::ACHIEVEMENTACHIEVEDREWARDABLE;
}

bool AchievementAchievedRewardable::operator==(const AchievementAchievedRewardable &compared)
{
  if(finishedLevel == compared.finishedLevel)
  return true;
  
  return false;
}

