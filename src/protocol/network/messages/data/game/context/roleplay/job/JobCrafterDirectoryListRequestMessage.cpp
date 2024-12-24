#include "JobCrafterDirectoryListRequestMessage.h"

void JobCrafterDirectoryListRequestMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryListRequestMessage(output);
}

void JobCrafterDirectoryListRequestMessage::serializeAs_JobCrafterDirectoryListRequestMessage(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryListRequestMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
}

void JobCrafterDirectoryListRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryListRequestMessage(input);
}

void JobCrafterDirectoryListRequestMessage::deserializeAs_JobCrafterDirectoryListRequestMessage(Reader *input)
{
  this->_jobIdFunc(input);
}

void JobCrafterDirectoryListRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryListRequestMessage(tree);
}

void JobCrafterDirectoryListRequestMessage::deserializeAsyncAs_JobCrafterDirectoryListRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectoryListRequestMessage::_jobIdFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryListRequestMessage::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryListRequestMessage -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryListRequestMessage.jobId.";
  }
}

JobCrafterDirectoryListRequestMessage::JobCrafterDirectoryListRequestMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE;
}

