#include "UpdateGuildRightsMessage.h"

void UpdateGuildRightsMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateGuildRightsMessage(output);
}

void UpdateGuildRightsMessage::serializeAs_UpdateGuildRightsMessage(Writer *output)
{
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - UpdateGuildRightsMessage -"<<"Forbidden value (" << this->rankId << ") on element rankId.";
  }
  output->writeVarInt((int)this->rankId);
  output->writeShort((short)this->rights.size());
  for(uint _i2 = 0; _i2 < this->rights.size(); _i2++)
  {
    if(this->rights[_i2] < 0)
    {
      qDebug()<<"ERREUR - UpdateGuildRightsMessage -"<<"Forbidden value (" << this->rights[_i2] << ") on element 2 (starting at 1) of rights.";
    }
    output->writeVarInt((int)this->rights[_i2]);
  }
}

void UpdateGuildRightsMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateGuildRightsMessage(input);
}

void UpdateGuildRightsMessage::deserializeAs_UpdateGuildRightsMessage(Reader *input)
{
  uint _val2 = 0;
  this->_rankIdFunc(input);
  uint _rightsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _rightsLen; _i2++)
  {
    _val2 = input->readVarUhInt();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - UpdateGuildRightsMessage -"<<"Forbidden value (" << _val2 << ") on elements of rights.";
    }
    this->rights.append(_val2);
  }
}

void UpdateGuildRightsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateGuildRightsMessage(tree);
}

void UpdateGuildRightsMessage::deserializeAsyncAs_UpdateGuildRightsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&UpdateGuildRightsMessage::_rankIdFunc, this, std::placeholders::_1));
  this->_rightstree = tree.addChild(std::bind(&UpdateGuildRightsMessage::_rightstreeFunc, this, std::placeholders::_1));
}

void UpdateGuildRightsMessage::_rankIdFunc(Reader *input)
{
  this->rankId = input->readVarUhInt();
  if(this->rankId < 0)
  {
    qDebug()<<"ERREUR - UpdateGuildRightsMessage -"<<"Forbidden value (" << this->rankId << ") on element of UpdateGuildRightsMessage.rankId.";
  }
}

void UpdateGuildRightsMessage::_rightstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_rightstree.addChild(std::bind(&UpdateGuildRightsMessage::_rightsFunc, this, std::placeholders::_1));
  }
}

void UpdateGuildRightsMessage::_rightsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - UpdateGuildRightsMessage -"<<"Forbidden value (" << _val << ") on elements of rights.";
  }
  this->rights.append(_val);
}

UpdateGuildRightsMessage::UpdateGuildRightsMessage()
{
  m_type = MessageEnum::UPDATEGUILDRIGHTSMESSAGE;
}

