#include "GameFightTurnListMessage.h"

void GameFightTurnListMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightTurnListMessage(output);
}

void GameFightTurnListMessage::serializeAs_GameFightTurnListMessage(Writer *output)
{
  output->writeShort((short)this->ids.size());
  for(uint _i1 = 0; _i1 < this->ids.size(); _i1++)
  {
    if(this->ids[_i1] < -9.007199254740992E15 || this->ids[_i1] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << this->ids[_i1] << ") on element 1 (starting at 1) of ids.";
    }
    output->writeDouble(this->ids[_i1]);
  }
  output->writeShort((short)this->deadsIds.size());
  for(uint _i2 = 0; _i2 < this->deadsIds.size(); _i2++)
  {
    if(this->deadsIds[_i2] < -9.007199254740992E15 || this->deadsIds[_i2] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << this->deadsIds[_i2] << ") on element 2 (starting at 1) of deadsIds.";
    }
    output->writeDouble(this->deadsIds[_i2]);
  }
}

void GameFightTurnListMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightTurnListMessage(input);
}

void GameFightTurnListMessage::deserializeAs_GameFightTurnListMessage(Reader *input)
{
  auto _val1 = NULL;
  auto _val2 = NULL;
  uint _idsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _idsLen; _i1++)
  {
    _val1 = input->readDouble();
    if(_val1 < -9.007199254740992E15 || _val1 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _val1 << ") on elements of ids.";
    }
    this->ids.append(_val1);
  }
  uint _deadsIdsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _deadsIdsLen; _i2++)
  {
    _val2 = input->readDouble();
    if(_val2 < -9.007199254740992E15 || _val2 > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _val2 << ") on elements of deadsIds.";
    }
    this->deadsIds.append(_val2);
  }
}

void GameFightTurnListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightTurnListMessage(tree);
}

void GameFightTurnListMessage::deserializeAsyncAs_GameFightTurnListMessage(FuncTree tree)
{
  this->_idstree = tree.addChild(std::bind(&GameFightTurnListMessage::_idstreeFunc, this, std::placeholders::_1));
  this->_deadsIdstree = tree.addChild(std::bind(&GameFightTurnListMessage::_deadsIdstreeFunc, this, std::placeholders::_1));
}

void GameFightTurnListMessage::_idstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idstree.addChild(std::bind(&GameFightTurnListMessage::_idsFunc, this, std::placeholders::_1));
  }
}

void GameFightTurnListMessage::_idsFunc(Reader *input)
{
  double _val = input->readDouble();
  if(_val < -9.007199254740992E15 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _val << ") on elements of ids.";
  }
  this->ids.append(_val);
}

void GameFightTurnListMessage::_deadsIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_deadsIdstree.addChild(std::bind(&GameFightTurnListMessage::_deadsIdsFunc, this, std::placeholders::_1));
  }
}

void GameFightTurnListMessage::_deadsIdsFunc(Reader *input)
{
  double _val = input->readDouble();
  if(_val < -9.007199254740992E15 || _val > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _val << ") on elements of deadsIds.";
  }
  this->deadsIds.append(_val);
}

GameFightTurnListMessage::GameFightTurnListMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNLISTMESSAGE;
}

