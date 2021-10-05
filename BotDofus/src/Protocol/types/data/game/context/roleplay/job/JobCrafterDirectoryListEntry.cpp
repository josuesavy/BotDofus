#include "JobCrafterDirectoryListEntry.h"

void JobCrafterDirectoryListEntry::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryListEntry(output);
}

void JobCrafterDirectoryListEntry::serializeAs_JobCrafterDirectoryListEntry(Writer *output)
{
  this->playerInfo->serializeAs_JobCrafterDirectoryEntryPlayerInfo(output);
  this->jobInfo.serializeAs_JobCrafterDirectoryEntryJobInfo(output);
}

void JobCrafterDirectoryListEntry::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryListEntry(input);
}

void JobCrafterDirectoryListEntry::deserializeAs_JobCrafterDirectoryListEntry(Reader *input)
{
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserialize(input);
  this->jobInfo = JobCrafterDirectoryEntryJobInfo();
  this->jobInfo.deserialize(input);
}

void JobCrafterDirectoryListEntry::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryListEntry(tree);
}

void JobCrafterDirectoryListEntry::deserializeAsyncAs_JobCrafterDirectoryListEntry(FuncTree tree)
{
  this->_playerInfotree = tree.addChild(std::bind(&JobCrafterDirectoryListEntry::_playerInfotreeFunc, this, std::placeholders::_1));
  this->_jobInfotree = tree.addChild(std::bind(&JobCrafterDirectoryListEntry::_jobInfotreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryListEntry::_playerInfotreeFunc(Reader *input)
{
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserializeAsync(this->_playerInfotree);
}

void JobCrafterDirectoryListEntry::_jobInfotreeFunc(Reader *input)
{
  this->jobInfo = JobCrafterDirectoryEntryJobInfo();
  this->jobInfo.deserializeAsync(this->_jobInfotree);
}

JobCrafterDirectoryListEntry::JobCrafterDirectoryListEntry()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYLISTENTRY;
}

bool JobCrafterDirectoryListEntry::operator==(const JobCrafterDirectoryListEntry &compared)
{
  if(playerInfo == compared.playerInfo)
  if(jobInfo == compared.jobInfo)
  if(_playerInfotree == compared._playerInfotree)
  if(_jobInfotree == compared._jobInfotree)
  return true;
  
  return false;
}

