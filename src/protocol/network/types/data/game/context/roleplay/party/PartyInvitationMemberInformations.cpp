#include "PartyInvitationMemberInformations.h"

void PartyInvitationMemberInformations::serialize(Writer *output)
{
  this->serializeAs_PartyInvitationMemberInformations(output);
}

void PartyInvitationMemberInformations::serializeAs_PartyInvitationMemberInformations(Writer *output)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeShort((short)this->entities.size());
  for(uint _i5 = 0; _i5 < this->entities.size(); _i5++)
  {
    qSharedPointerCast<PartyEntityBaseInformation>(this->entities[_i5])->serializeAs_PartyEntityBaseInformation(output);
  }
}

void PartyInvitationMemberInformations::deserialize(Reader *input)
{
  this->deserializeAs_PartyInvitationMemberInformations(input);
}

void PartyInvitationMemberInformations::deserializeAs_PartyInvitationMemberInformations(Reader *input)
{
  QSharedPointer<PartyEntityBaseInformation> _item5 ;
  CharacterBaseInformations::deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  uint _entitiesLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _entitiesLen; _i5++)
  {
    _item5 = QSharedPointer<PartyEntityBaseInformation>(new PartyEntityBaseInformation() );
    _item5->deserialize(input);
    this->entities.append(_item5);
  }
}

void PartyInvitationMemberInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyInvitationMemberInformations(tree);
}

void PartyInvitationMemberInformations::deserializeAsyncAs_PartyInvitationMemberInformations(FuncTree tree)
{
  CharacterBaseInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyInvitationMemberInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMemberInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMemberInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyInvitationMemberInformations::_subAreaIdFunc, this, std::placeholders::_1));
  this->_entitiestree = tree.addChild(std::bind(&PartyInvitationMemberInformations::_entitiestreeFunc, this, std::placeholders::_1));
}

void PartyInvitationMemberInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element of PartyInvitationMemberInformations.worldX.";
  }
}

void PartyInvitationMemberInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element of PartyInvitationMemberInformations.worldY.";
  }
}

void PartyInvitationMemberInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->mapId << ") on element of PartyInvitationMemberInformations.mapId.";
  }
}

void PartyInvitationMemberInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyInvitationMemberInformations.subAreaId.";
  }
}

void PartyInvitationMemberInformations::_entitiestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_entitiestree.addChild(std::bind(&PartyInvitationMemberInformations::_entitiesFunc, this, std::placeholders::_1));
  }
}

void PartyInvitationMemberInformations::_entitiesFunc(Reader *input)
{
  QSharedPointer<PartyEntityBaseInformation> _item = QSharedPointer<PartyEntityBaseInformation>(new PartyEntityBaseInformation() );
  _item->deserialize(input);
  this->entities.append(_item);
}

PartyInvitationMemberInformations::PartyInvitationMemberInformations()
{
  m_types<<ClassEnum::PARTYINVITATIONMEMBERINFORMATIONS;
}

bool PartyInvitationMemberInformations::operator==(const PartyInvitationMemberInformations &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(entities == compared.entities)
  if(_entitiestree == compared._entitiestree)
  return true;
  
  return false;
}

