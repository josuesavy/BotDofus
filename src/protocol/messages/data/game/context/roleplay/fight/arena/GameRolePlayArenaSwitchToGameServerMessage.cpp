#include "GameRolePlayArenaSwitchToGameServerMessage.h"

void GameRolePlayArenaSwitchToGameServerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaSwitchToGameServerMessage(output);
}

void GameRolePlayArenaSwitchToGameServerMessage::serializeAs_GameRolePlayArenaSwitchToGameServerMessage(Writer *output)
{
  output->writeBool(this->validToken);
  output->writeVarInt((int)this->ticket.size());
  for(uint _i2 = 0; _i2 < this->ticket.size(); _i2++)
  {
    output->writeByte(this->ticket[_i2]);
  }
  output->writeShort((short)this->homeServerId);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(input);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(Reader *input)
{
  auto _val2 = 0;
  this->_validTokenFunc(input);
  uint _ticketLen = input->readVarInt();
  for(uint _i2 = 0; _i2 < _ticketLen; _i2++)
  {
    _val2 = input->readByte();
    this->ticket.append(_val2);
  }
  this->_homeServerIdFunc(input);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaSwitchToGameServerMessage(tree);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAsyncAs_GameRolePlayArenaSwitchToGameServerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_validTokenFunc, this, std::placeholders::_1));
  this->_tickettree = tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_tickettreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_homeServerIdFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaSwitchToGameServerMessage::_validTokenFunc(Reader *input)
{
  this->validToken = input->readBool();
}

void GameRolePlayArenaSwitchToGameServerMessage::_tickettreeFunc(Reader *input)
{
  uint length = input->readVarInt();
  for(uint i = 0; i < length; i++)
  {
    this->_tickettree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_ticketFunc, this, std::placeholders::_1));
  }
}

void GameRolePlayArenaSwitchToGameServerMessage::_ticketFunc(Reader *input)
{
  int _val = input->readByte();
  this->ticket.append(_val);
}

void GameRolePlayArenaSwitchToGameServerMessage::_homeServerIdFunc(Reader *input)
{
  this->homeServerId = input->readShort();
}

GameRolePlayArenaSwitchToGameServerMessage::GameRolePlayArenaSwitchToGameServerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE;
}

