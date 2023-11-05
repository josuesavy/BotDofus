#include "HouseOnMapInformations.h"

void HouseOnMapInformations::serialize(Writer *output)
{
  this->serializeAs_HouseOnMapInformations(output);
}

void HouseOnMapInformations::serializeAs_HouseOnMapInformations(Writer *output)
{
  HouseInformations::serializeAs_HouseInformations(output);
  output->writeShort((short)this->doorsOnMap.size());
  for(uint _i1 = 0; _i1 < this->doorsOnMap.size(); _i1++)
  {
    if(this->doorsOnMap[_i1] < 0)
    {
      qDebug()<<"ERREUR - HouseOnMapInformations -"<<"Forbidden value (" << this->doorsOnMap[_i1] << ") on element 1 (starting at 1) of doorsOnMap.";
    }
    output->writeInt((int)this->doorsOnMap[_i1]);
  }
  output->writeShort((short)this->houseInstances.size());
  for(uint _i2 = 0; _i2 < this->houseInstances.size(); _i2++)
  {
    (this->houseInstances[_i2]).serializeAs_HouseInstanceInformations(output);
  }
}

void HouseOnMapInformations::deserialize(Reader *input)
{
  this->deserializeAs_HouseOnMapInformations(input);
}

void HouseOnMapInformations::deserializeAs_HouseOnMapInformations(Reader *input)
{
  uint _val1 = 0;
   _item2 ;
  HouseInformations::deserialize(input);
  uint _doorsOnMapLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _doorsOnMapLen; _i1++)
  {
    _val1 = uint(input->readInt());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - HouseOnMapInformations -"<<"Forbidden value (" << _val1 << ") on elements of doorsOnMap.";
    }
    this->doorsOnMap.append(_val1);
  }
  uint _houseInstancesLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _houseInstancesLen; _i2++)
  {
    _item2 = new com.ankamagames.dofus.network.types.game.house.HouseInstanceInformations();
    _item2.deserialize(input);
    this->houseInstances.append(_item2);
  }
}

void HouseOnMapInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseOnMapInformations(tree);
}

void HouseOnMapInformations::deserializeAsyncAs_HouseOnMapInformations(FuncTree tree)
{
  HouseInformations::deserializeAsync(tree);
  this->_doorsOnMaptree = tree.addChild(std::bind(&HouseOnMapInformations::_doorsOnMaptreeFunc, this, std::placeholders::_1));
  this->_houseInstancestree = tree.addChild(std::bind(&HouseOnMapInformations::_houseInstancestreeFunc, this, std::placeholders::_1));
}

void HouseOnMapInformations::_doorsOnMaptreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_doorsOnMaptree.addChild(std::bind(&HouseOnMapInformations::_doorsOnMapFunc, this, std::placeholders::_1));
  }
}

void HouseOnMapInformations::_doorsOnMapFunc(Reader *input)
{
  uint _val = uint(input->readInt());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - HouseOnMapInformations -"<<"Forbidden value (" << _val << ") on elements of doorsOnMap.";
  }
  this->doorsOnMap.append(_val);
}

void HouseOnMapInformations::_houseInstancestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_houseInstancestree.addChild(std::bind(&HouseOnMapInformations::_houseInstancesFunc, this, std::placeholders::_1));
  }
}

void HouseOnMapInformations::_houseInstancesFunc(Reader *input)
{
   _item = new com.ankamagames.dofus.network.types.game.house.HouseInstanceInformations();
  _item.deserialize(input);
  this->houseInstances.append(_item);
}

HouseOnMapInformations::HouseOnMapInformations()
{
  m_types<<ClassEnum::HOUSEONMAPINFORMATIONS;
}

bool HouseOnMapInformations::operator==(const HouseOnMapInformations &compared)
{
  if(doorsOnMap == compared.doorsOnMap)
  if(houseInstances == compared.houseInstances)
  if(_doorsOnMaptree == compared._doorsOnMaptree)
  if(_houseInstancestree == compared._houseInstancestree)
  return true;
  
  return false;
}

