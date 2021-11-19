#include "JobCrafterDirectorySettings.h"

void JobCrafterDirectorySettings::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectorySettings(output);
}

void JobCrafterDirectorySettings::serializeAs_JobCrafterDirectorySettings(Writer *output)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  output->writeByte(this->jobId);
  if(this->minLevel < 0 || this->minLevel > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
  }
  output->writeByte(this->minLevel);
  output->writeBool(this->free);
}

void JobCrafterDirectorySettings::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectorySettings(input);
}

void JobCrafterDirectorySettings::deserializeAs_JobCrafterDirectorySettings(Reader *input)
{
  this->_jobIdFunc(input);
  this->_minLevelFunc(input);
  this->_freeFunc(input);
}

void JobCrafterDirectorySettings::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectorySettings(tree);
}

void JobCrafterDirectorySettings::deserializeAsyncAs_JobCrafterDirectorySettings(FuncTree tree)
{
  tree.addChild(std::bind(&JobCrafterDirectorySettings::_jobIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectorySettings::_minLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&JobCrafterDirectorySettings::_freeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectorySettings::_jobIdFunc(Reader *input)
{
  this->jobId = input->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectorySettings.jobId.";
  }
}

void JobCrafterDirectorySettings::_minLevelFunc(Reader *input)
{
  this->minLevel = input->readUByte();
  if(this->minLevel < 0 || this->minLevel > 255)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->minLevel << ") on element of JobCrafterDirectorySettings.minLevel.";
  }
}

void JobCrafterDirectorySettings::_freeFunc(Reader *input)
{
  this->free = input->readBool();
}

JobCrafterDirectorySettings::JobCrafterDirectorySettings()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYSETTINGS;
}

bool JobCrafterDirectorySettings::operator==(const JobCrafterDirectorySettings &compared)
{
  if(jobId == compared.jobId)
  if(minLevel == compared.minLevel)
  if(free == compared.free)
  return true;
  
  return false;
}

