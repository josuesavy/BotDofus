#include "ServerStatusUpdateMessage.h"

void ServerStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_ServerStatusUpdateMessage(output);
}

void ServerStatusUpdateMessage::serializeAs_ServerStatusUpdateMessage(Writer *output)
{
  this->server.serializeAs_GameServerInformations(output);
}

void ServerStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerStatusUpdateMessage(input);
}

void ServerStatusUpdateMessage::deserializeAs_ServerStatusUpdateMessage(Reader *input)
{
  this->server = GameServerInformations();
  this->server.deserialize(input);
}

void ServerStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerStatusUpdateMessage(tree);
}

void ServerStatusUpdateMessage::deserializeAsyncAs_ServerStatusUpdateMessage(FuncTree tree)
{
  this->_servertree = tree.addChild(std::bind(&ServerStatusUpdateMessage::_servertreeFunc, this, std::placeholders::_1));
}

void ServerStatusUpdateMessage::_servertreeFunc(Reader *input)
{
  this->server = GameServerInformations();
  this->server.deserializeAsync(this->_servertree);
}

ServerStatusUpdateMessage::ServerStatusUpdateMessage()
{
  m_type = MessageEnum::SERVERSTATUSUPDATEMESSAGE;
}

