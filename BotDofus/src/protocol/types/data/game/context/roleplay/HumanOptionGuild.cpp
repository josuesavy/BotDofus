#include "HumanOptionGuild.h"

void HumanOptionGuild::serialize(Writer *output)
{
  this->serializeAs_HumanOptionGuild(output);
}

void HumanOptionGuild::serializeAs_HumanOptionGuild(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  this->guildInformations->serializeAs_GuildInformations(output);
}

void HumanOptionGuild::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionGuild(input);
}

void HumanOptionGuild::deserializeAs_HumanOptionGuild(Reader *input)
{
  HumanOption::deserialize(input);
  this->guildInformations = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformations->deserialize(input);
}

void HumanOptionGuild::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionGuild(tree);
}

void HumanOptionGuild::deserializeAsyncAs_HumanOptionGuild(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  this->_guildInformationstree = tree.addChild(std::bind(&HumanOptionGuild::_guildInformationstreeFunc, this, std::placeholders::_1));
}

void HumanOptionGuild::_guildInformationstreeFunc(Reader *input)
{
  this->guildInformations = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInformations->deserializeAsync(this->_guildInformationstree);
}

HumanOptionGuild::HumanOptionGuild()
{
  m_types<<ClassEnum::HUMANOPTIONGUILD;
}

bool HumanOptionGuild::operator==(const HumanOptionGuild &compared)
{
  if(guildInformations == compared.guildInformations)
  if(_guildInformationstree == compared._guildInformationstree)
  return true;
  
  return false;
}

