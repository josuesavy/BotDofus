#include "ObjectGroundListAddedMessage.h"

void ObjectGroundListAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectGroundListAddedMessage(output);
}

void ObjectGroundListAddedMessage::serializeAs_ObjectGroundListAddedMessage(Writer *output)
{
  output->writeShort((short)this->cells.size());
  for(uint _i1 = 0; _i1 < this->cells.size(); _i1++)
  {
    if(this->cells[_i1] < 0 || this->cells[_i1] > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << this->cells[_i1] << ") on element 1 (starting at 1) of cells.";
    }
    output->writeVarShort((int)this->cells[_i1]);
  }
  output->writeShort((short)this->referenceIds.size());
  for(uint _i2 = 0; _i2 < this->referenceIds.size(); _i2++)
  {
    if(this->referenceIds[_i2] < 0)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << this->referenceIds[_i2] << ") on element 2 (starting at 1) of referenceIds.";
    }
    output->writeVarShort((int)this->referenceIds[_i2]);
  }
}

void ObjectGroundListAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectGroundListAddedMessage(input);
}

void ObjectGroundListAddedMessage::deserializeAs_ObjectGroundListAddedMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _cellsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _cellsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0 || _val1 > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _val1 << ") on elements of cells.";
    }
    this->cells.append(_val1);
  }
  uint _referenceIdsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _referenceIdsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _val2 << ") on elements of referenceIds.";
    }
    this->referenceIds.append(_val2);
  }
}

void ObjectGroundListAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectGroundListAddedMessage(tree);
}

void ObjectGroundListAddedMessage::deserializeAsyncAs_ObjectGroundListAddedMessage(FuncTree tree)
{
  this->_cellstree = tree.addChild(std::bind(&ObjectGroundListAddedMessage::_cellstreeFunc, this, std::placeholders::_1));
  this->_referenceIdstree = tree.addChild(std::bind(&ObjectGroundListAddedMessage::_referenceIdstreeFunc, this, std::placeholders::_1));
}

void ObjectGroundListAddedMessage::_cellstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_cellstree.addChild(std::bind(&ObjectGroundListAddedMessage::_cellsFunc, this, std::placeholders::_1));
  }
}

void ObjectGroundListAddedMessage::_cellsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0 || _val > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _val << ") on elements of cells.";
  }
  this->cells.append(_val);
}

void ObjectGroundListAddedMessage::_referenceIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_referenceIdstree.addChild(std::bind(&ObjectGroundListAddedMessage::_referenceIdsFunc, this, std::placeholders::_1));
  }
}

void ObjectGroundListAddedMessage::_referenceIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _val << ") on elements of referenceIds.";
  }
  this->referenceIds.append(_val);
}

ObjectGroundListAddedMessage::ObjectGroundListAddedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE;
}

