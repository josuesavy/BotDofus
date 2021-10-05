#include "TeleportDestination.h"

void TeleportDestination::serialize(Writer *output)
{
  this->serializeAs_TeleportDestination(output);
}

void TeleportDestination::serializeAs_TeleportDestination(Writer *output)
{
  output->writeByte(this->type);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  if(this->cost < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->cost << ") on element cost.";
  }
  output->writeVarShort((int)this->cost);
}

void TeleportDestination::deserialize(Reader *input)
{
  this->deserializeAs_TeleportDestination(input);
}

void TeleportDestination::deserializeAs_TeleportDestination(Reader *input)
{
  this->_typeFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->_levelFunc(input);
  this->_costFunc(input);
}

void TeleportDestination::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportDestination(tree);
}

void TeleportDestination::deserializeAsyncAs_TeleportDestination(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportDestination::_typeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportDestination::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportDestination::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportDestination::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportDestination::_costFunc, this, std::placeholders::_1));
}

void TeleportDestination::_typeFunc(Reader *input)
{
  this->type = input->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->type << ") on element of TeleportDestination.type.";
  }
}

void TeleportDestination::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->mapId << ") on element of TeleportDestination.mapId.";
  }
}

void TeleportDestination::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->subAreaId << ") on element of TeleportDestination.subAreaId.";
  }
}

void TeleportDestination::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->level << ") on element of TeleportDestination.level.";
  }
}

void TeleportDestination::_costFunc(Reader *input)
{
  this->cost = input->readVarUhShort();
  if(this->cost < 0)
  {
    qDebug()<<"ERREUR - TeleportDestination -"<<"Forbidden value (" << this->cost << ") on element of TeleportDestination.cost.";
  }
}

TeleportDestination::TeleportDestination()
{
  m_types<<ClassEnum::TELEPORTDESTINATION;
}

bool TeleportDestination::operator==(const TeleportDestination &compared)
{
  if(type == compared.type)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(level == compared.level)
  if(cost == compared.cost)
  return true;
  
  return false;
}

