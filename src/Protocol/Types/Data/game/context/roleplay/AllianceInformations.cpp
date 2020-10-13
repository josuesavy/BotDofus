#include "AllianceInformations.h"

void AllianceInformations::serialize(Writer *output)
{
  this->serializeAs_AllianceInformations(output);
}

void AllianceInformations::serializeAs_AllianceInformations(Writer *output)
{
  BasicNamedAllianceInformations::serializeAs_BasicNamedAllianceInformations(output);
  this->allianceEmblem.serializeAs_GuildEmblem(output);
}

void AllianceInformations::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInformations(input);
}

void AllianceInformations::deserializeAs_AllianceInformations(Reader *input)
{
  BasicNamedAllianceInformations::deserialize(input);
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserialize(input);
}

void AllianceInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInformations(tree);
}

void AllianceInformations::deserializeAsyncAs_AllianceInformations(FuncTree tree)
{
  BasicNamedAllianceInformations::deserializeAsync(tree);
  this->_allianceEmblemtree = tree.addChild(std::bind(&AllianceInformations::_allianceEmblemtreeFunc, this, std::placeholders::_1));
}

void AllianceInformations::_allianceEmblemtreeFunc(Reader *input)
{
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserializeAsync(this->_allianceEmblemtree);
}

AllianceInformations::AllianceInformations()
{
  m_types<<ClassEnum::ALLIANCEINFORMATIONS;
}

bool AllianceInformations::operator==(const AllianceInformations &compared)
{
  if(allianceEmblem == compared.allianceEmblem)
  if(_allianceEmblemtree == compared._allianceEmblemtree)
  return true;
  
  return false;
}

