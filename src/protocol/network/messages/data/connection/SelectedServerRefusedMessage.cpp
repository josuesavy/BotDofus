#include "SelectedServerRefusedMessage.h"

void SelectedServerRefusedMessage::serialize(Writer *output)
{
  this->serializeAs_SelectedServerRefusedMessage(output);
}

void SelectedServerRefusedMessage::serializeAs_SelectedServerRefusedMessage(Writer *output)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  output->writeVarShort((int)this->serverId);
  output->writeByte(this->error);
  output->writeByte(this->serverStatus);
}

void SelectedServerRefusedMessage::deserialize(Reader *input)
{
  this->deserializeAs_SelectedServerRefusedMessage(input);
}

void SelectedServerRefusedMessage::deserializeAs_SelectedServerRefusedMessage(Reader *input)
{
  this->_serverIdFunc(input);
  this->_errorFunc(input);
  this->_serverStatusFunc(input);
}

void SelectedServerRefusedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SelectedServerRefusedMessage(tree);
}

void SelectedServerRefusedMessage::deserializeAsyncAs_SelectedServerRefusedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SelectedServerRefusedMessage::_serverIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SelectedServerRefusedMessage::_errorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SelectedServerRefusedMessage::_serverStatusFunc, this, std::placeholders::_1));
}

void SelectedServerRefusedMessage::_serverIdFunc(Reader *input)
{
  this->serverId = input->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverId << ") on element of SelectedServerRefusedMessage.serverId.";
  }
}

void SelectedServerRefusedMessage::_errorFunc(Reader *input)
{
  this->error = input->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->error << ") on element of SelectedServerRefusedMessage.error.";
  }
}

void SelectedServerRefusedMessage::_serverStatusFunc(Reader *input)
{
  this->serverStatus = input->readByte();
  if(this->serverStatus < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverStatus << ") on element of SelectedServerRefusedMessage.serverStatus.";
  }
}

SelectedServerRefusedMessage::SelectedServerRefusedMessage()
{
  m_type = MessageEnum::SELECTEDSERVERREFUSEDMESSAGE;
}

