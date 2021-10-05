#include "LoginQueueStatusMessage.h"

void LoginQueueStatusMessage::serialize(Writer *output)
{
  this->serializeAs_LoginQueueStatusMessage(output);
}

void LoginQueueStatusMessage::serializeAs_LoginQueueStatusMessage(Writer *output)
{
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element position.";
  }
  output->writeShort((short)this->position);
  if(this->total < 0 || this->total > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
  }
  output->writeShort((short)this->total);
}

void LoginQueueStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_LoginQueueStatusMessage(input);
}

void LoginQueueStatusMessage::deserializeAs_LoginQueueStatusMessage(Reader *input)
{
  this->_positionFunc(input);
  this->_totalFunc(input);
}

void LoginQueueStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_LoginQueueStatusMessage(tree);
}

void LoginQueueStatusMessage::deserializeAsyncAs_LoginQueueStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&LoginQueueStatusMessage::_positionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&LoginQueueStatusMessage::_totalFunc, this, std::placeholders::_1));
}

void LoginQueueStatusMessage::_positionFunc(Reader *input)
{
  this->position = input->readUShort();
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element of LoginQueueStatusMessage.position.";
  }
}

void LoginQueueStatusMessage::_totalFunc(Reader *input)
{
  this->total = input->readUShort();
  if(this->total < 0 || this->total > 65535)
  {
    qDebug()<<"ERREUR - LoginQueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element of LoginQueueStatusMessage.total.";
  }
}

LoginQueueStatusMessage::LoginQueueStatusMessage()
{
  m_type = MessageEnum::LOGINQUEUESTATUSMESSAGE;
}

