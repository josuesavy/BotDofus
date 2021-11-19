#include "MapFightStartPositionsUpdateMessage.h"

void MapFightStartPositionsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_MapFightStartPositionsUpdateMessage(output);
}

void MapFightStartPositionsUpdateMessage::serializeAs_MapFightStartPositionsUpdateMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapFightStartPositionsUpdateMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  this->fightStartPositions.serializeAs_FightStartingPositions(output);
}

void MapFightStartPositionsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapFightStartPositionsUpdateMessage(input);
}

void MapFightStartPositionsUpdateMessage::deserializeAs_MapFightStartPositionsUpdateMessage(Reader *input)
{
  this->_mapIdFunc(input);
  this->fightStartPositions = FightStartingPositions();
  this->fightStartPositions.deserialize(input);
}

void MapFightStartPositionsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapFightStartPositionsUpdateMessage(tree);
}

void MapFightStartPositionsUpdateMessage::deserializeAsyncAs_MapFightStartPositionsUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapFightStartPositionsUpdateMessage::_mapIdFunc, this, std::placeholders::_1));
  this->_fightStartPositionstree = tree.addChild(std::bind(&MapFightStartPositionsUpdateMessage::_fightStartPositionstreeFunc, this, std::placeholders::_1));
}

void MapFightStartPositionsUpdateMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapFightStartPositionsUpdateMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapFightStartPositionsUpdateMessage.mapId.";
  }
}

void MapFightStartPositionsUpdateMessage::_fightStartPositionstreeFunc(Reader *input)
{
  this->fightStartPositions = FightStartingPositions();
  this->fightStartPositions.deserializeAsync(this->_fightStartPositionstree);
}

MapFightStartPositionsUpdateMessage::MapFightStartPositionsUpdateMessage()
{
  m_type = MessageEnum::MAPFIGHTSTARTPOSITIONSUPDATEMESSAGE;
}

