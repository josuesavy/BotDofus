#include "AchievementStartedObjective.h"

void AchievementStartedObjective::serialize(Writer *output)
{
  this->serializeAs_AchievementStartedObjective(output);
}

void AchievementStartedObjective::serializeAs_AchievementStartedObjective(Writer *output)
{
  AchievementObjective::serializeAs_AchievementObjective(output);
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - AchievementStartedObjective -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  output->writeVarShort((int)this->value);
}

void AchievementStartedObjective::deserialize(Reader *input)
{
  this->deserializeAs_AchievementStartedObjective(input);
}

void AchievementStartedObjective::deserializeAs_AchievementStartedObjective(Reader *input)
{
  AchievementObjective::deserialize(input);
  this->_valueFunc(input);
}

void AchievementStartedObjective::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AchievementStartedObjective(tree);
}

void AchievementStartedObjective::deserializeAsyncAs_AchievementStartedObjective(FuncTree tree)
{
  AchievementObjective::deserializeAsync(tree);
  tree.addChild(std::bind(&AchievementStartedObjective::_valueFunc, this, std::placeholders::_1));
}

void AchievementStartedObjective::_valueFunc(Reader *input)
{
  this->value = input->readVarUhShort();
  if(this->value < 0)
  {
    qDebug()<<"ERREUR - AchievementStartedObjective -"<<"Forbidden value (" << this->value << ") on element of AchievementStartedObjective.value.";
  }
}

AchievementStartedObjective::AchievementStartedObjective()
{
  m_types<<ClassEnum::ACHIEVEMENTSTARTEDOBJECTIVE;
}

bool AchievementStartedObjective::operator==(const AchievementStartedObjective &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

