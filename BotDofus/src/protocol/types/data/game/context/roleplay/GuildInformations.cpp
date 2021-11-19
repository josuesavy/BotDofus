#include "GuildInformations.h"

void GuildInformations::serialize(Writer *output)
{
  this->serializeAs_GuildInformations(output);
}

void GuildInformations::serializeAs_GuildInformations(Writer *output)
{
  BasicGuildInformations::serializeAs_BasicGuildInformations(output);
  this->guildEmblem.serializeAs_GuildEmblem(output);
}

void GuildInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildInformations(input);
}

void GuildInformations::deserializeAs_GuildInformations(Reader *input)
{
  BasicGuildInformations::deserialize(input);
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserialize(input);
}

void GuildInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInformations(tree);
}

void GuildInformations::deserializeAsyncAs_GuildInformations(FuncTree tree)
{
  BasicGuildInformations::deserializeAsync(tree);
  this->_guildEmblemtree = tree.addChild(std::bind(&GuildInformations::_guildEmblemtreeFunc, this, std::placeholders::_1));
}

void GuildInformations::_guildEmblemtreeFunc(Reader *input)
{
  this->guildEmblem = GuildEmblem();
  this->guildEmblem.deserializeAsync(this->_guildEmblemtree);
}

GuildInformations::GuildInformations()
{
  m_types<<ClassEnum::GUILDINFORMATIONS;
}

bool GuildInformations::operator==(const GuildInformations &compared)
{
  if(guildEmblem == compared.guildEmblem)
  if(_guildEmblemtree == compared._guildEmblemtree)
  return true;
  
  return false;
}

