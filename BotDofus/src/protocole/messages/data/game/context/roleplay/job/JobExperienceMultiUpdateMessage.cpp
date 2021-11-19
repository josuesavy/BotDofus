#include "JobExperienceMultiUpdateMessage.h"

void JobExperienceMultiUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_JobExperienceMultiUpdateMessage(output);
}

void JobExperienceMultiUpdateMessage::serializeAs_JobExperienceMultiUpdateMessage(Writer *output)
{
  output->writeShort((short)this->experiencesUpdate.size());
  for(uint _i1 = 0; _i1 < this->experiencesUpdate.size(); _i1++)
  {
    (this->experiencesUpdate[_i1]).serializeAs_JobExperience(output);
  }
}

void JobExperienceMultiUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobExperienceMultiUpdateMessage(input);
}

void JobExperienceMultiUpdateMessage::deserializeAs_JobExperienceMultiUpdateMessage(Reader *input)
{
  JobExperience _item1 ;
  uint _experiencesUpdateLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _experiencesUpdateLen; _i1++)
  {
    _item1 = JobExperience();
    _item1.deserialize(input);
    this->experiencesUpdate.append(_item1);
  }
}

void JobExperienceMultiUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobExperienceMultiUpdateMessage(tree);
}

void JobExperienceMultiUpdateMessage::deserializeAsyncAs_JobExperienceMultiUpdateMessage(FuncTree tree)
{
  this->_experiencesUpdatetree = tree.addChild(std::bind(&JobExperienceMultiUpdateMessage::_experiencesUpdatetreeFunc, this, std::placeholders::_1));
}

void JobExperienceMultiUpdateMessage::_experiencesUpdatetreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_experiencesUpdatetree.addChild(std::bind(&JobExperienceMultiUpdateMessage::_experiencesUpdateFunc, this, std::placeholders::_1));
  }
}

void JobExperienceMultiUpdateMessage::_experiencesUpdateFunc(Reader *input)
{
  JobExperience _item = JobExperience();
  _item.deserialize(input);
  this->experiencesUpdate.append(_item);
}

JobExperienceMultiUpdateMessage::JobExperienceMultiUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE;
}

