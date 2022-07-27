#include "CurrentServerStatusUpdateMessage.h"

void CurrentServerStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_CurrentServerStatusUpdateMessage(output);
}

void CurrentServerStatusUpdateMessage::serializeAs_CurrentServerStatusUpdateMessage(Writer *output)
{
  output->writeByte(this->status);
}

void CurrentServerStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_CurrentServerStatusUpdateMessage(input);
}

void CurrentServerStatusUpdateMessage::deserializeAs_CurrentServerStatusUpdateMessage(Reader *input)
{
  this->_statusFunc(input);
}

void CurrentServerStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CurrentServerStatusUpdateMessage(tree);
}

void CurrentServerStatusUpdateMessage::deserializeAsyncAs_CurrentServerStatusUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CurrentServerStatusUpdateMessage::_statusFunc, this, std::placeholders::_1));
}

void CurrentServerStatusUpdateMessage::_statusFunc(Reader *input)
{
  this->status = input->readByte();
  if(this->status < 0)
  {
    qDebug()<<"ERREUR - CurrentServerStatusUpdateMessage -"<<"Forbidden value (" << this->status << ") on element of CurrentServerStatusUpdateMessage.status.";
  }
}

CurrentServerStatusUpdateMessage::CurrentServerStatusUpdateMessage()
{
  m_type = MessageEnum::CURRENTSERVERSTATUSUPDATEMESSAGE;
}

