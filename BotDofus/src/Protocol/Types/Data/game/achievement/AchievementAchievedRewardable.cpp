#include "AchievementAchievedRewardable.h"

void AchievementAchievedRewardable::serialize(Writer *output)
{
  this->serializeAs_AchievementAchievedRewardable(output);
}

void AchievementAchievedRewardable::serializeAs_AchievementAchievedRewardable(Writer *output)
{
  AchievementAchieved::serializeAs_AchievementAchieved(output);
  if(this->finishedlevel < 0 || this->finishedlevel > 200)
  {
    qDebug()<<"ERREUR - AchievementAchievedRewardable -"<<"Forbidden value (" << this->finishedlevel << ") on element finishedlevel.";
  }
  output->writeVarShort((int)this->finishedlevel);
}

void AchievementAchievedRewardable::deserialize(Reader *input)
{
  this->deserializeAs_AchievementAchievedRewardable(input);
}

void AchievementAchievedRewardable::deserializeAs_AchievementAchievedRewardable(Reader *input)
{
  AchievementAchieved::deserialize(input);
  this->_finishedlevelFunc(input);
}

void AchievementAchievedRewardable::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementAchievedRewardable(tree);
}

void AchievementAchievedRewardable::deserializeAsyncAs_AchievementAchievedRewardable(FuncTree tree)
{
  AchievementAchieved::deserializeAsync(tree);
  tree.addChild(std::bind(&AchievementAchievedRewardable::_finishedlevelFunc, this, std::placeholders::_1));
}

void AchievementAchievedRewardable::_finishedlevelFunc(Reader *input)
{
  this->finishedlevel = input->readVarUhShort();
  if(this->finishedlevel < 0 || this->finishedlevel > 200)
  {
    qDebug()<<"ERREUR - AchievementAchievedRewardable -"<<"Forbidden value (" << this->finishedlevel << ") on element of AchievementAchievedRewardable.finishedlevel.";
  }
}

AchievementAchievedRewardable::AchievementAchievedRewardable()
{
  m_types<<ClassEnum::ACHIEVEMENTACHIEVEDREWARDABLE;
}

bool AchievementAchievedRewardable::operator==(const AchievementAchievedRewardable &compared)
{
  if(finishedlevel == compared.finishedlevel)
  return true;
  
  return false;
}

