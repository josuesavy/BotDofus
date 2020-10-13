#include "QueueStatusMessage.h"

void QueueStatusMessage::serialize(Writer *output)
{
  this->serializeAs_QueueStatusMessage(output);
}

void QueueStatusMessage::serializeAs_QueueStatusMessage(Writer *output)
{
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element position.";
  }
  output->writeShort((short)this->position);
  if(this->total < 0 || this->total > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element total.";
  }
  output->writeShort((short)this->total);
}

void QueueStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_QueueStatusMessage(input);
}

void QueueStatusMessage::deserializeAs_QueueStatusMessage(Reader *input)
{
  this->_positionFunc(input);
  this->_totalFunc(input);
}

void QueueStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QueueStatusMessage(tree);
}

void QueueStatusMessage::deserializeAsyncAs_QueueStatusMessage(FuncTree tree)
{
  tree.addChild(std::bind(&QueueStatusMessage::_positionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QueueStatusMessage::_totalFunc, this, std::placeholders::_1));
}

void QueueStatusMessage::_positionFunc(Reader *input)
{
  this->position = input->readUShort();
  if(this->position < 0 || this->position > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->position << ") on element of QueueStatusMessage.position.";
  }
}

void QueueStatusMessage::_totalFunc(Reader *input)
{
  this->total = input->readUShort();
  if(this->total < 0 || this->total > 65535)
  {
    qDebug()<<"ERREUR - QueueStatusMessage -"<<"Forbidden value (" << this->total << ") on element of QueueStatusMessage.total.";
  }
}

QueueStatusMessage::QueueStatusMessage()
{
  m_type = MessageEnum::QUEUESTATUSMESSAGE;
}

