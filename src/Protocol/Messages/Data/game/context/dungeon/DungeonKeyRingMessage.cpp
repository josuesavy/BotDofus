#include "DungeonKeyRingMessage.h"

void DungeonKeyRingMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonKeyRingMessage(output);
}

void DungeonKeyRingMessage::serializeAs_DungeonKeyRingMessage(Writer *output)
{
  output->writeShort((short)this->availables.size());
  for(uint _i1 = 0; _i1 < this->availables.size(); _i1++)
  {
    if(this->availables[_i1] < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << this->availables[_i1] << ") on element 1 (starting at 1) of availables.";
    }
    output->writeVarShort((int)this->availables[_i1]);
  }
  output->writeShort((short)this->unavailables.size());
  for(uint _i2 = 0; _i2 < this->unavailables.size(); _i2++)
  {
    if(this->unavailables[_i2] < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << this->unavailables[_i2] << ") on element 2 (starting at 1) of unavailables.";
    }
    output->writeVarShort((int)this->unavailables[_i2]);
  }
}

void DungeonKeyRingMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonKeyRingMessage(input);
}

void DungeonKeyRingMessage::deserializeAs_DungeonKeyRingMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _availablesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _availablesLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _val1 << ") on elements of availables.";
    }
    this->availables.append(_val1);
  }
  uint _unavailablesLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _unavailablesLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _val2 << ") on elements of unavailables.";
    }
    this->unavailables.append(_val2);
  }
}

void DungeonKeyRingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonKeyRingMessage(tree);
}

void DungeonKeyRingMessage::deserializeAsyncAs_DungeonKeyRingMessage(FuncTree tree)
{
  this->_availablestree = tree.addChild(std::bind(&DungeonKeyRingMessage::_availablestreeFunc, this, std::placeholders::_1));
  this->_unavailablestree = tree.addChild(std::bind(&DungeonKeyRingMessage::_unavailablestreeFunc, this, std::placeholders::_1));
}

void DungeonKeyRingMessage::_availablestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_availablestree.addChild(std::bind(&DungeonKeyRingMessage::_availablesFunc, this, std::placeholders::_1));
  }
}

void DungeonKeyRingMessage::_availablesFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _val << ") on elements of availables.";
  }
  this->availables.append(_val);
}

void DungeonKeyRingMessage::_unavailablestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_unavailablestree.addChild(std::bind(&DungeonKeyRingMessage::_unavailablesFunc, this, std::placeholders::_1));
  }
}

void DungeonKeyRingMessage::_unavailablesFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _val << ") on elements of unavailables.";
  }
  this->unavailables.append(_val);
}

DungeonKeyRingMessage::DungeonKeyRingMessage()
{
  m_type = MessageEnum::DUNGEONKEYRINGMESSAGE;
}

