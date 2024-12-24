#include "DebugHighlightCellsMessage.h"

void DebugHighlightCellsMessage::serialize(Writer *output)
{
  this->serializeAs_DebugHighlightCellsMessage(output);
}

void DebugHighlightCellsMessage::serializeAs_DebugHighlightCellsMessage(Writer *output)
{
  if(this->color < -9007199254740992 || this->color > 9007199254740992)
  {
    qDebug()<<"ERREUR - DebugHighlightCellsMessage -"<<"Forbidden value (" << this->color << ") on element color.";
  }
  output->writeDouble(this->color);
  output->writeShort((short)this->cells.size());
  for(uint _i2 = 0; _i2 < this->cells.size(); _i2++)
  {
    if(this->cells[_i2] < 0 || this->cells[_i2] > 559)
    {
      qDebug()<<"ERREUR - DebugHighlightCellsMessage -"<<"Forbidden value (" << this->cells[_i2] << ") on element 2 (starting at 1) of cells.";
    }
    output->writeVarShort((int)this->cells[_i2]);
  }
}

void DebugHighlightCellsMessage::deserialize(Reader *input)
{
  this->deserializeAs_DebugHighlightCellsMessage(input);
}

void DebugHighlightCellsMessage::deserializeAs_DebugHighlightCellsMessage(Reader *input)
{
  uint _val2 = 0;
  this->_colorFunc(input);
  uint _cellsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _cellsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0 || _val2 > 559)
    {
      qDebug()<<"ERREUR - DebugHighlightCellsMessage -"<<"Forbidden value (" << _val2 << ") on elements of cells.";
    }
    this->cells.append(_val2);
  }
}

void DebugHighlightCellsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DebugHighlightCellsMessage(tree);
}

void DebugHighlightCellsMessage::deserializeAsyncAs_DebugHighlightCellsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DebugHighlightCellsMessage::_colorFunc, this, std::placeholders::_1));
  this->_cellstree = tree.addChild(std::bind(&DebugHighlightCellsMessage::_cellstreeFunc, this, std::placeholders::_1));
}

void DebugHighlightCellsMessage::_colorFunc(Reader *input)
{
  this->color = input->readDouble();
  if(this->color < -9007199254740992 || this->color > 9007199254740992)
  {
    qDebug()<<"ERREUR - DebugHighlightCellsMessage -"<<"Forbidden value (" << this->color << ") on element of DebugHighlightCellsMessage.color.";
  }
}

void DebugHighlightCellsMessage::_cellstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_cellstree.addChild(std::bind(&DebugHighlightCellsMessage::_cellsFunc, this, std::placeholders::_1));
  }
}

void DebugHighlightCellsMessage::_cellsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - DebugHighlightCellsMessage -"<<"Forbidden value (" << _val << ") on elements of cells.";
  }
  this->cells.append(_val);
}

DebugHighlightCellsMessage::DebugHighlightCellsMessage()
{
  m_type = MessageEnum::DEBUGHIGHLIGHTCELLSMESSAGE;
}

