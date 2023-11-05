#include "JobCrafterDirectoryAddMessage.h"

void JobCrafterDirectoryAddMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryAddMessage(output);
}

void JobCrafterDirectoryAddMessage::serializeAs_JobCrafterDirectoryAddMessage(Writer *output)
{
  this->listEntry.serializeAs_JobCrafterDirectoryListEntry(output);
}

void JobCrafterDirectoryAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryAddMessage(input);
}

void JobCrafterDirectoryAddMessage::deserializeAs_JobCrafterDirectoryAddMessage(Reader *input)
{
  this->listEntry = JobCrafterDirectoryListEntry();
  this->listEntry.deserialize(input);
}

void JobCrafterDirectoryAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryAddMessage(tree);
}

void JobCrafterDirectoryAddMessage::deserializeAsyncAs_JobCrafterDirectoryAddMessage(FuncTree tree)
{
  this->_listEntrytree = tree.addChild(std::bind(&JobCrafterDirectoryAddMessage::_listEntrytreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryAddMessage::_listEntrytreeFunc(Reader *input)
{
  this->listEntry = JobCrafterDirectoryListEntry();
  this->listEntry.deserializeAsync(this->_listEntrytree);
}

JobCrafterDirectoryAddMessage::JobCrafterDirectoryAddMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYADDMESSAGE;
}

