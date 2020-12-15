#include "AlliancedGuildFactSheetInformations.h"

void AlliancedGuildFactSheetInformations::serialize(Writer *output)
{
  this->serializeAs_AlliancedGuildFactSheetInformations(output);
}

void AlliancedGuildFactSheetInformations::serializeAs_AlliancedGuildFactSheetInformations(Writer *output)
{
  GuildInformations::serializeAs_GuildInformations(output);
  this->allianceInfos->serializeAs_BasicNamedAllianceInformations(output);
}

void AlliancedGuildFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_AlliancedGuildFactSheetInformations(input);
}

void AlliancedGuildFactSheetInformations::deserializeAs_AlliancedGuildFactSheetInformations(Reader *input)
{
  GuildInformations::deserialize(input);
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserialize(input);
}

void AlliancedGuildFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlliancedGuildFactSheetInformations(tree);
}

void AlliancedGuildFactSheetInformations::deserializeAsyncAs_AlliancedGuildFactSheetInformations(FuncTree tree)
{
  GuildInformations::deserializeAsync(tree);
  this->_allianceInfostree = tree.addChild(std::bind(&AlliancedGuildFactSheetInformations::_allianceInfostreeFunc, this, std::placeholders::_1));
}

void AlliancedGuildFactSheetInformations::_allianceInfostreeFunc(Reader *input)
{
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserializeAsync(this->_allianceInfostree);
}

AlliancedGuildFactSheetInformations::AlliancedGuildFactSheetInformations()
{
  m_types<<ClassEnum::ALLIANCEDGUILDFACTSHEETINFORMATIONS;
}

bool AlliancedGuildFactSheetInformations::operator==(const AlliancedGuildFactSheetInformations &compared)
{
  if(allianceInfos == compared.allianceInfos)
  if(_allianceInfostree == compared._allianceInfostree)
  return true;
  
  return false;
}

