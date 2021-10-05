#include "GameActionMarkedCell.h"

void GameActionMarkedCell::serialize(Writer *output)
{
  this->serializeAs_GameActionMarkedCell(output);
}

void GameActionMarkedCell::serializeAs_GameActionMarkedCell(Writer *output)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionMarkedCell -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  output->writeVarShort((int)this->cellId);
  output->writeByte(this->zoneSize);
  output->writeInt((int)this->cellColor);
  output->writeByte(this->cellsType);
}

void GameActionMarkedCell::deserialize(Reader *input)
{
  this->deserializeAs_GameActionMarkedCell(input);
}

void GameActionMarkedCell::deserializeAs_GameActionMarkedCell(Reader *input)
{
  this->_cellIdFunc(input);
  this->_zoneSizeFunc(input);
  this->_cellColorFunc(input);
  this->_cellsTypeFunc(input);
}

void GameActionMarkedCell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionMarkedCell(tree);
}

void GameActionMarkedCell::deserializeAsyncAs_GameActionMarkedCell(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionMarkedCell::_cellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMarkedCell::_zoneSizeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMarkedCell::_cellColorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMarkedCell::_cellsTypeFunc, this, std::placeholders::_1));
}

void GameActionMarkedCell::_cellIdFunc(Reader *input)
{
  this->cellId = input->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionMarkedCell -"<<"Forbidden value (" << this->cellId << ") on element of GameActionMarkedCell.cellId.";
  }
}

void GameActionMarkedCell::_zoneSizeFunc(Reader *input)
{
  this->zoneSize = input->readByte();
}

void GameActionMarkedCell::_cellColorFunc(Reader *input)
{
  this->cellColor = input->readInt();
}

void GameActionMarkedCell::_cellsTypeFunc(Reader *input)
{
  this->cellsType = input->readByte();
}

GameActionMarkedCell::GameActionMarkedCell()
{
  m_types<<ClassEnum::GAMEACTIONMARKEDCELL;
}

bool GameActionMarkedCell::operator==(const GameActionMarkedCell &compared)
{
  if(cellId == compared.cellId)
  if(zoneSize == compared.zoneSize)
  if(cellColor == compared.cellColor)
  if(cellsType == compared.cellsType)
  return true;
  
  return false;
}

