#include "GuildLogbookEntryBasicInformation.h"

void GuildLogbookEntryBasicInformation::serialize(Writer *output)
{
  this->serializeAs_GuildLogbookEntryBasicInformation(output);
}

void GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookEntryBasicInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  if(this->date < 0 || this->date > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildLogbookEntryBasicInformation -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  output->writeDouble(this->date);
}

void GuildLogbookEntryBasicInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildLogbookEntryBasicInformation(input);
}

void GuildLogbookEntryBasicInformation::deserializeAs_GuildLogbookEntryBasicInformation(Reader *input)
{
  this->_idFunc(input);
  this->_dateFunc(input);
}

void GuildLogbookEntryBasicInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildLogbookEntryBasicInformation(tree);
}

void GuildLogbookEntryBasicInformation::deserializeAsyncAs_GuildLogbookEntryBasicInformation(FuncTree tree)
{
  tree.addChild(std::bind(&GuildLogbookEntryBasicInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildLogbookEntryBasicInformation::_dateFunc, this, std::placeholders::_1));
}

void GuildLogbookEntryBasicInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GuildLogbookEntryBasicInformation -"<<"Forbidden value (" << this->id << ") on element of GuildLogbookEntryBasicInformation.id.";
  }
}

void GuildLogbookEntryBasicInformation::_dateFunc(Reader *input)
{
  this->date = input->readDouble();
  if(this->date < 0 || this->date > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildLogbookEntryBasicInformation -"<<"Forbidden value (" << this->date << ") on element of GuildLogbookEntryBasicInformation.date.";
  }
}

GuildLogbookEntryBasicInformation::GuildLogbookEntryBasicInformation()
{
  m_types<<ClassEnum::GUILDLOGBOOKENTRYBASICINFORMATION;
}

bool GuildLogbookEntryBasicInformation::operator==(const GuildLogbookEntryBasicInformation &compared)
{
  if(id == compared.id)
  if(date == compared.date)
  return true;
  
  return false;
}

