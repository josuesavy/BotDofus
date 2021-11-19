#include "MapCoordinates.h"

void MapCoordinates::serialize(Writer *output)
{
  this->serializeAs_MapCoordinates(output);
}

void MapCoordinates::serializeAs_MapCoordinates(Writer *output)
{
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
}

void MapCoordinates::deserialize(Reader *input)
{
  this->deserializeAs_MapCoordinates(input);
}

void MapCoordinates::deserializeAs_MapCoordinates(Reader *input)
{
  this->_worldXFunc(input);
  this->_worldYFunc(input);
}

void MapCoordinates::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapCoordinates(tree);
}

void MapCoordinates::deserializeAsyncAs_MapCoordinates(FuncTree tree)
{
  tree.addChild(std::bind(&MapCoordinates::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapCoordinates::_worldYFunc, this, std::placeholders::_1));
}

void MapCoordinates::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldX << ") on element of MapCoordinates.worldX.";
  }
}

void MapCoordinates::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - MapCoordinates -"<<"Forbidden value (" << this->worldY << ") on element of MapCoordinates.worldY.";
  }
}

MapCoordinates::MapCoordinates()
{
  m_types<<ClassEnum::MAPCOORDINATES;
}

bool MapCoordinates::operator==(const MapCoordinates &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  return true;
  
  return false;
}

