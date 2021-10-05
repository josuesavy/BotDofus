#include "FightResultTaxCollectorListEntry.h"

void FightResultTaxCollectorListEntry::serialize(Writer *output)
{
  this->serializeAs_FightResultTaxCollectorListEntry(output);
}

void FightResultTaxCollectorListEntry::serializeAs_FightResultTaxCollectorListEntry(Writer *output)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(output);
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightResultTaxCollectorListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeByte(this->level);
  this->guildInfo->serializeAs_BasicGuildInformations(output);
  output->writeInt((int)this->experienceForGuild);
}

void FightResultTaxCollectorListEntry::deserialize(Reader *input)
{
  this->deserializeAs_FightResultTaxCollectorListEntry(input);
}

void FightResultTaxCollectorListEntry::deserializeAs_FightResultTaxCollectorListEntry(Reader *input)
{
  FightResultFighterListEntry::deserialize(input);
  this->_levelFunc(input);
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserialize(input);
  this->_experienceForGuildFunc(input);
}

void FightResultTaxCollectorListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_FightResultTaxCollectorListEntry(tree);
}

void FightResultTaxCollectorListEntry::deserializeAsyncAs_FightResultTaxCollectorListEntry(FuncTree tree)
{
  FightResultFighterListEntry::deserializeAsync(tree);
  tree.addChild(std::bind(&FightResultTaxCollectorListEntry::_levelFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&FightResultTaxCollectorListEntry::_guildInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&FightResultTaxCollectorListEntry::_experienceForGuildFunc, this, std::placeholders::_1));
}

void FightResultTaxCollectorListEntry::_levelFunc(Reader *input)
{
  this->level = input->readUByte();
  if(this->level < 1 || this->level > 200)
  {
    qDebug()<<"ERREUR - FightResultTaxCollectorListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultTaxCollectorListEntry.level.";
  }
}

void FightResultTaxCollectorListEntry::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

void FightResultTaxCollectorListEntry::_experienceForGuildFunc(Reader *input)
{
  this->experienceForGuild = input->readInt();
}

FightResultTaxCollectorListEntry::FightResultTaxCollectorListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTTAXCOLLECTORLISTENTRY;
}

bool FightResultTaxCollectorListEntry::operator==(const FightResultTaxCollectorListEntry &compared)
{
  if(level == compared.level)
  if(guildInfo == compared.guildInfo)
  if(experienceForGuild == compared.experienceForGuild)
  if(_guildInfotree == compared._guildInfotree)
  return true;
  
  return false;
}

