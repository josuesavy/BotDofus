#include "HavenBagFurnituresRequestMessage.h"

void HavenBagFurnituresRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HavenBagFurnituresRequestMessage(output);
}

void HavenBagFurnituresRequestMessage::serializeAs_HavenBagFurnituresRequestMessage(Writer *output)
{
  output->writeShort((short)this->cellIds.size());
  for(uint _i1 = 0; _i1 < this->cellIds.size(); _i1++)
  {
    if(this->cellIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << this->cellIds[_i1] << ") on element 1 (starting at 1) of cellIds.";
    }
    output->writeVarShort((int)this->cellIds[_i1]);
  }
  output->writeShort((short)this->funitureIds.size());
  for(uint _i2 = 0; _i2 < this->funitureIds.size(); _i2++)
  {
    output->writeInt((int)this->funitureIds[_i2]);
  }
  output->writeShort((short)this->orientations.size());
  for(uint _i3 = 0; _i3 < this->orientations.size(); _i3++)
  {
    if(this->orientations[_i3] < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << this->orientations[_i3] << ") on element 3 (starting at 1) of orientations.";
    }
    output->writeByte(this->orientations[_i3]);
  }
}

void HavenBagFurnituresRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HavenBagFurnituresRequestMessage(input);
}

void HavenBagFurnituresRequestMessage::deserializeAs_HavenBagFurnituresRequestMessage(Reader *input)
{
  uint _val1 = 0;
  int _val2 = 0;
  uint _val3 = 0;
  uint _cellIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _cellIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of cellIds.";
    }
    this->cellIds.append(_val1);
  }
  uint _funitureIdsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _funitureIdsLen; _i2++)
  {
    _val2 = int(input->readInt());
    this->funitureIds.append(_val2);
  }
  uint _orientationsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _orientationsLen; _i3++)
  {
    _val3 = uint(input->readByte());
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _val3 << ") on elements of orientations.";
    }
    this->orientations.append(_val3);
  }
}

void HavenBagFurnituresRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HavenBagFurnituresRequestMessage(tree);
}

void HavenBagFurnituresRequestMessage::deserializeAsyncAs_HavenBagFurnituresRequestMessage(FuncTree tree)
{
  this->_cellIdstree = tree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_cellIdstreeFunc, this, std::placeholders::_1));
  this->_funitureIdstree = tree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_funitureIdstreeFunc, this, std::placeholders::_1));
  this->_orientationstree = tree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_orientationstreeFunc, this, std::placeholders::_1));
}

void HavenBagFurnituresRequestMessage::_cellIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_cellIdstree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_cellIdsFunc, this, std::placeholders::_1));
  }
}

void HavenBagFurnituresRequestMessage::_cellIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _val << ") on elements of cellIds.";
  }
  this->cellIds.append(_val);
}

void HavenBagFurnituresRequestMessage::_funitureIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_funitureIdstree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_funitureIdsFunc, this, std::placeholders::_1));
  }
}

void HavenBagFurnituresRequestMessage::_funitureIdsFunc(Reader *input)
{
  int _val = int(input->readInt());
  this->funitureIds.append(_val);
}

void HavenBagFurnituresRequestMessage::_orientationstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_orientationstree.addChild(std::bind(&HavenBagFurnituresRequestMessage::_orientationsFunc, this, std::placeholders::_1));
  }
}

void HavenBagFurnituresRequestMessage::_orientationsFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _val << ") on elements of orientations.";
  }
  this->orientations.append(_val);
}

HavenBagFurnituresRequestMessage::HavenBagFurnituresRequestMessage()
{
  m_type = MessageEnum::HAVENBAGFURNITURESREQUESTMESSAGE;
}

