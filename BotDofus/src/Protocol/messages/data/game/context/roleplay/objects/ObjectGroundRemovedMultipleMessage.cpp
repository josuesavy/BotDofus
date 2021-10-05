#include "ObjectGroundRemovedMultipleMessage.h"

void ObjectGroundRemovedMultipleMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectGroundRemovedMultipleMessage(output);
}

void ObjectGroundRemovedMultipleMessage::serializeAs_ObjectGroundRemovedMultipleMessage(Writer *output)
{
  output->writeShort((short)this->cells.size());
  for(uint _i1 = 0; _i1 < this->cells.size(); _i1++)
  {
    if(this->cells[_i1] < 0 || this->cells[_i1] > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundRemovedMultipleMessage -"<<"Forbidden value (" << this->cells[_i1] << ") on element 1 (starting at 1) of cells.";
    }
    output->writeVarShort((int)this->cells[_i1]);
  }
}

void ObjectGroundRemovedMultipleMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectGroundRemovedMultipleMessage(input);
}

void ObjectGroundRemovedMultipleMessage::deserializeAs_ObjectGroundRemovedMultipleMessage(Reader *input)
{
  uint _val1 = 0;
  uint _cellsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _cellsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0 || _val1 > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundRemovedMultipleMessage -"<<"Forbidden value (" << _val1 << ") on elements of cells.";
    }
    this->cells.append(_val1);
  }
}

void ObjectGroundRemovedMultipleMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectGroundRemovedMultipleMessage(tree);
}

void ObjectGroundRemovedMultipleMessage::deserializeAsyncAs_ObjectGroundRemovedMultipleMessage(FuncTree tree)
{
  this->_cellstree = tree.addChild(std::bind(&ObjectGroundRemovedMultipleMessage::_cellstreeFunc, this, std::placeholders::_1));
}

void ObjectGroundRemovedMultipleMessage::_cellstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_cellstree.addChild(std::bind(&ObjectGroundRemovedMultipleMessage::_cellsFunc, this, std::placeholders::_1));
  }
}

void ObjectGroundRemovedMultipleMessage::_cellsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundRemovedMultipleMessage -"<<"Forbidden value (" << _val << ") on elements of cells.";
  }
  this->cells.append(_val);
}

ObjectGroundRemovedMultipleMessage::ObjectGroundRemovedMultipleMessage()
{
  m_type = MessageEnum::OBJECTGROUNDREMOVEDMULTIPLEMESSAGE;
}

