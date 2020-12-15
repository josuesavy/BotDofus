#include "PartyMemberInformations.h"

void PartyMemberInformations::serialize(Writer *output)
{
  this->serializeAs_PartyMemberInformations(output);
}

void PartyMemberInformations::serializeAs_PartyMemberInformations(Writer *output)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(output);
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  output->writeVarInt((int)this->lifePoints);
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
  }
  output->writeVarInt((int)this->maxLifePoints);
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
  }
  output->writeVarShort((int)this->prospecting);
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
  }
  output->writeByte(this->regenRate);
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
  }
  output->writeVarShort((int)this->initiative);
  output->writeByte(this->alignmentSide);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
  output->writeShort((short)this->entities.size());
  for(uint _i12 = 0; _i12 < this->entities.size(); _i12++)
  {
    output->writeShort((short)qSharedPointerCast<PartyEntityBaseInformation>(this->entities[_i12])->getTypes().last());
    qSharedPointerCast<PartyEntityBaseInformation>(this->entities[_i12])->serialize(output);
  }
}

void PartyMemberInformations::deserialize(Reader *input)
{
  this->deserializeAs_PartyMemberInformations(input);
}

void PartyMemberInformations::deserializeAs_PartyMemberInformations(Reader *input)
{
  uint _id12 = 0;
  QSharedPointer<PartyEntityBaseInformation> _item12 ;
  CharacterBaseInformations::deserialize(input);
  this->_lifePointsFunc(input);
  this->_maxLifePointsFunc(input);
  this->_prospectingFunc(input);
  this->_regenRateFunc(input);
  this->_initiativeFunc(input);
  this->_alignmentSideFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  uint _id11 = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id11));
  this->status->deserialize(input);
  uint _entitiesLen = input->readUShort();
  for(uint _i12 = 0; _i12 < _entitiesLen; _i12++)
  {
    _id12 = input->readUShort();
    _item12 = qSharedPointerCast<PartyEntityBaseInformation>(ClassManagerSingleton::get()->getClass(_id12));
    _item12->deserialize(input);
    this->entities.append(_item12);
  }
}

void PartyMemberInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyMemberInformations(tree);
}

void PartyMemberInformations::deserializeAsyncAs_PartyMemberInformations(FuncTree tree)
{
  CharacterBaseInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&PartyMemberInformations::_lifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_maxLifePointsFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_prospectingFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_regenRateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_initiativeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_alignmentSideFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyMemberInformations::_subAreaIdFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&PartyMemberInformations::_statustreeFunc, this, std::placeholders::_1));
  this->_entitiestree = tree.addChild(std::bind(&PartyMemberInformations::_entitiestreeFunc, this, std::placeholders::_1));
}

void PartyMemberInformations::_lifePointsFunc(Reader *input)
{
  this->lifePoints = input->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyMemberInformations.lifePoints.";
  }
}

void PartyMemberInformations::_maxLifePointsFunc(Reader *input)
{
  this->maxLifePoints = input->readVarUhInt();
  if(this->maxLifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyMemberInformations.maxLifePoints.";
  }
}

void PartyMemberInformations::_prospectingFunc(Reader *input)
{
  this->prospecting = input->readVarUhShort();
  if(this->prospecting < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element of PartyMemberInformations.prospecting.";
  }
}

void PartyMemberInformations::_regenRateFunc(Reader *input)
{
  this->regenRate = input->readUByte();
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element of PartyMemberInformations.regenRate.";
  }
}

void PartyMemberInformations::_initiativeFunc(Reader *input)
{
  this->initiative = input->readVarUhShort();
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element of PartyMemberInformations.initiative.";
  }
}

void PartyMemberInformations::_alignmentSideFunc(Reader *input)
{
  this->alignmentSide = input->readByte();
}

void PartyMemberInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element of PartyMemberInformations.worldX.";
  }
}

void PartyMemberInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element of PartyMemberInformations.worldY.";
  }
}

void PartyMemberInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->mapId << ") on element of PartyMemberInformations.mapId.";
  }
}

void PartyMemberInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyMemberInformations.subAreaId.";
  }
}

void PartyMemberInformations::_statustreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

void PartyMemberInformations::_entitiestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_entitiestree.addChild(std::bind(&PartyMemberInformations::_entitiesFunc, this, std::placeholders::_1));
  }
}

void PartyMemberInformations::_entitiesFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<PartyEntityBaseInformation> _item = qSharedPointerCast<PartyEntityBaseInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->entities.append(_item);
}

PartyMemberInformations::PartyMemberInformations()
{
  m_types<<ClassEnum::PARTYMEMBERINFORMATIONS;
}

bool PartyMemberInformations::operator==(const PartyMemberInformations &compared)
{
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(prospecting == compared.prospecting)
  if(regenRate == compared.regenRate)
  if(initiative == compared.initiative)
  if(alignmentSide == compared.alignmentSide)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(status == compared.status)
  if(entities == compared.entities)
  if(_statustree == compared._statustree)
  if(_entitiestree == compared._entitiestree)
  return true;
  
  return false;
}

