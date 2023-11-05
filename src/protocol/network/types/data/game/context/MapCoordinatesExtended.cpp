#include "MapCoordinatesExtended.h"

void MapCoordinatesExtended::serialize(Writer *output)
{
  this->serializeAs_MapCoordinatesExtended(output);
}

void MapCoordinatesExtended::serializeAs_MapCoordinatesExtended(Writer *output)
{
  MapCoordinatesAndId::serializeAs_MapCoordinatesAndId(output);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapCoordinatesExtended -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void MapCoordinatesExtended::deserialize(Reader *input)
{
  this->deserializeAs_MapCoordinatesExtended(input);
}

void MapCoordinatesExtended::deserializeAs_MapCoordinatesExtended(Reader *input)
{
  MapCoordinatesAndId::deserialize(input);
  this->_subAreaIdFunc(input);
}

void MapCoordinatesExtended::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapCoordinatesExtended(tree);
}

void MapCoordinatesExtended::deserializeAsyncAs_MapCoordinatesExtended(FuncTree tree)
{
  MapCoordinatesAndId::deserializeAsync(tree);
  tree.addChild(std::bind(&MapCoordinatesExtended::_subAreaIdFunc, this, std::placeholders::_1));
}

void MapCoordinatesExtended::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapCoordinatesExtended -"<<"Forbidden value (" << this->subAreaId << ") on element of MapCoordinatesExtended.subAreaId.";
  }
}

MapCoordinatesExtended::MapCoordinatesExtended()
{
  m_types<<ClassEnum::MAPCOORDINATESEXTENDED;
}

bool MapCoordinatesExtended::operator==(const MapCoordinatesExtended &compared)
{
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

