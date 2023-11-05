#include "MapObstacleUpdateMessage.h"

void MapObstacleUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_MapObstacleUpdateMessage(output);
}

void MapObstacleUpdateMessage::serializeAs_MapObstacleUpdateMessage(Writer *output)
{
  output->writeShort((short)this->obstacles.size());
  for(uint _i1 = 0; _i1 < this->obstacles.size(); _i1++)
  {
    (this->obstacles[_i1]).serializeAs_MapObstacle(output);
  }
}

void MapObstacleUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapObstacleUpdateMessage(input);
}

void MapObstacleUpdateMessage::deserializeAs_MapObstacleUpdateMessage(Reader *input)
{
  MapObstacle _item1 ;
  uint _obstaclesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _obstaclesLen; _i1++)
  {
    _item1 = MapObstacle();
    _item1.deserialize(input);
    this->obstacles.append(_item1);
  }
}

void MapObstacleUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapObstacleUpdateMessage(tree);
}

void MapObstacleUpdateMessage::deserializeAsyncAs_MapObstacleUpdateMessage(FuncTree tree)
{
  this->_obstaclestree = tree.addChild(std::bind(&MapObstacleUpdateMessage::_obstaclestreeFunc, this, std::placeholders::_1));
}

void MapObstacleUpdateMessage::_obstaclestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_obstaclestree.addChild(std::bind(&MapObstacleUpdateMessage::_obstaclesFunc, this, std::placeholders::_1));
  }
}

void MapObstacleUpdateMessage::_obstaclesFunc(Reader *input)
{
  MapObstacle _item = MapObstacle();
  _item.deserialize(input);
  this->obstacles.append(_item);
}

MapObstacleUpdateMessage::MapObstacleUpdateMessage()
{
  m_type = MessageEnum::MAPOBSTACLEUPDATEMESSAGE;
}

