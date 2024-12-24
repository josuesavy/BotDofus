#include "GameActionMark.h"

void GameActionMark::serialize(Writer *output)
{
  this->serializeAs_GameActionMark(output);
}

void GameActionMark::serializeAs_GameActionMark(Writer *output)
{
  if(this->markAuthorId < -9007199254740992 || this->markAuthorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markAuthorId << ") on element markAuthorId.";
  }
  output->writeDouble(this->markAuthorId);
  output->writeByte(this->markTeamId);
  if(this->markSpellId < 0)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellId << ") on element markSpellId.";
  }
  output->writeInt((int)this->markSpellId);
  if(this->markSpellLevel < 1 || this->markSpellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellLevel << ") on element markSpellLevel.";
  }
  output->writeShort((short)this->markSpellLevel);
  output->writeShort((short)this->markId);
  output->writeByte(this->markType);
  if(this->markimpactCell < -1 || this->markimpactCell > 559)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markimpactCell << ") on element markimpactCell.";
  }
  output->writeShort((short)this->markimpactCell);
  output->writeShort((short)this->cells.size());
  for(uint _i8 = 0; _i8 < this->cells.size(); _i8++)
  {
    (this->cells[_i8]).serializeAs_GameActionMarkedCell(output);
  }
  output->writeBool(this->active);
}

void GameActionMark::deserialize(Reader *input)
{
  this->deserializeAs_GameActionMark(input);
}

void GameActionMark::deserializeAs_GameActionMark(Reader *input)
{
  GameActionMarkedCell _item8 ;
  this->_markAuthorIdFunc(input);
  this->_markTeamIdFunc(input);
  this->_markSpellIdFunc(input);
  this->_markSpellLevelFunc(input);
  this->_markIdFunc(input);
  this->_markTypeFunc(input);
  this->_markimpactCellFunc(input);
  uint _cellsLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _cellsLen; _i8++)
  {
    _item8 = GameActionMarkedCell();
    _item8.deserialize(input);
    this->cells.append(_item8);
  }
  this->_activeFunc(input);
}

void GameActionMark::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionMark(tree);
}

void GameActionMark::deserializeAsyncAs_GameActionMark(FuncTree tree)
{
  tree.addChild(std::bind(&GameActionMark::_markAuthorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markTeamIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markSpellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markSpellLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_markimpactCellFunc, this, std::placeholders::_1));
  this->_cellstree = tree.addChild(std::bind(&GameActionMark::_cellstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameActionMark::_activeFunc, this, std::placeholders::_1));
}

void GameActionMark::_markAuthorIdFunc(Reader *input)
{
  this->markAuthorId = input->readDouble();
  if(this->markAuthorId < -9007199254740992 || this->markAuthorId > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markAuthorId << ") on element of GameActionMark.markAuthorId.";
  }
}

void GameActionMark::_markTeamIdFunc(Reader *input)
{
  this->markTeamId = input->readByte();
  if(this->markTeamId < 0)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markTeamId << ") on element of GameActionMark.markTeamId.";
  }
}

void GameActionMark::_markSpellIdFunc(Reader *input)
{
  this->markSpellId = input->readInt();
  if(this->markSpellId < 0)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellId << ") on element of GameActionMark.markSpellId.";
  }
}

void GameActionMark::_markSpellLevelFunc(Reader *input)
{
  this->markSpellLevel = input->readShort();
  if(this->markSpellLevel < 1 || this->markSpellLevel > 32767)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellLevel << ") on element of GameActionMark.markSpellLevel.";
  }
}

void GameActionMark::_markIdFunc(Reader *input)
{
  this->markId = input->readShort();
}

void GameActionMark::_markTypeFunc(Reader *input)
{
  this->markType = input->readByte();
}

void GameActionMark::_markimpactCellFunc(Reader *input)
{
  this->markimpactCell = input->readShort();
  if(this->markimpactCell < -1 || this->markimpactCell > 559)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markimpactCell << ") on element of GameActionMark.markimpactCell.";
  }
}

void GameActionMark::_cellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_cellstree.addChild(std::bind(&GameActionMark::_cellsFunc, this, std::placeholders::_1));
  }
}

void GameActionMark::_cellsFunc(Reader *input)
{
  GameActionMarkedCell _item = GameActionMarkedCell();
  _item.deserialize(input);
  this->cells.append(_item);
}

void GameActionMark::_activeFunc(Reader *input)
{
  this->active = input->readBool();
}

GameActionMark::GameActionMark()
{
  m_types<<ClassEnum::GAMEACTIONMARK;
}

bool GameActionMark::operator==(const GameActionMark &compared)
{
  if(markAuthorId == compared.markAuthorId)
  if(markTeamId == compared.markTeamId)
  if(markSpellId == compared.markSpellId)
  if(markSpellLevel == compared.markSpellLevel)
  if(markId == compared.markId)
  if(markType == compared.markType)
  if(markimpactCell == compared.markimpactCell)
  if(cells == compared.cells)
  if(active == compared.active)
  if(_cellstree == compared._cellstree)
  return true;
  
  return false;
}

