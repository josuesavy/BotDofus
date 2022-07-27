#include "JobCrafterDirectoryEntryMessage.h"

void JobCrafterDirectoryEntryMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryEntryMessage(output);
}

void JobCrafterDirectoryEntryMessage::serializeAs_JobCrafterDirectoryEntryMessage(Writer *output)
{
  this->playerInfo->serializeAs_JobCrafterDirectoryEntryPlayerInfo(output);
  output->writeShort((short)this->jobInfoList.size());
  for(uint _i2 = 0; _i2 < this->jobInfoList.size(); _i2++)
  {
    (this->jobInfoList[_i2]).serializeAs_JobCrafterDirectoryEntryJobInfo(output);
  }
  this->playerLook->serializeAs_EntityLook(output);
}

void JobCrafterDirectoryEntryMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryEntryMessage(input);
}

void JobCrafterDirectoryEntryMessage::deserializeAs_JobCrafterDirectoryEntryMessage(Reader *input)
{
  JobCrafterDirectoryEntryJobInfo _item2 ;
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserialize(input);
  uint _jobInfoListLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _jobInfoListLen; _i2++)
  {
    _item2 = JobCrafterDirectoryEntryJobInfo();
    _item2.deserialize(input);
    this->jobInfoList.append(_item2);
  }
  this->playerLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->playerLook->deserialize(input);
}

void JobCrafterDirectoryEntryMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryEntryMessage(tree);
}

void JobCrafterDirectoryEntryMessage::deserializeAsyncAs_JobCrafterDirectoryEntryMessage(FuncTree tree)
{
  this->_playerInfotree = tree.addChild(std::bind(&JobCrafterDirectoryEntryMessage::_playerInfotreeFunc, this, std::placeholders::_1));
  this->_jobInfoListtree = tree.addChild(std::bind(&JobCrafterDirectoryEntryMessage::_jobInfoListtreeFunc, this, std::placeholders::_1));
  this->_playerLooktree = tree.addChild(std::bind(&JobCrafterDirectoryEntryMessage::_playerLooktreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryEntryMessage::_playerInfotreeFunc(Reader *input)
{
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserializeAsync(this->_playerInfotree);
}

void JobCrafterDirectoryEntryMessage::_jobInfoListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_jobInfoListtree.addChild(std::bind(&JobCrafterDirectoryEntryMessage::_jobInfoListFunc, this, std::placeholders::_1));
  }
}

void JobCrafterDirectoryEntryMessage::_jobInfoListFunc(Reader *input)
{
  JobCrafterDirectoryEntryJobInfo _item = JobCrafterDirectoryEntryJobInfo();
  _item.deserialize(input);
  this->jobInfoList.append(_item);
}

void JobCrafterDirectoryEntryMessage::_playerLooktreeFunc(Reader *input)
{
  this->playerLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->playerLook->deserializeAsync(this->_playerLooktree);
}

JobCrafterDirectoryEntryMessage::JobCrafterDirectoryEntryMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYENTRYMESSAGE;
}

