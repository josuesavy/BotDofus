#include "AchievementObjective.h"

void AchievementObjective::serialize(Writer *output)
{
  this->serializeAs_AchievementObjective(output);
}

void AchievementObjective::serializeAs_AchievementObjective(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  if(this->maxValue < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->maxValue << ") on element maxValue.";
  }
  output->writeVarShort((int)this->maxValue);
}

void AchievementObjective::deserialize(Reader *input)
{
  this->deserializeAs_AchievementObjective(input);
}

void AchievementObjective::deserializeAs_AchievementObjective(Reader *input)
{
  this->_idFunc(input);
  this->_maxValueFunc(input);
}

void AchievementObjective::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementObjective(tree);
}

void AchievementObjective::deserializeAsyncAs_AchievementObjective(FuncTree tree)
{
  tree.addChild(std::bind(&AchievementObjective::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AchievementObjective::_maxValueFunc, this, std::placeholders::_1));
}

void AchievementObjective::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->id << ") on element of AchievementObjective.id.";
  }
}

void AchievementObjective::_maxValueFunc(Reader *input)
{
  this->maxValue = input->readVarUhShort();
  if(this->maxValue < 0)
  {
    qDebug()<<"ERREUR - AchievementObjective -"<<"Forbidden value (" << this->maxValue << ") on element of AchievementObjective.maxValue.";
  }
}

AchievementObjective::AchievementObjective()
{
  m_types<<ClassEnum::ACHIEVEMENTOBJECTIVE;
}

bool AchievementObjective::operator==(const AchievementObjective &compared)
{
  if(id == compared.id)
  if(maxValue == compared.maxValue)
  return true;
  
  return false;
}

