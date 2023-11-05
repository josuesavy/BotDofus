#include "ServerSelectionMessage.h"

void ServerSelectionMessage::serialize(Writer *output)
{
  this->serializeAs_ServerSelectionMessage(output);
}

void ServerSelectionMessage::serializeAs_ServerSelectionMessage(Writer *output)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - ServerSelectionMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  output->writeVarShort((int)this->serverId);
}

void ServerSelectionMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerSelectionMessage(input);
}

void ServerSelectionMessage::deserializeAs_ServerSelectionMessage(Reader *input)
{
  this->_serverIdFunc(input);
}

void ServerSelectionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSelectionMessage(tree);
}

void ServerSelectionMessage::deserializeAsyncAs_ServerSelectionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ServerSelectionMessage::_serverIdFunc, this, std::placeholders::_1));
}

void ServerSelectionMessage::_serverIdFunc(Reader *input)
{
  this->serverId = input->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - ServerSelectionMessage -"<<"Forbidden value (" << this->serverId << ") on element of ServerSelectionMessage.serverId.";
  }
}

ServerSelectionMessage::ServerSelectionMessage()
{
  m_type = MessageEnum::SERVERSELECTIONMESSAGE;
}

