#include "AlliancePrismInformation.h"

void AlliancePrismInformation::serialize(Writer *output)
{
  this->serializeAs_AlliancePrismInformation(output);
}

void AlliancePrismInformation::serializeAs_AlliancePrismInformation(Writer *output)
{
  PrismInformation::serializeAs_PrismInformation(output);
  this->alliance->serializeAs_AllianceInformations(output);
}

void AlliancePrismInformation::deserialize(Reader *input)
{
  this->deserializeAs_AlliancePrismInformation(input);
}

void AlliancePrismInformation::deserializeAs_AlliancePrismInformation(Reader *input)
{
  PrismInformation::deserialize(input);
  this->alliance = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->alliance->deserialize(input);
}

void AlliancePrismInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlliancePrismInformation(tree);
}

void AlliancePrismInformation::deserializeAsyncAs_AlliancePrismInformation(FuncTree tree)
{
  PrismInformation::deserializeAsync(tree);
  this->_alliancetree = tree.addChild(std::bind(&AlliancePrismInformation::_alliancetreeFunc, this, std::placeholders::_1));
}

void AlliancePrismInformation::_alliancetreeFunc(Reader *input)
{
  this->alliance = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->alliance->deserializeAsync(this->_alliancetree);
}

AlliancePrismInformation::AlliancePrismInformation()
{
  m_types<<ClassEnum::ALLIANCEPRISMINFORMATION;
}

bool AlliancePrismInformation::operator==(const AlliancePrismInformation &compared)
{
  if(alliance == compared.alliance)
  if(_alliancetree == compared._alliancetree)
  return true;
  
  return false;
}

