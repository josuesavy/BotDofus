#include "AllianceRightsUpdateMessage.h"

void AllianceRightsUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRightsUpdateMessage(output);
}

void AllianceRightsUpdateMessage::serializeAs_AllianceRightsUpdateMessage(Writer *output)
{
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRightsUpdateMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  output->writeShort((short)this->rights.size());
  for(uint _i2 = 0; _i2 < this->rights.size(); _i2++)
  {
    if(this->rights[_i2] < 0)
    {
      qDebug()<<"ERREUR - AllianceRightsUpdateMessage -"<<"Forbidden value (" << this->rights[_i2] << ") on element 2 (starting at 1) of rights.";
    }
    output->writeVarInt((int)this->rights[_i2]);
  }
}

void AllianceRightsUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRightsUpdateMessage(input);
}

void AllianceRightsUpdateMessage::deserializeAs_AllianceRightsUpdateMessage(Reader *input)
{
  uint _val2 = 0;
  this->_rankIdFunc(input);
  uint _rightsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _rightsLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - AllianceRightsUpdateMessage -"<<"Forbidden value (" << _val2 << ") on elements of rights.";
    }
    this->rights.append(_val2);
  }
}

void AllianceRightsUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRightsUpdateMessage(tree);
}

void AllianceRightsUpdateMessage::deserializeAsyncAs_AllianceRightsUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceRightsUpdateMessage::_rankIdFunc, this, std::placeholders::_1));
  this->_rightstree = tree.addChild(std::bind(&AllianceRightsUpdateMessage::_rightstreeFunc, this, std::placeholders::_1));
}

void AllianceRightsUpdateMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRightsUpdateMessage -"<<"Forbidden value (" << this->rankId << ") on element of AllianceRightsUpdateMessage.rankId.";
  }
}

void AllianceRightsUpdateMessage::_rightstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_rightstree.addChild(std::bind(&AllianceRightsUpdateMessage::_rightsFunc, this, std::placeholders::_1));
  }
}

void AllianceRightsUpdateMessage::_rightsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceRightsUpdateMessage -"<<"Forbidden value (" << _val << ") on elements of rights.";
  }
  this->rights.append(_val);
}

AllianceRightsUpdateMessage::AllianceRightsUpdateMessage()
{
  m_type = MessageEnum::ALLIANCERIGHTSUPDATEMESSAGE;
}

