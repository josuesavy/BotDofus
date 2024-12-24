#include "GameRolePlayArenaSwitchToGameServerMessage.h"

void GameRolePlayArenaSwitchToGameServerMessage::serialize(Writer *output)
{
  this->serializeAs_GameRolePlayArenaSwitchToGameServerMessage(output);
}

void GameRolePlayArenaSwitchToGameServerMessage::serializeAs_GameRolePlayArenaSwitchToGameServerMessage(Writer *output)
{
  output->writeBool(this->validToken);
  output->writeUTF(this->token);
  output->writeShort((short)this->homeServerId);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(input);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(Reader *input)
{
  this->_validTokenFunc(input);
  this->_tokenFunc(input);
  this->_homeServerIdFunc(input);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameRolePlayArenaSwitchToGameServerMessage(tree);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAsyncAs_GameRolePlayArenaSwitchToGameServerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_validTokenFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_tokenFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameRolePlayArenaSwitchToGameServerMessage::_homeServerIdFunc, this, std::placeholders::_1));
}

void GameRolePlayArenaSwitchToGameServerMessage::_validTokenFunc(Reader *input)
{
  this->validToken = input->readBool();
}

void GameRolePlayArenaSwitchToGameServerMessage::_tokenFunc(Reader *input)
{
  this->token = input->readUTF();
}

void GameRolePlayArenaSwitchToGameServerMessage::_homeServerIdFunc(Reader *input)
{
  this->homeServerId = input->readShort();
}

GameRolePlayArenaSwitchToGameServerMessage::GameRolePlayArenaSwitchToGameServerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE;
}

