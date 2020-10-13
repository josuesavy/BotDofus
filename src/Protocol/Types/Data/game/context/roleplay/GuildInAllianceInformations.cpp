#include "GuildInAllianceInformations.h"

void GuildInAllianceInformations::serialize(Writer *output)
{
  this->serializeAs_GuildInAllianceInformations(output);
}

void GuildInAllianceInformations::serializeAs_GuildInAllianceInformations(Writer *output)
{
  GuildInformations::serializeAs_GuildInformations(output);
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeByte(this->nbMembers);
  if(this->joinDate < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->joinDate << ") on element joinDate.";
  }
  output->writeInt((int)this->joinDate);
}

void GuildInAllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildInAllianceInformations(input);
}

void GuildInAllianceInformations::deserializeAs_GuildInAllianceInformations(Reader *input)
{
  GuildInformations::deserialize(input);
  this->_nbMembersFunc(input);
  this->_joinDateFunc(input);
}

void GuildInAllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInAllianceInformations(tree);
}

void GuildInAllianceInformations::deserializeAsyncAs_GuildInAllianceInformations(FuncTree tree)
{
  GuildInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildInAllianceInformations::_nbMembersFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildInAllianceInformations::_joinDateFunc, this, std::placeholders::_1));
}

void GuildInAllianceInformations::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readUByte();
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildInAllianceInformations.nbMembers.";
  }
}

void GuildInAllianceInformations::_joinDateFunc(Reader *input)
{
  this->joinDate = input->readInt();
  if(this->joinDate < 0)
  {
    qDebug()<<"ERREUR - GuildInAllianceInformations -"<<"Forbidden value (" << this->joinDate << ") on element of GuildInAllianceInformations.joinDate.";
  }
}

GuildInAllianceInformations::GuildInAllianceInformations()
{
  m_types<<ClassEnum::GUILDINALLIANCEINFORMATIONS;
}

bool GuildInAllianceInformations::operator==(const GuildInAllianceInformations &compared)
{
  if(nbMembers == compared.nbMembers)
  if(joinDate == compared.joinDate)
  return true;
  
  return false;
}

