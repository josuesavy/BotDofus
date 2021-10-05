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
  this->guildIdentity->serializeAs_GuildInformations(output);
  if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
  }
  output->writeVarLong((double)this->callerId);
}

void TaxCollectorStaticInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorStaticInformations(input);
}

void TaxCollectorStaticInformations::deserializeAs_TaxCollectorStaticInformations(Reader *input)
{
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->guildIdentity = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildIdentity->deserialize(input);
  this->_callerIdFunc(input);
}

void TaxCollectorStaticInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorStaticInformations(tree);
}

void TaxCollectorStaticInformations::deserializeAsyncAs_TaxCollectorStaticInformations(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_lastNameIdFunc, this, std::placeholders::_1));
  this->_guildIdentitytree = tree.addChild(std::bind(&TaxCollectorStaticInformations::_guildIdentitytreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorStaticInformations::_callerIdFunc, this, std::placeholders::_1));
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

void TaxCollectorStaticInformations::_guildIdentitytreeFunc(Reader *input)
{
  this->guildIdentity = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildIdentity->deserializeAsync(this->_guildIdentitytree);
}

void TaxCollectorStaticInformations::_callerIdFunc(Reader *input)
{
  this->callerId = input->readVarUhLong();
  if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->callerId << ") on element of TaxCollectorStaticInformations.callerId.";
  }
}

TaxCollectorStaticInformations::TaxCollectorStaticInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORSTATICINFORMATIONS;
}

bool TaxCollectorStaticInformations::operator==(const TaxCollectorStaticInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(guildIdentity == compared.guildIdentity)
  if(callerId == compared.callerId)
  if(_guildIdentitytree == compared._guildIdentitytree)
  return true;
  
  return false;
}

