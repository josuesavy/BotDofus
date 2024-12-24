#include "HouseInformationsInside.h"

void HouseInformationsInside::serialize(Writer *output)
{
  this->serializeAs_HouseInformationsInside(output);
}

void HouseInformationsInside::serializeAs_HouseInformationsInside(Writer *output)
{
  HouseInformations::serializeAs_HouseInformations(output);
  output->writeShort((short)this->houseInfos->getTypes().last());
  this->houseInfos->serialize(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
}

void HouseInformationsInside::deserialize(Reader *input)
{
  this->deserializeAs_HouseInformationsInside(input);
}

void HouseInformationsInside::deserializeAs_HouseInformationsInside(Reader *input)
{
  HouseInformations::deserialize(input);
  uint _id1 = uint(input->readUShort());
  this->houseInfos = qSharedPointerCast<HouseInstanceInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->houseInfos->deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
}

void HouseInformationsInside::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseInformationsInside(tree);
}

void HouseInformationsInside::deserializeAsyncAs_HouseInformationsInside(FuncTree tree)
{
  HouseInformations::deserializeAsync(tree);
  this->_houseInfostree = tree.addChild(std::bind(&HouseInformationsInside::_houseInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsInside::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseInformationsInside::_worldYFunc, this, std::placeholders::_1));
}

void HouseInformationsInside::_houseInfostreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->houseInfos = qSharedPointerCast<HouseInstanceInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->houseInfos->deserializeAsync(this->_houseInfostree);
}

void HouseInformationsInside::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsInside.worldX.";
  }
}

void HouseInformationsInside::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsInside.worldY.";
  }
}

HouseInformationsInside::HouseInformationsInside()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSINSIDE;
}

bool HouseInformationsInside::operator==(const HouseInformationsInside &compared)
{
  if(houseInfos == compared.houseInfos)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(_houseInfostree == compared._houseInfostree)
  return true;
  
  return false;
}

