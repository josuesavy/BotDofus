#include "GuildFactSheetInformations.h"

void GuildFactSheetInformations::serialize(Writer *output)
{
  this->serializeAs_GuildFactSheetInformations(output);
}

void GuildFactSheetInformations::serializeAs_GuildFactSheetInformations(Writer *output)
{
  GuildInformations::serializeAs_GuildInformations(output);
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  output->writeVarLong((double)this->leaderId);
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeVarShort((int)this->nbMembers);
  if(this->lastActivityDay < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->lastActivityDay << ") on element lastActivityDay.";
  }
  output->writeShort((short)this->lastActivityDay);
  this->recruitment.serializeAs_GuildRecruitmentInformation(output);
  if(this->nbPendingApply < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbPendingApply << ") on element nbPendingApply.";
  }
  output->writeInt((int)this->nbPendingApply);
}

void GuildFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildFactSheetInformations(input);
}

void GuildFactSheetInformations::deserializeAs_GuildFactSheetInformations(Reader *input)
{
  GuildInformations::deserialize(input);
  this->_leaderIdFunc(input);
  this->_nbMembersFunc(input);
  this->_lastActivityDayFunc(input);
  this->recruitment = GuildRecruitmentInformation();
  this->recruitment.deserialize(input);
  this->_nbPendingApplyFunc(input);
}

void GuildFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFactSheetInformations(tree);
}

void GuildFactSheetInformations::deserializeAsyncAs_GuildFactSheetInformations(FuncTree tree)
{
  GuildInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildFactSheetInformations::_leaderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFactSheetInformations::_nbMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFactSheetInformations::_lastActivityDayFunc, this, std::placeholders::_1));
  this->_recruitmenttree = tree.addChild(std::bind(&GuildFactSheetInformations::_recruitmenttreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildFactSheetInformations::_nbPendingApplyFunc, this, std::placeholders::_1));
}

void GuildFactSheetInformations::_leaderIdFunc(Reader *input)
{
  this->leaderId = input->readVarUhLong();
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->leaderId << ") on element of GuildFactSheetInformations.leaderId.";
  }
}

void GuildFactSheetInformations::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readVarUhShort();
  if(this->nbMembers < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildFactSheetInformations.nbMembers.";
  }
}

void GuildFactSheetInformations::_lastActivityDayFunc(Reader *input)
{
  this->lastActivityDay = input->readShort();
  if(this->lastActivityDay < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->lastActivityDay << ") on element of GuildFactSheetInformations.lastActivityDay.";
  }
}

void GuildFactSheetInformations::_recruitmenttreeFunc(Reader *input)
{
  this->recruitment = GuildRecruitmentInformation();
  this->recruitment.deserializeAsync(this->_recruitmenttree);
}

void GuildFactSheetInformations::_nbPendingApplyFunc(Reader *input)
{
  this->nbPendingApply = input->readInt();
  if(this->nbPendingApply < 0)
  {
    qDebug()<<"ERREUR - GuildFactSheetInformations -"<<"Forbidden value (" << this->nbPendingApply << ") on element of GuildFactSheetInformations.nbPendingApply.";
  }
}

GuildFactSheetInformations::GuildFactSheetInformations()
{
  m_types<<ClassEnum::GUILDFACTSHEETINFORMATIONS;
}

bool GuildFactSheetInformations::operator==(const GuildFactSheetInformations &compared)
{
  if(leaderId == compared.leaderId)
  if(nbMembers == compared.nbMembers)
  if(lastActivityDay == compared.lastActivityDay)
  if(recruitment == compared.recruitment)
  if(nbPendingApply == compared.nbPendingApply)
  if(_recruitmenttree == compared._recruitmenttree)
  return true;
  
  return false;
}

