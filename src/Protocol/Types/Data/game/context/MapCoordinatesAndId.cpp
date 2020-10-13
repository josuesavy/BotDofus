#include "MapCoordinatesAndId.h"

void MapCoordinatesAndId::serialize(Writer *output)
{
  this->serializeAs_MapCoordinatesAndId(output);
}

void MapCoordinatesAndId::serializeAs_MapCoordinatesAndId(Writer *output)
{
  MapCoordinates::serializeAs_MapCoordinates(output);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapCoordinatesAndId -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void MapCoordinatesAndId::deserialize(Reader *input)
{
  this->deserializeAs_MapCoordinatesAndId(input);
}

void MapCoordinatesAndId::deserializeAs_MapCoordinatesAndId(Reader *input)
{
  MapCoordinates::deserialize(input);
  this->_mapIdFunc(input);
}

void MapCoordinatesAndId::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapCoordinatesAndId(tree);
}

void MapCoordinatesAndId::deserializeAsyncAs_MapCoordinatesAndId(FuncTree tree)
{
  MapCoordinates::deserializeAsync(tree);
  tree.addChild(std::bind(&MapCoordinatesAndId::_mapIdFunc, this, std::placeholders::_1));
}

void MapCoordinatesAndId::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapCoordinatesAndId -"<<"Forbidden value (" << this->mapId << ") on element of MapCoordinatesAndId.mapId.";
  }
}

MapCoordinatesAndId::MapCoordinatesAndId()
{
  m_types<<ClassEnum::MAPCOORDINATESANDID;
}

bool MapCoordinatesAndId::operator==(const MapCoordinatesAndId &compared)
{
  if(mapId == compared.mapId)
  return true;
  
  return false;
}

