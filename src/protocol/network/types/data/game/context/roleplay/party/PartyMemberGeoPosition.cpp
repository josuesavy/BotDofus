#include "PartyMemberGeoPosition.h"

void PartyMemberGeoPosition::serialize(Writer *output)
{
  this->serializeAs_PartyMemberGeoPosition(output);
}

void PartyMemberGeoPosition::serializeAs_PartyMemberGeoPosition(Writer *output)
{
  if(this->memberId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  output->writeInt((int)this->memberId);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void PartyMemberGeoPosition::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberGeoPosition(input);
}

void PartyMemberGeoPosition::deserializeAs_PartyMemberGeoPosition(Reader *input)
{
  this->_memberIdFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
}

void PartyMemberGeoPosition::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberGeoPosition(tree);
}

void PartyMemberGeoPosition::deserializeAsyncAs_PartyMemberGeoPosition(FuncTree tree)
{
  tree.addChild(std::bind(&PartyMemberGeoPosition::_memberIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberGeoPosition::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberGeoPosition::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberGeoPosition::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberGeoPosition::_subAreaIdFunc, this, std::placeholders::_1));
}

void PartyMemberGeoPosition::_memberIdFunc(Reader *input)
{
  this->memberId = input->readInt();
  if(this->memberId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->memberId << ") on element of PartyMemberGeoPosition.memberId.";
  }
}

void PartyMemberGeoPosition::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldX << ") on element of PartyMemberGeoPosition.worldX.";
  }
}

void PartyMemberGeoPosition::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldY << ") on element of PartyMemberGeoPosition.worldY.";
  }
}

void PartyMemberGeoPosition::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->mapId << ") on element of PartyMemberGeoPosition.mapId.";
  }
}

void PartyMemberGeoPosition::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyMemberGeoPosition.subAreaId.";
  }
}

PartyMemberGeoPosition::PartyMemberGeoPosition()
{
  m_types<<ClassEnum::PARTYMEMBERGEOPOSITION;
}

bool PartyMemberGeoPosition::operator==(const PartyMemberGeoPosition &compared)
{
  if(memberId == compared.memberId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

