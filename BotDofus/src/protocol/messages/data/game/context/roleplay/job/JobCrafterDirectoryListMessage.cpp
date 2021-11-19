#include "JobCrafterDirectoryListMessage.h"

void JobCrafterDirectoryListMessage::serialize(Writer *output)
{
  this->serializeAs_JobCrafterDirectoryListMessage(output);
}

void JobCrafterDirectoryListMessage::serializeAs_JobCrafterDirectoryListMessage(Writer *output)
{
  output->writeShort((short)this->listEntries.size());
  for(uint _i1 = 0; _i1 < this->listEntries.size(); _i1++)
  {
    qSharedPointerCast<JobCrafterDirectoryListEntry>(this->listEntries[_i1])->serializeAs_JobCrafterDirectoryListEntry(output);
  }
}

void JobCrafterDirectoryListMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobCrafterDirectoryListMessage(input);
}

void JobCrafterDirectoryListMessage::deserializeAs_JobCrafterDirectoryListMessage(Reader *input)
{
  QSharedPointer<JobCrafterDirectoryListEntry> _item1 ;
  uint _listEntriesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _listEntriesLen; _i1++)
  {
    _item1 = QSharedPointer<JobCrafterDirectoryListEntry>(new JobCrafterDirectoryListEntry() );
    _item1->deserialize(input);
    this->listEntries.append(_item1);
  }
}

void JobCrafterDirectoryListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobCrafterDirectoryListMessage(tree);
}

void JobCrafterDirectoryListMessage::deserializeAsyncAs_JobCrafterDirectoryListMessage(FuncTree tree)
{
  this->_listEntriestree = tree.addChild(std::bind(&JobCrafterDirectoryListMessage::_listEntriestreeFunc, this, std::placeholders::_1));
}

void JobCrafterDirectoryListMessage::_listEntriestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_listEntriestree.addChild(std::bind(&JobCrafterDirectoryListMessage::_listEntriesFunc, this, std::placeholders::_1));
  }
}

void JobCrafterDirectoryListMessage::_listEntriesFunc(Reader *input)
{
  QSharedPointer<JobCrafterDirectoryListEntry> _item = QSharedPointer<JobCrafterDirectoryListEntry>(new JobCrafterDirectoryListEntry() );
  _item->deserialize(input);
  this->listEntries.append(_item);
}

JobCrafterDirectoryListMessage::JobCrafterDirectoryListMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYLISTMESSAGE;
}

