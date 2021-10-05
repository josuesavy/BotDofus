#include "JobCrafterDirectoryEntryJobInfo.h"

void JobCrafterDirectoryEntryJobInfo::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryEntryJobInfo(output);
}

void JobCrafterDirectoryEntryJobInfo::serializeAs_JobCrafterDirectoryEntryJobInfo(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  if(this->jobLevel < 1 || this->jobLevel > 200)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobLevel << ") on element jobLevel.";
  }
  output->writeByte(this->jobLevel);
  output->writeBool(this->free);
  if(this->minLevel < 0 || this->minLevel > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
  }
  output->writeByte(this->minLevel);
}

void JobCrafterDirectoryEntryJobInfo::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryEntryJobInfo(input);
}

void JobCrafterDirectoryEntryJobInfo::deserializeAs_JobCrafterDirectoryEntryJobInfo(Reader *input)
{
  this->_jobIdFunc(input);
  this->_jobLevelFunc(input);
  this->_freeFunc(input);
  this->_minLevelFunc(input);
}

void JobCrafterDirectoryEntryJobInfo::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryEntryJobInfo(tree);
}

void JobCrafterDirectoryEntryJobInfo::deserializeAsyncAs_JobCrafterDirectoryEntryJobInfo(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectoryEntryJobInfo::_jobIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryJobInfo::_jobLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryJobInfo::_freeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectoryEntryJobInfo::_minLevelFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryEntryJobInfo::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryEntryJobInfo.jobId.";
  }
}

void JobCrafterDirectoryEntryJobInfo::_jobLevelFunc(Reader *input)
{
  this->jobLevel = input->readUByte();
  if(this->jobLevel < 1 || this->jobLevel > 200)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobLevel << ") on element of JobCrafterDirectoryEntryJobInfo.jobLevel.";
  }
}

void JobCrafterDirectoryEntryJobInfo::_freeFunc(Reader *input)
{
  this->free = input->readBool();
}

void JobCrafterDirectoryEntryJobInfo::_minLevelFunc(Reader *input)
{
  this->minLevel = input->readUByte();
  if(this->minLevel < 0 || this->minLevel > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->minLevel << ") on element of JobCrafterDirectoryEntryJobInfo.minLevel.";
  }
}

JobCrafterDirectoryEntryJobInfo::JobCrafterDirectoryEntryJobInfo()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYENTRYJOBINFO;
}

bool JobCrafterDirectoryEntryJobInfo::operator==(const JobCrafterDirectoryEntryJobInfo &compared)
{
  if(jobId == compared.jobId)
  if(jobLevel == compared.jobLevel)
  if(free == compared.free)
  if(minLevel == compared.minLevel)
  return true;
  
  return false;
}

