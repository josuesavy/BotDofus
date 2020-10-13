#include "ObjectJobAddedMessage.h"

void ObjectJobAddedMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectJobAddedMessage(output);
}

void ObjectJobAddedMessage::serializeAs_ObjectJobAddedMessage(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - ObjectJobAddedMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
}

void ObjectJobAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectJobAddedMessage(input);
}

void ObjectJobAddedMessage::deserializeAs_ObjectJobAddedMessage(Reader *input)
{
  this->_jobIdFunc(input);
}

void ObjectJobAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectJobAddedMessage(tree);
}

void ObjectJobAddedMessage::deserializeAsyncAs_ObjectJobAddedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectJobAddedMessage::_jobIdFunc, this, std::placeholders::_1));
}

void ObjectJobAddedMessage::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - ObjectJobAddedMessage -"<<"Forbidden value (" << this->jobId << ") on element of ObjectJobAddedMessage.jobId.";
  }
}

ObjectJobAddedMessage::ObjectJobAddedMessage()
{
  m_type = MessageEnum::OBJECTJOBADDEDMESSAGE;
}

