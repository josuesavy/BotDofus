#include "GuildLevelUpActivity.h"

void GuildLevelUpActivity::serialize(Writer *output)
{
  this->serializeAs_GuildLevelUpActivity(output);
}

void GuildLevelUpActivity::serializeAs_GuildLevelUpActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  if(this->newGuildLevel < 0 || this->newGuildLevel > 255)
  {
    qDebug()<<"ERREUR - GuildLevelUpActivity -"<<"Forbidden value (" << this->newGuildLevel << ") on element newGuildLevel.";
  }
  output->writeByte(this->newGuildLevel);
}

void GuildLevelUpActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildLevelUpActivity(input);
}

void GuildLevelUpActivity::deserializeAs_GuildLevelUpActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->_newGuildLevelFunc(input);
}

void GuildLevelUpActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildLevelUpActivity(tree);
}

void GuildLevelUpActivity::deserializeAsyncAs_GuildLevelUpActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildLevelUpActivity::_newGuildLevelFunc, this, std::placeholders::_1));
}

void GuildLevelUpActivity::_newGuildLevelFunc(Reader *input)
{
  this->newGuildLevel = input->readUByte();
  if(this->newGuildLevel < 0 || this->newGuildLevel > 255)
  {
    qDebug()<<"ERREUR - GuildLevelUpActivity -"<<"Forbidden value (" << this->newGuildLevel << ") on element of GuildLevelUpActivity.newGuildLevel.";
  }
}

GuildLevelUpActivity::GuildLevelUpActivity()
{
  m_types<<ClassEnum::GUILDLEVELUPACTIVITY;
}

bool GuildLevelUpActivity::operator==(const GuildLevelUpActivity &compared)
{
  if(newGuildLevel == compared.newGuildLevel)
  return true;
  
  return false;
}

