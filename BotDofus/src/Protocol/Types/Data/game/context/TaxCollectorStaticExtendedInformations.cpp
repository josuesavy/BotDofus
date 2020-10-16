#include "TaxCollectorStaticExtendedInformations.h"

void TaxCollectorStaticExtendedInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorStaticExtendedInformations(output);
}

void TaxCollectorStaticExtendedInformations::serializeAs_TaxCollectorStaticExtendedInformations(Writer *output)
{
  TaxCollectorStaticInformations::serializeAs_TaxCollectorStaticInformations(output);
  this->allianceIdentity->serializeAs_AllianceInformations(output);
}

void TaxCollectorStaticExtendedInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorStaticExtendedInformations(input);
}

void TaxCollectorStaticExtendedInformations::deserializeAs_TaxCollectorStaticExtendedInformations(Reader *input)
{
  TaxCollectorStaticInformations::deserialize(input);
  this->allianceIdentity = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceIdentity->deserialize(input);
}

void TaxCollectorStaticExtendedInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorStaticExtendedInformations(tree);
}

void TaxCollectorStaticExtendedInformations::deserializeAsyncAs_TaxCollectorStaticExtendedInformations(FuncTree tree)
{
  TaxCollectorStaticInformations::deserializeAsync(tree);
  this->_allianceIdentitytree = tree.addChild(std::bind(&TaxCollectorStaticExtendedInformations::_allianceIdentitytreeFunc, this, std::placeholders::_1));
}

void TaxCollectorStaticExtendedInformations::_allianceIdentitytreeFunc(Reader *input)
{
  this->allianceIdentity = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceIdentity->deserializeAsync(this->_allianceIdentitytree);
}

TaxCollectorStaticExtendedInformations::TaxCollectorStaticExtendedInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORSTATICEXTENDEDINFORMATIONS;
}

bool TaxCollectorStaticExtendedInformations::operator==(const TaxCollectorStaticExtendedInformations &compared)
{
  if(allianceIdentity == compared.allianceIdentity)
  if(_allianceIdentitytree == compared._allianceIdentitytree)
  return true;
  
  return false;
}

