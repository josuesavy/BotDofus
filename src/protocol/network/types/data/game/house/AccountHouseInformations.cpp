#include "AccountHouseInformations.h"

void AccountHouseInformations::serialize(Writer *output)
{
  this->serializeAs_AccountHouseInformations(output);
}

void AccountHouseInformations::serializeAs_AccountHouseInformations(Writer *output)
{
  HouseInformations::serializeAs_HouseInformations(output);
  output->writeShort((short)this->houseInfos.getTypeId());
  this->houseInfos.serialize(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void AccountHouseInformations::deserialize(Reader *input)
{
  this->deserializeAs_AccountHouseInformations(input);
}

void AccountHouseInformations::deserializeAs_AccountHouseInformations(Reader *input)
{
  HouseInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->houseInfos = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id1));
  this->houseInfos.deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
}

void AccountHouseInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountHouseInformations(tree);
}

void AccountHouseInformations::deserializeAsyncAs_AccountHouseInformations(FuncTree tree)
{
  HouseInformations::deserializeAsync(tree);
  this->_houseInfostree = tree.addChild(std::bind(&AccountHouseInformations::_houseInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountHouseInformations::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountHouseInformations::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountHouseInformations::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountHouseInformations::_subAreaIdFunc, this, std::placeholders::_1));
}

void AccountHouseInformations::_houseInfostreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->houseInfos = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id));
  this->houseInfos.deserializeAsync(this->_houseInfostree);
}

void AccountHouseInformations::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldX << ") on element of AccountHouseInformations.worldX.";
  }
}

void AccountHouseInformations::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldY << ") on element of AccountHouseInformations.worldY.";
  }
}

void AccountHouseInformations::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->mapId << ") on element of AccountHouseInformations.mapId.";
  }
}

void AccountHouseInformations::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of AccountHouseInformations.subAreaId.";
  }
}

AccountHouseInformations::AccountHouseInformations()
{
  m_types<<ClassEnum::ACCOUNTHOUSEINFORMATIONS;
}

bool AccountHouseInformations::operator==(const AccountHouseInformations &compared)
{
  if(houseInfos == compared.houseInfos)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(_houseInfostree == compared._houseInfostree)
  return true;
  
  return false;
}

