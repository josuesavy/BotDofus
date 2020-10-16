#include "JobDescriptionMessage.h"

void JobDescriptionMessage::serialize(Writer *output)
{
  this->serializeAs_JobDescriptionMessage(output);
}

void JobDescriptionMessage::serializeAs_JobDescriptionMessage(Writer *output)
{
  output->writeShort((short)this->jobsDescription.size());
  for(uint _i1 = 0; _i1 < this->jobsDescription.size(); _i1++)
  {
    qSharedPointerCast<JobDescription>(this->jobsDescription[_i1])->serializeAs_JobDescription(output);
  }
}

void JobDescriptionMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobDescriptionMessage(input);
}

void JobDescriptionMessage::deserializeAs_JobDescriptionMessage(Reader *input)
{
  QSharedPointer<JobDescription> _item1 ;
  uint _jobsDescriptionLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _jobsDescriptionLen; _i1++)
  {
    _item1 = QSharedPointer<JobDescription>(new JobDescription() );
    _item1->deserialize(input);
    this->jobsDescription.append(_item1);
  }
}

void JobDescriptionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobDescriptionMessage(tree);
}

void JobDescriptionMessage::deserializeAsyncAs_JobDescriptionMessage(FuncTree tree)
{
  this->_jobsDescriptiontree = tree.addChild(std::bind(&JobDescriptionMessage::_jobsDescriptiontreeFunc, this, std::placeholders::_1));
}

void JobDescriptionMessage::_jobsDescriptiontreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_jobsDescriptiontree.addChild(std::bind(&JobDescriptionMessage::_jobsDescriptionFunc, this, std::placeholders::_1));
  }
}

void JobDescriptionMessage::_jobsDescriptionFunc(Reader *input)
{
  QSharedPointer<JobDescription> _item = QSharedPointer<JobDescription>(new JobDescription() );
  _item->deserialize(input);
  this->jobsDescription.append(_item);
}

JobDescriptionMessage::JobDescriptionMessage()
{
  m_type = MessageEnum::JOBDESCRIPTIONMESSAGE;
}

