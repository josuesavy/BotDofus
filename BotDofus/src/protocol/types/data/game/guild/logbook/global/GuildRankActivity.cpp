#include "GuildRankActivity.h"

void GuildRankActivity::serialize(Writer *output)
{
  this->serializeAs_GuildRankActivity(output);
}

void GuildRankActivity::serializeAs_GuildRankActivity(Writer *output)
{
  GuildLogbookEntryBasicInformation::serializeAs_GuildLogbookEntryBasicInformation(output);
  output->writeByte(this->rankActivityType);
  this->guildRankMinimalInfos.serializeAs_GuildRankMinimalInformation(output);
}

void GuildRankActivity::deserialize(Reader *input)
{
  this->deserializeAs_GuildRankActivity(input);
}

void GuildRankActivity::deserializeAs_GuildRankActivity(Reader *input)
{
  GuildLogbookEntryBasicInformation::deserialize(input);
  this->_rankActivityTypeFunc(input);
  this->guildRankMinimalInfos = GuildRankMinimalInformation();
  this->guildRankMinimalInfos.deserialize(input);
}

void GuildRankActivity::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRankActivity(tree);
}

void GuildRankActivity::deserializeAsyncAs_GuildRankActivity(FuncTree tree)
{
  GuildLogbookEntryBasicInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildRankActivity::_rankActivityTypeFunc, this, std::placeholders::_1));
  this->_guildRankMinimalInfostree = tree.addChild(std::bind(&GuildRankActivity::_guildRankMinimalInfostreeFunc, this, std::placeholders::_1));
}

void GuildRankActivity::_rankActivityTypeFunc(Reader *input)
{
  this->rankActivityType = input->readByte();
  if(this->rankActivityType < 0)
  {
    qDebug()<<"ERREUR - GuildRankActivity -"<<"Forbidden value (" << this->rankActivityType << ") on element of GuildRankActivity.rankActivityType.";
  }
}

void GuildRankActivity::_guildRankMinimalInfostreeFunc(Reader *input)
{
  this->guildRankMinimalInfos = GuildRankMinimalInformation();
  this->guildRankMinimalInfos.deserializeAsync(this->_guildRankMinimalInfostree);
}

GuildRankActivity::GuildRankActivity()
{
  m_types<<ClassEnum::GUILDRANKACTIVITY;
}

bool GuildRankActivity::operator==(const GuildRankActivity &compared)
{
  if(rankActivityType == compared.rankActivityType)
  if(guildRankMinimalInfos == compared.guildRankMinimalInfos)
  if(_guildRankMinimalInfostree == compared._guildRankMinimalInfostree)
  return true;
  
  return false;
}

