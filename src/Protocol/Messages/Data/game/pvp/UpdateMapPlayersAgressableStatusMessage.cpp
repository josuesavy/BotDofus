#include "UpdateMapPlayersAgressableStatusMessage.h"

void UpdateMapPlayersAgressableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateMapPlayersAgressableStatusMessage(output);
}

void UpdateMapPlayersAgressableStatusMessage::serializeAs_UpdateMapPlayersAgressableStatusMessage(Writer *output)
{
  output->writeShort((short)this->playerIds.size());
  for(uint _i1 = 0; _i1 < this->playerIds.size(); _i1++)
  {
    if(this->playerIds[_i1] < 0 || this->playerIds[_i1] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << this->playerIds[_i1] << ") on element 1 (starting at 1) of playerIds.";
    }
    output->writeVarLong((double)this->playerIds[_i1]);
  }
  output->writeShort((short)this->enable.size());
  for(uint _i2 = 0; _i2 < this->enable.size(); _i2++)
  {
    output->writeByte(this->enable[_i2]);
  }
}

void UpdateMapPlayersAgressableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMapPlayersAgressableStatusMessage(input);
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAs_UpdateMapPlayersAgressableStatusMessage(Reader *input)
{
  auto _val1 = NULL;
  uint _val2 = 0;
  uint _playerIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _playerIdsLen; _i1++)
  {
    _val1 = input->readVarUhLong();
    if(_val1 < 0 || _val1 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _val1 << ") on elements of playerIds.";
    }
    this->playerIds.append(_val1);
  }
  uint _enableLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _enableLen; _i2++)
  {
    _val2 = input->readByte();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _val2 << ") on elements of enable.";
    }
    this->enable.append(_val2);
  }
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMapPlayersAgressableStatusMessage(tree);
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAsyncAs_UpdateMapPlayersAgressableStatusMessage(FuncTree tree)
{
  this->_playerIdstree = tree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_playerIdstreeFunc, this, std::placeholders::_1));
  this->_enabletree = tree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_enabletreeFunc, this, std::placeholders::_1));
}

void UpdateMapPlayersAgressableStatusMessage::_playerIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_playerIdstree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_playerIdsFunc, this, std::placeholders::_1));
  }
}

void UpdateMapPlayersAgressableStatusMessage::_playerIdsFunc(Reader *input)
{
  double _val = input->readVarUhLong();
  if(_val < 0 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _val << ") on elements of playerIds.";
  }
  this->playerIds.append(_val);
}

void UpdateMapPlayersAgressableStatusMessage::_enabletreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_enabletree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_enableFunc, this, std::placeholders::_1));
  }
}

void UpdateMapPlayersAgressableStatusMessage::_enableFunc(Reader *input)
{
  uint _val = input->readByte();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _val << ") on elements of enable.";
  }
  this->enable.append(_val);
}

UpdateMapPlayersAgressableStatusMessage::UpdateMapPlayersAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE;
}

