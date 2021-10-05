#include "ActivityLockRequestMessage.h"

void ActivityLockRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ActivityLockRequestMessage(output);
}

void ActivityLockRequestMessage::serializeAs_ActivityLockRequestMessage(Writer *output)
{
  if(this->activityId < 0)
  {
    qDebug()<<"ERREUR - ActivityLockRequestMessage -"<<"Forbidden value (" << this->activityId << ") on element activityId.";
  }
  output->writeVarShort((int)this->activityId);
  output->writeBool(this->lock);
}

void ActivityLockRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ActivityLockRequestMessage(input);
}

void ActivityLockRequestMessage::deserializeAs_ActivityLockRequestMessage(Reader *input)
{
  this->_activityIdFunc(input);
  this->_lockFunc(input);
}

void ActivityLockRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActivityLockRequestMessage(tree);
}

void ActivityLockRequestMessage::deserializeAsyncAs_ActivityLockRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ActivityLockRequestMessage::_activityIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActivityLockRequestMessage::_lockFunc, this, std::placeholders::_1));
}

void ActivityLockRequestMessage::_activityIdFunc(Reader *input)
{
  this->activityId = input->readVarUhShort();
  if(this->activityId < 0)
  {
    qDebug()<<"ERREUR - ActivityLockRequestMessage -"<<"Forbidden value (" << this->activityId << ") on element of ActivityLockRequestMessage.activityId.";
  }
}

void ActivityLockRequestMessage::_lockFunc(Reader *input)
{
  this->lock = input->readBool();
}

ActivityLockRequestMessage::ActivityLockRequestMessage()
{
  m_type = MessageEnum::ACTIVITYLOCKREQUESTMESSAGE;
}

