#include "AtlasPointsInformations.h"

void AtlasPointsInformations::serialize(Writer *output)
{
  this->serializeAs_AtlasPointsInformations(output);
}

void AtlasPointsInformations::serializeAs_AtlasPointsInformations(Writer *output)
{
  output->writeByte(this->type);
  output->writeShort((short)this->coords.size());
  for(uint _i2 = 0; _i2 < this->coords.size(); _i2++)
  {
    qSharedPointerCast<MapCoordinatesExtended>(this->coords[_i2])->serializeAs_MapCoordinatesExtended(output);
  }
}

void AtlasPointsInformations::deserialize(Reader *input)
{
  this->deserializeAs_AtlasPointsInformations(input);
}

void AtlasPointsInformations::deserializeAs_AtlasPointsInformations(Reader *input)
{
  QSharedPointer<MapCoordinatesExtended> _item2 ;
  this->_typeFunc(input);
  uint _coordsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _coordsLen; _i2++)
  {
    _item2 = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
    _item2->deserialize(input);
    this->coords.append(_item2);
  }
}

void AtlasPointsInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AtlasPointsInformations(tree);
}

void AtlasPointsInformations::deserializeAsyncAs_AtlasPointsInformations(FuncTree tree)
{
  tree.addChild(std::bind(&AtlasPointsInformations::_typeFunc, this, std::placeholders::_1));
  this->_coordstree = tree.addChild(std::bind(&AtlasPointsInformations::_coordstreeFunc, this, std::placeholders::_1));
}

void AtlasPointsInformations::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - AtlasPointsInformations -"<<"Forbidden value (" << this->type << ") on element of AtlasPointsInformations.type.";
  }
}

void AtlasPointsInformations::_coordstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_coordstree.addChild(std::bind(&AtlasPointsInformations::_coordsFunc, this, std::placeholders::_1));
  }
}

void AtlasPointsInformations::_coordsFunc(Reader *input)
{
  QSharedPointer<MapCoordinatesExtended> _item = QSharedPointer<MapCoordinatesExtended>(new MapCoordinatesExtended() );
  _item->deserialize(input);
  this->coords.append(_item);
}

AtlasPointsInformations::AtlasPointsInformations()
{
  m_types<<ClassEnum::ATLASPOINTSINFORMATIONS;
}

bool AtlasPointsInformations::operator==(const AtlasPointsInformations &compared)
{
  if(type == compared.type)
  if(coords == compared.coords)
  if(_coordstree == compared._coordstree)
  return true;
  
  return false;
}

