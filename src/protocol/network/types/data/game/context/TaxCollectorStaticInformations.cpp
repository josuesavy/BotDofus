#include "TaxCollectorStaticInformations.h"

void TaxCollectorStaticInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorStaticInformations(output);
}

void TaxCollectorStaticInformations::serializeAs_TaxCollectorStaticInformations(Writer *output)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  this->allianceIdentity->serializeAs_AllianceInformation(output);
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
  }
  output->writeVarLong((double)this->callerId);
  output->writeUTF(this->uid);
}

void TaxCollectorStaticInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorStaticInformations(input);
}

void TaxCollectorStaticInformations::deserializeAs_TaxCollectorStaticInformations(Reader *input)
{
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->allianceIdentity = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceIdentity->deserialize(input);
  this->_callerIdFunc(input);
  this->_uidFunc(input);
}

void TaxCollectorStaticInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorStaticInformations(tree);
}

void TaxCollectorStaticInformations::deserializeAsyncAs_TaxCollectorStaticInformations(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_lastNameIdFunc, this, std::placeholders::_1));
  this->_allianceIdentitytree = tree.addChild(std::bind(&TaxCollectorStaticInformations::_allianceIdentitytreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_callerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_uidFunc, this, std::placeholders::_1));
}

void TaxCollectorStaticInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorStaticInformations.firstNameId.";
  }
}

void TaxCollectorStaticInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorStaticInformations.lastNameId.";
  }
}

void TaxCollectorStaticInformations::_allianceIdentitytreeFunc(Reader *input)
{
  this->allianceIdentity = QSharedPointer<AllianceInformation>(new AllianceInformation() );
  this->allianceIdentity->deserializeAsync(this->_allianceIdentitytree);
}

void TaxCollectorStaticInformations::_callerIdFunc(Reader *input)
{
  this->callerId = input->readVarUhLong();
  if(this->callerId < 0 || this->callerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->callerId << ") on element of TaxCollectorStaticInformations.callerId.";
  }
}

void TaxCollectorStaticInformations::_uidFunc(Reader *input)
{
  this->uid = input->readUTF();
}

TaxCollectorStaticInformations::TaxCollectorStaticInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORSTATICINFORMATIONS;
}

bool TaxCollectorStaticInformations::operator==(const TaxCollectorStaticInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(allianceIdentity == compared.allianceIdentity)
  if(callerId == compared.callerId)
  if(uid == compared.uid)
  if(_allianceIdentitytree == compared._allianceIdentitytree)
  return true;
  
  return false;
}

