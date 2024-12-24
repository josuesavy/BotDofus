#include "AllianceInformation.h"

void AllianceInformation::serialize(Writer *output)
{
  this->serializeAs_AllianceInformation(output);
}

void AllianceInformation::serializeAs_AllianceInformation(Writer *output)
{
  BasicNamedAllianceInformations::serializeAs_BasicNamedAllianceInformations(output);
  this->allianceEmblem.serializeAs_SocialEmblem(output);
}

void AllianceInformation::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInformation(input);
}

void AllianceInformation::deserializeAs_AllianceInformation(Reader *input)
{
  BasicNamedAllianceInformations::deserialize(input);
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserialize(input);
}

void AllianceInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInformation(tree);
}

void AllianceInformation::deserializeAsyncAs_AllianceInformation(FuncTree tree)
{
  BasicNamedAllianceInformations::deserializeAsync(tree);
  this->_allianceEmblemtree = tree.addChild(std::bind(&AllianceInformation::_allianceEmblemtreeFunc, this, std::placeholders::_1));
}

void AllianceInformation::_allianceEmblemtreeFunc(Reader *input)
{
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserializeAsync(this->_allianceEmblemtree);
}

AllianceInformation::AllianceInformation()
{
  m_types<<ClassEnum::ALLIANCEINFORMATION;
}

bool AllianceInformation::operator==(const AllianceInformation &compared)
{
  if(allianceEmblem == compared.allianceEmblem)
  if(_allianceEmblemtree == compared._allianceEmblemtree)
  return true;
  
  return false;
}

