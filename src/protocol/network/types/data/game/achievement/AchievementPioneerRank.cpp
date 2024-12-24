#include "AchievementPioneerRank.h"

void AchievementPioneerRank::serialize(Writer *output)
{
  this->serializeAs_AchievementPioneerRank(output);
}

void AchievementPioneerRank::serializeAs_AchievementPioneerRank(Writer *output)
{
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementPioneerRank -"<<"Forbidden value (" << this->achievementId << ") on element achievementId.";
  }
  output->writeVarInt((int)this->achievementId);
  if(this->pioneerRank < 0)
  {
    qDebug()<<"ERREUR - AchievementPioneerRank -"<<"Forbidden value (" << this->pioneerRank << ") on element pioneerRank.";
  }
  output->writeVarInt((int)this->pioneerRank);
}

void AchievementPioneerRank::deserialize(Reader *input)
{
  this->deserializeAs_AchievementPioneerRank(input);
}

void AchievementPioneerRank::deserializeAs_AchievementPioneerRank(Reader *input)
{
  this->_achievementIdFunc(input);
  this->_pioneerRankFunc(input);
}

void AchievementPioneerRank::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementPioneerRank(tree);
}

void AchievementPioneerRank::deserializeAsyncAs_AchievementPioneerRank(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementPioneerRank::_achievementIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AchievementPioneerRank::_pioneerRankFunc, this, std::placeholders::_1));
}

void AchievementPioneerRank::_achievementIdFunc(Reader *input)
{
  this->achievementId = input->readVarUhInt();
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementPioneerRank -"<<"Forbidden value (" << this->achievementId << ") on element of AchievementPioneerRank.achievementId.";
  }
}

void AchievementPioneerRank::_pioneerRankFunc(Reader *input)
{
  this->pioneerRank = input->readVarUhInt();
  if(this->pioneerRank < 0)
  {
    qDebug()<<"ERREUR - AchievementPioneerRank -"<<"Forbidden value (" << this->pioneerRank << ") on element of AchievementPioneerRank.pioneerRank.";
  }
}

AchievementPioneerRank::AchievementPioneerRank()
{
  m_types<<ClassEnum::ACHIEVEMENTPIONEERRANK;
}

bool AchievementPioneerRank::operator==(const AchievementPioneerRank &compared)
{
  if(achievementId == compared.achievementId)
  if(pioneerRank == compared.pioneerRank)
  return true;
  
  return false;
}

