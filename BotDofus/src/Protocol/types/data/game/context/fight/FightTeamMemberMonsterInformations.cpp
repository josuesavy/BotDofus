#include "FightTeamMemberMonsterInformations.h"

void FightTeamMemberMonsterInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberMonsterInformations(output);
}

void FightTeamMemberMonsterInformations::serializeAs_FightTeamMemberMonsterInformations(Writer *output)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(output);
  output->writeInt((int)this->monsterId);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberMonsterInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  output->writeByte(this->grade);
}

void FightTeamMemberMonsterInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberMonsterInformations(input);
}

void FightTeamMemberMonsterInformations::deserializeAs_FightTeamMemberMonsterInformations(Reader *input)
{
  FightTeamMemberInformations::deserialize(input);
  this->_monsterIdFunc(input);
  this->_gradeFunc(input);
}

void FightTeamMemberMonsterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberMonsterInformations(tree);
}

void FightTeamMemberMonsterInformations::deserializeAsyncAs_FightTeamMemberMonsterInformations(FuncTree tree)
{
  FightTeamMemberInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTeamMemberMonsterInformations::_monsterIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberMonsterInformations::_gradeFunc, this, std::placeholders::_1));
}

void FightTeamMemberMonsterInformations::_monsterIdFunc(Reader *input)
{
  this->monsterId = input->readInt();
}

void FightTeamMemberMonsterInformations::_gradeFunc(Reader *input)
{
  this->grade = input->readByte();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberMonsterInformations -"<<"Forbidden value (" << this->grade << ") on element of FightTeamMemberMonsterInformations.grade.";
  }
}

FightTeamMemberMonsterInformations::FightTeamMemberMonsterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERMONSTERINFORMATIONS;
}

bool FightTeamMemberMonsterInformations::operator==(const FightTeamMemberMonsterInformations &compared)
{
  if(monsterId == compared.monsterId)
  if(grade == compared.grade)
  return true;
  
  return false;
}

