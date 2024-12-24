#include "AchievementAchieved.h"

void AchievementAchieved::serialize(Writer *output)
{
  this->serializeAs_AchievementAchieved(output);
}

void AchievementAchieved::serializeAs_AchievementAchieved(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarShort((int)this->id);
  if(this->achievedBy < 0 || this->achievedBy > 9007199254740992)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->achievedBy << ") on element achievedBy.";
  }
  output->writeVarLong((double)this->achievedBy);
  if(this->achievedPioneerRank < 0)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->achievedPioneerRank << ") on element achievedPioneerRank.";
  }
  output->writeVarInt((int)this->achievedPioneerRank);
}

void AchievementAchieved::deserialize(Reader *input)
{
  this->deserializeAs_AchievementAchieved(input);
}

void AchievementAchieved::deserializeAs_AchievementAchieved(Reader *input)
{
  this->_idFunc(input);
  this->_achievedByFunc(input);
  this->_achievedPioneerRankFunc(input);
}

void AchievementAchieved::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementAchieved(tree);
}

void AchievementAchieved::deserializeAsyncAs_AchievementAchieved(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementAchieved::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AchievementAchieved::_achievedByFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AchievementAchieved::_achievedPioneerRankFunc, this, std::placeholders::_1));
}

void AchievementAchieved::_idFunc(Reader *input)
{
  this->id = input->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->id << ") on element of AchievementAchieved.id.";
  }
}

void AchievementAchieved::_achievedByFunc(Reader *input)
{
  this->achievedBy = input->readVarUhLong();
  if(this->achievedBy < 0 || this->achievedBy > 9007199254740992)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->achievedBy << ") on element of AchievementAchieved.achievedBy.";
  }
}

void AchievementAchieved::_achievedPioneerRankFunc(Reader *input)
{
  this->achievedPioneerRank = input->readVarUhInt();
  if(this->achievedPioneerRank < 0)
  {
    qDebug()<<"ERREUR - AchievementAchieved -"<<"Forbidden value (" << this->achievedPioneerRank << ") on element of AchievementAchieved.achievedPioneerRank.";
  }
}

AchievementAchieved::AchievementAchieved()
{
  m_types<<ClassEnum::ACHIEVEMENTACHIEVED;
}

bool AchievementAchieved::operator==(const AchievementAchieved &compared)
{
  if(id == compared.id)
  if(achievedBy == compared.achievedBy)
  if(achievedPioneerRank == compared.achievedPioneerRank)
  return true;
  
  return false;
}

