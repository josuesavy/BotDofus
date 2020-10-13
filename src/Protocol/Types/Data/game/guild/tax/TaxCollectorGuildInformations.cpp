#include "TaxCollectorGuildInformations.h"

void TaxCollectorGuildInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorGuildInformations(output);
}

void TaxCollectorGuildInformations::serializeAs_TaxCollectorGuildInformations(Writer *output)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(output);
  this->guild->serializeAs_BasicGuildInformations(output);
}

void TaxCollectorGuildInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorGuildInformations(input);
}

void TaxCollectorGuildInformations::deserializeAs_TaxCollectorGuildInformations(Reader *input)
{
  TaxCollectorComplementaryInformations::deserialize(input);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(input);
}

void TaxCollectorGuildInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorGuildInformations(tree);
}

void TaxCollectorGuildInformations::deserializeAsyncAs_TaxCollectorGuildInformations(FuncTree tree)
{
  TaxCollectorComplementaryInformations::deserializeAsync(tree);
  this->_guildtree = tree.addChild(std::bind(&TaxCollectorGuildInformations::_guildtreeFunc, this, std::placeholders::_1));
}

void TaxCollectorGuildInformations::_guildtreeFunc(Reader *input)
{
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserializeAsync(this->_guildtree);
}

TaxCollectorGuildInformations::TaxCollectorGuildInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORGUILDINFORMATIONS;
}

bool TaxCollectorGuildInformations::operator==(const TaxCollectorGuildInformations &compared)
{
  if(guild == compared.guild)
  if(_guildtree == compared._guildtree)
  return true;
  
  return false;
}

