#include "FightTeamMemberInformations.h"

void FightTeamMemberInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberInformations(output);
}

void FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(Writer *output)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
}

void FightTeamMemberInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberInformations(input);
}

void FightTeamMemberInformations::deserializeAs_FightTeamMemberInformations(Reader *input)
{
  this->_idFunc(input);
}

void FightTeamMemberInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberInformations(tree);
}

void FightTeamMemberInformations::deserializeAsyncAs_FightTeamMemberInformations(FuncTree tree)
{
  tree.addChild(std::bind(&FightTeamMemberInformations::_idFunc, this, std::placeholders::_1));
}

void FightTeamMemberInformations::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberInformations -"<<"Forbidden value (" << this->id << ") on element of FightTeamMemberInformations.id.";
  }
}

FightTeamMemberInformations::FightTeamMemberInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERINFORMATIONS;
}

bool FightTeamMemberInformations::operator==(const FightTeamMemberInformations &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

