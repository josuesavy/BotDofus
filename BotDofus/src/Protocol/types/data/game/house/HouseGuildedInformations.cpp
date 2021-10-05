#include "HouseGuildedInformations.h"

void HouseGuildedInformations::serialize(Writer *output)
{
  this->serializeAs_HouseGuildedInformations(output);
}

void HouseGuildedInformations::serializeAs_HouseGuildedInformations(Writer *output)
{
  HouseInstanceInformations::serializeAs_HouseInstanceInformations(output);
  this->guildInfo->serializeAs_GuildInformations(output);
}

void HouseGuildedInformations::deserialize(Reader *input)
{
  this->deserializeAs_HouseGuildedInformations(input);
}

void HouseGuildedInformations::deserializeAs_HouseGuildedInformations(Reader *input)
{
  HouseInstanceInformations::deserialize(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
}

void HouseGuildedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseGuildedInformations(tree);
}

void HouseGuildedInformations::deserializeAsyncAs_HouseGuildedInformations(FuncTree tree)
{
  HouseInstanceInformations::deserializeAsync(tree);
  this->_guildInfotree = tree.addChild(std::bind(&HouseGuildedInformations::_guildInfotreeFunc, this, std::placeholders::_1));
}

void HouseGuildedInformations::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

HouseGuildedInformations::HouseGuildedInformations()
{
  m_types<<ClassEnum::HOUSEGUILDEDINFORMATIONS;
}

bool HouseGuildedInformations::operator==(const HouseGuildedInformations &compared)
{
  if(guildInfo == compared.guildInfo)
  if(_guildInfotree == compared._guildInfotree)
  return true;
  
  return false;
}

