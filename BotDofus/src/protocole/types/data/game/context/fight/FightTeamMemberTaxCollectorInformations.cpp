#include "FightTeamMemberTaxCollectorInformations.h"

void FightTeamMemberTaxCollectorInformations::serialize(Writer *output)
{
  this->serializeAs_FightTeamMemberTaxCollectorInformations(output);
}

void FightTeamMemberTaxCollectorInformations::serializeAs_FightTeamMemberTaxCollectorInformations(Writer *output)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(output);
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  if(this->uid < 0 || this->uid > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  output->writeDouble(this->uid);
}

void FightTeamMemberTaxCollectorInformations::deserialize(Reader *input)
{
  this->deserializeAs_FightTeamMemberTaxCollectorInformations(input);
}

void FightTeamMemberTaxCollectorInformations::deserializeAs_FightTeamMemberTaxCollectorInformations(Reader *input)
{
  FightTeamMemberInformations::deserialize(input);
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->_levelFunc(input);
  this->_guildIdFunc(input);
  this->_uidFunc(input);
}

void FightTeamMemberTaxCollectorInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightTeamMemberTaxCollectorInformations(tree);
}

void FightTeamMemberTaxCollectorInformations::deserializeAsyncAs_FightTeamMemberTaxCollectorInformations(FuncTree tree)
{
  FightTeamMemberInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&FightTeamMemberTaxCollectorInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberTaxCollectorInformations::_lastNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberTaxCollectorInformations::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberTaxCollectorInformations::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightTeamMemberTaxCollectorInformations::_uidFunc, this, std::placeholders::_1));
}

void FightTeamMemberTaxCollectorInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of FightTeamMemberTaxCollectorInformations.firstNameId.";
  }
}

void FightTeamMemberTaxCollectorInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of FightTeamMemberTaxCollectorInformations.lastNameId.";
  }
}

void FightTeamMemberTaxCollectorInformations::_levelFunc(Reader *input)
{
  this->level = input->readUByte();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberTaxCollectorInformations.level.";
  }
}

void FightTeamMemberTaxCollectorInformations::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->guildId << ") on element of FightTeamMemberTaxCollectorInformations.guildId.";
  }
}

void FightTeamMemberTaxCollectorInformations::_uidFunc(Reader *input)
{
  this->uid = input->readDouble();
  if(this->uid < 0 || this->uid > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberTaxCollectorInformations -"<<"Forbidden value (" << this->uid << ") on element of FightTeamMemberTaxCollectorInformations.uid.";
  }
}

FightTeamMemberTaxCollectorInformations::FightTeamMemberTaxCollectorInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS;
}

bool FightTeamMemberTaxCollectorInformations::operator==(const FightTeamMemberTaxCollectorInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(level == compared.level)
  if(guildId == compared.guildId)
  if(uid == compared.uid)
  return true;
  
  return false;
}

