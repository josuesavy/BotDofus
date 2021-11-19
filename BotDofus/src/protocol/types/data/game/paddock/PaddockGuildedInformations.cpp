#include "PaddockGuildedInformations.h"

void PaddockGuildedInformations::serialize(Writer *output)
{
  this->serializeAs_PaddockGuildedInformations(output);
}

void PaddockGuildedInformations::serializeAs_PaddockGuildedInformations(Writer *output)
{
  PaddockBuyableInformations::serializeAs_PaddockBuyableInformations(output);
  output->writeBool(this->deserted);
  this->guildInfo->serializeAs_GuildInformations(output);
}

void PaddockGuildedInformations::deserialize(Reader *input)
{
  this->deserializeAs_PaddockGuildedInformations(input);
}

void PaddockGuildedInformations::deserializeAs_PaddockGuildedInformations(Reader *input)
{
  PaddockBuyableInformations::deserialize(input);
  this->_desertedFunc(input);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(input);
}

void PaddockGuildedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockGuildedInformations(tree);
}

void PaddockGuildedInformations::deserializeAsyncAs_PaddockGuildedInformations(FuncTree tree)
{
  PaddockBuyableInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&PaddockGuildedInformations::_desertedFunc, this, std::placeholders::_1));
  this->_guildInfotree = tree.addChild(std::bind(&PaddockGuildedInformations::_guildInfotreeFunc, this, std::placeholders::_1));
}

void PaddockGuildedInformations::_desertedFunc(Reader *input)
{
  this->deserted = input->readBool();
}

void PaddockGuildedInformations::_guildInfotreeFunc(Reader *input)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserializeAsync(this->_guildInfotree);
}

PaddockGuildedInformations::PaddockGuildedInformations()
{
  m_types<<ClassEnum::PADDOCKGUILDEDINFORMATIONS;
}

bool PaddockGuildedInformations::operator==(const PaddockGuildedInformations &compared)
{
  if(deserted == compared.deserted)
  if(guildInfo == compared.guildInfo)
  if(_guildInfotree == compared._guildInfotree)
  return true;
  
  return false;
}

