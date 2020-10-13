#include "FightTeamMemberCharacterInformations.h"

void FightTeamMemberCharacterInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberCharacterInformations(output);
}

void FightTeamMemberCharacterInformations::serializeAs_FightTeamMemberCharacterInformations(Writer *output)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(output);
  output->writeUTF(this->name);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberCharacterInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
}

void FightTeamMemberCharacterInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberCharacterInformations(input);
}

void FightTeamMemberCharacterInformations::deserializeAs_FightTeamMemberCharacterInformations(Reader *input)
{
  FightTeamMemberInformations::deserialize(input);
  this->_nameFunc(input);
  this->_levelFunc(input);
}

void FightTeamMemberCharacterInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberCharacterInformations(tree);
}

void FightTeamMemberCharacterInformations::deserializeAsyncAs_FightTeamMemberCharacterInformations(FuncTree tree)
{
  FightTeamMemberInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTeamMemberCharacterInformations::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberCharacterInformations::_levelFunc, this, std::placeholders::_1));
}

void FightTeamMemberCharacterInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void FightTeamMemberCharacterInformations::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberCharacterInformations -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberCharacterInformations.level.";
  }
}

FightTeamMemberCharacterInformations::FightTeamMemberCharacterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERCHARACTERINFORMATIONS;
}

bool FightTeamMemberCharacterInformations::operator==(const FightTeamMemberCharacterInformations &compared)
{
  if(name == compared.name)
  if(level == compared.level)
  return true;
  
  return false;
}

