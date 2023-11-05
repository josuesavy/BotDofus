#include "GameRolePlayArenaSwitchToFightServerMessage.h"

void GameRolePlayArenaSwitchToFightServerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaSwitchToFightServerMessage(output);
}

void GameRolePlayArenaSwitchToFightServerMessage::serializeAs_GameRolePlayArenaSwitchToFightServerMessage(Writer *output)
{
  output->writeUTF(this->address);
  output->writeShort((short)this->ports.size());
  for(uint _i2 = 0; _i2 < this->ports.size(); _i2++)
  {
    if(this->ports[_i2] < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaSwitchToFightServerMessage -"<<"Forbidden value (" << this->ports[_i2] << ") on element 2 (starting at 1) of ports.";
    }
    output->writeVarShort((int)this->ports[_i2]);
  }
  output->writeUTF(this->token);
}

void GameRolePlayArenaSwitchToFightServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(input);
}

void GameRolePlayArenaSwitchToFightServerMessage::deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(Reader *input)
{
  uint _val2 = 0;
  this->_addressFunc(input);
  uint _portsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _portsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayArenaSwitchToFightServerMessage -"<<"Forbidden value (" << _val2 << ") on elements of ports.";
    }
    this->ports.append(_val2);
  }
  this->_tokenFunc(input);
}

void GameRolePlayArenaSwitchToFightServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaSwitchToFightServerMessage(tree);
}

void GameRolePlayArenaSwitchToFightServerMessage::deserializeAsyncAs_GameRolePlayArenaSwitchToFightServerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToFightServerMessage::_addressFunc, this, std::placeholders::_1));
  this->_portstree = tree.addChild(std::bind(&GameRolePlayArenaSwitchToFightServerMessage::_portstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToFightServerMessage::_tokenFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaSwitchToFightServerMessage::_addressFunc(Reader *input)
{
  this->address = input->readUTF();
}

void GameRolePlayArenaSwitchToFightServerMessage::_portstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_portstree.addChild(std::bind(&GameRolePlayArenaSwitchToFightServerMessage::_portsFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaSwitchToFightServerMessage::_portsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaSwitchToFightServerMessage -"<<"Forbidden value (" << _val << ") on elements of ports.";
  }
  this->ports.append(_val);
}

void GameRolePlayArenaSwitchToFightServerMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

GameRolePlayArenaSwitchToFightServerMessage::GameRolePlayArenaSwitchToFightServerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE;
  m_needsHash = true;
}

