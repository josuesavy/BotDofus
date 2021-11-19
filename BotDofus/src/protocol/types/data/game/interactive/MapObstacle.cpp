#include "MapObstacle.h"

void MapObstacle::serialize(Writer *output)
{
  this->serializeAs_MapObstacle(output);
}

void MapObstacle::serializeAs_MapObstacle(Writer *output)
{
  if(this->obstacleCellId < 0 || this->obstacleCellId > 559)
  {
    qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->obstacleCellId << ") on element obstacleCellId.";
  }
  output->writeVarShort((int)this->obstacleCellId);
  output->writeByte(this->state);
}

void MapObstacle::deserialize(Reader *input)
{
  this->deserializeAs_MapObstacle(input);
}

void MapObstacle::deserializeAs_MapObstacle(Reader *input)
{
  this->_obstacleCellIdFunc(input);
  this->_stateFunc(input);
}

void MapObstacle::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapObstacle(tree);
}

void MapObstacle::deserializeAsyncAs_MapObstacle(FuncTree tree)
{
  tree.addChild(std::bind(&MapObstacle::_obstacleCellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapObstacle::_stateFunc, this, std::placeholders::_1));
}

void MapObstacle::_obstacleCellIdFunc(Reader *input)
{
  this->obstacleCellId = input->readVarUhShort();
  if(this->obstacleCellId < 0 || this->obstacleCellId > 559)
  {
    qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->obstacleCellId << ") on element of MapObstacle.obstacleCellId.";
  }
}

void MapObstacle::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - MapObstacle -"<<"Forbidden value (" << this->state << ") on element of MapObstacle.state.";
  }
}

MapObstacle::MapObstacle()
{
  m_types<<ClassEnum::MAPOBSTACLE;
}

bool MapObstacle::operator==(const MapObstacle &compared)
{
  if(obstacleCellId == compared.obstacleCellId)
  if(state == compared.state)
  return true;
  
  return false;
}

