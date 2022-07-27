#include "JobExperienceUpdateMessage.h"

void JobExperienceUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_JobExperienceUpdateMessage(output);
}

void JobExperienceUpdateMessage::serializeAs_JobExperienceUpdateMessage(Writer *output)
{
  this->experiencesUpdate.serializeAs_JobExperience(output);
}

void JobExperienceUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_JobExperienceUpdateMessage(input);
}

void JobExperienceUpdateMessage::deserializeAs_JobExperienceUpdateMessage(Reader *input)
{
  this->experiencesUpdate = JobExperience();
  this->experiencesUpdate.deserialize(input);
}

void JobExperienceUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_JobExperienceUpdateMessage(tree);
}

void JobExperienceUpdateMessage::deserializeAsyncAs_JobExperienceUpdateMessage(FuncTree tree)
{
  this->_experiencesUpdatetree = tree.addChild(std::bind(&JobExperienceUpdateMessage::_experiencesUpdatetreeFunc, this, std::placeholders::_1));
}

void JobExperienceUpdateMessage::_experiencesUpdatetreeFunc(Reader *input)
{
  this->experiencesUpdate = JobExperience();
  this->experiencesUpdate.deserializeAsync(this->_experiencesUpdatetree);
}

JobExperienceUpdateMessage::JobExperienceUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEUPDATEMESSAGE;
}

