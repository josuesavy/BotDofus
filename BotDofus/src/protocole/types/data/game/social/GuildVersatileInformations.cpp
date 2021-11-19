#include "GuildVersatileInformations.h"

void GuildVersatileInformations::serialize(Writer *output)
{
  this->serializeAs_GuildVersatileInformations(output);
}

void GuildVersatileInformations::serializeAs_GuildVersatileInformations(Writer *output)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  output->writeVarInt((int)this->guildId);
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  output->writeVarLong((double)this->leaderId);
  if(this->guildLevel < 1 || this->guildLevel > 200)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildLevel << ") on element guildLevel.";
  }
  output->writeByte(this->guildLevel);
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element nbMembers.";
  }
  output->writeByte(this->nbMembers);
}

void GuildVersatileInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildVersatileInformations(input);
}

void GuildVersatileInformations::deserializeAs_GuildVersatileInformations(Reader *input)
{
  this->_guildIdFunc(input);
  this->_leaderIdFunc(input);
  this->_guildLevelFunc(input);
  this->_nbMembersFunc(input);
}

void GuildVersatileInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildVersatileInformations(tree);
}

void GuildVersatileInformations::deserializeAsyncAs_GuildVersatileInformations(FuncTree tree)
{
  tree.addChild(std::bind(&GuildVersatileInformations::_guildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildVersatileInformations::_leaderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildVersatileInformations::_guildLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildVersatileInformations::_nbMembersFunc, this, std::placeholders::_1));
}

void GuildVersatileInformations::_guildIdFunc(Reader *input)
{
  this->guildId = input->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildId << ") on element of GuildVersatileInformations.guildId.";
  }
}

void GuildVersatileInformations::_leaderIdFunc(Reader *input)
{
  this->leaderId = input->readVarUhLong();
  if(this->leaderId < 0 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->leaderId << ") on element of GuildVersatileInformations.leaderId.";
  }
}

void GuildVersatileInformations::_guildLevelFunc(Reader *input)
{
  this->guildLevel = input->readUByte();
  if(this->guildLevel < 1 || this->guildLevel > 200)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->guildLevel << ") on element of GuildVersatileInformations.guildLevel.";
  }
}

void GuildVersatileInformations::_nbMembersFunc(Reader *input)
{
  this->nbMembers = input->readUByte();
  if(this->nbMembers < 1 || this->nbMembers > 240)
  {
    qDebug()<<"ERREUR - GuildVersatileInformations -"<<"Forbidden value (" << this->nbMembers << ") on element of GuildVersatileInformations.nbMembers.";
  }
}

GuildVersatileInformations::GuildVersatileInformations()
{
  m_types<<ClassEnum::GUILDVERSATILEINFORMATIONS;
}

bool GuildVersatileInformations::operator==(const GuildVersatileInformations &compared)
{
  if(guildId == compared.guildId)
  if(leaderId == compared.leaderId)
  if(guildLevel == compared.guildLevel)
  if(nbMembers == compared.nbMembers)
  return true;
  
  return false;
}

