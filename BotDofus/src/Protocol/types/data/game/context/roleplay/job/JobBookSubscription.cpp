#include "JobBookSubscription.h"

void JobBookSubscription::serialize(Writer *output)
{
  this->serializeAs_JobBookSubscription(output);
}

void JobBookSubscription::serializeAs_JobBookSubscription(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobBookSubscription -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  output->writeBool(this->subscribed);
}

void JobBookSubscription::deserialize(Reader *input)
{
  this->deserializeAs_JobBookSubscription(input);
}

void JobBookSubscription::deserializeAs_JobBookSubscription(Reader *input)
{
  this->_jobIdFunc(input);
  this->_subscribedFunc(input);
}

void JobBookSubscription::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobBookSubscription(tree);
}

void JobBookSubscription::deserializeAsyncAs_JobBookSubscription(FuncTree tree)
{
  tree.addChild(std::bind(&JobBookSubscription::_jobIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobBookSubscription::_subscribedFunc, this, std::placeholders::_1));
}

void JobBookSubscription::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobBookSubscription -"<<"Forbidden value (" << this->jobId << ") on element of JobBookSubscription.jobId.";
  }
}

void JobBookSubscription::_subscribedFunc(Reader *input)
{
  this->subscribed = input->readBool();
}

JobBookSubscription::JobBookSubscription()
{
  m_types<<ClassEnum::JOBBOOKSUBSCRIPTION;
}

bool JobBookSubscription::operator==(const JobBookSubscription &compared)
{
  if(jobId == compared.jobId)
  if(subscribed == compared.subscribed)
  return true;
  
  return false;
}

