#include "TaxCollectorBasicInformations.h"

void TaxCollectorBasicInformations::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorBasicInformations(output);
}

void TaxCollectorBasicInformations::serializeAs_TaxCollectorBasicInformations(Writer *output)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void TaxCollectorBasicInformations::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorBasicInformations(input);
}

void TaxCollectorBasicInformations::deserializeAs_TaxCollectorBasicInformations(Reader *input)
{
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
}

void TaxCollectorBasicInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorBasicInformations(tree);
}

void TaxCollectorBasicInformations::deserializeAsyncAs_TaxCollectorBasicInformations(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_lastNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorBasicInformations::_subAreaIdFunc, this, std::placeholders::_1));
}

void TaxCollectorBasicInformations::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorBasicInformations.firstNameId.";
  }
}

void TaxCollectorBasicInformations::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorBasicInformations.lastNameId.";
  }
}

void TaxCollectorBasicInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorBasicInformations.worldX.";
  }
}

void TaxCollectorBasicInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorBasicInformations.worldY.";
  }
}

void TaxCollectorBasicInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->mapId << ") on element of TaxCollectorBasicInformations.mapId.";
  }
}

void TaxCollectorBasicInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorBasicInformations.subAreaId.";
  }
}

TaxCollectorBasicInformations::TaxCollectorBasicInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORBASICINFORMATIONS;
}

bool TaxCollectorBasicInformations::operator==(const TaxCollectorBasicInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

